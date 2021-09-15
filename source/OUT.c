#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>
#include<string.h> 
#include<time.h>
#include"mouse.h"
#include"hz.h"
#include"out.h"
#include"zhuce1.h"
#include"GNXZ.h"
#include"dos.h"

void outmode(OUTU*o)
{
	int i, num = 0;
	int k = 0;
	char nc1[20];
	char mi1[20];
	FILE* filep = NULL;
	delay(300);
	draw1();
	memset(nc1, '\0', sizeof(nc1));
	memset(mi1, '\0', sizeof(mi1));
	while (1)
	{
		newmouse(&MouseX, &MouseY, &press);
		MouseS = 0;
		if (mouse_press(270, 150, 400, 180) == 2 || mouse_press(270, 200, 400, 230) == 2)
		{
			MouseS = 2;
		}
		else if (mouse_press(270, 150, 400, 180) == 1)
		{
			delay(200);
			setfillstyle(1, WHITE);
			bar(270, 150, 400, 180);
			memset(nc1, '\0', sizeof(nc1));
			shuru1(270, 153, nc1, 0,400,180);
		}
		else if (mouse_press(270, 200, 400, 230) == 1)
		{
			delay(200);
			memset(mi1, '\0', sizeof(mi1));
			setfillstyle(1, WHITE);
			bar(270, 200, 400, 230);
			shuru1(270, 203, mi1, 1,400,230);
		}
		if (mouse_press(270, 250, 350, 280) == 2 || mouse_press(270, 320, 350, 350) == 2 || mouse_press(530, 440, 636, 470) == 2)
		{
			MouseS = 1;
		}
		else if (mouse_press(270, 250, 350, 280) == 1)
		{
			delay(300);
			zhuce1();
			clearviewport();
			draw1();

		}
		else if (mouse_press(270, 320, 350, 350) == 1)
		{

			delay(300);
			if (nc1[0] == '\0' || mi1[0] == '\0')
			{
				puthz(270, 400, "ÐÅÏ¢²»È«", 24, 34, BLACK);
				delay(3000);
				setfillstyle(1, LIGHTBLUE);
				bar(270, 400, 430, 425);
				continue;
			}
			else
			{
				if ((filep = fopen("c:\\ckeshe\\txt\\dlxx.txt", "rt")) == NULL)
				{
					printf("error");
					closegraph();
					delay(2000);
					exit(1);
				}
				for (i = 0; i < 20; i++)
				{
					fscanf(filep, "%s %s\n", o[i].oname, o[i].code);
				}
				fclose(filep);
				filep = NULL;

				for (i = 0; i < 20; i++)
				{
					if (strcmp(nc1, o[i].oname) == 0 && strcmp(mi1, o[i].code) == 0)
					{
						k = 1;
						gnxz(num);
						memset(nc1, '\0', sizeof(nc1));
						memset(mi1, '\0', sizeof(mi1));
						draw1();
						break;
					}
					else
					{

						num++;
						k = 0;
					}
				}
				if (k == 0)
				{
					puthz(270, 400, "´íÎó", 24, 34, BLACK);
					memset(nc1, '\0', sizeof(nc1));
					memset(mi1, '\0', sizeof(mi1));
					delay(1000);
					draw1();
				}
			}
		}
		else if (mouse_press(530, 440, 636, 470) == 1)
		{
			delay(200);
			return;
		}

	}
	
}

