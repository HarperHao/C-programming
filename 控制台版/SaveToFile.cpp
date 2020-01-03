#include "Family.h"
#include <stdio.h>
#include <stdlib.h>
void save(person T)//把祖先结点T传进来
{
	/*char del_filename[10] = "JiaPu.txt";
	remove(del_filename);*/
	FILE *fp;
	fp = fopen("JiaPu.txt", "w");
	if (fp == NULL)
	{
		printf("家谱文件不存在！\n");
		return;
	}
	else
	{
		
		save1(T, fp);
		fclose(fp);
		printf("家谱保存成功！\n");
		return;
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
	//fwrite(T, sizeof(Tree_Node), 1, fp);//将一个树结点写入文件中去
	fprintf(fp,"\n%s %s %d %s %s %s %d %d %d %d",T->name,T->sex,T->height,T->occupation,T->education,T->address,T->child_num,T->birthDate.year, T->birthDate.month, T->birthDate.day);
}
void save3(person T, FILE *fp)//专门用来保存第一个结点
{
	fprintf(fp, "%s %s %d %s %s %s %d %d %d %d", T->name, T->sex, T->height, T->occupation, T->education, T->address, T->child_num, T->birthDate.year, T->birthDate.month, T->birthDate.day);

}
