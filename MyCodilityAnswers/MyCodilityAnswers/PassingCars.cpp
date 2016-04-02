#include <vector>
using namespace std;
int solution(vector<int> &A) {
	// write your code in C++11 (g++ 4.8.2)
	int east = 0, passing = 0;
	for (vector<int>::iterator it = A.begin(); it != A.end(); it++)
	{
		if (*it == 0)
		{
			east++;
		}
		else
		{
			passing += east;
			if (passing > 1000000000)
			{
				return -1;
			}
		}
	}
	return passing;
}

/*
Comments::
a basic algorithm which may express how prefix works

*/