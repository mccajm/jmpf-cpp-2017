/*
 * HigherOrderOdeSolver.hpp
 *
 *  Created on: 25 Oct 2017
 *      Author: adathy
 */

#ifndef HIGHERORDERODESOLVER_HPP_
#define HIGHERORDERODESOLVER_HPP_

#include "AbstractOdeSolver.hpp"

class HigherOrderOdeSolver: public AbstractOdeSolver {
public:
	HigherOrderOdeSolver();
	virtual ~HigherOrderOdeSolver();
	void Solve();
};

#endif /* HIGHERORDERODESOLVER_HPP_ */
