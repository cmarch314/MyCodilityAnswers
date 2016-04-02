#include<vector>
using namespace std;

// count the occurence of 1:N number, sync the counters to max counts when A[i] == N+1
vector<int> solution(int N, vector<int> &A) {
	int min = 0, max = 0;
	vector<int> counter(N, 0);
	for (int i = 0; i < A.size(); i++)
	{
		if (A[i] == (N + 1))//all update?
		{
			min = max;
		}
		else //A[i] within [1:N], count++
		{
			if (counter[A[i] - 1] < min) //catching all update.
			{
				counter[A[i] - 1] = min;
			}

			counter[A[i] - 1]++;
			
			if (counter[A[i] - 1] > max)//update max value.
			{
				max = counter[A[i] - 1];
			}
		}
	}

	//sync the un-updated(sync) elements
	for (int i = 0; i < counter.size(); i++)
	{
		if (counter[i] < min)
		{
			counter[i] = min;
		}
	}
	return counter;
}

/*
the point of this problem is performance
if you strictly follow the algorithm described in the question. 
you will fail the performance test because of unneccessary updates
and getting the time complexity of O(N*M)

for example
consider the sequence with N=100
1,101,1,101,1,101,1,101,1,101,1,101
Note that it increments a counter of 1 and sync the rest of counters 
in this case by the algorithm it will cost 1 + N + 1 + N + 1 + N ... ~= O(N*M) where M = length of A
by storing min value (sync value) and updates it at last or its later increment (in this case A[i] < min should be updated)
will save the process to O(N+M) as the condition requires.
*/