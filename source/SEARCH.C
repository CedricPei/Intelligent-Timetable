#include<stdio.h>
#include<graphics.h>
#include<dos.h>
#include<graphics.h>
#include<string.h>
#include<stdlib.h>
#include"hz.h"
#include"mouse.h"
#include"search.h"
#include"test.h"


void page1(int* week, int* day)
{
	int month = 9;
	int date = 1;
	int row;
	int column;
	char month_string[3];
	char date_string[3];
	int location_x = 117;
	int location_y = 47;
	int flag_return = 0;
	memset(month_string, '\0',sizeof(month_string));
	memset(date_string, '\0', sizeof(date_string));

	mouseinit();
	clrmous(MouseX, MouseY);

	cleardevice();
	setfillstyle(1, WHITE);
	bar(0, 0, 640, 480);
	setcolor(DARKGRAY);
	line(10, 20, 630, 20);
	line(10, 42, 630, 42);
	line(10, 64, 630, 64);
	line(10, 86, 630, 86);
	line(10, 108, 630, 108);
	line(10, 130, 630, 130);
	line(10, 152, 630, 152);
	line(10, 174, 630, 174);
	line(10, 196, 630, 196);
	line(10, 218, 630, 218);
	line(10, 240, 630, 240);
	line(10, 262, 630, 262);
	line(10, 284, 630, 284);
	line(10, 306, 630, 306);
	line(10, 328, 630, 328);
	line(10, 350, 630, 350);
	line(10, 372, 630, 372);
	line(10, 394, 630, 394);
	line(10, 416, 630, 416);
	line(10, 20, 10, 416);
	line(91, 20, 91, 416);
	line(168, 20, 168, 416);
	line(245, 20, 245, 416);
	line(322, 20, 322, 416);
	line(399, 20, 399, 416);
	line(476, 20, 476, 416);
	line(553, 20, 553, 416);
	line(630, 20, 630, 416);
	puthz(25, 25, "周次", 16, 33, RED);
	puthz(117, 25, "一", 16, 33, RED);
	puthz(197, 25, "二", 16, 33, RED);
	puthz(275, 25, "三", 16, 33, RED);
	puthz(351, 25, "四", 16, 33, RED);
	puthz(428, 25, "五", 16, 33, RED);
	puthz(505, 25, "六", 16, 33, RED);
	puthz(582, 25, "日", 16, 33, RED);
	puthz(40, 47, "一", 16, 33, RED);
	puthz(40, 69, "二", 16, 33, RED);
	puthz(40, 91, "三", 16, 33, RED);
	puthz(40, 113, "四", 16, 33, RED);
	puthz(40, 135, "五", 16, 33, RED);
	puthz(40, 157, "六", 16, 33, RED);
	puthz(40, 179, "七", 16, 33, RED);
	puthz(40, 201, "八", 16, 33, RED);
	puthz(40, 223, "九", 16, 33, RED);
	puthz(40, 245, "十", 16, 33, RED);
	puthz(30, 267, "十一", 16, 25, RED);
	puthz(30, 289, "十二", 16, 25, RED);
	puthz(30, 311, "十三", 16, 25, RED);
	puthz(30, 333, "十四", 16, 25, RED);
	puthz(30, 355, "十五", 16, 25, RED);
	puthz(30, 377, "十六", 16, 25, RED);
	puthz(30, 399, "十七", 16, 25, RED);
	puthz(560, 448, "返回", 24, 24, RED);
	setcolor(BLUE);
	rectangle(530, 440, 636, 480);
	settextstyle(SMALL_FONT, HORIZ_DIR, 3);

	for (row = 0; row < 17; row++)
	{
		for (column = 0; column < 7; column++)
		{
			itoa(date, date_string, 10);
			if (1 == date)
			{
				itoa(month, month_string, 10);
				strcat(month_string, ".");
				strcat(month_string, date_string);
				outtextxy(location_x, location_y, month_string);
			}
			if (date != 1)
			{
				outtextxy(location_x, location_y, date_string);
			}
			if (date == limit(month))
			{
				date = 0;
				month += 1;
				if (13 == month)
				{
					month = 1;
				}
			}
			date += 1;
			location_x += 77;
		}
		location_x = 117;
		location_y += 22;
	}

	save_bk_mou(MouseX, MouseY);
	drawmous(MouseX, MouseY);

	while (1)
	{
		newmouse(&MouseX, &MouseY, &press);

		if (mouse_press(530, 440, 636, 480) == 1)
		{
			flag_return = 1;
		}
		if (flag_return == 1)
		{
			return;
		}
		location_x = 91;
		location_y = 47;
		if (1 == mouse_press(0, 0, 640, 480))
		{
			for (row = 0; row < 17; row++)
			{
				if (location_y < MouseY && (location_y + 22)>MouseY)
				{
					(*week) = row + 1;
				}
				for (column = 0; column < 7; column++)
				{
					if (location_x < MouseX && (location_x + 77)>MouseX)
					{
						(*day) = column + 1;
						break;
					}
					else
					{
						location_x += 77;
					}
				}
				location_x = 91;
				location_y += 22;
			}
		}
		if ((*week) > 0 && (*day) > 0)
		{
			break;
		}
	}

}

