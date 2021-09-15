#include<stdio.h>
#include<dos.h>
#include<graphics.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include"hz.h"
#include"mouse.h"
#include"tableset.h"
#include"count.h"
#define HZ_OFFSET 4

void tableset(int num)
{
	void *buf = NULL;
	int ispopwindow=0;
	int m;
	int n;
	int ch=0;
	char file[40];
	char new[40];
	FILE *fp;
	FILE *fp1;
	char temp[70]={'\0'};
	char t_info[70]={'\0'};
	char course[4]={'\0'};
	int cors;
	char start_hour[10]={'\0'};
	int shour;
	char start_minute[6]={'\0'};
	int smin;
	char end_hour[6]={'\0'};
	int ehour;
	char end_minute[6]={'\0'};
	int emin;
	char start_info[6]={'\0'};
	int sinfo;
	char end_info[6]={'\0'};
	int einfo;
	char pre_info[6]={'\0'};
	int pinfo;
	char nex_info[6]={'\0'};
	int ninfo;
	int table_location;
	int location_x1= 292;
	int location_y1= 75;
	int location_x2= 262 ;
	int location_y2= 135;
	int location_x3= 362;
	int location_y3= 135;
	int location_x4= 262;
	int location_y4= 215;
	int location_x5= 362;
	int location_y5= 215;
	int flag_course=0;
	int flag_start1=0;
	int flag_start2=0;
	int flag_end1=0;
	int flag_end2=0;
	int flag_sure=0;
	int flag_out=0;
	int logocenterx=100;
	int logocentery=100;//logo的圆心
	
	cleardevice();
	
	setfillstyle(1,DARKGRAY);
	bar(0,0,640,480);
	setfillstyle(1,WHITE);
	bar(160,50,450,270);
	setfillstyle(1,LIGHTBLUE);
	pieslice(210,85,0,360,30);
	pieslice(210,145,0,360,30);
	pieslice(210,225,0,360,30);
	setcolor(LIGHTBLUE);
	line(210,85,240,85);
	line(210,145,240,145);
	line(210,225,240,225);
	puthz(250,10,"时间设定",24,35,RED); 
	puthz(180,80,"节数",24,35,WHITE);
	puthz(180,140,"起始",24,35,WHITE); 
	puthz(335,140,"：",24,35,RED); 
	puthz(180,220,"终止",24,35,WHITE); 
	puthz(335,220,"：",24,35,RED); 
	puthz(275,300,"确定",24,35,RED);
	puthz(275,390,"退出",24,35,RED);
	setcolor(RED);
	rectangle(290,70,360,108); //节数
	rectangle(260,130,325,165); //s1
	rectangle(360,130,425,165); //s2
	rectangle(260,210,325,245); //e1
	rectangle(360,210,425,245); //e2
	rectangle(270,295,335,330);
	rectangle(270,385,335,420);
	setcolor(BLUE);
	setlinestyle(0,0,THICK_WIDTH);
    moveto(310,0);
	lineto(230,20);
	lineto(310,40);
	lineto(390,20);
	lineto(310,0);
	setcolor(GREEN);
	moveto(480,350);
   lineto(400,350);
   lineto(490,300);
   lineto(400,300);
   lineto(510,250); //顶点
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
   moveto(150,350);
   lineto(230,350);
   lineto(140,300);
   lineto(230,300);
   lineto(120,250); //顶点
   lineto(10,300);
   lineto(100,300);
   lineto(10,350);
   lineto(90,350);
   lineto(50,410);
   lineto(90,410);
   lineto(90,470);
   lineto(150,470);
   lineto(150,410);
   lineto(190,410);
   lineto(150,350);
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
	
	
	mouseinit();
	while(1)
	{
		newmouse(&MouseX, &MouseY, &press);
		if(0==ispopwindow)
		{
			
			if(1==mouse_press(290,70,360,105))
			{
				flag_course=1;
				flag_start1=0;
				flag_start2=0;
				flag_end1=0;
				flag_end2=0;
				flag_sure=0;
				flag_out=0;
			}
			if(1==mouse_press(260,130,325,165))
			{
				flag_start1=1;
				flag_course=0;
				flag_start2=0;
				flag_end1=0;
				flag_end2=0;
				flag_sure=0;
				flag_out=0;
			}
			if(1==mouse_press(360,130,425,165))
			{
				flag_start2=1;
				flag_start1=0;
				flag_course=0;
				flag_end1=0;
				flag_end2=0;
				flag_sure=0;
				flag_out=0;
			}
			if(1==mouse_press(260,210,325,245))
			{
				flag_end1=1;
				flag_course=0;
				flag_start1=0;
				flag_start2=0;
				flag_end2=0;
				flag_sure=0;
				flag_out=0;
			}
			if(1==mouse_press(360,210,425,245))
			{
				flag_end2=1;
				flag_course=0;
				flag_start1=0;
				flag_start2=0;
				flag_end1=0;
				flag_sure=0;
				flag_out=0;
			}
			if(1==mouse_press(270,295,335,330))
			{
				flag_sure=1;
				flag_course=0;
				flag_start1=0;
				flag_start2=0;
				flag_end1=0;
				flag_end2=0;
				flag_out=0;
			}
			if(1==mouse_press(270,385,335,420))
			{
				flag_out=1;
				flag_course=0;
				flag_start1=0;
				flag_start2=0;
				flag_end1=0;
				flag_end2=0;
				flag_sure=0;
			}
		
			if(1==flag_out)
			{
				break;
			}
			if(1==flag_course)
			{

				if(kbhit()!=0)
				{
					ch=getch();
					switch(ch)
					{
						case 8:
							if(strlen(course)>0)
							{
								course[strlen(course) - 1] = '\0';
								setfillstyle(SOLID_FILL,WHITE);
								location_x1 -=25;
								bar(location_x1,location_y1,location_x1+36,location_y1+28);
							}
							break;
						case 13:
							{
								flag_course=0;
								break;
							}
						default:
							if(strlen(course)<2)
							{
								course[strlen(course)]=ch;
								settextstyle(0,0,4);
								clrmous(MouseX,MouseY);
								outtextxy(295,75,course); 
								save_bk_mou(MouseX,MouseY);
								drawmous(MouseX,MouseY);
								location_x1 +=25;
							}
							break;
					}
					  
				}
			}
			if(1==flag_start1)
			{
				if(kbhit()!=0)
				{
					ch=getch();
					switch(ch)
					{
						case 8:
							if(strlen(start_hour)>0)
							{
								start_hour[strlen(start_hour) - 1] = '\0';
								setfillstyle(SOLID_FILL,WHITE);
								location_x2 -=25;
								bar(location_x2,location_y2,location_x2+36,location_y2+28);
							}
							break;
						case 13:
							{
								flag_start1=0;
								break;
							}
						default:
							if(strlen(start_hour)<2)
							{
								start_hour[strlen(start_hour)]=ch;
								settextstyle(0,0,4);
								clrmous(MouseX,MouseY);
								outtextxy(265,135,start_hour); 
								save_bk_mou(MouseX,MouseY);
								drawmous(MouseX,MouseY);
								location_x2 +=25;
							}
							break;
					}
					  
				}
			}
			if(1==flag_start2)
			{
				if(kbhit()!=0)
				{
					ch=getch();
					switch(ch)
					{
						case 8:
							if(strlen(start_minute)>0)
							{
								start_minute[strlen(start_minute) - 1] = '\0';
								setfillstyle(SOLID_FILL,WHITE);
								location_x3 -=25;
								bar(location_x3,location_y3,location_x3+36,location_y3+28);
							}
							break;
						case 13:
							{
								flag_start2=0;
								break;
							}
						default:
							if(strlen(start_minute)<2)
							{
								start_minute[strlen(start_minute)]=ch;
								settextstyle(0,0,4);
								clrmous(MouseX,MouseY);
								outtextxy(365,135,start_minute); 
								save_bk_mou(MouseX,MouseY);
								drawmous(MouseX,MouseY);
								location_x3 +=25;
							}
							break;
					}
					  
				}
			}
			if(1==flag_end1)
			{
				if(kbhit()!=0)
				{
					ch=getch();
					switch(ch)
					{
						case 8:
							if(strlen(end_hour)>0)
							{
								end_hour[strlen(end_hour) - 1] = '\0';
								setfillstyle(SOLID_FILL,WHITE);
								location_x4 -=25;
								bar(location_x4,location_y4,location_x4+36,location_y4+28);
							}
							break;
						case 13:
							{
								flag_end1=0;
								break;
							}
						default:
							if(strlen(end_hour)<2)
							{
								end_hour[strlen(end_hour)]=ch;
								settextstyle(0,0,4);
								clrmous(MouseX,MouseY);
								outtextxy(265,215,end_hour); 
								save_bk_mou(MouseX,MouseY);
								drawmous(MouseX,MouseY);
								location_x4 +=25;
							}
							break;
					}
					  
				}
			}
			if(1==flag_end2)
			{
				if(kbhit()!=0)
				{
					ch=getch();
					switch(ch)
					{
						case 8:
							if(strlen(end_minute)>0)
							{
								end_minute[strlen(end_minute) - 1] = '\0';
								setfillstyle(SOLID_FILL,WHITE);
								location_x5 -=25;
								bar(location_x5,location_y5,location_x5+36,location_y5+28);
							}
							break;
						case 13:
							{
								flag_end2=0;
								break;
							}
						default: 
							if(strlen(end_minute)<2)
							{
								end_minute[strlen(end_minute)]=ch;
								settextstyle(0,0,4);
								clrmous(MouseX,MouseY);
								outtextxy(365,215,end_minute); 
								save_bk_mou(MouseX,MouseY);
								drawmous(MouseX,MouseY);
								location_x5 +=25;
							}
							break;
					}
					  
				}
			}
			if(1==flag_sure)
			{
				cors=atoi(course);
				shour=atoi(start_hour);
				smin=atoi(start_minute);
				ehour=atoi(end_hour);
				emin=atoi(end_minute);
				if( /*(course-'0')>0 && (course-'0')<9 &&*/ (cors)<9 && (shour)<24 && (smin)<60 && (ehour)<24 && (emin)<60 )
				{
					//数据处理模块
					table_location=choose_location(course);
					modify(start_hour);
					modify(start_minute);
					modify(end_hour);
					modify(end_minute);
					
					strcpy(start_info,start_hour);
					strcat(start_info,start_minute);
					sinfo=atoi(start_info);
					strcpy(end_info,end_hour);
					strcat(end_info,end_minute);
					einfo=atoi(end_info);
					
					sprintf(file,"c:\\ckeshe\\txt\\USERT\\T%d.txt",num);
					fp=fopen(file,"rt+");
					for(m=0;m<70;m++)
					{
						temp[m]=fgetc(fp);
					}
					fclose(fp);
					for(m=table_location-4,n=0;m<(table_location+4);m++,n++)
					{
					     temp[m]=pre_info[n];
					}
					for(m=table_location+8,n=0;m<(table_location+12);m++,n++)
					{
						temp[m]=nex_info[n];
					}
					pinfo=atoi(pre_info);
					ninfo=atoi(nex_info);
					if( ((sinfo < pinfo) && pinfo!=0 ) || (( einfo>ninfo) && ninfo!=0) )
					{
						printf("%d\n",sinfo);
						printf("%d\n",pinfo);
						printf("%d\n",einfo);
						printf("%d\n",ninfo);
						popWindow_withoutFlash(&buf,&ispopwindow,"时间冲突");
						flag_sure=0;
					}
					else
					{
						strcpy(t_info,start_info);
						strcat(t_info,end_info);
						for(m=table_location,n=0;m<(table_location+8);m++,n++)
						{
							temp[m]=t_info[n];
						}
						sprintf(new,"c:\\ckeshe\\txt\\USERT\\T%d_new.txt",num);
						fp1=fopen(new,"wt+");
						for(m=0;m<70;m++)
						{
							fputc(temp[m],fp1);
						}
						fclose(fp1);
						remove(file);
						rename(new,file);
						popWindow_withoutFlash(&buf,&ispopwindow,"设定成功");
						flag_sure=0;
					}
				}
				else
				{
					popWindow_withoutFlash(&buf,&ispopwindow,"信息有误");
					flag_sure=0;
				}
			}
		}
		else
		{
			popWindow_withoutFlash(&buf,&ispopwindow, "");
		}
	}
}

void modify( char *a)
{
	int m;
	char add[6]={'0'};
	m=strlen(a);
	if(1==m)
	{
        strcat(add,a);
		strcpy(a,add);
	}
}

int choose_location(char *a)
{
	int table_location;
	table_location=8*( (*a-'0')-1 );
	return table_location;
}