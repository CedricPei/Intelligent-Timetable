#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>
#include<string.h> 
#include<time.h>
#include"mouse.h"
#include"hz.h"
#include"stu.h"
#include"run.h"


void stumode(class*aia,class*jx,class*gd,class*sk,class*ch)
{
	USER u[5];
	char xh[11],mm[20],temp[5];//´æ´¢ÊäÈëµÄÑ§ºÅÃÜÂë»º³åÇø
	int jl[3],PE[5],xuanxiu[5];
	char *x=NULL,c,d;
	int count=0,i=0,k=0,j=0,w;
	FILE* unb=NULL , * week=NULL;
	delay(100);
	memset(xh, '\0', sizeof(xh));
	memset(mm, '\0', sizeof(mm));
	memset(temp, '\0', sizeof(temp));
	memset(jl, 0, sizeof(jl));
	memset(PE, 0, sizeof(PE));
	memset(xuanxiu, 0, sizeof(xuanxiu));
	if((unb=fopen("c:\\ckeshe\\txt\\student.txt","rt+"))==NULL)
	{
		printf("cannot open student.txt");
	}
	while (1)
	{
		d = fgetc(unb);
		if (d == EOF)
		{
			break;
		}
		if (k == 0&&d<='9'&&d>='0')
		{
			(u+count)->xuehao[i] = d;
			i++;
		}
		else if (k == 1 && d <= '9' && d >= '0')
		{
			(u + count)->mima[i] = d;
			i++;
		}
		else if (k == 2 && d <= '9' && d >= '0')
		{
			(u + count)->xy = d - '0';
		}
		else if (k == 3 && d <= '9' && d >= '0')
		{
			PE[count] = d - '0';
		}
		else if (k == 4 && d <= '9' && d >= '0')
		{
			xuanxiu[count] = d - '0';
		}
		else if (d == '\n' && k == 0)
		{
			(u + count)->xuehao[i] = '\0';
			i = 0;
			k++;
		}
		else if (d == '\n'&&k==1)
		{
			(u + count)->mima[i] = '\0';
			i = 0;
			k++;
		}
		
		else if (d == '\n' && k == 2)
		{
			k++;
			//i = 0, k = 0;
			//count++;
		}
		else if (d == '\n' && k == 3)
		{
			k++;
			//count++;
		}
		else if (d == '\n' && k == 4)
		{
			i = 0, k = 0;
			count++;
		}
	}
	clearviewport();
	drawview();
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
		if(mouse_press(260, 190, 260 + 315, 220)==2||mouse_press(260, 250, 260 + 315, 280)==2)
		{
			MouseS=2;
		}
		else if(mouse_press(260, 360, 380, 395)==2||mouse_press(260, 310, 380, 345)==2||mouse_press(260, 410, 380, 445)==2)
		{
			MouseS=1;
		}
		else if(mouse_press(260, 190, 260 + 315, 220)==0&&mouse_press(260, 250, 260 + 315, 280)==0&&mouse_press(260, 360, 380, 395)==0&&mouse_press(260, 310, 380, 345)==0&&mouse_press(260, 410, 380, 445)==0)
		{
			MouseS=0;
		}
		if(mouse_press(260, 360, 380, 395)==2&&jl[0]==0)
		{
			clrmous(MouseX,MouseY);
			setfillstyle(1,LIGHTGREEN);
			bar(260, 360, 380, 395);
			puthz(290, 365, "×¢²á", 24, 34, BLACK);
			jl[0]=1;
		}
		else if(mouse_press(260, 360, 380, 395)==0&&jl[0]==1)
		{
			clrmous(MouseX,MouseY);
			setfillstyle(1,WHITE);
			bar(260, 360, 380, 395);
			puthz(290, 365, "×¢²á", 24, 34, BLACK);
			jl[0]=0;
		}
		if(mouse_press(260, 310, 380, 345)==2&&jl[1]==0)
		{
			clrmous(MouseX,MouseY);
			setfillstyle(1,LIGHTGREEN);
			bar(260, 310, 380, 345);
			puthz(290, 315, "µÇÂ¼", 24, 34, BLACK);
			jl[1]=1;
		}
		else if(mouse_press(260, 310, 380, 345)==0&&jl[1]==1)
		{
			clrmous(MouseX,MouseY);
			setfillstyle(1,WHITE);
			bar(260, 310, 380, 345);
			puthz(290, 315, "µÇÂ¼", 24, 34, BLACK);
			jl[1]=0;
		}
		if(mouse_press(260, 410, 380, 445)==2&&jl[2]==0)
		{
			clrmous(MouseX,MouseY);
			setfillstyle(1,LIGHTGREEN);
			bar(260, 410, 380, 445);
			puthz(290, 415, "·µ»Ø", 24, 34, BLACK);
			jl[2]=1;
		}
		else if(mouse_press(260, 410, 380, 445)==0&&jl[2]==1)
		{
			clrmous(MouseX,MouseY);
			setfillstyle(1,WHITE);
			bar(260, 410, 380, 445);
			puthz(290, 415, "·µ»Ø", 24, 34, BLACK);
			jl[2]=0;
		}
		if(mouse_press(260, 190, 260 + 315, 220)==1)//ÊäÈëÑ§ºÅ 
		{
			clrmous(MouseX,MouseY);
			setfillstyle(1,WHITE);
			bar(260, 190, 260 + 315, 220);
			strcpy(xh,'\0');
			shuru(260,193,xh,0);
		}
		else if(mouse_press(260, 250, 260 + 315, 280)==1)//ÊäÈëÃÜÂë 
		{
			clrmous(MouseX,MouseY);
			setfillstyle(1,WHITE);
			bar(260, 250, 260 + 315, 280);
			strcpy(mm,'\0');
			shuru(260,253,mm,1);
		}
		else if(mouse_press(260, 360, 380, 395)==1)//×¢²á 
		{
			zhuce(u, (count + 1), unb);
			clearviewport();
			drawview();
			count++;
		}
		else if(mouse_press(260, 310, 380, 345)==1)//µã»÷µÇÂ¼¿ò 
		{
			setfillstyle(1,5);
			for (i = 0; i < 5; i++)
			{
				if ((u + i)->xy != 0)
				{
					break;
				}
			}
			if (i == 5)
			{
				puthz(385, 315, "ÇëÏÈ×¢²á", 24, 24, YELLOW);
				delay(200);
				bar(380, 310, 480, 400);
				continue;
			}
			for (i = 0; i < 5; i++)
			{
				if (strcmp((u + i)->xuehao, xh) == 0)
				{
					break;
				}
			}
			if (i == 5)
			{
				puthz(500, 170, "Ñ§ºÅ´íÎó", 16, 16, YELLOW);
				delay(200);
				bar(490, 169, 570, 189);
				continue;
			}
			w = i;
			if(strcmp((u+i)->mima,mm)!=0)
			{
				puthz(500,230,"ÃÜÂë´íÎó",16,16,YELLOW);
				delay(200);
				bar(490,229,570,249);
				continue;
			}
			
			else
			{
				delay(100);
				if((u+i)->xy==1)
				{
					if ((week = fopen("c:\\ckeshe\\txt\\stwk1.txt", "rt")) == NULL)
					{
						printf("cannot open stwk1.txt");
					}
					j = 0;
					for (i = 0; i < 8; i++)
					{
						while (1)
						{
							c = fgetc(week);
							//printf("%d", c - '0');
							//scanf("%s", temp);
							if (c == EOF || c == '\n')
							{
								break;
							}
							temp[j] = c;
							j++;
						}
						temp[j] = '\0';
						j = 0;
						(aia + i)->stwk = atoi(temp);
						//printf("%d", (aia + i)->stwk);
						strcpy(temp, "\0");
					}
					for (i = 0; i < 8; i++)
					{
						while (1)
						{
							c = fgetc(week);
							//printf("%d", c - '0');
							//scanf("%s", temp);
							if (c == EOF || c == '\n')
							{
								break;
							}
							temp[j] = c;
							j++;
						}
						temp[j] = '\0';
						j = 0;
						(aia + i)->edwk = atoi(temp);
						strcpy(temp, "\0");
					}
					for (i = 0; i < 8; i++)
					{
						while (1)
						{
							c = fgetc(week);
							//printf("%d", c - '0');
							//scanf("%s", temp);
							if (c == EOF || c == '\n')
							{
								break;
							}
							temp[j] = c;
							j++;
						}
						temp[j] = '\0';
						j = 0;
						(aia + i)->mzjs = atoi(temp);
						strcpy(temp, "\0");
					}
					for (i = 0; i < 8; i++)
					{
						while (1)
						{
							c = fgetc(week);
							if (c == EOF || c == '\n')
							{
								break;
							}
							temp[j] = c;
							j++;
						}
						temp[j] = '\0';
						j = 0;
						strcpy((aia + i)->tcname, temp);
						strcpy(temp, "\0");
					}
					for (i = 0; i < 8; i++)
					{
						while (1)
						{
							c = fgetc(week);
							if (c == EOF || c == '\n')
							{
								break;
							}
							if (j == 0)
							{
								(aia + i)->bui = c - '0';
							}
							else if (j == 1)
							{
								(aia + i)->flr = c - '0';
							}
							else
							{
								(aia + i)->room = c - '0';
							}
							j++;
						}
						j = 0;
					}
					for (i = 0; i < 8; i++)
					{
						for (j = 0; j < 5; j++)
						{
							for (k = 0; k < 2; k++)
							{
								c = fgetc(week);
								(aia + i)->t[j][k] = c - '0';
							}
						}
					}
					fclose(week);
					runmode( aia,w);
				}
				else if((u + i)->xy==2)
				{
					if ((week = fopen("c:\\ckeshe\\txt\\stwk2.txt", "rt")) == NULL)
					{
						printf("cannot open stwk1.txt");
					}
					j = 0;
					for (i = 0; i < 8; i++)
					{
						while (1)
						{
							c = fgetc(week);
							//printf("%d", c - '0');
							//scanf("%s", temp);
							if (c == EOF || c == '\n')
							{
								break;
							}
							temp[j] = c;
							j++;
						}
						temp[j] = '\0';
						j = 0;
						(jx + i)->stwk = atoi(temp);
						//printf("%d", (aia + i)->stwk);
						strcpy(temp, "\0");
					}
					for (i = 0; i < 8; i++)
					{
						while (1)
						{
							c = fgetc(week);
							//printf("%d", c - '0');
							//scanf("%s", temp);
							if (c == EOF || c == '\n')
							{
								break;
							}
							temp[j] = c;
							j++;
						}
						temp[j] = '\0';
						j = 0;
						(jx + i)->edwk = atoi(temp);
						strcpy(temp, "\0");
					}
					for (i = 0; i < 8; i++)
					{
						while (1)
						{
							c = fgetc(week);
							//printf("%d", c - '0');
							//scanf("%s", temp);
							if (c == EOF || c == '\n')
							{
								break;
							}
							temp[j] = c;
							j++;
						}
						temp[j] = '\0';
						j = 0;
						(jx + i)->mzjs = atoi(temp);
						strcpy(temp, "\0");
					}
					for (i = 0; i < 8; i++)
					{
						while (1)
						{
							c = fgetc(week);
							if (c == EOF || c == '\n')
							{
								break;
							}
							temp[j] = c;
							j++;
						}
						temp[j] = '\0';
						j = 0;
						strcpy((jx + i)->tcname, temp);
						strcpy(temp, "\0");
					}
					for (i = 0; i < 8; i++)
					{
						while (1)
						{
							c = fgetc(week);
							if (c == EOF || c == '\n')
							{
								break;
							}
							if (j == 0)
							{
								(jx + i)->bui = c - '0';
							}
							else if (j == 1)
							{
								(jx + i)->flr = c - '0';
							}
							else
							{
								(jx + i)->room = c - '0';
							}
							j++;
						}
						j = 0;
					}
					for (i = 0; i < 8; i++)
					{
						for (j = 0; j < 5; j++)
						{
							for (k = 0; k < 2; k++)
							{
								c = fgetc(week);
								(jx + i)->t[j][k] = c - '0';
							}
						}
					}
					fclose(week);
					runmode( jx,w);
				}
				else if((u + i)->xy==3)
				{
				if ((week = fopen("c:\\ckeshe\\txt\\stwk3.txt", "rt")) == NULL)
				{
					printf("cannot open stwk3.txt");
				}
				j = 0;
				for (i = 0; i < 8; i++)
				{
					while (1)
					{
						c = fgetc(week);
						//printf("%d", c - '0');
						//scanf("%s", temp);
						if (c == EOF || c == '\n')
						{
							break;
						}
						temp[j] = c;
						j++;
					}
					temp[j] = '\0';
					j = 0;
					(gd + i)->stwk = atoi(temp);
					//printf("%d", (aia + i)->stwk);
					strcpy(temp, "\0");
				}
				for (i = 0; i < 8; i++)
				{
					while (1)
					{
						c = fgetc(week);
						//printf("%d", c - '0');
						//scanf("%s", temp);
						if (c == EOF || c == '\n')
						{
							break;
						}
						temp[j] = c;
						j++;
					}
					temp[j] = '\0';
					j = 0;
					(gd + i)->edwk = atoi(temp);
					strcpy(temp, "\0");
				}
				for (i = 0; i < 8; i++)
				{
					while (1)
					{
						c = fgetc(week);
						//printf("%d", c - '0');
						//scanf("%s", temp);
						if (c == EOF || c == '\n')
						{
							break;
						}
						temp[j] = c;
						j++;
					}
					temp[j] = '\0';
					j = 0;
					(gd + i)->mzjs = atoi(temp);
					strcpy(temp, "\0");
				}
				for (i = 0; i < 8; i++)
				{
					while (1)
					{
						c = fgetc(week);
						if (c == EOF || c == '\n')
						{
							break;
						}
						temp[j] = c;
						j++;
					}
					temp[j] = '\0';
					j = 0;
					strcpy((gd + i)->tcname, temp);
					strcpy(temp, "\0");
				}
				for (i = 0; i < 8; i++)
				{
					while (1)
					{
						c = fgetc(week);
						if (c == EOF || c == '\n')
						{
							break;
						}
						if (j == 0)
						{
							(gd + i)->bui = c - '0';
						}
						else if (j == 1)
						{
							(gd + i)->flr = c - '0';
						}
						else
						{
							(gd + i)->room = c - '0';
						}
						j++;
					}
					j = 0;
				}
				for (i = 0; i < 8; i++)
				{
					for (j = 0; j < 5; j++)
					{
						for (k = 0; k < 2; k++)
						{
							c = fgetc(week);
							(gd + i)->t[j][k] = c - '0';
						}
					}
				}
				fclose(week);
					runmode( gd,w);
				}
				else if((u + i)->xy==4)
				{
					if ((week = fopen("c:\\ckeshe\\txt\\stwk4.txt", "rt")) == NULL)
					{
						printf("cannot open stwk1.txt");
					}
					j = 0;
					for (i = 0; i < 8; i++)
					{
						while (1)
						{
							c = fgetc(week);
							//printf("%d", c - '0');
							//scanf("%s", temp);
							if (c == EOF || c == '\n')
							{
								break;
							}
							temp[j] = c;
							j++;
						}
						temp[j] = '\0';
						j = 0;
						(sk + i)->stwk = atoi(temp);
						//printf("%d", (aia + i)->stwk);
						strcpy(temp, "\0");
					}
					for (i = 0; i < 8; i++)
					{
						while (1)
						{
							c = fgetc(week);
							//printf("%d", c - '0');
							//scanf("%s", temp);
							if (c == EOF || c == '\n')
							{
								break;
							}
							temp[j] = c;
							j++;
						}
						temp[j] = '\0';
						j = 0;
						(sk + i)->edwk = atoi(temp);
						strcpy(temp, "\0");
					}
					for (i = 0; i < 8; i++)
					{
						while (1)
						{
							c = fgetc(week);
							//printf("%d", c - '0');
							//scanf("%s", temp);
							if (c == EOF || c == '\n')
							{
								break;
							}
							temp[j] = c;
							j++;
						}
						temp[j] = '\0';
						j = 0;
						(sk + i)->mzjs = atoi(temp);
						strcpy(temp, "\0");
					}
					for (i = 0; i < 8; i++)
					{
						while (1)
						{
							c = fgetc(week);
							if (c == EOF || c == '\n')
							{
								break;
							}
							temp[j] = c;
							j++;
						}
						temp[j] = '\0';
						j = 0;
						strcpy((sk + i)->tcname, temp);
						strcpy(temp, "\0");
					}
					for (i = 0; i < 8; i++)
					{
						while (1)
						{
							c = fgetc(week);
							if (c == EOF || c == '\n')
							{
								break;
							}
							if (j == 0)
							{
								(sk + i)->bui = c - '0';
							}
							else if (j == 1)
							{
								(sk + i)->flr = c - '0';
							}
							else
							{
								(sk + i)->room = c - '0';
							}
							j++;
						}
						j = 0;
					}
					for (i = 0; i < 8; i++)
					{
						for (j = 0; j < 5; j++)
						{
							for (k = 0; k < 2; k++)
							{
								c = fgetc(week);
								(sk + i)->t[j][k] = c - '0';
							}
						}
					}
					fclose(week);
					runmode( sk,w);
				}
				else if((u + i)->xy==5)
				{
					if ((week = fopen("c:\\ckeshe\\txt\\stwk5.txt", "rt")) == NULL)
					{
						printf("cannot open stwk1.txt");
					}
					j = 0;
					for (i = 0; i < 8; i++)
					{
						while (1)
						{
							c = fgetc(week);
							//printf("%d", c - '0');
							//scanf("%s", temp);
							if (c == EOF || c == '\n')
							{
								break;
							}
							temp[j] = c;
							j++;
						}
						temp[j] = '\0';
						j = 0;
						(ch + i)->stwk = atoi(temp);
						//printf("%d", (aia + i)->stwk);
						strcpy(temp, "\0");
					}
					for (i = 0; i < 8; i++)
					{
						while (1)
						{
							c = fgetc(week);
							//printf("%d", c - '0');
							//scanf("%s", temp);
							if (c == EOF || c == '\n')
							{
								break;
							}
							temp[j] = c;
							j++;
						}
						temp[j] = '\0';
						j = 0;
						(ch + i)->edwk = atoi(temp);
						strcpy(temp, "\0");
					}
					for (i = 0; i < 8; i++)
					{
						while (1)
						{
							c = fgetc(week);
							//printf("%d", c - '0');
							//scanf("%s", temp);
							if (c == EOF || c == '\n')
							{
								break;
							}
							temp[j] = c;
							j++;
						}
						temp[j] = '\0';
						j = 0;
						(ch + i)->mzjs = atoi(temp);
						strcpy(temp, "\0");
					}
					for (i = 0; i < 8; i++)
					{
						while (1)
						{
							c = fgetc(week);
							if (c == EOF || c == '\n')
							{
								break;
							}
							temp[j] = c;
							j++;
						}
						temp[j] = '\0';
						j = 0;
						strcpy((ch + i)->tcname, temp);
						strcpy(temp, "\0");
					}
					for (i = 0; i < 8; i++)
					{
						while (1)
						{
							c = fgetc(week);
							if (c == EOF || c == '\n')
							{
								break;
							}
							if (j == 0)
							{
								(ch + i)->bui = c - '0';
							}
							else if (j == 1)
							{
								(ch + i)->flr = c - '0';
							}
							else
							{
								(ch + i)->room = c - '0';
							}
							j++;
						}
						j = 0;
					}
					for (i = 0; i < 8; i++)
					{
						for (j = 0; j < 5; j++)
						{
							for (k = 0; k < 2; k++)
							{
								c = fgetc(week);
								(ch + i)->t[j][k] = c - '0';
							}
						}
					}
					fclose(week);
					runmode( ch,w);
				}
				//runmode(u);
				clearviewport;
	            drawview();
			}
		}
		else if(mouse_press(260, 410, 380, 445)==1)//µã»÷·µ»Ø¿ò 
		{
		    fclose(unb);
			return;
	    }
	}
}


