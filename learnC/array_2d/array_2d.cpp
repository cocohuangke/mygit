#include<stdio.h>
int main1()
{
	int B[5][10] = {
		{0,1,2,3,4,5,6,7,8,9},
		{10,11,12,13,14,15,16,17,18,19},
		{20,21,22,23,24,25,26,27,28,29},
		{30,31,32,33,34,35,36,37,38,39},
		{40,41,42,43,44,45,46,47,48,49}
	};
	int(*pInt10)[10] = B;
	printf("pInt10=%d\n", pInt10);
	printf("pInt10+1=%d\n", pInt10 + 1);
	printf("pInt10+2=%d\n", pInt10 + 2);
	printf("pInt10+3=%d\n", pInt10 + 3);
	printf("pInt10+4=%d\n", pInt10 + 4);
	return 0;
}
int main2()
{
	int A[5] = { 1,2,3,4,5 };
	int B[5] = { 6,7,8,9,10 };
	int C[10] = {};
	int i;
	for (i = 0; i < 5; i++) {
		C[i * 2] = A[i];
		C[i * 2 + 1] = B[i];
	}
	for (i = 0; i < 10; i++)
		printf("%d\n", C[i]);
	return 0;
}
int main()
{
	int A[5] = { 1,2,3,4,5 };
	int B[5] = { 6,7,8,9,10 };
	int C[10] = {};
	int* pA = A;
	int* pB = B;
	int* pC = C;
	int i;
	for (i = 0; i < 5; i++) {
		*(pC + 2 * i) = *(pA + i);
		*(pC + 2 * i + 1) = *(pB + i);
	}
	for (i = 0; i < 10; i++)
		printf("%d\n", C[i]);
	return 0;
}