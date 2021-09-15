#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>
#include<string.h> 
#include<time.h>
#include"mouse.h"
#include"hz.h"
#include"out.h"
#include"djs.h"
#include<stdio.h>
#include<string.h>
#include<dos.h>
#include"GNXZ.h"
#include"input.h"



//倒计时功能主体
void djs(int num)//num为登陆序号
{
	FILE* fp=NULL;
	int i;
	int change=1,k,t = 0;//延时工具t
	char line;
	char a[20][30] ;//文件名
	char c;//序号
	char mc[100] ;
	char year1[20];
	char mon1[20];
	char day1[20];
	char bnum;
	memset(a, '\0', sizeof(a));
	memset(mc, '\0', sizeof(mc));
	memset(year1, '\0', sizeof(year1));
	memset(mon1, '\0', sizeof(mon1));
	memset(day1, '\0', sizeof(day1));
	k = '0';
	
	for (i = 0; i < 20; i++)
	{
		sprintf(a[i], "c:\\ckeshe\\txt\\DJSSJ\\s%d.txt", i);
		//fp = fopen("c:\\ckeshe\\DJSSJ\\fname.txt", "at");
		//fprintf(fp, a[i]);
		//fprintf(fp, "\n");
			//fclose(fp);
			//fp = NULL;
	}
	clearviewport();
	while (1)
	{
		newmouse(&MouseX, &MouseY, &press);
		//t为更新界面辅助变量
		t++;
		if (t % 8000== 0)
		{
			setfillstyle(1, LIGHTBLUE);
			bar(500, 40,530 , 70);
			time2();
		}
		if (t % 10000 == 0)
		{
			setfillstyle(1, LIGHTBLUE);
			bar(440, 40, 470, 70);
			time2();
		}
		if (t % 20000 == 0)
		{
			setfillstyle(1, LIGHTBLUE);
			bar(380, 40, 410, 70);
			bar(320, 40, 350, 70);
			bar(170, 40, 220, 70);
			t = 0;
			time2();
		}
		if (change == 0)
		{
		}
		else
		{
			hjm2();
			bnum = '0';
			memset(mc, k, sizeof(mc));
			memset(year1, k, sizeof(year1));
			memset(mon1, k, sizeof(mon1));
			memset(day1, k, sizeof(day1));

			if ((fp = fopen(a[num], "rt+")) == NULL)
			{
				closegraph();
				printf("a[num] error");
				getch();
			}
			if (feof(fp) == 0)
			{
				fscanf(fp, "%c %s %s %s %s\n", &bnum, mc, year1, mon1, day1);//不能读取导致直接保存原始结果
				xstime(bnum, mc, year1, mon1, day1);
				if (feof(fp) == 0)
				{
					fscanf(fp, "%c %s %s %s %s\n", &bnum, mc, year1, mon1, day1);
					xstime(bnum, mc, year1, mon1, day1);
					if (feof(fp) == 0)
					{
						fscanf(fp, "%c %s %s %s %s\n", &bnum, mc, year1, mon1, day1);
						xstime(bnum, mc, year1, mon1, day1);
						if (feof(fp) == 0)
						{
							fscanf(fp, "%c %s %s %s %s\n", &bnum, mc, year1, mon1, day1);
							xstime(bnum, mc, year1, mon1, day1);
						}

					}
				}
			}

			fclose(fp);
			fp = NULL;
			change = 0;
		}
		if (mouse_press(550, 100, 610, 140) == 1)//第一个选择按钮
		{
			delay(300);
			sz('1', a,num);
			clearviewport();
			hjm2();
			change = 1;	
			continue;
		}
		else if (mouse_press(550, 180, 610, 220) == 1)//第二个选择按钮
		{
			delay(300);
			sz('2', a, num);
			clearviewport();
			hjm2();
			change = 1;
			continue;
			
		}	
		else if (mouse_press(550, 260, 610, 300) == 1)//第三个选择按钮
		{
			delay(300);
			
			sz('3', a, num);
			clearviewport();
			hjm2();
			change = 1;
			continue;
			
		}
		else if (mouse_press(550, 340, 610, 380) == 1)//第四个选择按钮
		{
			delay(300);
			sz('4', a, num);
			clearviewport();
			hjm2();
			change = 1;
			continue;
		}

		if (mouse_press(525 - 10, 120 - 10, 525 + 10, 120 + 10) == 1)//删除第一条
		{
			delay(300);	
			clickdel('1',num,a);	
			change = 1;
		}
		else if (mouse_press(525 - 10, 200 - 10, 525 + 10, 200 + 10) == 1)//删除第二条
		{
			delay(300);
			clickdel('2',num, a);
			change = 1;
		}
		else if (mouse_press(525 - 10, 280 - 10, 525 + 10, 280 + 10) == 1)//删除第三条
		{
			delay(300);
			clickdel('3',num, a);
			change = 1;
		}
		else if (mouse_press(525 - 10, 360 - 10, 525 + 10, 360 + 10) == 1)//删除第四条
		{
			delay(300);
			clickdel('4',num, a);
			change = 1;
		}
		if(mouse_press(530, 440, 636, 470) == 1)//返回
		{
			delay(300);
			clearviewport;
			break;
		}
		//将输入信息写入文件
		
	}
//sz(line, a, num);
}
//********************************************************
//画倒计时主页面
void hjm2()
{
	clrmous(MouseX, MouseY);
	clearviewport();
	setfillstyle(1, WHITE);
	bar(0, 0, 1023, 767);
	setfillstyle(1, LIGHTBLUE);
	bar(0, 0, 1023, 80);
    puthz(270, 10, "倒计时", 32, 40, WHITE);
	puthz(10, 50, "现在时间：",24, 34, WHITE);

	setfillstyle(1,WHITE );
	bar(40, 100, 500, 140);
	bar(40, 180, 500, 220);
	bar(40, 260, 500, 300);
	bar(40, 340, 500, 380);

	setcolor(BLACK);
	rectangle(40, 100, 500, 140);
	rectangle(40, 180, 500, 220);
	rectangle(40, 260, 500, 300);
	rectangle(40, 340, 500, 380);
	rectangle(40, 100, 100, 140);
	rectangle(40, 180, 100, 220);
	rectangle(40, 260, 100, 300);
	rectangle(40, 340, 100, 380);

	settextstyle(2, 0, 10);
	outtextxy(45, 100, "1");
	outtextxy(45, 180, "2");
	outtextxy(45, 260, "3");
	outtextxy(45, 340, "4");

	setfillstyle(1, LIGHTBLUE);
	bar(550, 100, 610, 140);
	bar(550, 180, 610, 220);
	bar(550, 260, 610, 300);
	bar(550, 340, 610, 380);
	puthz(550, 105, "编辑", 24, 34, WHITE);
	puthz(550, 185, "编辑", 24, 34, WHITE);
	puthz(550, 265, "编辑", 24, 34, WHITE);
	puthz(550, 345, "编辑", 24, 34, WHITE);

	setfillstyle(1, LIGHTGRAY);
	bar(530, 440, 636, 470);
	puthz(550, 445, "返回", 24, 34, BLACK);

	deletbutton(525, 120);
	deletbutton(525, 200);
	deletbutton(525, 280);
	deletbutton(525, 360);

}
//获取时间并实现实时更新现在时间
void time2()
{
	char year[10];
	char mday[3];
	char week[3];
	char mon[3];
	char hour[3];
	char min[3];
	char sec[3];
	time_t timep;
	struct tm* p=NULL;
	time(&timep);
	p = localtime(&timep);
	memset(year, '\0', sizeof(year));
	memset(mday, '\0', sizeof(mday));
	memset(week, '\0', sizeof(week));
	memset(mon, '\0', sizeof(mon));
	memset(hour, '\0', sizeof(hour));
	memset(min, '\0', sizeof(min));
	memset(sec, '\0', sizeof(sec));


	//printf("%d\n", p->tm_sec); /*获取当前秒*/
	//printf("%d\n", p->tm_min); /*获取当前分*/
	//printf("%d\n", 8 + p->tm_hour);/*获取当前时,这里获取西方的时间,刚好相差八个小时*/
	//printf("%d\n", p->tm_mday);/*获取当前月份日数,范围是1-31*/
	//printf("%d\n", 1 + p->tm_mon);/*获取当前月份,范围是0-11,所以要加1*/
	//printf("%d\n", 1900 + p->tm_year);/*获取当前年份,从1900开始，所以要加1900*/
	//printf("%d\n", p->tm_yday); /*从今年1月1日算起至今的天数，范围为0-365*/

	/*
	itoa(1 + p->tm_mon, mon,10);
	setcolor(BLACK);
	settextstyle(2, 0, 8);
	outtextxy(40 ,136,mon );
	*/
	
	p->tm_year = p->tm_year + 1900;
	itoa(p->tm_year, year, 10);
	setcolor(WHITE);
	settextstyle(2, 0, 8);
	outtextxy(170, 47, year);

	puthz(230, 50, "年", 24, 34, WHITE);
	
	itoa(1 + p->tm_mon, mon, 10);
	setcolor(WHITE);
	settextstyle(2, 0, 8);
	outtextxy(260, 47, mon);

	puthz(290, 50, "月", 24, 34, WHITE);

	itoa(p->tm_mday, mday, 10);
	setcolor (WHITE);
	settextstyle(2, 0, 8);
	outtextxy(320, 47, mday);

	puthz(350, 50, "日", 24, 34, WHITE);

	itoa(p->tm_hour, hour, 10);
	setcolor(WHITE);
	settextstyle(2, 0, 8);
	outtextxy(380, 47, hour);

	puthz(410, 50, "时", 24, 34, WHITE);

	itoa(p->tm_min, min, 10);
	setcolor(WHITE);
	settextstyle(2, 0, 8);
	outtextxy(440, 47, min);

	puthz(470, 50, "分", 24, 34, WHITE);

	itoa(p->tm_sec, sec, 10);
	setcolor(WHITE);
	settextstyle(2, 0, 8);
	outtextxy(500, 47, sec);

	puthz(530, 50, "秒", 24, 34, WHITE);
	
}

