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
#include"djs.h"
#include"deletkcb.h"
#include<dos.h>
#include"kcb.h"
#include"input.h"

void deletkcb(char* a, int daynum1, int classnum1, int weeknum)
{
	char mc1[100];
	char mcf1[100];
	char mc2[100];
	char mcf2[100];
	char mc3[100];
	char mcf3[100];
	int i, j = 0;
	int classnum=0;//上课节数
	int daynum=0;//星期几
	char chooseweek[19] ;
	int color,dec=1;
	int len=0;
	FILE* fp1=NULL;
	FILE* fp=NULL;
	//void* box=NULL;
	void* box1=NULL;
	unsigned x,s;
	memset(mc1, '\0', sizeof(mc1));
	memset(mc2, '\0', sizeof(mc2));
	memset(mc3, '\0', sizeof(mc3));
	memset(mcf1, '\0', sizeof(mc1));
	memset(mcf2, '\0', sizeof(mc2));
	memset(mcf3, '\0', sizeof(mc3));
	memset(chooseweek, '0', sizeof(chooseweek));
	chooseweek[18] = '\0';
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
			dec = 1;
		}
		else
		{
			dec = 0;
		}
		if (dec ==1)
		{
			drawdelet();
			hz_int(300,70, 400, 100, mc1,BLACK);
			hz_int(300, 130, 400, 160, mc2, BLACK);
			hz_int(300, 190, 400, 220, mc3, BLACK);
			break;
		}
		else
		{
		}
	}
	fclose(fp1);
	while (1)
	{
		newmouse(&MouseX, &MouseY, &press);
		if (dec == 1)
		{
			if (mouse_press(300, 245, 360, 275) == 1)
			{
				delay(300);
				if ((fp1 = fopen(a, "rt")) == NULL)
				{
					closegraph();
					printf("a error");
					getchar();
				}

				if ((fp = fopen("c:\\ckeshe\\txt\\KCBSJ\\LINSHI.txt", "wt")) == NULL)
				{
					closegraph();
					printf("filename error");
					getchar();
				}
				while (!feof(fp1))
				{
					fscanf(fp1, "%s %s %s %s %d %d %d\n", mc1/*课程名称*/, mc2/*上课地点*/, mc3/*教师姓名*/, chooseweek, &color, &daynum, &classnum);
					if ((chooseweek[weeknum - 1] == '1') && (daynum == daynum1) && (classnum == classnum1))
					{
					}
					else
					{
						fprintf(fp, "%s %s %s %s %d %d %d\n", mc1/*课程名称*/, mc2/*上课地点*/, mc3/*教师姓名*/, chooseweek, color, daynum, classnum);
					}

				}
				fclose(fp);
				fclose(fp1);
				remove(a);
				rename("c:\\ckeshe\\txt\\KCBSJ\\LINSHI.txt", a);
				break;
			}
			if (mouse_press(300, 295, 360, 325) == 1)
			{
				delay(300);
				break;
			}
		}
		else
		{
			clrmous(MouseX, MouseY);
			drawdelet();
			setfillstyle(1, WHITE);
			bar(300, 245, 360, 275);
			puthz(300, 250, "添加", 24, 25, LIGHTBLUE);
			memset(mc1, '\0', sizeof(mc1));
			memset(mc2, '\0', sizeof(mc2));
			memset(mc3, '\0', sizeof(mc3));
			while (1)
			{
				newmouse(&MouseX, &MouseY, &press);
				if (mouse_press(300, 70, 400, 95) == 1)//课程名称
				{
					memset(mc1, '\0', sizeof(mc1));
					clrmous(MouseX, MouseY);
					delay(300);
					setfillstyle(1, WHITE);
					bar(300, 70, 400, 100);
					
					len= hz_input(302, 70, 400, 100, mc1, len, WHITE);
					len = 0;

				}
				
				else if (mouse_press(300, 130, 400, 155) == 1)//上课地点
				{
					memset(mc2, '\0', sizeof(mc2));
					clrmous(MouseX, MouseY);
					delay(300);
					setfillstyle(1, WHITE);
					bar(300, 130, 400, 155);
				
					len = hz_input(302, 130, 400, 160, mc2, len, WHITE);
					len = 0;
				}
				else if (mouse_press(300, 190, 400, 215) == 1)//教师姓名
				{
					memset(mc3, '\0', sizeof(mc3));
					clrmous(MouseX, MouseY);
					delay(300);
					setfillstyle(1, WHITE);
					bar(300, 190, 400, 215);
					
					len = hz_input(302, 190, 400, 220, mc3, len, WHITE);
					len = 0;
				}
				else if (mouse_press(300, 245, 360, 275) == 1)//确定
				{
					if (mc1[0] == '\0' || mc2[0] == '\0' || mc3[0] == '\0')
					{
						puthz(300, 330, "信息不全", 16, 18, WHITE);
						delay(3000);
						setfillstyle(1, LIGHTBLUE);
						bar(300,330,370,350);

					}
					else
					{


						delay(300);
						fclose(fp);
						memset(chooseweek, '0', sizeof(chooseweek));
						chooseweek[weeknum - 1] = '1';
						if ((fp = fopen(a, "at")) == NULL)
						{
							closegraph();
							printf("a error");
							getchar();
						}
						fprintf(fp, "%s %s %s %s %d %d %d\n", mc1/*课程名称*/, mc2/*上课地点*/, mc3/*教师姓名*/, chooseweek, 7, daynum1, classnum1);
						fclose(fp);
						fp = NULL;
						fp1 = NULL;
						break;
					}
				}
				else if(mouse_press(300, 295, 360, 325)==1)//取消
				{
					delay(300);
					break;
				}
			}
			fclose(fp);
			break;
		}
		
	}
	clrmous(MouseX, MouseY);

}
void drawdelet()
{
	setfillstyle(1, LIGHTGRAY);
	bar(195, 45, 435, 355);
	setfillstyle(1, LIGHTBLUE);
	bar(200, 50, 430, 350);
	setfillstyle(1, WHITE);
	bar(300, 70, 400, 95);
	puthz(210, 72, "课程名称", 16, 17, WHITE);
	bar(300, 130, 400, 155);
	puthz(210, 132, "上课地点", 16, 17, WHITE);
	bar(300, 190, 400, 215);
	puthz(210, 192, "任课教师", 16, 17, WHITE);
	
	setfillstyle(1, WHITE);
	bar(300, 245, 360, 275);
	puthz(300, 250, "删除", 24, 25, BLACK);

	bar(300, 295, 360, 325);
	puthz(300, 300, "取消", 24, 25, BLACK);
}