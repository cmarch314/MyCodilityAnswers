/*comment:
the problem is combination of prefix and sort. 
firstly I used pair for each circle points where i - A[i] and i+A[i]
and flag for its in and out. (initially 0 meaning not in yet)
once all meeting point added we can sort the points however inserting points order matters because of the circle that has length 0.
so we have to loop the begin point first and end point last. 
then sort to proceed prefix problem. (just like car passing problem)
*/


#include <vector>
#include <utility>
using namespace std;

vector<pair<double, double>> merge_sort(vector<pair<double, double>> A);
vector<pair<double, double>> merge(vector<pair<double, double>> left, vector<pair<double, double>> right);

int solution(vector<int> &A)
{
	int current = 0, result = 0;
	vector<int> flag(A.size(), 0);
	vector<pair<double, double>> beginAndEnd;
	beginAndEnd.reserve(2 * A.size());
	for (int i = 0; i < A.size(); i++)
	{
		beginAndEnd.push_back(make_pair((double)i - (double)A[i], i));
	}
	for (int i = 0; i < A.size(); i++)
	{
		beginAndEnd.push_back(make_pair((double)i + (double)A[i], i));
	}
	beginAndEnd = merge_sort(beginAndEnd);

	for (int i = 0; i < beginAndEnd.size(); i++)
	{
		if (flag[beginAndEnd[i].second] == 0)
		{
			result += current;
			current++;
			flag[beginAndEnd[i].second] = 1;

			if (result > 10000000)
			{
				return -1;
			}
		}
		else
		{
			flag[beginAndEnd[i].second] = 1;
			current--;
		}
	}
	return  result;
}

vector<pair<double, double>> merge_sort(vector<pair<double, double>> A)
{
	if (A.size() <= 1)
	{
		return A;
	}
	vector<pair<double, double>>::iterator middle = A.begin() + (A.size() / 2);

	vector<pair<double, double>> left(A.begin(), middle);
	vector<pair<double, double>> right(middle, A.end());

	left = merge_sort(left);
	right = merge_sort(right);

	return merge(left, right);
}
vector<pair<double, double>> merge(vector<pair<double, double>> left, vector<pair<double, double>> right)
{
	int size = left.size() + right.size();
	vector<pair<double, double>> merged;
	merged.reserve(size);
	vector<pair<double, double>>::iterator left_it = left.begin(), right_it = right.begin();
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
		else if ((*left_it).first > (*right_it).first)
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