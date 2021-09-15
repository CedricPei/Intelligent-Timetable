#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>
#include<string.h> 
#include<time.h>
#include"mouse.h"
#include"hz.h"
#include"run.h"
#include"chaxun.h"
#include"search.h"
#include"choose.h"
#include"count.h"

void runmode(class*x,int i)
{
	int week=1,move,PE,xuanxiu;
	char c;
	FILE* fp;
	if ((fp = fopen("c:\\ckeshe\\txt\\PE.txt", "rt")) == NULL)
	{
		printf("cannot open stwk1.txt");
	}
	
	for (move = 0; move < 2 * i; move++)
	{
		c = fgetc(fp);
	}
	c = fgetc(fp);
	PE = c-'0';
	c = fgetc(fp);
	xuanxiu = c-'0';
	fclose(fp);
	drawkcb(x,week, PE,xuanxiu);
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
		if(mouse_press(5, 20, 15, 52)==2||mouse_press(137, 20, 147, 52)==2||mouse_press(150, 60, 240, 90)==2||mouse_press(30, 60, 120, 90)==2||mouse_press(530, 440, 636, 470)==2|| mouse_press(270, 60, 360, 90) == 2|| mouse_press(390, 65, 480, 90) == 2)
		{
			MouseS=1;
		}
		else if(mouse_press(5,20,15,52)==1&&week>1)
		{
			week--;
			delay(200);
			drawkcb(x,week, PE, xuanxiu);
		}
		else if(mouse_press(137,20,147,52)==1&&week<20)
		{
			week++;
			delay(200);
			drawkcb(x,week, PE, xuanxiu);
		}
		else if(mouse_press(150, 60, 240, 90)==1)
		{
			clrmous(MouseX,MouseY);
			cxmode(1,x, &PE, &xuanxiu);
			drawkcb(x,week, PE, xuanxiu);
		}
		else if(mouse_press(30, 60, 120, 90)==1)
		{
			clrmous(MouseX,MouseY);
			cxmode(2,x,&PE,&xuanxiu);
			drawkcb(x,week, PE, xuanxiu);
		}
		else if(mouse_press(530, 440, 636, 470)==1)
		{
			delay(200);
			return;
		}
		else if(mouse_press(270, 60, 360, 90)==1)
		{
			delay(200);
			clrmous(MouseX,MouseY);
			search(x);
			drawkcb(x, week, PE, xuanxiu);
		}
		else if(mouse_press(390, 65, 480, 90)==1)
		{
			choose(i,&PE,&xuanxiu);
        	drawkcb(x,week, PE,xuanxiu);
		}
		else
		{
			MouseS=0;
		}
	}
}

