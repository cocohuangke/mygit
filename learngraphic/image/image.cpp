#include <stdio.h>
#include <easyx.h>
#include <graphics.h>
#include <math.h>

#define BEAR_FRAMES 11

void putTransparentImage(int x, int y, const IMAGE* mask, const IMAGE* img)
{
	putimage(x, y, mask, SRCAND);
	putimage(x, y, img, SRCPAINT);
}

int main()
{
	initgraph(1200, 480);
	setbkcolor(WHITE);
	cleardevice();

	IMAGE imgBackground;
	loadimage(&imgBackground, "\\MyProjects\\git\\leargraphic\\image\\background.jpg");

	IMAGE imgArrBearFrames[BEAR_FRAMES];
	for (int i = 0; i < BEAR_FRAMES; i++) {
		TCHAR strImgPath[200];
		sprintf_s(strImgPath, "D:\\MyProjects\\git\\leargraphic\\image\\bear\\frames\\bear%d.png", i);
		loadimage(&imgArrBearFrames[i], strImgPath);
	}

	IMAGE imgArrBearMasks[BEAR_FRAMES];
	for (int i = 0; i < BEAR_FRAMES; i++) {
		TCHAR strImgPath[200];
		sprintf_s(strImgPath, "D:\\MyProjects\\git\\leargraphic\\image\\bear\\masks\\bearmask%d.png", i);
		loadimage(&imgArrBearMasks[i], strImgPath);
	}
	int frame = 0;
	int x = -150;

	BeginBatchDraw();

	while (1) {
		putimage(0, 0, &imgBackground);
		putTransparentImage(x, 180, &imgArrBearMasks[frame], &imgArrBearFrames[frame]);

		FlushBatchDraw();

		frame++;
		x += 10;

		if (frame >= BEAR_FRAMES)
			frame = 0;
		if (x >= 1200 + 150)
			x = -150;

		Sleep(50);
	}
	EndBatchDraw();
	getchar();
	closegraph();
	return 0;

}