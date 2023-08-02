#include<stdio.h>
#include<easyx.h>
#include<conio.h>
#include<time.h>
typedef struct {
	int x, y;
	int vx, vy;
	int r;
	int barLeft, barRight;
	int barTop, barBottom;
}GameData;

void reset(GameData* gdata)
{
	gdata->x = rand() % 401 - 200;
	gdata->y = rand() % 301 - 150;
	gdata->vx = 10;
	gdata->vy = 10;
	if (rand() % 2 == 0) {
		gdata->vx = -gdata->vx;
	}
	if (rand() % 2 == 0) {
		gdata->vy = -gdata->vy;
	}
	gdata->r = 25;
	gdata->barBottom = -300;
	gdata->barRight = 100;
	gdata->barLeft = -100;
	gdata->barTop = -280;
}
int main()
{
	initgraph(800, 600);
	setorigin(400, 300);
	setaspectratio(1, -1);

	srand((unsigned int)time(NULL));
	GameData gdata;
	reset(&gdata);

	BeginBatchDraw();
	while (1) {
		cleardevice();
		solidcircle(gdata.x, gdata.y, gdata.r);
		solidrectangle(gdata.barLeft, gdata.barTop, gdata.barRight, gdata.barBottom);
		FlushBatchDraw();
		Sleep(40);

		if (gdata.y >= 300 - gdata.r) {
			gdata.vy = -gdata.vy;
		}
		if (gdata.x <= -400 + gdata.r || gdata.x >= 400 - gdata.r) {
			gdata.vx = -gdata.vx;
		}
		if (gdata.y <= gdata.barTop + gdata.r && gdata.barLeft <= gdata.x && gdata.x <= gdata.barRight) {
			gdata.vy = -gdata.vy;
		}
		gdata.x += gdata.vx;
		gdata.y += gdata.vy;
		if (_kbhit() != 0) {
			char c = _getch();
			if (c == 'a') {
				if (gdata.barLeft > -400) {
					gdata.barLeft -= 20;
					gdata.barRight -= 20;
				}
			}
			else if (c == 'd') {
				if (gdata.barRight < 400) {
					gdata.barLeft += 20;
					gdata.barRight += 20;
				}
			}
		}
		if (gdata.y <= -300) {
			reset(&gdata);
		}
	}
	EndBatchDraw();
	closegraph();
	return 0;
}