#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>
#include<string.h> 
#include<time.h>
#include"mouse.h"
#include"hz.h"
#include"tc.h"
#include"paike.h"

void tcmode(class *aia,class*jx,class*gd,class*sk,class*ch,char**pbc)
{
	int rec=0,i,r,x=0,j;           //rec���ڼ�¼�б�Ϊչ����������״̬ 
	static int re[5];
	
	FILE* k;
	char cy;
	int jl[20] ;
	int jszy[90];
	
	char*s[5]={"�˹��������Զ���",
	           "��е",
			   "���",
			   "������ѧ",
			   "����"}; 
	tec wjf[5]={                  //΢���� 
	                   {0,"����"},
	                   {0,"���"},
	                   {0,"�𽨻�"},
	                   {0,"��־��"},
	                   {0,"�����"}};
	tec xxds[5]={                //���Դ��� 
	                   {0,"�˵�"},
	                   {0,"л�ɷ�"},
	                   {0,"Ф����"},
	                   {0,"����"},
	                   {0,"����"}};
	tec jsll[5]={               //�������� 
	                   {0,"��ƽ"},
	                   {0,"����"},
	                   {0,"̷��"},
	                   {0,"�ܽ�÷"},
	                   {0,"����"}};
	tec sx[5]={                //˼�� 
	                   {0,"����"},
	                   {0,"����"},
	                   {0,"���"},
	                   {0,"�޴���"},
	                   {0,"����Ƽ"}};
	tec zgyw[5]={             //�й����� 
	                   {0,"����"},
	                   {0,"Ϳ��"},
	                   {0,"������"},
	                   {0,"�ӡ"},
	                   {0,"̷ɼɼ"}};
	tec zhyy111[5]={             //�ۺ�Ӣ�� 
	                   {0,"����"},
	                   {0,"������"},
	                   {0,"����"},
	                   {0,"������"},
	                   {0,"������"}};

	tec zhyy[5] = {             //�ۺ�Ӣ�� 
					   {0,"����"},
					   {0,"������"},
					   {0,"����"},
					   {0,"������"},
					   {0,"������"} };
	memset(re, 0, sizeof(re));
	memset(jl, 0, sizeof(jl));
	memset(jszy, 0, sizeof(jszy));
	                   
	if ((k = fopen("c:\\ckeshe\\txt\\class.txt", "rt+")) == NULL)
	{
		printf("cannot open class.txt");
	}
	for (i = 0; i < 5; i++)
	{
		cy = fgetc(k);
		(wjf + i)->zt = cy - '0';
	}
	for (i = 0; i < 5; i++)
	{
		cy = fgetc(k);
		(xxds + i)->zt = cy - '0';
	}
	for (i = 0; i < 5; i++)
	{
		cy = fgetc(k);
		(jsll +i)->zt = cy - '0';
	}
	for (i = 0; i < 5; i++)
	{
		cy = fgetc(k);
		(sx + i)->zt = cy - '0';
	}
	for (i = 0; i < 5; i++)
	{
		cy = fgetc(k);
		(zgyw + i)->zt = cy - '0';
	}
	for (i = 0; i < 5; i++)
	{
		cy = fgetc(k);
		(zhyy + i)->zt = cy - '0';
	}
	for (i = 0; i < 5; i++)
	{
		cy = fgetc(k);
		re[i] = cy - '0';
	}
	fclose(k);           
	                   
	clrmous(MouseX,MouseY);
	
	viewinit();
    delay(200);
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
		if(mouse_press(408,155,438,177)==1&&rec==0)
		{
			rec=1,r=0;
			//viewinit(r, re, s);
			switch (r)
			{
			case 0:
				setfillstyle(1, WHITE);
				setlinestyle(0, 0, 3);
				line(198, 185, 448, 185);
				for (i = 1; i < 6; i++)
				{
					bar(198, 150 + i * 35, 448, 185 + i * 35);
					puthz(198, 156 + i * 35, s[i - 1], 24, 24, BLACK);
					line(198, 185 + i * 35, 448, 185 + i * 35);
				}
				break;

			case 1:
				setfillstyle(1, GREEN);
				bar(198, 185, 448, 375);
				break;
			}
			delay(200);
			//goto XZ;
		}
		
		else if(mouse_press(198,185,448,220)==1&&rec==1)
		{
			delay(150);
			pk(1,&re[0],aia,pbc,wjf,xxds,jsll,sx,zgyw,zhyy,jl,jszy);
			if ((k = fopen("c:\\ckeshe\\txt\\class.txt", "w")) == NULL)
	        {
		        printf("cannot open class.txt");
        	}
            for(i=0;i<5;i++)
            {
            	fputc((wjf+i)->zt+'0',k);
			}
			for(i=0;i<5;i++)
            {
            	fputc((xxds+i)->zt+'0',k);
			}
			for(i=0;i<5;i++)
            {
            	fputc((jsll+i)->zt+'0',k);
			}
			for(i=0;i<5;i++)
            {
            	fputc((sx+i)->zt+'0',k);
			}
			for(i=0;i<5;i++)
            {
            	fputc((zgyw+i)->zt+'0',k);
			}
			for(i=0;i<5;i++)
            {
            	fputc((zhyy+i)->zt+'0',k);
			}
			for (i = 0; i < 5; i++)
			{
				fputc(re[i] + '0', k);
			}
			fclose(k);
			r=1;
			viewinit();
			delay(200); 
			//goto XZ;
		}
		
		else if(mouse_press(198,220,448,255)==1&&rec==1)
		{
			pk(2,&re[1],jx,pbc,wjf,xxds,jsll,sx,zgyw,zhyy,jl,jszy);
			if ((k = fopen("c:\\ckeshe\\txt\\class.txt", "w")) == NULL)
	        {
		        printf("cannot open class.txt");
        	}
            for(i=0;i<5;i++)
            {
            	fputc((wjf+i)->zt+'0',k);
			}
			for(i=0;i<5;i++)
            {
            	fputc((xxds+i)->zt+'0',k);
			}
			for(i=0;i<5;i++)
            {
            	fputc((jsll+i)->zt+'0',k);
			}
			for(i=0;i<5;i++)
            {
            	fputc((sx+i)->zt+'0',k);
			}
			for(i=0;i<5;i++)
            {
            	fputc((zgyw+i)->zt+'0',k);
			}
			for(i=0;i<5;i++)
            {
            	fputc((zhyy+i)->zt+'0',k);
			}
			for (i = 0; i < 5; i++)
			{
				fputc(re[i] + '0', k);
			}
			fclose(k);
			r=1;
			viewinit();
			delay(200);
			//goto XZ;
		}
		
		else if(mouse_press(198,255,448,290)==1&&rec==1)
		{
			pk(3,&re[2],gd,pbc,wjf,xxds,jsll,sx,zgyw,zhyy,jl,jszy);
			if ((k = fopen("c:\\ckeshe\\txt\\class.txt", "w")) == NULL)
	        {
		        printf("cannot open class.txt");
        	}
            for(i=0;i<5;i++)
            {
            	fputc((wjf+i)->zt+'0',k);
			}
			for(i=0;i<5;i++)
            {
            	fputc((xxds+i)->zt+'0',k);
			}
			for(i=0;i<5;i++)
            {
            	fputc((jsll+i)->zt+'0',k);
			}
			for(i=0;i<5;i++)
            {
            	fputc((sx+i)->zt+'0',k);
			}
			for(i=0;i<5;i++)
            {
            	fputc((zgyw+i)->zt+'0',k);
			}
			for(i=0;i<5;i++)
            {
            	fputc((zhyy+i)->zt+'0',k);
			}
			for (i = 0; i < 5; i++)
			{
				fputc(re[i] + '0', k);
			}
			fclose(k);
			r=1;
			viewinit();
			delay(200);
			//goto XZ;
		}
		
		else if(mouse_press(198,290,448,325)==1&&rec==1)
		{
			pk(4,&re[3],sk,pbc,wjf,xxds,jsll,sx,zgyw,zhyy,jl,jszy);
			if ((k = fopen("c:\\ckeshe\\txt\\class.txt", "w")) == NULL)
	        {
		        printf("cannot open class.txt");
        	}
            for(i=0;i<5;i++)
            {
            	fputc((wjf+i)->zt+'0',k);
			}
			for(i=0;i<5;i++)
            {
            	fputc((xxds+i)->zt+'0',k);
			}
			for(i=0;i<5;i++)
            {
            	fputc((jsll+i)->zt+'0',k);
			}
			for(i=0;i<5;i++)
            {
            	fputc((sx+i)->zt+'0',k);
			}
			for(i=0;i<5;i++)
            {
            	fputc((zgyw+i)->zt+'0',k);
			}
			for(i=0;i<5;i++)
            {
            	fputc((zhyy+i)->zt+'0',k);
			}
			for (i = 0; i < 5; i++)
			{
				fputc(re[i] + '0', k);
			}
			fclose(k);
			r=1;
			viewinit();
			delay(200);
			//goto XZ;
		}
		
		else if(mouse_press(198,325,448,360)==1&&rec==1)
		{
			pk(5,&re[4],ch,pbc,wjf,xxds,jsll,sx,zgyw,zhyy,jl,jszy);
			if ((k = fopen("c:\\ckeshe\\txt\\class.txt", "w")) == NULL)
	        {
		        printf("cannot open class.txt");
        	}
            for(i=0;i<5;i++)
            {
            	fputc((wjf+i)->zt+'0',k);
			}
			for(i=0;i<5;i++)
            {
            	fputc((xxds+i)->zt+'0',k);
			}
			for(i=0;i<5;i++)
            {
            	fputc((jsll+i)->zt+'0',k);
			}
			for(i=0;i<5;i++)
            {
            	fputc((sx+i)->zt+'0',k);
			}
			for(i=0;i<5;i++)
            {
            	fputc((zgyw+i)->zt+'0',k);
			}
			for(i=0;i<5;i++)
            {
            	fputc((zhyy+i)->zt+'0',k);
			}
			for (i = 0; i < 5; i++)
			{
				fputc(re[i] + '0', k);
			}
			fclose(k);
			r=1;
			viewinit();
			delay(200);
			//goto XZ;
		}
		
		else if(mouse_press(408,155,438,177)==1&&rec==1)
		{
			rec=0,r=1;
			//viewinit(r, re, s);
			switch (r)
			{
			case 0:
				setfillstyle(1, WHITE);
				setlinestyle(0, 0, 3);
				line(198, 185, 448, 185);
				for (i = 1; i < 6; i++)
				{
					bar(198, 150 + i * 35, 448, 185 + i * 35);
					if (re[i - 1] == 0)
					{
						puthz(198, 156 + i * 35, s[i - 1], 24, 24, BLACK);
					}
					else
					{
						puthz(198, 156 + i * 35, s[i - 1], 24, 24, DARKGRAY);
					}
					line(198, 185 + i * 35, 448, 185 + i * 35);
				}
				break;

			case 1:
				setfillstyle(1, GREEN);
				bar(198, 185, 448, 375);
				break;
			}
			delay(200);
			//goto XZ;
		}
		
		else if(mouse_press(248,156+8*35-10,398,185+8*35)==1)
		{
			//arrange(aia,jx,gd,sk,ch);
			//pos(aia,jx,gd,sk,ch);
			break;
		}
		
		else if(mouse_press(248,156+8*35-10,398,185+8*35)==2&&x==0)
		{
			clrmous(MouseX,MouseY);
			setfillstyle(1,LIGHTCYAN);
			bar(248,156+8*35-10,398,185+8*35);
			puthz(273, 157 + 8 * 35, "����", 24, 75, BLACK);
	        x=1;
		}
		
		else if(mouse_press(248,156+8*35-10,398,185+8*35)==0&&x==1)
		{
			clrmous(MouseX,MouseY);
			setfillstyle(1,YELLOW);
			bar(248,156+8*35-10,398,185+8*35);
			puthz(273, 157 + 8 * 35, "����", 24, 75, BLACK);
	        x=0;
		}
		
		if(mouse_press(408,155,438,177)==2)
		{
			MouseS=1;
		}
		
		else if(mouse_press(408,155,438,177)==0)
		{
			MouseS=0;
		}
	}
	return;
}

void viewinit()
{
	clearviewport();
	//mouseinit();
	clrmous(MouseX,MouseY);
	setfillstyle(1,GREEN);
	bar(0,0,1023,767);
	setfillstyle(1,WHITE);
	bar(198,150,448,185);
	setcolor(BLACK);
	setfillstyle(1,BLACK);
	moveto(408,155);
	lineto(438,155);
	lineto(423,177);
	lineto(408,155);
	floodfill(423,160,BLACK);
	puthz(198,156,"��ѡ��ѧԺ",24,24,BLACK);
	setfillstyle(1,YELLOW);
	bar(248,156+8*35-10,398,185+8*35);
	puthz(273,157+8*35,"����",24,75,BLACK);
}

