#include<stdio.h>
#include<stdlib.h>

int main() {
	int a, b, c, d;

	for ( a = 100; a <= 999; a++)
	{
		b = a / 100;
		c = a % 100 / 10;
		d = a % 10;

		if (b*b*b+c*c*c+d*d*d==a)
		{
			printf("Narcissistic Number:%d\n", a);
		}
	}

	system("pause");
	return 0;
}