#include"global.h"
#include"Family.h"
extern person T;
extern int stop;

void creat(char *fileName)//���ļ���ȡ���ݴ���һ������
{

	loadimage(NULL, _T("1.jpg"));
	setbkmode(TRANSPARENT);
	settextcolor(BLACK);
	settextstyle(30, 0, _T("����"));
	FILE *fp = fopen(fileName, "r");
	if (!fp)
	{
		TCHAR s1[] = _T("�ļ���ʧ��!");
		outtextxy(300, 240, s1);
		//return NULL;
	}
	int i;
	Queue *q = init();
	//person T = NULL, T1, T2, T3;
	person T1, T2, T3;
	T1 = NULL;
	T2 = NULL;
	T3 = NULL;
	while ((!feof(fp)) && stop == 0)//����Ƿ��ļ�ĩβ
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
	stop = 1;
	fclose(fp);
	TCHAR s2[] = _T("��ȡ�ļ��ɹ��������������");
	outtextxy(280, 240, s2);
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
int isFamily(person T, char *s)//�жϳ�Ա�Ƿ���������
{
	if (Find(s))
		return 1;//��
	else
		return 0;//����
}