#include<stdio.h>
#include<easyx.h>
#include<math.h>
#define PI 3.1415926
int main()
{
	initgraph(1024, 1024);
	setbkcolor(WHITE);
	cleardevice();
	setaspectratio(0.5, 0.5);

	setlinestyle(PS_SOLID, 10);
	setlinecolor(BLACK);
	setfillcolor(BLUE);
	fillellipse(118, 129, 990, 931);

	setfillcolor(WHITE);
	fillellipse(189, 271, 919, 931);
	fillellipse(375, 170, 555, 420);
	fillellipse(555, 170, 735, 420);

	setfillcolor(BLACK);
	solidcircle(484, 333, 25);
	solidcircle(617, 333, 25);
	setfillcolor(WHITE);
	solidcircle(484, 333, 10);
	solidcircle(617, 333, 10);

	setfillcolor(RED);
	fillcircle(554, 420, 35);

	line(554, 460, 554, 828);
	arc(320, 510, 789, 827, PI, 2 * PI);
	line(125, 313, 296, 410);
	line(83, 444, 270, 474);
	line(83, 595, 262, 537);
	line(819, 414, 990, 320);
	line(845, 478, 1029, 448);
	line(853, 542, 1029, 660);

	getchar();
	closegraph();



}