#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<string.h>
#include<stdlib.h>
#include<mmsystem.h>
#include<windows.h>
#include<math.h>
typedef struct Date {
	int year;//��
	int month;//��
	int day;//��
}Date;
typedef struct Tree_Node {
	char name[20];//����
	char sex[5];//�Ա�
	int height;//���
	char occupation[20];//ְҵ
	char education[20];//�ܽ����̶� 
	char parent_name[20];//����������������ӽڵ�ʱ�� 
	int Depth;//���������,�ڼ�����,���������ʱ�� 
	char address[20];//��ͥסַ
	int child_num;//������
	Date birthDate;//��������
	int x;//x����
	int y;//y����
	struct Tree_Node *firstchild, *sibling, *parent;
}Tree_Node;
typedef Tree_Node *person;

//-----------------��ʽ����-------------------//�ö������������Ĺ���
typedef struct QNode {
	person data;//ÿһ�����ڵ��ָ��
	struct QNode *next;
}QNode;
typedef struct {
	QNode *rear, *front;
}Queue;
/////////////////////////////////����������//////////////
Queue *init();
int empty(Queue*);
void EnQueue(Queue *, person);
person DelQueue(Queue *);
void save(person);//�����ݱ��浽�ļ���ȥ
void save1(person , FILE*);
void save2(person, FILE *);
person  Find(person, char name[]);
void biaoti(int x, int y, int nHeight, int nWidth);
void First_Window();//��һ������
void  Find_name(person T, char name[]);//�ҵ�����Ϊname���˲�������������Ϣ
void Find_sex(person T, char sex[]);//�ҵ������Ա��л�Ů���˲�������ǵ������Ϣ
void Find_occupation(person T, char occupation[]);
void Find_education(person T, char education[]);
person creat(char *fileName);
void AddNewNode(person T);
int isFamily(person T, char *s);
void numOfFamily(person T, int sum[20]);//ͳ��ÿһ��Ľ�����
int  Depth(person T);//�������ĸ߶�
int Max(int x, int y);//�����������ֵ
void view(person T);
void draw_circle(person m);
Queue * Get_AllNode(person T);
void init_position(person T);
void displaytree(person T);
void menu1();
void Mouse_Pos();
void save3(person T, FILE *fp);