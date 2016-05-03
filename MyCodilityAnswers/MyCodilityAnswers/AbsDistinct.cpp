/*comment: an easy example to know usage of "Set" data structure.

*/


#include <unordered_set>
using namespace std;
int solution(vector<int> &A) {
	unordered_set<int> distinct;
	int size = A.size();

	for (int i = 0; i < size; i++)
	{
		distinct.insert(abs(A[i]));
	}
	return distinct.size();
}