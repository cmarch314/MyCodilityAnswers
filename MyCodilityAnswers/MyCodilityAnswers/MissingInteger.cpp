#include <vector>
using namespace std;
//returns minimal missing positive integer ex:[1,2,5] returns 3
int solution(vector<int> &A) {
	int temp = 0;
	for (int i = 0; i < A.size(); i++)
	{
		if ((A[i] > 0)
			&& (A[i] < A.size())
			&& A[i] != i
			&& A[A[i]] != A[i])
		{
			temp = A[i];
			A[i] = A[temp];
			A[temp] = temp;
			i--;
		}
	}
	for (int i = 1; i < A.size(); i++)
	{
		if (A[i] != i)
		{
			return i;
		}
	}
	return (A[0] == A.size()) ? (A.size() + 1) : (A.size());
}

/*
the algorithm checks the element is in range of [1 ~ N-1]
if it is, check for the element is worth to swap (A[i] != i && A[A[i]] != A[i])
keep check and swaps under the condition.
the algorithm only requires O(N) swaps at worst. (each swap matches at least one A[i] = i)
O(N) to find the minimal missing integer.
although It was allow to use extra O(N) space, since modifying array A also being allowed. 
using extra array to find which number is missing would be much easier as we can check the index and assign true false to mark existance
I took the second part. as a challenge.

FunFact on return value condition.
by the algorithm (matching for A[i] == i)
A[0] cannot be A.size() until it is already assigned A[0] or A[1:N] == 1:N
*/