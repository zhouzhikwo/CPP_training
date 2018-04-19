#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include<math.h>

bool is_prime(int n) {
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

int main(void) {
	int n;

	printf("Enter a number: ");
	scanf_s("%d", &n);

	if (is_prime(n))
		printf("prime\n");
	else
		printf("not prime\n");
	
	system("pause");
	return 0;
}