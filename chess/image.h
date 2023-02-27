#pragma once
#include<stdlib.h>
#include<Windows.h>
#include<easyx.h>
#include <graphics.h>
#include <conio.h>
void button(int x, int y, int w, int h, COLORREF bkcolor, TCHAR* text, int size)
{//左上坐标x,y,宽w，高h
	setbkmode(TRANSPARENT);
	setfillcolor(bkcolor);
	fillroundrect(x, y, x + w, y + h, 10, 10);
	// 输出字符串（MBCS 字符集）
	settextstyle(size, 0, L"黑体");

	int tx = x + (w - textwidth(text)) / 2;
	int ty = y + (h - textheight(text)) / 2;

	outtextxy(tx, ty, text);

}

void clear(int x, int y, int w, int h) {
	clearroundrect(x, y, x + w, y + h, 10, 10);

}

void printnum(int i) {
	TCHAR s[2];
	s[0] = '0' + i;
	s[1] = '\0';
	button(900, 600, 30,30, WHITE, s, 25);
	Sleep(1600);
	clear(900, 600, 30, 30);
}

unsigned int random(int n) {
	
	return n % 6;
}

IMAGE im;
void myrandom() {
	TCHAR s1[] = _T("点击骰子开始选点数");
	//TCHAR s2[] = _T("单击左键固定点数");
	button(530, 50, 230, 40, WHITE, s1, 25);
	//button(530, 90, 230,40, WHITE, s2, 25);

	loadimage(&im, _T("1.png"), 60, 60, 1);
	putimage(770, 60, &im);
}

int die(int flag) {
	int i = random(rand());
	if (flag == 0) {
		return 0;
	}
	else if (flag == 1) {

		for (int i = 0; i <= 3; i++) {
			loadimage(&im, _T("1.png"), 60, 60, 1);
			putimage(770, 60, &im);
			Sleep(10);

			loadimage(&im, _T("2.png"), 60, 60, 1);
			putimage(770, 60, &im);
			Sleep(10);

			loadimage(&im, _T("3.png"), 60, 60, 1);
			putimage(770, 60, &im);
			Sleep(10);

			loadimage(&im, _T("4.png"), 60, 60, 1);
			putimage(770, 60, &im);
			Sleep(10);

			loadimage(&im, _T("5.png"), 60, 60, 1);
			putimage(770, 60, &im);
			Sleep(10);

			loadimage(&im, _T("6.png"), 60, 60, 1);
			putimage(770, 60, &im);
			Sleep(10);
		}
		if (i == 0) {
			loadimage(&im, _T("1.png"), 60, 60, 1);
			putimage(770, 60, &im);
			return 1;
		}
		if (i== 1) {
			loadimage(&im, _T("2.png"), 60, 60, 1);
			putimage(770, 60, &im);
			return 2;
		}
		if (i == 2) {
			loadimage(&im, _T("3.png"), 60, 60, 1);
			putimage(770, 60, &im);
			return 3;
		}
		if (i== 3) {
			loadimage(&im, _T("4.png"), 60, 60, 1);
			putimage(770, 60, &im);
			return 4;
		}
		if (i == 4) {
			loadimage(&im, _T("5.png"), 60, 60, 1);
			putimage(770, 60, &im);
			return 5;
		}
		if (i == 5) {
			loadimage(&im, _T("6.png"), 60, 60, 1);
			putimage(770, 60, &im);
			return 6;
		}

	}
	//break;
//default: break;
//}

//}
//}
//_getch();
}


void airport(int x, int y, COLORREF color) {//左上角坐标，固定4个半径20像素的园，矩形110x110
	fillrectangle(x, y, x + 110, y + 110);
	setfillcolor(color);
	solidrectangle(x, y, x + 110, y + 110);
	circle(x + 30, y + 30, 20);
	circle(x + 30, y + 80, 20);
	circle(x + 80, y + 30, 20);
	circle(x + 80, y + 80, 20);
	setfillcolor(WHITE);
	solidcircle(x + 30, y + 30, 20);
	solidcircle(x + 30, y + 80, 20);
	solidcircle(x + 80, y + 30, 20);
	solidcircle(x + 80, y + 80, 20);
	TCHAR s1[] = _T("1");
	TCHAR s2[] = _T("2");
	TCHAR s3[] = _T("3");
	TCHAR s4[] = _T("4");
	button(x + 15, y + 15, 30, 30, color, s1, 20);
	button(x + 15, y + 65, 30, 30, color, s2, 20);
	button(x + 65, y + 15, 30, 30, color, s3, 20);
	button(x + 65, y + 65, 30, 30, color, s4, 20);

}

void arrow() {
	IMAGE arrowg, arrowb, arrowr, arrowy;
	loadimage(&arrowg, _T("Garrow.png"), 20, 40, 1);
	putimage(230, 30, &arrowg);//左上角坐标

	loadimage(&arrowr, _T("Rarrow.png"), 40, 20, 1);
	putimage(10, 300, &arrowr);//左上角坐标

	loadimage(&arrowb, _T("Barrow.png"), 20, 40, 1);
	putimage(230, 650, &arrowb);//左上角坐标

	loadimage(&arrowy, _T("Yarrow.png"), 100, 30, 1);
	putimage(710, 290, &arrowy);//左上角坐标

	loadimage(&arrowg, _T("Garrow.png"), 20, 40, 1);
	putimage(1130, 400, &arrowg);//左上角坐标

	loadimage(&arrowb, _T("Barrow.png"), 20, 40, 1);
	putimage(1130, 290, &arrowb);//左上角坐标

	loadimage(&arrowr, _T("Rarrow.png"), 40, 20, 1);
	putimage(1220, 300, &arrowr);//左上角坐标
}
