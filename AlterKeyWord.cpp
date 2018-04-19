#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int ReplaceInString(char* strLine, const char* strSearch, const char* strReplace) {
	int nSearch = strlen(strSearch);
	int nLine = strlen(strLine);

	char strNew[512] = "", *pTarStr = strNew;
	char *pSrcStr0 = strLine, *pSrcStr1 = strstr(strLine, strSearch);

	int nFinds = 0;
	while (pSrcStr1) {
		int n = pSrcStr1 - pSrcStr0;
		memcpy(pTarStr, pSrcStr0, n * sizeof(char));
		strcat(pTarStr, strReplace);
		pTarStr += (n + nSearch - 1);

		pSrcStr0 = pSrcStr1 + nSearch;
		pSrcStr1 = strstr(pSrcStr0, strSearch);

		nFinds++;
	}

	if (nFinds > 0) {
		if (pSrcStr0 < strLine + nLine) strcat(strNew, pSrcStr0);
		strcpy(strLine, strNew);
	}

	return nFinds;
}

int ReplaceInFile(const char* strSrcFile, const char* strTarFile, const char* strSearch, const char* strReplace) {
	FILE *fSrc = nullptr, *fTar = nullptr;
	errno_t err1 = fopen_s(&fSrc, strSrcFile, "rt");
	errno_t err2 = fopen_s(&fTar, strTarFile, "wt");
	if (!fSrc || !fTar) {
		if (fSrc) fclose(fSrc);
		if (fTar) fclose(fTar);
		return 0;
	}

	int nFinds = 0;
	char strLine[256];
	while (!feof(fSrc)) {
		fgets(strLine, 256, fSrc);
		nFinds += ReplaceInString(strLine, strSearch, strReplace);
		fputs(strLine, fTar);
	}

	fclose(fSrc);
	fclose(fTar);

	return nFinds;
}

void main() {
	char strSearch[] = "NULL";
	char strReplace[] = "nullptr";
	char strSrcFile[] = "E:\\photo.txt";
	char strTarFile[] = "E:\\photo-new.txt";

	int nFind = ReplaceInFile(strSrcFile, strTarFile, strSearch, strReplace);
	printf("Total %d find and replace!\n", nFind);
}
