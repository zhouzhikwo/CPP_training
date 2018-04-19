#include<stdio.h>
#include<stdlib.h>

int main()
{
	printf("  红 白 黑\n");
	int i, j, k, count = 0;
	for (i = 0; i<4; i++) //红球从0到3个
	{
		for (j = 1; j<6; j++) //白球从1到5个(应为必须有白球，所以白球至少是1个)
		{
			for (k = 0; k<7; k++)//黑球从0到6个
			{
				if (i + j + k == 8) { printf("%3d%3d%3d\n", i, j, k); count++; }
			}
		}
	}
	printf("一共有%d种可能。\n", count);

	system("pause");
	return 0;
}