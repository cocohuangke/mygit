#include <iostream>
#include<Cstdio>

int main()
{
	double a, b;
	int m, n;
	scanf_s("%lf", &a);
	scanf_s("%lf", &b);
	m = a / b;
	n = a - m * b;
	printf("%d\n", m);
	printf("%d\n", n);
	return 0;
}
