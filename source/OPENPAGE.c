#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include "openpage.h"

void openpage()
{
  //setcolor(LIGHTBLUE);
	setfillstyle(1, LIGHTBLUE);
	bar(0, 0, 1023, 767);
  setfillstyle(1,WHITE);
  pieslice(320,240,0,360,230);
  setfillstyle(1,YELLOW);
  pieslice(230,140,0,180,35);
  bar(195,140,265,340);
  setcolor(YELLOW);
  rectangle(195,140,265,340);
  pieslice(230,340,180,360,35);
  setcolor(DARKGRAY);
  setfillstyle(1,DARKGRAY);
  pieslice(320,140,0,360,35);
  circle(320,140,35);
  setfillstyle(1,GREEN);
  setcolor(GREEN);
  pieslice(320,240,0,180,35);
  pieslice(320,340,180,360,35);
  rectangle(285,240,355,340);
  bar(285,240,355,340);
  setfillstyle(1,RED);
  setcolor(RED);
  circle(410,340,35);
  pieslice(410,340,0,360,35);
  setfillstyle(1,LIGHTBLUE);
  setcolor(LIGHTBLUE);
  pieslice(410,240,180,360,35);
  pieslice(410,140,0,180,35);
  rectangle(375,140,445,240);
  bar(375,140,445,240);
  delay(500);
  clearviewport();
}
