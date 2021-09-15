#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>
#include<string.h> 
#include<time.h>
#include"mouse.h"
#include"hz.h"
#include"stu.h"
#include"kcb.h"
#include"KCSZ.h"
#include"dos.h"
#include"deletkcb.h"
#include"input.h"
#include"TABLESET.h"

void kcb(int num)
{
	FILE* fp=NULL;
	FILE* fp1 = NULL;
	FILE* fp2 = NULL;
	char mc1[20];
	char mcf1[20];
	char mc2[20];
	char mcf2[20];
	char mc3[20];
	char mcf3[20];
	int classnum;//上课节数
	int daynum;//星期几
	char chooseweek[19] = { 0 };
	int color;
	char a[20][30] = { 0 };
	char b[20][30] = { 0 };
	char c[71];
	unsigned x;
	void* box=NULL;
	char weeknum1[3] = { 0 };
	int i=0,j=0,t=0,k=0;
	int weeknum = 1;
	memset(c, '0', sizeof(c));
	c[70] = '\0';
	clearviewport();
	draw2();
	for (i = 0; i < 20; i++)
	{
		sprintf(a[i], "c:\\ckeshe\\txt\\KCBSJ\\s%d.txt", i);
	    sprintf(b[i], "c:\\ckeshe\\txt\\USERT\\T%d.txt", i);
		/*
		if ((fp2= fopen(b[i], "wt+")) == NULL)
		{
			closegraph();
			printf("USER_T error");
			getch();
			exit(1);
		}
		fprintf(fp2,"%s", c);
		fclose(fp2);
		fp2 = NULL;
		*/
	}

	while (1)
	{
		newmouse(&MouseX, &MouseY, &press);
		color = WHITE;
		daynum = 0;
		classnum = 0;
		if (mouse_press(590 - 10, 25 - 10, 590 + 10, 25 + 10) == 1)
		{
			delay(300);
			kcsz(num);
			press = 0;
			t = 0;
			draw2();
		}
		if (t == 0)
		{
			clearviewport();
			draw2();
			setcolor(WHITE);
			circle(74,32 ,20);
			setfillstyle(1, WHITE);
			floodfill(70,35, WHITE);
			setcolor(BLACK);
			if (weeknum > 18)
			{
				weeknum = 18;
			}
			else if (weeknum <=0)
			{
				weeknum =1;
			}
			itoa(weeknum, weeknum1, 10);
			if (weeknum <= 9)
			{
				settextstyle(2, 0, 10);
				outtextxy(63, 8, weeknum1);
			}
			else
			{
				settextstyle(2, 0, 10);
				outtextxy(53, 8, weeknum1);
			}
			//puthz(64, 8, "7", 32, 40, WHITE);
			memset(mc1, '\0', sizeof(mc1));
			memset(mc2, '\0', sizeof(mc2));
			memset(mc3, '\0', sizeof(mc3));
			if((fp1 = fopen(a[num], "rt"))==NULL)
			{
				closegraph();
				printf("a[num] error");
				delay(1000);
				getch();
				exit(1);

			}
			while (!feof(fp1))
			{
				fscanf(fp1, "%s %s %s %s %d %d %d\n", mc1/*课程名称*/, mc2/*上课地点*/, mc3/*教师姓名*/, chooseweek,&color, &daynum,&classnum);
				if (daynum == 0)
				{
				}
				else
				{
					if (chooseweek[weeknum - 1] == '1')
					{
						
						setfillstyle(1, color);
						bar(40 + 70 * daynum, 103 + 33 * classnum, 40 + 70 * daynum + 70, 103 + 33 * classnum + 33);
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
						hz_int(42+ 70 * daynum, 103 + 33 * classnum, 145 + 70 * daynum, 150 + 33 * classnum, mc1, BLACK);
						draw_time(num);
						
						
					}
				}
				continue;
			}

			fclose(fp1);
			t++;
		}

		if (mouse_press(5, 20,15,52) == 1)
		{
			delay(300);
			weeknum--;
			t = 0;

		}
		else if (mouse_press(137, 20, 147, 52) == 1)
		{
			delay(300);
			weeknum++;
			t = 0;

		}
		else if (mouse_press(30, 60, 120, 90) == 1)
		{
			delay(300);
			clrmous(MouseX, MouseY);
			weeknum=butten_choose();
			clrmous(MouseX, MouseY);
			t = 0;
			
		}
		else if (mouse_press(40 + 1 * 70, 136, 600, 400) == 1)
		{
		delay(300);
		for (i = 0; 40 + (i + 1) * 70 < MouseX; i++)
		{
		}
		for (j = 0; 136 + j * 33 < MouseY; j++)
		{
		}
		deletkcb(a[num], i, j, weeknum);
		t = 0;
		continue;
		}
		else if (mouse_press(530, 440, 636, 470) == 1)
		{
		delay(300);
		break;
		}
		else if (mouse_press(40, 100, 110, 136) == 1)
		{
		delay(300);
		clrmous(MouseX, MouseY);
		tableset(num);
		t = 0;
		continue;
		}
		if (mouse_press(520 - 20, 25 - 15, 520 + 15, 25 + 20) == 1)
		{
			delay(300);
			clrmous(MouseX, MouseY);
			search_class(num,a[num]);
			press = 0;
			t = 0;
		}
	}
	delay(300);
	
}

