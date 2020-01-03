#include"Family.h"
#include<string.h>
void  Find_name(person T, char name[])
{
	Queue *q;
	int flag = -2;
	person m = T;
	person n = NULL;
	q = init();//��ʼ��һ������
	if (T == NULL)
	{
		printf("û�д������ȣ�\n");
	}
	else//�������Ĳ������
	{
		EnQueue(q, m);//��Ӳ���
		while (!empty(q))//���в���ʱ
		{
			n = DelQueue(q);//����
			if (strcmp(n->name, name) == 0)//�ҵ���
			{
				printf("����:%s �Ա�:%s ���:%d ������:%d ְҵ:%s �ܽ����̶�:%s ��������:%s ��%d���� ��ͥסַ:%s ��������:%d��%d��%d��\n", n->name, n->sex, n->height, n->child_num, n->occupation, n->education, n->parent_name,n->Depth,n->address, n->birthDate.year, n->birthDate.month, n->birthDate.day);
				return;
			}
			else//����������
			{
				if (n->firstchild != NULL)
					EnQueue(q, n->firstchild);
				if (n->sibling != NULL)
					EnQueue(q, n->sibling);
			}
		}
		printf("��������û���ҵ�%s\n", name);
	}
	
}
void Find_sex(person T, char sex[])
{

	Queue *q;
	person n = NULL;
	q = init();
	int flag = 0;
	if (T == NULL)
	{
		printf("û�д������ȣ�\n");
	}
	else
	{
		q = Get_AllNode(T);
		while (!empty(q))//�����в���ʱ
		{
			n=DelQueue(q);//������
			if (strcmp(n->sex, sex) == 0)
			{
				printf("����:%s �Ա�:%s ���:%d ������:%d ְҵ:%s �ܽ����̶�:%s ��������:%s ��%d���� ��ͥסַ:%s ��������:%d��%d��%d��\n", n->name, n->sex, n->height, n->child_num, n->occupation, n->education, n->parent_name, n->Depth, n->address, n->birthDate.year, n->birthDate.month, n->birthDate.day);
				flag++;
			}
		}
		if (flag == 0)
		{
			printf("û���ҵ��Ա�Ϊ%s���ˣ�", sex);
		}
	}	
	
}
void Find_occupation(person T, char occupation[])
	{
	Queue *q;
	person n = NULL;
	q = init();
	int flag = 0;
	if (T == NULL)
	{
		printf("û�д������ȣ�\n");
	}
	else
	{
		q = Get_AllNode(T);
		while (!empty(q))//�����в���ʱ
		{
			n = DelQueue(q);//������
			if (strcmp(n->occupation, occupation) == 0)
			{
				printf("����:%s �Ա�:%s ���:%d ������:%d ְҵ:%s �ܽ����̶�:%s ��������:%s ��%d���� ��ͥסַ:%s ��������:%d��%d��%d��\n", n->name, n->sex, n->height, n->child_num, n->occupation, n->education, n->parent_name, n->Depth, n->address, n->birthDate.year, n->birthDate.month, n->birthDate.day);
				flag++;
			}
		}
		if (flag == 0)
		{
			printf("û���ҵ�ְҵΪ%s���ˣ�",occupation);
		}
	}
	
	}
void Find_education(person T, char education[])
{
	Queue *q;
	person n = NULL;
	q = init();
	int flag = 0;
	if (T == NULL)
	{
		printf("û�д������ȣ�\n");
	}
	else
	{
		q = Get_AllNode(T);
		while (!empty(q))//�����в���ʱ
		{
			n = DelQueue(q);//������
			if (strcmp(n->education, education) == 0)
			{
				printf("����:%s �Ա�:%s ���:%d ������:%d ְҵ:%s �ܽ����̶�:%s ��������:%s ��%d���� ��ͥסַ:%s ��������:%d��%d��%d��\n", n->name, n->sex, n->height, n->child_num, n->occupation, n->education, n->parent_name, n->Depth, n->address, n->birthDate.year, n->birthDate.month, n->birthDate.day);
				flag++;
			}
		}
		if (flag == 0)
		{
			printf("û���ҵ�ְҵΪ%s���ˣ�", education);
		}
	}
}
void Decide(person T)
{
	int choice_num;
	char search_name[20];
	char search_sex[5];
	char search_occupation[20];
	char search_education[20];
	menu1();
		scanf_s("%d", &choice_num);
		switch (choice_num)
		{
		case 1:
			system("cls");
			printf("������Ҫ���ҵ�������\n");
			fflush(stdin);
			scanf_s("%s", search_name,20);
			Find_name(T, search_name);
			printf("\n\t\t�밴���������!");
			getchar();
			break;
		case 2:
			system("cls");
			printf("������Ҫ���ҵ��Ա�(��/Ů)��\n");
			fflush(stdin);
			scanf_s("%s", search_sex,5);
			Find_sex(T, search_sex);
			printf("\n\t\t�밴���������!");
			getchar();
			break;
		case 3:
			system("cls");
			printf("������Ҫ���ҵ�ְҵ��\n");
			fflush(stdin);
			scanf_s("%s", search_occupation,20);
			Find_sex(T, search_occupation);
			printf("\n\t\t�밴���������!");
			getchar();
			break;
		case 4:
			system("cls");
			printf("������Ҫ���ҵ�ѧ����\n");
			fflush(stdin);
			scanf_s("%s", search_education,20);
			Find_education(T, search_education);
			printf("\n\t\t�밴���������!");
			getchar();
			break;
		case 0:
			printf("\n\t\t�밴������˳�����ϵͳ");
			getchar();
			return;
		default:
			printf("\n\t\t�������󣡰����������");
			getchar();
		}
}
void menu1()
{

	/*TCHAR s1[] = _T("*******************************");
	TCHAR s2[] = _T("********** 1. ��������*********");
	TCHAR s3[] = _T("********** 2. �����Ա�*********");
	TCHAR s4[] = _T("********** 3. ����ְҵ*********");
	TCHAR s5[] = _T("********** 4. ����ѧ��*********");
	TCHAR s6[] = _T("********** 0.�˳��˹���********");
	TCHAR s7[] = _T("*******************************");
	outtextxy(300, 100, s1);
	outtextxy(300, 140, s2);
	outtextxy(300, 180, s3);
	outtextxy(300, 220, s4);
	outtextxy(300, 260, s5);
	outtextxy(300, 300, s6);
	outtextxy(300, 340, s7);*/
	
	printf("\n\t\t*******************************\n");
	printf("\n\t\t******\t 1. ��������      ******\n");
	printf("\n\t\t******\t 2  �����Ա�      ******\n");
	printf("\n\t\t******\t 3. ����ְҵ     ******\n");
	printf("\n\t\t******\t 4. ����ѧ��       ******\n");
	printf("\n\t\t******\t 0. �˳��˹���     ******\n");
	printf("\n\t\t*******************************\n");
	printf("�������Ӧ��������Ӧ�����֣�1-5��:\n");

}


