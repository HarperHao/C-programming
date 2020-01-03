#include<string.h>
#include"Family.h"
person  Find(person T, char name[])
{
	
	Queue *q;
	int flag=-2;
	person m = T;
	person n = NULL;
	q = init();//初始化一个队列
	if (T == NULL)
	{
		printf("没有创建祖先！\n");
		return NULL;
	}
	else//二叉树的层序遍历
	{
		EnQueue(q, m);//入队操作
		while (!empty(q))//队列不空时
		{
			n = DelQueue(q);//出队
			if (strcmp(n->name, name) == 0)//找到了
				return n;
			else//继续往下找
			{
				if (n->firstchild != NULL)
					EnQueue(q, n->firstchild);
				if (n->sibling != NULL)
					EnQueue(q, n->sibling);
			}
		}
		printf("在族谱中没有找到%s\n", name);
		return NULL;
	}
}