void draw1()
{
	clearviewport();
	clrmous(MouseX,MouseY);
	setfillstyle(1,WHITE);
	bar(0,0,1023,767);
	setfillstyle(1,LIGHTBLUE);
	bar(0,0,1023,40);

	setcolor(LIGHTBLUE);
	circle(330, 250, 200);
	setfillstyle(1, LIGHTBLUE);
	floodfill(330, 250, LIGHTBLUE);

	puthz(265,10,"Ð£Íâ·ÃÎÊ",24,34,WHITE);
	/*
	setfillstyle(1,WHITE);
	bar(215,150,245,180);
	setcolor(WHITE);
	circle(215, 165, 15);
	circle(245, 165, 15);
	setfillstyle(1, WHITE);
	floodfill(212, 165, WHITE);
	floodfill(247, 165, WHITE);
	*/
	drawfram(230, 165);
	puthz(202,152,"êÇ³Æ",24,30,BLACK);

	setfillstyle(1, WHITE);
	sector(420, 162, 230, 310, 16, 16);
	fillellipse(420, 160, 6, 6);
	setcolor(WHITE);
	//µÇÂ¼Ð¡ÈË 
	
	//bar(200,200,260,230);
	drawfram(230, 215);
	puthz(202,202,"ÃÜÂë",24,30,BLACK);

	setcolor(WHITE);
	bar(410, 215, 430, 225);
	circle(420, 215, 5);//»­Ëø
	
	//bar(270,250,350,280);
	drawfram(310, 265);
	drawfram(320, 265);
	puthz(284,255,"×¢²á",24,34,BLACK);
	
	//bar(270,320,350,350);
	drawfram(310, 335);
	drawfram(320, 335);
	puthz(284,325,"µÇÂ¼",24,34,BLACK);
	
	setfillstyle(1,LIGHTGRAY);
	bar(530,440,636,470);
	puthz(550,445,"·µ»Ø",24,34,BLACK);

	setfillstyle(1,WHITE);//»­¿ò 
	bar(270,150,400,180);
	bar(270,200,400,230);
		
}



void shuru1(int x, int y, char* s, int a,int end_x,int end_y)
{
	char c;
	char buffer1[20];
	char temp[2];
	int i = 0, j = 0,x1=x,y1=y;
	clrmous(MouseX, MouseY);
	clrmous(MouseX, MouseY);
	memset(temp, '\0', sizeof(temp));
	memset(buffer1, '\0', sizeof(buffer1));

   
	while (bioskey(1))//Çå³ý¼üÅÌ»º³åÇø  ·ÀÖ¹ÎóÊäÈë
	{
		bioskey(0);
	}
	
	while (1)
	{
		
		newmouse(&MouseX, &MouseY, &press);
		if ((mouse_press(x, y, end_x, end_y) == 0) && (mouse_press(0, 0, 1023, 767) == 1))
		{
			break;
		}
		
		if (kbhit() != 0)
		{
			c = getch();//bioskey(0);
			if (c == 13)
			{
				break;
			}
			else if (c == '\b')
			{
				if (i == 0)
				{
					continue;
				}
				setfillstyle(1, WHITE);
				x -= 12;
				clrmous(MouseX, MouseY);
				bar(x, y, x + 10, y + 27);
				save_bk_mou(MouseX, MouseY);
				drawmous(MouseX, MouseY);
				i--;
				buffer1[i] = '\0';
				continue;
			}
			if (x <end_x)
			{
				temp[0] = c;
				temp[1] = '\0';
				buffer1[i] = c;
				i++;
				setcolor(BLACK);
				settextstyle(2, 0, 8);
				clrmous(MouseX, MouseY);
				if (a == 0)
				{
					outtextxy(x, y, temp);
				}
				else
				{
					outtextxy(x, y, "*");
				}
				save_bk_mou(MouseX, MouseY);
				drawmous(MouseX, MouseY);
				x += 12;
			}

			buffer1[i] = '\0';
			strcpy(s, buffer1);
		}
	}
	
}

void drawfram(int x,int y)
{
	setfillstyle(1, WHITE);
	bar(x-15, y-15, x+15, y+15);
	setcolor(WHITE);
	circle(x - 15, y, 15);
	circle(x +15, y, 15);
	setfillstyle(1, WHITE);
	floodfill(x-29, y, WHITE);
	floodfill(x+29, y, WHITE);
}
