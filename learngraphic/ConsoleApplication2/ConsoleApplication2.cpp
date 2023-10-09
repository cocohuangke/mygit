#include <iostream>
#include<Cstdio>

int main()
{
	int a, b;
	int ans1, ans2, ans3;
	int ans4, ans5;
	scanf_s("%d", &a);
	scanf_s("%d", &b);
	ans1 = a + b;
	ans2 = a - b;
	ans3 = a * b;
	ans4 = a / b;
	ans5 = a % b;
	printf("%d\n", ans1);
	printf("%d\n", ans2);
	printf("%d\n", ans3);
	printf("%d\n", ans4);
	printf("%d\n", ans5);
	return 0;
}

