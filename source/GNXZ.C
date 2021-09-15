#include<stdio.h>
#include"count.h"
#include<stdio.h>
#include<graphics.h>
#include<stdlib.h>
#include<string.h> 
#include<time.h>
#include"mouse.h"
#include"hz.h"
#include"stu.h"
#include"djs.h"
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<dos.h>
#include"GNXZ.h"
#include"kcb.h"

void gnxz(int num)
{
	clearviewport();
	xzjm();
	xz(num);
	
}

void xzjm()
{
	clearviewport();
	clrmous(MouseX, MouseY);
	setfillstyle(1, WHITE);
	bar(0, 0, 1023, 767);
	setfillstyle(1, LIGHTBLUE);
	bar(0, 0, 1023, 40);
	setcolor(LIGHTBLUE);
	circle(330, 250, 200);
	setfillstyle(1, LIGHTBLUE);
	floodfill(330, 250, LIGHTBLUE);
	puthz(265, 10, "功能选择", 24, 34, WHITE);

	setfillstyle(1, WHITE);
	bar(270, 150, 370, 180);
	puthz(270, 150, "课程表", 24, 34, BLACK);



	bar(270, 225, 370, 255);
	puthz(270, 225, "自习室", 24, 34, BLACK);

	bar(270, 300, 370, 330);
	puthz(270, 300, "倒计时", 24, 34, BLACK);
	
	setfillstyle(1, LIGHTGRAY);
	bar(530, 440, 636, 470);
	puthz(550, 445, "返回", 24, 34, BLACK);

}

void xz(int num)
{
	int t=0;
	while (1)
	{
		
		newmouse(&MouseX, &MouseY, &press);
		MouseS = 0;
		
		if (mouse_press(270, 150, 370, 180) == 0 && mouse_press(270, 225, 370, 255) == 0 && mouse_press(270, 300, 370, 330) == 0)
		{
			setcolor(LIGHTBLUE);
			setlinestyle(SOLID_LINE, 0, 3);
			rectangle(270, 150, 370, 180);
			rectangle(270, 225, 370, 255);
			rectangle(270, 300, 370, 330);
			rectangle(530, 440, 636, 470);
		}

		else if (mouse_press(270, 150, 370, 180) == 2)
		{
			MouseS = 1;
			setcolor(BLACK);
			setlinestyle(SOLID_LINE, 0, 3);
			rectangle(270, 150, 370, 180);
		}
		
		else if (mouse_press(270, 225, 370, 255) == 2)
		{
			MouseS = 1;
			setcolor(BLACK);
			setlinestyle(SOLID_LINE, 0, 3);
			rectangle(270, 225, 370, 255);
		}
		else if (mouse_press(270, 300, 370, 330) == 2)
		{
			MouseS = 1;
			setcolor(BLACK);
			setlinestyle(SOLID_LINE, 0, 3);
			rectangle(270, 300, 370, 330);
		}
		else if (mouse_press(530, 440, 636, 470) == 2)
		{
			MouseS = 1;
			setcolor(BLACK);
			setlinestyle(SOLID_LINE, 0, 3);
			rectangle(530, 440, 636, 470);
		}
		else if (mouse_press(270, 150, 370, 180) == 1)
		{
			delay(300);
			kcb(num);
			clearviewport();
			xzjm();
			continue;
		}
		else if (mouse_press(270, 300, 370, 330) == 1)
		{
			delay(300);
			djs(num);
			clearviewport();
			xzjm();
			continue;
			
		}
		else if (mouse_press(270, 225, 370, 255) == 1)
		{
			delay(300);
			count();
			clearviewport();
			xzjm();
			press = 0;
			continue;
		}
		
		 if (mouse_press(530, 440, 636, 470) == 1)
		{
			delay(200);
			break;
		}
		
		
	}
}



