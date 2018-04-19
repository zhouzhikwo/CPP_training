#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
	double a, b, c, d;
	scanf_s("%lf", &a);
	b = a;
	c = 1;

	while ((fabs(b - c))>0.000001) {
		d = (b + (a / b)) / 2;
		b = d;
		c = a / b;
	}
	printf("%.5lf\n", b);

	system("pause");
	return 0;
}
