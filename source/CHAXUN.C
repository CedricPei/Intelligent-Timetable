#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>
#include<string.h> 
#include<time.h>
#include"mouse.h"
#include"hz.h"
#include"chaxun.h"
#include"stu.h"
#include"run.h"
#include"search.h"
#include"out.h"

void cxmode(int choose,class*x,int *PE,int*xuanxiu)
{
	clearviewport();
	setfillstyle(1,LIGHTCYAN);
	bar(0,0,640,480);
	switch(choose)
	{
		case 1:
			 datecx(x,PE,xuanxiu);
			 delay(200);
			 break;
			 
		case 2:
			setfillstyle(1,BLACK);
			bar(0,0,640,480);
			classcx(x);
			delay(200);
			 break;
		
	}
}

void datecx(class*x, int* PE, int* xuanxiu)
{
	int wk,day;
	char buffer1[5];
	setfillstyle(1,WHITE);
	puthz(80,130,"第",32,32,BLACK);
	bar(120,130,160,162);
	puthz(160,130,"周",32,32,BLACK);
	puthz(220,130,"星期",32,32,BLACK);
	bar(285,130,325,162);
	bar(360,130,460,166);//查询框 
	puthz(360,133,"查询",32,32,BLACK);
	bar(530,440,636,480);//返回框 
	puthz(560,448,"返回",24,24,BLACK);
	memset(buffer1, '\0', sizeof(buffer1));
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
		if(mouse_press(120,130,160,162)==2||mouse_press(285,130,325,162)==2)
		{
			MouseS=2;
		}
		else if(mouse_press(360,130,460,166)==2)
		{
			MouseS=1;
		}
		else if(mouse_press(120,130,160,162)==1)
		{
			bar(120,130,160,162);
			shuru1(120,133,buffer1,0,168,133);
			wk=atoi(buffer1);
		}
		else if(mouse_press(285,130,325,162)==1)
		{
			bar(285,130,325,162);
			shuru1(285,133, buffer1,0,333,133);
			day=atoi(buffer1);
		}
		else if(mouse_press(360,130,460,166)==1)
		{
			if(wk==0||day==0)
			{
				puthz(360,170,"请输入日期",32,23,RED);
				delay(200);
				setfillstyle(1,LIGHTCYAN);
				bar(360,168,520,210);
				continue;
			}
			else
			{
				page2(&wk, &day, x);
				delay(200);
				setfillstyle(1,LIGHTCYAN);
				bar(0,0,640,480);
				draw();
			}
		}
		else if(mouse_press(530,440,636,480)==1)
		{
			return;
		}
		else
		{
			MouseS=0;
		} 
	}
}


void draw()
{
	setfillstyle(1,WHITE);
	puthz(80,130,"第",32,32,BLACK);
	bar(120,130,160,162);
	puthz(160,130,"周",32,32,BLACK);
	puthz(220,130,"星期",32,32,BLACK);
	bar(285,130,325,162);
	bar(360,130,460,166);//查询框 
	puthz(360,133,"查询",32,32,BLACK);
	bar(530,440,636,480);//返回框 
	puthz(560,448,"返回",24,24,BLACK);
}

void classcx(class*x)
{
	int r=0,i;//r用于记录列表展开状态 
	setfillstyle(1,WHITE);
	bar(0,0,640,480);
	puthz(0,3,"选择课程",16,16,BLACK);
	setcolor(BLACK);
	moveto(80,2);
	lineto(98,2);
	lineto(89,23);
	lineto(80,2);
	rectangle(530,440,636,480);
	puthz(560,448,"返回",24,24,BLACK);
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
		if(mouse_press(99,3,129,28)==2)
		{
			MouseS=1;
		}
		else if(mouse_press(80,2,98,23)==1&&r==0)//展开列表 
		{
			delay(200);
			setfillstyle(1,WHITE);
			line(0,25,100,25);
			for(i=0;i<10;i++)
			{
				bar(0,(i+1)*25,100,(i+2)*25);
				line(0,(i+2)*25,100,(i+2)*25);
				if((x+i)->zfhz==1)
				{
					settextstyle(2,0,8);
					outtextxy(0,(i+1)*25,(x+i)->cname);
					
				} 
				else
				{
					puthz(0,3+(i+1)*25,(x+i)->cname,16,16,BLACK);
				}
				//puthz(0,3+(i+1)*25,(x+i)->cname,16,16,BLACK);
			}
			r=1;
		}
		else if(mouse_press(80,2,98,23)==1&&r==1)
		{
			delay(200);
			setfillstyle(1,WHITE);
			bar(0,25,100,300);
			puthz(0,38,"起始周",24,24,BLACK);
	        puthz(0,38+30,"结束周",24,24,BLACK);
	        puthz(0,38+60,"教师姓名",24,24,BLACK);
	        puthz(0,38+90,"上课地点",24,24,BLACK);
	        puthz(0,38+120,"上课时间",24,24,BLACK);
	        for(i=0;i<5;i++)
	        {
		        line(0,35+i*30,640,35+i*30);
        		//puthz(120,158+i*30,"星期",24,24,WHITE);
	        }
	        r=0;
		}
		else if (mouse_press(530, 440, 636, 480) == 1)
		{
			return;
		}
		else
		{
			MouseS = 0;
		}
		for (i = 0; i < 10; i++)
		{
			if (mouse_press(0, 25+i*25, 100, 50+i*25) == 1 && r == 1)
			{
				clrmous(MouseX, MouseY);
				huajiemian(i, x);
				setfillstyle(1, WHITE);
				bar(0, 0, 100, 25);
				moveto(80, 2);
				lineto(98, 2);
				lineto(89, 23);
				lineto(80, 2);
				if ((x + i)->zfhz == 1)
				{
					outtextxy(0, 0, (x + i)->cname);
				}
				else
				{
					puthz(0, 3, (x + i)->cname, 16, 16, BLACK);
				}
				r = 0;
			}
		}
	}
}

