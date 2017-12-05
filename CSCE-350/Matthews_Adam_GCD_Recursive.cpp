#include <iostream>
#include <stdlib.h>

using namespace std;

int gcd(int x, int y)
{
	return (y != 0) ? gcd(y, x % y) : x;
}

int main(int argc, char **argv)
{
	int n1, n2, result;
	cout << "Enter the numbers to be calculated";
	cin >> n1 >> n2;
	result = gcd(n1,n2);
	cout << "\nGCD is: " << result;
	return 0;
}