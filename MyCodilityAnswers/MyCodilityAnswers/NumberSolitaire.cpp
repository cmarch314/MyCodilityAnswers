/**
comment:
basic dynamic programming technique. 
tracking best sums within range 1~6 proceed to end. 


**/


#include <iostream>
#include <vector>
using namespace std;
int solution(vector<int> &A) {
	int size = A.size();
	vector<int> sums(size, 0);
	sums[0] = A[0];
	//set up default sum (setting not best case results)
	for (int i = 1; i < size; i++)
	{
		sums[i] = sums[i - 1] + A[i];
	}

	//begin dynamic programming
	if (size >= 6)
	{
		for (int i = 0; i < size - 6; i++)
		{
			//range of dice
			for (int j = 1; j <= 6; j++)
			{
				if (sums[i + j] < sums[i] + A[i + j])
				{
					sums[i + j] = sums[i] + A[i + j];
				}
			}
		}
		//finish last 5 elements.
		for (int i = 1; i < 6; i++)
		{
			//range of dice, 
			for (int j = 1; j <= 6 - i; j++)
			{
				if (sums[size - 7 + i + j] < sums[size - 7 + i] + A[size - 7 + i + j])
				{
					sums[size - 7 + i + j] = sums[size - 7 + i] + A[size - 7 + i + j];
				}
			}
		}
	}
	//if the size is less than 6, only add first, last and positive elements. 
	else
	{
		int result = A[0];
		for (int i = 1; i < size - 1; i++)
		{
			if (A[i] > 0)
			{
				result += A[i];
			}
		}
		result += A.back();
		return result;
	}
	return sums.back();
}