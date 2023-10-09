#include <stdio.h>
#include <easyx.h>
#include <graphics.h>
#include <conio.h>
#include <time.h>

#define NODE_WIDTH 40

COLORREF randcolor()
{
	return RGB(rand() % 256, rand() % 256, rand() % 256);
}

typedef struct tagNode {
	int x;
	int y;
	COLORREF ncolor;
} TNode;

typedef enum direction {
	eUp,
	eDown,
	eLeft,
	eRight
} TDir;

typedef struct tagSnake {
	TNode nodes[100];
	int length;
	TDir dir;
	COLORREF scolor;
} TSnake;

// ---------------------------------------------------------------
void initSnake(TSnake* psnake, int len)
{
	COLORREF c = randcolor();
	psnake->scolor = c;

	float h, s, v;
	RGBtoHSV(c, &h, &s, &v);
	for (int i = 0; i < len; i++) {
		psnake->nodes[i].x = 5 + i;
		psnake->nodes[i].y = 7;
		//		psnake->nodes[i].ncolor = HSVtoRGB(h, s, v * 0.1 * i);
	};
	psnake->length = len;
	psnake->dir = eLeft;
}


void paintSnake(TSnake* psnake)
{
	TNode* nodes = psnake->nodes;
	int left, top, right, bottom;

	float h, s, v;
	RGBtoHSV(psnake->scolor, &h, &s, &v);

	for (int i = 0; i < psnake->length; i++) {
		left = nodes[i].x * NODE_WIDTH;
		top = nodes[i].y * NODE_WIDTH;
		right = (nodes[i].x + 1) * NODE_WIDTH;
		bottom = (nodes[i].y + 1) * NODE_WIDTH;

		setfillcolor(HSVtoRGB(h, s * (psnake->length - i) / psnake->length, v));
		solidrectangle(left, top, right, bottom);
	}
}


TNode snakeMove(TSnake* psnake)
{
	TNode* nodes = psnake->nodes;
	int length = psnake->length;
	TDir direction = psnake->dir;

	TNode tail = nodes[length - 1];
	for (int i = length - 1; i > 0; i--) {
		nodes[i] = nodes[i - 1];
	}
	if (direction == eUp)
		nodes[0].y--;
	else if (direction == eDown)
		nodes[0].y++;
	else if (direction == eLeft)
		nodes[0].x--;
	else
		nodes[0].x++;
	return tail;
}

void snakeReturn(TSnake* psnake)
{
	TNode* nodes = psnake->nodes;
	int length = psnake->length;

	for (int i = 0; i < length; i++) {

		if (nodes[i].y > 600 / NODE_WIDTH)
			nodes[i].y = nodes[i].y - 600 / NODE_WIDTH - 1;
		else if (nodes[i].y < 0)
			nodes[i].y = nodes[i].y + 600 / NODE_WIDTH + 1;

		if (nodes[i].x < 0)
			nodes[i].x = nodes[i].x + 800 / NODE_WIDTH + 1;
		else if (nodes[i].x > 800 / NODE_WIDTH)
			nodes[i].x = nodes[i].x - 800 / NODE_WIDTH - 1;
	}
}

void changeDirection(TSnake* psnake)
{
	ExMessage m;
	TDir d = psnake->dir;
	if (peekmessage(&m, EX_KEY)) {
		switch (m.vkcode) {
		case 'W':
			if (d != eDown)
				psnake->dir = eUp;
			break;
		case 'S':
			if (d != eUp)
				psnake->dir = eDown;
			break;
		case 'A':
			if (d != eRight)
				psnake->dir = eLeft;
			break;
		case 'D':
			if (d != eLeft)
				psnake->dir = eRight;
			break;
		}
	}
}

void paintFood(TNode food)
{
	int left, top, right, bottom;
	left = food.x * NODE_WIDTH;
	top = food.y * NODE_WIDTH;
	right = (food.x + 1) * NODE_WIDTH;
	bottom = (food.y + 1) * NODE_WIDTH;
	setfillcolor(food.ncolor);
	solidrectangle(left, top, right, bottom);
}

void createFood(TNode* pfood, TSnake* psnake)
{
	TNode* nodes = psnake->nodes;
	while (1) {
		pfood->x = rand() % (800 / NODE_WIDTH);
		pfood->y = rand() % (600 / NODE_WIDTH);

		int i;
		for (i = 0; i < psnake->length; i++) {
			if (nodes[i].x == pfood->x && nodes[i].y == pfood->y)
				break;
		}
		if (i < psnake->length)
			continue;
		else
			break;
	}
	pfood->ncolor = randcolor();
}

bool isGameOver(TSnake* psnake)
{
	TNode* nodes = psnake->nodes;
	for (int i = 1; i < psnake->length; i++) {
		if (nodes[0].x == nodes[i].x && nodes[0].y == nodes[i].y)
			return true;
	}
	return false;
}

void paintGrid()
{
	for (int y = 0; y < 600; y += NODE_WIDTH) {
		line(0, y, 800, y);
	}
	for (int x = 0; x < 800; x += NODE_WIDTH) {
		line(x, 0, x, 600);
	}
}

int main()
{
	initgraph(800, 600);
	srand(unsigned int(time(NULL)));

	TSnake snake;
	TNode food;

	initSnake(&snake, 5);
	createFood(&food, &snake);

	BeginBatchDraw();
	while (1) {
		cleardevice();
		paintGrid();

		paintSnake(&snake);
		paintFood(food);

		FlushBatchDraw();
		Sleep(250);
		changeDirection(&snake);

		TNode lastTail = snakeMove(&snake);
		if (snake.nodes[0].x == food.x && snake.nodes[0].y == food.y) {
			if (snake.length < 100) {
				snake.scolor = food.ncolor;
				snake.nodes[snake.length] = lastTail;
				snake.length++;
			}
			createFood(&food, &snake);
		}
		snakeReturn(&snake);
		if (isGameOver(&snake) == true) {
			settextcolor(RED);
			setbkmode(TRANSPARENT);
			settextstyle(100, 40, "微软雅黑");
			char str[] = "游戏结束";
			outtextxy(200, 200, str);
			FlushBatchDraw();
			Sleep(5000);
			initSnake(&snake, 5);
			createFood(&food, &snake);
		}
	}
	EndBatchDraw();
	getchar();
	closegraph();
	return 0;
}