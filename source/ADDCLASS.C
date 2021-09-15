#include<stdio.h>
#include<conio.h>
#include"graphics.h"
#include<stdlib.h>
#include<time.h>
#include"addclass.h"
#include"mouse.h"
#include"hz.h"
#include"dos.h"

void addclass(class*x)
{
	int timetable[20];
	int i,j,k,kcnum=0;
	char temp_mzjs[5];
	memset(timetable, 0, sizeof(timetable));
	memset(temp_mzjs, '\0', sizeof(temp_mzjs));
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 5; j++)
		{
			if ((x + i)->t[j][0] > 0 && (x + i)->t[j][1] > 0)
			{
				k = ((x + i)->t[j][0] - 1) * 4 + (x + i)->t[j][1] - 1;
				timetable[k] = 1;
			}
		}
	}
	for (i = 0; i < 20; i++)
	{
		if (timetable[i] == 1)
		{
			kcnum++;
		}
	}
	
	addview(x);
	while (1)
	{
		newmouse(&MouseX, &MouseY, &press);
		for (i = 0; i < 8; i++)
		{
			if (mouse_press(415, 53 + i * 50, 425, 63 + i * 50) == 1)
			{
				delay(150);
				if ((x + i)->mzjs < 5&&kcnum<20)
				{
					(x + i)->mzjs++;
					kcnum++;
					setfillstyle(1, WHITE);
					bar(315, 45 + i * 50, 405, 72 + i * 50);
					itoa((x + i)->mzjs, temp_mzjs, 10);
					outtextxy(315, 45 + i * 50, temp_mzjs);
					for (j = 0; j < 20; j++)
					{
						if (timetable[j] != 1)//找到一个没课的位置
						{
							timetable[j] = 1;
							break;
						}
					}
					for (k = 0; k < 5; k++)
					{
						if ((x + i)->t[k][0] < 1)
						{
							break;
						}
					}
					(x + i)->t[k][0] = (j - j % 4) / 4 + 1;
					(x + i)->t[k][1] = j - ((x + i)->t[k][0] - 1) * 4 + 1;
					break;
				}
				else if ((x + i)->mzjs < 5 && kcnum >= 20)
				{
					puthz(400, 157 + 8 * 35, "课表已满", 24, 24, RED);
					delay(500);
					setfillstyle(1, GREEN);
					bar(400, 157 + 8 * 35, 530, 157 + 8 * 35 + 30);
					break;
				}
				else if((x + i)->mzjs >= 5)
				{
					puthz(400, 157 + 8 * 35, "已达上限", 24, 24, RED);
					delay(500);
					setfillstyle(1, GREEN);
					bar(400, 157 + 8 * 35, 530, 157 + 8 * 35 + 30);
					break;
				}

			}
		}
		for (i = 0; i < 8; i++)
		{
			if (mouse_press(295, 53 + i * 50, 305, 63 + i * 50) == 1)
			{
				delay(150);
				if ((x + i)->mzjs > 0)
				{
					(x + i)->mzjs--;
					kcnum--;
					setfillstyle(1, WHITE);
					bar(315, 45 + i * 50, 405, 72 + i * 50);
					itoa((x + i)->mzjs, temp_mzjs, 10);
					outtextxy(315, 45 + i * 50, temp_mzjs);
					for (j = 4; j >= 0; j--)
					{
						if ((x + i)->t[j][0] > 0 && (x + i)->t[j][1] > 0)
						{
							(x + i)->t[j][0] = 0, (x + i)->t[j][1] = 0;
							break;
						}
					}
				}
			}
		}
		if (mouse_press(530, 440, 636, 470) == 1)
		{
			return;
		}
	}
}


void addview(class*x)
{
	int i;
	char temp_mzjs[5];
	clearviewport();
	clrmous(MouseX, MouseY);
	setfillstyle(1,GREEN);
	bar(0,0,640,480);
	setfillstyle(1,WHITE);
	settextstyle(2,0,8);
	bar(530, 440, 636, 470);
	puthz(550, 445, "完成", 24, 34, BLACK);
	puthz(315, 5, "每周节数", 24, 24, BLACK);
	puthz(10, 5, "课程名称", 24, 24, BLACK);
	for(i=0;i<8;i++)
	{
		bar(10,45+i*50,110,72+i*50);
		bar(315,45+i*50,405,72+i*50);
		if((x+i)->zfhz==1)
		{
			outtextxy(10,45+i*50,(x+i)->cname);
		}
		else
		{
			puthz(10,48+i*50,(x+i)->cname,24,24,BLACK);
		}
		itoa((x+i)->mzjs, temp_mzjs,10);
		outtextxy(315,45+i*50,temp_mzjs);
		circle(300,58+i*50,10);
		circle(420,58+i*50,10);
		outtextxy(295,43+i*50,"-");
		outtextxy(415,43+i*50,"+");
	}
}
