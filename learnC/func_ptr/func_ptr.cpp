#include <stdio.h>
#include <string.h>
void TheShawshankRedemption()
{
	printf("1.肖申克的救赎\n");
}
void Zootopia()
{
	printf("2.疯狂动物城\n");
}
void Interstellar()
{
	printf("3.星际穿越\n");
}
void TheLegendof1900()
{
	printf("4.海上钢琴师\n");
}
void TheMatrix()
{
	printf("5.黑客帝国\n");
}

int main1()
{
	void (*movies[5])() =
	{ TheShawshankRedemption ,Zootopia ,Interstellar ,TheLegendof1900 ,TheMatrix };
	char playlist[21];
	scanf_s("%s", playlist, 10);

	printf("%s\n", playlist);
	for (int i = 0; playlist[i] != '\0'; i++)
	{
		char num = playlist[i];
		num = num - '0';
		num--;
		movies[num]();

	}
	return 0;
}

int main()
{
	const char* names[] = { "xskdjs", "fkdwc", "xjcy", "hsgqs", "hkdg" };
	void (*movies[5])() =
	{ TheShawshankRedemption ,Zootopia ,Interstellar ,TheLegendof1900 ,TheMatrix };
	char name[21];
	scanf_s("%s", name, 10);
	printf("%s\n", name);
	for (int i = 0; i < 5; i++)
	{
		if (strcmp(name, names[i]) == 0) {
			movies[i]();
			return 0;
		}
	}
	printf("not found\n");
	return 0;
}