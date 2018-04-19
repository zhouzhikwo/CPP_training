#include <iostream>
#include <math.h>
#include <stdlib.h>
using namespace std;

bool is_prime(int n)
{
	int divisor;

	if (n <= 1)
		return false;
	for (divisor = 2; divisor <= sqrt(n); divisor++)
	{
		if (n % divisor == 0)
		{
			return false;
		}
	}

	return true;
}

int main()
{
	int i, n = 0;
	for (i = 2; i < 100; i++)
	{
		if (is_prime(i))
		{
			cout << i;
			n++;
			if (n % 5 == 0)
			{
				cout << endl;
			}
		}
	}

	system("pause");
	return 0;
}
