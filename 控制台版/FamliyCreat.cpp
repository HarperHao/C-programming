#include<stdio.h>
#include"Family.h"
#include<string.h>
person creat(char *fileName)//从文件读取数据创建一个族谱
{
	FILE *fp = fopen(fileName, "r");
	if (!fp)
	{
		printf("文件打开失败!\n");
		return NULL;
	}
	int i;
	Queue *q = init();
	person T = NULL, T1, T2, T3;
	while (!feof(fp))//检测是否文件末尾
	{
		if (!T)
		{
			T = T2 = (person)malloc(sizeof(Tree_Node));
			fscanf_s(fp, "%s", T->name, 20);
			fscanf_s(fp, "%s", T->sex, 20);
			fscanf(fp, "%d", &T->height);
			fscanf_s(fp, "%s", T->occupation, 20);
			fscanf_s(fp, "%s", T->education, 20);
			T->parent_name[0] = '\0';//祖先无父亲姓名
			fscanf(fp, "%d", &T->child_num);
			T->Depth = 1;//祖先为第一代
			fscanf_s(fp, "%s", T->address, 20);
			fscanf_s(fp, "%d", &T->child_num);
			fscanf_s(fp, "%d", &T->birthDate.year);
			fscanf_s(fp, "%d", &T->birthDate.month);
			fscanf_s(fp, "%d", &T->birthDate.day);
			T->firstchild = NULL;//孩子结点先置空
			T->sibling = NULL;//祖先无兄弟结点
			T->parent = NULL;//祖先无父母结点
		}
		else
		{
			i = T2->child_num;//i作为链接父亲与孩子的控制变量
			while (i--)
			{
				T1 = (person)malloc(sizeof(Tree_Node));
				fscanf_s(fp, "%s", T1->name, 20);
				fscanf_s(fp, "%s", T1->sex, 20);
				fscanf(fp, "%d", &T1->height);
				fscanf_s(fp, "%s", T1->occupation, 20);
				fscanf_s(fp, "%s", T1->education, 20);
				strcpy(T1->parent_name, T2->name);//T2为父亲结点
				fscanf(fp, "%d", &T1->child_num);
				T1->Depth = T2->Depth + 1;
				fscanf_s(fp, "%s", T1->address, 20);
				fscanf_s(fp, "%d", &T1->child_num);
				fscanf_s(fp, "%d", &T1->birthDate.year);
				fscanf_s(fp, "%d", &T1->birthDate.month);
				fscanf_s(fp, "%d", &T1->birthDate.day);
				T1->firstchild = NULL;//孩子结点先置空
				T1->parent = T2;
				T1->sibling = NULL;//兄弟结点先置空
				if (!T2->firstchild)
				{
					T2->firstchild = T1;
					T3 = T2->firstchild;//T3为了链接兄弟结点
				}
				else
				{
					T3->sibling = T1;
					T3 = T3->sibling;
				}
				if (T1->child_num)
					EnQueue(q, T1);
			}
			T2 = DelQueue(q);
		}
	}
	fclose(fp);
	return T;
}
int isFamily(person T, char *s)//判断成员是否在族谱中
{
	if (Find(T, s))
		return 1;//在
	else
		return 0;//不在
}
//int main()
//{
//	person T;
//	int sum[20] = {0};
//	char filename[] = "JiaPu.txt";
//	T = creat(filename);
//	numOfFamily(T, sum);
//	for (int i = 0; sum[i] != 0; i++)
//		printf("%d ", sum[i]);
//	system("pause");
//	return 0;
//}