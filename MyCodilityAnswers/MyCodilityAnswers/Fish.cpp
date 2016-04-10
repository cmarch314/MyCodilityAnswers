/* comment:
the algorithm is straight forward, 
if you see fish 0 then push it to bucket. 
if you see fish 1 try consume the fishes in the bucket.
if the fish 1 eats all then increment the result. 
iterate should start from index 0.
*/

#include <vector>
using namespace std;
int solution(vector<int> &A, vector<int> &B) {

	vector<int> fish_one;
	fish_one.reserve(A.size());
	vector<int>::iterator it;
	int result = 0;
	for (int i = 0; i < A.size(); i++)
	{
		if (B[i] == 1)
		{
			fish_one.push_back(A[i]);
		}
		else// B[i] == 0
		{
			it = fish_one.end();
			while (it != fish_one.begin())
			{
				it--;
				if (*it < A[i])
				{
					fish_one.pop_back();
				}
				else
				{
					break;
				}
			}
			if (fish_one.empty())
			{
				result++;
			}
		}
	}
	result += fish_one.size();
	return result;
}