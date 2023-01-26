#define _CRT_SECURE_NO_WARNINGS 1
#define lenth 19
//#define debug
#include<stdio.h>
#include"image.h"//这里所需的头文件已调用

typedef struct Square {
	COLORREF color;
	int x;
	int y;//位置坐标
	int colornum;//格子里有几方的棋子,由于设置的三维数组，可能这个为每一颗棋子的绝对位置
}square;

typedef struct CHESS {
	square cur;
	int pos;//所处的位置状态，0是未出机场，1是出机场，2是已到终点
}chess;

square sq[3][4][32];//3种颜色，每种4个棋，第几个格;0R,1G,2B,下同
chess ch[3][4][32];//3种颜色，每种4个棋,在第几个格子上



TCHAR st1[3] = _T("1\0");
TCHAR st2[3] = _T("2\0");
TCHAR st3[3] = _T("3\0");
TCHAR st4[3] = _T("4\0");

void move(chess player, chess cur, TCHAR* t) {//从当前位置
	clear(player.cur.x, player.cur.y, 30, 30);
	getpixel(player.cur.x +33, player.cur.y + 33);
	solidroundrect(player.cur.x, player.cur.y, player.cur.x + 28, player.cur.y + 28, 10, 10);
	button(cur.cur.x , cur.cur.y, 30, 30, cur.cur.color, t, 20);
}

void yourturn() {
	TCHAR str[] = _T("到你了");
	button(600, 600, 100, 45, WHITE, str, 25);
	Sleep(2000);
	clear(598,598, 105, 49);
}
void yourchoice() {
	TCHAR str[] = _T("请选择你要动的棋子,输入1/2/3/4");
	button(600, 680, 400, 45, WHITE, str, 25);
	Sleep(1800);
	clear(598,678, 405, 49);
}
int clickrandom() {
	yourturn();
	ExMessage msg;
	while (true) {
		if (peekmessage(&msg, EM_MOUSE)) {
			switch (msg.message) {
			case WM_LBUTTONDOWN:
				if (msg.x >= 770 && msg.x <= 830 && msg.y >= 60 && msg.y <= 120) {
					return die(1);
				}
			}
		}
	}
}//已包含yourturn输出字符

void rules() {
	initgraph(800, 600);
	cleardevice();
	setbkcolor(WHITE);
	settextstyle(24, 0, L"黑体");
	gettextcolor();
	settextcolor(BLACK);
	outtextxy(150, 120, _T("请注意移动后会留下印记，带数字的是棋子"));
	outtextxy(150, 160, _T("如果数字没有了说明该棋子已经到终点抹除"));
	outtextxy(140, 200, _T("本游戏3个玩家，1人操作，你获得首次掷色子机会"));
	outtextxy(130, 240, _T("白格下方将有一些提示操作，点击鼠标左键掷色子"));
	outtextxy(30, 280, _T("当显示”到你了“并消失后，才能点色子，按键盘上对应数字移动棋子"));
	outtextxy(40, 320, _T("机场有棋子时，掷到6才能起动，不是6则只能移动已经出发的棋子"));
	outtextxy(200, 360, _T("无子可动则自动继续电脑玩家操作"));
	Sleep(1000);
		TCHAR c[] = _T("按任意键继续");
	button(240, 410, 280, 60, YELLOW,c,30);
	_getch();
	cleardevice();
	
}
void warning() {
	TCHAR str[] = _T("请规范操作");
	button(600, 670, 130, 40, YELLOW, str, 25); 
	Sleep(2100); 
	clear(598, 668, 134, 44);
}
void over(int i) {
	initgraph(800, 600);
	cleardevice();
	setbkcolor(WHITE);
	settextstyle(24, 0, L"黑体");
	gettextcolor();
	settextcolor(BLACK);
	if(i==0)outtextxy(140, 200, _T("红方获胜"));
	if(i==1)outtextxy(140, 200, _T("绿方获胜"));
	if(i==2)outtextxy(140, 200, _T("蓝方获胜"));
	Sleep(1000);
	TCHAR c[] = _T("按任意键继续");
	button(240, 370, 280, 60, YELLOW, c, 30);
	_getch();
	cleardevice();
	
}



