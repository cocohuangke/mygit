#include<Cstdio>
#include<iostream>
using namespace std;
int main()
{
	double a, b, h, S;
	scanf_s("%lf %lf %lf", &a, &b, &h);
	S = (a + b) * h / 2;
	printf("%.2lf", S);
	return 0;
}