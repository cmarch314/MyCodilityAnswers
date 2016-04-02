/*
A zero-indexed array A consisting of N integers is given. Rotation of the array means that each element is shifted right by one index, and the last element of the array is also moved to the first place.

For example, the rotation of array A = [3, 8, 9, 7, 6] is [6, 3, 8, 9, 7]. The goal is to rotate array A K times; that is, each element of A will be shifted to the right by K indexes.

Write a function:

vector<int> solution(vector<int> &A, int K);

that, given a zero-indexed array A consisting of N integers and an integer K, returns the array A rotated K times.

For example, given array A = [3, 8, 9, 7, 6] and K = 3, the function should return [9, 7, 6, 3, 8].

Assume that:

N and K are integers within the range [0..100];
each element of array A is an integer within the range [−1,000..1,000].
In your solution, focus on correctness. The performance of your solution will not be the focus of the assessment.

Copyright 2009–2016 by Codility Limited. All Rights Reserved. Unauthorized copying, publication or disclosure prohibited.
*/
#include <vector>
using namespace std;
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