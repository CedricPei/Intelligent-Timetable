#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>
#include<time.h>
#include<string.h> 
#include"mouse.h"
#include"hz.h"
#include"paike.h"
#include"tc.h"
#include"select.h"
#include"pos.h"
#include"yulan.h"

void pk(int num,int*ret,class*xuey,char**pbcl,tec*wjf,tec*xxds,tec*jsll,tec*sx,tec*zgyw,tec*zhyy,int *jil,int *jszy)
{
	int i, j, k;
	int jl[24];
	int tectemp[6];
	char stw[8][5], edw[8][5], evw[8][5], newtxt[30], temp[5];
	char c[6], ch, czf;
	FILE* week=NULL, * old=NULL;
	memset(jl, 0, sizeof(jl));
	memset(tectemp, 0, sizeof(tectemp));
	memset(stw, '\0', sizeof(stw));
	memset(edw, '\0', sizeof(edw));
	memset(newtxt, '\0', sizeof(newtxt));
	memset(temp, '\0', sizeof(temp));
	memset(c, '\0', sizeof(c));

	clearviewport();
	clrmous(MouseX, MouseY);
	setfillstyle(1, GREEN);
	bar(0, 0, 640, 480);
	puthz(10,5,"选择课程",24,24,WHITE);//画界面 
	puthz(150,5,"课程周数",24,24,WHITE);
	puthz(315,5,"选择教师",24,24,WHITE);
	puthz(450,5,"每周节数",24,24,WHITE);
	setcolor(WHITE);
	setlinestyle(0,0,3);
	setfillstyle(1,WHITE);
	for(i=0;i<8;i++)
	{
		bar(10,45+i*50,110,72+i*50);
		bar(150,45+i*50,210,72+i*50);
		line(215,59+i*50,235,59+i*50);
		bar(240,45+i*50,300,72+i*50);
		bar(315,45+i*50,405,72+i*50);
		bar(450,45+i*50,530,72+i*50);
		if(i>=6)
		{
			puthz(315,48+i*50,(xuey+i)->tcname,24,24,DARKGRAY);
		}
	}
	setcolor(BLACK);
	setfillstyle(1,BLACK);
	for(i=0;i<8;i++)
	{
		moveto(385,50+i*50);
		lineto(400,50+i*50);
		lineto(393,68+i*50);
		lineto(385,50+i*50);
		floodfill(393,60+i*50,BLACK);
	}
	setfillstyle(1,WHITE);
	bar(10,45+8*50,110,72+8*50);
	puthz(10,48+8*50,"完成排课",24,24,BLACK);
	for(i=0;i<6;i++)
	{
		puthz(10,48+i*50,pbcl[i],24,24,BLACK);
	}
	switch (num)
	{
	case 1:
		puthz(10, 48 + 6 * 50, "工程制图", 24, 24, BLACK);
		puthz(25, 48 + 7 * 50, "语言", 24, 24, BLACK);
		setcolor(BLACK);
		settextstyle(2, 0, 8);
		outtextxy(12, 48 + 7 * 50, "C");
		if (*ret != 1)
		{
			if ((week = fopen("c:\\ckeshe\\txt\\stwk1.txt", "w")) == NULL)
			{
				printf("cannot open stwk1.txt");
			}
		}
		else
		{
			if ((week = fopen("c:\\ckeshe\\txt\\newstw.txt", "wt+")) == NULL)
			{
				printf("cannot open newstw.txt");
			}
			if ((old = fopen("c:\\ckeshe\\txt\\stwk1.txt", "rt+")) == NULL)
			{
				printf("cannot open stwk1.txt");
			}
		}
		break;

	case 2:
		puthz(10, 48 + 6 * 50, "机械设计", 24, 24, BLACK);
		setcolor(BLACK);
		settextstyle(2, 0, 8);
		outtextxy(12, 48 + 7 * 50, "C++");
		if (*ret != 1)
		{
			if ((week = fopen("c:\\ckeshe\\txt\\stwk2.txt", "w")) == NULL)
			{
				printf("cannot open stwk2.txt");
			}
		}
		else
		{
			if ((week = fopen("c:\\ckeshe\\txt\\newstw.txt", "wt+")) == NULL)
			{
				printf("cannot open newstw.txt");
			}
			if ((old = fopen("c:\\ckeshe\\txt\\stwk2.txt", "rt+")) == NULL)
			{
				printf("cannot open stwk2.txt");
			}
		}
		break;


	case 3:
		puthz(10, 48 + 6 * 50, "工程制图", 24, 24, BLACK);
		puthz(10, 48 + 7 * 50, "软件基础", 24, 24, BLACK);
		if (*ret != 1)
		{
			if ((week = fopen("c:\\ckeshe\\txt\\stwk3.txt", "w")) == NULL)
			{
				printf("cannot open stwk3.txt");
			}
		}
		else
		{
			if ((week = fopen("c:\\ckeshe\\txt\\newstw.txt", "wt+")) == NULL)
			{
				printf("cannot open newstw.txt");
			}
			if ((old = fopen("c:\\ckeshe\\txt\\stwk3.txt", "rt+")) == NULL)
			{
				printf("cannot open stwk3.txt");
			}
		}
		break;


	case 4:
		puthz(10, 48 + 6 * 50, "工程制图", 24, 24, BLACK);
		puthz(10, 48 + 7 * 50, "基础化学", 24, 24, BLACK);
		if (*ret != 1)
		{
			if ((week = fopen("c:\\ckeshe\\txt\\stwk4.txt", "w")) == NULL)
			{
				printf("cannot open stwk4.txt");
			}
		}
		else
		{
			if ((week = fopen("c:\\ckeshe\\txt\\newstw.txt", "wt+")) == NULL)
			{
				printf("cannot open newstw.txt");
			}
			if ((old = fopen("c:\\ckeshe\\txt\\stwk4.txt", "rt+")) == NULL)
			{
				printf("cannot open stwk4.txt");
			}
		}
		break;

	case 5:
		puthz(10, 48 + 6 * 50, "机械设计", 24, 24, BLACK);
		setcolor(BLACK);
		settextstyle(2, 0, 8);
		outtextxy(12, 48 + 7 * 50, "C++");
		if (*ret != 1)
		{
			if ((week = fopen("c:\\ckeshe\\txt\\stwk5.txt", "w")) == NULL)
			{
				printf("cannot open stwk5.txt");
			}
		}
		else
		{
			if ((week = fopen("c:\\ckeshe\\txt\\newstw.txt", "wt+")) == NULL)
			{
				printf("cannot open newstw.txt");
			}
			if ((old = fopen("c:\\ckeshe\\txt\\stwk5.txt", "rt+")) == NULL)
			{
				printf("cannot open stwk5.txt");
			}
		}
		break;


	}
	setcolor(BLACK);
	settextstyle(2,0,8);
	if (*ret == 1)
	{
		j = 0;
		for (i = 0; i < 8; i++)
		{
			while (1)
			{
				czf = fgetc(old);
				//printf("%d", c - '0');
				//scanf("%s", temp);
				if (czf == EOF || czf == '\n')
				{
					break;
				}
				temp[j] = czf;
				j++;
			}
			temp[j] = '\0';
			j = 0;
			(xuey + i)->stwk = atoi(temp);
			//printf("%d", (aia + i)->stwk);
			strcpy(temp, "\0");
		}
		for (i = 0; i < 8; i++)
		{
			while (1)
			{
				czf = fgetc(old);
				//printf("%d", c - '0');
				//scanf("%s", temp);
				if (czf == EOF || czf == '\n')
				{
					break;
				}
				temp[j] = czf;
				j++;
			}
			temp[j] = '\0';
			j = 0;
			(xuey + i)->edwk = atoi(temp);
			strcpy(temp, "\0");
		}
		for (i = 0; i < 8; i++)
		{
			while (1)
			{
				czf = fgetc(old);
				//printf("%d", c - '0');
				//scanf("%s", temp);
				if (czf == EOF || czf == '\n')
				{
					break;
				}
				temp[j] = czf;
				j++;
			}
			temp[j] = '\0';
			j = 0;
			(xuey + i)->mzjs = atoi(temp);
			strcpy(temp, "\0");
		}
		for (i = 0; i < 8; i++)
		{
			while (1)
			{
				czf = fgetc(old);
				if (czf == EOF || czf == '\n')
				{
					break;
				}
				temp[j] = czf;
				j++;
			}
			temp[j] = '\0';
			j = 0;
			strcpy((xuey + i)->tcname, temp);
			strcpy(temp, "\0");
		}
		for (i = 0; i < 8; i++)
		{
			while (1)
			{
				czf = fgetc(old);
				if (czf == EOF || czf == '\n')
				{
					break;
				}
				if (j == 0)
				{
					(xuey + i)->bui = czf - '0';
				}
				else if (j == 1)
				{
					(xuey + i)->flr = czf - '0';
				}
				else
				{
					(xuey + i)->room = czf - '0';
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
					czf = fgetc(old);
					(xuey + i)->t[j][k] = czf - '0';
				}
			}
		}
		fclose(old);
		for (i = 0; i < 8; i++)
		{
			itoa((xuey + i)->stwk, stw[i], 10);
			outtextxy(150, 48 + i * 50, stw[i]);
			itoa((xuey + i)->edwk, edw[i], 10);
			outtextxy(240, 48 + i * 50, edw[i]);
			itoa((xuey + i)->mzjs, evw[i], 10);
			outtextxy(450, 48 + i * 50, evw[i]);
			puthz(315, 48 + i * 50, (xuey + i)->tcname, 24, 24, DARKGRAY);
		}
	}


	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
		MouseS = 0;
		for (i = 0; i < 8; i++)
		{
			if (mouse_press(150, 45 + i * 50, 210, 72 + i * 50) == 2 && jl[i] == 0)
			{
				clrmous(MouseX, MouseY);
				light(150, 45 + i * 50, 210, 72 + i * 50);
				jl[i] = 1;
			}
			else if (mouse_press(150, 45 + i * 50, 210, 72 + i * 50) == 0 && jl[i] == 1)
			{
				clrmous(MouseX, MouseY);
				dark(150, 45 + i * 50, 210, 72 + i * 50);
				jl[i] = 0;
			}

			if (mouse_press(240, 45 + i * 50, 300, 72 + i * 50) == 2 && jl[i+8] == 0)
			{
				clrmous(MouseX, MouseY);
				light(240, 45 + i * 50, 300, 72 + i * 50);
				jl[i+8] = 1;
			}
			else if (mouse_press(240, 45 + i * 50, 300, 72 + i * 50) == 0 && jl[i+8] == 1)
			{
				clrmous(MouseX, MouseY);
				dark(240, 45 + i * 50, 300, 72 + i * 50);
				jl[i+8] = 0;
			}

			if (mouse_press(450, 45 + i * 50, 530, 72 + i * 50) == 2 && jl[i+16] == 0)
			{
				clrmous(MouseX, MouseY);
				light(450, 45 + i * 50, 530, 72 + i * 50);
				jl[i+16] = 1;
			}
			else if (mouse_press(450, 45 + i * 50, 530, 72 + i * 50) == 0 && jl[i+16] == 1)
			{
				clrmous(MouseX, MouseY);
				dark(450, 45 + i * 50, 530, 72 + i * 50);
				jl[i+16] = 0;
			}
		}
		for (i = 0; i < 8; i++)
		{
			if (mouse_press(150, 45 + i * 50, 210, 72 + i * 50) == 2)
			{
				MouseS = 2;
			}
			else if (mouse_press(240, 45 + i * 50, 300, 72 + i * 50) == 2)
			{
				MouseS = 2;
			}
			else if (mouse_press(450, 45 + i * 50, 530, 72 + i * 50) == 2)
			{
				MouseS = 2;
			}
		}
		for (i = 0; i < 8; i++)
		{
			if (mouse_press(150, 45 + i * 50, 210, 72 + i * 50) == 1)
			{
				clrmous(MouseX, MouseY);
				setfillstyle(1, WHITE);
				bar(150, 45 + i * 50, 210, 72 + i * 50);
				input(150, 48+i * 50, &((xuey+i)->stwk));
			}

			else if (mouse_press(240, 45 + i * 50, 300, 72 + i * 50) == 1)
			{
				clrmous(MouseX, MouseY);
				setfillstyle(1, WHITE);
				bar(240, 45 + i * 50, 300, 72 + i * 50);
				input(240, 48 + i * 50, &((xuey + i)->edwk));
			}

			else if (mouse_press(450, 45 + i * 50, 530, 72 + i * 50) == 1&&*ret!=1)
			{
				clrmous(MouseX, MouseY);
				setfillstyle(1, WHITE);
				bar(450, 45 + i * 50, 530, 72 + i * 50);
				input(450, 48 + i * 50, &((xuey + i)->mzjs));
			}
		}
		if(mouse_press(385,50,400,68)==1 && *ret != 1)
		{
			tectemp[0]=tcsel(1,wjf,(xuey)->tcname,xuey, tectemp[0]);
			clrmous(MouseX,MouseY);
		}
		else if(mouse_press(385,50+1*50,400,68+1*50)==1 && *ret != 1)
		{
			tectemp[1]=tcsel(2,xxds,(xuey+1)->tcname,xuey, tectemp[1]);
			clrmous(MouseX,MouseY);
		}
		else if(mouse_press(385,50+2*50,400,68+2*50)==1 && *ret != 1)
		{
			tectemp[2] = tcsel(3,zgyw,(xuey+2)->tcname,xuey, tectemp[2]);
			clrmous(MouseX,MouseY);
		}
		else if(mouse_press(385,50+3*50,400,68+3*50)==1 && *ret != 1)
		{
			tectemp[3] = tcsel(4,zhyy,(xuey+3)->tcname,xuey, tectemp[3]);
			clrmous(MouseX,MouseY);
		}
		else if(mouse_press(385,50+4*50,400,68+4*50)==1 && *ret != 1)
		{
			tectemp[4] = tcsel(5,jsll,(xuey+4)->tcname,xuey, tectemp[4]);
			clrmous(MouseX,MouseY);
		}
		else if(mouse_press(385,50+5*50,400,68+5*50)==1 && *ret != 1)
		{
			tectemp[5] = tcsel(6,sx,(xuey+5)->tcname,xuey, tectemp[5]);
			clrmous(MouseX,MouseY);
		}
		for (i = 0; i < 5; i++)
		{
			if (mouse_press(385, 50 + i * 50, 400, 68 + i * 50) == 2)
			{
				MouseS = 1;
			}
		}
		
		
		if(mouse_press(10,45+8*50,110,72+8*50)==1)
	    {
			if (check(xuey) == 0)
			{
				if (*ret != 1)
				{
					(wjf + tectemp[0])->zt = 1;
					(xxds + tectemp[1])->zt = 1;
					(zgyw + tectemp[2])->zt = 1;
					(zhyy + tectemp[3])->zt = 1;
					(jsll + tectemp[4])->zt = 1;
					(sx + tectemp[5])->zt = 1;
				}
				if (*ret != 1)
				{
					arrange(xuey);
					pos(xuey, num, jil, jszy);
				}
				tiaoz(xuey);
				for (i = 0; i < 8; i++)
				{
					itoa((xuey + i)->stwk, c, 10);
					fputs(c, week);
					fputc('\n', week);
				}
				for (i = 0; i < 8; i++)
				{
					itoa((xuey + i)->edwk, c, 10);
					fputs(c, week);
					fputc('\n', week);
				}
				for (i = 0; i < 8; i++)
				{
					fputc((xuey + i)->mzjs + '0', week);
					fputc('\n', week);
				}
				for (i = 0; i < 8; i++)
				{
					fputs((xuey + i)->tcname, week);
					fputc('\n', week);
				}

				for (i = 0; i < 8; i++)
				{
					fputc((xuey + i)->bui + '0', week);
					fputc((xuey + i)->flr + '0', week);
					fputc((xuey + i)->room + '0', week);
					fputc('\n', week);
				}
				for (i = 0; i < 8; i++)
				{
					for (j = 0; j < 5; j++)
					{
						for (k = 0; k < 2; k++)
						{
							fputc((xuey + i)->t[j][k] + '0', week);
						}
					}
				}
				fclose(week);
				if (*ret == 1)
				{
					sprintf(newtxt, "c:\\ckeshe\\txt\\stwk%d.txt", num);
					remove(newtxt);
					rename("c:\\ckeshe\\txt\\newstw.txt", newtxt);
				}
				*ret = 1;
				return;
			}
			else if(check(xuey)==2)
			{
				puthz(400,157+8*35,"请减少课程数",24,24,YELLOW);
				delay(500);
				setfillstyle(1,GREEN);
				bar(400,157+8*35,560,157+8*35+30);
				continue;
			}
			else
			{
				puthz(400,157+8*35,"排课未完成",24,24,YELLOW);
				delay(500);
				setfillstyle(1,GREEN);
				bar(400,157+8*35,530,157+8*35+30);
				continue;
			}
	    }
	}
}