//画倒计时的第二个界面——————设置界面
void szjm()
{
	clrmous(MouseX, MouseY);
	clearviewport();
	setfillstyle(1, WHITE);
	bar(0, 0, 1023, 767);
	setfillstyle(1, LIGHTBLUE);
	bar(0, 0, 1023, 70);

	setfillstyle(1, LIGHTBLUE);
	bar(150, 150, 230, 180);
	puthz(150, 155, "名称", 24, 34, WHITE);

	bar(150, 300, 230, 330);
	puthz(150, 305, "时间", 24, 34, WHITE);

	bar(350, 380, 410, 410);
	puthz(350, 385, "确定", 24, 34, WHITE);
	puthz(260, 20, "设置倒计时", 24, 34, WHITE);

	setfillstyle(1, WHITE);
	bar(270, 150, 350, 180);
	bar(270, 300, 330, 330);
	bar(360, 300, 390, 330);
	bar(420, 300, 450, 330);

	puthz(335, 305, "年", 24, 34, LIGHTBLUE);
	puthz(395, 305, "月", 24, 34, LIGHTBLUE);
	puthz(455, 305, "日", 24, 34, LIGHTBLUE);

	setcolor(BLACK);
	rectangle(270, 150, 350, 180);
	rectangle(270, 300, 330, 330);
	rectangle(360, 300, 390, 330);
	rectangle(420, 300, 450, 330);

	setfillstyle(1, LIGHTGRAY);
	bar(530, 440, 636, 470);
	puthz(550, 445, "返回", 24, 34, BLACK);

}

