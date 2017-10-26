/*
 *
 * ForwardEulerOdeSolver.cpp
 *
 *  Created on: 25 Oct 2017
 *      Author: adathy
 */

#include "ForwardEulerOdeSolver.hpp"

ForwardEulerOdeSolver::ForwardEulerOdeSolver() {
	// TODO Auto-generated constructor stub

}

ForwardEulerOdeSolver::~ForwardEulerOdeSolver() {
	// TODO Auto-generated destructor stub
}

void ForwardEulerOdeSolver::Solve() {
	// Defensive programming to prevent bad inputs
	if (mNumberOfTimeSteps < 0) {
        throw "The number of time steps is negative";
	}

	if (mTimeStepSize < 0.0 &&
		mStartTime < (mStartTime + mNumberOfTimeSteps*mTimeStepSize)) {
		throw "The timestep size is in the wrong direction";
	}

	Pair v, dvdt;

	// Clear the traces if the code has been previously run
	mSolutionTrace.clear();
	mTimeTrace.clear();

	// Start the trace with the initial values and start times
	mSolutionTrace.push_back(mInitialValues);
	mTimeTrace.push_back(mStartTime);
    for (int t = 1; t <= mNumberOfTimeSteps; t++) {
    	// Run the DE
    	mpRhsFunction(mSolutionTrace.back(), mTimeTrace.back(), dvdt);

    	// Progress over the current timestep
    	v = mSolutionTrace.back();
    	v += dvdt * mTimeStepSize;

    	// Append the results to the traces
    	mSolutionTrace.push_back(v);
    	mTimeTrace.push_back(mStartTime + t*mTimeStepSize);
    }
}
