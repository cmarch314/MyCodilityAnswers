/*
the problem can be solved using hash.
psudo code will be

for each element in A
	if(element not in hash_map)
		hash_map.insert(element)
return element.size()

since the condition is O(n*log(n)) time complexity, O(n) space complexity.
I used merge sort to fulfill the condition.
and iterate the sorted array to find different values.
*/

#include <vector>
using namespace std;

vector<int> merge_sort(vector<int> A);
vector<int> merge(vector<int> left, vector<int> right);


int solution(vector<int> &A) {
	// write your code in C++11 (g++ 4.8.2)
	if (A.size() <= 1)
	{
		return A.size();
	}
	int counter = 1;
	vector<int> sorted(merge_sort(A));
	for (int i = 0; i < sorted.size() - 1; i++)
	{
		if (sorted[i] != sorted[i + 1])
		{
			counter++;
		}
	}
	return counter;
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