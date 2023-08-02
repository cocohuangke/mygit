#include<stdio.h>
int main()
{
	struct contact {
		char phone[20];
		char email[20];
	};
	struct person {
		const char name[20];
		int gender;
		double height;
		double weight;
		struct contact c;
	};
	struct person people[3] = {
		{"Timmy",1,170.00,60.00,{"13012345678","timmy@xxx.com"}},
		{"David",1,175.00,65.00,{"12343562454","david@xxx.com"}},
		{"Jane",2,165.00,55.00,{"12456796565","jane@xxx.com"}}
	};
	for (int i = 0; i < 3; i++) {
		struct person per = people[i];
		printf("%s ", per.name);
		printf("%d ", per.gender);
		printf("%.2f ", per.height);
		printf("%.2f ", per.weight);
		printf("%s ", per.c.phone);
		printf("%s\n", per.c.email);
	};
	return 0;
}