//第二个界面主功能：设置倒计时
void sz(char bnum,char a[][30],int num)
{
	FILE* fp = NULL;
	FILE* fp1 = NULL;
	
	char c;//序号
	char mc[100] ;
	char year1[20] ;
	char mon1[20] ;
	char day1[20] ;
	char mcf[100] ;
	char year1f[20] ;
	char mon1f[20] ;
	char day1f[20] ;
	int i,j,k,row=0;
	int mon,day,leap_year = 0;
	char numcf[2];
	int len = 0;
	time_t timep;
	struct tm* p=NULL;
	p = localtime(&timep);
	time(&timep);
	memset(mc, '\0', sizeof(mc));
	memset(year1, '\0', sizeof(year1));
	memset(mon1, '\0', sizeof(mon1));
	memset(day1, '\0', sizeof(day1));
	memset(year1f, '\0', sizeof(year1));
	memset(mon1f, '\0', sizeof(mon1));
	memset(day1f, '\0', sizeof(day1));
	memset(mcf, '\0', sizeof(mcf));
	memset(numcf, '\0', sizeof(numcf));

	szjm();
	while (1)
	{
		MouseS = 0;
		newmouse(&MouseX, &MouseY, &press);
		if (mouse_press(270, 150, 450, 180) == 2 || mouse_press(270, 300, 450, 330) == 2)//光标变形
		{
			MouseS = 2;
		}
		else if (mouse_press(270, 150, 350, 180) == 1)//输入倒计时名称
		{
			delay(300);
			memset(mc, '\0', sizeof(mc));
			clrmous(MouseX, MouseY);
			setfillstyle(1, WHITE);
			bar(270, 150, 350, 180);
			rectangle(270, 150, 350, 180);
			len = hz_input(270, 150, 350, 180, mc, len, WHITE);
			len = 0;

		}
		else if (mouse_press(270, 300, 330, 330) == 1)//输入年份
		{
			delay(300);
			memset(year1, '\0', sizeof(year1));
			clrmous(MouseX, MouseY);
			setfillstyle(1, WHITE);
			bar(270, 300, 330, 330);
			rectangle(270, 300, 330, 330);
			shuru1(275, 303, year1, 0,315,330);
			
		}
		else if (mouse_press(360, 300, 390, 330) == 1)//输入月份
		{
			delay(300);
			memset(mon1, '\0', sizeof(mon1));
			clrmous(MouseX, MouseY);
			setfillstyle(1, WHITE);
			bar(360, 300, 390, 330);
			rectangle(360, 300, 390, 330);
			shuru1(365, 303, mon1, 0,380,330);
		}
		else if (mouse_press(420, 300, 450, 330) == 1)//输入天
		{
			delay(300);
			memset(day1, '\0', sizeof(day1));
			clrmous(MouseX, MouseY);
			setfillstyle(1, WHITE);
			bar(420, 300, 450, 330);
			rectangle(420, 300, 450, 330);
			shuru1(425, 303, day1, 0,440,330);
		}
		else if (mouse_press(350, 380, 410, 410) == 1)
		{
			if (mc[0] == '\0' || year1 == '\0' || mon1 == '\0' || day1 == '\0')
			{
				puthz(180, 450, "信息缺失", 24, 34, BLACK);
				delay(3000);
				setfillstyle(1, WHITE);
				bar(180, 450, 350, 480);
			}
			else
			{
				delay(400);
				//判断是否为闰年
				mon = atoi(mon1);
				day = atoi(day1);
				if (atoi(year1) % 4 == 0)
				{
					if (atoi(year1) % 100 == 0)
					{
						if (atoi(year1) % 400 == 0)
						{
							leap_year = 1;
						}
						else
						{
							leap_year = 0;
						}
					}

					else
					{
						leap_year = 1;
					}
				}
				else
				{
					leap_year = 0;
				}


				//如果是平年
				if (daycha(year1, mon1, day1) >= 0 && leap_year == 0 && ((mon == 1 && day <= 31) || (mon == 2 && day <= 28) || (mon == 3 && day <= 31) || (mon == 4 && day <= 30) || (mon == 5 && day <= 31) || (mon == 6 && day <= 30) || (mon == 7 && day <= 31) || (mon == 8 && day <= 31) || (mon == 9 && day <= 30) || (mon == 10 && day <= 31) || (mon == 11 && day <= 30) || (mon == 12 && day <= 31)))
				{

					if ((fp1 = fopen("c:\\ckeshe\\txt\\DJSSJ\\linshi.txt", "wt+")) == NULL)
					{
						closegraph();
						printf("c:\\ckeshe\\txt\\DJSSJ\\linshi.txt error");
						getchar();
					}

					if ((fp = fopen(a[num], "rt")) == NULL)
					{
						closegraph();
						printf("a[num] error");
						getchar();
					}


					while (!feof(fp))
					{
						fscanf(fp, "%c %s %s %s %s\n", &c, mcf, year1f, mon1f, day1f);

						if (c != bnum && c >= '0' && c <= '9')
						{
							fprintf(fp1, "%c %s %s %s %s\n", c, mcf, year1f, mon1f, day1f);
						}

					}


					fclose(fp);
					fclose(fp1);
					remove(a[num]);
					rename("c:\\ckeshe\\txt\\DJSSJ\\linshi.txt", a[num]);

					if ((fp = fopen(a[num], "at")) == NULL)

					{
						closegraph();
						printf("a[num] error");
						getchar();
					}

					fprintf(fp, "%c %s %s %s %s\n", bnum, mc, year1, mon1, day1);
					fclose(fp);

					break;
				}
				//如果是闰年
				else if (daycha(year1, mon1, day1) >= 0 && leap_year == 1 && ((mon == 1 && day <= 31) || (mon == 2 && day <= 29) || (mon == 3 && day <= 31) || (mon == 4 && day <= 30) || (mon == 5 && day <= 31) || (mon == 6 && day <= 30) || (mon == 7 && day <= 31) || (mon == 8 && day <= 31) || (mon == 9 && day <= 30) || (mon == 10 && day <= 31) || (mon == 11 && day <= 30) || (mon == 12 && day <= 31)))

				{
					
					if ((fp1 = fopen("c:\\ckeshe\\txt\\DJSSJ\\linshi.txt", "wt+")) == NULL)
					{
						closegraph();
						printf("c:\\ckeshe\\txt\\DJSSJ\\linshi.txt error");
						getchar();
					}
					if ((fp = fopen(a[num], "rt")) == NULL)
					{
						closegraph();
						printf("a[num] error");
						getchar();
					}

					while (!feof(fp))
					{
						fscanf(fp, "%c %s %s %s %s\n", &c, mcf, year1f, mon1f, day1f);

						if (c != bnum && c >= '0' && c <= '9')
						{
							fprintf(fp1, "%c %s %s %s %s\n", c, mcf, year1f, mon1f, day1f);
						}

					}


					fclose(fp);
					fclose(fp1);
					remove(a[num]);
					rename("c:\\ckeshe\\txt\\DJSSJ\\linshi.txt", a[num]);

					if ((fp = fopen(a[num], "at")) == NULL)
					{
						closegraph();
						printf("a[num] error");
						getchar();
					}
					fprintf(fp, "%c %s %s %s %s\n", bnum, mc, year1, mon1, day1);
					fclose(fp);

					break;
				}
				else
				{
					puthz(180, 450, "输入错误，请重新输入", 24, 34, BLACK);
					delay(3000);
					szjm();
					memset(mc, '\0', sizeof(mc));
					memset(year1, '\0', sizeof(year1));
					memset(mon1, '\0', sizeof(mon1));
					memset(day1, '\0', sizeof(day1));
					memset(mcf, '\0', sizeof(mcf));
					memset(year1f, '\0', sizeof(year1f));
					memset(mc, '\0', sizeof(mc));
					memset(mcf, '\0', sizeof(mcf));

				}
			}
		}
	 if(mouse_press(530, 440, 636, 470) == 1)
		{
			delay(300);
			break;
		}
	}
	
}






