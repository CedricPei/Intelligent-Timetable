#ifndef _test_h_
#define _test_h_



typedef struct class
{
 int xynum;//ѧԺ��� 12345
 int kcnum;//�γ̱�� 12345678
 char cname[10];//�γ����� 
 int stwk;//��ʼ�� 
 int edwk;//������ 
 char tcname[10];//��ʦ���� 
 int mzjs;//ÿ�ܽ��� 
 int zfhz;//�γ�����Ϊ�ַ�/���� 
 int bui;//�Ͽεص�      1234-����ABCD 5-��ʮ�� 
 int flr;
 int room;
 int t[5][2];//�Ͽ�ʱ��
 int color;//����ģʽ�е���ʾ��ɫ 
}class;

typedef struct tec
{
	int zt;//ռ��״̬ 
	char tname[10];//��ʦ���� 
}tec;

typedef struct USER
{
	int xy;//����ѧԺ
	char xuehao[11]; //ѧ��
	char mima[20];//���� 
}USER;

typedef struct snake
{
	int posi[2];
	struct snake *next;
	struct snake *last;
}snake;

typedef struct OUTU
{
	char oname[20];//�ǳ�
	char code[20];//���� 
}OUTU;
#endif
