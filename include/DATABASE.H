#ifndef _DATABASE_H_
#define _DATABASE_H_


typedef struct admininfo
{
	char user[15];//6-12位，管理员账号
	char password[10];//8位密码
}ADMIN;

typedef  struct goods
{
	char name[15];              //物资名称
	char num[10];               //捐赠需求量
	char ber[10];               //已捐赠数量
	char use[30];               //物资用途
	char ti[11];                //申请时间
	char addres[20];            //捐赠地址
	char flag ;                 //用来判断审核
}UZI;

typedef struct complain
{
	char name[15];//接收人
	char con[200];//内容
	char t[11];//写信时间
}CA;


typedef struct shoujuan
{
	char wzname[15]; //受捐物资名称
	char ti[11];//捐赠时间
	char num[10];//受捐量
	char t[11];//项目发起时间
	char name[15];//捐赠人
}SJ;

typedef struct juanzeng
{
	char wzname[15]; //受捐物资名称
	char ti[11];//接受捐赠时间
	char num[10];//捐赠量
	char t[11];//项目发起时间
	char use[30];//使用情况
	char name[15];//受捐人
}JZ;

typedef struct Node		//快速排序法
{
	int num;			//用户序号
	int order;			//该节点所储存物资位于文件中的偏移量位置
	long int Element ;   //时间
	UZI q; 				 //该节点所储存的申请物资
	struct Node* Next;
} *List, * Position;

#endif