//计算这一年已经过的天数
int day_js(int year, int month, int day)
{
	int sum = 0;
	switch (month)
	{
	case 1:sum = day;
		break;
	case 2:sum = 31 + day;
		break;
	case 3:sum = 59 + day;
		break;
	case 4:sum = 90 + day;
		break;
	case 5:sum = 120 + day;
		break;
	case 6:sum = 151 + day;
		break;
	case 7:sum = 181 + day;
		break;
	case 8:sum = 212 + day;
		break;
	case 9:sum = 243 + day;
		break;
	case 10:sum = 273 + day;
		break;
	case 11:sum = 304 + day;
		break;
	case 12:sum = 334 + day;
		break;
	default:
		break;
	}
	if (month > 2)
	{
		if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400) == 0) {
			sum = sum + 1;
		}
	}
	return sum;
}
//年与年相差的天数
int year_daycha(int year1,int year2)
{
	int sum_year_day = 0;
	int i = 0;
	sum_year_day = (year2 - year1) * 365;
	for (i = year1; i < year2; i++)
	{
		if (((i % 4 == 0) && (i % 100 != 0)) || (i % 400) == 0) {
			sum_year_day = sum_year_day + 1;
		}
	}
	return sum_year_day;
}
int daycha(char* year,char* month,char* day)
{
	int year2;
	int month2;
	int day2;
	int day_cha = 0;
	time_t timep;
	struct tm* p=NULL;
	time(&timep);
	p = localtime(&timep);


	//printf("%d\n", p->tm_sec); /*获取当前秒*/
	//printf("%d\n", p->tm_min); /*获取当前分*/
	//printf("%d\n", 8 + p->tm_hour);/*获取当前时,这里获取西方的时间,刚好相差八个小时*/
	//printf("%d\n", p->tm_mday);/*获取当前月份日数,范围是1-31*/
	//printf("%d\n", 1 + p->tm_mon);/*获取当前月份,范围是0-11,所以要加1*/
	//printf("%d\n", 1900 + p->tm_year);/*获取当前年份,从1900开始，所以要加1900*/
	//printf("%d\n", p->tm_yday); /*从今年1月1日算起至今的天数，范围为0-365*/
	year2 = atoi(year);
	month2 = atoi(month);
	day2 = atoi(day);


	day_cha = year_daycha(1900+p->tm_year, year2)-day_js(1900+p->tm_year,p->tm_mon+1,p->tm_mday)+day_js(year2, month2, day2);
	return day_cha;
	
}

