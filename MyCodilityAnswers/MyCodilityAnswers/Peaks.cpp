/*
find all peak iterating trough O(N)
starting from maximal division # which is # of peak
check if the # can divide array evenly, if so check every slice contains peak.

for example

let say we have 4 peak in 12 element

 0 1 2 3 4 5 6 7 8 9 10 11 
[0,1,0,1,0,1,0,1,0,0, 0, 0]

12%4 == 0
so 
each sequence will be
 [0,1,0][1,0,1][0,1,0][0,0,0]
 the algorithm below will check each peaks index
 1/3 = 0
 3/3 = 1
 5/3 = 1 
 7/3 = 2
 
 since no peak can make X/3 = 3
 proceed to 
 12%3 == 0
 [0,1,0,1][0,1,0,1][0,0, 0, 0]

 then
 12%2 == 0
 [0,1,0,1,0,1][0,1,0,0, 0, 0]

 return 2.
 
 */

#include <vector>
using namespace std;
bool allContains(vector<int> X, int gap, int goal)
{
	int index = 0;
	for (int i = 0; i < goal; i++)
	{
		while (X[index] / gap < i && index < X.size())
		{
			index++;
		}
		if (X[index] / gap > i)
		{
			return false;
		}
		else if (X[index] == i)
		{
			index++;
		}
		else
		{
			return false;
		}
	}
	return true;
}
int solution(vector<int> &A) {
	vector<int> peaks;
	peaks.reserve(A.size() / 2);
	int size = A.size();
	if (size < 3)
	{
		return 0;
	}

	for (int i = 1; i < size - 1; i++)
	{
		if (A[i - 1] < A[i] && A[i + 1] < A[i])
		{
			peaks.push_back(i);
		}
	}
	int n = peaks.size();
	for (int i = n; i >= 1; i--)
	{
		if (size%i == 0)
		{
			if (allContains(peaks, size / i, i))
			{
				return i;
			}
		}
	}
	return 0;
}