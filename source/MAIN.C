#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>
#include<string.h> 
#include<time.h>
#include"stu.h"
#include"mouse.h"
#include"hz.h"
#include"page1.h"
#include"tc.h"
#include"paike.h"
#include"test.h"
#include"run.h"
#include"fuzhi.h"
#include"openpage.h"

void main()
{
 int choose=0;
 char*pbclass[6]={
                "微积分",
				"线性代数",
				"中国语文",
			    "综合英语",
				"军事理论",
				"思修" 
                };
 class aia[10],jx[10],gd[10],sk[10],ch[10];//5个学院 
 OUTU outu[20];
 int grd=VGA,gm=VGAHI;
 initgraph(&grd,&gm,"C:\\BORLANDC\\BGI");
 openpage();
 mouseinit();
 fuzhi(aia,jx,gd,sk,ch,pbclass);
 while(1)
 {
 	switch(choose)
 	{
 		case 0:
 		clrmous(MouseX,MouseY);
 		firstpage(&choose);
 		continue;
 		
 		case 1:
 		delay(200);
 		tcmode(aia,jx,gd,sk,ch,pbclass);
 		clearviewport();
 		choose=0;
 		break;
 		
 		case 2:
 		delay(200);
 		stumode(aia,jx,gd,sk,ch);
 		clearviewport();
 		choose=0;
 		break;
 		
 		case 3:
         clrmous(MouseX, MouseY);
         outmode(outu);
         clearviewport();
         choose = 0;
         break;

        case 5:
		 closegraph();
         delay(1000);
		 exit(1); 
	}
 }
 
}