void xstime(char c,char*mc,char*year1,char*mon1,char*day1)
{
	int i;
	char dayc1[4] ;
	char dayc2[4] ;
	char dayc3[4] ;
	char dayc4[4] ;
	memset(dayc1, '\0', sizeof(dayc1));
	memset(dayc2, '\0', sizeof(dayc2));
	memset(dayc3, '\0', sizeof(dayc3));
	memset(dayc4, '\0', sizeof(dayc4));

	if (c == '1')
	{
		//chat_use(180, 110, 500, 140, mc, 16);
		hz_int(180, 104, 500, 140, mc, BLACK);
		i = daycha(year1, mon1, day1);
		itoa(i, dayc1, 10);
		setcolor(BLACK);
		settextstyle(2, 0, 6);
		outtextxy(300, 107, dayc1);
		puthz(100, 110, "今天距离", 16, 20, BLACK);
		puthz(260, 110, "还有", 16, 20, BLACK);
		puthz(390, 110, "天", 16, 20, BLACK);
	}
	else if (c == '2')
	{
		//chat_use(180, 190, 500, 220, mc, 16);
		hz_int(180, 184, 500, 220, mc, BLACK);
		i = daycha(year1, mon1, day1);
		itoa(i, dayc2, 10);
		setcolor(BLACK);
		settextstyle(2, 0, 6);
		outtextxy(300, 187, dayc2);
		puthz(100, 190, "今天距离", 16, 20, BLACK);
		puthz(260, 190, "还有", 16, 20, BLACK);
		puthz(390, 190, "天", 16, 20, BLACK);
	}
	else if (c == '3')
	{
		//chat_use(180, 270, 500, 300, mc, 16);
		hz_int(180, 264, 500, 300, mc, BLACK);
		i = daycha(year1, mon1, day1);
		itoa(i, dayc3, 10);
		setcolor(BLACK);
		settextstyle(2, 0, 6);
		outtextxy(300, 267, dayc3);
		puthz(100, 270, "今天距离", 16, 20, BLACK);
		puthz(260, 270, "还有", 16, 20, BLACK);
		puthz(390, 270, "天", 16, 20, BLACK);
	}
	else if (c == '4')
	{
		//chat_use(180, 350, 500, 380, mc, 16);
		hz_int(180, 344, 500, 380, mc, BLACK);
		i = daycha(year1, mon1, day1);
		itoa(i, dayc4, 10);
		setcolor(BLACK);
		settextstyle(2, 0, 6);
		outtextxy(300, 347, dayc4);
		puthz(100, 350, "今天距离", 16, 20, BLACK);
		puthz(260, 350, "还有", 16, 20, BLACK);
		puthz(390, 350, "天", 16, 20, BLACK);
	}
}

