# MATH_continued_fraction
A module/class to calculate the period of continued fraction and retrieve its Rth convergent
## Description
The continued fraction tool is available in both Python and C++, as part of the solution to [Project Euler problem 66](https://projecteuler.net/problem=66). It calculates the period of square root of a given positive integer n (n itself cannot be a perfect square) in its continued fraction, and it allows for the generation of the numerator and denominator separatedly for the Rth convergent based on the continued fraction. For details of continued fraction, one can refer to [Wolfram Continued Fraction](http://mathworld.wolfram.com/ContinuedFraction.html) and see its application in [solving the Pell Equation](http://mathworld.wolfram.com/PellEquation.html).
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
* Use member function getConvergent() to retrieve the Rth convergent fraction. The fraction's numerator and denominator is returned separately. The function takes R as its only parameter. __Special notes for Rth convergent: If a period is like this: a0 [a1, a2, a3] in which a0 is the first integer outside the period and a1-a3 are the period, the first convergent (R = 1) is a0; the second convergent (R = 2) is a0 + a1; the third convergent (R = 3) is a0 + 1 / (a1 + a2); the fourth convergent (R = 4) is a0 + 1 / (a1 + 1 / (a2 + a3)) ...__
```python
from continuedFraction import ContinuedFraction

n = 23
R = 9
CF = ContinuedFraction(n)
num, den = CF.getConvergent(R)
print("The {}th convergent is: {}/{}".format(R, num, den))

# The 9th convergent is: 10124/2111
```
### C++
* [GMP library](https://gmplib.org/) is needed. 
* Include both continuedFraction.h and continuedFraction.cpp files in the directory. Create an instance of ContinuedFraction class and initialize it with the target positive integer (currently set as int variable, i.e. cannot exceed 2^31 - 1). Upon initialization, the period vector will have been calculated already. Use member function getPeriodAt(), getPeriodLen(), and geta0() to get access to the periods.
```C++
#include "continuedFraction.h"

int n = 31;
int R = 11;
ContinuedFraction CF(n);
std::cout << "The period is: " << CF.geta0() << " [";
for (int i = 0; i < CF.getPeriodLen(); i++)
	std::cout << CF.getPeriodAt(i) << " ";
std::cout << "]\n";

// The period is: 5 [1 1 3 5 3 1 1 10 ]
```
* Use member function getConvergent() to retrieve the Rth convergent (for what Rth convergent implies in this context, refer to the bold text in the Python section). Since the convergent can have very big numerator and denominator as R gets bigger, the convergent is represented using the mpq_class of GMP. 
```C++
#include "continuedFraction.h"

int n = 31;
int R = 100; // a big R value
ContinuedFraction CF(n);
mpq_class res = CF.getConvergent(R); // the numerator and denominator will be huge
std::cout << "The " << R << "th convergent is " << res.get_num() << "/" << res.get_den() << std::endl;

// The 100th convergent is 24288696594210052168209797436920799302880999/4362378687639795310878136232646876050637127
```
