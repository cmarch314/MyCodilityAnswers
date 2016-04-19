/*ignoring the condition that elements are less or equal then 2*size of array
this may be optimal answer. (got 77% failure of performance test , limit = 0.1sec performed 0.6sec)

*/

#include <vector>
#include <map>
using namespace std;

vector<int> merge_sort(vector<int> A);
vector<int> merge(vector<int> left, vector<int> right);

vector<int> solution(vector<int> &A) {
	int size = A.size();
	vector<int> sorted = merge_sort(A);
	map<int, int> divisors;
	vector<int> result;
	result.reserve(size);
	for (int i = 0; i < size; i++)
	{
		if (divisors.find(sorted[i]) == divisors.end())
		{
			divisors.insert(divisors.end(), make_pair(sorted[i], 1));
		}
		else
		{
			divisors[sorted[i]]++;
		}
	}
	for (map<int, int>::iterator it = divisors.begin();
		it != divisors.end(); it++)
	{
		for (int j = 0; sorted[j] * 2 <= it->first; j++)
		{
			if (it->first%sorted[j] == 0)
			{
				divisors[it->first]++;
			}
		}
	}
	for (int i = 0; i < size; i++)
	{
		result.push_back(size - divisors[A[i]]);
	}
	return result;
}

vector<int> merge_sort(vector<int> A)
{
	if (A.size() <= 1)
	{
		return A;
	}
	vector<int>::iterator middle = A.begin() + (A.size() / 2);

	vector<int> left(A.begin(), middle);
	vector<int> right(middle, A.end());

	left = merge_sort(left);
	right = merge_sort(right);

	return merge(left, right);
}
vector<int> merge(vector<int> left, vector<int> right)
{
	int size = left.size() + right.size();
	vector<int> merged;
	merged.reserve(size);
	vector<int>::iterator left_it = left.begin(), right_it = right.begin();
	while (left_it != left.end() || right_it != right.end())
	{
		if (left_it == left.end())
		{
			merged.push_back(*right_it);
			right_it++;
		}
		else if (right_it == right.end())
		{
			merged.push_back(*left_it);
			left_it++;
		}
		else if (*left_it > *right_it)
		{
			merged.push_back(*right_it);
			right_it++;
		}
		else
		{
			merged.push_back(*left_it);
			left_it++;
		}

	}
	return merged;
}