void mode1() {
	square sq[3][4][32];//3种颜色，每种4个棋，第几个格;0R,1G,2B,下同
	square squ[4][32];//3W色
	chess ch[3][4][32];//3种颜色，每种4个棋,在第几个格子上
    //145-209棋子格子初始化
	ch[0][0][0].cur.x =25 ; ch[0][1][0].cur.x = 25; ch[0][2][0].cur.x = 75; ch[0][3][0].cur.x = 75;
	ch[0][0][0].cur.y = 415; ch[0][1][0].cur.y=465 ; ch[0][2][0].cur.y =415 ; ch[0][3][0].cur.y =465 ;
	ch[0][0][0].cur.color= LIGHTRED; ch[0][1][0].cur.color = LIGHTRED; ch[0][2][0].cur.color = LIGHTRED; ch[0][3][0].cur.color = LIGHTRED;
	for (int i = 1; i <=30; i++) {//红格坐标初始化
		sq[0][0][i].x = -20 + 50 * i; sq[0][1][i].x = -40 + 50 * i; sq[0][2][i].x = -20 + 50 * i; sq[0][3][i].x = -40 + 50 * i;
		sq[0][0][i].y = 360;             sq[0][1][i].y = 360;             sq[0][2][i].y = 330;              sq[0][3][i].y = 330;	
		for (int j = 0; j < 4; j++) {
			sq[0][j][i].color = LIGHTRED;
			ch[0][j][i].cur= sq[0][j][i]; 
		}
	}

	ch[1][0][0].cur.x = 335; ch[1][1][0].cur.x = 335; ch[1][2][0].cur.x = 385; ch[1][3][0].cur.x = 385;
	ch[1][0][0].cur.y = 45; ch[1][1][0].cur.y = 95; ch[1][2][0].cur.y = 45; ch[1][3][0].cur.y = 95;
	ch[1][0][0].cur.color = GREEN; ch[1][1][0].cur.color = GREEN; ch[1][2][0].cur.color = GREEN; ch[1][3][0].cur.color = GREEN;
	for (int i = 6; i <=24; i++) {
		sq[1][0][i].x = -20 + 50 * i; sq[1][1][i].x = -40 + 50 * i; sq[1][2][i].x = -20 + 50 * i; sq[1][3][i].x = -40 + 50 * i;
		sq[1][0][i].y = 360;             sq[1][1][i].y = 360;             sq[1][2][i].y = 330;              sq[1][3][i].y = 330;
		sq[1][0][i].color = GREEN;
		for (int j = 0; j < 4; j++) {
			sq[1][j][i].color = GREEN;ch[1][j][i].cur = sq[1][j][i]; 
		}
	}
	for (int i = 1; i <= 5; i++) {
		sq[1][0][i].x = 285; sq[1][1][i].x = 255; sq[1][2][i].x = 285; sq[1][3][i].x = 255;
		sq[1][0][i].y =  60 * i; sq[1][1][i].y = 60 * i-30; sq[1][2][i].y = 60 * i-30; sq[1][3][i].y = 60 * i;
		sq[1][0][i].color = GREEN;
		for (int j = 0; j < 4; j++) { sq[1][j][i].color = GREEN;ch[1][j][i].cur = sq[1][j][i];  }
	}
	for (int i = 25; i <= 29; i++) {
		sq[1][0][i].x = 1185; sq[1][1][i].x = 1155; sq[1][2][i].x = 1185; sq[1][3][i].x = 1155;
		sq[1][0][i].y = 420 + 60 * (i - 25); sq[1][1][i].y = 420 +60 * (i - 25); sq[1][2][i].y = 390 + 60 * (i - 25); sq[1][3][i].y = 390 + 60 * (i - 25);
		for (int j = 0; j < 4; j++) {sq[1][j][i].color = GREEN;  ch[1][j][i].cur = sq[1][j][i]; }
	}
	sq[1][0][30].x = 1135; sq[1][0][30].y = 660;	sq[1][1][30].x = 1105; sq[1][1][30].y = 660;
	sq[1][2][30].x = 1135; sq[1][2][30].y = 630;	sq[1][3][30].x = 1105; sq[1][3][30].y = 630;
	sq[1][0][30].color = GREEN; sq[1][1][30].color = GREEN; sq[1][2][30].color = GREEN; sq[1][3][30].color = GREEN;
	ch[1][0][30].cur = sq[1][0][30]; ch[1][1][30].cur = sq[1][1][30]; ch[1][2][30].cur = sq[1][2][30]; ch[1][3][30].cur = sq[1][3][30];
	
    ch[2][0][0].cur.x = 335; ch[2][1][0].cur.x = 335; ch[2][2][0].cur.x = 385; ch[2][3][0].cur.x = 385;
	ch[2][0][0].cur.y = 595; ch[2][1][0].cur.y = 645; ch[2][2][0].cur.y = 595; ch[2][3][0].cur.y = 645;
	ch[2][0][0].cur.color = LIGHTBLUE; ch[2][1][0].cur.color = LIGHTBLUE; ch[2][2][0].cur.color = LIGHTBLUE; ch[2][3][0].cur.color = LIGHTBLUE;
	for (int i = 1; i <= 5; i++) {
		sq[2][0][i].x = 285; sq[2][1][i].x = 255; sq[2][2][i].x = 285; sq[2][3][i].x = 255;
		sq[2][0][i].y = 720-60 * i; sq[2][1][i].y = 720-60 * i - 30; sq[2][2][i].y = 720-60 * i - 30; sq[2][3][i].y =720-60 * i;
		sq[2][0][i].color = LIGHTBLUE;
		for (int j = 0; j < 4; j++) { sq[2][j][i].color = LIGHTBLUE; ch[2][j][i].cur = sq[2][j][i]; }
	}
	for (int i = 6; i <= 24; i++) {
		sq[2][0][i].x = -20 + 50 * i; sq[2][1][i].x = -40 + 50 * i; sq[2][2][i].x = -20 + 50 * i; sq[2][3][i].x = -40 + 50 * i;
		sq[2][0][i].y = 360;             sq[2][1][i].y = 360;             sq[2][2][i].y = 330;              sq[2][3][i].y = 330;
		sq[2][0][i].color = LIGHTBLUE;
		for (int j = 0; j < 4; j++) {
			sq[2][j][i].color = LIGHTBLUE; ch[2][j][i].cur = sq[2][j][i];
		}
	}
	for (int i = 25; i <= 29; i++) {
		sq[2][0][i].x = 1185; sq[2][1][i].x = 1155; sq[2][2][i].x = 1185; sq[2][3][i].x = 1155;
		sq[2][0][i].y = 270- 60 * (i - 25); sq[2][1][i].y =  270-60 * (i - 25); sq[2][2][i].y =300-60 * (i - 25); sq[2][3][i].y = 300 - 60 * (i - 25);
		for (int j = 0; j < 4; j++) { sq[2][j][i].color =LIGHTBLUE;  ch[2][j][i].cur = sq[2][j][i]; }
	}
	sq[2][0][30].x = 1135; sq[2][0][30].y = 60;	sq[2][1][30].x = 1105; sq[2][1][30].y = 60;
	sq[2][2][30].x = 1135; sq[2][2][30].y = 30;	sq[2][3][30].x = 1105; sq[2][3][30].y = 30;
	sq[2][0][30].color =LIGHTBLUE; sq[2][1][30].color = LIGHTBLUE; sq[2][2][30].color = LIGHTBLUE; sq[2][3][30].color = LIGHTBLUE;
	ch[2][0][30].cur = sq[2][0][30]; ch[2][1][30].cur = sq[2][1][30]; ch[2][2][30].cur = sq[2][2][30]; ch[2][3][30].cur = sq[2][3][30];
#ifdef debug
	button(sq[1][3][28].x, sq[1][3][28].y, 30, 30, LIGHTRED, st4, 25);//test
	clear(335, 45, 30, 30);//test
	move(ch[1][1][28], ch[1][1][25], st2);//test
	move(ch[1][1][0],ch[1][1][24],st2);//test
	move(ch[2][1][1], ch[2][1][4], st2);
#endif
	int playernum = 3; int player = 0; 
	int cnt[3] = { 4,4,4 }; //没到终点剩余棋子个数
	int count[3] = { 4,4,4 };//机场内剩余棋子个数
	int point[3] = { 0 }; //开场判断后移动的点数
	//int point1[3] = { 0 };
	//int point2[3] = { 0 };
	int flag = 1;
	int judge[3] = { 0 };//判断开场时是否到6
	TCHAR s1[] = _T("步数");
	button(870, 540, 60, 40, YELLOW, s1, 25);
#ifdef debug
	yourchoice();
	//over(0);
#endif
	Sleep(2000); 
	int start[4] = { 0 }; 
	int start1[4] = { 0 };
	int start2[4] = { 0 };
	for (int i = 0; i < 4; i++) {
		ch[0][i][0].pos = 0;
		ch[1][i][0].pos = 0;
		ch[2][i][0].pos = 0;
	}
	while (cnt[player] != 0) {
		if (player == 0) {//人操作
			
			judge[0] = clickrandom();

			if (judge[0] == 6 && count[0] > 0 && count[0] <= 4) {
				count[0]--;
				point[0] = clickrandom();
				int end[4];
				for (int i = 0; i < 4; i++) end[i] = (start[i] + point[0] <= 30) ? (start[i] + point[0]) : (30 - (start[i] + point[0]) % 30);//含反弹
				yourchoice();
				char temp;
				temp = 0;
				printnum(point[0]);
	loop:	temp = _getch();
				switch (temp) {
					
				case '1': if (ch[0][0][0].pos == 0) {
					ch[0][0][0].pos = 1; sq[0][0][start[0]].colornum = 0; sq[0][0][end[0]].colornum = 1;  move(ch[0][0][start[0]], ch[0][0][end[0]], st1); start[0] = end[0]; temp = 0;
					break;
				}
						else { warning(); goto loop; }
					
				case '2':if (ch[0][1][0].pos == 0) { 
					ch[0][1][0].pos = 1; sq[0][1][start[1]].colornum = 0; sq[0][1][end[1]].colornum = 1;  move(ch[0][1][start[1]], ch[0][1][end[1]], st2); start[1] =end[1]; temp = 0;
					break;
				}
						else { warning(); goto loop; }
					
				case '3':if (ch[0][2][0].pos == 0) {
					ch[0][2][0].pos = 1; sq[0][2][start[2]].colornum = 0;  sq[0][2][end[2]].colornum = 1; move(ch[0][2][start[2]], ch[0][2][end[2]], st3); start[2] =end[2]; temp = 0;
					break;
				}
						else { warning(); goto loop; }
					
				case '4': if (ch[0][3][0].pos == 0) {
					ch[0][3][0].pos = 1; sq[0][3][start[3]].colornum = 0;  sq[0][3][end[3]].colornum = 1; move(ch[0][3][start[3]], ch[0][3][end[3]], st4); start[3] =end[3]; temp = 0;
					break;
				}
						else { warning(); goto loop; }
				default:warning();
					goto loop;
				}
				player = (player + 1) % playernum;
			}

			else if (judge[0] != 6 && count[0] > 0 && count[0] < 4) {
				point[0] = judge[0];
				int end[4];
				for (int i = 0; i < 4; i++) end[i] = (start[i] + point[0] <= 30) ? (start[i] + point[0]) : (30 - (start[i] + point[0]) % 30);//含反弹
				yourchoice();
				char temp;
				temp = 0;
				printnum(point[0]);
	  loop1:temp = _getch();
				switch (temp) {
					
				case '1': if (ch[0][0][0].pos == 1) {
					ch[0][0][0].pos = 1; sq[0][0][start[0]].colornum = 0; sq[0][0][end[0]].colornum = 1; move(ch[0][0][start[0]], ch[0][0][end[0]], st1); start[0]=end[0]; temp = 0;
					if (end[0] == 30) {
						clear(ch[0][0][30].cur.x, ch[0][0][30].cur.y, 30, 30); cnt[0]--; ch[0][0][0].pos = 2;
					} break;
				}
						else { warning(); goto loop1; }
					
				case '2': if (ch[0][1][0].pos == 1) {
					ch[0][1][0].pos = 1; sq[0][1][start[1]].colornum = 0; sq[0][1][end[1]].colornum = 1; move(ch[0][1][start[1]], ch[0][1][end[1]], st2); start[1] =end[1]; temp = 0;
					if (end[1] == 30) {
						clear(ch[0][1][30].cur.x, ch[0][1][30].cur.y, 30, 30); cnt[0]--; ch[0][1][0].pos = 2;
					}break;
				}
						else { warning(); goto loop1; }
					
				case '3':if (ch[0][2][0].pos == 1) {
					ch[0][2][0].pos = 1; sq[0][2][start[2]].colornum = 0;  sq[0][2][end[2]].colornum = 1; move(ch[0][2][start[2]], ch[0][2][end[2]], st3); start[2] =end[2]; temp = 0;
					if (end[2] == 30) {
						clear(ch[0][2][30].cur.x, ch[0][2][30].cur.y, 30, 30); cnt[0]--; ch[0][2][0].pos = 2;
					}break;
				}
						else { warning(); goto loop1; }
					
				case '4': if (ch[0][3][0].pos == 1) {
					ch[0][3][0].pos = 1; sq[0][3][start[3]].colornum = 0;  sq[0][3][end[3]].colornum = 1;  move(ch[0][3][start[3]], ch[0][3][end[3]], st4); start[3] =end[3]; temp = 0;
					if (end[3] == 30) {
						clear(ch[0][3][30].cur.x, ch[0][3][30].cur.y, 30, 30); cnt[0]--; ch[0][3][0].pos = 2;
					} break;
				}
						else { warning(); goto loop1; }
				default:warning();goto loop1;
				}
				player = (player + 1) % playernum;
			}

			else if (judge[0] != 6 && count[0] == 4) {
				player = (player + 1) % playernum;
			}

			else if (count[0] == 0) {
				point[0] = judge[0];
				int end[4];
				for (int i = 0; i < 4; i++) end[i] = (start[i] + point[0] <= 30) ? (start[i] + point[0]) : (30 - (start[i] + point[0]) % 30);//含反弹
				yourchoice();
				char temp;
				temp = 0;
				printnum(point[0]);
	loop2:  temp = _getch();
				switch (temp) {

				case '1': ch[0][0][0].pos = 1; sq[0][0][start[0]].colornum = 0;  sq[0][0][end[0]].colornum = 1;  move(ch[0][0][start[0]], ch[0][0][end[0]], st1); start[0] =end[0]; temp = 0;
					if (end[0] == 30) {
						clear(ch[0][0][30].cur.x, ch[0][0][30].cur.y, 30, 30); cnt[0]--; ch[0][0][0].pos = 2;
					} break;


				case '2': ch[0][1][0].pos = 1; sq[0][1][start[1]].colornum = 0;  sq[0][1][end[1]].colornum = 1;  move(ch[0][1][start[1]], ch[0][1][end[1]], st2); start[1] =end[1]; temp = 0;
					if (end[1] == 30) {
						clear(ch[0][1][30].cur.x, ch[0][1][30].cur.y, 30, 30); cnt[0]--; ch[0][1][0].pos = 2;
					}break;


				case '3':ch[0][2][0].pos = 1;  sq[0][2][start[2]].colornum = 0; sq[0][2][end[2]].colornum = 1;  move(ch[0][2][start[2]], ch[0][2][end[2]], st3); start[2] =end[2]; temp = 0;
					if (end[2] == 30) {
						clear(ch[0][2][30].cur.x, ch[0][2][30].cur.y, 30, 30); cnt[0]--; ch[0][2][0].pos = 2;
					}break;


				case '4': ch[0][3][0].pos = 1;  sq[0][3][start[3]].colornum = 0; sq[0][3][end[3]].colornum = 1; move(ch[0][3][start[3]], ch[0][3][end[3]], st4); start[3] =end[3]; temp = 0;
					if (end[3] == 30) {
						clear(ch[0][3][30].cur.x, ch[0][3][30].cur.y, 30, 30); cnt[0]--; ch[0][3][0].pos = 2;
					} break;

				default:TCHAR str[] = _T("请规范操作"); button(600, 670, 130, 40, YELLOW, str, 25); Sleep(2500); clear(598, 668, 134, 44);
					goto loop;
				}
				player = (player + 1) % playernum;
			}
		}
		for (int i = 6; i <= 24; i++) {
			for (int j = 0; j < 4; j++) {
				for (int k = 0; k < 4; k++) {
					if (sq[0][j][i].colornum == 1 && sq[1][k][i].colornum == 1) {
						switch (k) {
						case 0: move(ch[1][k][i], ch[1][k][0], st1); break;
						case 1: move(ch[1][k][i], ch[1][k][0], st2); break;
						case 2: move(ch[1][k][i], ch[1][k][0], st3); break;
						case 3: move(ch[1][k][i], ch[1][k][0], st4); break;
						}
						switch (j) {
						case 0:button(ch[0][j][i].cur.x, ch[0][j][i].cur.y, 30, 30, ch[0][j][i].cur.color, st1, 20); break;
						case 1:button(ch[0][j][i].cur.x, ch[0][j][i].cur.y, 30, 30, ch[0][j][i].cur.color, st2, 20); break;
						case 2:button(ch[0][j][i].cur.x, ch[0][j][i].cur.y, 30, 30, ch[0][j][i].cur.color, st3, 20); break;
						case 3:button(ch[0][j][i].cur.x, ch[0][j][i].cur.y, 30, 30, ch[0][j][i].cur.color, st4, 20); break;
						}
						sq[1][k][i].colornum = 0; ch[1][k][0].pos = 0; 
						start1[k] = 0; count[1]++;
					}
					if (sq[0][j][i].colornum == 1 && sq[2][k][i].colornum == 1) {
						switch (k) {
						case 0: move(ch[2][k][i], ch[2][k][0], st1); break;
						case 1: move(ch[2][k][i], ch[2][k][0], st2); break;
						case 2: move(ch[2][k][i], ch[2][k][0], st3); break;
						case 3: move(ch[2][k][i], ch[2][k][0], st4); break;
						}
						switch (j) {
						case 0:button(ch[0][j][i].cur.x, ch[0][j][i].cur.y, 30, 30, ch[0][j][i].cur.color, st1, 20); break;
						case 1:button(ch[0][j][i].cur.x, ch[0][j][i].cur.y, 30, 30, ch[0][j][i].cur.color, st2, 20); break;
						case 2:button(ch[0][j][i].cur.x, ch[0][j][i].cur.y, 30, 30, ch[0][j][i].cur.color, st3, 20); break;
						case 3:button(ch[0][j][i].cur.x, ch[0][j][i].cur.y, 30, 30, ch[0][j][i].cur.color, st4, 20); break;
						}
						sq[2][k][i].colornum = 0; ch[2][k][0].pos = 0;
						start2[k] = 0; count[2]++;
					}
				}
			}
		}//撞回机场
		if (cnt[0] == 0) {
			over(0);
			return;
		}
		Sleep(1000);

		if (player == 1) {//电脑操作
			judge[1] = die(1);
			if (judge[1] != 6 && count[1] == 4) {
				player = (player + 1) % playernum;
			}
			if (judge[1] == 6 && count[1] > 0) {
				Sleep(1000);
				point[1] = die(1); printnum(point[1]);
				int end[4];
				for (int i = 0; i < 4; i++)end[i] = (start1[i] + point[1] <= 30) ? (start1[i] + point[1]) : (30 - (start1[i] + point[1]) % 30);
				for (int i = 0; i < 4; i++) {
					if (ch[1][i][0].pos == 0) {
						switch(i){
						case 0:move(ch[1][i][start1[i]], ch[1][i][end[i]], st1); break;
						case 1:move(ch[1][i][start1[i]], ch[1][i][end[i]], st2); break;
						case 2:move(ch[1][i][start1[i]], ch[1][i][end[i]], st3); break;
						case 3: move(ch[1][i][start1[i]], ch[1][i][end[i]], st4); break;
						}
						sq[1][i][start1[i]].colornum = 1; sq[1][i][end[i]].colornum = 1; 
						ch[1][i][0].pos = 1;
						start1[i]=end[i];
						count[1]--;
						break;
					}
				}
				player = (player + 1) % playernum;
			}

			if (judge[1] != 6 && count[1] > 0 && count[1] < 4) {
				Sleep(1000);
				point[1] = judge[1]; printnum(point[1]);
				int end[4];
				for (int i = 0; i < 4; i++)end[i] = (start1[i] + point[1] <= 30) ? (start1[i] + point[1]) : (30 - (start1[i] + point[1]) % 30);
				for (int i = 0; i < 4; i++) {
					if (ch[1][i][0].pos == 1) {
						switch (i) {
						case 0:move(ch[1][i][start1[i]], ch[1][i][end[i]], st1); break;
						case 1:move(ch[1][i][start1[i]], ch[1][i][end[i]], st2); break;
						case 2:move(ch[1][i][start1[i]], ch[1][i][end[i]], st3); break;
						case 3: move(ch[1][i][start1[i]], ch[1][i][end[i]], st4); break;
						}
						sq[1][i][start1[i]].colornum = 1; sq[1][i][end[i]].colornum = 1;
						ch[1][i][0].pos = 1;
						start1[i] =end[i];
						break;
					}
				}
				player = (player + 1) % playernum;
			}

			if (count[1] == 0) {
				point[1] = judge[1]; printnum(point[1]);
				int end[4];
				for (int i = 0; i < 4; i++)end[i] = (start1[i] + point[1] <= 30) ? (start1[i] + point[1]) : (30 - (start1[i] + point[1]) % 30);
				int i = rand()%4;
				switch (i) {
				case 0:move(ch[1][i][start1[i]], ch[1][i][end[i]], st1); break;
				case 1:move(ch[1][i][start1[i]], ch[1][i][end[i]], st2); break;
				case 2:move(ch[1][i][start1[i]], ch[1][i][end[i]], st3); break;
				case 3: move(ch[1][i][start1[i]], ch[1][i][end[i]], st4); break;
				}
				sq[1][i][start1[i]].colornum = 1; sq[1][i][end[i]].colornum = 1; 
				ch[1][i][0].pos = 1;
				start1[i] =end[i];
				if (end[i] == 30) {
					clear(ch[1][i][30].cur.x, ch[1][i][30].cur.y, 30, 30); cnt[1]--; ch[1][i][0].pos = 2;
				}
				//if (ch[1][i][0].pos == 1 && ch[1][(i + 1) % 4][0].pos == 1) i = (i + 1) % 4;
				player = (player + 1) % playernum;
			}
		}

		for (int i = 6; i <= 24; i++) {
			for (int j = 0; j < 4; j++) {
				for (int k = 0; k < 4; k++) {
					if (sq[1][j][i].colornum == 1 && sq[0][k][i].colornum == 1) {
						switch (k) {
						case 0: move(ch[0][k][i], ch[0][k][0], st1); break;
						case 1: move(ch[0][k][i], ch[0][k][0], st2); break;
						case 2: move(ch[0][k][i], ch[0][k][0], st3); break;
						case 3: move(ch[0][k][i], ch[0][k][0], st4); break;
						}
						switch (j) {
						case 0:button(ch[1][j][i].cur.x, ch[1][j][i].cur.y, 30, 30, ch[1][j][i].cur.color, st1, 20); break;
						case 1:button(ch[1][j][i].cur.x, ch[1][j][i].cur.y, 30, 30, ch[1][j][i].cur.color, st2, 20); break;
						case 2:button(ch[1][j][i].cur.x, ch[1][j][i].cur.y, 30, 30, ch[1][j][i].cur.color, st3, 20); break;
						case 3:button(ch[1][j][i].cur.x, ch[1][j][i].cur.y, 30, 30, ch[1][j][i].cur.color, st4, 20); break;
						}
						sq[0][k][i].colornum = 0; ch[0][k][0].pos = 0; 
						start[k] = 0; count[0]++;
					}
					if (sq[1][j][i].colornum == 1 && sq[2][k][i].colornum == 1) {
						switch (k) {
						case 0: move(ch[2][k][i], ch[2][k][0], st1); break;
						case 1: move(ch[2][k][i], ch[2][k][0], st2); break;
						case 2: move(ch[2][k][i], ch[2][k][0], st3); break;
						case 3: move(ch[2][k][i], ch[2][k][0], st4); break;
						}
						switch (j) {
						case 0:button(ch[1][j][i].cur.x, ch[1][j][i].cur.y, 30, 30, ch[1][j][i].cur.color, st1, 20); break;
						case 1:button(ch[1][j][i].cur.x, ch[1][j][i].cur.y, 30, 30, ch[1][j][i].cur.color, st2, 20); break;
						case 2:button(ch[1][j][i].cur.x, ch[1][j][i].cur.y, 30, 30, ch[1][j][i].cur.color, st3, 20); break;
						case 3:button(ch[1][j][i].cur.x, ch[1][j][i].cur.y, 30, 30, ch[1][j][i].cur.color, st4, 20); break;
						}//叠子可能会被clear掉，补上
						sq[2][k][i].colornum = 0; ch[2][k][0].pos = 0; 
						start2[k] = 0; count[2]++;
					}
				}
			}
		}//撞回机场

		if (cnt[1] == 0) {
			over(1); return;
		}
		Sleep(1000);
		
		if (player == 2) {//电脑操作
			judge[2] = die(1);
			if (judge[2] != 6 && count[2] == 4) {
				player = (player + 1) % playernum;
			}
			if (judge[2] == 6 && count[2] > 0) {
				Sleep(1000);
				point[2] = die(1); printnum(point[2]);
				int end[4];
				for (int i = 0; i < 4; i++)end[i] = (start2[i] + point[2] <= 30) ? (start2[i] + point[2]) : (30 - (start2[i] + point[2]) % 30);
				for (int i = 0; i < 4; i++) {
					if (ch[2][i][0].pos == 0) {
						switch (i) {
						case 0:move(ch[2][i][start2[i]], ch[2][i][end[i]], st1); break;
						case 1:move(ch[2][i][start2[i]], ch[2][i][end[i]], st2); break;
						case 2:move(ch[2][i][start2[i]], ch[2][i][end[i]], st3); break;
						case 3: move(ch[2][i][start2[i]], ch[2][i][end[i]], st4); break;
						}
						sq[2][i][start2[i]].colornum = 0; sq[2][i][end[i]].colornum = 1; 
						ch[2][i][0].pos = 1;
						start2[i] =end[i];
						count[2]--;
						break;
					}
				}
				player = (player + 1) % playernum;
			}

			if (judge[2] != 6 && count[2] > 0 && count[2] < 4) {//有问题
				Sleep(1000);
				point[2] = judge[2]; printnum(point[2]);
				int end[4];
				for (int i = 0; i < 4; i++)end[i] = (start2[i] + point[2] <= 30) ? (start2[i] + point[2]) : (30 - (start2[i] + point[2]) % 30);
				for (int i = 0; i < 4; i++) {
					if (ch[2][i][0].pos == 1) {
						switch (i) {
						case 0:move(ch[2][i][start2[i]], ch[2][i][end[i]], st1); break;
						case 1:move(ch[2][i][start2[i]], ch[2][i][end[i]], st2); break;
						case 2:move(ch[2][i][start2[i]], ch[2][i][end[i]], st3); break;
						case 3: move(ch[2][i][start2[i]], ch[2][i][end[i]], st4); break;
						}
						if (end[i] == 30) {
							clear(ch[2][i][30].cur.x, ch[2][i][30].cur.y, 30, 30); cnt[1]--; ch[2][i][0].pos = 2;
						}
						else {
							sq[2][i][start2[i]].colornum = 0; sq[2][i][end[i]].colornum = 1; 
							ch[2][i][0].pos = 1;
							start2[i] =end[i];
						}
						break;
					}
				}
				player = (player + 1) % playernum;
			}

			if (count[2] == 0) {
				point[2] = judge[2]; printnum(point[2]);
				int end[4];
				for (int i = 0; i < 4; i++)end[i] = (start2[i] + point[2] <= 30) ? (start2[i] + point[2]) : (30 - (start2[i] + point[2]) % 30);
				int i = rand()%4;
				switch (i) {
				case 0:move(ch[2][i][start2[i]], ch[2][i][end[i]], st1); break;
				case 1:move(ch[2][i][start2[i]], ch[2][i][end[i]], st2); break;
				case 2:move(ch[2][i][start2[i]], ch[2][i][end[i]], st3); break;
				case 3: move(ch[2][i][start2[i]], ch[2][i][end[i]], st4); break;
				}
				if (end[i] == 30) {
					clear(ch[2][i][30].cur.x, ch[2][i][30].cur.y, 30, 30); cnt[1]--; ch[2][i][0].pos = 2;
				}
				else {
					sq[2][i][start2[i]].colornum = 0;  sq[2][i][end[i]].colornum = 1;
					ch[2][i][0].pos = 1;
					start2[i] =end[i];
					if (ch[2][i][0].pos == 1 && ch[2][(i + 1) % 4][0].pos == 1) i = (i + 1) % 4;
				}
				player = (player + 1) % playernum;
			}

		}	

		for (int i = 6; i <= 24; i++) {
			for (int j = 0; j < 4; j++) {
				for (int k = 0; k < 4; k++) {
					if (sq[2][j][i].colornum == 1 && sq[0][k][i].colornum == 1) {
						switch (k) {
						case 0: move(ch[0][k][i], ch[0][k][0], st1); break;
						case 1: move(ch[0][k][i], ch[0][k][0], st2); break;
						case 2: move(ch[0][k][i], ch[0][k][0], st3); break;
						case 3: move(ch[0][k][i], ch[0][k][0], st4); break;
						}
						switch (j) {
						case 0:button(ch[2][j][i].cur.x, ch[2][j][i].cur.y, 30, 30, ch[2][j][i].cur.color, st1, 20); break;
						case 1:button(ch[2][j][i].cur.x, ch[2][j][i].cur.y, 30, 30, ch[2][j][i].cur.color, st2, 20); break;
						case 2:button(ch[2][j][i].cur.x, ch[2][j][i].cur.y, 30, 30, ch[2][j][i].cur.color, st3, 20); break;
						case 3:button(ch[2][j][i].cur.x, ch[2][j][i].cur.y, 30, 30, ch[2][j][i].cur.color, st4, 20); break;
						}
						sq[0][k][i].colornum = 0; ch[0][k][0].pos = 0; 
						start[k] = 0; count[0]++;
					}
					if (sq[2][j][i].colornum == 1 && sq[1][k][i].colornum == 1) {
						switch (k) {
						case 0: move(ch[1][k][i], ch[1][k][0], st1); break;
						case 1: move(ch[1][k][i], ch[1][k][0], st2); break;
						case 2: move(ch[1][k][i], ch[1][k][0], st3); break;
						case 3: move(ch[1][k][i], ch[1][k][0], st4); break;
						}
						switch (j) {
						case 0:button(ch[2][j][i].cur.x, ch[2][j][i].cur.y, 30, 30, ch[2][j][i].cur.color, st1, 20); break;
						case 1:button(ch[2][j][i].cur.x, ch[2][j][i].cur.y, 30, 30, ch[2][j][i].cur.color, st2, 20); break;
						case 2:button(ch[2][j][i].cur.x, ch[2][j][i].cur.y, 30, 30, ch[2][j][i].cur.color, st3, 20); break;
						case 3:button(ch[2][j][i].cur.x, ch[2][j][i].cur.y, 30, 30, ch[2][j][i].cur.color, st4, 20); break;
						}//叠子可能会被clear掉，补上
						sq[1][k][i].colornum = 0; ch[1][k][0].pos = 0; 
						start1[k] = 0; count[1]++;
					}
				}
			}
		}//撞回机场

		if (cnt[2] == 0) {
			over(2); return;
		}

	}

}

