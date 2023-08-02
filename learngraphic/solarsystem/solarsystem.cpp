#include<stdio.h>
#include<easyx.h>
#include<math.h>
#define PI 3.1415926

void drawstar(int x, int y, double startangle, int r)
{
	double delta = 2 * PI / 5;
	POINT points[5];
	for (int i = 0; i < 5; i++) {
		points[i].x = cos(startangle + 2 * delta * i) * r + x;
		points[i].y = sin(startangle + 2 * delta * i) * r + y;
	}
	solidpolygon(points, 5);
}
int main()
{
	initgraph(800, 800);
	setorigin(400, 400);
	setaspectratio(1, -1);
	cleardevice();
	setfillcolor(RGB(255, 255, 255));
	setpolyfillmode(WINDING);
	int x, y, p, q;
	double starttheta = 0;
	double dtheta = 0.025;
	int ea = 300, eb = 150;
	int ma = 80, mb = 50;
	BeginBatchDraw();
	while (1) {
		cleardevice();
		drawstar(0, 0, PI / 2, 50);
		x = cos(starttheta) * ea;
		y = sin(starttheta) * eb;
		drawstar(x, y, PI / 2, 25);
		p = x + cos(starttheta) * ma;
		q = y + sin(starttheta) * mb;
		drawstar(p, q, PI / 2, 15);
		starttheta = starttheta + dtheta;
		FlushBatchDraw();
		Sleep(40);
	}
	EndBatchDraw();
	getchar();
	closegraph();
	return 0;
}