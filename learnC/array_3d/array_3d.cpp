#include<stdio.h>
int main()
{
	int A[3][3] = {
		{1,2,3},
		{4,5,6},
		{7,8,9}
	};
	int B[3][3];
	int n = 3;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
		{
			B[j][i] = A[n - i - 1][j];
		}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++)
			printf("%d ", A[i][j]);
		putchar('\n');
	}
	putchar('\n');
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++)
			printf("%d ", B[i][j]);
		putchar('\n');
	}
	return 0;
}