void draw2()
{
	int i;
	clrmous(MouseX, MouseY);
	clearviewport();

	setfillstyle(1,WHITE);
	bar(0, 0, 1023, 767);
	setfillstyle(1, LIGHTBLUE);
	bar(0, 0, 1023, 55);
	setfillstyle(1, LIGHTBLUE);//画表填充
	bar(35, 95, 605, 405);

	setfillstyle(1, WHITE);//画表填充
	bar(40, 100, 600, 400);
	
	setfillstyle(1, LIGHTBLUE);//画选项
	

	
	setcolor(LIGHTBLUE);
	circle(290, 55+380, 5);
	circle(360, 55 + 380, 5);
	setfillstyle(1, LIGHTBLUE);
	floodfill(286, 55 + 380, LIGHTBLUE);
	floodfill(362, 55 + 380, LIGHTBLUE);
	

	puthz(40, 106, "设置时间", 16, 17, BLUE);

	bar(45, 60, 105, 90);
	setcolor(LIGHTBLUE);
	circle(45,75,15);
	circle(105, 75, 15);
	setfillstyle(1, LIGHTBLUE);
	floodfill(42, 75, LIGHTBLUE);
	floodfill(107,75, LIGHTBLUE);
	puthz(40, 65, "选择周数", 16, 20, WHITE);

	setfillstyle(1, LIGHTGRAY);
	bar(530, 440, 636, 470);
	puthz(550, 445, "返回", 24, 34, BLACK);

	setcolor(BLACK);//画表
	rectangle(40, 100, 600, 400);
	for (i = 0; i < 8; i++)
	{
		line(40, 136 + i* 33, 600, 136 + i* 33);
	}
	for (i = 1; i < 8; i++)
	{
		line(40+i*70, 100, 40 + i* 70, 400);
	}
	
	puthz(40 + 1 * 70 + 25, 100 + 16, "一", 16, 20, BLACK);
	puthz(40 + 2 * 70 + 25, 100 + 16, "二", 16, 20, BLACK);
	puthz(40 + 3 * 70 + 25, 100 + 16, "三", 16, 20, BLACK);
	puthz(40 + 4 * 70 + 25, 100 + 16, "四", 16, 20, BLACK);
	puthz(40 + 5 * 70 + 25, 100 + 16, "五", 16, 20, BLACK);
	puthz(40 + 6 * 70 + 25, 100 + 16, "六", 16, 20, BLACK);
	puthz(40 + 7 * 70 + 25, 100 + 16, "日", 16, 20, BLACK);

	puthz(20, 14, "第", 32, 40,WHITE);
	puthz(100, 14, "周", 32, 40, WHITE);

	setcolor(WHITE);
	line(5, 30, 15, 14);
	line(5, 30, 15, 46);
	line(15, 14, 15, 46);
	line(147, 30, 137, 14);
	line(147, 30, 137, 46);
	line(137, 14, 137, 46);

	setfillstyle(1, WHITE);
	floodfill(6, 30, WHITE);
	floodfill(146, 30, WHITE);

	draw_search(520, 25);
	draw_plus(590, 25);

	setcolor(BLACK);
	settextstyle(2, 0, 7);
	outtextxy(70, 134 , "1");
	outtextxy(70, 134 + 1 * 33, "2");
	outtextxy(70, 134 + 2 * 33, "3");
	outtextxy(70, 134 + 3 * 33, "4");
	outtextxy(70, 134 + 4 * 33, "5");
	outtextxy(70, 134 + 5 * 33, "6");
	outtextxy(70, 134 + 6 * 33, "7");
	outtextxy(70, 134 + 7 * 33, "8");

}

