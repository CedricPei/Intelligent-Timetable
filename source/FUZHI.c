#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>
#include<string.h> 
#include"stu.h"
#include"mouse.h"
#include"hz.h"
#include"fuzhi.h"

void fuzhi(class*aia,class*jx,class*gd,class*sk,class*ch,char **pbc)
{
	int i,j,k;
	char c;
	/*memset(&aia, 0, sizeof(class));
	memset(&jx, 0, sizeof(class));
	memset(&gd, 0, sizeof(class));
	memset(&sk, 0, sizeof(class));
	memset(&ch, 0, sizeof(class));*/
	for (i = 0; i < 10; i++)
	{
		memset((aia + i)->tcname, '\0', sizeof((aia + i)->tcname));
		memset((aia + i)->cname, '\0', sizeof((aia + i)->cname));
		(aia + i)->stwk = 0;
		(aia + i)->edwk = 0;
		(aia + i)->mzjs = 0;
		(aia + i)->zfhz = 0;
		(aia + i)->bui = 0;
		(aia + i)->flr = 0;
		(aia + i)->room = 0;
		(aia + i)->color = 0;
		(aia + i)->kcnum = 0;
	}

	for (i = 0; i < 10; i++)
	{
		memset((jx + i)->tcname, '\0', sizeof((jx + i)->tcname));
		memset((jx + i)->cname, '\0', sizeof((jx + i)->cname));
		(jx + i)->stwk = 0;
		(jx + i)->edwk = 0;
		(jx + i)->mzjs = 0;
		(jx + i)->zfhz = 0;
		(jx + i)->bui = 0;
		(jx + i)->flr = 0;
		(jx + i)->room = 0;
		(jx + i)->color = 0;
		(jx + i)->kcnum = 0;
	}

	for (i = 0; i < 10; i++)
	{
		memset((gd + i)->tcname, '\0', sizeof((gd + i)->tcname));
		memset((gd + i)->cname, '\0', sizeof((gd + i)->cname));
		(gd + i)->stwk = 0;
		(gd + i)->edwk = 0;
		(gd + i)->mzjs = 0;
		(gd + i)->zfhz = 0;
		(gd + i)->bui = 0;
		(gd + i)->flr = 0;
		(gd + i)->room = 0;
		(gd + i)->color = 0;
		(gd + i)->kcnum = 0;
	}

	for (i = 0; i < 10; i++)
	{
		memset((ch + i)->tcname, '\0', sizeof((ch + i)->tcname));
		memset((ch + i)->cname, '\0', sizeof((ch + i)->cname));
		(ch + i)->stwk = 0;
		(ch + i)->edwk = 0;
		(ch + i)->mzjs = 0;
		(ch + i)->zfhz = 0;
		(ch + i)->bui = 0;
		(ch + i)->flr = 0;
		(ch + i)->room = 0;
		(ch + i)->color = 0;
		(ch + i)->kcnum = 0;
	}

	for (i = 0; i < 10; i++)
	{
		memset((sk + i)->tcname, '\0', sizeof((sk + i)->tcname));
		memset((sk + i)->cname, '\0', sizeof((sk + i)->cname));
		(sk + i)->stwk = 0;
		(sk + i)->edwk = 0;
		(sk + i)->mzjs = 0;
		(sk + i)->zfhz = 0;
		(sk + i)->bui = 0;
		(sk + i)->flr = 0;
		(sk + i)->room = 0;
		(sk + i)->color = 0;
		(sk + i)->kcnum = 0;
	}
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 5; j++)
		{
			(aia + i)->t[j][0] = 0;
			(aia + i)->t[j][1] = 0;
			(jx + i)->t[j][0] = 0;
			(jx + i)->t[j][1] = 0;
			(gd + i)->t[j][0] = 0;
			(gd + i)->t[j][1] = 0;
			(sk + i)->t[j][0] = 0;
			(sk + i)->t[j][1] = 0;
			(ch + i)->t[j][0] = 0;
			(ch + i)->t[j][1] = 0;
		}
	}
	strcpy(aia[6].cname,"������ͼ"),strcpy(aia[7].cname,"C"),strcpy(aia[6].tcname,"�ú굤"),strcpy(aia[7].tcname,"�߳���"),aia[7].zfhz=1;
	strcpy(jx[6].cname,"��е���"),strcpy(jx[7].cname,"C++"),strcpy(jx[6].tcname,"����"),strcpy(jx[7].tcname,"����");
	strcpy(gd[6].cname,"������ͼ"),strcpy(gd[7].cname,"�������"),strcpy(gd[6].tcname,"�ν�Ӣ"),strcpy(gd[7].tcname,"Ф����");
	strcpy(sk[6].cname,"������ͼ"),strcpy(sk[7].cname,"������ѧ"),strcpy(sk[6].tcname,"�ƽ��"),strcpy(sk[7].tcname,"��Ԫ��");
	strcpy(ch[6].cname,"��е���"),strcpy(ch[7].cname,"C++"),strcpy(ch[6].tcname,"������"),strcpy(ch[7].tcname,"����"), ch[7].zfhz=1;
	strcpy(aia[8].cname,"����"),strcpy(aia[9].cname,"ѡ��"); 
	strcpy(jx[8].cname,"����"),strcpy(jx[9].cname,"ѡ��");
	strcpy(gd[8].cname,"����"),strcpy(gd[9].cname,"ѡ��");
	strcpy(sk[8].cname,"����"),strcpy(sk[9].cname,"ѡ��");
	strcpy(ch[8].cname,"����"),strcpy(ch[9].cname,"ѡ��");
	(aia+7)->zfhz=1,(jx+7)->zfhz=1,(ch+7)->zfhz=1;
	for(i=0;i<=5;i++)
	{
		strcpy(aia[i].cname,pbc[i]);
		strcpy(jx[i].cname,pbc[i]);
		strcpy(gd[i].cname,pbc[i]);
		strcpy(sk[i].cname,pbc[i]);
		strcpy(ch[i].cname,pbc[i]);
	} 
	
	aia->color=1;//��ɫ 
	(aia+1)->color=2;
	(aia+2)->color=3;
	(aia+3)->color=4;
	(aia+4)->color=5;
	(aia+5)->color=6;
	(aia+6)->color=8;
	(aia+7)->color=9;
	(aia+8)->color=7;
	(aia+9)->color=7;
	
	(aia+8)->stwk=1,(aia+8)->edwk=19;
	(aia+9)->stwk=1,(aia+9)->edwk=19;
	(aia + 8)->t[0][0] = 2, (aia + 8)->t[0][1] = 4, (aia + 8)->mzjs = 1;
	(aia + 9)->t[0][0] = 4, (aia + 9)->t[0][1] = 4, (aia + 9)->mzjs = 1;
	
	 gd->color=1;//��ɫ 
	(gd+1)->color=2;
	(gd+2)->color=3;
	(gd+3)->color=4;
	(gd+4)->color=5;
	(gd+5)->color=6;
	(gd+6)->color=8;
	(gd+7)->color=9;
	(gd+8)->color=7;
	(gd+9)->color=7;
	
	(gd+8)->stwk=1,(gd+8)->edwk=19;
	(gd+9)->stwk=1,(gd+9)->edwk=19;
	(gd + 8)->t[0][0] = 2, (gd + 8)->t[0][1] = 4, (gd + 8)->mzjs = 1;
	(gd + 9)->t[0][0] = 4, (gd + 9)->t[0][1] = 4, (gd + 9)->mzjs = 1;
	
	 jx->color=1;//��ɫ 
	(jx+1)->color=2;
	(jx+2)->color=3;
	(jx+3)->color=4;
	(jx+4)->color=5;
	(jx+5)->color=6;
	(jx+6)->color=8;
	(jx+7)->color=9;
	(jx+8)->color=7;
	(jx+9)->color=7;
	
	(jx+8)->stwk=1,(jx+8)->edwk=19;
	(jx+9)->stwk=1,(jx+9)->edwk=19;
	(jx + 8)->t[0][0] = 2, (jx + 8)->t[0][1] = 4, (jx + 8)->mzjs = 1;
	(jx + 9)->t[0][0] = 4, (jx + 9)->t[0][1] = 4, (jx + 9)->mzjs = 1;
	
	 sk->color=1;//��ɫ 
	(sk+1)->color=2;
	(sk+2)->color=3;
	(sk+3)->color=4;
	(sk+4)->color=5;
	(sk+5)->color=6;
	(sk+6)->color=8;
	(sk+7)->color=9;
	(sk+8)->color=7;
	(sk+9)->color=7;
	
	(sk+8)->stwk=1,(sk+8)->edwk=19;
	(sk+9)->stwk=1,(sk+9)->edwk=19;
	(sk + 8)->t[0][0] = 2, (sk + 8)->t[0][1] = 4, (sk + 8)->mzjs = 1;
	(sk + 9)->t[0][0] = 4, (sk + 9)->t[0][1] = 4, (sk + 9)->mzjs = 1;
	
	 ch->color=1;//��ɫ 
	(ch+1)->color=2;
	(ch+2)->color=3;
	(ch+3)->color=4;
	(ch+4)->color=5;
	(ch+5)->color=6;
	(ch+6)->color=8;
	(ch+7)->color=9;
	(ch+8)->color=7;
	(ch+9)->color=7;
	
	(ch+8)->stwk=1,(ch+8)->edwk=19;
	(ch+9)->stwk=1,(ch+9)->edwk=19;
	(ch + 8)->t[0][0] = 2, (ch + 8)->t[0][1] = 4, (ch + 8)->mzjs = 1;
	(ch + 9)->t[0][0] = 4, (ch + 9)->t[0][1] = 4, (ch + 9)->mzjs = 1;
}
