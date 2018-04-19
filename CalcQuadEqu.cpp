#include<stdio.h>
#include<stdlib.h>
#include<math.h>

bool CalcQuadEqu(double a, double b, double c, double x[2]) {
	double delta = b*b - 4.0*a*c;
	if (delta < 0) return false;
	if (a == 0) {
		x[0] = x[1] = -c / b;
	}
	else{
		x[0] = (-b + sqrt(delta)) / (2.0*a);
	    x[1] = (-b - sqrt(delta)) / (2.0*a);
	}
	return true;
}


bool CalcQuadEqu(double a, double b, double c) {
	double d, x1, x2;
	d = b*b - 4 * a*c;

	if (d>0)
	{
		x1 = (-b + sqrt(d)) / (2 * a);
		x2 = (-b - sqrt(d)) / (2 * a);
		printf("x1=%g,x2=%g\n", x1, x2);
	}
	else if (d == 0)
	{
		x1 = x2 = (-b) / (2 * a);
		printf("方程有两个相等实根：x1=x2=%g\n", x1);
	}
	else
	{
		printf("无实根");
		return false;
	}
	return true;
}

int main() {
	double a, b, c,x[2];
	printf("please enter 方程的三个系数:");
	scanf_s("%lf%lf%lf", &a, &b, &c);

	CalcQuadEqu(a, b, c);
	
	system("pause");
	return 0;
}