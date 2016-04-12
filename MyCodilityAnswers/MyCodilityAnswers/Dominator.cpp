/*
fun fact, if dominator (an element occurs more than half) exists
the starvation algorithm such that
dominator = A[0], counter = 1.
for i = 1 to A.end()
	if A[i] == domonator 
	counter ++
	else
	counter --
	if counter == 0 (starved)
	dominator = A[i] (pick current number)

this algorithm guarantees the result of dominator being more than half occurs (if it exists)

we should check the dominator occurence after the starvation algorithm.(it could not be exists)
*/
#include <vector>
using namespace std;

int solution(vector<int> &A) {
	// write your code in C++11 (g++ 4.8.2)
	if (A.size() == 0)
	{
		return -1;
	}
	int leader = 0;
	int counter = 0;
	for (int i = 0; i < A.size(); i++)
	{
		if (A[i] == A[leader])
		{
			counter++;
		}
		else
		{
			counter--;
			if (counter <= 0)
			{
				leader = i;
				counter = 1;
			}
		}
	}
	counter = 0;
	for (int i = 0; i < A.size(); i++)
	{
		if (A[i] == A[leader])
		{
			counter++;
		}
	}
	return (2 * counter > A.size()) ? leader : -1;

}