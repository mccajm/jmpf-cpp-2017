#include <cxxtest/TestSuite.h>
#include <fstream>

#include "AbstractOdeSolver.hpp"
#include "RK4Solver.hpp"

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

void RhsVanderPol(const Pair& v, double t, Pair& dvdt) {
	double mu = 7;
    dvdt.x = mu * (v.x - pow(v.x, 3) / 3.0 - v.y);
    dvdt.y = v.x / mu;
}

/**
 * This test suite is about testing a higher-order ODE solver (Runge-Kutta, Adams-Bashforth etc.)
 */
class TestRK4Solver : public CxxTest::TestSuite
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
        RK4Solver rk4_solver;

        //std::cout << "\n#step_size \t euler_error \t hi_error \n";
        for (int num_steps = 1; num_steps<5e6; num_steps *=2)
        {
            rk4_solver.SetInitialTimeNumberOfStepsAndFinalTime(0.0, num_steps, 2*M_PI /* 2*pi is one circuit */);

            double rk4_error = SolveAndCalculateL2ErrorForCircle(&rk4_solver); // Private helper method defined above
            double step_size = (2.0*M_PI)/num_steps;

            TS_ASSERT_DELTA(rk4_solver.GetTimeTrace().back(), 2.0*M_PI, 2e-15);

            //std::cout << step_size << "\t" << euler_error << "\t" << hi_error<< "\n";

            // When the step is not too coarse then we can actually bound the errors
            // (There are some constant factors here: Euler settles to error~1.8138*dt; RK2 to error~0.605*dt)
            if (step_size < 0.05)
            {
                TS_ASSERT_DELTA(rk4_error, 0.0, step_size*step_size);
            }
        }
    }

    /** Try with a coupled "circle" system  */
     void TestSimpleCircle()
     {
         RK4Solver solver;
         const int num_steps = 10000;
         solver.SetInitialValues(1.0, 0.0);  // For a unit circle
         solver.SetRhsFunction( &RhsCircle ); // See top of file for definition
         solver.SetInitialTimeNumberOfStepsAndFinalTime(0.0, num_steps, 2*M_PI /* 2*pi is one circuit */);
         solver.Solve();
         solver.DumpToFile("rk4_solver_dump.txt");

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
          RK4Solver rk4_solver;

          std::ofstream write_output("errors_rk4.txt", std::ofstream::out);
          if (write_output.is_open() == false) {
              throw Exception("OdePost", "Can't open output file");
          }
          write_output.precision(10);

          // For each timestep, output the L2Error for the solver
          for (int num_steps=1; num_steps<5e6; num_steps*=2) {
              rk4_solver.SetInitialTimeNumberOfStepsAndFinalTime(0.0, num_steps, 2*M_PI /* 2*pi is one circuit */);
              double rk4_error = SolveAndCalculateL2ErrorForCircle(&rk4_solver);

              write_output << num_steps <<  "," << rk4_error << std::endl;
          }

          write_output.close();
     }

     void TestVanderPol() {
         const int num_steps = 10000;
         RK4Solver solver;
         solver.SetInitialValues(1.0, 0.0);
         solver.SetRhsFunction(&RhsVanderPol); // See top of file for definition
         solver.SetInitialTimeNumberOfStepsAndFinalTime(0.0, num_steps, 2*M_PI*100);
         solver.Solve();
         solver.DumpToFile("rk4_vanderpol.txt");
     }
};
