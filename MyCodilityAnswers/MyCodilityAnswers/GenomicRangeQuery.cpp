
#include <vector>
using namespace std;
/*@param S:string of [A|C|G|T], P and Q : pair of index of sequence where P is begin Q is end.
@return lowest Alphabet appeared for each sequence.
*/
vector<int> solution(string &S, vector<int> &P, vector<int> &Q) {
	//A, C, G and T
	//1, 2, 3 and 4 (or default)
	int l = (S.size() + 1), test_size = P.size();
	int* prefix = new int[3 * l];
	int A = 0, C = 0, G = 0;
	vector<int> result;
	result.reserve(test_size);

	//constructing prefix (size = S.size()+1)
	prefix[0] = 0;//A
	prefix[1] = 0;//C
	prefix[2] = 0;//G
	for (int i = 1; i < l; i++)
	{
		if (S.at(i - 1) == 'A')
		{
			A++;
		}
		else if (S.at(i - 1) == 'C')
		{
			C++;
		}
		else if (S.at(i - 1) == 'G')
		{
			G++;
		}
		prefix[3 * i] = A;
		prefix[3 * i + 1] = C;
		prefix[3 * i + 2] = G;
	}

	for (int i = 0; i < test_size; i++)
	{
		if (prefix[3 * P[i]] != prefix[3 * (Q[i] + 1)])
		{
			result.push_back(1);
		}
		else if (prefix[3 * P[i] + 1] != prefix[3 * (Q[i] + 1) + 1])
		{
			result.push_back(2);
		}
		else if (prefix[3 * P[i] + 2] != prefix[3 * (Q[i] + 1) + 2])
		{
			result.push_back(3);
		}
		else
		{
			result.push_back(4);
		}
	}
	return result;
}

/*
great example of prefix

here is figure of the prefix.
prefix is 2D array

assume S = ACGT

string S =   A   C   G   T
prefix  [0],[1],[2],[3],[4]
A = [0]  0 , 1 , 1 , 1 , 1
B = [1]  0 , 0 , 1 , 1 , 1
C = [2]  0 , 0 , 0 , 1 , 1

for example
sequence 0 , 4
prefix[0][A] = 0 , prefix[4][A] = 1 meaning A appeard once in the sequence

sequence 2, 3
the only increased sequence is prefix[2][C] , prefix[3][C] meaning that C appeared in the sequence.

sequence 3, 4
there are no number changes meaning that only T appeared. 


for this question 
time complexity is O(n+m) where n = S.size(), m = P.size() (or Q.size())
space complexity is O(n) or approximatly 3n. if n is large enough. 

*/