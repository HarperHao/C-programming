#include<stdio.h>
#include"Family.h"
#include<string.h>
person creat(char *fileName)//���ļ���ȡ���ݴ���һ������
{
	FILE *fp = fopen(fileName, "r");
	if (!fp)
	{
		printf("�ļ���ʧ��!\n");
		return NULL;
	}
	int i;
	Queue *q = init();
	person T = NULL, T1, T2, T3;
	while (!feof(fp))//����Ƿ��ļ�ĩβ
	{
		if (!T)
		{
			T = T2 = (person)malloc(sizeof(Tree_Node));
			fscanf_s(fp, "%s", T->name, 20);
			fscanf_s(fp, "%s", T->sex, 20);
			fscanf(fp, "%d", &T->height);
			fscanf_s(fp, "%s", T->occupation, 20);
			fscanf_s(fp, "%s", T->education, 20);
			T->parent_name[0] = '\0';//�����޸�������
			fscanf(fp, "%d", &T->child_num);
			T->Depth = 1;//����Ϊ��һ��
			fscanf_s(fp, "%s", T->address, 20);
			fscanf_s(fp, "%d", &T->child_num);
			fscanf_s(fp, "%d", &T->birthDate.year);
			fscanf_s(fp, "%d", &T->birthDate.month);
			fscanf_s(fp, "%d", &T->birthDate.day);
			T->firstchild = NULL;//���ӽ�����ÿ�
			T->sibling = NULL;//�������ֵܽ��
			T->parent = NULL;//�����޸�ĸ���
		}
		else
		{
			i = T2->child_num;//i��Ϊ���Ӹ����뺢�ӵĿ��Ʊ���
			while (i--)
			{
				T1 = (person)malloc(sizeof(Tree_Node));
				fscanf_s(fp, "%s", T1->name, 20);
				fscanf_s(fp, "%s", T1->sex, 20);
				fscanf(fp, "%d", &T1->height);
				fscanf_s(fp, "%s", T1->occupation, 20);
				fscanf_s(fp, "%s", T1->education, 20);
				strcpy(T1->parent_name, T2->name);//T2Ϊ���׽��
				fscanf(fp, "%d", &T1->child_num);
				T1->Depth = T2->Depth + 1;
				fscanf_s(fp, "%s", T1->address, 20);
				fscanf_s(fp, "%d", &T1->child_num);
				fscanf_s(fp, "%d", &T1->birthDate.year);
				fscanf_s(fp, "%d", &T1->birthDate.month);
				fscanf_s(fp, "%d", &T1->birthDate.day);
				T1->firstchild = NULL;//���ӽ�����ÿ�
				T1->parent = T2;
				T1->sibling = NULL;//�ֵܽ�����ÿ�
				if (!T2->firstchild)
				{
					T2->firstchild = T1;
					T3 = T2->firstchild;//T3Ϊ�������ֵܽ��
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
int isFamily(person T, char *s)//�жϳ�Ա�Ƿ���������
{
	if (Find(T, s))
		return 1;//��
	else
		return 0;//����
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