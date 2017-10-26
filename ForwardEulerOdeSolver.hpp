/*
 * ForwardEulerOdeSolver.hpp
 *
 *  Created on: 25 Oct 2017
 *      Author: adathy
 */

#ifndef FORWARDEULERODESOLVER_HPP_
#define FORWARDEULERODESOLVER_HPP_

#include "AbstractOdeSolver.hpp"

class ForwardEulerOdeSolver: public AbstractOdeSolver {
public:
	ForwardEulerOdeSolver();
	virtual ~ForwardEulerOdeSolver();
	void Solve();
};

#endif /* FORWARDEULERODESOLVER_HPP_ */
