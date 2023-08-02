#include <stdio.h>
#include <easyx.h>
#include <math.h>
#include <conio.h>
#define PI 3.1415926
#define NUM_OF_BALLS 100

typedef struct tagBall {
	int x;
	int y;
	int vx;
	int vy;
	COLORREF color;
} TBall;

int r = 10;
int count = 10;
TBall* balls;
int randRange(int from, int to)
{
	return rand() % (to - from + 1) + from;
}

void initBall(TBall* pb)
{
	pb->x = randRange(-400 + r, 400 - r);
	pb->y = randRange(-300 + r, 300 - r);
	int v = randRange(3, 8);
	double theta = rand() % 360;
	pb->vx = v * cos(theta * PI / 180);
	pb->vy = v * sin(theta * PI / 180);
	pb->color = HSVtoRGB(rand() % 360, 0.8f, 0.9f);
}
void drawBalls()
{
	for (int i = 0; i < count; i++) {
		setfillcolor(balls[i].color);
		fillcircle(balls[i].x, balls[i].y, r);
	}
}
void moveBalls()
{
	for (int i = 0; i < count; i++) {
		if (balls[i].x >= 400 - r || balls[i].x <= -400 + r) {
			balls[i].vx = -balls[i].vx;
		}
		if (balls[i].y >= 300 - r || balls[i].y <= -300 + r) {
			balls[i].vy = -balls[i].vy;
		}
		balls[i].x += balls[i].vx;
		balls[i].y += balls[i].vy;
	}
}
void addBalls()
{
	TBall* p = (TBall*)realloc(balls, sizeof(TBall) * (count + 1));
	if (p != NULL) {
		balls = p;
		count++;
		initBall(&balls[count - 1]);
	}
}

void delBalls()
{
	if (count < 1)
		return;
	else if (count == 1) {
		TBall* p = (TBall*)realloc(balls, sizeof(TBall) * (count - 1));
		balls = p;
		count--;
	}
	else if (count > 1) {
		TBall* p = (TBall*)realloc(balls, sizeof(TBall) * (count - 1));
		if (p != NULL) {
			balls = p;
			count--;
		}
	}
}

int main()
{
	initgraph(800, 600);
	setorigin(400, 300);
	setaspectratio(1, -1);
	balls = (TBall*)malloc(sizeof(TBall) * count);

	for (int i = 0; i < count; i++) {
		initBall(&balls[i]);
	}
	BeginBatchDraw();
	ExMessage m;
	while (1) {
		cleardevice();
		drawBalls();
		FlushBatchDraw();
		Sleep(40);
		moveBalls();
		if (peekmessage(&m)) {
			if (m.vkcode == VK_ESCAPE)
				break;
			else if (m.ch == '+') {
				addBalls();
			}
			else if (m.ch == '-') {
				delBalls();
			}
		}
	}
	free(balls);
	EndBatchDraw();
	closegraph();
	return 0;
}