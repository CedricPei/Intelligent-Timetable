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
	int rec=0,i,r,x=0,j;           //rec用于记录列表为展开还是收起状态 
	static int re[5];
	
	FILE* k;
	char cy;
	int jl[20] ;
	int jszy[90];
	
	char*s[5]={"人工智能与自动化",
	           "机械",
			   "光电",
			   "生命科学",
			   "船海"}; 
	tec wjf[5]={                  //微积分 
	                   {0,"何涛"},
	                   {0,"吴洁"},
	                   {0,"金建华"},
	                   {0,"韩志斌"},
	                   {0,"吴娥子"}};
	tec xxds[5]={                //线性代数 
	                   {0,"潘灯"},
	                   {0,"谢松法"},
	                   {0,"肖吉福"},
	                   {0,"邹猛"},
	                   {0,"彭丽"}};
	tec jsll[5]={               //军事理论 
	                   {0,"朱平"},
	                   {0,"丁鼎"},
	                   {0,"谭静"},
	                   {0,"曹金梅"},
	                   {0,"刘欢"}};
	tec sx[5]={                //思修 
	                   {0,"吴漾"},
	                   {0,"梁红"},
	                   {0,"李建国"},
	                   {0,"邹从清"},
	                   {0,"阮丽萍"}};
	tec zgyw[5]={             //中国语文 
	                   {0,"骆琳"},
	                   {0,"涂慧"},
	                   {0,"齐晓燕"},
	                   {0,"李传印"},
	                   {0,"谭杉杉"}};
	tec zhyy111[5]={             //综合英语 
	                   {0,"黄婷"},
	                   {0,"张兰玲"},
	                   {0,"何欣"},
	                   {0,"胡先立"},
	                   {0,"刘月琴"}};

	tec zhyy[5] = {             //综合英语 
					   {0,"黄婷"},
					   {0,"张兰玲"},
					   {0,"何欣"},
					   {0,"胡先立"},
					   {0,"刘月琴"} };
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
			puthz(273, 157 + 8 * 35, "返回", 24, 75, BLACK);
	        x=1;
		}
		
		else if(mouse_press(248,156+8*35-10,398,185+8*35)==0&&x==1)
		{
			clrmous(MouseX,MouseY);
			setfillstyle(1,YELLOW);
			bar(248,156+8*35-10,398,185+8*35);
			puthz(273, 157 + 8 * 35, "返回", 24, 75, BLACK);
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
	puthz(198,156,"请选择学院",24,24,BLACK);
	setfillstyle(1,YELLOW);
	bar(248,156+8*35-10,398,185+8*35);
	puthz(273,157+8*35,"返回",24,75,BLACK);
}