void drawkcb(class*x,int week,int PE,int xuanxiu)
{
	int i,j,k,h;
	char wk[3];
	memset(wk, '\0', sizeof(wk));
	clrmous(MouseX, MouseY);
	clearviewport();

	setfillstyle(1, CYAN);
	bar(0, 0, 1023, 767);

	setfillstyle(1, WHITE);//画表填充
	bar(40, 100, 600, 400);

	setfillstyle(1, LIGHTGREEN);//画选项

	bar(30, 60, 120, 90);
	puthz(40, 65, "按课程查", 16, 20, BLUE);
	bar(150, 60, 240, 90);
	puthz(160, 65, "按日期查", 16, 20, BLUE);
	bar(270, 60, 360, 90);
	puthz(280, 65, "按校历查", 16, 20, BLUE);
	bar(390, 60, 480, 90);
	puthz(400, 65, "选择课程", 16, 20, BLUE);

	setfillstyle(1, LIGHTGRAY);
	bar(530, 440, 636, 470);
	puthz(550, 445, "返回", 24, 34, BLACK);

	setcolor(BLACK);//画表
	rectangle(40, 100, 600, 400);
	for (i = 0; i < 8; i++)
	{
		line(40, 136 + i * 33, 600, 136 + i * 33);
	}

	for (i = 1; i < 8; i++)
	{
		line(40 + i * 70, 100, 40 + i * 70, 400);
	}

	puthz(40 + 1 * 70 + 25, 100 + 16, "一", 16, 20, BLACK);
	puthz(40 + 2 * 70 + 25, 100 + 16, "二", 16, 20, BLACK);
	puthz(40 + 3 * 70 + 25, 100 + 16, "三", 16, 20, BLACK);
	puthz(40 + 4 * 70 + 25, 100 + 16, "四", 16, 20, BLACK);
	puthz(40 + 5 * 70 + 25, 100 + 16, "五", 16, 20, BLACK);
	puthz(40 + 6 * 70 + 25, 100 + 16, "六", 16, 20, BLACK);
	puthz(40 + 7 * 70 + 25, 100 + 16, "日", 16, 20, BLACK);

	puthz(20, 20, "第", 32, 40, BLACK);
	puthz(100, 20, "周", 32, 40, BLACK);
	line(5, 36, 15, 20);
	line(5, 36, 15, 52);
	line(15, 20, 15, 52);
	line(147, 36, 137, 20);
	line(147, 36, 137, 52);
	line(137, 20, 137, 52);

	setfillstyle(1, YELLOW);
	floodfill(6, 36, BLACK);
	floodfill(146, 36, BLACK);

	setcolor(BLACK);
	settextstyle(2, 0, 9);
	itoa(week, wk, 10);
	outtextxy(70, 22, wk);
	settextstyle(2, 0, 4);
	outtextxy(50, 136 + 20, "8:10-8:55");
	outtextxy(50, 136 + 20 + 1 * 33, "8:10-8:55");
	outtextxy(50, 136 + 20 + 2 * 33, "9:00-9:45");
	outtextxy(45, 136 + 20 + 3 * 33, "10:15-11:00");
	outtextxy(45, 136 + 20 + 4 * 33, "11:05-11:50");
	outtextxy(45, 136 + 20 + 5 * 33, "14:30-15:15");
	outtextxy(45, 136 + 20 + 6 * 33, "15:20-16:05");
	outtextxy(45, 136 + 20 + 7 * 33, "16:25-17:10");

	settextstyle(2, 0, 7);
	outtextxy(70, 134, "1");
	outtextxy(70, 134 + 1 * 33, "2");
	outtextxy(70, 134 + 2 * 33, "3");
	outtextxy(70, 134 + 3 * 33, "4");
	outtextxy(70, 134 + 4 * 33, "5");
	outtextxy(70, 134 + 5 * 33, "6");
	outtextxy(70, 134 + 6 * 33, "7");
	outtextxy(70, 134 + 7 * 33, "8");

	for(i=0;i<10;i++)
	{
		setfillstyle(1,(x+i)->color);
		if(week>=(x+i)->stwk&&week<=(x+i)->edwk)
		{
			for(j=0;j<(x+i)->mzjs;j++)
		    {
			    k=(x+i)->t[j][0];
			    h=(x+i)->t[j][1];
				if (k > 0 && h > 0)
				{
					bar(40 + k * 70 + 1, 136 + (h - 1) * 66 + 1, 40 + (k + 1) * 70 - 1, 136 + h * 66 - 1);
					if ((x + i)->zfhz == 1)
					{
						settextstyle(2, 0, 8);
						outtextxy(40 + k * 70 + 30, 136 + (h - 1) * 60 + 18, (x + i)->cname);
					}
					else
					{
						if (i == 8)
						{
							switch (PE)
							{
							case 1:
								puthz(40 + k * 70 + 1, 136 + (h - 1) * 66 + 22, "足球", 16, 16, WHITE);
								break;

							case 2:
								puthz(40 + k * 70 + 1, 136 + (h - 1) * 66 + 22, "篮球", 16, 16, WHITE);
								break;

							case 3:
								puthz(40 + k * 70 + 1, 136 + (h - 1) * 66 + 22, "排球", 16, 16, WHITE);
								break;

							default:
								puthz(40 + k * 70 + 1, 136 + (h - 1) * 66 + 22, (x + i)->cname, 16, 16, WHITE);
								break;
							}
						}
						else if (i == 9)
						{
							switch (xuanxiu)
							{
							case 1:
								puthz(40 + k * 70 + 1, 136 + (h - 1) * 66 + 22, "国学", 16, 16, WHITE);
								break;

							case 2:
								puthz(40 + k * 70 + 1, 136 + (h - 1) * 66 + 22, "心理", 16, 16, WHITE);
								break;

							case 3:
								puthz(40 + k * 70 + 1, 136 + (h - 1) * 66 + 22, "音乐", 16, 16, WHITE);
								break;

							default:
								puthz(40 + k * 70 + 1, 136 + (h - 1) * 66 + 22, (x + i)->cname, 16, 16, WHITE);
								break;
							}
						}
						else if ((x + i)->color == 1 || (x + i)->color == 2 || (x + i)->color == 5 || (x + i)->color == 8)
						{
							puthz(40 + k * 70 + 1, 136 + (h - 1) * 66 + 22, (x + i)->cname, 16, 16, WHITE);
						}
						else
						{
							puthz(40 + k * 70 + 1, 136 + (h - 1) * 66 + 22, (x + i)->cname, 16, 16, BLACK);
						}
					}
				}
		    }
		}
	}
}