void drawboard1() {
	initgraph(1580, 720);
	setbkcolor(WHITE);
	cleardevice();
	setlinestyle(PS_SOLID, 2);
	setcolor(BLACK);

	airport(320, 30, GREEN);
	airport(10, 400, LIGHTRED);
	airport(320, 580, LIGHTBLUE);

	//填色
	for (int i = 0; i < lenth; i++) {
		setfillcolor(WHITE);
		solidrectangle(260 + 50 * i, 390, 310 + 50 * i, 330);
	}
	for (int i = 0; i < 5; i++) {
		setfillcolor(LIGHTRED);
		solidrectangle(10 + 50 * i, 390, 60 + 50 * i, 330);
	}
	for (int i = 0; i < 6; i++) {
		setfillcolor(LIGHTRED);
		solidrectangle(1210 + 50 * i, 390, 1260 + 50 * i, 330);
	}
	for (int i = 0; i < 5; i++) {
		setfillcolor(GREEN);
		solidrectangle(260, 30 + 60 * i, 310, 90 + 60 * i);
		solidrectangle(1160, 390 + 60 * i, 1210, 450 + 60 * i);
		solidrectangle(1110, 630, 1160, 690);
		setfillcolor(LIGHTBLUE);
		solidrectangle(260, 390 + 60 * i, 310, 450 + 60 * i);
		solidrectangle(1160, 30 + 60 * i, 1210, 90 + 60 * i);
		solidrectangle(1110, 30, 1160, 90);
	}
	//for(int i=0;i<5;i++)

//注意后填色会覆盖边框
//边框
	line(10, 330, 1510, 330);
	line(10, 390, 1510, 390);
	for (int i = 0; i <= lenth + 5 + 6; i++) {
		line(10 + 50 * i, 330, 10 + 50 * i, 390);
	}
	line(260, 30, 260, 690);
	line(310, 30, 310, 690);
	line(1160, 30, 1160, 690);
	line(1210, 30, 1210, 690);
	for (int i = 0; i <= 11; i++) {
		line(260, 30 + 60 * i, 310, 30 + 60 * i);
		line(1160, 30 + 60 * i, 1210, 30 + 60 * i);
	}
	line(1110, 30, 1160, 30);
	line(1110, 90, 1160, 90);
	line(1110, 30, 1110, 90);

	line(1110, 630, 1160, 630);
	line(1110, 690, 1160, 690);
	line(1110, 630, 1110, 690);

	arrow();
	TCHAR s[] = _T("起点");
	TCHAR s1[] = _T("终点");
	button(10, 240, 60, 40, LIGHTRED, s, 24);
	button(160, 30, 60, 40, GREEN, s, 24);
	button(160, 650, 60, 40, LIGHTBLUE, s, 24);
	button(1460, 280, 60, 40, LIGHTRED, s1, 24);
	button(1040, 650, 60, 40, GREEN, s1, 24);
	button(1040, 30, 60, 40, LIGHTBLUE, s1, 24);

	TCHAR s2[] = _T("你的阵营为红色");
	button(700, 30, 0, 0, WHITE, s2, 25);
	myrandom();

	//mode1();
	//_getch();
}
void welcome() {
	initgraph(1080, 720);//初始化界面大小

	IMAGE background;
	loadimage(&background, _T("background1.png"), 1080, 720, 1);
	putimage(0, 0, &background);//左上角坐标为(0,0)


	TCHAR s1[] = _T("欢迎来到飞行棋");
	TCHAR s2[] = _T("请选择你想要的对手数量");
	settextstyle(48, 0, L"黑体");
	setbkmode(TRANSPARENT);
	gettextcolor();
	settextcolor(0x5555FF);
	outtextxy(350, 190, s1);
	outtextxy(270, 250, s2);

	TCHAR s3[] = _T("2");
	TCHAR s4[] = _T("2");
	button(375, 415, 56, 56, YELLOW, s3, 48);
	button(600, 415, 56, 56, YELLOW, s4, 48);

	ExMessage msg;
	while (true) {
		if (peekmessage(&msg, EM_MOUSE)) {
			switch (msg.message) {
			case WM_LBUTTONDOWN:
				if (msg.x >= 375 && msg.x <= 375 + 56 && msg.y >= 415 && msg.y <= 415 + 56) {
					//outtextxy(375, 415, s1);//test
					rules();
					drawboard1();
					mode1();
					//_getch();
				}
				if (msg.x >= 600 && msg.x <= 600 + 56 && msg.y >= 415 && msg.y <= 415 + 56) {
					//outtextxy(600, 415, s1);//test
					rules();
					drawboard1();
					mode1();
					//_getch();
				}
				break;
			default:
				break;
			}

		}
	}
	_getch();//防止程序关闭

}

int main()
{
	welcome();
	//mode1();
	//drawboard1();
}