void draw_search(int x, int y)
{
	setcolor(WHITE);
	circle(x, y, 12);
	setfillstyle(1, WHITE);
	floodfill(x, y, WHITE);
	setcolor(LIGHTBLUE);
	circle(x, y, 10);
	setfillstyle(1, LIGHTBLUE);
	floodfill(x, y, LIGHTBLUE);
	
	setcolor(WHITE);
	line(x - 8, y +8,x-20,y+20);

}
void draw_plus(int x, int y)
{
	setfillstyle(1, WHITE);
	bar(x - 10, y - 2, x + 10, y + 2);
	bar(x -2, y -10, x +2, y +10);
}
void draw_time(int num)
{
	FILE* fp=NULL;
	char file[30];
	char temp[70];
	char timeshow[33][3];
	char renum[33][3];
	char putnum[9][20];
	int  tempnum[33];
	int m,i,j;
	memset(file, '\0', sizeof(file));
	memset(renum, '\0', sizeof(renum));
	memset(temp, '\0', sizeof(temp));
	memset(timeshow, '\0', sizeof(timeshow));
	memset(tempnum, '\0', sizeof(tempnum));
	memset(putnum, '\0', sizeof(putnum));
	sprintf(file, "c:\\ckeshe\\txt\\USERT\\T%d.txt", num);
	fp = fopen(file, "rt+");
	for (m = 0; m < 70; m++)
	{
		temp[m] = fgetc(fp);
	}
	fclose(fp);
	m = 0;

	for (i = 0; i < 32; i++)
	{
		for (j = 0; j < 2; j++)
		{
			timeshow[i][j] = temp[m];
			m++;
		}
	}

	for (i = 0; i < 32; i++)
	{
		tempnum[i]=atoi(timeshow[i]);
		itoa(tempnum[i], renum[i], 10);
	}
	for (i = 0; i < 8; i++)
	{
		sprintf(putnum[i], "%s:%s-%s:%s", renum[4*i], timeshow[4*i+1], renum[4*i+2], timeshow[4*i+3]);
	}
	setcolor(BLACK);
	settextstyle(2, 0, 4);
	for (i = 0; i < 8; i++)
	{
		outtextxy(50, 136 + 20 + i * 33, putnum[i]);
	}
	
}
void search_class(int num,char*a)
{
	int weeknum=0;
	int classnum=0;
	int daynum=0;
	int i,t=0;
	unsigned s;
	void* box;
	draw_sc();

	while (1)
	{
		newmouse(&MouseX, &MouseY, &press);
		if (mouse_press(140+275, 340 - 3 * 60,480,370-60*3) == 1)//点击选择周数
		{
			delay(300);
			clrmous(MouseX, MouseY);
			weeknum = butten_choose();
			press = 0;
		}
		else if (mouse_press(415, 340 - 2* 60, 480, 370 - 60 * 2) == 1)
		{
			clrmous(MouseX, MouseY);
			delay(300);
			s = imagesize(402, 370 - 60 * 2, 492, 370 - 60 * 2+210);
			box = malloc(s);
			getimage(402, 370 - 60 * 2, 492, 370 - 60 * 2 + 210, box);
			setfillstyle(1, WHITE);
			for (i = 0; i < 7; i++)
			{
				bar(402, 370 - 60 * 2 + 30 * i, 492, 400 - 60 * 2 + 30 * i);
			}
			setcolor(BLACK);
			for (i = 0; i < 7; i++)
			{
				rectangle(402, 370 - 60 * 2 + 30 * i, 492, 400 - 60 * 2 + 30 * i);
			}
			puthz(402, 253, "星期一", 24, 27, BLACK);
			puthz(402, 253 + 1 * 30, "星期二", 24, 27, BLACK);
			puthz(402, 253 + 2 * 30, "星期三", 24, 27, BLACK);
			puthz(402, 253 + 3 * 30, "星期四", 24, 27, BLACK);
			puthz(402, 253 + 4 * 30, "星期五", 24, 27, BLACK);
			puthz(402, 253 + 5 * 30, "星期六", 24, 27, BLACK);
			puthz(402, 253 + 6 * 30, "星期天", 24, 27, BLACK);

			while (1)
			{

				newmouse(&MouseX, &MouseY, &press);
				for (i = 0; i < 7; i++)
				{
					if (mouse_press(402, 370 - 60 * 2 + 30 * i, 492, 400 - 60 * 2 + 30 * i) == 1)
					{
						delay(300);
						clrmous(MouseX, MouseY);
						putimage(402, 370 - 60 * 2, box, 0);
						daynum = i+1;
						delay(300);
						free(box);
						box = NULL;
						t = 1;
						break;
					}
				}
				if (t == 1)
				{
					t = 0;
					break;
				}
				
			}
			press = 0;
		}
		 if (mouse_press(140 + 275, 340 - 1 * 60, 480, 370 - 60 * 1) == 1)
		{
			
			 
			clrmous(MouseX, MouseY);
			delay(300);
			s = imagesize(402, 370 - 60 * 1, 492, 370 - 60 * 1 + 160);
			box = malloc(s);
			getimage(402, 370 - 60 * 1, 492, 370 - 60 * 1 + 160, box);
			//402, 370 - 60 * 2, 492, 370 - 60 * 2 + 160
			setfillstyle(1, WHITE);
			for (i = 0; i < 8; i++)
			{
				bar(402, 310 + 20 * i, 492, 330 + 20 * i);
			}

			setcolor(BLACK);
			for (i = 0; i < 8; i++)
			{
				rectangle(402, 310 + 20 * i, 492, 330 + 20 * i);
			}
			puthz(402, 310 + 0 * 20, "第一节", 16, 25, BLACK);
			puthz(402, 310 + 1 * 20, "第二节", 16, 25, BLACK);
			puthz(402, 310 + 2 * 20, "第三节", 16, 25, BLACK);
			puthz(402, 310 + 3 * 20, "第四节", 16, 25, BLACK);
			puthz(402, 310 + 4 * 20, "第五节", 16, 25, BLACK);
			puthz(402, 310 + 5 * 20, "第六节", 16, 25, BLACK);
			puthz(402, 310 + 6 * 20, "第七节", 16, 25, BLACK);
			puthz(402, 310 + 7 * 20, "第八节", 16, 25, BLACK);
			while (1)
			{

				newmouse(&MouseX, &MouseY, &press);
				for (i = 0; i < 8; i++)
				{
					if (mouse_press(402, 310 + 20 * i, 492, 330 + 20 * i) == 1)
					{
						delay(300);
						clrmous(MouseX, MouseY);
						putimage(402, 310, box, 0);
						classnum = 1 + i;
						free(box);
						box = NULL;
						t = 1;
						break;
					}
				}
				if (t == 1)
				{
					t = 0;
					break;

				}

			}
			press = 0;
		}
		 if (mouse_press(140 + 275, 340 , 480, 370 ) == 1)
		{
			 delay(300);
		     if (weeknum == 0 || daynum == 0 || classnum == 0)
		     {
				 puthz(140 + 273, 380, "信息缺失", 24, 25, WHITE);
				 delay(3000);
				 draw_sc();
		     }
			 else
			 {
				 show_inform(a, daynum, classnum, weeknum);
			 }
			 press = 0;
		}
		 else if (mouse_press(530, 440, 636, 470) == 1)
		 {
			 delay(300);
			 break;
		 }
	}

}
void draw_sc()
{
	int i;
	setfillstyle(1, WHITE);
	bar(0, 0, 1023, 767);
	setfillstyle(1, LIGHTBLUE);
	bar(0, 0, 1023, 55);

	setcolor(LIGHTBLUE);
	circle(170, 360, 100);
	setfillstyle(1, LIGHTBLUE);
	floodfill(170, 360, LIGHTBLUE);
	circle(170, 170, 100);
	setfillstyle(1, LIGHTBLUE);
	floodfill(170, 170, LIGHTBLUE);
	bar(170 - 100, 170, 170 + 100, 360);

	setcolor(LIGHTBLUE);
	circle(450, 360, 100);
	setfillstyle(1, LIGHTBLUE);
	floodfill(450, 360, LIGHTBLUE);
	circle(450, 170, 100);
	setfillstyle(1, LIGHTBLUE);
	floodfill(450, 170, LIGHTBLUE);
	bar(450 - 100, 170, 450 + 100, 360);

	puthz(265, 10, "课程查询", 24, 34, WHITE);
	puthz(110, 120, "课程信息", 24, 34, WHITE);
	puthz(390, 120, "课程时间", 24, 34, WHITE);
	
	setfillstyle(1, WHITE);
	pieslice(110, 235, 0, 360, 15);
	pieslice(230, 235, -180, 180, 15);
	pieslice(110, 295, 0, 360, 15);
	pieslice(230, 295, -180, 180, 15);
	setcolor(WHITE);
	circle(230, 235, 15);
	floodfill(240, 235, WHITE);
	circle(230, 295, 15);
	floodfill(240, 295, WHITE);
	circle(110, 175, 15);
	floodfill(100, 175, WHITE);
	circle(230, 175, 15);
	floodfill(240, 175, WHITE);

	circle(140, 355, 15);
	floodfill(130, 355, WHITE);
	circle(200, 355, 15);
	floodfill(210, 355, WHITE);
	circle(140+280, 355, 15);
	floodfill(130+280, 355, WHITE);
	circle(200+280, 355, 15);
	floodfill(210+280, 355, WHITE);
	

	setfillstyle(1, WHITE);
	
	bar(170 - 60, 160, 170 + 60, 190);
	bar(170 - 60, 220, 170 + 60, 250);
	bar(170 - 60, 280, 170 + 60, 310);
	bar(170 - 30+280, 340, 170 + 30+280, 370);

	for (i = 0; i < 4; i++)
	{
		circle(140 + 280, 355-60*i, 15);
		floodfill(130 + 280, 355-60*i, WHITE);
		circle(200 + 280, 355-60*i, 15);
		floodfill(210 + 280, 355-60*i, WHITE);
		bar(170 - 30 + 280, 340-60*i, 170 + 30 + 280, 370-60*i);
	}

	
	puthz(140+283, 340, "查询", 24, 25, BLACK);
	puthz(140 + 283, 340-1*60, "节数", 24, 20, BLACK);
	puthz(140 + 283, 340-2*60, "星期", 24, 20, BLACK);
	puthz(140 + 283, 340-3*60, "周数", 24, 20, BLACK);
	

	setfillstyle(1, LIGHTGRAY);
	bar(530, 440, 636, 470);
	puthz(550, 445, "返回", 24, 34, BLACK);
}

