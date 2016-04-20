/* 
this answer strictly follows instruction of question.
literally devides common divisors seeking for different divisor. 
the answer failed on performance test (result of 66% performance pass) 
total result was 84%.
*/

#include <vector>
#include <iostream>
using namespace std;
int solution(vector<int> &A, vector<int> &B) {
	// write your code in C++11 (g++ 4.8.2)
	int size = A.size(), index, found, result = 0;
	for (int i = 0; i < size; i++)
	{
		index = 2;
		found = 1;
		while (index <= (A[i] > B[i]) ? (A[i]) : (B[i]))
		{
			if ((A[i] % index == 0) != (B[i] % index == 0))
			{
				cout << "found" << endl;
				found = 0;
				break;
			}
			else
			{
				if ((A[i] % index == 0) && (B[i] % index == 0))
				{
					while (A[i] % index == 0)
					{
						A[i] = (A[i] / index);
					}
					while (B[i] % index == 0)
					{
						B[i] = (B[i] / index);
					}
				}
			}

			index++;
		}
		result += found;
		cout << endl;
	}
	return result;
}