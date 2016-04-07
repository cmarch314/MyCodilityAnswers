int solution(int A, int B, int K) {
	// write your code in C++11 (g++ 4.8.2)
	A = (A%K == 0) ? (A / K - 1) : (A / K);
	B = (B / K);

	return B - A;

}

/*
only need to consider the condition 
the sequence includes the integer A
*/