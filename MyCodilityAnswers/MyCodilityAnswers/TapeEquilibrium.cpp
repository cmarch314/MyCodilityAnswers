#include <vector>
using namespace std;
//finds the minimum difference of leftSum and rightSum of any index.
int solution(vector<int> &A) {
	//if empty or single element. 
	int result = 0;
	if (A.size() < 2)
	{
		return result;
	}

	vector<int> leftSum;
	leftSum.reserve(A.size());
	leftSum.push_back(A[0]);
	//fill the leftSum list.
	for (int i = 1; i < A.size(); i++)
	{
		leftSum.push_back(leftSum[i - 1] + A[i]);
	}

	//initial difference value  = (leftSum-A.back()) - A.back(); meaning that A[0:N-1] - A[N]
	int rightSum = 0; result = abs(leftSum.back() - 2 * A.back());
	//find minimum value. from most right element to very first element.
	for (int i = A.size() - 1; i > 0; i--)
	{
		rightSum += A[i];
		if (result > abs(leftSum[i - 1] - rightSum))
		{
			result = abs(leftSum[i - 1] - rightSum);
		}

	}

	return result;
}

/* Comments
There could be various answers for this problem.
desired informations are summation of leftside and rightside for each index.
computing summation will take O(N) time and search the result will take another O(N) time.
in this solution, I computed leftsum only and did the search and rightSum at the sametime.

as the problem restricted, I only used O(N) space and time complexity. 
*/