void drawview()
{
	clrmous(MouseX,MouseY);
	setfillstyle(1,5);
	bar(0,0,1023,767);
	setfillstyle(1, YELLOW);
	bar(0, 0, 640, 50);
	puthz(20, 10, "ÖÇÄÜ¿Î³Ì±í", 24, 34, BLACK);
	setfillstyle(1, YELLOW);
	fillellipse(320, 120, 35, 35);
	setcolor(LIGHTCYAN);
	setlinestyle(SOLID_LINE, 0, 2);
	line(0, 120, 640, 120);
	line(0, 0, 0, 120);
	line(639, 0, 639, 120);
	
	setfillstyle(1, LIGHTGREEN);
	sector(320, 120, 230, 310, 35, 35);
	fillellipse(320, 120 - 5, 15, 15);
	setcolor(LIGHTGREEN);
	circle(320, 120 - 5, 15);//µÇÂ¼Ð¡ÈË 
	
	setfillstyle(SOLID_FILL, WHITE);
	bar(140, 190, 260, 220);
	bar(260, 190, 260 + 315, 220);	//ÕËºÅ¿ò

	bar(140, 250, 260, 280);
	bar(260, 250, 260 + 315, 280);	//ÃÜÂë¿ò
	
	setfillstyle(1, WHITE);
	sector(102, 203, 230, 310, 15, 15);
	fillellipse(102, 203 - 2, 7, 7);
	setcolor(WHITE);
	circle(102, 203 - 2, 7);//»­µÇÂ¼Ð¡ÈË2

	setcolor(WHITE);
	rectangle(89, 260, 115, 275);
	arc(102, 260, 0, 180, 7);
	circle(102, 267, 4);//»­Ëø
	
	setcolor(LIGHTGREEN);
	setlinestyle(SOLID_LINE, 0, 3);
	line(260, 190, 260, 220);
	line(260, 250, 260, 280);	
	rectangle(140, 190, 260 + 315, 220);
	rectangle(140, 250, 260 + 315, 280);	//»­ÓÃ»§ÃûºÍÃÜÂëµÄ±ß¿ò
	
	puthz(163, 193, "Ñ§ºÅ", 24, 50, BLACK);
	puthz(163, 253, "ÃÜÂë", 24, 50, BLACK);
	
	setfillstyle(SOLID_FILL, WHITE);
	bar(260, 310, 380, 345);
	puthz(290, 315, "µÇÂ¼", 24, 34, BLACK);//µÇÂ¼¿ò
	
	setfillstyle(SOLID_FILL, WHITE);
	bar(260, 360, 380, 395);
	puthz(290, 365, "×¢²á", 24, 34, BLACK);//×¢²á¿ò
	
	setfillstyle(SOLID_FILL, WHITE);
	bar(260, 410, 380, 445);
	puthz(290, 415, "·µ»Ø", 24, 34, BLACK);//·µ»Ø¿ò
}

