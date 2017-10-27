#include <cxxtest/TestSuite.h>
#include <fstream>

#include "AbstractOdeSolver.hpp"
#include "ForwardEulerOdeSolver.hpp"
#include "HigherOrderOdeSolver.hpp"
/**
 *
 *  Functions used for generating an ODE system of the form
 *  x' = f(x,t) where x and f are vectors
 *  Specifically this a two-dimensional function.
 *  x' = f(x,y,t) y'=g(x,y,t)
 */

/*
 * x' = -y
 * y' = +x
 * You can solve this one as: dy/dx = (dy/dt)/(dx/dt) = -x/y.  Separate and integrate to give x^2 + y^2 = 2*c
 */
void RhsCircle(const Pair& v, double t, Pair& dvdt)
{
    dvdt.x = -v.y;
    dvdt.y =  v.x;
}

/**
 * This test suite is about testing a higher-order ODE solver (Runge-Kutta, Adams-Bashforth etc.)
 */
class TestHigherOrderOdeSolver : public CxxTest::TestSuite
{
private:
    /*
     * Private helper method.
     * This takes in a solver (with time-steps set), plugs in the circle function,
     * solves it, then post-processes the L_2 error of the solution
     */
    double SolveAndCalculateL2ErrorForCircle(AbstractOdeSolver* pSolver)
    {
        pSolver->SetRhsFunction( &RhsCircle );
        pSolver->SetInitialValues(1.0, 0.0);  // For a unit circle

        pSolver->Solve();

        std::vector<double> times = pSolver->GetTimeTrace();
        std::vector<double> x = pSolver->GetXTrace();
        std::vector<double> y = pSolver->GetYTrace();
        double sum_square_error = 0.0;
        for (unsigned i=0; i<times.size();i++)
        {
            sum_square_error += (x[i]-cos(times[i])) *  (x[i]-cos(times[i]));
            sum_square_error += (y[i]-sin(times[i])) *  (y[i]-sin(times[i]));
        }
        return( sqrt( sum_square_error/times.size() ) );
    }
public:

    /** Convergence with a coupled "circle" system  */
    void TestSimpleCircleConvergence()
    {
        // Do the same thing with both solvers simultaneously
        ForwardEulerOdeSolver euler_solver;
        HigherOrderOdeSolver hi_solver;

        //std::cout << "\n#step_size \t euler_error \t hi_error \n";
        for (int num_steps = 1; num_steps<5e6; num_steps *=2)
        {
            euler_solver.SetInitialTimeNumberOfStepsAndFinalTime(0.0, num_steps, 2*M_PI /* 2*pi is one circuit */);
            hi_solver.SetInitialTimeNumberOfStepsAndFinalTime(0.0, num_steps, 2*M_PI /* 2*pi is one circuit */);

            double euler_error = SolveAndCalculateL2ErrorForCircle(&euler_solver); // Private helper method defined above
            double hi_error = SolveAndCalculateL2ErrorForCircle(&hi_solver);
            double step_size = (2.0*M_PI)/num_steps;

            TS_ASSERT_DELTA(euler_solver.GetTimeTrace().back(), 2.0*M_PI, 2e-15);
            TS_ASSERT_DELTA(hi_solver.GetTimeTrace().back(), 2.0*M_PI, 2e-15);

            //std::cout << step_size << "\t" << euler_error << "\t" << hi_error<< "\n";

            // When the step is not too coarse then we can actually bound the errors
            // (There are some constant factors here: Euler settles to error~1.8138*dt; RK2 to error~0.605*dt)
            if (step_size < 0.05)
            {
                // Euler has linear convergence
                TS_ASSERT_DELTA(euler_error, 0.0, 2.0*step_size);
                // Runge-Kutta RK2 has quadratic convergence.  Other methods will do better.
                TS_ASSERT_DELTA(hi_error,    0.0, step_size*step_size);
            }
        }
    }

    /** Try with a coupled "circle" system  */
     void TestSimpleCircle()
     {
         HigherOrderOdeSolver solver;
         const int num_steps = 10000;
         solver.SetInitialValues(1.0, 0.0);  // For a unit circle
         solver.SetRhsFunction( &RhsCircle ); // See top of file for definition
         solver.SetInitialTimeNumberOfStepsAndFinalTime(0.0, num_steps, 2*M_PI /* 2*pi is one circuit */);
         solver.Solve();
         solver.DumpToFile("hi_solver_dump.txt");

         std::vector<double> times = solver.GetTimeTrace();
         std::vector<double> x = solver.GetXTrace();
         std::vector<double> y = solver.GetYTrace();

         /*
          *
          * Check that the time-stepping is accurate enough
          * The actual machine precision of the calculation here is about
          *     2 * pi * 2.2204e-16 = 1.395e-15
          */
         TS_ASSERT_DELTA(solver.GetTimeTrace().back(), 2.0*M_PI, 2e-15);

         /*
          * Check the solution
          *
          */
         for (int i=0; i<=num_steps; i++)
         {
             // Unit radius test
             TS_ASSERT_DELTA( sqrt(x[i]*x[i] + y[i]*y[i]), 1.0, 2e-3);

             // Actual solution test
             TS_ASSERT_DELTA( x[i], cos(times[i]), 2e-3);
             TS_ASSERT_DELTA( y[i], sin(times[i]), 2e-3);
         }
     }

     void TestErrorofSolver() {
          // Load the solver
          HigherOrderOdeSolver hi_solver;

          std::ofstream write_output("errors_hi.txt", std::ofstream::out);
          if (write_output.is_open() == false) {
              throw Exception("OdePost", "Can't open output file");
          }
          write_output.precision(10);

          // For each timestep, output the L2Error for the solver
          for (int num_steps=1; num_steps<5e6; num_steps*=2) {
              hi_solver.SetInitialTimeNumberOfStepsAndFinalTime(0.0, num_steps, 2*M_PI /* 2*pi is one circuit */);
              double hi_error = SolveAndCalculateL2ErrorForCircle(&hi_solver);

              write_output << 2*M_PI/num_steps << "\t" << hi_error << std::endl;
          }

          write_output.close();
      }
};
