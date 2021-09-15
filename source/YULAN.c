#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>
#include<time.h>
#include<string.h> 
#include"mouse.h"
#include"hz.h"
#include"run.h"
#include"yulan.h"
#include"addclass.h"


void tiaoz(class*x)
{
	int week=1,flag=0,i,j,subject,judge;
	int day[2] = { 0 }, jie[2] = { 0 };
	yulanjm(x,week);
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
		if(mouse_press(215,442,242,478)==2||mouse_press(501,442,528,478)==2||mouse_press(0,440,106,480)==2||mouse_press(106,440,212,480)==2||mouse_press(530,440,636,480)==2)
		{
			MouseS=1;
		}
		else if(mouse_press(5, 20, 15, 52)==1&&week>1&&flag==0)
		{
			week--;
			delay(200);
			yulanjm(x,week);
		}
		else if(mouse_press(137, 20, 147, 52)==1&&week<20&&flag==0)
		{
			week++;
			delay(200);
			yulanjm(x,week);
		}
		else if (mouse_press(150, 60, 240, 90) == 1 && flag == 0)
		{
			addclass(x);
			delay(200);
			yulanjm(x, week);
		}
		else if(mouse_press(530, 440, 636, 470)==1&&flag==0)
		{
			delay(200);
			return;
		}
		else if(mouse_press(0,0,640,480)==1&&flag==0)
		{
			day[1] = 0, jie[1] = 0;//重新初始化这两个变量
			delay(100);
			for(i=0;i<5;i++)
			{
				for(j=0;j<4;j++)
				{
					if(MouseX>(i+1)*70+40&&MouseX<(i + 2) * 70 + 40 &&MouseY>136 + j * 66 &&MouseY< 136 + (j+1) * 66)
					{
						day[0]=i+1,jie[0]=j+1;
						break;
					}
				}
			}
			for(i=0;i<10;i++)
			{
				for(j=0;j<5;j++)
				{
					if((x+i)->t[j][0]==day[0]&&(x+i)->t[j][1]==jie[0])
					{
						flag=1;
						subject=i;
						break;
					}
				}
			}
				
		}
		else if(mouse_press(0,0,640,480)==1&&flag==1)
		{
			delay(100);
			flag=0;
			for(i=0;i<5;i++)
			{
				for(j=0;j<4;j++)
				{
					if(MouseX > (i + 1) * 70 + 40 && MouseX < (i + 2) * 70 + 40 && MouseY>136 + j * 66 && MouseY < 136 + (j + 1) * 66)
					{
						day[1]=i+1,jie[1]=j+1;//获得新的时间
						break;
					}
				}
			}
			judge=0;
			for(i=0;i<10;i++)
			{
				for(j=0;j<5;j++)
				{
					if(day[1]==(x+i)->t[j][0]&&jie[1]==(x+i)->t[j][1])
					{
						judge=1;//判断新的时间是否已经有课
					}
				}
			}
			/*if (MouseX < 120 && MouseX>30 && MouseY < 90 && MouseY > 60)//删除课程
			{
				for (i = 0; i < 5; i++)
				{
					if ((x + subject)->t[i][0] == day[0] && (x + subject)->t[i][1] == jie[0])
					{
						(x + subject)->t[i][0] = 0, (x + subject)->t[i][1] = 0;
						(x + subject)->mzjs--;
						break;
					}
				}
				yulanjm(x, week);
				continue;
			}*/

			if(judge==1||day[1]==0||jie[1]==0|| (day[0] == 2 && jie[0] == 4)|| (day[0] == 4 && jie[0] == 4))//day[1]==0是点击位置不在课程表内的情况,体育课选修课不能调
			{
				puthz(2,448,"无效移动",24,24,RED);
				delay(300);
				setfillstyle(1, CYAN);
				bar(0,442,210,480);
				yulanjm(x,week);
				continue;
			}
			else
			{
				for(i=0;i<5;i++)
				{
					if((x+subject)->t[i][0]==day[0]&&(x+subject)->t[i][1]==jie[0])
					{
						(x+subject)->t[i][0]=day[1],(x+subject)->t[i][1]=jie[1];
						break;
					}
				}
				yulanjm(x,week);
				continue;
			}
		}
		else
		{
			MouseS=0;
		}
		
	}
}

void yulanjm(class*x,int week)
{
	int i, j, k, h;
	char wk[3];
	x->color = 1;//颜色 
	(x + 1)->color = 2;
	(x + 2)->color = 3;
	(x + 3)->color = 4;
	(x + 4)->color = 5;
	(x + 5)->color = 6;
	(x + 6)->color = 8;
	(x + 7)->color = 9;
	(x + 8)->color = 7;
	(x + 9)->color = 7;
	clrmous(MouseX, MouseY);
	clearviewport();

	setfillstyle(1, CYAN);
	bar(0, 0, 1023, 767);

	setfillstyle(1, WHITE);//画表填充
	bar(40, 100, 600, 400);

	setfillstyle(1, LIGHTGREEN);//画选项

	//bar(30, 60, 120, 90);
	//puthz(40, 65, "删除课程", 16, 20, BLUE);
	bar(150, 60, 240, 90);
	puthz(160, 65, "变更数量", 16, 20, BLUE);

	setfillstyle(1, LIGHTGRAY);
	bar(530, 440, 636, 470);
	puthz(550, 445, "完成", 24, 34, BLACK);

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

	for (i = 0; i < 10; i++)
	{
		setfillstyle(1, (x + i)->color);
		if (week >= (x + i)->stwk && week <= (x + i)->edwk)
		{
			for (j = 0; j < (x + i)->mzjs; j++)
			{
				k = (x + i)->t[j][0];
				h = (x + i)->t[j][1];
				if (k > 0 && h > 0)
				{
					bar(40 + k * 70 + 1, 136 + (h - 1) * 66 + 1, 40 + (k + 1) * 70 - 1, 136 + h * 66 - 1);
					if ((x + i)->zfhz == 1)
					{
						settextstyle(2, 0, 8);
						outtextxy(40 + k * 70 + 30, 136 + (h - 1) * 60 + 18, (x + i)->cname);
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
