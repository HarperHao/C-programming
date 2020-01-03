#include"Family.h"
#include"global.h"
//ͳ���������ĸ߶�
int  Depth(person T)
{
	if (T == NULL)
		return 0;
	else
	{
		return (Max(Depth(T->firstchild) + 1, Depth(T->sibling)));
	}
}
//ͳ��ÿһ����ĸ���
void numOfFamily(person T, int sum[20])//ͳ��ÿ�����������һ��Ԫ�ر�����ֵ
{
	int i;
	if (!T)
		return;
	person T1 = T->firstchild, T2;
	sum[1] = sum[0] = 1;//��һ��ֻ�����Ƚ��
	Queue *q = init();
	i = 2;//�ӵڶ��㿪ʼ����
	do
	{
		sum[i]++;
		EnQueue(q, T1);
		T1 = T1->sibling;
	} while (T1);
	while (!empty(q))
	{
		T2 = DelQueue(q)->firstchild;
		if (!T2)
			continue;
		if (T2->Depth == i + 1)
		{
			sum[0] += sum[i];//�ۼӵ�����
			i++;
		}
		do
		{
			sum[i]++;
			EnQueue(q, T2);
			T2 = T2->sibling;
		} while (T2);
	}
	sum[0] += sum[i];
}
//�������е����ֵ
int Max(int x, int y)
{
	if (x >= y)
		return x;
	else
		return y;
}
//�����н�㰴��α����ķ�������m������, ����m
Queue * Get_AllNode(person T)
{
	Queue *m;
	m = init();//��ʼ��һ������
	Queue *q;
	q = init();//��ʼ��һ������
	if (T != NULL)
	{
		EnQueue(m, T);//��m������
		EnQueue(q, T);//��q������
		while (!empty(q))//������в�Ϊ�յĻ�
		{
			person x, y;
			y = DelQueue(q);
			x = y->firstchild;
			while (x)
			{
				EnQueue(m, x);//��m������
				EnQueue(q, x);//��q����
				x = x->sibling;//ָ�������ֵ�
			}
		}
	}
	return m;
}
//��m�����е����н�����λ������ĳ�ʼ��
void init_position(person T)
{
	person p=NULL;
	person q = NULL;
	person r = NULL;
	person pre = NULL;
	Queue *m=NULL;
	int offset1 = 0;//����ĸ�������ĵ�һ�����Ӽ��ƫ����
	int offset2 = 0;//�����ֵܽ����ƫ����
	int last_offset1 = 0;//������һ��ֵ
	m = init();//��ʼ��һ������
	m = Get_AllNode(T);
	//���������Ƚ����������ʼ��
	T->x = 478;
	T->y = 30;	
	last_offset1= 188;//��һ���ƫ����
	while (!empty(m))//�����в�Ϊ�յ�ʱ��.p�Ǹ�ĸ��㣬q�ǵ�һ�����ӽ�㣬
	{
		p = DelQueue(m);
		q = p->firstchild;
		//�����һ�����ӽ�������
		if (q != NULL)
		{
			offset1 = last_offset1 -  4* (q->Depth *q->Depth ) ; //������
			q->x = p->x - offset1;
			q->y = 30 + (q->Depth - 1) * 80;
			last_offset1 = offset1;
			//�����һ�������ֵ��ǽ�������
			offset2 = 200 - (10*p->child_num+5*p->Depth*p->Depth);
			pre = q;
			q = q->sibling;
			while (q!=NULL)
			{
				q->x = pre->x + offset2;
				q->y=30+(q->Depth-1)*80;
				pre = q; 
				q = q->sibling;
			}
		}
		
	}
}
//�����x
void draw_circle(person m)
{

	//����������ʽ
	settextcolor(RED);
	settextstyle(20, 10, _T("����"));
	//�����������ʽ
	setlinecolor(BLACK);
	setlinestyle(PS_SOLID | PS_ENDCAP_FLAT, 3);
	circle(m->x, m->y, 30);//��Բ
	outtextxy(m->x - 15, m->y - 10, m->name);//д����	
	if (m->parent != NULL)//���ǵ������Ƚ�����������ӵڶ��㿪ʼ����
	{
		person parent = m->parent;
		line(parent->x, parent->y + 30, m->x, m->y - 30);//����
	}
}
//�������������������
void view(person T)
{
	init_position(T);//��ʼ������
	Queue *q;
	q = init();//��ʼ��һ������
	if (T != NULL)
	{
		draw_circle(T);//�����
		EnQueue(q, T);//���
		while (!empty(q))//������в�Ϊ�յĻ�
		{
			person x, y;
			y = DelQueue(q);//����
			x = y->firstchild;
			while (x)
			{
				draw_circle(x);//�ٻ����
				EnQueue(q, x);//���
				x = x->sibling;//ָ�������ֵ�
			}
		}
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