void page2(int* week, int* day, class* x)
{
	int location_x = 10;
	int location_y = 100;
	char str_1[2];
	char* str_2 = "第";
	char* str_3 = "节";
	char str_4[6];
	char str_5[4];
	int flag_break = 0;
	int room_location;
	int i, n;
	memset(str_1, '\0', sizeof(str_1));
	memset(str_4, '\0', sizeof(str_4));
	memset(str_5, '\0', sizeof(str_5));

	itoa(*day, str_5, 10);
	outtextxy(70, 10, str_5);

	cleardevice();
	clrmous(MouseX, MouseY);
	setfillstyle(1, WHITE);
	bar(0, 0, 640, 480);
	puthz(240, 10, "当日信息", 16, 33, RED);
	puthz(25, 35, "课程", 16, 33, RED);
	puthz(175, 35, "时间", 16, 33, RED);
	puthz(375, 35, "地点", 16, 33, RED);
	puthz(525, 35, "老师", 16, 33, RED);
	puthz(560, 448, "退出", 24, 24, RED);
	setcolor(BLUE);
	setlinestyle(0, 0, THICK_WIDTH);
	circle(47, 45, 27);
	circle(197, 45, 27);
	circle(397, 45, 27);
	circle(547, 45, 27);
	line(0, 80, 640, 80);
	moveto(300, 0);
	lineto(220, 20);
	lineto(300, 40);
	lineto(380, 20);
	lineto(300, 0);
	setcolor(DARKGRAY);
	line(150, 80, 150, 480);
	line(250, 80, 250, 480);
	line(475, 80, 475, 266);
	setcolor(GREEN);
	moveto(480, 350);
	lineto(400, 350);
	lineto(490, 300);
	lineto(400, 300);
	lineto(510, 250); //顶点
	lineto(620, 300);
	lineto(530, 300);
	lineto(620, 350);
	lineto(540, 350);
	lineto(580, 410);
	lineto(540, 410);
	lineto(540, 470);
	lineto(480, 470);
	lineto(480, 410);
	lineto(440, 410);
	lineto(480, 350);
	setcolor(RED);
	rectangle(530, 440, 636, 480);

	for (i = 0; i < 10; i++)
	{
		if ((x + i)->stwk <= *week && (x + i)->edwk >= *week)
		{
			for (n = 0; n < 5; n++)
			{
				if ((x + i)->t[n][0] == *day)
				{
					if ((x + i)->zfhz == 1)
					{
						settextstyle(2, 0, 8);
						outtextxy(location_x, location_y, (x + i)->cname);
					}
					else
					{
						puthz(location_x, location_y, (x + i)->cname, 16, 33, RED);
					}
					location_x += 150;

					settextstyle(SMALL_FONT, HORIZ_DIR, 6);
					itoa((x + i)->t[n][1], str_1, 10);
					puthz(location_x, location_y, str_2, 16, 33, RED);
					outtextxy(location_x + 15, location_y - 5, str_1);
					puthz(location_x + 25, location_y, str_3, 16, 33, RED);
					location_x += 150;

					if (8 == i)
					{
						puthz(location_x, location_y, "东校区操场", 16, 33, RED);
					}
					else if (9 == i)
					{
						puthz(location_x, location_y, "待定", 16, 33, RED);
					}
					else
					{
						switch ((x + i)->bui)
						{
						case 1:
							puthz(location_x, location_y, "东九", 16, 33, RED);
							outtextxy(location_x + 60, location_y, "A");
							break;
						case 2:
							puthz(location_x, location_y, "东九", 16, 33, RED);
							outtextxy(location_x + 60, location_y, "B");
							break;
						case 3:
							puthz(location_x, location_y, "东九", 16, 33, RED);
							outtextxy(location_x + 60, location_y, "C");
							break;
						case 4:
							puthz(location_x, location_y, "东九", 16, 33, RED);
							outtextxy(location_x + 60, location_y, "D");
							break;
						case 5:
							puthz(location_x, location_y, "东十二", 16, 33, RED);
							break;
						}
						location_x += 90;

						room_location = 100 * (x + i)->flr + (x + i)->room;
						itoa(room_location, str_4, 10);
						outtextxy(location_x, location_y, str_4);
					}
					location_x += 150;

					puthz(location_x, location_y, (x + i)->tcname, 16, 33, RED);
					location_x = 10;
					location_y += 60;
				}
			}
		}
	}
	while (1)
	{
		newmouse(&MouseX, &MouseY, &press);
		if (mouse_press(530, 440, 636, 480) == 1)
		{
			flag_break = 1;
		}
		if (flag_break == 1)
		{
			delay(200);
			break;
		}
	}
}


void search(class* x)
{
	
	int week=0;
	int day=0;
	page1(&week,&day);
	page2(&week,&day,x);
}


int limit(int month)
{
	int limit;
	switch(month)
	{
		case 9:
			limit=30;
			break;
		case 10:
			limit=31;
			break;
		case 11:
			limit=30;
			break;
		case 12:
			limit=31;
			break;
	}
    return limit;
}
