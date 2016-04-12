/*comment

this problem takes several steps

step1: find leader :O(N)
since we need to find leader who occurs more than half of total length.
(otherwise equi-leader cannot be exists)
the condition is for each sequence X Y, and its corresponding leader freqency fX fY
fX/X > 1/2 and fY/Y > 1/2 then fX/X + fY/Y > 1 maening that (fX+fY) / (X+Y) > 1/2

once we found the leader
we can compute the equi leader position where fX/X > 1/2 && fY/Y > 1/2

*/

#include <map>
#include <vector>
using namespace std;

int solution(vector<int> &A) {
	//find leader
	map<int, int> frequency;
	map<int, int>::iterator it;
	for (int i = 0; i < A.size(); i++)
	{
		it = frequency.find(A[i]);
		if (it == frequency.end())
		{
			frequency.insert(pair<int, int>(A[i], 1));
		}
		else
		{
			frequency[A[i]]++;
		}
	}
	int leader, total_freq, found = 0;
	for (it = frequency.begin(); it != frequency.end(); it++)
	{
		if (2 * ((*it).second) > A.size())
		{
			leader = (*it).first;
			total_freq = (*it).second;
			found = 1;
		}
	}
	if (found == 0)
	{
		return 0;
	}
	//compute the prefix
	double freq = 0;
	double length = A.size();
	int result = 0;
	for (int i = 0; i < A.size() - 1; i++)
	{
		if (A[i] == leader)
		{
			freq++;

		}
		if ((freq / (i + 1)) > 0.5
			&& ((total_freq - freq) / (length - (i + 1))) > 0.5)
		{
			result++;
		}
	}
	//return the number of found
	return result;
}