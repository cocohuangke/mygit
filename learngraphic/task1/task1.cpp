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

TPoint triangleSmall1[3] = { {0,0},{0,1 * UNIT_LEN},{1 * UNIT_LEN,0} };
TPoint triangleSmall2[3] = { {0,0},{0,1 * UNIT_LEN},{1 * UNIT_LEN,0} };
TPoint triangleMedium[3] = { {0,0},{0,sqrt(2) * UNIT_LEN},{sqrt(2) * UNIT_LEN,0} };
TPoint triangleBig1[3] = { {0,0},{0,2 * UNIT_LEN},{2 * UNIT_LEN,0} };
TPoint triangleBig2[3] = { {0,0},{0,2 * UNIT_LEN},{2 * UNIT_LEN,0} };
TPoint square[4] = { {0,0},{0,1 * UNIT_LEN},{1 * UNIT_LEN,1 * UNIT_LEN},{1 * UNIT_LEN,0} };
TPoint parallelRect[4] = { {0,0},{sqrt(2) * UNIT_LEN,0},{sqrt(2) / 2 * UNIT_LEN,sqrt(2) / 2 * UNIT_LEN},{-sqrt(2) / 2 * UNIT_LEN,sqrt(2) / 2 * UNIT_LEN} };

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

void drawBlock(TPoint* pts, int num, double angle, double xoff, double yoff) {
	rotateBlock(pts, num, angle);
	moveBlock(pts, num, xoff, yoff);
	POINT pts1[4];
	for (int i = 0; i < num; i++) {
		pts1[i].x = (int)round(pts[i]);
	}
}
int main() {
	initgraph(800, 800);
	setfillcolor(RED);
	rotateBlock((TPoint*)triangleSmall1, 3, -PI / 4);
	moveBlock((TPoint*)triangleSmall1, 3, sqrt(2) * 3 * UNIT_LEN / 2, sqrt(2) / 2 * UNIT_LEN);
	fillpolygon((POINT*)triangleSmall1, 3);

	rotateBlock((TPoint*)triangleSmall2, 3, PI / 4);
	moveBlock((TPoint*)triangleSmall2, 3, sqrt(2) * UNIT_LEN, sqrt(2) * UNIT_LEN);
	fillpolygon((POINT*)triangleSmall2, 3);

	rotateBlock((TPoint*)triangleMedium, 3, PI);
	moveBlock((TPoint*)triangleMedium, 3, 2 * sqrt(2) * UNIT_LEN, 2 * sqrt(2) * UNIT_LEN);
	fillpolygon((POINT*)triangleMedium, 3);
	
	rotateBlock((TPoint*)triangleBig1, 3, PI * 3 / 4);
	moveBlock((TPoint*)triangleBig1, 3, sqrt(2) * UNIT_LEN, sqrt(2) * UNIT_LEN);
	fillpolygon((POINT*)triangleBig1, 3);

	rotateBlock((TPoint*)triangleBig2, 3, PI * 5 / 4);
	moveBlock((TPoint*)triangleBig2, 3, sqrt(2) * UNIT_LEN, sqrt(2) * UNIT_LEN);
	fillpolygon((POINT*)triangleBig2, 3);

	rotateBlock((TPoint*)square, 4, -PI / 4);
	moveBlock((TPoint*)square, 4, sqrt(2) * UNIT_LEN, sqrt(2) * UNIT_LEN);
	fillpolygon((POINT*)square, 4);

	moveBlock((TPoint*)parallelRect , 4, sqrt(2) / 2 * UNIT_LEN, sqrt(2) * 3 * UNIT_LEN / 2);
	fillpolygon((POINT*)parallelRect, 4);

	getchar();
	closegraph;
	return 0;

}