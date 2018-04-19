#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double CalPIValue(double eps) {
	int n = 0;
	double s = 0.0;
	do {
		n += 1;
		s += pow(-1, n + 1) / (2 * n - 1);
	} while (4.0 / (2 * n - 1) >= eps);
	return 4.0*s;
}

void main() {
	double PI, eps;
	printf("Please enter eps=");
	scanf("%lf", &eps);
	PI = CalPIValue(eps);
	printf("%lf\n", PI);

	system("pause");
}
