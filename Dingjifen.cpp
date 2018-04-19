#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define eps 10e-8

double Function(double x) {
	return exp(-x*x);	
}

double Result(double a, double b, double h) {
	double res,k=0;
	for (int i = 1; i <= 1/h - 1; i++)
	{
		k += 2*Function(i*h);
	}

    res = (k+(a + b))*h / 2;
	
	return res;
}

int main(void) {
	double low = 0, high = 1;
	double result_low, result_high, result[128] = {0}, h = high-low;
	int k;

	result_low = Function(low);
	result_high = Function(high);

	result[0] = Result(result_low, result_high, h);
	for (int i = 0; i <= 20; i++)
	{
		h = h / 2;
		result[i + 1] = Result(result_low, result_high, h);
		k = i;
		if (result[i+1]-result[i]<=eps)
		{
			break;
		}
	}

	printf("ANSWER=%.8lf \n", result[k]);

	system("pause");
}