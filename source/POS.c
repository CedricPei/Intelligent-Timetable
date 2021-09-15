#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>
#include<string.h> 
#include<time.h>
#include"mouse.h"
#include"hz.h"
#include"pos.h"

void pos(class *aia,int num,int *jl,int *jszy)//安排上课地点 
{
	int a = 1, p=0, i=0,j=0;//a用于更换随机种子  
	char c;
	a = (int)time(NULL);
	p = rand() % 20;//公共课 
	while (jl[p] == 1)//自动化 
	{
		changep(&p);
	}
	jl[p] = 1;
	a++;
	srand(a);
	for (i = 0; i < 3; i++)
	{
		(aia + i)->bui = ((p - p % 10)) / 10 + 2;
		(aia + i)->flr = (p % 10 - (p % 10 % 2)) / 2 + 1;
		(aia + i)->room = p % 2 + 1;
	}

	p = rand() % 20;
	while (jl[p] == 1)
	{
		changep(&p);
	}
	jl[p] = 1;
	a++;
	srand(a);
	for (i = 3; i < 6; i++)
	{
		(aia + i)->bui = ((p - p % 10)) / 10 + 2;
		(aia + i)->flr = (p % 10 - (p % 10 % 2)) / 2 + 1;
		(aia + i)->room = p % 2 + 1;
	}
		for (i = 6; i <= 7; i++)//自动化 
	{
		p = rand() % 90;
		while (jszy[p] == 1)
		{
			p++;
			if (p > 89)
			{
				p -= 90;
			}
		}
		jszy[p] = 1;
		a++;
		srand(a);
		(aia + i)->bui = (p - p % 45) / 45 + 4;
		(aia + i)->flr = (p % 45 - (p % 45 % 9)) / 9 + 1;
		(aia + i)->room = p % 9 + 1;
	}
}

void changep(int *p)
{
	(*p)++;
	if((*p)>19)
	{
		(*p)-=20;
	}
}
