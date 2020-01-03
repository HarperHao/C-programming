#include"Family.h"
#include<string.h>
void  Find_name(person T, char name[])
{
	Queue *q;
	int flag = -2;
	person m = T;
	person n = NULL;
	q = init();//初始化一个队列
	if (T == NULL)
	{
		printf("没有创建祖先！\n");
	}
	else//二叉树的层序遍历
	{
		EnQueue(q, m);//入队操作
		while (!empty(q))//队列不空时
		{
			n = DelQueue(q);//出队
			if (strcmp(n->name, name) == 0)//找到了
			{
				printf("姓名:%s 性别:%s 身高:%d 孩子数:%d 职业:%s 受教育程度:%s 父亲姓名:%s 第%d代人 家庭住址:%s 出生日期:%d年%d月%d日\n", n->name, n->sex, n->height, n->child_num, n->occupation, n->education, n->parent_name,n->Depth,n->address, n->birthDate.year, n->birthDate.month, n->birthDate.day);
				return;
			}
			else//继续往下找
			{
				if (n->firstchild != NULL)
					EnQueue(q, n->firstchild);
				if (n->sibling != NULL)
					EnQueue(q, n->sibling);
			}
		}
		printf("在族谱中没有找到%s\n", name);
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
		printf("没有创建祖先！\n");
	}
	else
	{
		q = Get_AllNode(T);
		while (!empty(q))//当队列不空时
		{
			n=DelQueue(q);//出队列
			if (strcmp(n->sex, sex) == 0)
			{
				printf("姓名:%s 性别:%s 身高:%d 孩子数:%d 职业:%s 受教育程度:%s 父亲姓名:%s 第%d代人 家庭住址:%s 出生日期:%d年%d月%d日\n", n->name, n->sex, n->height, n->child_num, n->occupation, n->education, n->parent_name, n->Depth, n->address, n->birthDate.year, n->birthDate.month, n->birthDate.day);
				flag++;
			}
		}
		if (flag == 0)
		{
			printf("没有找到性别为%s的人！", sex);
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
		printf("没有创建祖先！\n");
	}
	else
	{
		q = Get_AllNode(T);
		while (!empty(q))//当队列不空时
		{
			n = DelQueue(q);//出队列
			if (strcmp(n->occupation, occupation) == 0)
			{
				printf("姓名:%s 性别:%s 身高:%d 孩子数:%d 职业:%s 受教育程度:%s 父亲姓名:%s 第%d代人 家庭住址:%s 出生日期:%d年%d月%d日\n", n->name, n->sex, n->height, n->child_num, n->occupation, n->education, n->parent_name, n->Depth, n->address, n->birthDate.year, n->birthDate.month, n->birthDate.day);
				flag++;
			}
		}
		if (flag == 0)
		{
			printf("没有找到职业为%s的人！",occupation);
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
		printf("没有创建祖先！\n");
	}
	else
	{
		q = Get_AllNode(T);
		while (!empty(q))//当队列不空时
		{
			n = DelQueue(q);//出队列
			if (strcmp(n->education, education) == 0)
			{
				printf("姓名:%s 性别:%s 身高:%d 孩子数:%d 职业:%s 受教育程度:%s 父亲姓名:%s 第%d代人 家庭住址:%s 出生日期:%d年%d月%d日\n", n->name, n->sex, n->height, n->child_num, n->occupation, n->education, n->parent_name, n->Depth, n->address, n->birthDate.year, n->birthDate.month, n->birthDate.day);
				flag++;
			}
		}
		if (flag == 0)
		{
			printf("没有找到职业为%s的人！", education);
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
			printf("请输入要查找的姓名：\n");
			fflush(stdin);
			scanf_s("%s", search_name,20);
			Find_name(T, search_name);
			printf("\n\t\t请按任意键继续!");
			getchar();
			break;
		case 2:
			system("cls");
			printf("请输入要查找的性别(男/女)：\n");
			fflush(stdin);
			scanf_s("%s", search_sex,5);
			Find_sex(T, search_sex);
			printf("\n\t\t请按任意键继续!");
			getchar();
			break;
		case 3:
			system("cls");
			printf("请输入要查找的职业：\n");
			fflush(stdin);
			scanf_s("%s", search_occupation,20);
			Find_sex(T, search_occupation);
			printf("\n\t\t请按任意键继续!");
			getchar();
			break;
		case 4:
			system("cls");
			printf("请输入要查找的学历：\n");
			fflush(stdin);
			scanf_s("%s", search_education,20);
			Find_education(T, search_education);
			printf("\n\t\t请按任意键继续!");
			getchar();
			break;
		case 0:
			printf("\n\t\t请按任意键退出操作系统");
			getchar();
			return;
		default:
			printf("\n\t\t输入有误！按任意键继续");
			getchar();
		}
}
void menu1()
{

	/*TCHAR s1[] = _T("*******************************");
	TCHAR s2[] = _T("********** 1. 查找姓名*********");
	TCHAR s3[] = _T("********** 2. 查找性别*********");
	TCHAR s4[] = _T("********** 3. 查找职业*********");
	TCHAR s5[] = _T("********** 4. 查找学历*********");
	TCHAR s6[] = _T("********** 0.退出此功能********");
	TCHAR s7[] = _T("*******************************");
	outtextxy(300, 100, s1);
	outtextxy(300, 140, s2);
	outtextxy(300, 180, s3);
	outtextxy(300, 220, s4);
	outtextxy(300, 260, s5);
	outtextxy(300, 300, s6);
	outtextxy(300, 340, s7);*/
	
	printf("\n\t\t*******************************\n");
	printf("\n\t\t******\t 1. 查找姓名      ******\n");
	printf("\n\t\t******\t 2  查找性别      ******\n");
	printf("\n\t\t******\t 3. 查找职业     ******\n");
	printf("\n\t\t******\t 4. 查找学历       ******\n");
	printf("\n\t\t******\t 0. 退出此功能     ******\n");
	printf("\n\t\t*******************************\n");
	printf("请输入对应功能所对应的数字（1-5）:\n");

}


