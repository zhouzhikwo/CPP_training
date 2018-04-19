#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void main(){
	int n, i;
	printf("please input n=");
	scanf_s("%d", &n);
	printf("=");
	for (i = 2; i<n; i++){
		while (i != n){
			if (n%i == 0){
				n = n / i;
				printf("%d*", i);
			}
			else
				break;
		}
	}
	printf("%d\n", n);

	system("pause");
}
