#include<stdio.h>
void swapint(int* x, int* y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}
int main()
{
	int a, b;
	int temp;
	a = 1;
	b = 2;
	printf("a=%d b=%d\n", a, b);
	swapint(&a, &b);
	printf("a=%d b=%d\n", a, b);
	return 0;
}

void swap(void* x, void* y, int size)
{
	char* px = (char*)x;
	char* py = (char*)y;
	char temp[128];
	for (int i = 0; i < size; i++)
		temp[i] = px[i];
	for (int i = 0; i < size; i++)
		px[i] = py[i];
	for (int i = 0; i < size; i++)
		py[i] = temp[i];
}
int main1()
{
	int x = 1, y = 10000;
	char str1[] = "akshdwei";
	char str2[] = "sskjdwew";
	printf("x=%d y=%d\n", x, y);
	swap(&x, &y, sizeof(int));
	printf("x=%d y=%d\n", x, y);
	printf("str1=%s str2=%s\n", str1, str2);
	swap(str1, str2, sizeof(str1));
	printf("str1=%s str2=%s\n", str1, str2);
	return 0;
}