#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>
#include<dos.h>
#include<conio.h>
#include<string.h>
#include"hz.h"
#include"mouse.h"
#include"count.h"
#define HZ_OFFSET 4
extern int press;
extern int flag;
extern void* buffer;

void count()
{
	long int a = 0;
	int m = 0, n = 0;

	page5(&m, &n);
	a = 3600 * m + 60 * n;
	page6(&a);
}

void page5(int* m, int* n)
{
  int changdu=0;
  int flag_hour=0;
  int flag_minute=0;
  int flag_sure=0;
  int flag_exit=0;
  int ch = 0;
  int ch2 = 0;
  char hour[4]={'\0'};
  char minute[4]={'\0'};
  int x_hour = 212;
  int y_hour = 165;
  int x_minute=212;
  int y_minute=285;
  void *buf=NULL;
  int ispopwindow=0;
  int logocenterx=100;
  int logocentery=100;
	
	clrmous(MouseX,MouseY);
	 
	cleardevice();
	setfillstyle(1,DARKGRAY);
	bar(0,0,640,480);
	setfillstyle(1,WHITE);
	pieslice(320,240,0,360,210);
	setcolor(WHITE);
	moveto(320,240);
	lineto(530,240);
	setcolor(DARKGRAY);
	rectangle(210,160,330,200);
	rectangle(210,280,330,320);
	rectangle(300,340,370,380);
	rectangle(300,390,370,430);
	puthz(245,90,"自习室",32,36,RED);
	puthz(343,170,"小时",24,30,RED);
	puthz(343,290,"分钟",24,30,RED);
	puthz(305,350,"确定",24,30,RED);
	puthz(305,400,"退出",24,30,RED);
	setlinestyle(0,0,THICK_WIDTH);
	setcolor(BLUE);
	circle(300,100,52);
	circle(375,300,31);
	circle(375,180,31);
	
	setcolor(GREEN);
	setlinestyle(0,0,NORM_WIDTH);
	circle(logocenterx,logocentery,60);
	circle(logocenterx,logocentery,40);
	arc(logocenterx,logocentery,120,300,30);
	ellipse(logocenterx+15,logocentery+9,90,270,20,17);
	ellipse(logocenterx+15,logocentery-26,180,270,30,18);
	circle(logocenterx,logocentery-22,6);
	setfillstyle(1,LIGHTGREEN);
	floodfill(logocenterx,logocentery-50,GREEN);
	floodfill(logocenterx-20,logocentery,GREEN);
	floodfill(logocenterx,logocentery-22,GREEN);
	//Tree
	setlinestyle(0,0,THICK_WIDTH);
   moveto(490,350);
   lineto(410,350);
   lineto(500,300);
   lineto(410,300);
   lineto(520,250); //Top
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
   
	save_bk_mou(MouseX,MouseY);
	drawmous(MouseX,MouseY);
   while(1)
   {
		start:
		newmouse(&MouseX,&MouseY,&press);
		if(0==ispopwindow)
		{
				
			if(1==flag_hour)
			{
			   if(kbhit()!=0)
			   {
				   ch=getch();
				   switch(ch)
				   {
					   case 8:
					   //Backspace
							if(strlen(hour)>0)
							{
							changdu=strlen(hour)-1;
							hour[changdu]='\0';
							setfillstyle(SOLID_FILL,WHITE);
							x_hour-=25;
							bar(x_hour,y_hour,x_hour+36,y_hour+30);
							}
							break;
						case 13:
						//Sure
							{
							flag_hour=0;
							break;
							}
						default:
							if(strlen(hour)<2)
							{
							changdu=strlen(hour);
							hour[changdu]=ch;
							settextstyle(0,0,4);
							outtextxy(215,165,hour);
							x_hour+=25;
							}
							break;
				   }
				  
			   }
			}
			if (1==flag_minute)
			{
				if(kbhit()!=0)
				{
					ch2=getch();
					switch(ch2)
				   {
					   case 8:
							if(strlen(minute)>0)
							{
							changdu=strlen(minute) - 1;
							minute[changdu]='\0';
							setfillstyle(SOLID_FILL,WHITE);
							x_minute-=25;
							bar(x_minute,y_minute,x_minute+36,y_minute+30);
							}
							break;
						case 13:
							{
								flag_minute=0;
								break;
							}
						default:
							if(strlen(minute)<2)
							{
							changdu=strlen(minute);
							minute[changdu]=ch2;
							settextstyle(0,0,4);
							outtextxy(215,285,minute);
							x_minute+=25;
							}
							break;
				   }
				}
			}
			if(1==flag_sure)
			{
				(*m) = atoi(hour); 
				(*n) = atoi(minute); 
				if( (*m)>=24 || (*n)>=60)
				{
					popWindow_withoutFlash(&buf,&ispopwindow,"时间错误");
					flag_sure = 0;
					goto start;
				}
				if((*m)>=6)
				{
					popWindow_withoutFlash(&buf,&ispopwindow,"时间过长");
					flag_sure= 0;
					goto start;
				}
				if( (*m)==0 && (*n)==0 )
				{
					popWindow_withoutFlash(&buf,&ispopwindow,"无信息");
					flag_sure=0;
					goto start;
				}	
				return;
			}
			if(1==flag_exit)
			{
				break;
			}
			if(mouse_press(210,160,330,200)==1)
			{
				flag_hour=1;
				flag_minute=0;
				flag_sure=0;
				flag_exit=0;
			}
			if(mouse_press(210,280,330,320)==1)
			{
				flag_minute=1;
				flag_hour=0;
				flag_sure=0;
				flag_exit=0;
			}
			if(mouse_press(300,340,370,380)==1)
			{
				flag_sure=1;
				flag_hour=0;
				flag_minute=0;
				flag_exit=0;
			}
			if(mouse_press(300,390,370,430)==1)
			{
				flag_exit=1;
				flag_minute=0;
				flag_hour=0;
				flag_sure=0;
			}
		}
		else
		{
			popWindow_withoutFlash(&buf,&ispopwindow, "");
		}
    }
}

