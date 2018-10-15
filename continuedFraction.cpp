/*
 * continuedFraction.cpp
 *
 *  Created on: Oct 14, 2018
 *      Author: fanchen
 */

#include "continuedFraction.h"

ContinuedFraction::ContinuedFraction(int num){ // constructor
	a0 = static_cast<int>(sqrt(num));
	if (a0 * a0 != num){
		n = num;
		getPeriod(); // initialize vector period.
	}
	else
		std::cerr << "Error! The given integer must NOT be a perfect square!" << std::endl;
};

void ContinuedFraction::getPeriod(){
	int a, b, c; // each level is represented as a + (sqrt(n) - b) / c
	std::map<std::pair<int, int>, bool> coeffMap; // if want to use unordered_map, must provide hash method for pair

	b = a0;
	c = 1;
	while(true){
		auto it = coeffMap.find(std::make_pair(b, c));
		if (it != coeffMap.end()) // full period found
			break;
		else{
			coeffMap[std::make_pair(b, c)] = true; // current b, c recorded
			// calculate new coefficient
			c = (n - b * b) / c;
			a = static_cast<int>((sqrt(n) + b) / c);
			b = a * c - b;
			period.push_back(a); // store each a
		}
	}
}

mpq_class ContinuedFraction::getConvergent(int R) const{
	int pLen = period.size();
	mpq_class res;
	if (R == 1)
		return mpq_class(a0, 1);

	res = 1 / mpq_class(period[(R - 2) % pLen], 1); // last element of the period
	for (int i = R - 3; i >= 0; i--){ // add the rest of element, from R - 2 to 0.
		res = 1 / (period[i % pLen] + res);
	}
	res += mpq_class(a0, 1); // add the first one

	return res;
}

int ContinuedFraction::getPeriodAt(int pos) const{
	return period[pos];
}

int ContinuedFraction::getPeriodLen() const{
	return period.size();
}

int ContinuedFraction::geta0() const{
	return a0;
}


