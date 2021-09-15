#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>
#include<string.h> 
#include<time.h>
#include"mouse.h"
#include"hz.h"
#include"select.h"


int tcsel(int a,tec *cl,char*n,class*x,int nownum)
{
	int i;
	setcolor(BLACK);
	setlinestyle(0,0,3);
	setfillstyle(1,WHITE);
	line(315,72,405,72);
	clrmous(MouseX,MouseY);
	delay(200);
	for(i=1;i<6;i++)
	{
		line(315,72+(a-1)*50,405,72+(a-1)*50);
		bar(315,45+i*27+(a-1)*50,405,72+i*27+(a-1)*50);
		line(315,72+i*27+(a-1)*50,405,72+i*27+(a-1)*50);
		if((cl+i-1)->zt==1)
		{
			puthz(315,48+i*27+(a-1)*50,(cl+i-1)->tname,24,24,DARKGRAY);
		}
		else
		{
			puthz(315,48+i*27+(a-1)*50,(cl+i-1)->tname,24,24,BLACK);
		}
	}
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
		if(mouse_press(315,45+1*27+(a-1)*50,405,72+1*27+(a-1)*50)==1&&(cl)->zt!=1)
	    {
	    	clrmous(MouseX,MouseY);
		    strcpy(n,(cl)->tname);
		    puthz(315,48+(a-1)*50,n,24,24,BLACK);
		    //(cl)->zt=1;
		    setfillstyle(1,GREEN);
		    bar(315,45,405,767);
		    setfillstyle(1,WHITE);
		    for(i=0;i<8;i++)
		    {
		       bar(315,45+i*50,405,72+i*50);
			   puthz(315, 48 + i * 50, (x + i)->tcname, 24, 24, BLACK);
		       /*if(((x+i)->tcname[0])!='\0')
		       {
		   	      puthz(315,48+i*50,(x+i)->tcname,24,24,BLACK);
		       }*/	
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
		    return 0;
     	}
    	else if(mouse_press(315,45+2*27+(a-1)*50,405,72+2*27+(a-1)*50)==1&&(cl+1)->zt!=1)
	    {
	    	clrmous(MouseX,MouseY);
		    strcpy(n,(cl+1)->tname);
		    puthz(315,48+(a-1)*50,n,24,24,BLACK);
		    //(cl+1)->zt=1;
		    setfillstyle(1, GREEN);
		    bar(315,45,405,767);
	    	setfillstyle(1,WHITE);
		    for(i=0;i<8;i++)
		    {
		       bar(315,45+i*50,405,72+i*50);
		       if(((x+i)->tcname[0])!='\0')
		       {
		   	      puthz(315,48+i*50,(x+i)->tcname,24,24, BLACK);
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
		    return 1;	
     	}
	    else if(mouse_press(315,45+3*27+(a-1)*50,405,72+3*27+(a-1)*50)==1&&(cl+2)->zt!=1)
    	{
    		clrmous(MouseX,MouseY);
		    strcpy(n,(cl+2)->tname);
		    puthz(315,48+(a-1)*50,n,24,24,BLACK);
		   // (cl+2)->zt=1;
		    setfillstyle(1, GREEN);
	    	bar(315,45,405,767);
		    setfillstyle(1,WHITE);
	    	for(i=0;i<8;i++)
	    	{
	    	   bar(315,45+i*50,405,72+i*50);
	    	   if(((x+i)->tcname[0])!='\0')
	    	   {
	    	   	  puthz(315,48+i*50,(x+i)->tcname,24,24, BLACK);
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
	    	return 2;
	    }
	    else if(mouse_press(315,45+4*27+(a-1)*50,405,72+4*27+(a-1)*50)==1&&(cl+3)->zt!=1)
	    {
	    	clrmous(MouseX,MouseY);
	    	strcpy(n,(cl+3)->tname);
	     	puthz(315,48+(a-1)*50,n,24,24,BLACK);
	    	//(cl+3)->zt=1;
	    	setfillstyle(1, GREEN);
	    	bar(315,45,405,767);
	    	setfillstyle(1,WHITE);
	    	for(i=0;i<8;i++)
	    	{
	    	   bar(315,45+i*50,405,72+i*50);
	    	   if(((x+i)->tcname[0])!='\0')
	    	   {
	    	   	  puthz(315,48+i*50,(x+i)->tcname,24,24, BLACK);
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
	    	return 3;
	    }
	    else if(mouse_press(315,45+5*27+(a-1)*50,405,72+5*27+(a-1)*50)==1&&(cl+4)->zt!=1)
	    {
	    	clrmous(MouseX,MouseY);
	    	strcpy(n,(cl+4)->tname);
	    	puthz(315,48+(a-1)*50,n,24,24,BLACK);
	    	//(cl+4)->zt=1;
	    	setfillstyle(1, GREEN);
	    	bar(315,45,405,767);
	    	setfillstyle(1,WHITE);
	    	for(i=0;i<8;i++)
	    	{
	    	   bar(315,45+i*50,405,72+i*50);
	    	   if(((x+i)->tcname[0])!='\0')
	    	   {
	    	   	  puthz(315,48+i*50,(x+i)->tcname,24,24, BLACK);
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
	    	return 4;
	    }
	    if(mouse_press(385,50+(a-1)*50,400,68+(a-1)*50)==1)
	    {
	    	clrmous(MouseX,MouseY);
	    	setfillstyle(1, GREEN);
	    	bar(315,45,405,767);
	    	setfillstyle(1,WHITE);
	    	for(i=0;i<8;i++)
	    	{
	    	   bar(315,45+i*50,405,72+i*50);
	    	   if(((x+i)->tcname[0])!='\0')
	    	   {
	    	   	  puthz(315,48+i*50,(x+i)->tcname,24,24, BLACK);
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
			delay(200);
	    	return nownum;
	    }	
	}
}
