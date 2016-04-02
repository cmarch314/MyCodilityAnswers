// write your code in C++11 (g++ 4.8.2)

/*Counts "0"s in binary form between any "1"s
*/
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