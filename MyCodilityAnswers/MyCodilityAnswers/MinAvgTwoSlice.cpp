#include <vector>
using namespace std;
int solution(vector<int> &A) {
	// write your code in C++11 (g++ 4.8.2)
	int minIndex = 0, l = A.size() - 1;
	double minValue = (A[0] + A[1]) / 2;
	vector<double> sumOfTwo;
	sumOfTwo.reserve(l);
	//compute prefix for two element
	for (int i = 0; i < l; i++)
	{
		//fill and check for two
		sumOfTwo[i] = (A[i] + A[i + 1]);
		if (sumOfTwo[i] / 2 < minValue)
		{
			minValue = sumOfTwo[i] / 2;
			minIndex = i;
		}
	}
	//search for element of three.
	for (int i = 0; i < l - 1; i++)
	{
		//fill and check for two
		if ((sumOfTwo[i] + A[i + 2]) / 3 < minValue)
		{
			minValue = (sumOfTwo[i] + A[i + 2]) / 3;
			minIndex = i;
		}
		else if ((sumOfTwo[i] + A[i + 2]) / 3 == minValue)
		{
			if (i < minIndex)
			{
				minIndex = i;
			}
		}
	}
	return minIndex;
}

/*
fun fact! (key to solution)
let say number sequence S where S.size() > 3
there are always exists s' where minAvg(s') where s'.size() <= 3

meaning that minAvg sequence can only be size of 2 or 3,
if size is greater or equal to 4 then always smaller agv exists in the sequence.

so Solution is check the sum of two and three elements.

algorithm may different to find minimal index*
for example, we can search for 3 element first, and two element later to find lowest index.
*/