void input(int x,int y,int* z)
{
	char a;
	char temp[2];
	char str[5];
	int i=0,j=0,left=x;
	int jl[24];
	memset(temp, '\0', sizeof(temp));
	memset(str, '\0', sizeof(str));
	memset(jl, 0, sizeof(jl));
	while(1)
	{
		newmouse(&MouseX, &MouseY, &press);
		MouseS = 0;
		if (mouse_press(0, 0, 640, 480) == 1)
		{
			break;
		}
		for (i = 0; i < 8; i++)
		{
			if (mouse_press(150, 45 + i * 50, 210, 72 + i * 50) == 2 && jl[i] == 0)
			{
				clrmous(MouseX, MouseY);
				light(150, 45 + i * 50, 210, 72 + i * 50);
				jl[i] = 1;
			}
			else if (mouse_press(150, 45 + i * 50, 210, 72 + i * 50) == 0 && jl[i] == 1)
			{
				clrmous(MouseX, MouseY);
				dark(150, 45 + i * 50, 210, 72 + i * 50);
				jl[i] = 0;
			}

			if (mouse_press(240, 45 + i * 50, 300, 72 + i * 50) == 2 && jl[i + 8] == 0)
			{
				clrmous(MouseX, MouseY);
				light(240, 45 + i * 50, 300, 72 + i * 50);
				jl[i + 8] = 1;
			}
			else if (mouse_press(240, 45 + i * 50, 300, 72 + i * 50) == 0 && jl[i + 8] == 1)
			{
				clrmous(MouseX, MouseY);
				dark(240, 45 + i * 50, 300, 72 + i * 50);
				jl[i + 8] = 0;
			}

			if (mouse_press(450, 45 + i * 50, 530, 72 + i * 50) == 2 && jl[i + 16] == 0)
			{
				clrmous(MouseX, MouseY);
				light(450, 45 + i * 50, 530, 72 + i * 50);
				jl[i + 16] = 1;
			}
			else if (mouse_press(450, 45 + i * 50, 530, 72 + i * 50) == 0 && jl[i + 16] == 1)
			{
				clrmous(MouseX, MouseY);
				dark(450, 45 + i * 50, 530, 72 + i * 50);
				jl[i + 16] = 0;
			}
		}

		for (i = 0; i < 8; i++)
		{
			if (mouse_press(150, 45 + i * 50, 210, 72 + i * 50) == 2)
			{
				MouseS = 2;
			}
			else if (mouse_press(240, 45 + i * 50, 300, 72 + i * 50) == 2)
			{
				MouseS = 2;
			}
			else if (mouse_press(450, 45 + i * 50, 530, 72 + i * 50) == 2)
			{
				MouseS = 2;
			}
		}
		for (i = 0; i < 5; i++)
		{
			if (mouse_press(385, 50 + i * 50, 400, 68 + i * 50) == 2)
			{
				MouseS = 1;
			}
		}
		if (kbhit())
		{
			a = getch();
			if (a == '\b'&&x>=left)
			{
				if (j == 0)
				{
					continue;
				}
				setfillstyle(1, WHITE);
				x -= 12;
				bar(x, y, x + 10, y + 23);
				j--;
				str[j] = '\0';
				continue;
			}
			
			else if (x <= left + 50&&a!=13)
			{
				temp[0] = a, temp[1] = '\0';
				str[j] = a;
				j++;
				setcolor(BLACK);
				settextstyle(2, 0, 8);
				clrmous(MouseX, MouseY);
				outtextxy(x, y, temp);
				save_bk_mou(MouseX, MouseY);
				drawmous(MouseX, MouseY);
				x += 12;
			}
			else if (a == 13)
			{
				break;
			}
		}
	}
	str[i]='\0';
	*z=atoi(str);
	return;
}




