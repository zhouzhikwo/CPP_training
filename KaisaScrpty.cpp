#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	char passwd[100];
	int i, move;
	
	printf("Enter message to be encrypted:");
	gets_s(passwd);
	printf("Enter shift amount(1-25):");
	scanf_s("%d", &move);
	for (i = 0; i<strlen(passwd); i++){
		if (passwd[i] >= 'A' && passwd[i] <= 'Z'){
				passwd[i] = ((passwd[i] - 'A') + move) % 26 + 'A';
			}
		else if (passwd[i] >= 'a' && passwd[i] <= 'z'){
				passwd[i] = ((passwd[i] - 'a') + move) % 26 + 'a';
			}
	}

	printf("Encrypted message: %s\n", passwd);
		
	system("pause");
	return 0;
}
