#include"Family.h"
#include"global.h"
extern person T;
extern int stop1;
void AddNewNode()//���һ����Ա
{
	loadimage(NULL, _T("1.jpg"));
	setbkmode(TRANSPARENT);
	settextcolor(BLACK);
	settextstyle(20, 0, _T("����"));
	if (stop1 == 0)
	{
		person T1, T2;
			int i=0;
			char a[20];
			T1 = (person)malloc(sizeof(Tree_Node));
			InputBox(a, 20, "����������ӳ�Ա�ĸ��׻�ĸ������:   ");
			T2 = Find(a);
			while (!T2)
			{
				InputBox(a, 20, "���˵ĸ��׻�ĸ�����������ڣ����������룡");
				T2 = Find(a);
			}
			T1->parent = T2;
			T2->child_num++;
			strcpy(T1->parent_name, T2->name);
			if (T2->firstchild)//��ĸ���ĵ�һ�����Ӳ�Ϊ��
			{
				T2 = T2->firstchild;
				while (T2->sibling)
					T2 = T2->sibling;
				T2->sibling = T1;
				T1->Depth = T2->Depth;
				T1->firstchild = NULL;
				T1->sibling = NULL;
			}
			else
			{
				T1->Depth = T2->Depth + 1;//����Ϊ���״�����һ
				T2->firstchild = T1;
				T1->sibling = NULL;
				T1->firstchild = NULL;
			}
			InputBox(T1->name, 20, "�������Ա����:");
			char s6[20];
			InputBox(s6, 20, "�������Ա�Ա�:(1������,0����Ů)");//
			sscanf(s6, "%d", &i);//���ַ�ת��Ϊ����
			i ? strcpy(T1->sex, "��") : strcpy(T1->sex, "Ů");
			char s7[20];
			InputBox(s7, 20, "�������Ա���:");
			sscanf(s7, "%d", &T1->height);
			InputBox(T1->occupation, 20, "�������Աְҵ:");
			InputBox(T1->education, 20, "�������Ա�ܽ����̶�:");
			InputBox(T1->address, 20, "�������Ա��ͥסַ:");
			T1->child_num = 0;//�¼����Ա������Ĭ��Ϊ0
			char s10[20];
			InputBox(s10, 20, "�������Ա�����������:");
			sscanf(s10, "%d.", &T1->birthDate.year);
			char s11[20];
			InputBox(s11, 20, "�������Ա���������·�:");
			sscanf(s11, "%d", &T1->birthDate.month);
			char s12[20];
			InputBox(s12, 20, "�������Ա������������:");
			sscanf(s12, "%d", &T1->birthDate.day);
			stop1 = 1;
	}
	if (isMouseDown&&mouseX < 85 && mouseX>0 && mouseY < 35 && mouseY>0)
	{
		GamePhase = 0;
	}
	else
	{
		//���÷������˵���Ŧ
		setfillcolor(RGB(240, 248, 255));
		setlinecolor(RGB(119, 136, 153));
		fillrectangle(0, 0, 80, 30);
		settextstyle(15, 0, _T("����"));
		TCHAR s0[] = _T("���ز˵�");
		outtextxy(10, 10, s0);
	}
}