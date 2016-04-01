/*
A binary gap within a positive integer N is any maximal sequence of consecutive zeros that is surrounded by ones at both ends in the binary representation of N.

For example, number 9 has binary representation 1001 and contains a binary gap of length 2. The number 529 has binary representation 1000010001 and contains two binary gaps: one of length 4 and one of length 3. The number 20 has binary representation 10100 and contains one binary gap of length 1. The number 15 has binary representation 1111 and has no binary gaps.

Write a function:

int solution(int N);

that, given a positive integer N, returns the length of its longest binary gap. The function should return 0 if N doesn't contain a binary gap.

For example, given N = 1041 the function should return 5, because N has binary representation 10000010001 and so its longest binary gap is of length 5.

Assume that:

N is an integer within the range [1..2,147,483,647].
Complexity:

expected worst-case time complexity is O(log(N));
expected worst-case space complexity is O(1).
Copyright 2009–2016 by Codility Limited. All Rights Reserved. Unauthorized copying, publication or disclosure prohibited.
*/

// write your code in C++11 (g++ 4.8.2)

int solution(int N) {

	int count = 0, maxGab = 0;

	//skip right most zero sequence (it can't be gab)
	while (N % 2 == 0)
	{
		N = N / 2;
	}

	//start counting. 
	while (N > 0)
	{
		//Starting from rightside
		if (N % 2 == 1)//if right most binary# is 1
		{
			//check the count and update the max value
			if (count > maxGab)
			{
				maxGab = count;
			}
			//reset the count.
			count = 0;
		}
		else
		{
			count++;
		}
		
		N = N / 2; //same as N>>1 ( shift right );
	}
	return maxGab;
}

/* Comments:
let say you have binary number.
1001011000000
^  ^ ^^
2  1 00 skip

the sequence will be proceed as below

after skip loop
1001011

first if(true)
100101
count = 0.

second 
10010
count = 0.

third
100
count = 1.

last
0
count = 2.
*/