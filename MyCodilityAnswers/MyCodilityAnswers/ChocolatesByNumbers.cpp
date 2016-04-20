/*
the algorithm finds least common multiplier, (LCM). 
returns LCM/M. which is answer of the question.

100% correct. 
*/

#include <vector>
#include <map>
using namespace std;

int solution(int N, int M) {
	//looking for LCM
	//since LCM(N,M) may cause overflow. I used N ,M
	double scm = N, term = M;
	//n , m = list of factors of N and M
	map<int, int> n, m;
	
	//find factor of N
	int i = 2;
	while (i*i <= N)
	{
		if (N%i == 0)
		{
			if (n.find(i) == n.end())
			{
				n.insert(n.end(), make_pair(i, 1));
			}
			else
			{
				n[i]++;
			}
			N = N / i;
		}
		else
		{
			i++;
		}
	}
	if (n.find(N) == n.end())
	{
		n.insert(n.end(), make_pair(N, 1));
	}
	else
	{
		n[N]++;
	}

	//find factor of M
	i = 2;
	while (i*i <= M)
	{
		if (M%i == 0)
		{
			if (m.find(i) == m.end())
			{
				m.insert(m.end(), make_pair(i, 1));
			}
			else
			{
				m[i]++;
			}
			M = M / i;
		}
		else
		{
			i++;
		}
	}
	if (m.find(M) == m.end())
	{
		m.insert(m.end(), make_pair(M, 1));
	}
	else
	{
		m[M]++;
	}

	//calculate LCM , (finds missing factors and multiply it)
	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
	{
		if (n.find(it->first) == n.end())
		{
			for (int i = 0; i < (it->second); i++)
			{
				scm = scm*(it->first);
			}
		}
		else
		{
			for (int i = 0; i < (it->second - n[it->first]); i++)
			{
				scm = scm*(it->first);
			}
		}
	}

	
	return scm / term;
}