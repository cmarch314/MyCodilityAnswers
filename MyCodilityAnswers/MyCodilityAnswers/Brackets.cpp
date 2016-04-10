/*comment:
this is a simple problem that uses bucket (stack) which works with push and pop
*/
#include <vector>
using namespace std;
int solution(string &S) {
	// write your code in C++11 (g++ 4.8.2)
	vector<char> bucket;
	bucket.reserve(S.size());
	for (int i = 0; i < S.size(); i++)
	{
		if (S[i] == '(' || S[i] == '{' || S[i] == '[')
		{
			bucket.push_back(S[i]);
		}
		else if (S[i] == ')' || S[i] == '}' || S[i] == ']')
		{
			if (bucket.empty())
			{
				return 0;
			}
			else if (S[i] == ')')
			{
				if (bucket.back() == '(')
				{
					bucket.pop_back();
				}
				else
				{
					return 0;
				}
			}
			else if (S[i] == '}')
			{
				if (bucket.back() == '{')
				{
					bucket.pop_back();
				}
				else
				{
					return 0;
				}
			}
			else if (S[i] == ']')
			{
				if (bucket.back() == '[')
				{
					bucket.pop_back();
				}
				else
				{
					return 0;
				}
			}
		}
	}
	if (bucket.empty())
	{
		return 1;
	}
	return 0;
}