void page6(long* temp)
{
   int b,c,d,i,j; 
   int flag_continue=1;
   int m=0,n=0;
   char text[50] = {'\0'};
   mouseinit();
   clrmous(MouseX,MouseY);
	
   cleardevice();
   setfillstyle(1, DARKGRAY);
   bar(0, 0, 640, 480);
   setfillstyle(1,WHITE);
   pieslice(320,240,0,360,210);
   setcolor(DARKGRAY);
   rectangle(280,260,360,300);
   puthz(285,265,"暂停",32,36,RED);
   rectangle(280,320,360,360);
   puthz(285,325,"退出",32,36,RED);
   puthz(265,150,"倒计时",32,36,RED);
   setcolor(GREEN);
   setlinestyle(0,0,THICK_WIDTH);
   moveto(480,350);
   lineto(400,350);
   lineto(490,300);
   lineto(400,300);
   lineto(510,250); //Right Top
   lineto(620,300);
   lineto(530,300);
   lineto(620,350);
   lineto(540,350);
   lineto(580,410);
   lineto(540,410);
   lineto(540,470);
   lineto(480,470);
   lineto(480,410);
   lineto(440,410);
   lineto(480,350);
   moveto(160,350);
   lineto(240,350);
   lineto(150,300);
   lineto(240,300);
   lineto(130,250); //Left Top
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
   
    save_bk_mou(MouseX,MouseY);
    drawmous(MouseX,MouseY);

    while((*temp)>0)
	{
		newmouse(&MouseX,&MouseY,&press);

		setcolor(WHITE);
		setfillstyle(1,WHITE);
		line(320,240,530,240);
		d=(*temp)/3600;
		b=((*temp)-d*3600)/60;
		c=(*temp)%60;
		sprintf(text,"%2d:%2d:%.2d",d,b,c);
		settextstyle(0,0,4);
		setcolor(DARKGRAY);
		outtextxy(200,200,text);
	   
	   if(flag_continue==1)
	   {

	     (*temp)=(*temp)-1;
			
		 for(m=30000;m>-5000;m--)
		 {
			 for(n=7000;n>0;n--)
			 {
				;
			 }
			 newmouse(&MouseX,&MouseY,&press);
				if(mouse_press(285,260,360,300)==1)
			  {
				  delay(100);
					setfillstyle(1,WHITE);
					bar(280,260,360,300);
					setcolor(DARKGRAY);
					rectangle(280,260,360,300);
					puthz(285,265,"继续",32,36,RED);
					flag_continue=0;
					break;
			  }
			  if(mouse_press(280,320,360,360)==1)
				  goto out;
					 
		 }
	    bar(200,200,520,250);
	   }
	   
	   newmouse(&MouseX,&MouseY,&press);
	   	if((flag_continue==0) && (mouse_press(285,260,360,300)==1))
		{
				
			delay(100);
			setfillstyle(1,WHITE);
			bar(280,260,360,300);
			setcolor(DARKGRAY);
			rectangle(280,260,360,300);
			puthz(285,265,"暂停",32,36,RED);
			flag_continue=1;
		}
		newmouse(&MouseX,&MouseY,&press);
		if(mouse_press(280,320,360,360)==1)
		{
			delay(100);
			out:
			break;
		}
	}

   puthz(270,200,"自习结束",32,36,RED);
}

void popWindow_withoutFlash(void ** buf, int * isPopWindow, char *s)
{
	int size;
	
	if((*isPopWindow) == 0)
	{
		size=imagesize(210,138,435,300);
		(*buf)=malloc(size);
		clrmous(MouseX,MouseY);
		if((*buf)!=NULL)
		{
			getimage(210,138,435,300,(*buf));
		}
		else
		{
			settextjustify(LEFT_TEXT,TOP_TEXT);          
			settextstyle(GOTHIC_FONT,HORIZ_DIR,1);					
			outtextxy(10,10,"Error!");
			delay(1000);
			exit(-1);
		}

		clrmous(MouseX,MouseY);

		setcolor(DARKGRAY);
		setfillstyle(SOLID_FILL,DARKGRAY);
		bar(210,138,435,300); // Clear behind bkground
		setcolor(DARKGRAY);
		setlinestyle(SOLID_LINE,0,NORM_WIDTH);
		rectangle(210,138,435,300);
		printHZ_withoutRec(220, 150,s,48,YELLOW);
		rectangle(232,236,414,300);
		settextstyle(DEFAULT_FONT,HORIZ_DIR,5);
		setcolor(YELLOW);
		outtextxy(285,250,"OK");
		
		save_bk_mou(MouseX,MouseY);
		drawmous(MouseX,MouseY);
		
		(*isPopWindow) = 1;
	}
	else
	{
		if(mouse_press(232,236,414,300) == 1)
		{
			clrmous(MouseX,MouseY);
			
			setfillstyle(SOLID_FILL,BLACK);
			setcolor(BLACK);
			bar(210,138,435,300); 	//Clear Popwindow

			putimage(210,138,(*buf),COPY_PUT);
			free((*buf));
			
			save_bk_mou(MouseX,MouseY);
			drawmous(MouseX,MouseY);
			
			(*buf) = NULL;
			(*isPopWindow) = 0;
			
			delay(200);
		}		
	}
	
	return;
}

void printHZ_withoutRec(int x, int y,char *s,int flag,int color)
{
	int part = flag + HZ_OFFSET;
	
	puthz(x,y,s,flag,part,color);
	
	return;
}