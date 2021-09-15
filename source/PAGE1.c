#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>
#include"mouse.h"
#include"hz.h"
#include"page1.h"

//extern int choose;
void firstpage(int *choose)
{ 
	//setbkcolor(LIGHTCYAN);

	clrmous(MouseX,MouseY);
	setcolor(LIGHTCYAN);
	setfillstyle(1,LIGHTCYAN);
	bar(0,0,1023,767);
	puthz(163,120,"智能课程表",32,64,BLACK);
	puthz(160,117,"智能课程表",32,64,RED);
	setfillstyle(1,WHITE);
	btn_tc();
	btn_stu();
	//btn_game();
	btn_exit();
	lightbtn(choose);
	return;
}

void btn_stu(void)
{
	bar(238,180,378,215);
	puthz(245,186,"学生端",24,50,BLACK);
	bar(238,240,378,275);
	puthz(245,246,"校外端",24,50,BLACK);
}

void btn_tc(void)
{
	bar(238,300,378,335);
	puthz(245,306,"教务处",24,50,BLACK);
}
/*void btn_game()
{
	bar(238, 360, 378, 395);
	puthz(245, 366, "小游戏", 24, 50, BLACK);
}*/

void btn_exit()
{
	bar(530,440,636,480);
	puthz(560,448,"退出",24,24,BLACK);
}

void lightbtn(int *c)
{
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
		if(mouse_press(238,180,378,215)==2)
		{
			setcolor(RED);
			moveto(238,180);
			lineto(238,215);
			lineto(378,215);
			lineto(378,180);
			lineto(238,180);
		}
		
		else if(mouse_press(238,180,378,215)==0&&mouse_press(238,300,378,335)!=2)
		{
			setcolor(WHITE);
			moveto(238,180);
			lineto(238,215);
			lineto(378,215);
			lineto(378,180);
			lineto(238,180);
		}
		
		else if(mouse_press(238,180,378,215)==1)
		{
			*c=2;
			break;
		}
		
		if(mouse_press(238,300,378,335)==2)
		{
			setcolor(RED);
			moveto(238,300);
			lineto(238,335);
			lineto(378,335);
			lineto(378,300);
			lineto(238,300);
		}
		
		else if(mouse_press(238,300,378,335)==0&&mouse_press(238,180,378,215)!=2)
		{
			setcolor(WHITE);
			moveto(238,300);
			lineto(238,335);
			lineto(378,335);
			lineto(378,300);
			lineto(238,300);
		}
		
		else if(mouse_press(238,300,378,335)==1)
		{
			*c=1;
			break; 
		}
		
		if(mouse_press(530,440,636,480)==2)
		{
			setcolor(RED);
			moveto(530,440);
			lineto(636,440);
			lineto(636,480);
			lineto(530,480);
			lineto(530,440);
		}
		
		else if(mouse_press(530,440,636,480)==0)
		{
			setcolor(WHITE);
			moveto(530,440);
			lineto(636,440);
			lineto(636,480);
			lineto(530,480);
			lineto(530,440);
		}
		
		else if(mouse_press(530,440,636,480)==1)
		{
			*c=5;
			break;
		}
		
		if(mouse_press(238,240,378,275)==2)
		{
			setcolor(RED);
			moveto(238,240);
			lineto(378,240);
			lineto(378,275);
			lineto(238,275);
			lineto(238,240);
		}
		
		else if(mouse_press(238,240,378,275)==0)
		{
			setcolor(WHITE);
			moveto(238,240);
			lineto(378,240);
			lineto(378,275);
			lineto(238,275);
			lineto(238,240);
		}
		
		else if(mouse_press(238,240,378,275)==1)
		{
			*c=3;
			break;
		}

		/*if (mouse_press(238, 360, 378, 395) == 2)
		{
			setcolor(RED);
			moveto(238, 360);
			lineto(378, 360);
			lineto(378, 395);
			lineto(238, 395);
			lineto(238, 360);
		}

		else if(mouse_press(238, 360, 378, 395) == 0)
		{
			setcolor(WHITE);
			moveto(238, 360);
			lineto(378, 360);
			lineto(378, 395);
			lineto(238, 395);
			lineto(238, 360);
		}

		else if (mouse_press(238, 360, 378, 395) == 1)
		{
			*c = 4;
			break;
		}*/
	}
}