void zhuce(USER*u,int i,FILE *unb)
{
	int j=0;
	clrmous(MouseX,MouseY);
	clearviewport();
	setfillstyle(1,RED);
	bar(0,0,1023,767);
	setfillstyle(SOLID_FILL, WHITE);
	
	bar(140, 110, 260, 140);
	bar(260, 110, 260 + 315, 140);	//ÕËºÅ¿ò

	bar(140, 170, 260, 200);
	bar(260, 170, 260 + 315, 200);	//ÃÜÂë¿ò
	
	bar(290,410,350,435);
	puthz(302,415,"×¢²á",16,24,BLUE); 
	
	bar(198,230,448,255);
	setfillstyle(1,BLACK);
	moveto(410,235);
	lineto(436,235);
	lineto(423,250);
	lineto(410,235);
	//floodfill(423,240,BLACK);
	puthz(198,231,"ÇëÑ¡ÔñÑ§Ôº",24,24,BLACK);//Ñ¡ÔñÑ§Ôº¿ò
	
	 
	
	puthz(163, 113, "Ñ§ºÅ", 24, 50, BLACK);
	puthz(163, 173, "ÃÜÂë", 24, 50, BLACK);
	
	setcolor(BLACK);
	setlinestyle(SOLID_LINE, 0, 3);
	line(260, 110, 260, 140);
	line(260, 170, 260, 200);	
	rectangle(140, 110, 260 + 315, 140);
	rectangle(140, 170, 260 + 315, 200);	//»­ÓÃ»§ÃûºÍÃÜÂëµÄ±ß¿ò
	
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
		if(mouse_press(260,110,575,140)==2||mouse_press(260,170,575,200)==2)
		{
			MouseS=2;
		}
		
		else if(mouse_press(260,110,575,140)==1)
		{
			j = 0;
			clrmous(MouseX,MouseY);
			setfillstyle(1,WHITE);
			bar(260,110,575,140);
			//strcpy(u->xuehao,'\0');
			shuruzc(260,113,(u+i)->xuehao,0);
		}
		else if(mouse_press(260,170,575,200)==1)
		{
			j = 0;
			clrmous(MouseX,MouseY);
			setfillstyle(1,WHITE);
			bar(260,170,575,200);
			//strcpy(u->mima,'\0');
			shuruzc(260,173,(u+i)->mima,1);
		}
		else if(mouse_press(410,235,436,250)==1)
		{
			delay(200);
			xysel(&((u+i)->xy));
			clrmous(MouseX,MouseY);
			setfillstyle(1, RED);
			bar(198, 255, 448, 410);
		}
		else if(mouse_press(290,410,350,435)==1)
		{
			if((u+i)->xuehao[0]!='\0'&&(u+i)->mima[0]!='\0'&&(u+i)->xy!=0)
			{
				rewind(unb);
				if (fgetc(unb) != EOF)
				{
					fseek(unb, 0L, 2);
					fputc('\n', unb);
					while ((u + i)->xuehao[j] != '\0')
					{
						fputc((u + i)->xuehao[j], unb);
						j++;
					}
				}
				else
				{
					rewind(unb);
					while ((u + i)->xuehao[j] != '\0')
					{
						fputc((u + i)->xuehao[j], unb);
						j++;
					}
				}
				fputc('\n', unb);
				j = 0;
				while ((u + i)->mima[j] != '\0')
				{
					fputc((u + i)->mima[j], unb);
					j++;
				}
				fputc('\n', unb);
				fputc((u + i)->xy + '0', unb);
				fputc('\n', unb);
				fputc((u + i)->xy + '0', unb);
				fputc('\n', unb);
				fputc((u + i)->xy + '0', unb);
				delay(200);
				return;
			}
			else
			{
				puthz(355,413,"×¢²áÎ´Íê³É",24,24,YELLOW);
			}
		}
		else
		{
			MouseS=0;
		}
	}
	
}

