﻿#include <stdio.h>
#include <easyx.h>
#include <graphics.h>
#include <math.h>

#define BEAR_FRAMES 11
#define BOY_FRAMES 12

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
	loadimage(&imgBackground, "\\MyProjects\\git\\learngraphic\\image\\background.jpg");

	IMAGE imgArrBearFrames[BEAR_FRAMES];
	for (int i = 0; i < BEAR_FRAMES; i++) {
		TCHAR strImgPath[200];
		sprintf_s(strImgPath, "D:\\MyProjects\\git\\learngraphic\\image\\bear\\frames\\bear%d.png", i);
		loadimage(&imgArrBearFrames[i], strImgPath);
	}

	IMAGE imgArrBearMasks[BEAR_FRAMES];
	for (int i = 0; i < BEAR_FRAMES; i++) {
		TCHAR strImgPath[200];
		sprintf_s(strImgPath, "D:\\MyProjects\\git\\learngraphic\\image\\bear\\masks\\bearmask%d.png", i);
		loadimage(&imgArrBearMasks[i], strImgPath);
	}

	IMAGE imgArrBoyFrames[BOY_FRAMES];
	for (int i = 0; i < BOY_FRAMES; i++) {
		TCHAR strImgPath[200];
		sprintf_s(strImgPath, "D:\\MyProjects\\git\\learngraphic\\image\\bear\\frames\\boy%d.png", i);
		loadimage(&imgArrBoyFrames[i], strImgPath);
	}

	IMAGE imgArrBoyMasks[BOY_FRAMES];
	for (int i = 0; i < BOY_FRAMES; i++) {
		TCHAR strImgPath[200];
		sprintf_s(strImgPath, "D:\\MyProjects\\git\\learngraphic\\image\\bear\\masks\\boymask%d.png", i);
		loadimage(&imgArrBoyMasks[i], strImgPath);
	}
	int frame = 0;
	int x1 = -150;
	int x2 = 0;

	BeginBatchDraw();

	while (1) {
		putimage(0, 0, &imgBackground);
		putTransparentImage(x1, 180, &imgArrBearMasks[frame], &imgArrBearFrames[frame]);
		putTransparentImage(x2, 240, &imgArrBoyMasks[frame], &imgArrBoyFrames[frame]);
//		putimage(x2, 220, &imgArrBoyMasks[frame], SRCCOPY);
//		putimage(x2, 220, &imgArrBoyFrames[frame], SRCCOPY);


		FlushBatchDraw();

		frame++;
		x1 += 10;
		x2 += 10;

		if (frame >= BEAR_FRAMES)
			frame = 0;
		if (frame >= BOY_FRAMES)
			frame = 0;
		
		if (x1 >= 1200 + 150)
			x1 = -150;
		if (x2 >= 1200 + 150)
			x2 = -150;

		Sleep(50);
	}
	EndBatchDraw();
	getchar();
	closegraph();
	return 0;

}