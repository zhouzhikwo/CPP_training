#include<stdio.h>
#include<stdlib.h>

int max(int a, int b) {
	int tem;
	while (b!=0)
	{
		tem = a%b;
		a = b;
		b = tem;
	}
	return a;
}

int main(void) {
	int a, b;

	scanf_s("%d/%d", &a, &b);
	int tem = max(a, b);

	a /= tem;
	b /= tem;
	printf("%d/%d\n", a, b);

	system("pause");
	return 0;
}