void shuru(int x,int y,char*s,int a)
{
	char c;
	char huanchong[20];
	char temp[2];
	int i=0;
	int jl[3] = { 0 };
	//clrmous(MouseX,MouseY); 

	while(1)
	{
		newmouse(&MouseX, &MouseY, &press);
		if (mouse_press(260, 190, 260 + 315, 220) == 2 || mouse_press(260, 250, 260 + 315, 280) == 2)
		{
			MouseS = 2;
		}
		else if (mouse_press(260, 360, 380, 395) == 2 || mouse_press(260, 310, 380, 345) == 2 || mouse_press(260, 410, 380, 445) == 2)
		{
			MouseS = 1;
		}
		else if (mouse_press(260, 190, 260 + 315, 220) == 0 && mouse_press(260, 250, 260 + 315, 280) == 0 && mouse_press(260, 360, 380, 395) == 0 && mouse_press(260, 310, 380, 345) == 0 && mouse_press(260, 410, 380, 445) == 0)
		{
			MouseS = 0;
		}
		if (mouse_press(260, 360, 380, 395) == 2 && jl[0] == 0)
		{
			clrmous(MouseX, MouseY);
			setfillstyle(1, LIGHTGREEN);
			bar(260, 360, 380, 395);
			puthz(290, 365, "×¢²á", 24, 34, BLACK);
			jl[0] = 1;
		}
		else if (mouse_press(260, 360, 380, 395) == 0 && jl[0] == 1)
		{
			clrmous(MouseX, MouseY);
			setfillstyle(1, WHITE);
			bar(260, 360, 380, 395);
			puthz(290, 365, "×¢²á", 24, 34, BLACK);
			jl[0] = 0;
		}
		if (mouse_press(260, 310, 380, 345) == 2 && jl[1] == 0)
		{
			clrmous(MouseX, MouseY);
			setfillstyle(1, LIGHTGREEN);
			bar(260, 310, 380, 345);
			puthz(290, 315, "µÇÂ¼", 24, 34, BLACK);
			jl[1] = 1;
		}
		else if (mouse_press(260, 310, 380, 345) == 0 && jl[1] == 1)
		{
			clrmous(MouseX, MouseY);
			setfillstyle(1, WHITE);
			bar(260, 310, 380, 345);
			puthz(290, 315, "µÇÂ¼", 24, 34, BLACK);
			jl[1] = 0;
		}
		if (mouse_press(260, 410, 380, 445) == 2 && jl[2] == 0)
		{
			clrmous(MouseX, MouseY);
			setfillstyle(1, LIGHTGREEN);
			bar(260, 410, 380, 445);
			puthz(290, 415, "·µ»Ø", 24, 34, BLACK);
			jl[2] = 1;
		}
		else if (mouse_press(260, 410, 380, 445) == 0 && jl[2] == 1)
		{
			clrmous(MouseX, MouseY);
			setfillstyle(1, WHITE);
			bar(260, 410, 380, 445);
			puthz(290, 415, "·µ»Ø", 24, 34, BLACK);
			jl[2] = 0;
		}
		if (mouse_press(0, 0, 640, 480) == 1)
		{
			break;
		}
		if (kbhit())
		{
			c = getch();
			if (c == '\b'&&x>=260)
			{
				if (i == 0)
				{
					continue;
				}
				setfillstyle(1, WHITE);
				x -= 12;
				bar(x, y, x + 10, y + 23);
				i--;
				huanchong[i] = '\0';
				continue;
			}
			if (a == 0&&x<=550&&c!=13)
			{
				temp[0] = c, temp[1] = '\0';
				huanchong[i] = c;
				i++;
				setcolor(BLACK);
				settextstyle(2, 0, 8);
				outtextxy(x, y, temp);
				x += 12;
			}
			
			else if(x<=550&&c != 13)
			{
				temp[0] = c, temp[1] = '\0';
				huanchong[i] = c;
				i++;
				setcolor(BLACK);
				settextstyle(2, 0, 8);
				outtextxy(x, y, "*");
				x += 12;
			}
			else if (c == 13)
			{
				break;
			}
			
		}
		
	}
	huanchong[i]='\0';
	strcpy(s, huanchong);
	//newmouse(&MouseX,&MouseY,&press);
	return;
}

