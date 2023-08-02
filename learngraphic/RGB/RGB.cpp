#include<stdio.h>
#include<easyx.h>
int main()
{
	initgraph(800, 600);
	float s = 0.76;
	float dS = s / 600;
	for (int i = 0; i < 600; i++) {
		setlinecolor(HSVtoRGB(216, s, 0.95));
		line(0, i, 800, i);
		s = s - dS;
	}
	float h = 0;
	float dH = 360.0 / 100.0;
	for (int r = 300; r >= 200; r--) {
		setlinecolor(HSVtoRGB(h, 1, 1));
		circle(400, 600, r);
		h = h + dH;
	}
	getchar();
	closegraph();
	return 0;

}
