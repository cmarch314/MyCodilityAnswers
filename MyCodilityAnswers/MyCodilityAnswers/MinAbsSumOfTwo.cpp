/*comment:
solution can be solved with abs sort which is sorted by its absolute value.
any pair of number that has oposite sign and close abs value would be an answer except abs(smallest)*2
once we sort it with abs value, set the min number to be abs(A[0])*2. then seek for adjacent pairs that substract each other.


*/
#include <algorithm>

using namespace std;
bool absSmall(int a, int b)
{
	return (abs(a) < abs(b));
}
int solution(vector<int> &A) {
	sort(A.begin(), A.end(), absSmall);
	int min = abs(A.front()) * 2;
	int size = A.size();
	int temp;
	if (size == 1)
	{
		return min;
	}
	for (int i = 1; i < size; i++)
	{
		temp = abs(A[i - 1] + A[i]);
		if (temp < min)
		{
			min = temp;
		}

	}
	return min;
}