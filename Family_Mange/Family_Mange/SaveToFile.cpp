#include "Family.h"
#include"global.h"
void save(person T)//�����Ƚ��T������
{
	loadimage(NULL, _T("1.jpg"));
	settextstyle(20, 0, _T("����"));
	FILE *fp;
	fp = fopen("JiaPu.txt", "w");
	if (fp == NULL)
	{
		TCHAR s0[] = _T("�����ļ������ڣ�");
		outtextxy(400, 200, s0);
	}
	else
	{
		save1(T, fp);
		fclose(fp);
		TCHAR s1[] = _T("�����ļ�����ɹ���");
		outtextxy(400, 200, s1);
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
	fprintf(fp,"\n%s %s %d %s %s %s %d %d %d %d",T->name,T->sex,T->height,T->occupation,T->education,T->address,T->child_num,T->birthDate.year, T->birthDate.month, T->birthDate.day);
}
void save3(person T, FILE *fp)//ר�����������һ�����
{
	fprintf(fp, "%s %s %d %s %s %s %d %d %d %d", T->name, T->sex, T->height, T->occupation, T->education, T->address, T->child_num, T->birthDate.year, T->birthDate.month, T->birthDate.day);
}
