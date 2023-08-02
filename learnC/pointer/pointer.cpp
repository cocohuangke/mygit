#include<stdio.h>
int main1()
{
	int nums[] = { 672538,52738,73928,38946 };
	printf("&n1=%lu\n", &nums[0]);
	printf("&n2=%lu\n", &nums[1]);
	printf("&n3=%lu\n", &nums[2]);
	printf("&n4=%lu\n", &nums[3]);
	int* p = &nums[0];
	printf("p=%u\n", p);
	printf("p+1=%u\n", p + 1);
	printf("p+2=%u\n", p + 2);
	printf("p+3=%u\n", p + 3);
	putchar('\n');
	*p = 111;
	*(p + 1) = 222;
	*(p + 2) = 333;
	*(p + 3) = 444;
	printf("nums[0]=%d,%d\n", nums[0], *p);
	printf("nums[1]=%d,%d\n", nums[1], *(p + 1));
	printf("nums[2]=%d,%d\n", nums[2], *(p + 2));
	printf("nums[3]=%d,%d\n", nums[3], *(p + 3));

	return 0;

}

int main()
{
	char str[] = "khdjkwqkljd";
	printf("&n1=%lu\n", &str[0]);
	printf("&n2=%lu\n", &str[1]);
	printf("&n3=%lu\n", &str[2]);
	printf("&n4=%lu\n", &str[3]);
	char* p = &str[0];
	printf("p=%u\n", p);
	printf("p+1=%u\n", p + 1);
	printf("p+2=%u\n", p + 2);
	printf("p+3=%u\n", p + 3);
	putchar('\n');
	*p = 'A';
	*(p + 1) = 'B';
	*(p + 2) = 'C';
	*(p + 3) = 'D';
	printf("nums[0]=%c,%c\n", str[0], *p);
	printf("nums[1]=%c,%c\n", str[1], *(p + 1));
	printf("nums[2]=%c,%c\n", str[2], *(p + 2));
	printf("nums[3]=%c,%c\n", str[3], *(p + 3));
	printf("str[]=%s\n", str);
	return 0;
}