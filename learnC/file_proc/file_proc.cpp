#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
void fileEofOrError(FILE* pFile)
{
	if (feof(pFile) != 0)
		printf("end of file\n");
	else if (ferror(pFile) != 0)
		printf("file access error\n");
}
int main()
{
	FILE* pFile1;
	FILE* pFile2;
	errno_t err = fopen_s(&pFile1, "d://data.txt", "r");
	fseek(pFile1, 0, SEEK_END);
	int f_len = ftell(pFile1);

	char* str = (char*)malloc(f_len + 1);
	fseek(pFile1, 0, SEEK_SET);



	int get = fread(str, 1, 100, pFile1);
	printf("%d\n", get);
	str[get] = '\0';
	printf("%s\n", str);



	for (int i = 0; i < get; i++) {
		if (str[i] >= 97)
			str[i] = toupper(str[i]);
		else
			str[i] = tolower(str[i]);
	}

	printf("%s\n", str);
	err = fopen_s(&pFile2, "d://data1.txt", "w+");
	fwrite(str, 1, get, pFile2);
	free(str);
	return 0;
}