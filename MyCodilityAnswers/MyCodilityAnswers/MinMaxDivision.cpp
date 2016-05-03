
#include <cmath>

int TestLargeSum(const std::vector < int > &A, int K, int LargeSum)
{
	int i, n, j;
	n = A.size();
	long long sum;

	sum = 0;
	j = 0;
	for (i = 0; i < n; i++)
	{
		sum += A[i];
		if (sum > LargeSum)
		{
			j++;
			if (j > (K - 1)) return 0;
			sum = A[i];
		}
	}

	return 1;
}

int solution(int K, vector < int > &A)
{
	int i, n, Amax, LargeSum;
	int r, b, e, LargeSumR;

	n = A.size();
	LargeSum = 0;
	for (i = K - 1; i < n; i++) LargeSum += A[i];

	Amax = 0;
	for (i = 0; i < n; i++) if (A[i] > Amax) Amax = A[i];

	if (K == n) return Amax;
	LargeSum = max(Amax, LargeSum);

	b = Amax;
	e = LargeSum;
	if (e < b) swap(e, b);
	LargeSumR = e;

	// BinSearch
	while (b <= e)
	{
		LargeSum = (b + e) / 2;
		r = TestLargeSum(A, K, LargeSum);
		if (r)
		{
			e = LargeSum - 1;
			LargeSumR = LargeSum;
		}
		else
		{
			b = LargeSum + 1;
		}
	}
	return LargeSumR;
}