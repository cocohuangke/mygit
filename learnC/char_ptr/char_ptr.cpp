#include<stdio.h>
int main1()
{
	char str[] = "helloworld";
	char* p = str;
	while (*p != '\0') {
		*p -= 32;
		p++;
	}
	puts(str);
	return 0;
}

int main()
{
	char str[] = "dlrowolleh";
	puts(str);
	char* pHead = str;
	char* pTail = str;
	while (*pTail)
		pTail++;
	pTail--;
	while (pHead <= pTail) {
		char tmp = *pHead;
		*pHead = *pTail;
		*pTail = tmp;
		pHead++;
		pTail--;
	}
	puts(str);
	return 0;
}