#include<string.h>
#include"Family.h"
person  Find(person T, char name[])
{
	
	Queue *q;
	int flag=-2;
	person m = T;
	person n = NULL;
	q = init();//��ʼ��һ������
	if (T == NULL)
	{
		printf("û�д������ȣ�\n");
		return NULL;
	}
	else//�������Ĳ������
	{
		EnQueue(q, m);//��Ӳ���
		while (!empty(q))//���в���ʱ
		{
			n = DelQueue(q);//����
			if (strcmp(n->name, name) == 0)//�ҵ���
				return n;
			else//����������
			{
				if (n->firstchild != NULL)
					EnQueue(q, n->firstchild);
				if (n->sibling != NULL)
					EnQueue(q, n->sibling);
			}
		}
		printf("��������û���ҵ�%s\n", name);
		return NULL;
	}
}
