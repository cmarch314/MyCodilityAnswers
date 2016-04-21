/*
this problem seems very similar to snapsack problem which can be solved by dynamic programming.
available moves are Fibonacci numbers.
and find least step cost.

unlike to snapsack problem , this question has additional condition which the move is valid or not.
end up with score of 100%
*/
#include<vector>;
using namespace std;


//Fibonacci Generator
vector<int> GenFib(int N)
{
	vector<int> result;
	result.push_back(0);
	result.push_back(1);
	int index = 1;
	while (result[index] < N)
	{
		result.push_back(result[index - 1] + result[index]);
		index++;
	}
	//remove result.back() which is larger than N.
	result.pop_back();
	return result;
}
int solution(vector<int> &A) {

	//the goal is reach to N (A.size()) 
	// so I added additional position considering it as a goal.
	A.push_back(1);

	//since I cannot use -1 as an index of array, I will start from 0.
	int position;
	//N is used for steps which is array of number of steps taken to the position. (position : 0 to N+1)
	int N = (A.size() + 1);

	//Fib is array of Fibonacci numbers.
	vector<int> Fib;

	//steps are array of number of steps taken to the position (storing minimum steps)
	vector<int> steps(N, -1);

	//initial position takes 0 steps to reach. (0 means -1 position from the question)
	steps[0] = 0;

	//generate array of Fibonacci numbers
	Fib = GenFib(N);

	//for position = -1 (shifted to 0) to A.size() (shifted to A.size()+1)
	for (position = 0; position < N; position++)
	{
		//if steps taken before (initially indicates position "-1")
		if (steps[position] != -1)
		{
			//checking Fib[0] = 0 and Fib[1] = 1 is pointless since Fib[2] is 1, the loop seek position + Fib[i] reaches to N
			for (int i = 2; Fib[i] + position < N; i++)
			{
				//if step is valid move (position is shifted so we negate the number)
				if ((A[Fib[i] + position - 1] == 1))
				{
					//if the target position has not taken.
					if (steps[Fib[i] + position] == -1)
					{
						//update the value with current position steps taken + 1
						steps[Fib[i] + position] = steps[position] + 1;
					}
					//if taken
					else
					{
						//update least moves comparing already taken vs current position taken + 1
						steps[Fib[i] + position] =
							(steps[Fib[i] + position] < (steps[position] + 1)) ?
							(steps[Fib[i] + position]) : (steps[position] + 1);
					}
				}
			}
		}
	}
	return (steps.back() == 0) ? (-1) : (steps.back());
}