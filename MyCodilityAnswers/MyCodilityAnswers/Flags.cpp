/*
the algorithm simply stores all peaks 
since the optimal(possible max) number of flags are sqrt(N)
for example, if we want minimum size of array that can carry 4 flags then
[0,1,0,0,0,1,0,0,0,1,0,0,0,1,0] is optimal array.
since the minimum array size to achieve flag 4 is 14. 
meaning that M * (M-1) + 2 where M is desired number of flags
so the relation for minimum N will be O(M*M)
indicates that we don't need to check O(sqrt(N)) number of flags to carry.


iterate from 1 to sqrt(N) where N = A.size()
to find maximal number of flags we can carry

the reason why the algorithm runs O(N) time complexity is that
sum of 1 to sqrt(N) is
O((sqrt(N))(sqrt(N)-1) / 2 ) = O(N).
*/

#include <vector>
using namespace std;

int solution(vector<int> &A) {
	int size = A.size();
	vector<int> peaks;
	peaks.reserve(size);
	//find peaks
	for (int i = 1; i< size - 1; i++)
	{
		if (A[i - 1] < A[i]
			&& A[i + 1] < A[i])
		{
			peaks.push_back(i);
		}
	}
	if (peaks.size() < 2)
	{
		return peaks.size();
	}
	int current, flags, index, result = 1;
	for (int i = 2; i*(i - 1) < size; i++)
	{
		flags = i - 1;
		current = 0;
		index = 1;
		while (flags > 0 && index < peaks.size())
		{
			if (peaks[index] - peaks[current] >= i)
			{
				flags--;
				current = index;
			}
			index++;
		}
		if (flags == 0)
		{
			result = i;
		}
	}
	return result;
}