int butten_choose()
{
	unsigned x;
	void* box2;
	int weeknum;
	x = imagesize(230, 50, 400, 400);
	box2 = malloc(x);
	getimage(230, 50, 400, 400, box2);
	clrmous(MouseX, MouseY);
	setfillstyle(1, LIGHTGRAY);
	bar(230, 50, 400, 400);
	setfillstyle(1, LIGHTBLUE);
	bar(235, 55, 395, 395);
	puthz(275, 65, "选择周数", 24, 20,WHITE );
	draw_butten();
	while (1)
	{

		newmouse(&MouseX, &MouseY, &press);
		if (mouse_press(260 - 7, 130 - 7, 260 + 7, 130 + 7) == 1)
		{
			delay(300);
			weeknum = 1;
			break;
		}
		if (mouse_press(260 - 7, 180 - 7, 260 + 7, 180 + 7) == 1)
		{
			delay(300);
			weeknum = 2;
			break;
		}
		if (mouse_press(260 - 7, 230 - 7, 260 + 7, 230 + 7) == 1)
		{
			delay(300);
			weeknum = 3;

			break;
		}
		if (mouse_press(260 - 7, 280 - 7, 260 + 7, 280 + 7) == 1)
		{
			delay(300);
			weeknum = 4;

			break;
		}
		if (mouse_press(260 - 7, 330 - 7, 260 + 7, 330 + 7) == 1)
		{
			delay(300);
			weeknum = 5;

			break;
		}
		if (mouse_press(260 - 7, 380 - 7, 260 + 7, 380 + 7) == 1)
		{
			delay(300);
			weeknum = 6;

			break;
		}
		if (mouse_press(315 - 7, 130 - 7, 315 + 7, 130 + 7) == 1)
		{
			delay(300);
			weeknum = 7;

			break;
		}
		if (mouse_press(315 - 7, 180 - 7, 315 + 7, 180 + 7) == 1)
		{
			delay(300);
			weeknum = 8;

			break;
		}
		if (mouse_press(315 - 7, 230 - 7, 315 + 7, 230 + 7) == 1)
		{
			delay(300);
			weeknum = 9;

			break;
		}
		if (mouse_press(315 - 7, 280 - 7, 315 + 7, 280 + 7) == 1)
		{
			delay(300);
			weeknum = 10;


			break;
		}
		if (mouse_press(315 - 7, 330 - 7, 315 + 7, 330 + 7) == 1)
		{
			delay(300);
			weeknum = 11;

			break;
		}
		if (mouse_press(315 - 7, 380 - 7, 315 + 7, 380 + 7) == 1)
		{
			delay(300);
			weeknum = 12;

			break;
		}
		if (mouse_press(370 - 7, 130 - 7, 370 + 7, 130 + 7) == 1)
		{
			delay(300);
			weeknum = 13;

			break;
		}
		if (mouse_press(370 - 7, 180 - 7, 370 + 7, 180 + 7) == 1)
		{
			delay(300);
			weeknum = 14;

			break;
		}
		if (mouse_press(370 - 7, 230 - 7, 370 + 7, 230 + 7) == 1)
		{
			delay(300);
			weeknum = 15;

			break;
		}
		if (mouse_press(370 - 7, 280 - 7, 370 + 7, 280 + 7) == 1)
		{
			delay(300);
			weeknum = 16;

			break;
		}
		if (mouse_press(370 - 7, 330 - 7, 370 + 7, 330 + 7) == 1)
		{
			delay(300);
			weeknum = 17;
			break;
		}
		if (mouse_press(370 - 7, 380 - 7, 370 + 7, 380 + 7) == 1)
		{
			delay(300);
			weeknum = 18;
			break;
		}
	}
	putimage(230, 50, box2,0);
	free(box2);
	box2 = NULL;
	save_bk_mou(MouseX, MouseY);
	drawmous(MouseX, MouseY);
	//clrmous(MouseX, MouseY);
	return weeknum;
}

