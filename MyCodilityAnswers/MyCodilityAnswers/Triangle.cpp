/*comment:
since we only need to check the existance of triangle
in sorted list
where A[x]<A[y]<A[z] and x < y < z
can only be triangle if A[x] + A[x+1] > A[x+2] where x+1 <= y and x+2 <= z
meaning that if the condition is not satisfied, we don't need to check further index combination with A[x]
besides we only want to know the existance, checking A[x] + A[x+1] > A[x+2] for {x|A.begin()<x<A.end()-3}
also all negative number should be ignored for triangle. the starting index should be first index of A[x] > 0
*/

#include <vector>
using namespace std;

vector<int> merge_sort(vector<int> A);
vector<int> merge(vector<int> left, vector<int> right);

/* return 1 if triangle can be built
	return 0 if cannot.
*/
int solution(vector<int> &A) {
	//if element is less than 3 then no need to check
	if (A.size() < 3)
	{
		return 0;
	}

	//get sorted array, find initial index to search where sorted[index] > 0
	vector<int> sorted(merge_sort(A));
	int i = 0;
	for (i; i < sorted.size(); i++)
	{
		if (sorted[i] > 0)
		{
			break;
		}
	}

	//if size - i < 3 then impossible
	if (sorted.size() - i < 3)
	{
		return 0;
	}

	//find the triangle.
	for (i; i < sorted.size() - 2; i++)
	{
		//overflow may occur. compute as double.
		if (double(sorted[i]) + double(sorted[i + 1]) > double(sorted[i + 2]))
		{
			return 1;
		}
	}
	return 0;
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