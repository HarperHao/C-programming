#include"Family.h"
#include"global.h"
extern person T;
extern int stop2;
extern int stop3;
extern int stop4;
extern int stop5;
void  Find_name(char name[])
{
	int flag = 0;
	char search_name[20];
	loadimage(NULL, _T("1.jpg"));
	setbkmode(TRANSPARENT);
	settextcolor(BLACK);
	settextstyle(20, 0, _T("����"));
	Queue *q;
	person m = T;
	person n = NULL;
	q = init();//��ʼ��һ������

	if (T == NULL)
	{
		TCHAR s9[] = _T("û�д������ȣ�");
		outtextxy(300, 100, s9);
	}
	else//�������Ĳ������
	{
		TCHAR s13[] = _T("����:");
		outtextxy(100, 80, s13);
		TCHAR s14[] = _T("�Ա�");
		outtextxy(100, 100, s14);
		TCHAR s15[] = _T("��ߣ�");
		outtextxy(100, 120, s15);
		TCHAR s16[] = _T("��������");
		outtextxy(100, 140, s16);
		TCHAR s17[] = _T("ְҵ��");
		outtextxy(100, 160, s17);
		TCHAR s18[] = _T("ѧ����");
		outtextxy(100, 180, s18);
		TCHAR s19[] = _T("�������֣�");
		outtextxy(100, 200, s19);
		TCHAR s21[] = _T("�ڼ�����");
		outtextxy(100, 220, s21);
		TCHAR s22[] = _T("��ס�أ�");
		outtextxy(100, 240, s22);
		TCHAR s23[] = _T("����������:");
		outtextxy(100, 260, s23);
		EnQueue(q, m);//��Ӳ���
		while (!empty(q))//���в���ʱ
		{
			n = DelQueue(q);//����
			if (strcmp(n->name, name) == 0)//�ҵ���
			{
				settextstyle(20, 0, _T("����"));
				char s9[20];//����һ���ַ�����
				strcpy(s9, n->name);//��n->name����һ���˵����֣���ֵ�����s9�ַ�������ȥ
				outtextxy(160, 80, s9);//��ָ��λ���������˵�����
				char s8[20];
				strcpy(s8, n->sex);
				outtextxy(160, 100, s8);
				char s7[20];
				sprintf(s7, "%d", n->height);//������תΪ�ַ�
				outtextxy(160, 120, s7);
				char s6[20];
				sprintf(s6, "%d", n->child_num);
				outtextxy(170, 140, s6);//*
				char s5[20];
				strcpy(s5, n->occupation);
				outtextxy(160, 160, s5);
				char s4[20];
				strcpy(s4, n->education);
				outtextxy(160, 180, s4);
				char s3[20];
				strcpy(s3, n->parent_name);//*
				outtextxy(190, 200, s3);
				char s2[20];
				sprintf(s2, "%d", n->Depth);
				outtextxy(170, 220, s2);//*
				char s1[20];
				strcpy(s1, n->address);
				outtextxy(170, 240, s1);//*
				char s10[20];
				sprintf(s10, "%d.", n->birthDate.year);//*
				outtextxy(210, 260, s10);
				char s11[20];
				sprintf(s11, "%d.", n->birthDate.month);//*
				outtextxy(260, 260, s11);
				char s12[20];
				sprintf(s12, "%d", n->birthDate.day);//*
				outtextxy(290, 260, s12);
				flag++;
				break;
			}
			else//����������
			{
				if (n->firstchild != NULL)
					EnQueue(q, n->firstchild);
				if (n->sibling != NULL)
					EnQueue(q, n->sibling);
			}
		}
		if (flag == 0)
		{
			TCHAR s20[] = _T("��������û���ҵ�����");
			outtextxy(300, 100, s20);
		}
	}
	stop2 = 1;
	ExitButton();
}
void Find_sex(char sex[])
{
	loadimage(NULL, _T("1.jpg"));
	setbkmode(TRANSPARENT);
	settextcolor(BLACK);
	settextstyle(20, 0, _T("����"));
	Queue *q;
	person n = NULL;
	q = init();
	int flag = 0;
	if (T == NULL)
	{
		TCHAR s13[] = _T("û�д������ȣ�");
		outtextxy(300, 100, s13);
	}
	else
	{
		TCHAR s13[] = _T("������");
		outtextxy(100, 80, s13);
		TCHAR s14[] = _T("�Ա�");
		outtextxy(100, 100, s14);
		TCHAR s15[] = _T("��ߣ�");
		outtextxy(100, 120, s15);
		TCHAR s16[] = _T("��������");
		outtextxy(100, 140, s16);
		TCHAR s17[] = _T("ְҵ��");
		outtextxy(100, 160, s17);
		TCHAR s18[] = _T("ѧ����");
		outtextxy(100, 180, s18);
		TCHAR s19[] = _T("�������֣�");
		outtextxy(100, 200, s19);
		TCHAR s21[] = _T("�ڼ�����");
		outtextxy(100, 220, s21);
		TCHAR s22[] = _T("��ַ��");
		outtextxy(100, 240, s22);
		TCHAR s23[] = _T("����������:");
		outtextxy(100, 260, s23);
		q = Get_AllNode(T);
		while (!empty(q))//�����в���ʱ
		{
			n = DelQueue(q);//������
			if (strcmp(n->sex, sex) == 0)
			{
				char s9[20];//����һ���ַ�����
				strcpy(s9, n->name);//��n->name����һ���˵����֣���ֵ�����s9�ַ���������ȥ
				//���������������������
				outtextxy(160 + flag * 100, 80, s9);//��ָ��λ���������˵�����
				char s8[20];
				strcpy(s8, n->sex);
				outtextxy(160 + flag * 100, 100, s8);
				char s7[20];
				sprintf(s7, "%d", n->height);
				outtextxy(160 + flag * 100, 120, s7);
				char s6[20];
				sprintf(s6, "%d", n->child_num);
				outtextxy(170 + flag * 100, 140, s6);
				char s5[20];
				strcpy(s5, n->occupation);
				outtextxy(160 + flag * 100, 160, s5);
				char s4[20];
				strcpy(s4, n->education);
				outtextxy(160 + flag * 100, 180, s4);
				char s3[20];
				strcpy(s3, n->parent_name);
				outtextxy(190 + flag * 100, 200, s3);
				char s2[20];
				sprintf(s2, "%d", n->Depth);
				outtextxy(170 + flag * 100, 220, s2);
				char s1[20];
				strcpy(s1, n->address);
				outtextxy(170 + flag * 100, 240, s1);
				char s10[20];
				sprintf(s10, "%d.", n->birthDate.year/*, n->birthDate.month, n->birthDate.day*/);
				outtextxy(210 + flag * 100, 260, s10);
				char s11[20];
				sprintf(s11, "%d.", n->birthDate.month);
				outtextxy(260 + flag * 100, 260, s11);
				char s12[20];
				sprintf(s12, "%d", n->birthDate.day);
				outtextxy(290 + flag * 100, 260, s12);
				flag++;
			}
		}
		if (flag == 0)
		{
			TCHAR s26[] = _T("û���ҵ����Ա���ˣ�");
			outtextxy(300, 100, s26);
		}
	}
	stop3 = 1;
	ExitButton();
}
void Find_occupation(char occupation[])
{
	loadimage(NULL, _T("1.jpg"));
	setbkmode(TRANSPARENT);
	settextcolor(BLACK);
	settextstyle(20, 0, _T("����"));
	Queue *q;
	person n = NULL;
	q = init();
	int flag = 0;
	if (T == NULL)
	{
		TCHAR s18[] = _T("û�д������ȣ�");
		outtextxy(300, 100, s18);
	}
	else
	{
		TCHAR s13[] = _T("������");
		outtextxy(100, 80, s13);
		TCHAR s14[] = _T("�Ա�");
		outtextxy(100, 100, s14);
		TCHAR s15[] = _T("��ߣ�");
		outtextxy(100, 120, s15);
		TCHAR s16[] = _T("��������");
		outtextxy(100, 140, s16);
		TCHAR s17[] = _T("ְҵ��");
		outtextxy(100, 160, s17);
		TCHAR s18[] = _T("ѧ����");
		outtextxy(100, 180, s18);
		TCHAR s19[] = _T("�������֣�");
		outtextxy(100, 200, s19);
		TCHAR s21[] = _T("�ڼ�����");
		outtextxy(100, 220, s21);
		TCHAR s22[] = _T("��ַ��");
		outtextxy(100, 240, s22);
		TCHAR s23[] = _T("����������:");
		outtextxy(100, 260, s23);
		q = Get_AllNode(T);
		while (!empty(q))//�����в���ʱ
		{
			n = DelQueue(q);//������
			if (strcmp(n->occupation, occupation) == 0)
			{
				char s9[20];//����һ���ַ�����
				strcpy(s9, n->name);//��n->name����һ���˵����֣���ֵ�����s9�ַ���������ȥ
				//���������������������
				outtextxy(160 + flag * 80, 80, s9);//��ָ��λ���������˵�����
				char s8[20];
				strcpy(s8, n->sex);
				outtextxy(160 + flag * 100, 100, s8);
				char s7[20];
				sprintf(s7, "%d", n->height);
				outtextxy(160 + flag * 100, 120, s7);
				char s6[20];
				sprintf(s6, "%d", n->child_num);
				outtextxy(170 + flag * 100, 140, s6);
				char s5[20];
				strcpy(s5, n->occupation);
				outtextxy(160 + flag * 100, 160, s5);
				char s4[20];
				strcpy(s4, n->education);
				outtextxy(160 + flag * 100, 180, s4);
				char s3[20];
				strcpy(s3, n->parent_name);
				outtextxy(190 + flag * 100, 200, s3);
				char s2[20];
				sprintf(s2, "%d", n->Depth);
				outtextxy(170 + flag * 100, 220, s2);
				char s1[20];
				strcpy(s1, n->address);
				outtextxy(170 + flag * 100, 240, s1);
				char s10[20];
				sprintf(s10, "%d.", n->birthDate.year/*, n->birthDate.month, n->birthDate.day*/);
				outtextxy(210 + flag * 100, 260, s10);
				char s11[20];
				sprintf(s11, "%d.", n->birthDate.month);
				outtextxy(260 + flag * 100, 260, s11);
				char s12[20];
				sprintf(s12, "%d", n->birthDate.day);
				outtextxy(290 + flag * 100, 260, s12);
				flag++;
			}
		}
		if (flag == 0)
		{
			TCHAR s22[] = _T("û���ҵ���ְҵ���ˣ�");
			outtextxy(300, 100, s22);
		}
	}
	stop4 = 1;
	ExitButton();
}
void Find_education(char education[])
{
	loadimage(NULL, _T("1.jpg"));
	setbkmode(TRANSPARENT);
	settextcolor(BLACK);
	settextstyle(20, 0, _T("����"));
	Queue *q;
	person n = NULL;
	q = init();
	int flag = 0;
	if (T == NULL)
	{
		TCHAR s23[] = _T("û�д������ȣ�");
		outtextxy(300, 100, s23);
	}
	else
	{
		TCHAR s13[] = _T("������");
		outtextxy(100, 80, s13);
		TCHAR s14[] = _T("�Ա�");
		outtextxy(100, 100, s14);
		TCHAR s15[] = _T("��ߣ�");
		outtextxy(100, 120, s15);
		TCHAR s16[] = _T("��������");
		outtextxy(100, 140, s16);
		TCHAR s17[] = _T("ְҵ��");
		outtextxy(100, 160, s17);
		TCHAR s18[] = _T("ѧ����");
		outtextxy(100, 180, s18);
		TCHAR s19[] = _T("�������֣�");
		outtextxy(100, 200, s19);
		TCHAR s21[] = _T("�ڼ�����");
		outtextxy(100, 220, s21);
		TCHAR s22[] = _T("��ַ��");
		outtextxy(100, 240, s22);
		TCHAR s23[] = _T("����������:");
		outtextxy(100, 260, s23);
		q = Get_AllNode(T);
		while (!empty(q))//�����в���ʱ
		{
			n = DelQueue(q);//������
			if (strcmp(n->education, education) == 0)
			{
				char s9[20];//����һ���ַ�����
				strcpy(s9, n->name);//��n->name����һ���˵����֣���ֵ�����s9�ַ���������ȥ
				outtextxy(160 + flag * 100, 80, s9);//��ָ��λ���������˵�����
				char s8[20];
				strcpy(s8, n->sex);
				outtextxy(160 + flag * 100, 100, s8);
				char s7[20];
				sprintf(s7, "%d", n->height);
				outtextxy(160 + flag * 100, 120, s7);
				char s6[20];
				sprintf(s6, "%d", n->child_num);
				outtextxy(170 + flag * 100, 140, s6);
				char s5[20];
				strcpy(s5, n->occupation);
				outtextxy(160 + flag * 100, 160, s5);
				char s4[20];
				strcpy(s4, n->education);
				outtextxy(160 + flag * 100, 180, s4);
				char s3[20];
				strcpy(s3, n->parent_name);
				outtextxy(190 + flag * 100, 200, s3);
				char s2[20];
				sprintf(s2, "%d", n->Depth);
				outtextxy(170 + flag * 100, 220, s2);
				char s1[20];
				strcpy(s1, n->address);
				outtextxy(170 + flag * 100, 240, s1);
				char s10[20];
				sprintf(s10, "%d.", n->birthDate.year);
				outtextxy(210 + flag * 100, 260, s10);
				char s11[20];
				sprintf(s11, "%d.", n->birthDate.month);
				outtextxy(260 + flag * 100, 260, s11);
				char s12[20];
				sprintf(s12, "%d", n->birthDate.day);
				outtextxy(290 + flag * 100, 260, s12);
				flag++;
			}
		}
		if (flag == 0)
		{
			TCHAR s27[] = _T("û���ҵ���ѧ�����ˣ�");
			outtextxy(300, 100, s27);
		}
	}
	stop5 = 1;
	ExitButton();
}
