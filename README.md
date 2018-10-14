# MATH_continued_fraction
A module/class to calculate the period of continued fraction and retrieve its Rth convergent
## Description
The code is written in Python first, as part of the solution to [Project Euler problem 66](https://projecteuler.net/problem=66). It calculates the period of square root of a given positive integer n (n itself cannot be a perfect square) in its continued fraction, and it allows for the generation of the numerator and denominator separatedly for the Rth convergent based on the continued fraction. For details of continued fraction, one can refer to [Wolfram Continued Fraction](http://mathworld.wolfram.com/ContinuedFraction.html) and see its application in [solving the Pell Equation](http://mathworld.wolfram.com/PellEquation.html).
## How to Use
### Python3
* Include the continuedFraction.py file under the same directory as the driver file. Create an instance of ContinuedFraction class and initialize with the positive integer whose square root one wishes to be converted into continued fraction. Upon initialization, the first integer outside the period and the period itself will have been calculated already. They can be accessed directly.
```python
from continuedFraction import ContinuedFraction

n = 23
CF = ContinuedFraction(n)
print("Continued fraction of sqrt({}):".format(n), CF.a0, CF.period)
print("Length of period:", CF.periodLen)

# Continued fraction of sqrt(23): 4 [1, 3, 1, 8]
# Length of period: 4
```
* Use member function getConvergent() to retrieve the Rth convergent fraction. The fraction's numerator and denominator is returned separately. The function takes R as its only parameter.
```python
from continuedFraction import ContinuedFraction

n = 23
R = 9
CF = ContinuedFraction(n)
num, den = CF.getConvergent(R)
print("The {}th convergent is: {}/{}".format(R, num, den))

# The 9th convergent is: 10124/2111
```
