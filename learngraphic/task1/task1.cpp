#include<stdio.h>
#include<easyx.h>
#include<math.h>
#include<graphics.h>

#define PI 3.1415926
#define UNIT_LEN 100
POINT triangleSmall1[3] = { {0,0},{0,1 * UNIT_LEN},{1 * UNIT_LEN,0} };
POINT triangleSmall2[3] = { {0,0},{0,1 * UNIT_LEN},{1 * UNIT_LEN,0} };
POINT triangleMedium[3] = { {0,0},{0,sqrt(2) * UNIT_LEN},{sqrt(2) * UNIT_LEN,0} };
POINT triangleBig1[3] = { {0,0},{0,2 * UNIT_LEN},{2 * UNIT_LEN,0} };
POINT triangleBig2[3] = { {0,0},{0,2 * UNIT_LEN},{2 * UNIT_LEN,0} };
POINT square[4] = { {0,0},{0,1 * UNIT_LEN},{1 * UNIT_LEN,1 * UNIT_LEN},{1 * UNIT_LEN,0} };
POINT parallelRect[4] = { {0,0},{sqrt(2) * UNIT_LEN,0},{sqrt(2) / 2 * UNIT_LEN,sqrt(2) / 2 * UNIT_LEN},{-sqrt(2) / 2 * UNIT_LEN,sqrt(2) / 2 * UNIT_LEN} };

void moveBlock(POINT* pts, int num, double xoff, double yoff) {
	for (int i = 0; i < num; i++) {
		pts[i].x = pts[i].x + xoff;
		pts[i].y = pts[i].y + yoff;
	}
}
void rotateBlock(POINT*pts, int num, double angle) {
	double rad = angle;
	for (int i = 0; i < num; i++) {
		double x = pts[i].x;
		double y = pts[i].y;
		pts[i].x = x * cos(rad) - y * sin(rad);
		pts[i].y = x * sin(rad) + y * cos(rad);
	}
}
int main() {
	initgraph(800, 800);
	setfillcolor(RED);
	rotateBlock((POINT*)triangleSmall1, 3, -PI / 4);
	moveBlock((POINT*)triangleSmall1, 3, sqrt(2) * 3 * UNIT_LEN / 2, sqrt(2) / 2 * UNIT_LEN);
	fillpolygon((POINT*)triangleSmall1, 3);

	rotateBlock((POINT*)triangleSmall2, 3, PI / 4);
	moveBlock((POINT*)triangleSmall2, 3, sqrt(2) * UNIT_LEN, sqrt(2) * UNIT_LEN);
	fillpolygon((POINT*)triangleSmall2, 3);

	rotateBlock((POINT*)triangleMedium, 3, PI);
	moveBlock((POINT*)triangleMedium, 3, 2 * sqrt(2) * UNIT_LEN, 2 * sqrt(2) * UNIT_LEN);
	fillpolygon((POINT*)triangleMedium, 3);
	
	rotateBlock((POINT*)triangleBig1, 3, PI * 3 / 4);
	moveBlock((POINT*)triangleBig1, 3, sqrt(2) * UNIT_LEN, sqrt(2) * UNIT_LEN);
	fillpolygon((POINT*)triangleBig1, 3);

	rotateBlock((POINT*)triangleBig2, 3, PI * 5 / 4);
	moveBlock((POINT*)triangleBig2, 3, sqrt(2) * UNIT_LEN, sqrt(2) * UNIT_LEN);
	fillpolygon((POINT*)triangleBig2, 3);

	rotateBlock((POINT*)square, 4, -PI / 4);
	moveBlock((POINT*)square, 4, sqrt(2) * UNIT_LEN, sqrt(2) * UNIT_LEN);
	fillpolygon((POINT*)square, 4);

	moveBlock((POINT*)parallelRect , 4, sqrt(2) / 2 * UNIT_LEN, sqrt(2) * 3 * UNIT_LEN / 2);
	fillpolygon((POINT*)parallelRect, 4);

	getchar();
	closegraph;
	return 0;

}