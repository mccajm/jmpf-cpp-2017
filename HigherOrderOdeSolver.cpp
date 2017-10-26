/*
 * HigherOrderOdeSolver.cpp
 *
 * Implements a second order Runge-Kutta solver
 *
 *  Created on: 25 Oct 2017
 *      Author: adathy
 */

#include "HigherOrderOdeSolver.hpp"

HigherOrderOdeSolver::HigherOrderOdeSolver() {
	// TODO Auto-generated constructor stub

}

HigherOrderOdeSolver::~HigherOrderOdeSolver() {
	// TODO Auto-generated destructor stub
}

void HigherOrderOdeSolver::Solve() {
	// Defensive programming to prevent bad inputs
	if (mNumberOfTimeSteps < 0) {
        throw "The number of time steps is negative";
	}

	if (mTimeStepSize < 0.0 &&
		mStartTime < (mStartTime + mNumberOfTimeSteps*mTimeStepSize)) {
		throw "The timestep size is in the wrong direction";
	}

	Pair v, k1, k2;

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

    	// Progress over the current timestep
    	v = mSolutionTrace.back() + k2*mTimeStepSize;

    	// Append the results to the traces
    	mSolutionTrace.push_back(v);
    	mTimeTrace.push_back(mStartTime + t*mTimeStepSize);
    }
}
