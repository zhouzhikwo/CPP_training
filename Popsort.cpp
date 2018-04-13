#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

int mystrcmp(const char* p1, const char* p2) {
	while (*p1 == *p2) {
		if (*p1 == '\0')
			return 0;
		p1++;
		p2++;
	}
	return *p1 - *p2;
}

void mypopsort(int *pList, int listSize) {
	int temp;
	for (int i = 0; i < listSize; i++) {
		for (int j = 0; j < listSize; j++) {
			if (pList[i] < pList[j]) {
				temp = pList[i];
				pList[i] = pList[j];
				pList[j] = temp;
			}
		}
	}

	return;
}

void main(void) {
	const char* p1 = "stringA";
	const char* p2 = "string";
	cout << mystrcmp(p1, p2) << endl;

	int pList[] = { 1,6,8,9,7,4 };
	int listSize = 6;
	mypopsort(pList, listSize);
	for (int i = 0; i < listSize; i++) {
		cout << pList[i] << ' ';
	}
	cout << endl;

	system("pause");
	return;
}