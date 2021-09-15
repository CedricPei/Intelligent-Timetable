#include<stdio.h>
#include<conio.h>
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
#include"kcsz.h"
#include<dos.h>

void kcsz(int num)
{
	FILE* fp=NULL;
	FILE* fp1=NULL;
	char mc1[20];
	char mcf1[20];
	char mc2[20];
	char mcf2[20];
	char mc3[20];
	char mcf3[20];
	int classnum=100;//上课节数
	int classnumf;//上课节数
	int daynum=100;//星期几
	int daynumf;//星期几
	char a[20][30];//文件名
	char butnum[3];
	int i, k, dec, t = 0, j = 0, len = 0,u=0;
	char chooseweek[19];
	char chooseweekf[19];
	int color=100;
	int colorf;
	int flag_sure = 0;

	unsigned s;
	void* box=NULL;

	memset(chooseweek, '0', sizeof(chooseweek));
	memset(chooseweekf, '0', sizeof(chooseweekf));
	memset(mc1, '\0', sizeof(mc1));
	memset(mc2, '\0', sizeof(mc2));
	memset(mc3, '\0', sizeof(mc3));
	memset(mcf1, '\0', sizeof(mcf1));
	memset(mcf2, '\0', sizeof(mcf2));
	memset(mcf3, '\0', sizeof(mcf3));
	memset(butnum, '\0', sizeof(butnum));
	memset(a, '\0', sizeof(a));
	ksjm();
	chooseweek[18] = '\0';
	chooseweekf[18] = '\0';
	for (i = 0; i < 20; i++)
	{
		
		sprintf(a[i], "c:\\ckeshe\\txt\\KCBSJ\\s%d.txt", i);
		fp = fopen("c:\\ckeshe\\txt\\KCBSJ\\fname.txt", "wt");
		//fprintf(fp,"%s\n", a[i]);
		fclose(fp);
	}
	fp = NULL;
	while (1)
	{

		newmouse(&MouseX, &MouseY, &press);
		if (mouse_press(300, 40, 390, 70) == 1)
		{
			clrmous(MouseX, MouseY);
			delay(300);
			setfillstyle(1, LIGHTCYAN);
			bar(230, 50, 400, 400);
			setfillstyle(1, 10);
			bar(260-20, 55, 260+20, 75);
			bar(260 - 20, 80, 260 + 20, 100);
			bar(315 - 20, 55, 315 + 20, 75);
			bar(370 - 20, 55, 370 + 20, 75);
			bar(370 - 20, 80, 370 + 20, 100);
			puthz(245, 60, "单周", 16, 18, BLACK);
			puthz(300, 60, "双周", 16, 18, BLACK);
			puthz(355, 60, "全选", 16, 18, BLACK);
			puthz(355, 85, "确定", 16, 18, BLACK);
			puthz(245, 85, "清空", 16, 18, BLACK);

			draw_butten();

			while (1)
			{

				newmouse(&MouseX, &MouseY, &press);
				if (mouse_press(370 - 20, 80, 370 + 20, 100) == 1)//确定
				{
					delay(300);
					clrmous(MouseX, MouseY);
					ksjm();
					
					 hz_int(270, 270, 350, 300, mc1, BLACK);
					 hz_int(270, 330, 350, 360, mc2, BLACK);
					 hz_int(270, 390, 350, 420, mc3, BLACK);
					break;
				}
				if (mouse_press(260 - 20, 80, 260 + 20, 100) == 1)//清除
				{
					delay(300);
					clrmous(MouseX, MouseY);
					draw_butten();
					memset(chooseweek, '0', sizeof(chooseweek));
					chooseweek[18] = '\0';
				}
				if (mouse_press(260 - 20, 55, 260 + 20, 75) == 1)//单周
				{
					delay(300);
					clrmous(MouseX, MouseY);
					
					draw_butten();
					setfillstyle(1, BLUE);
					for (i = 0; i < 3; i++)
					{
						for (k = 0; k < 3; k++)
						{
							floodfill(260 + 55 * i, 130 + 100 * k, RED);
						}
					}
					
					memset(chooseweek, '0', sizeof(chooseweek));
					chooseweek[18] = '\0';
					for (i = 0; i < 18; i = i + 2)
					{
						chooseweek[i] = '1';
					}
				

				}
				if (mouse_press(315 - 20, 55, 315 + 20, 75) == 1)//双周
				{
					delay(300);
					clrmous(MouseX, MouseY);
					draw_butten();

					setfillstyle(1, BLUE);
					for (i = 0; i < 3; i++)
					{
						for (k = 0; k < 3; k++)
						{
							floodfill(260 + 55 * i, 180 + 100 * k, RED);
						}
					}
					memset(chooseweek, '0', sizeof(chooseweek));
					chooseweek[18] = '\0';
					for (i = 1; i < 18; i=i+2)
					{
						chooseweek[i] = '1';
					}

				}
				if (mouse_press(370 - 20, 55, 370 + 20, 75) == 1)//全选
				{
					delay(300);
					clrmous(MouseX, MouseY);

					setfillstyle(1, BLUE);
					for (i = 0; i < 3; i++)
					{
						for (k = 0; k < 3; k++)
						{
							floodfill(260+55*i, 180+100*k, RED);
							floodfill(260 + 55 * i, 130 + 100 * k, RED);
						}
					}
					memset(chooseweek, '1', sizeof(chooseweek));
					chooseweek[18] = '\0';

				}
				if (mouse_press(260 - 7, 130 - 7, 260 + 7, 130 + 7) == 1)
				{
					chooseweek[0] = '1';
					changecolor(260,130);
				}
				if (mouse_press(260 - 7, 180 - 7, 260 + 7, 180 + 7) == 1)
				{
					chooseweek[1] = '1';
					changecolor(260, 180);
				}
				if (mouse_press(260 - 7, 230 - 7, 260 + 7, 230 + 7) == 1)
				{
					chooseweek[2] = '1';
					changecolor(260, 230);
				}
				if (mouse_press(260 - 7, 280 - 7, 260 + 7, 280 + 7) == 1)
				{
					chooseweek[3] = '1';
					changecolor(260, 280);
				}
				if (mouse_press(260 - 7, 330 - 7, 260 + 7, 330 + 7) == 1)
				{
					chooseweek[4] = '1';
					changecolor(260, 330);
				}
				if (mouse_press(260 - 7, 380 - 7, 260 + 7, 380 + 7) == 1)
				{
					chooseweek[5] = '1';
					changecolor(260, 380);
				}
				if (mouse_press(315 - 7, 130 - 7, 315 + 7, 130 + 7) == 1)
				{
					chooseweek[6] = '1';
					changecolor(315, 130);
				}
				if (mouse_press(315 - 7, 180- 7, 315 + 7, 180 + 7) == 1)
				{
					chooseweek[7] = '1';
					changecolor(315, 180);
				}
				if (mouse_press(315 - 7, 230 - 7, 315 + 7, 230 + 7) == 1)
				{
					chooseweek[8] = '1';
					changecolor(315, 230);
				}
				if (mouse_press(315 - 7, 280 - 7, 315 + 7, 280 + 7) == 1)
				{
					changecolor(315, 280);
					chooseweek[9] = '1';
				}
				if (mouse_press(315 - 7, 330 - 7, 315 + 7, 330 + 7) == 1)
				{
					changecolor(315, 330);
					chooseweek[10] = '1';
				}
				if (mouse_press(315- 7, 380 - 7, 315 + 7, 380 + 7) == 1)
				{
					changecolor(315, 380);
					chooseweek[11] = '1';
				}
				if (mouse_press(370 - 7, 130 - 7, 370 + 7, 130 + 7) == 1)
				{
					changecolor(370, 130);
					chooseweek[12] = '1';
				}
				if (mouse_press(370 - 7, 180 - 7, 370 + 7, 180 + 7) == 1)
				{
					changecolor(370, 180);
					chooseweek[13] = '1';
				}
				if (mouse_press(370 - 7, 230 - 7, 370 + 7, 230 + 7) == 1)
				{
					changecolor(370, 230);
					chooseweek[14] = '1';
				}
				if (mouse_press(370 - 7, 280 - 7, 370 + 7, 280 + 7) == 1)
				{
					changecolor(370, 280);
					chooseweek[15] = '1';
				}
				if (mouse_press(370 - 7, 330 - 7, 370 + 7, 330 + 7) == 1)
				{
					changecolor(370, 330);
					chooseweek[16] = '1';
				}
				if (mouse_press(370 - 7, 380 - 7, 370 + 7, 380 + 7) == 1)
				{
					changecolor(370, 380);
					chooseweek[17] = '1';
				}
				
				
			}

		}
		if (mouse_press(300, 100, 390, 130) == 1)//选择星期
		{
			clrmous(MouseX, MouseY);
			delay(300);
			/*
			s = imagesize(300, 130, 390, 340);
			box = malloc(s);
			getimage(300, 130, 390, 340, box);
			*/
			setfillstyle(1, WHITE);
			for (i = 0; i < 7; i++)
			{
				bar(300, 130+30*i, 390, 160+30*i);
			}
			setcolor(BLACK);
			for (i = 0; i < 7; i++)
			{
				rectangle(300, 130+30*i, 390, 160+30*i);
			}
			puthz(305, 133, "星期一", 24, 27, BLACK);
			puthz(305, 133 + 1 * 30, "星期二", 24, 27, BLACK);
			puthz(305, 133 + 2 * 30, "星期三", 24, 27, BLACK);
			puthz(305, 133 + 3 * 30, "星期四", 24, 27, BLACK);
			puthz(305, 133 + 4 * 30, "星期五", 24, 27, BLACK);
			puthz(305, 133 + 5 * 30, "星期六", 24, 27, BLACK);
			puthz(305, 133 + 6 * 30, "星期天", 24, 27, BLACK);

			while (1)
			{

				newmouse(&MouseX, &MouseY, &press);
				
				for (i = 0; i < 7; i++)
				{
					if (mouse_press(300, 130+30*i, 390, 160+30*i) == 1)
					{
						delay(300);
						clrmous(MouseX, MouseY);
						//putimage(300, 130, box, 0);
						daynum = 1+i;
						delay(300);
						//free(box);
						//box = NULL;
						ksjm();

						hz_int(270, 270, 350, 300, mc1, BLACK);
						hz_int(270, 330, 350, 360, mc2, BLACK);
						hz_int(270, 390, 350, 420, mc3, BLACK);
						u = 1;
						break;
					}
				}
				if (u == 1)
				{
					u = 0;
					break;
				}
				
				
			}
			press = 0;
		}

		 if (mouse_press(300, 150, 390, 180) == 1)//选择第几节课
		{

			clrmous(MouseX, MouseY);
			delay(300);
			/*
			s = imagesize(300, 180, 390, 340);
			box = malloc(s);
			getimage(300, 180, 390, 340, box);
			*/
			setfillstyle(1, WHITE);
			for (i = 0; i < 8; i++)
			{
				bar(300, 180+20*i, 390, 200+20*i);
			}
			
			setcolor(BLACK);
			for (i = 0; i < 8; i++)
			{
				rectangle(300, 180 + 20 * i, 390, 200 + 20 * i);
			}
			puthz(305, 183 + 0 * 20, "第一节", 16, 25, BLACK);
			puthz(305, 183 + 1 * 20, "第二节", 16, 25, BLACK);
			puthz(305, 183 + 2 * 20, "第三节", 16, 25, BLACK);
			puthz(305, 183 + 3 * 20, "第四节", 16, 25, BLACK);
			puthz(305, 183 + 4 * 20, "第五节", 16, 25, BLACK);
			puthz(305, 183 + 5 * 20, "第六节", 16, 25, BLACK);
			puthz(305, 183 + 6 * 20, "第七节", 16, 25, BLACK);
			puthz(305, 183 + 7 * 20, "第八节", 16, 25, BLACK);
			while (1)
			{

				newmouse(&MouseX, &MouseY, &press);
				for (i = 0; i < 8; i++)
				{
					if (mouse_press(300, 180+20*i, 390, 200+20*i) == 1)
					{
						delay(300);
						clrmous(MouseX, MouseY);
						//putimage(300, 180, box, 0);
						classnum = 1+i;
						//free(box);
						//box = NULL;
						ksjm();

						hz_int(270, 270, 350, 300, mc1, BLACK);
						hz_int(270, 330, 350, 360, mc2, BLACK);
						hz_int(270, 390, 350, 420, mc3, BLACK);
						u = 1;
						break;
					}
					
				}
				if (u == 1)
				{
					u = 0;
					break;
				}
			}
			press = 0;
		}

		 if (mouse_press(300, 200, 390, 230) == 1)//选择颜色
		{

			clrmous(MouseX, MouseY);
			delay(300);
			/*
			s = imagesize(300, 230, 390, 340);
			box = malloc(s);
			getimage(300, 230, 390, 340, box);
			*/
			setfillstyle(1, 11);
			bar(300, 230, 390, 250);
			setfillstyle(1, 4);
			bar(300, 250, 390, 270);
			setfillstyle(1, 10);
			bar(300, 270, 390, 290);
			setfillstyle(1, 13);
			bar(300, 290, 390, 310);
			setfillstyle(1, GREEN);
			bar(300, 310, 390, 330);

			setcolor(BLACK);
			for (i = 0; i < 5; i++)
			{
				rectangle(300, 230 + 20 * i, 390, 250 + 20 * i);
			}

			while (1)
			{

				newmouse(&MouseX, &MouseY, &press);
				if (mouse_press(300, 230, 390, 250) == 1)
				{
					delay(300);
					clrmous(MouseX, MouseY);
					color = 11;//choose_col(box, 11);
					//free(box);
					ksjm();

					hz_int(270, 270, 350, 300, mc1, BLACK);
					hz_int(270, 330, 350, 360, mc2, BLACK);
					hz_int(270, 390, 350, 420, mc3, BLACK);
					break;
				}
				if (mouse_press(300, 250, 390, 270) == 1)
				{
					delay(300);
					clrmous(MouseX, MouseY);
					color = 4;// choose_col(box, 4);
					ksjm();

					hz_int(270, 270, 350, 300, mc1, BLACK);
					hz_int(270, 330, 350, 360, mc2, BLACK);
					hz_int(270, 390, 350, 420, mc3, BLACK);
					//free(box);
					break;
				}
				if (mouse_press(300, 270, 390, 290) == 1)
				{
					delay(300);
					clrmous(MouseX, MouseY);
					color = 10;// choose_col(box, 10);
					ksjm();

					hz_int(270, 270, 350, 300, mc1, BLACK);
					hz_int(270, 330, 350, 360, mc2, BLACK);
					hz_int(270, 390, 350, 420, mc3, BLACK);
					//free(box);
					break;
				}
				if (mouse_press(300, 290, 390, 310) == 1)
				{
					delay(300);
					clrmous(MouseX, MouseY);
					color = 13;// choose_col(box, 13);
					ksjm();

					hz_int(270, 270, 350, 300, mc1, BLACK);
					hz_int(270, 330, 350, 360, mc2, BLACK);
					hz_int(270, 390, 350, 420, mc3, BLACK);
					//free(box);

					break;
				}
				if (mouse_press(300, 310, 390, 330) == 1)
				{
					delay(300);
					clrmous(MouseX, MouseY);
					color = GREEN;// choose_col(box, GREEN);
					ksjm();

					hz_int(270, 270, 350, 300, mc1, BLACK);
					hz_int(270, 330, 350, 360, mc2, BLACK);
					hz_int(270, 390, 350, 420, mc3, BLACK);
					//free(box);

					break;
				}

			}
			press = 0;
		}
		  if (mouse_press(270, 270, 350, 300) == 1)//课程名称
		{
		    memset(mc1, '\0', sizeof(mc1));
			
			clrmous(MouseX, MouseY);
			delay(300);
			setfillstyle(1, WHITE);
			bar(270, 270, 350, 300);
			rectangle(270, 270, 350, 300);

			len = hz_input(270, 270, 350, 300, mc1, len, WHITE);
			len = 0;
			press = 0;

		}
		 if (mouse_press(270, 330, 350, 360) == 1)//上课地点
		{
		memset(mc2, '\0', sizeof(mc2));

		clrmous(MouseX, MouseY);
		delay(300);
		setfillstyle(1, WHITE);
		bar(270, 330, 350, 360);
		rectangle(270, 330, 350, 360);
		     len = hz_input(270, 330, 350, 360, mc2, len, WHITE);
			 len = 0;
			 press = 0;
		}
		 if (mouse_press(270, 390, 350, 420) == 1)//教师姓名
		{
		memset(mc3, '\0', sizeof(mc3));
			
		clrmous(MouseX, MouseY);
		delay(300);
		setfillstyle(1, WHITE);
		bar(270, 390, 350, 420);
		rectangle(270, 390, 350, 420);
		len = hz_input(270, 390, 350, 420, mc3, len, WHITE);
		len = 0;
		press=0;
		}
		 if (mouse_press(510 - 30, 340 - 30, 510 + 30, 340 + 30) == 1)//确定
		{
			delay(300);
			flag_sure = 1;
		}
		else if (mouse_press(530, 440, 636, 470) == 1)
		{
		delay(300);
		break;
		}
		 if (flag_sure == 1)
		 {
			 //审查信息是否完整
			 if (mc1[0] == '\0' || mc2[0] == '\0' || mc3[0] == '\0' || (strcmp(chooseweek, chooseweekf) == 0) || color == 100 || daynum == 100 || classnum == 100)
			 {
				 puthz(400, 400, "课程信息缺失，请重新输入", 24, 27, BLACK);
				 t = 1;
			 }
			 //若信息完整审查时间是否冲突
			 if (t == 0)
			 {

				 if ((fp = fopen(a[num], "rt")) == NULL)
				 {
					 closegraph();
					 printf("a[num] error");
					 delay(1000);
					 getch();
					 exit(1);
				 }
				 while (!feof(fp))
				 {
					 fscanf(fp, "%s %s %s %s %d %d %d\n", mcf1/*课程名称*/, mcf2/*上课地点*/, mcf3/*教师姓名*/, chooseweekf, &colorf, &daynumf, &classnumf);
					 for (i = 0; i < 19; i++)
					 {
						 if ((chooseweek[i] == chooseweekf[i]) && (daynumf == daynum) && (classnumf == classnum))
						 {
							 puthz(400, 400, "课程时间冲突，请重新设置课程", 24, 27, BLACK);
							 memset(chooseweekf, '\0', sizeof(chooseweekf));
							 t = 1;
						 }
					 }
				 }

				 fclose(fp);
				 fp = NULL;
			 }
			 //若信息不完整或时间冲突则刷新界面
			 if (t == 1)
			 {
				 t = 0;
				 delay(3000);
				 ksjm();
				 hz_int(270, 270, 350, 300, mc1, BLACK);
				 hz_int(270, 330, 350, 360, mc2, BLACK);
				 hz_int(270, 390, 350, 420, mc3, BLACK);
			 }
			 else
			 {
				 delay(400);
				 t = 0;

				 if ((fp = fopen(a[num], "at")) == NULL)
				 {
					 closegraph();
					 printf("a[num] error");
					 delay(1000);
					 getch();
					 exit(1);
				 }
				 fprintf(fp, "%s %s %s %s %d %d %d\n", mc1/*课程名称*/, mc2/*上课地点*/, mc3/*教师姓名*/, chooseweek, color, daynum, classnum);
				 fclose(fp);
				 clrmous(MouseX, MouseY);
				 break;
			 }
			 flag_sure = 0;
		 }
	}


}
void ksjm()
{
	int i;
	clrmous(MouseX, MouseY);
	setfillstyle(1, WHITE);
	bar(0, 0, 1023, 767);
	setfillstyle(1, LIGHTBLUE);
	bar(0, 0, 1023, 55);

	setfillstyle(1,LIGHTBLUE);
	bar(300, 40, 390, 70);
	bar(300, 100, 390, 130);
	bar(300, 150, 390, 180);
	bar(300, 200, 390, 230);
	puthz(305, 45, "选择周数", 16, 20, WHITE);
	puthz(305, 105, "选择星期", 16, 20, WHITE);
	puthz(305, 155, "选择节数", 16, 20, WHITE);
	puthz(305, 205, "格子颜色", 16, 20, WHITE);

	setcolor(BLACK);
	setfillstyle(1, LIGHTBLUE);
	for (i = 0; i < 3; i++)
	{
		bar(140, 270+60*i, 250, 300+60*i);
	}

	setfillstyle(1, WHITE);
	for (i = 0; i < 3; i++)
	{
		bar(270, 270 + 60 * i, 350, 300 +60 * i);
		rectangle(270, 270 + 60 * i, 350, 300 + 60 * i);
	}
	setfillstyle(1, LIGHTGRAY);
	bar(530, 440, 636, 470);
	puthz(550, 445, "返回", 24, 34, BLACK);

	puthz(50, 20, "课程设置", 24, 27, WHITE);
	puthz(145, 275, "课程名称", 24, 27, WHITE);
	puthz(145, 335, "上课地点", 24, 27, WHITE);
	puthz(145, 395, "教师姓名", 24, 27, WHITE);


	setcolor(LIGHTBLUE);
	circle(510, 340, 30);
	setfillstyle(1, LIGHTBLUE);
	floodfill(510, 340, LIGHTBLUE);
	puthz(485, 325, "确定", 24, 27, WHITE);
	setcolor(BLACK);
	rectangle(300, 40, 390, 70);
	rectangle(300, 100, 390, 130);
	rectangle(300, 150, 390, 180);
	rectangle(300, 200, 390, 230);
}
void circle_but(int x,int y,char* c)
{
	setcolor(BLACK);
	settextstyle(2, 0, 4);
	outtextxy(x-1, y-20, c);
	setcolor(RED);
	circle(x, y, 7);
	setfillstyle(1, RED);
	floodfill(x, y, RED);
	setcolor(YELLOW);
	circle(x, y, 5);
	setfillstyle(1, YELLOW);
	floodfill(x, y, YELLOW);
}
void changecolor(int x, int y)
{
	clrmous(MouseX, MouseY);
	setfillstyle(1, BLUE);
	floodfill(x, y, RED);
}
void draw_butten()
{
	int dec, i, k;
	char butnum[3];
	memset(butnum, '\0', sizeof(butnum));
	dec = 1;

	for (i = 0; i < 3; i++)
	{
		for (k = 0; k < 6; k++)
		{
			itoa(dec, butnum, 10);
			circle_but(260 + 55 * i, 130 + 50 * k, butnum);
			dec++;
			memset(butnum, '\0', sizeof(butnum));
		}
	}
}
/*
int choose_col(void* box ,int colnum )
{
	putimage(300, 230, box, 0);
	delay(300);
	free(box);
	box = NULL;
	return colnum;
}
*/

