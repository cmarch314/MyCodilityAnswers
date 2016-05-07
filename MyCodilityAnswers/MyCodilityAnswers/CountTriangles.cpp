// you can use includes, for example:
#include <algorithm>
#include <vector>
using namespace std;
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
	int size = A.size(), count = 0;
	if (size < 3)
	{
		return 0;
	}
	sort(A.begin(), A.end());
	int a = 0, b = 1, c = 2;
	while (a < size - 2)
	{
		b = a + 1;
		c = b + 1;


	}
	return count;
}