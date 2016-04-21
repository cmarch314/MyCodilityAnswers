// you can use includes, for example:
// #include <algorithm>

/*
it is always beautyful to use double or float numbers 
since Fibonacci(30.000) is too large to be stored 
we can construct the numbers mod with 2^30 (max) which will not affact the result of any mods of 2^x where x <=30.

also size of A may much greater than 30,000. it may be beautiful to construct full fibonacci numbers
rather than search for max(A).

this algorithm guaranteed to O(L) where L = A.size().

result passed all tests (100%)
*/
#include <vector>
#include <math.h>
using namespace std;
vector<double> GenFib(int N)
{
	vector<double> result;
	result.push_back(0);
	result.push_back(1);
	double max = pow(2, 30);
	for (int i = 2; i < N + 2; i++)
	{
		result.push_back(fmod(result[i - 1], max) + fmod(result[i - 2], max));
	}
	//remove result.back() which is larger than N.
	return result;
}
vector<int> solution(vector<int> &A, vector<int> &B) {
	// write your code in C++11 (g++ 4.8.2)
	vector<double> Fibs;
	//construct full fibonacci number.
	Fibs = GenFib(30000);
	vector<int> result;
	int size = A.size();

	for (int i = 0; i < size; i++)
	{
		result.push_back(
			(int)fmod(Fibs[A[i] + 1], pow(2, B[i])));
	}
	return result;
}
/*
ladder is fibnacci, few example shown below.
N = 0:0

N = 1:1
1

N = 2:2
1,1
2

N = 3:3

1,1,1

1,2
2,1


N = 4:5

1,1,1,1

1,1,2
1,2,1
2,1,1

2,2

N = 5:8
1, 1, 1, 1, 1	 

1, 1, 1 , 2		
1, 1, 2 , 1		
1, 2, 1 , 1		
2, 1, 1 , 1		

1, 2, 2 
2, 1 , 2		
2, 2 , 1		
*/