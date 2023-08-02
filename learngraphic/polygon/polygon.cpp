#include<stdio.h>
#include<easyx.h>
#include<math.h>
#define PI 3.1415926
POINT points[50] = { 0 };
//画一个n边形
COLORREF randcolor()
{
	return RGB(rand() % 256, rand() % 256, rand() % 256);
}

void drawNpolygon(int r, int n)//r是多边形的外接圆半径 n是边数
{
	double theta = PI / 2;
	double delta = 2 * PI / n;
	TCHAR str[20];
	for (int i = 0; i < n; i++) {
		points[i].x = cos(theta + delta * i) * r;
		points[i].y = sin(theta + delta * i) * r;
	}
	setfillcolor(randcolor());
	setlinecolor(randcolor());
	setlinestyle(rand() % 9, 4);
	fillpolygon(points, n);
	swprintf_s(str, _T("%d"), n);//将n输出到字符串缓存里
	outtextxy(0, 0, str);//在原点输出n边形字符串
}

int main()
{
	initgraph(800, 800);
	setorigin(400, 400);
	//	setaspectratio(1, -1);
	for (int n = 3; n <= 50; n++) {
		cleardevice();
		drawNpolygon(300, n);
		Sleep(500);
	}
	getchar();
	closegraph();
	return 0;
}