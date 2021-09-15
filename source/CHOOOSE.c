#include<stdio.h>
#include<graphics.h>
#include<dos.h>
#include<stdlib.h>
#include"hz.h"
#include"mouse.h"
#include"count.h"
#include"choose.h" 
#define HZ_OFFSET 4


void choose(int i,int*PE,int*xuanxiu)
{
    FILE*fp,*ft;
	unsigned s;
	void *box;
	int j;
	int m=0;
	int n=0;
	int flag_pe=0;
	int flag_select=0;
	int flag_exit=0;
	int flag_sure=0;
	void *buf = NULL;
	int ispopwindow=0;
	 int logocenterx=100;
	int logocentery=100;//logo的圆心
    char c;
	cleardevice();

	setfillstyle(1, DARKGRAY);
	bar(0, 0, 640, 480);
	setfillstyle(1,WHITE);
	pieslice(320,240,0,360,210);
	setcolor(WHITE);
	moveto(320,240);
	lineto(530,240);
	setcolor(DARKGRAY);
	setlinestyle(0,0,NORM_WIDTH);
	rectangle(270,295,335,330);
	rectangle(270,385,335,420);
	rectangle(300,100,390,130);
	rectangle(300,200,390,230);
	setcolor(BLUE);
	setlinestyle(0,0,THICK_WIDTH);
	moveto(310,30);
	lineto(225,65);
	lineto(310,90);
	lineto(395,65);
	lineto(310,30);
	setfillstyle(1,BLUE);
	pieslice(225,115,0,360,30);
	pieslice(225,210,0,360,30);
	puthz(250,50,"选课系统",24,35,RED);
	puthz(200,105,"体育",24,35,WHITE);
	puthz(200,205,"选修",24,35,WHITE);
	puthz(275,300,"确定",24,35,RED);
	puthz(275,390,"退出",24,35,RED);
	setcolor(GREEN);
	setlinestyle(0,0,NORM_WIDTH);
	circle(logocenterx,logocentery,60);//外圈
	circle(logocenterx,logocentery,40);//内圈
	arc(logocenterx,logocentery,120,300,30);
	ellipse(logocenterx+15,logocentery+9,90,270,20,17);
	ellipse(logocenterx+15,logocentery-26,180,270,30,18);//小人身子
	circle(logocenterx,logocentery-22,6);//小人头
	setfillstyle(1,LIGHTGREEN);
	floodfill(logocenterx,logocentery-50,GREEN);
	floodfill(logocenterx-20,logocentery,GREEN);
	floodfill(logocenterx,logocentery-22,GREEN);
	setlinestyle(0,0,THICK_WIDTH);
	moveto(490,350);
	lineto(410,350);
	lineto(500,300);
	lineto(410,300);
	lineto(520,250); //顶点
	lineto(630,300);
	lineto(540,300);
	lineto(630,350);
	lineto(550,350);
	lineto(590,410);
	lineto(550,410);
	lineto(550,470);
	lineto(490,470);
	lineto(490,410);
	lineto(450,410);
	lineto(490,350);
	moveto(160,350);
   lineto(240,350);
   lineto(150,300);
   lineto(240,300);
   lineto(130,250); //顶点
   lineto(20,300);
   lineto(110,300);
   lineto(20,350);
   lineto(100,350);
   lineto(60,410);
   lineto(100,410);
   lineto(100,470);
   lineto(160,470);
   lineto(160,410);
   lineto(200,410);
   lineto(160,350);

	
	mouseinit();
	while (1)
	{
		newmouse(&MouseX, &MouseY, &press);
		if(0==ispopwindow)
		{
			if(mouse_press(300, 100, 390, 130) == 1)
			{
				flag_pe=1;
			}
			if(mouse_press(300,200,390,230)==1)
			{
				flag_select=1;
			}
			if(mouse_press(270,385,335,420)==1)
			{
				flag_exit=1;
			}
			
			if(mouse_press(270,295,335,330)==1)
			{
				flag_sure=1;
			}
			if( flag_pe==1)
			{
				clrmous(MouseX, MouseY);
				delay(300);
				s = imagesize(300, 130, 390, 220);
				box = malloc(s);
				getimage(300, 130, 390, 220, box);
				
				setfillstyle(1, LIGHTCYAN);
				bar(300, 130, 390, 160);
				bar(300, 160, 390, 190);
				bar(300, 190, 390, 220);
				setcolor(BLACK);
				rectangle(300, 130, 390, 160);
				rectangle(300, 160, 390, 190);
				rectangle(300, 190, 390, 220);
				puthz(315, 133, "足球", 24, 35, RED);
				puthz(315, 163, "篮球", 24, 35, RED);
				puthz(315, 193, "排球", 24, 35, RED);
				
				while(1)
				{
					newmouse(&MouseX, &MouseY, &press);
					setfillstyle(1,WHITE);
					if( mouse_press(300, 130, 390, 160)==1)
					{
						m=1;
						clrmous(MouseX, MouseY);
						putimage(300,130,box,0);
						free(box);
						bar(315,103,380,125);
						puthz(315,103,"足球",24,35,RED);
						flag_pe=0;
						break;
					}
					
					if( mouse_press(300, 160, 390, 190)==1)
					{
						m=2;
						clrmous(MouseX, MouseY);
						putimage(300,130,box,0);
						free(box);
						bar(315,103,380,125);
						puthz(315,103,"篮球",24,35,RED);
						flag_pe=0;
						break;
					}
					if(mouse_press(300, 190, 390, 220)==1)
					{
						m=3;
						clrmous(MouseX, MouseY);
						putimage(300,130,box,0);
						free(box);
						bar(315,103,380,125);
						puthz(315,103,"排球",24,35,RED);
						flag_pe=0;
						break;
					}
				}
			}
			
			if( flag_select==1)
			{
				clrmous(MouseX, MouseY);
				delay(300);
				s = imagesize(300, 230, 390, 320);
				box = malloc(s);
				getimage(300, 230, 390, 320, box);
				
				setfillstyle(1, LIGHTCYAN);
				bar(300, 230, 390, 260);
				bar(300, 260, 390, 290);
				bar(300, 290, 390, 320);
				setcolor(BLACK);
				rectangle(300, 230, 390, 260);
				rectangle(300, 260, 390, 290);
				rectangle(300, 290, 390, 320);
				puthz(315,233,"国学",24,35,RED);
				puthz(315,263,"心理",24,35,RED);
				puthz(315,293,"音乐",24,35,RED);
				
				while(1)
				{
					newmouse(&MouseX, &MouseY, &press);
					setfillstyle(1,WHITE);
					if( mouse_press(300, 230, 390, 260)==1)
					{
						n=1;
						clrmous(MouseX, MouseY);
						putimage(300,230,box,0);
						free(box);
						bar(315,203,380,225);
						puthz(315,203,"国学",24,35,RED);
						flag_select=0;
						break;
					}
					
					if( mouse_press(300, 260, 390, 290)==1)
					{
						n=2;
						clrmous(MouseX, MouseY);
						putimage(300,230,box,0);
						free(box);
						bar(315,203,380,225);
						puthz(315,203,"心理",24,35,RED);
						flag_select=0;
						break;
					}
					if(mouse_press(300, 290, 390, 320)==1)
					{
						n=3;
						clrmous(MouseX, MouseY);
						putimage(300,230,box,0);
						free(box);
						bar(315,203,380,225);
						puthz(315,203,"音乐",24,35,RED);
						flag_select=0;
						break;
					}
				}
			}
			if(flag_sure==1)
			{
				if( m!=0 && n!=0 )
				{
					popWindow_withoutFlash(&buf,&ispopwindow,"选课成功");
					flag_sure=0;
				}
				else
				{
					popWindow_withoutFlash(&buf,&ispopwindow,"未完成");
					flag_sure=0;
				}
			}
			if( flag_exit==1)
			{
				*PE=m;
				*xuanxiu=n;
				if((fp=fopen("c:\\ckeshe\\txt\\PE.txt","rt+"))==NULL)
	            {
		            printf("cannot open PE");
	            }
	            if((ft=fopen("c:\\ckeshe\\txt\\NEW.txt","wt+"))==NULL)
	            {
		            printf("cannot open new");
	            }
	            for(j=0;j<10;j++)
	            {
	            	c=fgetc(fp);
	            	if(j==2*i)
	            	{
	            		fputc(m+'0',ft);
					}
					else if(j==2*i+1)
					{
						fputc(n+'0',ft);
					}
	            	else
	            	{
	            		fputc(c,ft);
					}
				}
				fclose(fp);
				fclose(ft);
				remove("c:\\ckeshe\\txt\\PE.txt");
				rename("c:\\ckeshe\\txt\\NEW.txt","c:\\ckeshe\\txt\\PE.txt");
				delay(1000);
				return;
				//exit(1);
			}
		}
		else
			popWindow_withoutFlash(&buf,&ispopwindow,"");
	}

	delay(3000);
}
