#include <vector>
using namespace std;

/*
Rotates Array to right for amount of K.
*/
vector<int> solution(vector<int> &A, int K) 
{
	// write your code in C++11 (g++ 4.8.2)
	if (A.size() == 0)
	{
		return A;
	}
	int shiftedIndexZero = A.size() - (K % A.size());

	vector<int> result;
	result.reserve(A.size());
	for (int i = 0; i < A.size(); i++)
	{
		result.push_back(A[(i + shiftedIndexZero) % A.size()]);
	}
	return result;
}

/*Comments:
the problem seems to be solved easily by doing pop front and push last
	it would be inefficient process because of rapid memory allocation.

the problem can be solved using index scheme.
since we are rotating to right. the index of the first element of shifted result will be
	size - K % size.
however we have to handle the case where size == 0.
then we can allocate the new vector with same size and insert from shifted index.
for index number that is greater than size can be rotated back to 0 by index%size (index mod size)


example:
[3, 8, 9, 7, 6] , shift amount = 3
       ^
	   first element of shifted result.
5 - 3 % 5 = 2 (same results for K = 3+5N where N is integer)
A[2] = 9
A[3] = 7
A[4] = 6
A[5] = A[5%5] = A[0] = 3
A[6] = A[6%5] = A[1] = 8

*/