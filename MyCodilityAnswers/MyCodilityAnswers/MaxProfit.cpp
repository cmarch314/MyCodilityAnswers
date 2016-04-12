/*comment:
a simple problem that tracks maximum substraction pair.

starting from index 0
if any value that is greater than A[0] check for the profit.(update if it is maximal)
if the value is lower than lowest value (initially A[0]) mark the element as lowest.

*/

#include <vector>
using namespace std;
int solution(vector<int> &A) {
	// write your code in C++11 (g++ 4.8.2)
	if (A.size() == 0)
	{
		return 0;
	}
	int profit = 0;
	int lowest = A[0];
	for (int i = 0; i < A.size(); i++)
	{
		if (A[i] > lowest && (A[i] - lowest) > profit)
		{
			profit = A[i] - lowest;
		}
		else if (A[i] < lowest)
		{
			lowest = A[i];
		}
	}
	return profit;
}