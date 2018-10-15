#! /usr/bin/env python3
from math import sqrt

class ContinuedFraction:
    ''' a class to handle continued fraction generated from the square root of any positive integer that is not a perfect square '''
    def __init__(self, n):
        self.a0 = int(sqrt(n))
        if self.a0**2 != n: # given number n is not perfect square
            self.n = n # n is the integer to be handled
            self.period = self.getPeriod()
            self.periodLen = len(self.period)
        else:
            print("Error! The target integer must NOT be a perfect square!")

    def getPeriod(self):
        ''' find the period of continued fraction of sqrt(n), return the period as a list.
            code borrowed from Project Euler problem 64
        '''
        b = self.a0
        c = 1
        coeffDict = {}
        period = []
        while True:
            coeffDict[(b, c)] = True # record previous coefficient pair
            
            # calculate current coefficients
            c = (self.n - b**2) // c
            a = int((sqrt(self.n) + b) / c) # this is the KEY. Each level is to convert a fraction into an integer plus a smaller-than-one fraction
            b = a * c - b
            period.append(a)
            if (b, c) in coeffDict:
                break
        return period

    def getConvergent(self, R):
        ''' find the Rth convergent of sqrt(n) based on its continued fraction period. Return the convergent's numerator and denominator separately
            Note that R counts from the non-repeated first integer as the first convergent.
            code borrowed from Project Euler problem 65
        '''
        pLen = len(self.period)
        if R == 1:
            return self.a0, 1

        den = self.period[(R - 2) % pLen] # this is the last component (Nth) of the continued fraction
        num = 1 
        for i in range(R - 3, -1, -1): # from period[R - 3] to period[0]. Add the non-period first integer outside the loop
            num, den = den, self.period[i % pLen] * den + num
        num, den = self.a0 * den + num, den # the first sequence

        return num, den