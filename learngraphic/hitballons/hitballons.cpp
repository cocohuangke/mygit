#include<stdio.h>
#include<easyx.h>
#include<math.h>

#define WINDOW_HEIGHT 800
#define WINDOW_WIDTH 600
#define MAX_IN_WINDOW 5
#define BALLON_RADIUS 30

typedef struct {
	int x;
	int y;
	int v;
	int r;
	COLORREF color;
}balloon;

balloon generateBallon()
{
	balloon b;
	int m, n;
	m = 100;
	n = 700;
	b.x = rand() % (n - m + 1) + m;
	b.y = WINDOW_WIDTH;
	b.r = BALLON_RADIUS;
	m = 1;
	n = 3;
	b.v = rand() % (n - m + 1) + m;
	b.color = RGB(rand() % 256, rand() % 256, rand() % 256);
	return b;
}

int main()
{
	initgraph(WINDOW_HEIGHT, WINDOW_WIDTH);
	setbkcolor(WHITE);
	cleardevice();

	balloon arrBalloons[MAX_IN_WINDOW];
	for (int i = 0; i < MAX_IN_WINDOW; i++)
		arrBalloons[i] = generateBallon();

	int current = MAX_IN_WINDOW;
	int mouseX = 0;
	int mouseY = 0;

	timeBeginPeriod(1);
	LARGE_INTEGER startCount, endCount, F;
	QueryPerformanceFrequency(&F);
	BeginBatchDraw();
	while (1) {
		QueryPerformanceCounter(&startCount);

		cleardevice();
		for (int i = 0; i < MAX_IN_WINDOW; i++) {
			setfillcolor(arrBalloons[i].color);
			solidcircle(arrBalloons[i].x, arrBalloons[i].y, arrBalloons[i].r);
		}

		for (int i = 0; i < MAX_IN_WINDOW; i++) {
			arrBalloons[i].y -= arrBalloons[i].v;
		}

		int i = 0;
		while (i < current) {
			int y = arrBalloons[i].y;
			if (y < -BALLON_RADIUS) {
				for (int j = i; j < current - 1; j++)
					arrBalloons[j] = arrBalloons[j + 1];
				current--;
			}
			else
				i++;
		}
		if (current < MAX_IN_WINDOW) {
			arrBalloons[current] = generateBallon();
			current++;
		}
		setlinecolor(RGB(237, 178, 29));
		setlinestyle(PS_SOLID, 3);
		circle(mouseX, mouseY, 20);
		line(mouseX - 20, mouseY, mouseX + 20, mouseY);
		line(mouseX, mouseY - 20, mouseX, mouseY + 20);

		QueryPerformanceCounter(&endCount);
		long long elapse = (endCount.QuadPart - startCount.QuadPart) * 1000000 / F.QuadPart;



		while (elapse < 1000000 / 60) {
			Sleep(1);

			ExMessage msg;
			bool isOK = peekmessage(&msg, EX_MOUSE);
			if (isOK == true) {
				if (msg.message == WM_MOUSEMOVE) {
					mouseX = msg.x;
					mouseY = msg.y;
				}
				else if (msg.message == WM_LBUTTONDOWN) {
					int i = 0;
					while (i < current) {
						int ballX = arrBalloons[i].x;
						int ballY = arrBalloons[i].y;
						int distance = (int)sqrt(pow(ballY - msg.y, 2) + pow(ballX - msg.x, 2));
						if (distance < BALLON_RADIUS) {
							for (int j = i; j < current - 1; j++)
								arrBalloons[j] = arrBalloons[j + 1];
							current--;
						}
						else
							i++;
					}
				}
			}
			QueryPerformanceCounter(&endCount);
			elapse = (endCount.QuadPart - startCount.QuadPart) * 1000000 / F.QuadPart;

		}
		FlushBatchDraw();
	}
	EndBatchDraw();
	timeEndPeriod(1);
	getchar();
	closegraph();
	return 0;
}