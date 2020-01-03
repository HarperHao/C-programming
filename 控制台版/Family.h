#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<string.h>
#include<stdlib.h>
#include<mmsystem.h>
#include<windows.h>
#include<math.h>
typedef struct Date {
	int year;//年
	int month;//月
	int day;//日
}Date;
typedef struct Tree_Node {
	char name[20];//姓名
	char sex[5];//性别
	int height;//身高
	char occupation[20];//职业
	char education[20];//受教育程度 
	char parent_name[20];//父亲姓名，用于添加节点时用 
	int Depth;//二叉树深度,第几代人,输出二叉树时用 
	char address[20];//家庭住址
	int child_num;//孩子数
	Date birthDate;//出生日期
	int x;//x坐标
	int y;//y坐标
	struct Tree_Node *firstchild, *sibling, *parent;
}Tree_Node;
typedef Tree_Node *person;

//-----------------链式队列-------------------//用队列来辅助树的功能
typedef struct QNode {
	person data;//每一个树节点的指针
	struct QNode *next;
}QNode;
typedef struct {
	QNode *rear, *front;
}Queue;
/////////////////////////////////函数的声明//////////////
Queue *init();
int empty(Queue*);
void EnQueue(Queue *, person);
person DelQueue(Queue *);
void save(person);//将数据保存到文件中去
void save1(person , FILE*);
void save2(person, FILE *);
person  Find(person, char name[]);
void biaoti(int x, int y, int nHeight, int nWidth);
void First_Window();//第一个界面
void  Find_name(person T, char name[]);//找到姓名为name的人并输出他的相关信息
void Find_sex(person T, char sex[]);//找到所有性别男或女的人并输出他们的相关信息
void Find_occupation(person T, char occupation[]);
void Find_education(person T, char education[]);
person creat(char *fileName);
void AddNewNode(person T);
int isFamily(person T, char *s);
void numOfFamily(person T, int sum[20]);//统计每一层的结点个数
int  Depth(person T);//整棵树的高度
int Max(int x, int y);//两个树的最大值
void view(person T);
void draw_circle(person m);
Queue * Get_AllNode(person T);
void init_position(person T);
void displaytree(person T);
void menu1();
void Mouse_Pos();
void save3(person T, FILE *fp);