void deletbutton(int x,int y)
{
	setcolor(LIGHTBLUE);
	circle(x, y, 10);
	
	setcolor(RED);
	circle(x, y, 8);
	setfillstyle(1, RED);
	floodfill(x, y + 9,LIGHTBLUE);
	
	setcolor(WHITE);
	line(x - 4, y - 4, x + 4, y + 4);
	line(x - 4, y + 4, x + 4, y - 4);
	setcolor(RED);

}

void clickdel(char n,int num,char a[][30])
{
	FILE* fp2 = NULL;
	FILE* fp3 = NULL;
	char mcf[100] ;
	char year1f[20];
	char mon1f[20] ;
	char day1f[20] ;
	char c ;
	int i;
	memset(mcf, '\0', sizeof(mcf));
	memset(year1f, '\0', sizeof(year1f));
	memset(mon1f, '\0', sizeof(mon1f));
	memset(day1f, '\0', sizeof(day1f));
	//画删除框
	setfillstyle(1, YELLOW);
	bar(185, 205, 475, 295);
	setfillstyle(1,LIGHTCYAN);
	bar(190, 210, 470, 290);
	setfillstyle(1, YELLOW);
	bar(230, 270, 280, 285);
	bar(320, 270, 370, 285);
	puthz(195, 220, "删除后无法恢复，是否确认删除？",16,17,BLACK);
	puthz(235, 270, "确定", 16, 17, RED);
	puthz(325, 270, "取消", 16, 17, RED);
	while (1)
	{
		newmouse(&MouseX, &MouseY, &press);
		if (mouse_press(320, 270, 370, 285) == 1)//点击取消删除
		{
			delay(300);
			clearviewport;
			break;
		}
		else if (mouse_press(230, 270, 280, 285) == 1)//点击删除
		{
			delay(300);
			
			if ((fp2 = fopen("c:\\ckeshe\\txt\\DJSSJ\\linshi.txt", "wt")) == NULL)
			{
				closegraph();
				printf("linshi error");
				getchar();
			}
			if ((fp3 = fopen(a[num], "rt")) == NULL)
			{
				closegraph();
				delay(1000);
				printf("pf3 error");
				getch();
				exit(1);
			}
			//puthz(400, 270, "坏", 16, 17, RED);
			while (!feof(fp3))
			{
				//fprintf(fp1, "hello");
				fscanf(fp3, "%c %s %s %s %s\n", &c, mcf, year1f, mon1f, day1f);
				//printf("111");
				if (c != n&& c >= '0' && c <= '9')
				{
				       //	puthz(300, 300, "确定", 16, 17, RED);
					fprintf(fp2, "%c %s %s %s %s\n", c, mcf, year1f, mon1f, day1f);
				}


			}
			fclose(fp2);
			fclose(fp3);
			fp2 = NULL;
			fp3 = NULL;
			remove(a[num]);
			rename("c:\\ckeshe\\txt\\DJSSJ\\linshi.txt", a[num]);
			break;
		}
	}
	
}