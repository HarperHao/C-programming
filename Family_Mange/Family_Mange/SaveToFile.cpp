#include "Family.h"
#include"global.h"
void save(person T)//把祖先结点T传进来
{
	loadimage(NULL, _T("1.jpg"));
	settextstyle(20, 0, _T("楷体"));
	FILE *fp;
	fp = fopen("JiaPu.txt", "w");
	if (fp == NULL)
	{
		TCHAR s0[] = _T("家谱文件不存在！");
		outtextxy(400, 200, s0);
	}
	else
	{
		save1(T, fp);
		fclose(fp);
		TCHAR s1[] = _T("家谱文件保存成功！");
		outtextxy(400, 200, s1);
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
void save1(person T, FILE* fp)//保存所有成员信息函数,按照树的层次遍历存入文件中
{
	Queue *q;
	q = init();//初始化一个队列
	if (T != NULL)
	{
		save3(T, fp); 
		EnQueue(q, T);//入队
		while (!empty(q))//如果队列不为空的话
		{
			person x, y;
			y = DelQueue(q);//出队
			x = y->firstchild;
			while (x)
			{
				save2(x, fp);
				EnQueue(q, x);//入队
				x = x->sibling;//指向它的兄
			}
		}
	}
}
void save2(person T, FILE *fp)//保存一个成员信息函数,保存其他结点
{
	fprintf(fp,"\n%s %s %d %s %s %s %d %d %d %d",T->name,T->sex,T->height,T->occupation,T->education,T->address,T->child_num,T->birthDate.year, T->birthDate.month, T->birthDate.day);
}
void save3(person T, FILE *fp)//专门用来保存第一个结点
{
	fprintf(fp, "%s %s %d %s %s %s %d %d %d %d", T->name, T->sex, T->height, T->occupation, T->education, T->address, T->child_num, T->birthDate.year, T->birthDate.month, T->birthDate.day);
}
