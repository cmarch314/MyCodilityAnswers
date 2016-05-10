/*
comment:
the problem is a simple example of greedy method. 
seeking only best results in any point of time. 
personally, I don't thing this is a good example for greedy method. (too simple)
*/

#include <vector>

using namespace std;

int solution(int K, vector<int> &A) {
	int length = 0;
	int count = 0;
	int size = A.size();

	for (int i = 0; i < size; i++)
	{
		length += A[i];
		if (length >= K)
		{
			count++;
			length = 0;
		}
	}
	return count;

}