int check(class*x)
{
	int i,j=0;
	for(i=0;i<8;i++)
	{
		j+=(x+i)->mzjs;
	}
	if(j>18)
	{
		//return 2;
		return 0;
	}
	for(i=0;i<8;i++)
	{
		if((x+i)->stwk==0||(x+i)->edwk==0||(x+i)->tcname[0]=='\0'||(x+i)->mzjs==0)
		{
			//return 1;
			return 0;
		}
	} 
	return 0;
}

void light(int x1,int y1,int x2,int y2)
{
	setcolor(LIGHTCYAN);
	line(x1,y1,x2,y1);
	line(x2,y1,x2,y2);
	line(x2,y2,x1,y2);
	line(x1,y2,x1,y1);
}

void dark(int x1,int y1,int x2,int y2)
{
	setcolor(WHITE);
	line(x1,y1,x2,y1);
	line(x2,y1,x2,y2);
	line(x2,y2,x1,y2);
	line(x1,y2,x1,y1);
}

void arrange(class *xy)
{
	int i, j, k, h, g = 1;
	int jl[20]={0};
	jl[7] = 1, jl[15] = 1;
	h = (int)time(NULL);
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < (xy + i)->mzjs; j++)
		{
			(xy + i)->t[j][0] = g;
			change(&g);
			srand(h);
			h++;
			(xy + i)->t[j][1] = rand() % 4 + 1;
			k = ((xy + i)->t[j][0] - 1) * 4 + (xy + i)->t[j][1] - 1;
			while (jl[k] == 1)
			{
				(xy + i)->t[j][1]++;
				if ((xy + i)->t[j][1] > 4)
				{
					(xy + i)->t[j][1] -= 4;
				}
				//k++;
				k = ((xy + i)->t[j][0] - 1) * 4 + (xy + i)->t[j][1] - 1;
			}
			jl[k] = 1;
		}
	}
}


void change(int *g)
{
	(*g)+=2;
	if((*g)>5)
	{
		(*g)-=5;
	}
}