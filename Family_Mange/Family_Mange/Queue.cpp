#include"Family.h"
//建立一个空的链式队列
Queue *init()
{
	Queue *q;
	q = (Queue*)malloc(sizeof(Queue));
	q->front = NULL;
	q->rear = NULL;
	return q;
}
//判断链式队列是否为空,如果为空返回1,如果不为空返回0
int empty(Queue* q)
{
	if (q->front == NULL)
		return 1;
	else
		return 0;
}
//链式队列的入队操作,向链式队列里面插入一个x的结点
void EnQueue(Queue *q, person x)
{
	QNode*m;
	m = (QNode *)malloc(sizeof(QNode));//分配空间
	m->data = x;//设置新结点的值
	m->next = NULL;
	//向一个空队列里面插入一个结点
	if (empty(q))
	{
		q->front = m;//头指针和尾指针
		q->rear = m;
	}
	//向一个非空队列里面插入一个结点
	else
	{
		q->rear->next = m;
		q->rear = m;
	}
}
//链式队列的出队操作，删除头结点并让头结点出队
person DelQueue(Queue *q)
{
	QNode* Frontcell;//第一个结点
	person FrontElem;//第一个元素
	if (empty(q))
	{
		printf("队列为空");
		return NULL;
	}
	else
	{
		Frontcell = q->front;
	
		if (q->front == q->rear)//若队列中只有一个元素
		{
			q->front = q->rear = NULL;//删除后队列置为空
		}
		else//队列中不只有一个元素
		{
			q->front = q->front->next;
		}
		FrontElem = Frontcell->data;
		free(Frontcell);
		return FrontElem;
	}
}
