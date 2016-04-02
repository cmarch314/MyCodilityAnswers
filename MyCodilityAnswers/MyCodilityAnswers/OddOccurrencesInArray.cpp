#include <vector>
using namespace std;
int solution(vector<int> &A) {
	// write your code in C++11 (g++ 4.8.2)
	int result = 0;
	std::vector<int>::iterator it;
	//another way to iterate vector without using its size and index
	for (it = A.begin(); it != A.end(); ++it)
	{
		result = result ^ *it;
	}
	return result;
}

/*Comments:
Fun & Key Fact!
Behavior of XOR.

X xor Y = Y xor X.
X xor X = 0.
0 xor X = X.

so 
  X xor Y xor X 
= X xor X xor Y 
= 0 xor Y
= Y

*/