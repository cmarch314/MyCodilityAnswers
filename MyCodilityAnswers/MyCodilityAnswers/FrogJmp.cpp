// finds minimal S such that {S| S > (Y-X)/D} 
int solution(int X, int Y, int D) {
	// write your code in C99 (gcc 4.8.2)
	int distance = (Y - X);
	int result = distance / D;
	return (distance%D > 0) ? (result + 1) : (result);
}

/* Comment:
the problem is relativly easy calculation. although it is asking for the behavior of division and mod. 

above three lines of code can be shorten by one line. 
 return ((Y - X) % D > 0) ? ((Y - X) / D + 1) : ((Y - X) / D);
 if the compiler is good enough, one line can be efficient than above (no extra memory space). 
*/