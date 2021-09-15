#ifndef _test_h_
#define _test_h_



typedef struct class
{
 int xynum;//学院编号 12345
 int kcnum;//课程编号 12345678
 char cname[10];//课程名称 
 int stwk;//开始周 
 int edwk;//结束周 
 char tcname[10];//教师名称 
 int mzjs;//每周节数 
 int zfhz;//课程名称为字符/汉字 
 int bui;//上课地点      1234-东九ABCD 5-东十二 
 int flr;
 int room;
 int t[5][2];//上课时间
 int color;//运行模式中的显示颜色 
}class;

typedef struct tec
{
	int zt;//占用状态 
	char tname[10];//教师姓名 
}tec;

typedef struct USER
{
	int xy;//所属学院
	char xuehao[11]; //学号
	char mima[20];//密码 
}USER;

typedef struct snake
{
	int posi[2];
	struct snake *next;
	struct snake *last;
}snake;

typedef struct OUTU
{
	char oname[20];//昵称
	char code[20];//密码 
}OUTU;
#endif
