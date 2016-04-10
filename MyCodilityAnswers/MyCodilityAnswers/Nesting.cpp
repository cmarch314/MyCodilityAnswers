/*comment:
the problem is straigt forward. 
just need to becareful with ")(" case, 
which is false case but the algorithm result will be 0.(since we are doing increment and decrement)
to handle this case, if the stack integer (result) is 0 and we sees close parantheses ')' return 0 for false.

*/

#include <string>
using namespace std;

int solution(string &S) {
	int result = 0;
	for (int i = 0; i < S.size(); i++)
	{
		if (S[i] == '(')
		{
			result++;
		}
		else
		{
			if (result == 0)
			{
				return 0;
			}
			result--;
		}
	}
	return (result == 0) ? 1 : 0;
}