void xysel(int* n)
{
	int i;
	char*s[5]={"ÈË¹¤ÖÇÄÜÓë×Ô¶¯»¯",
	           "»úÐµ",
			   "¹âµç",
			   "ÉúÃü¿ÆÑ§",
			   "´¬º£"};
	clrmous(MouseX,MouseY);
	setfillstyle(1,WHITE);
	for(i=0;i<5;i++)
	{
		bar(198,230+i*25+25,448,255+i*25+25);
		puthz(198,233+i*25+25,s[i],16,16,BLACK); 
	}
	setcolor(BLACK);
	setlinestyle(0,0,3);
	for(i=0;i<6;i++)
	{
		line(198,230+i*25+25,448,230+i*25+25);
	}
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
		if(mouse_press(198,230+1*25,448,255+1*25)==1)
		{
			*n=1;
			bar(198,230,410,255);
			puthz(198,233,s[0],16,16,BLACK);
			setfillstyle(1,RED);
			//bar(198,255,448,255+125);
			clrmous(MouseX,MouseY);
			break;
		}
		else if(mouse_press(198,230+2*25,448,255+2*25)==1)
		{
			*n=2;
			bar(198,230,410,255);
			puthz(198,233,s[1],16,16,BLACK);
			setfillstyle(1,RED);
			//bar(198,255,448,255+125);
			clrmous(MouseX,MouseY);
			break;
		}
		else if(mouse_press(198,230+3*25,448,255+3*25)==1)
		{
			*n=3;
			bar(198,230,410,255);
			puthz(198,233,s[2],16,16,BLACK);
			setfillstyle(1,RED);
			//bar(198,255,448,255+125);
			clrmous(MouseX,MouseY);
			break;
		}
		else if(mouse_press(198,230+4*25,448,255+4*25)==1)
		{
			*n=4;
			bar(198,230,410,255);
			puthz(198,233,s[3],16,16,BLACK);
			setfillstyle(1,RED);
			//bar(198,255,448,255+125);
			clrmous(MouseX,MouseY);
			break;
		}
		else if(mouse_press(198,230+5*25,448,255+5*25)==1)
		{
			*n=5;
			bar(198,230,410,255);
			puthz(198,233,s[4],16,16,BLACK);
			setfillstyle(1,RED);
			//bar(198,255,448,255+125);
			clrmous(MouseX,MouseY);
			break;
		}
		else if(mouse_press(410,235,436,250)==1)
		{
			setfillstyle(1,RED);
			//bar(198,255,448,255+125);
			clrmous(MouseX,MouseY);
			break;
		}
	}
	delay(200);
	return;
}

