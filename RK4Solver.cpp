/*
 * HigherOrderOdeSolver.cpp
 *
 * Implements a second order Runge-Kutta solver
 *
 *  Created on: 25 Oct 2017
 *      Author: adathy
 */

#include "RK4Solver.hpp"

RK4Solver::RK4Solver() {
	// TODO Auto-generated constructor stub

}

RK4Solver::~RK4Solver() {
	// TODO Auto-generated destructor stub
}

void RK4Solver::Solve() {
	// Defensive programming to prevent bad inputs
	if (mNumberOfTimeSteps < 0) {
        throw "The number of time steps is negative";
	}

	if (mpRhsFunction == NULL) {
		throw "Please define the right hand side function";
	}

	Pair v, k1, k2, k3, k4;

	// Clear the traces if the code has been previously run
	mSolutionTrace.clear();
	mTimeTrace.clear();

	// Start the trace with the initial values and start times
	mSolutionTrace.push_back(mInitialValues);
	mTimeTrace.push_back(mStartTime);
    for (int t = 1; t <= mNumberOfTimeSteps; t++) {
    	// Run the DE
    	mpRhsFunction(mSolutionTrace.back(), mTimeTrace.back(), k1);
    	mpRhsFunction(mSolutionTrace.back() + k1*(0.5*mTimeStepSize), mTimeTrace.back() + mTimeStepSize*0.5, k2);
    	mpRhsFunction(mSolutionTrace.back() + k2*(0.5*mTimeStepSize), mTimeTrace.back() + mTimeStepSize*0.5, k3);
    	mpRhsFunction(mSolutionTrace.back() + k3*mTimeStepSize, mTimeTrace.back() + mTimeStepSize, k4);

    	// Progress over the current timestep
    	v = mSolutionTrace.back() + (k1/6.0 + k2/3.0 + k3/3.0 + k4/6.0)*mTimeStepSize;

    	// Append the results to the traces
    	mSolutionTrace.push_back(v);
    	mTimeTrace.push_back(mStartTime + t*mTimeStepSize);
    }
}
