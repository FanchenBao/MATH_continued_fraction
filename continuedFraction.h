/*
 * continuedFraction.h
 *
 *  Created on: Oct 14, 2018
 *      Author: fanchen
 *
 *  Allows for calculation of the period of the continued fraction representation of the square root of a positive
 *  integer (excluding perfect squares), and generation of the Rth convergent of the continued fraction.
 */

#ifndef CONTINUEDFRACTION_H_
#define CONTINUEDFRACTION_H_

#include <iostream>
#include <gmpxx.h>
#include <vector>
#include <map>
#include <cmath> //sqrt
#include <utility>      // std::pair

class ContinuedFraction{
public:
	/*
	 * PreCondition: A positive integer num is passed. Num is to be represented by continued fraction
	 * PostCondition: Private variable n and a0 are initialized from num
	 * Description: Constructor of the class to initialize n and a0.
	 */
	ContinuedFraction(int num);

	/*
	 * PreCondition: None
	 * PostCondition: Private variable period is populated, with its values being the period of the continued fraction
	 * Description: Calculate the period of continued fraction of sqrt(n)
	 */
	void getPeriod();

	/*
	 * PreCondition: An integer R is passed. R is the position of the target convergent to be returned
	 * PostCondition: The Rth convergent of the continued fraction is returned. If a period is like this:
	 * 				a0 [a1, a2, a3] in which a0 is the first integer outside the period and a1-a3 are the
	 * 				period, the first convergent (R = 1) is a0, the second convergent (R = 2) is a0 + a1,
	 * 				the third convergent (R = 3) is a0 + 1 / (a1 + a2), the fourth convergent (R = 4) is
	 * 				a0 + 1 / (a1 + 1 / (a2 + a3)) ...
	 * 				Note that the return type is mpq_class under the gmp library, because the fraction can
	 * 				have gigantic numerator and denominator.
	 * 	Description: Calculate the Rth convergent, and return the value as mpq_class.
	 */
	mpq_class getConvergent(int R) const;


	/*
	 * PreCondition: A positive integer position is passed.
	 * PostCondition: The period value at the given position is returned. Position can be larger than the size of period
	 * 				because the period is cyclical and a big position simply loops back to the start.
	 * Description: Get the values of the period at any position given.
	 */
	int getPeriodAt(int pos) const;


	/*
	 * PreCondition: None
	 * PostCondition: The size of the period size is returned.
	 * Description: Get the size of the period.
	 */
	int getPeriodLen() const;


	/*
	 * PreCondition: None
	 * PostCondition: The value of a0 is returned.
	 * Description: Get the first integer outside the period.
	 */
	int geta0() const;

private:
	int n; // whose square root is to be represented as continued fraction
	std::vector<int> period; // store values within the period
	int a0; // first integer outside the period
};



#endif /* CONTINUEDFRACTION_H_ */
