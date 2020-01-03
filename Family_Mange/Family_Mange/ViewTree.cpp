#include"Family.h"
#include"global.h"
//统计整棵树的高度
int  Depth(person T)
{
	if (T == NULL)
		return 0;
	else
	{
		return (Max(Depth(T->firstchild) + 1, Depth(T->sibling)));
	}
}
//统计每一层结点的个数
void numOfFamily(person T, int sum[20])//统计每层结点个数，第一个元素保存总值
{
	int i;
	if (!T)
		return;
	person T1 = T->firstchild, T2;
	sum[1] = sum[0] = 1;//第一层只有祖先结点
	Queue *q = init();
	i = 2;//从第二层开始计算
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
			sum[0] += sum[i];//累加到总数
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
//两个数中的最大值
int Max(int x, int y)
{
	if (x >= y)
		return x;
	else
		return y;
}
//将所有结点按层次遍历的方法进入m队列中, 返回m
Queue * Get_AllNode(person T)
{
	Queue *m;
	m = init();//初始化一个队列
	Queue *q;
	q = init();//初始化一个队列
	if (T != NULL)
	{
		EnQueue(m, T);//入m队列中
		EnQueue(q, T);//入q队列中
		while (!empty(q))//如果队列不为空的话
		{
			person x, y;
			y = DelQueue(q);
			x = y->firstchild;
			while (x)
			{
				EnQueue(m, x);//入m队列中
				EnQueue(q, x);//入q队中
				x = x->sibling;//指向它的兄弟
			}
		}
	}
	return m;
}
//对m队列中的所有结点进行位置坐标的初始化
void init_position(person T)
{
	person p=NULL;
	person q = NULL;
	person r = NULL;
	person pre = NULL;
	Queue *m=NULL;
	int offset1 = 0;//处理父母结点和他的第一个孩子间的偏移量
	int offset2 = 0;//处理兄弟结点间的偏移量
	int last_offset1 = 0;//保存上一个值
	m = init();//初始化一个队列
	m = Get_AllNode(T);
	//单独给祖先结点进行坐标初始化
	T->x = 478;
	T->y = 30;	
	last_offset1= 188;//第一层的偏移量
	while (!empty(m))//当队列不为空的时候.p是父母结点，q是第一个儿子结点，
	{
		p = DelQueue(m);
		q = p->firstchild;
		//处理第一个儿子结点的坐标
		if (q != NULL)
		{
			offset1 = last_offset1 -  4* (q->Depth *q->Depth ) ; //最多五代
			q->x = p->x - offset1;
			q->y = 30 + (q->Depth - 1) * 80;
			last_offset1 = offset1;
			//处理第一个结点的兄弟们结点的坐标
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
//画结点x
void draw_circle(person m)
{

	//设置字体样式
	settextcolor(RED);
	settextstyle(20, 10, _T("宋体"));
	//设置字体的样式
	setlinecolor(BLACK);
	setlinestyle(PS_SOLID | PS_ENDCAP_FLAT, 3);
	circle(m->x, m->y, 30);//画圆
	outtextxy(m->x - 15, m->y - 10, m->name);//写字体	
	if (m->parent != NULL)//考虑到了祖先结点的情况，即从第二层开始画线
	{
		person parent = m->parent;
		line(parent->x, parent->y + 30, m->x, m->y - 30);//画线
	}
}
//按多叉树层序遍历画结点
void view(person T)
{
	init_position(T);//初始化坐标
	Queue *q;
	q = init();//初始化一个队列
	if (T != NULL)
	{
		draw_circle(T);//画结点
		EnQueue(q, T);//入队
		while (!empty(q))//如果队列不为空的话
		{
			person x, y;
			y = DelQueue(q);//出队
			x = y->firstchild;
			while (x)
			{
				draw_circle(x);//再画结点
				EnQueue(q, x);//入队
				x = x->sibling;//指向它的兄弟
			}
		}
	}
	if (isMouseDown&&mouseX < 85 && mouseX>0 && mouseY < 35 && mouseY>0)
	{
		GamePhase = 0;
	}
	else
	{
		//设置返回主菜单按纽
		setfillcolor(RGB(240, 248, 255));
		setlinecolor(RGB(119, 136, 153));
		fillrectangle(0, 0, 80, 30);
		settextstyle(15, 0, _T("楷体"));
		TCHAR s0[] = _T("返回菜单");
		outtextxy(10, 10, s0);
	}
}