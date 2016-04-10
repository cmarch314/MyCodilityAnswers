/*comment:
to solve the problem, stack the different hights when it increases. 
dequeue until the maximal height lower then current height. 
counts number of dequeued times. add the size of stacks at the end

for convenience initial stack pushed with 0. since H contains numbers greater than 0.
*/

#include <vector>
using namespace std;

int solution(vector<int> &H) {
	vector<int> stack;
	stack.reserve(H.size());
	stack.push_back(0);
	int result = 0;
	for (int i = 0; i < H.size(); i++)
	{
		while (stack.back() > H[i])
		{
			stack.pop_back();
			result++;
		}
		if (stack.back() < H[i])
		{
			stack.push_back(H[i]);
		}
	}
	result += stack.size() - 1;//exclude 0
	return result;
}