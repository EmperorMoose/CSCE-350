#include <iostream>
#include <stdlib.h>

int gcd(int x, int y)
{
	while(y != 0)
	{
		int t = y;
		y = x % y;
		x = t;
		return x
	}
}

int main(int argc, char **argv)
{
	int n1, n2, result;
	cout << "Enter the numbers to be calculated";
	cin << n1 << n2;
	result = gcd(n1,n2);
	cout << "\nGCD is: " << result;
	return 0;
}
