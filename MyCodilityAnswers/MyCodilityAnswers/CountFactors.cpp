/*
comment:
for each integer X,Y such that X*Y = N where X!=Y 
it is true that X > Z and Y < Z where Z*Z = N

so iterate integer that i*i < N
to find factor of N. (count +=2 for its pair)
if sqrt(N) is integer, increment 1 for count
*/

int solution(int N) {
	int count = 0;
	double M = N;
	for (double i = 1; i*i <= M; i++)
	{
		if (int(M) % int(i) == 0)
		{
			if (i*i == M)
			{
				count++;
			}
			else
			{
				count += 2;
			}
		}
	}
	return count;
}