void shuruzc(int x, int y, char* s, int a)
{
	char c;
	char huanchong[20];
	char temp[2];
	int i = 0;
	int jl[3] = { 0 };
	//clrmous(MouseX,MouseY); 

	while (1)
	{
		newmouse(&MouseX, &MouseY, &press);
		if (mouse_press(260, 110, 575, 140) == 2 || mouse_press(260, 170, 575, 200) == 2)
		{
			MouseS = 2;
		}
		else if (mouse_press(410, 235, 436, 250) == 2)
		{
			MouseS = 1;
		}
		else
		{
			MouseS = 0;
		}
		if (mouse_press(0, 0, 640, 480) == 1)
		{
			break;
		}
		if (kbhit())
		{
			c = getch();
			/*if (c == 13)
			{
				break;
			}*/
			if (c == '\b'&&x>=260)
			{
				if (i == 0)
				{
					continue;
				}
				setfillstyle(1, WHITE);
				x -= 12;
				bar(x, y, x + 10, y + 23);
				i--;
				huanchong[i] = '\0';
				continue;
			}
			
			if (a == 0&&x<=562&&c!=13)
			{
				temp[0] = c, temp[1] = '\0';
				huanchong[i] = c;
				i++;
				setcolor(BLACK);
				settextstyle(2, 0, 8);
				outtextxy(x, y, temp);
				x += 12;
			}
			
			else if(x<=562&&c != 13)
			{
				temp[0] = c, temp[1] = '\0';
				huanchong[i] = c;
				i++;
				setcolor(BLACK);
				settextstyle(2, 0, 8);
				outtextxy(x, y, "*");
				x += 12;
			}
			else if (c == 13)
			{
				break;
			}
			
		}

	}
	huanchong[i] = '\0';
	strcpy(s, huanchong);
	//newmouse(&MouseX,&MouseY,&press);
	return;
}
