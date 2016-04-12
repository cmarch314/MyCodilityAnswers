/*
comment:

key factor:
for integer area N, the maximum integer Perimeter is side of 1 and N
to achieve O(sqrt(N)) iterate the integer until i*i > N

set the initial min value to 1+N (reduce the shift operation, we can compute 2*X later)
compare each integer that is factor of N
find the min value.
*/



int solution(int N) {
	int min =  (N + 1);
	for (int i = 1; i*i <= N; i++)
	{
		if (N%i == 0)
		{
			if ((i + N / i) < min)
			{
				min = (i + N / i);
			}
		}
	}
	return 2*min;
}