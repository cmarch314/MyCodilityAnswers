// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

/*
this answer is exacly same algorithm but translated to C++.
for python version please see following link
https://codesays.com/2014/solution-to-common-prime-divisors-by-codility/

unlike to my brutal force algorithm. this algorithm uses recursive gcd (greatest common divisor) to find common primes.
*/
#include <vector>
using namespace std;
int gcd(int x, int y)
{
	if (x%y == 0)
		return y;
	else
		return gcd(y, x%y);
}
int removeCommonPrimeDivisors(int x, int y)
{
	int gcd_value;
	while (x != 1)
	{
		gcd_value = gcd(x, y);
		if (gcd_value == 1)
			break;

		x /= gcd_value;
	}
	return x;
}

int hasSamePrimeDivisors(int x, int y)
{
	int gcd_value;
	gcd_value = gcd(x, y);
	x = removeCommonPrimeDivisors(x, gcd_value);
	if (x != 1)
		return 0;
	y = removeCommonPrimeDivisors(y, gcd_value);
	return (y == 1);
}
int solution(vector<int> &A, vector<int> &B) {
	// write your code in C++11 (g++ 4.8.2)
	int count = 0;
	for (int i = 0; i < A.size(); i++)
	{
		if (hasSamePrimeDivisors(A[i], B[i]))
			count += 1;
	}

	return count;
}