/*comment:
key facts: 
- we can choose adjacent indexes to output 0 for max sum, (which means 0 is special number to compare)
- from left to right iteration (ascending index) calculate the max sum problem. (and same to descending index)

first two index (and last two) has sum of 0. since it is adjacent (choosing 0,1,X will only consider sum of 2 ~ X-1)
from index 2 to N-2. calculate the max possible sum (same to opposite direction)
iterate to find the maximum value. 

the point is understanding maximal sum of sequence. 

example:
A = [1,2,-1,3,1]

inital left and right sums
left =	[	0,	0,	2,	1,	Null]
right = [Null,	2,	3,	0,	0]
index 2 (3rd element) has max value.
*/



#include <vector>
using namespace std;
int solution(vector<int> &A) {
	// write your code in C++11 (g++ 4.8.2)
	int last = A.size() - 1;
	int* left = new int[last + 1];
	int* right = new int[last + 1];

	left[0] = 0;
	left[1] = 0;
	right[last] = 0;
	right[last - 1] = 0;

	for (int i = 2; i < last; i++)
	{
		if (A[i - 1] + left[i - 1] > 0)
		{
			left[i] = A[i - 1] + left[i - 1];
		}
		else
		{
			left[i] = 0;
		}

		if (A[last - i + 1] + right[last - i + 1] > 0)
		{
			right[last - i] = A[last - i + 1] + right[last - i + 1];
		}
		else
		{
			right[last - i] = 0;
		}
	}
	int max = 0;
	for (int i = 1; i <last; i++)
	{
		if (left[i] + right[i] > max)
		{
			max = left[i] + right[i];
		}
	}
	return max;
}