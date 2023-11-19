#include<stdio.h>
#include<easyx.h>
#include<math.h>
#include<graphics.h>

#define PI 3.1415926
#define UNIT_LEN 100

typedef struct tagTPoint {
	double x;
	double y;
} TPoint;

typedef struct tagBlock {
	TPoint pts[4];
	double xoff, yoff;
	int num;
	COLORREF color;
	double angle;
}TBlock;

TBlock triangleSmall1 = { { {0,0},{0,1 * UNIT_LEN},{1 * UNIT_LEN,0},{0,0} },3,YELLOW, -PI / 4 };
TBlock triangleSmall2 = { { {0,0},{0,1 * UNIT_LEN},{1 * UNIT_LEN,0},{0,0}},3,WHITE, PI / 4 };
TBlock triangleMedium = { { {0,0},{0,sqrt(2) * UNIT_LEN},{sqrt(2) * UNIT_LEN,0},{0,0} },3,BLUE, PI };
TBlock triangleBig1 = { { {0,0},{0,2 * UNIT_LEN},{2 * UNIT_LEN,0},{0,0} }, 3,RED, PI * 3 / 4 };
TBlock triangleBig2 = { { {0,0},{0,2 * UNIT_LEN},{2 * UNIT_LEN,0},{0,0} }, 3,GREEN, PI * 5 / 4 };
TBlock square = { { {0,0},{0,1 * UNIT_LEN},{1 * UNIT_LEN,1 * UNIT_LEN},{1 * UNIT_LEN,0} },4,CYAN, -PI / 4};
TBlock parallelRect = { { {0,0},{sqrt(2) * UNIT_LEN,0},{sqrt(2) / 2 * UNIT_LEN,sqrt(2) / 2 * UNIT_LEN},{-sqrt(2) / 2 * UNIT_LEN,sqrt(2) / 2 * UNIT_LEN} },4,BROWN, 0 };

void moveBlock(TPoint* pts, int num, double xoff, double yoff) {
	for (int i = 0; i < num; i++) {
		pts[i].x = pts[i].x + xoff;
		pts[i].y = pts[i].y + yoff;
	}
}
void rotateBlock(TPoint*pts, int num, double angle) {
	double rad = angle;
	for (int i = 0; i < num; i++) {
		double x = pts[i].x;
		double y = pts[i].y;
		pts[i].x = x * cos(rad) - y * sin(rad);
		pts[i].y = x * sin(rad) + y * cos(rad);
	}
}

void drawBlock(TBlock*blk) {
	rotateBlock(blk->pts, blk->num, blk->angle);
	moveBlock(blk->pts, blk->num, blk->xoff,blk->yoff);
	POINT pts1[4];
	for (int i = 0; i < blk->num; i++) {
		pts1[i].x = (int)round(blk->pts[i].x);
		pts1[i].y = (int)round(blk->pts[i].y);
	}
	setfillcolor(blk->color);
	fillpolygon(pts1, blk->num);
}
int main() {
	initgraph(800, 800);

	drawBlock(&triangleSmall1);
	drawBlock(&triangleSmall2);
	drawBlock(&triangleMedium);
	drawBlock(&triangleBig1);
	drawBlock(&triangleBig2);
	drawBlock(&square);
	drawBlock(&parallelRect);

	getchar();
	closegraph;
	return 0;

}