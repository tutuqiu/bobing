#include <iostream>
#include<conio.h>
#include "cmd_console_tools.h"
#include<Windows.h>
#include<random>
using namespace std;


//╭━━━╮╰━━━╯┃●
string a = "╭";

void draw(int x, int y,int d) {
	//cct_showstr(x, y, "╭━━━╮", 0, 7);
	cct_showstr(x, y, "╭", 0, 7);
	cct_showstr(x + 2, y, "━", 0, 7);
	cct_showstr(x +4, y, "━", 0, 7);
	cct_showstr(x + 6, y, "━", 0, 7);
	cct_showstr(x + 8, y, "╮", 0, 7);
	cct_showstr(x, y + 1, "┃", 0, 7);
	cct_showstr(x+8, y+1, "┃", 0, 7);
	cct_showstr(x, y + 2, "┃", 0, 7);
	cct_showstr(x+8, y+2, "┃", 0, 7);
	cct_showstr(x, y + 3, "┃", 0, 7);
	cct_showstr(x+8, y+3, "┃", 0, 7);
	//cct_showstr(x, y+4, "╰━━━╯", 0, 7);
	cct_showstr(x, y+4, "╰", 0, 7);
	cct_showstr(x + 2, y+4, "━", 0, 7);
	cct_showstr(x + 4, y+4, "━", 0, 7);
	cct_showstr(x + 6, y+4, "━", 0, 7);
	cct_showstr(x + 8, y+4, "╯", 0, 7);
	switch (d) {
		case 1:
			cct_showstr(x+4, y+2, "●", 0, 4);
			break;
		case 2:
			cct_showstr(x + 2, y + 2, "●  ●", 0, 1);
			break;
		case 3:{
			cct_showstr(x + 2, y + 1, "●", 0, 1);
			cct_showstr(x + 4, y + 2, "●", 0, 1);
			cct_showstr(x + 6, y + 3, "●", 0, 1);
			break;
		}
		case 4: {
			cct_showstr(x + 2, y + 1, "●  ●", 0, 4);
			cct_showstr(x + 2, y + 3, "●  ●", 0, 4);
			break;
		}
		case 5: {
			cct_showstr(x + 2, y + 1, "●  ●", 0, 1);
			cct_showstr(x + 4, y + 2, "●", 0, 1);
			cct_showstr(x + 2, y + 3, "●  ●", 0, 1);
			break;
		}
		case 6: {
			cct_showstr(x + 2, y + 1, "●  ●", 0, 1);
			cct_showstr(x + 2, y + 2, "●  ●", 0, 1);
			cct_showstr(x + 2, y + 3, "●  ●", 0, 1);
			break;
		}
		
	}
	cct_gotoxy(x, y + 5);
	cct_setcolor(0, 7);
}

void result(int t[],int &top,int &zyd) {
	int i, j, co[7] = { 0 }, s, dian=0;
	for (i = 0; i < 6; i++) {
		for (j = 1; j <= 6; j++) {
			if (t[i] == j) {
				co[j]++;
				break;
			}
		}
	}
	if (co[1] && co[2] && co[3] && co[4] && co[5] && co[6]) {
		cout << "运气爆棚！恭喜你博到对堂（榜眼）" << endl;
		s = 5;
		goto X;
	}
	else {
		for (i = 1; i <= 6; i++) {
			if (co[i] == 4 && i != 4) {
				cout << "恭喜你博到四进（进士)" << endl;
				s = 3;
				goto X;
			}
			else if (co[i] == 5 && i != 4) {
				if(!co[4])
				{
					cout << "学富五车！恭喜你博到五子登科（状元）！" << endl;
					s = 7;
					goto X;
				}
				else {
					cout<< "学富五车！恭喜你博到五子带一秀（状元）！！" << endl;
					s = 8;
					goto X;
				}
			}
			else if (co[i] == 6 && i != 4) {
				cout << "六六大顺！恭喜你博到六杯黑（状元）！！！" << endl;
				s = 10;
				goto X;
			}
		}

		switch (co[4]) {
			case 0:
				cout << "很遗憾你没博到（落榜）" << endl;
				s = 0;
				break;
			case 1:
				cout << "恭喜你博到一秀（秀才）" << endl;
				s = 1;
				break;
			case 2:
				cout << "恭喜你博到二举（举人）" << endl;
				s = 2;
				break;
			case 3:
				cout << "恭喜你博到三红（探花）" << endl;
				s = 4;
				break;
			case 4:
				dian = co[1] + 2 * co[2] + 3 * co[3] + 5 * co[5] + 6 * co[6];
				if (dian == 2)
				{
					cout << "七星高照！恭喜你博到插金花（状元）！！！！" << endl;
					s = 12;
				}
				else
				{	
					cout << "四方来财！恭喜你博到四点红（状元）！" << endl;
					s = 6;
				}
				break;
			case 5:
				cout << "五福临门！恭喜你博到五王（状元）！！" << endl;
				s = 9;
				break;
			case  6:
				cout << "六六大顺！恭喜你博到六杯红（状元）！！！" << endl;
				s = 11;
				break;
			default:
				break;
		}
	}
	X:
	top = s > top ? s : top;
	zyd = zyd > dian ? zyd : dian;
	cout << "当前最高记录：";
	switch (top) {
		case 0:
			cout << "落榜";
			break;
		case 1:
			cout << "一秀";
			break;
		case 2:
			cout << "二举";
			break;
		case 3:
			cout << "四进";
			break;
		case 4:
			cout << "三红";
			break;
		case 5:
			cout << "对堂";
			break;
		case 6:
			cout << "状元" << "（点数为：" << zyd << "）";
			break;
		case 7:
			cout << "五子登科";
			break;
		case 8:
			cout << "五子带一秀";
			break;
		case 9:
			cout << "五王";
			break;
		case 10:
			cout << "六杯黑";
			break;
		case 11:
			cout << "六杯红";
			break;
		case 12:
			cout << "状元插金花";
			break;
		default:
			break;
	}




}

