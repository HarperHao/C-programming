#include "Family.h"
#include <stdio.h>
#include <stdlib.h>
void save(person T)//�����Ƚ��T������
{
	/*char del_filename[10] = "JiaPu.txt";
	remove(del_filename);*/
	FILE *fp;
	fp = fopen("JiaPu.txt", "w");
	if (fp == NULL)
	{
		printf("�����ļ������ڣ�\n");
		return;
	}
	else
	{
		
		save1(T, fp);
		fclose(fp);
		printf("���ױ���ɹ���\n");
		return;
	}
}
void save1(person T, FILE* fp)//�������г�Ա��Ϣ����,�������Ĳ�α��������ļ���
{
	Queue *q;
	q = init();//��ʼ��һ������
	if (T != NULL)
	{
		save3(T, fp); 
		EnQueue(q, T);//���
		while (!empty(q))//������в�Ϊ�յĻ�
		{
			person x, y;
			y = DelQueue(q);//����
			x = y->firstchild;
			while (x)
			{
				save2(x, fp);
				EnQueue(q, x);//���
				x = x->sibling;//ָ��������
			}
		}
	}
}
void save2(person T, FILE *fp)//����һ����Ա��Ϣ����,�����������
{
	//fwrite(T, sizeof(Tree_Node), 1, fp);//��һ�������д���ļ���ȥ
	fprintf(fp,"\n%s %s %d %s %s %s %d %d %d %d",T->name,T->sex,T->height,T->occupation,T->education,T->address,T->child_num,T->birthDate.year, T->birthDate.month, T->birthDate.day);
}
void save3(person T, FILE *fp)//ר�����������һ�����
{
	fprintf(fp, "%s %s %d %s %s %s %d %d %d %d", T->name, T->sex, T->height, T->occupation, T->education, T->address, T->child_num, T->birthDate.year, T->birthDate.month, T->birthDate.day);

}
