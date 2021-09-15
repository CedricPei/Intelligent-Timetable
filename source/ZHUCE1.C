#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>
#include<string.h> 
#include<time.h>
#include"mouse.h"
#include"hz.h"
#include"zhuce1.h"
#include"out.h"
#include"dos.h"

void zhuce1()
{
	FILE* fp=NULL;
	int t=0,dec=0;
	char nc[20];
	char mi[20];
	char nc1[20];
	char mi1[20];
	memset(nc, '\0', sizeof(nc));
	memset(mi, '\0', sizeof(mi));
	memset(nc1, '\0', sizeof(nc1));
	memset(mi1, '\0', sizeof(mi1));
	hjm();
	while (1)
	{
		newmouse(&MouseX, &MouseY, &press);
		MouseS = 0;
		if (mouse_press(270, 150, 400, 180) == 0 && mouse_press(270, 200, 400, 230) == 0&&mouse_press(270, 250, 350, 280) == 0)
		{
			setcolor(LIGHTBLUE);
			setlinestyle(SOLID_LINE, 0, 3);
			rectangle(270, 150, 400, 180);
			rectangle(270, 200, 400, 230);
			rectangle(270, 250, 350, 280);
		}
		if (mouse_press(270, 150, 400, 180) == 2 )
		{
			setcolor(BLACK);
		    setlinestyle(SOLID_LINE, 0, 3);
		    rectangle(270, 150, 400, 180);
			MouseS = 2;
		}
		if (mouse_press(270, 200, 400, 230) == 2)
		{
			setcolor(BLACK);
			setlinestyle(SOLID_LINE, 0, 3);
			rectangle(270, 200, 400, 230);
			MouseS = 2;
		}
		else if (mouse_press(270, 150, 400, 180) == 1)
		{
			delay(300);
			setfillstyle(1, WHITE);
			bar(270, 150, 400, 180);
			clrmous(MouseX, MouseY);
			memset(nc, '\0', sizeof(nc));
			shuru1(275, 150, nc, 0,400,180);

		}
		else if (mouse_press(270, 200, 400, 230) == 1)
		{
			delay(300);
			setfillstyle(1, WHITE);
			bar(270, 200, 400, 230);
			clrmous(MouseX, MouseY);
			memset(mi, '\0', sizeof(mi));
			shuru1(275, 200, mi, 1,400,230);

		}
		if (mouse_press(270, 250, 350, 280) == 2|| mouse_press(530, 440, 636, 470) == 1)
		{
			MouseS = 1;
			
			setcolor(RED);
			setlinestyle(SOLID_LINE, 0, 3);
			rectangle(270, 250, 350, 280);
			
		}
		else if (mouse_press(270, 250, 350, 280) == 1)
		{
			delay(300);
			
				if (nc[0] == '\0' || mi[0] == '\0')
				{
					puthz(270, 400, "信息不全", 24, 34, BLACK);
					delay(3000);
					setfillstyle(1, WHITE);
					bar(270, 400, 430, 425);
					continue;
				}
				else
				{
					if ((fp = fopen("c:\\ckeshe\\txt\\dlxx.txt", "at+")) == NULL)
					{
						closegraph();
						delay(1000);
						printf("dlxx.txt error");
						getch();
						exit(1);
					}
					while (!feof(fp))
					{
						fscanf(fp, "%s %s\n", nc1, mi1);
						if ((strcmp(nc, nc1) == 0) && (strcmp(mi, mi1) == 0))
						{
							puthz(230, 400, "昵称密码重复请重新输入", 16, 20, BLACK);
							delay(2500);
							hjm();

							dec = 1;
							break;
						}
						else
						{
							dec == 0;
						}
					}
					if (dec == 0)
					{
						fprintf(fp, "%s %s\n", nc, mi);
						fclose(fp);
						fp = NULL;
						clrmous(MouseX, MouseY);
						break;
					}
					else
					{
						fclose(fp);
						fp = NULL;
						dec = 0;
						memset(nc1, '\0', sizeof(nc1));
						memset(mi1, '\0', sizeof(mi1));
					}
				}
		}
		if (mouse_press(530, 440, 636, 470) == 1)
		{
			delay(300);
			break;
		}

	}
	return;
	
}

void hjm()
{
	clrmous(MouseX, MouseY);
	clearviewport();
	setfillstyle(1, WHITE);
	bar(0, 0, 1023, 767);
	setfillstyle(1, LIGHTBLUE);
	bar(0, 0, 1023, 40);
	puthz(282, 0, "注册", 32, 34, WHITE);

	bar(200, 150, 260, 180);
	puthz(200, 150, "昵称", 24, 34, WHITE);

	bar(200, 200, 260, 230);
	puthz(200, 200, "密码", 24, 34, WHITE);

	bar(270, 250, 350, 280);
	puthz(270, 255, "确定", 24, 34, WHITE);

	setfillstyle(1, LIGHTGRAY);
	bar(530, 440, 636, 470);
	puthz(550, 445, "返回", 24, 34, BLACK);

	setfillstyle(1, WHITE);//画框 
	bar(270, 150, 400, 180);
	bar(270, 200, 400, 230);

	setcolor(LIGHTBLUE);
	setlinestyle(SOLID_LINE, 0, 3);
	rectangle(270, 150, 400, 180);
	rectangle(270, 200, 400, 230);
	rectangle(270, 250, 350, 280);

	setcolor(BLUE);
	rectangle(200, 150, 260, 180);
	rectangle(200, 200, 260, 230);
	rectangle(270, 250, 350, 280);
}


