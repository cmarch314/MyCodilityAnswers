#include<vector>
using namespace std;
//ensure the array is fill with 1 to N consecutive numbers (order does not matter)
int solution(vector<int> &A) {
	// write your code in C++11 (g++ 4.8.2)
	int result = 0;
	for (int i = 0; i < A.size(); i++)
	{
		result = result ^ (i + 1);
		result = result^A[i];
	}
	return (result == 0) ? (1) : (0);
}

/*
implemented same idea of PermMissingElem.cpp
the only difference is return condition and values.


quick reference:
X xor Y = Y xor X.
X xor X = 0.
0 xor X = X.
*/