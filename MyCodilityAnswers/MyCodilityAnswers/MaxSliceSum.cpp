
/*comment:
Since we can simply choose an element for sum, each element is comparison values.
from begin to end,
if an element is greater than addition of the element and previous sum, 
current sum becomes the value of element. (meaning that previous sum does not help for next sum)

*/

#include<vector>
using namespace std;

int solution(vector<int> &A) {
	vector<int> sum(A);

	for (int i = 1; i < A.size(); i++)
	{
		if (sum[i - 1] + A[i] > A[i])
		{
			sum[i] = sum[i - 1] + A[i];
		}
	}
	int max = sum[0];
	for (int i = 1; i < A.size(); i++)
	{
		if (sum[i] > max)
		{
			max = sum[i];
		}
	}
	return max;
}