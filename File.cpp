#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>
#include <direct.h>

void CreateDirectory(const char* strPath) {
	// split the input directory by the last '\\'
	char strTemp[256];
	strcpy_s(strTemp, _countof(strTemp), strPath);
	char* p = strrchr(strTemp, '\\');

	if (!p) return;                             // terminate the recursion

	*p = '\0';                                  // and get the parent directory name

	// recurrent iterated to create parent directories
	CreateDirectory(strTemp);
	_mkdir(strPath);                           //if (_access(strPath, 0) != 0) _mkdir(strPath);
}


int main(void)
{
	CreateDirectory("E:\\test\\level1\\level2\\level3");

	system("pause");
	return 0;
}