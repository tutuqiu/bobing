#include <iostream>
#include<conio.h>
#include "cmd_console_tools.h"
#include<Windows.h>
#include<random>
using namespace std;


//�q�������r�t�������s����
string a = "�q";

void draw(int x, int y,int d) {
	//cct_showstr(x, y, "�q�������r", 0, 7);
	cct_showstr(x, y, "�q", 0, 7);
	cct_showstr(x + 2, y, "��", 0, 7);
	cct_showstr(x +4, y, "��", 0, 7);
	cct_showstr(x + 6, y, "��", 0, 7);
	cct_showstr(x + 8, y, "�r", 0, 7);
	cct_showstr(x, y + 1, "��", 0, 7);
	cct_showstr(x+8, y+1, "��", 0, 7);
	cct_showstr(x, y + 2, "��", 0, 7);
	cct_showstr(x+8, y+2, "��", 0, 7);
	cct_showstr(x, y + 3, "��", 0, 7);
	cct_showstr(x+8, y+3, "��", 0, 7);
	//cct_showstr(x, y+4, "�t�������s", 0, 7);
	cct_showstr(x, y+4, "�t", 0, 7);
	cct_showstr(x + 2, y+4, "��", 0, 7);
	cct_showstr(x + 4, y+4, "��", 0, 7);
	cct_showstr(x + 6, y+4, "��", 0, 7);
	cct_showstr(x + 8, y+4, "�s", 0, 7);
	switch (d) {
		case 1:
			cct_showstr(x+4, y+2, "��", 0, 4);
			break;
		case 2:
			cct_showstr(x + 2, y + 2, "��  ��", 0, 1);
			break;
		case 3:{
			cct_showstr(x + 2, y + 1, "��", 0, 1);
			cct_showstr(x + 4, y + 2, "��", 0, 1);
			cct_showstr(x + 6, y + 3, "��", 0, 1);
			break;
		}
		case 4: {
			cct_showstr(x + 2, y + 1, "��  ��", 0, 4);
			cct_showstr(x + 2, y + 3, "��  ��", 0, 4);
			break;
		}
		case 5: {
			cct_showstr(x + 2, y + 1, "��  ��", 0, 1);
			cct_showstr(x + 4, y + 2, "��", 0, 1);
			cct_showstr(x + 2, y + 3, "��  ��", 0, 1);
			break;
		}
		case 6: {
			cct_showstr(x + 2, y + 1, "��  ��", 0, 1);
			cct_showstr(x + 2, y + 2, "��  ��", 0, 1);
			cct_showstr(x + 2, y + 3, "��  ��", 0, 1);
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
		cout << "���������ϲ�㲩�����ã����ۣ�" << endl;
		s = 5;
		goto X;
	}
	else {
		for (i = 1; i <= 6; i++) {
			if (co[i] == 4 && i != 4) {
				cout << "��ϲ�㲩���Ľ�����ʿ)" << endl;
				s = 3;
				goto X;
			}
			else if (co[i] == 5 && i != 4) {
				if(!co[4])
				{
					cout << "ѧ���峵����ϲ�㲩�����ӵǿƣ�״Ԫ����" << endl;
					s = 7;
					goto X;
				}
				else {
					cout<< "ѧ���峵����ϲ�㲩�����Ӵ�һ�㣨״Ԫ������" << endl;
					s = 8;
					goto X;
				}
			}
			else if (co[i] == 6 && i != 4) {
				cout << "������˳����ϲ�㲩�������ڣ�״Ԫ��������" << endl;
				s = 10;
				goto X;
			}
		}

		switch (co[4]) {
			case 0:
				cout << "���ź���û���������" << endl;
				s = 0;
				break;
			case 1:
				cout << "��ϲ�㲩��һ�㣨��ţ�" << endl;
				s = 1;
				break;
			case 2:
				cout << "��ϲ�㲩�����٣����ˣ�" << endl;
				s = 2;
				break;
			case 3:
				cout << "��ϲ�㲩�����죨̽����" << endl;
				s = 4;
				break;
			case 4:
				dian = co[1] + 2 * co[2] + 3 * co[3] + 5 * co[5] + 6 * co[6];
				if (dian == 2)
				{
					cout << "���Ǹ��գ���ϲ�㲩����𻨣�״Ԫ����������" << endl;
					s = 12;
				}
				else
				{	
					cout << "�ķ����ƣ���ϲ�㲩���ĵ�죨״Ԫ����" << endl;
					s = 6;
				}
				break;
			case 5:
				cout << "�帣���ţ���ϲ�㲩��������״Ԫ������" << endl;
				s = 9;
				break;
			case  6:
				cout << "������˳����ϲ�㲩�������죨״Ԫ��������" << endl;
				s = 11;
				break;
			default:
				break;
		}
	}
	X:
	top = s > top ? s : top;
	zyd = zyd > dian ? zyd : dian;
	cout << "��ǰ��߼�¼��";
	switch (top) {
		case 0:
			cout << "���";
			break;
		case 1:
			cout << "һ��";
			break;
		case 2:
			cout << "����";
			break;
		case 3:
			cout << "�Ľ�";
			break;
		case 4:
			cout << "����";
			break;
		case 5:
			cout << "����";
			break;
		case 6:
			cout << "״Ԫ" << "������Ϊ��" << zyd << "��";
			break;
		case 7:
			cout << "���ӵǿ�";
			break;
		case 8:
			cout << "���Ӵ�һ��";
			break;
		case 9:
			cout << "����";
			break;
		case 10:
			cout << "������";
			break;
		case 11:
			cout << "������";
			break;
		case 12:
			cout << "״Ԫ���";
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
	cct_showstr(x, y, "�����������£�", 0, 7);
		{
			cct_showstr(x, ++y, "һ��", 0, 7);
			draw(x, ++y, 4);
			y += 4;
		}
		{
			cct_showstr(x, ++y, "����", 0, 7);
			draw(x, ++y, 4);
			draw(x + 10, y, 4);
			y += 4;
		}
		{
			cct_showstr(x, ++y, "�Ľ�(�������������4�ĵ���)", 0, 7);
			draw(x, ++y, 2);
			draw(x + 10, y, 2);
			draw(x + 20, y, 2);
			draw(x + 30, y, 2);
			y += 4;
		}
		{
			cct_showstr(x, ++y, "����", 0, 7);
			draw(x, ++y, 4);
			draw(x + 10, y, 4);
			draw(x + 20, y, 4);
			y += 4;
		}
		{
			cct_showstr(x, ++y, "����", 0, 7);
			draw(x, ++y, 1);
			draw(x + 10, y, 2);
			draw(x + 20, y, 3);
			draw(x + 30, y, 4);
			draw(x + 40, y, 5);
			draw(x + 50, y, 6);
			y += 4;
		}
		{
			cct_showstr(x, ++y, "״Ԫ", 0, 7);
			draw(x, ++y, 4);
			draw(x + 10, y, 4);
			draw(x + 20, y, 4);
			draw(x + 30, y, 4);
			y += 5;
		}
	}
	cct_showstr(x, y, "�س���ʼ������", 0, 7);
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
		cout << "��" << n << "�غϣ�";
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
		cout << endl << "�밴�س�������һ�غ�,�����밴�ո�";
		while (1) {
			char a = _getch();
			if (a == '\r')
				break;
			else if (a == 32) {
				cout << endl << "��Ϸ��������߼�¼Ϊ��";
				switch (s) {
				case 0:
					cout << "���";
					break;
				case 1:
					cout << "һ��";
					break;
				case 2:
					cout << "����";
					break;
				case 3:
					cout << "�Ľ�";
					break;
				case 4:
					cout << "����";
					break;
				case 5:
					cout << "����";
					break;
				case 6:
					cout << "״Ԫ" << "������Ϊ��" << zyd << "��";
				case 7:
					cout << "���ӵǿ�";
					break;
				case 8:
					cout << "���Ӵ�һ��";
					break;
				case 9:
					cout << "����";
					break;
				case 10:
					cout << "������";
					break;
				case 11:
					cout << "������";
					break;
				case 12:
					cout << "״Ԫ���";
					break;
				default:
					break;
				}
				cout << endl << endl;
				cout << "�밴�ո��˳�...";
				while (_getch() != 32);
	
				return 0;
			}
			
		}
		n++;
	}









}