void show_inform(char*a, int daynum1, int classnum1, int weeknum)
{
	char mc1[100];
	char mc2[100];
	char mc3[100];
	int dec = 0;
	int classnum = 0;//上课节数
	int daynum = 0;//星期几
	char chooseweek[19] = { 0 };
	int color;
	FILE* fp1 = NULL;
	memset(mc1, '\0', sizeof(mc1));
	memset(mc2, '\0', sizeof(mc2));
	memset(mc3, '\0', sizeof(mc3));
	clrmous(MouseX, MouseY);
	delay(300);

	if ((fp1 = fopen(a, "rt")) == NULL)
	{
		closegraph();
		printf("a error");
		getchar();
	}
	while (!feof(fp1))
	{
		fscanf(fp1, "%s %s %s %s %d %d %d\n", mc1/*课程名称*/, mc2/*上课地点*/, mc3/*教师姓名*/, chooseweek, &color, &daynum, &classnum);
		if ((chooseweek[weeknum - 1] == '1') && (daynum == daynum1) && (classnum == classnum1))
		{
			bar(170 - 60, 160, 170 + 60, 190);
			bar(170 - 60, 220, 170 + 60, 250);
			bar(170 - 60, 280, 170 + 60, 310);
			puthz(170 - 65, 160, "课程：", 24, 25, BLACK);
			puthz(170 - 65, 220, "教师：", 24, 25, BLACK);
			puthz(170 - 65, 280, "地点：", 24, 25, BLACK);
			hz_int(165, 156, 300, 190, mc1, BLACK);
			hz_int(165, 216, 300, 250, mc2, BLACK);
			hz_int(165, 276, 300, 310, mc3, BLACK);
			dec = 0;
			break;
		}
		else
		{
			dec = 1;
			
		}
	}
	fclose(fp1);
	fp1 == NULL;
	if (dec == 1)
	{
		puthz(140 + 263, 380, "未查到课程", 24, 25, WHITE);
		delay(3000);
		draw_sc();
	}
		
}