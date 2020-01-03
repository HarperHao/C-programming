#include"Family.h"
#include"global.h"
extern person T;
extern int stop1;
void AddNewNode()//添加一名成员
{
	loadimage(NULL, _T("1.jpg"));
	setbkmode(TRANSPARENT);
	settextcolor(BLACK);
	settextstyle(20, 0, _T("楷体"));
	if (stop1 == 0)
	{
		person T1, T2;
			int i=0;
			char a[20];
			T1 = (person)malloc(sizeof(Tree_Node));
			InputBox(a, 20, "请输入新添加成员的父亲或母亲姓名:   ");
			T2 = Find(a);
			while (!T2)
			{
				InputBox(a, 20, "此人的父亲或母亲姓名不存在，请重新输入！");
				T2 = Find(a);
			}
			T1->parent = T2;
			T2->child_num++;
			strcpy(T1->parent_name, T2->name);
			if (T2->firstchild)//父母结点的第一个儿子不为空
			{
				T2 = T2->firstchild;
				while (T2->sibling)
					T2 = T2->sibling;
				T2->sibling = T1;
				T1->Depth = T2->Depth;
				T1->firstchild = NULL;
				T1->sibling = NULL;
			}
			else
			{
				T1->Depth = T2->Depth + 1;//代数为父亲代数加一
				T2->firstchild = T1;
				T1->sibling = NULL;
				T1->firstchild = NULL;
			}
			InputBox(T1->name, 20, "请输入成员姓名:");
			char s6[20];
			InputBox(s6, 20, "请输入成员性别:(1代表男,0代表女)");//
			sscanf(s6, "%d", &i);//将字符转化为数字
			i ? strcpy(T1->sex, "男") : strcpy(T1->sex, "女");
			char s7[20];
			InputBox(s7, 20, "请输入成员身高:");
			sscanf(s7, "%d", &T1->height);
			InputBox(T1->occupation, 20, "请输入成员职业:");
			InputBox(T1->education, 20, "请输入成员受教育程度:");
			InputBox(T1->address, 20, "请输入成员家庭住址:");
			T1->child_num = 0;//新加入成员孩子数默认为0
			char s10[20];
			InputBox(s10, 20, "请输入成员出生所在年份:");
			sscanf(s10, "%d.", &T1->birthDate.year);
			char s11[20];
			InputBox(s11, 20, "请输入成员出生所在月份:");
			sscanf(s11, "%d", &T1->birthDate.month);
			char s12[20];
			InputBox(s12, 20, "请输入成员出生所在日子:");
			sscanf(s12, "%d", &T1->birthDate.day);
			stop1 = 1;
	}
	if (isMouseDown&&mouseX < 85 && mouseX>0 && mouseY < 35 && mouseY>0)
	{
		GamePhase = 0;
	}
	else
	{
		//设置返回主菜单按纽
		setfillcolor(RGB(240, 248, 255));
		setlinecolor(RGB(119, 136, 153));
		fillrectangle(0, 0, 80, 30);
		settextstyle(15, 0, _T("楷体"));
		TCHAR s0[] = _T("返回菜单");
		outtextxy(10, 10, s0);
	}
}