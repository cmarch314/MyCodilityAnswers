#include <vector>
using namespace std;
int solution(int X, vector<int> &A) {
	// write your code in C++11 (g++ 4.8.2)
	vector<bool> travel;
	travel.reserve(X + 1);
	for (int i = 0; i < X + 1; i++)
	{
		travel[i] = 1;
	}

	int furthestReach = 0;
	for (int i = 0; i < A.size(); i++)
	{
		travel[A[i]] = 0;
		while (true)
		{
			if (travel[furthestReach + 1] == 0)
			{
				furthestReach++;
				if (furthestReach == X)
				{
					return i;
				}
			}
			else
			{
				break;
			}
		}
	}
	return -1;
}

/*comment:
although this is straight foward question, 
it is ambiguous to perform better using bitmap
bitmap may reduce the space
number of comparisson may be same as I used

N = A.size()
time complexity O(N)
space complexity O(X)
*/