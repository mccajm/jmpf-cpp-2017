/*
 * RK4SOLVER_HPP_.hpp
 *
 *  Created on: 25 Oct 2017
 *      Author: adathy
 */

#ifndef RK4SOLVER_HPP_
#define RK4SOLVER_HPP_

#include "AbstractOdeSolver.hpp"

class RK4Solver: public AbstractOdeSolver {
public:
	RK4Solver();
	virtual ~RK4Solver();
	void Solve();
};

#endif /* RK4SOLVER_HPP_ */
