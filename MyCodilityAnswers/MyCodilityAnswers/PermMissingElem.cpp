#include <vector>
using namespace std;

//Find a missing number from shuffled consecutive number (1 to N+1) array. 
int solution(vector<int> &A) {
	// write your code in C++11 (g++ 4.8.2)
	int result = 0;
	for (int i = 0; i < A.size(); i++)
	{
		result = result ^ A[i];
		result = result ^ (i + 1);
	}
	result = result ^ A.size() + 1;
	return result;
}

/*comment:
implementing Idea of OddOccurncesInArray.cpp
X xor Y = Y xor X.
X xor X = 0.
0 xor X = X.

given the condition that the array is filled with N+1 different numbers except for one random number.
and the range was 1 to N+1, so if we apply same "xor" parity search skill doing with (i+1) and N+1 
we shall find the missing number at the end of process. 

example:
[2,1,4]

iteration will be
0)result =	0	  xor 2 xor 1
1)result = result xor 1 xor 2
2)result = result xor 4 xor 3

and N+1
  result = result xor 4

as you can see only "3" is unpaired.
*/