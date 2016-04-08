/*
sort to perform O(nlogn) time
check two combination 
largest negative * second largest negative * largest positive
and
product of three largest positive
compare and return most largest combination.

note that we can perform O(n) time just to find those five numbers (lowest two negative and largest three positive)
however, the section is about sorting the solution may proper to use sort.
*/

#include <vector>
using namespace std;

vector<int> merge_sort(vector<int> A);
vector<int> merge(vector<int> left, vector<int> right);

int solution(vector<int> &A)
{
	int X, Y;
	A = merge_sort(A);
	X = A[0] * A[1] * A[A.size() - 1];
	Y = A[A.size() - 1] * A[A.size() - 2] * A[A.size() - 3];
	return (X>Y) ? X : Y;
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