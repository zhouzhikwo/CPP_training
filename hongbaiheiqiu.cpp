#include<stdio.h>
#include<stdlib.h>

int main()
{
	printf("  �� �� ��\n");
	int i, j, k, count = 0;
	for (i = 0; i<4; i++) //�����0��3��
	{
		for (j = 1; j<6; j++) //�����1��5��(ӦΪ�����а������԰���������1��)
		{
			for (k = 0; k<7; k++)//�����0��6��
			{
				if (i + j + k == 8) { printf("%3d%3d%3d\n", i, j, k); count++; }
			}
		}
	}
	printf("һ����%d�ֿ��ܡ�\n", count);

	system("pause");
	return 0;
}