void huajiemian(int n,class*x)
{
	int i;
	char rom[5],fl[5],st[5],ed[5];
	char tim[5][5];
	memset(rom, '\0', sizeof(rom));
	memset(fl, '\0', sizeof(fl));
	memset(st, '\0', sizeof(st));
	memset(ed, '\0', sizeof(ed));
	memset(tim, '\0', sizeof(tim));
	for(i=0;i<5;i++)
	{
		itoa((x+n)->t[i][0],tim[i],10);
	}
	itoa((x+n)->stwk,st,10);
	itoa((x+n)->edwk,ed,10);
	itoa((x+n)->flr,fl,10);
	itoa((x+n)->room,rom,10);
	setfillstyle(1,WHITE);
	bar(0,0,640,480);
	setcolor(BLACK);
	setlinestyle(0,0,1);
	
	for(i=0;i<5;i++)
	{
		line(0,35+i*30,640,35+i*30);
		if ((x + n)->t[i][0] != 0)
		{
			if (n != 9)
			{
				puthz(120, 158 + i * 30, "星期", 24, 24, BLACK);
			}
			else if(n==9&&i==0)
			{
				puthz(120, 158 + i * 30, "星期", 24, 24, BLACK);
			}
		}
	}
	puthz(0,38,"起始周",24,24,BLACK);
	puthz(0,38+30,"结束周",24,24, BLACK);
	puthz(0,38+60,"教师姓名",24,24, BLACK);
	if (n == 9)
	{
		setfillstyle(1, WHITE);
	}
	puthz(0,38+90,"上课地点",24,24, BLACK);
	puthz(0,38+120,"上课时间",24,24, BLACK);
	//setfillstyle(1,WHITE);
	setlinestyle(0, 0, 1);
	rectangle(530,440,636,480);
	puthz(560,448,"返回",24,24,BLACK);
	settextstyle(2,0,8);
	outtextxy(120,35,st);
	outtextxy(120,65,ed);
	if (n != 9)
	{
		puthz(120, 98, (x + n)->tcname, 24, 24, BLACK);
	}
	if((x+n)->bui==1)
	{
		puthz(120,128,"东九",24,24, BLACK);
		outtextxy(180,125,"A");
	}
	else if((x+n)->bui==2)
	{
		puthz(120,128,"东九",24,24, BLACK);
		outtextxy(180,125,"B");
	}
	else if((x+n)->bui==3)
	{
		puthz(120,128,"东九",24,24, BLACK);
		outtextxy(180,125,"C");
	}
	else if((x+n)->bui==4)
	{
		puthz(120,128,"东九",24,24, BLACK);
		outtextxy(180,125,"D");
	}
	else if((x+n)->bui==5)
	{
		puthz(120,128,"东十二",24,24, BLACK);
	}
	else if(n==8)
	{
		puthz(120,128,"东校区操场",24,24, BLACK);
	}
	else if(n==9)
	{
		puthz(120,128,"待定",24,24, BLACK);
	}
	if(n!=8&&n!=9)
	{
		outtextxy(192,125,fl);
	    outtextxy(204,125,"0");
	    outtextxy(216,125,rom);
	} 
	for(i=0;i<(x+n)->mzjs;i++)
	{
		outtextxy(180,155+i*30,tim[i]);
		if((x+n)->t[i][1]==1)
		{
			outtextxy(204,155+i*30,"8:00-8:45 8:55-9:40");
		}
		else if((x+n)->t[i][1]==2)
		{
			outtextxy(204,155+i*30,"10:10-10:55 11:05-11:50");
		}
		else if((x+n)->t[i][1]==3)
		{
			outtextxy(204,155+i*30,"14:00-14:45 14:50-15:35");
		}
		else if((x+n)->t[i][1]==4)
		{
			outtextxy(204,155+i*30,"15:55-16:40 16:45-17:30");
		}
	}
}