int main() {
	cct_cls();
	cct_setconsoleborder(120, 30, 9000, 150);
	int t[6];
	int x = 0, y = 0;
	{
	//draw
	cct_showstr(x, y, "博饼规则如下：", 0, 7);
		{
			cct_showstr(x, ++y, "一秀", 0, 7);
			draw(x, ++y, 4);
			y += 4;
		}
		{
			cct_showstr(x, ++y, "二举", 0, 7);
			draw(x, ++y, 4);
			draw(x + 10, y, 4);
			y += 4;
		}
		{
			cct_showstr(x, ++y, "四进(可以是任意除了4的点数)", 0, 7);
			draw(x, ++y, 2);
			draw(x + 10, y, 2);
			draw(x + 20, y, 2);
			draw(x + 30, y, 2);
			y += 4;
		}
		{
			cct_showstr(x, ++y, "三红", 0, 7);
			draw(x, ++y, 4);
			draw(x + 10, y, 4);
			draw(x + 20, y, 4);
			y += 4;
		}
		{
			cct_showstr(x, ++y, "对堂", 0, 7);
			draw(x, ++y, 1);
			draw(x + 10, y, 2);
			draw(x + 20, y, 3);
			draw(x + 30, y, 4);
			draw(x + 40, y, 5);
			draw(x + 50, y, 6);
			y += 4;
		}
		{
			cct_showstr(x, ++y, "状元", 0, 7);
			draw(x, ++y, 4);
			draw(x + 10, y, 4);
			draw(x + 20, y, 4);
			draw(x + 30, y, 4);
			y += 5;
		}
	}
	cct_showstr(x, y, "回车开始博饼！", 0, 7);
	cct_gotoxy(x + 14, y);
	cct_setcursor(CURSOR_VISIBLE_NORMAL);
	while (_getch() != '\r');
	cct_cls();
	//Sleep()
	int n = 1, s = 0, zyd = 0;
	while(1)
	{
		srand(time(0));
		for (int i = 0; i < 6; i++) 
			t[i] = rand() % 6 + 1;	
		y = 9 * (n - 1);
		cct_gotoxy(0,y);
		cct_setcursor(CURSOR_INVISIBLE);//0123456 78910111213 14
		cout << "第" << n << "回合：";
		y++;//7*(n-1)+1
		draw(x, y, t[0]);
		Sleep(300);
		draw(x + 10, y, t[1]);
		Sleep(300);
		draw(x + 20, y, t[2]);
		Sleep(300);
		draw(x + 30, y, t[3]);
		Sleep(300);
		draw(x + 40, y, t[4]);
		Sleep(400);
		draw(x + 50, y, t[5]);
		y += 5;
		cct_gotoxy(0, y);
		result(t, s, zyd);
		cct_setcursor(CURSOR_VISIBLE_NORMAL);
		cout << endl << "请按回车进行下一回合,结束请按空格";
		while (1) {
			char a = _getch();
			if (a == '\r')
				break;
			else if (a == 32) {
				cout << endl << "游戏结束！最高记录为：";
				switch (s) {
				case 0:
					cout << "落榜";
					break;
				case 1:
					cout << "一秀";
					break;
				case 2:
					cout << "二举";
					break;
				case 3:
					cout << "四进";
					break;
				case 4:
					cout << "三红";
					break;
				case 5:
					cout << "对堂";
					break;
				case 6:
					cout << "状元" << "（点数为：" << zyd << "）";
				case 7:
					cout << "五子登科";
					break;
				case 8:
					cout << "五子带一秀";
					break;
				case 9:
					cout << "五王";
					break;
				case 10:
					cout << "六杯黑";
					break;
				case 11:
					cout << "六杯红";
					break;
				case 12:
					cout << "状元插金花";
					break;
				default:
					break;
				}
				cout << endl << endl;
				cout << "请按空格退出...";
				while (_getch() != 32);
	
				return 0;
			}
			
		}
		n++;
	}









}