/*comment:
the problem is combination of prefix and sort. 
firstly I used pair for each circle points where i - A[i] and i+A[i]
and flag for its in and out. (initially 0 meaning not in yet)
once all meeting point added we can sort the points however inserting points order matters because of the circle that has length 0.
so we have to loop the begin point first and end point last. 
then sort to proceed prefix problem. (just like car passing problem)

example:
assume for each center X and its radius r, bX is begin eX is end where bX = X-r, eX = X+r then
then figure of X = 0 and R = 1 will be
(-3)-(-2)-[bX]-(0)-[eX]-(2)-(3)

let say we have two element X ,Y and Z where X = 0 and Y = 1 and its corresponding radius is 1,2 and 0.
then figure will be
(-3)-(-2)-[bX]-(0)-[eX]-(2)-(3)
(-3)-(-2)-[bY]-(0)-(1)-(2)-[eY]
(-3)-(-2)-(-1)-(0)-(1)-(2)-[bZ][eZ]-(4)

then the algorithm will construct array 
[-1,X][-1,Y][3,Z][2,X][3,Y][3,Z]
(	all begins	)(	all ends	)
as it pushes from each begin, then each end.

notice that merge sort will put the end point to right side when the same value compares.
just because the end point was constructed on right side.

after merge sort
[-1,X][-1,Y][2,X][3,Y][3,Z][3,Z]

then prefix will calculate the intersections.
[-1,X] 0
[-1,Y] 1
[2,X] 1
[3,Y] 1
[3,Z] 1
[3,Z] 1

result = 1.
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