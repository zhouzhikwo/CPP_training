#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

void main() {
	FILE* fp = fopen("E:\\test.txt", "wt");
	if (!fp) return;

	int iter = 0;
	while (iter < 20) {
		int a = 0;
		scanf("%d", &a);
		fprintf(fp, "%d  ", a);
		iter++;
	}

	fclose(fp);

	system("pause");
}
