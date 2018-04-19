#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
#include<math.h>

double Averange(double *a, int N)
{
	double total = 0;
	for (int i = 0; i < N; i++)total += a[i];
	return total / N;
}
double CalcCorrelationCoef(double a[], double b[], int N)
{
	double total1 = 0;
	for (int i = 0; i < N; i++)
	{
		total1 += ((a[i] - Averange(a, N))*(b[i] - Averange(b, N)));
	}
	double totala = 0;
	double totalb = 0;
	for (int i = 0; i < N; i++)
	{
		totala += pow(a[i] - Averange(a, N), 2);
		totalb += pow(b[i] - Averange(b, N), 2);
	}
	double total2 = sqrt(totala*totalb);
	double COR = total1 / total2;
	return COR;
}
int main(void)
{
	int N;
	printf("请输入数组长度N: ");
	scanf_s("%d", &N);
	double *a = new double[N];
	double *b = new double[N];
	memset(a, 0, N * sizeof(double));
	memset(b, 0, N * sizeof(double));

	while (getchar() != '\n');
	printf("\n请输入数组a : ");
	for (int i = 0; i < N; i++)
	{
		scanf("%lf", &a[i]);
	}
	while (getchar() != '\n');
	printf("\n\n请输入数组b : ");
	for (int i = 0; i < N; i++)
	{
		scanf_s("%lf", &b[i]);
	}
	
	printf("\nSo the answer is %lf.\n\n", CalcCorrelationCoef(a, b, N));
	if(a)delete[]a;
	if(b)delete[]b;
	system("pause");
	return 0;
}