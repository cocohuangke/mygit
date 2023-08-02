#include <stdio.h>
#include <easyx.h>
#include <math.h>
#include <conio.h>

void linearmotion(int x1, int y1, int x2, int y2, int v)
{
	double theta = atan2(y2 - y1, x2 - x1);
	double vx = cos(theta) * v;
	double vy = sin(theta) * v;

	double x, y;
	x = x1;
	y = y1;
	BeginBatchDraw();
	while (1) {
		cleardevice();
		solidcircle(x, y, 25);
		FlushBatchDraw();
		Sleep(40);
		x = x + (int)round(vx);
		y = y + (int)round(vy);
		if (fabs(x2 - x) <= 0 && fabs(y2 - y) <= 0)
			break;
	}
	EndBatchDraw();
}
int main()
{
	initgraph(800, 600);
	setorigin(400, 300);
	setaspectratio(1, -1);
	linearmotion(0, 200, 200, -200, 5);
	linearmotion(200, -200, -200, -200, 5);
	linearmotion(-200, -200, 0, 200, 5);

	getchar();
	closegraph();
	return 0;
}
