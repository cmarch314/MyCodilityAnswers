/*comment:
as I made the solution by myself
this solution may not be optimal solution, however the test result is 100% (both correctness and performance)
the code is relativly simple as it works simple enough. 

create a list that size of N+1, fill the list with 1's
each index of the list represents its number
the number 1 means it has initially multiple of it self and 1

as iteration goes through, the number will represent how many factor of integer it contains
so the result of semiPrime[Z] = 3, means it has two number X,Y where X<Z, Y<Z and X*Y = Z and Z*1
to achieve this algorithm we need to iterate multiple times

for each number X from 2 to N+1
	for each number Y 2 to N+1
		semiPrimes [X*Y] += semiPrimes[X]
		if X==Y 
			semiprime[X*Y]++


example:			
the result of N=26 is below where [A:B] A:index, B:number of prime integer factor (+1).
[2:1][3:1][4:3][5:1][6:3][7:1][8:5][9:3][10:3][11:1][12:9][13:1][14:3][15:3][16:11][17:1][18:9][19:1][20:9][21:3][22:3][23:1][24:23][25:3][26:3]

as you can see all prime number remains 1 which no integer could increment it
6 has two factor 2 and 3 where semiPrime[2] = 1 and semiPrime[3] = 1
ergo semiPrime[6] = 1+1+1
8 has 5 factor as it represents
semiPrime[2] + semiPrime[4] + 1 = 1+3+1 = 5

*/


#include <vector>
using namespace std;

vector<int> solution(int N, vector<int> &P, vector<int> &Q) {
	vector<int> semiPrimes(N + 1, 1);
	vector<int> prefixes(N + 1, 0);
	int prefix = 0;
	for (int i = 2; i < N + 1; i++)
	{
		for (int j = 2; i*j < N + 1; j++) // add its multiple results
		{
			semiPrimes[i*j] += semiPrimes[i];
			if (i == j)
			{
				semiPrimes[i*j] ++;
			}
		}
		if (semiPrimes[i] == 3)//if we found semiPrime
		{
			prefix++;
		}
		prefixes[i] = prefix;
	}

	int size = P.size();
	vector<int> result;
	result.reserve(size);
	for (int i = 0; i < size; i++)
	{
		result.push_back(prefixes[Q[i]] - prefixes[P[i] - 1]);
	}
	return result;
}