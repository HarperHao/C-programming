#include"Family.h"
//����һ���յ���ʽ����
Queue *init()
{
	Queue *q;
	q = (Queue*)malloc(sizeof(Queue));
	q->front = NULL;
	q->rear = NULL;
	return q;
}
//�ж���ʽ�����Ƿ�Ϊ��,���Ϊ�շ���1,�����Ϊ�շ���0
int empty(Queue* q)
{
	if (q->front == NULL)
		return 1;
	else
		return 0;
}
//��ʽ���е���Ӳ���,����ʽ�����������һ��x�Ľ��
void EnQueue(Queue *q, person x)
{
	QNode*m;
	m = (QNode *)malloc(sizeof(QNode));//����ռ�
	m->data = x;//�����½���ֵ
	m->next = NULL;
	//��һ���ն����������һ�����
	if (empty(q))
	{
		q->front = m;//ͷָ���βָ��
		q->rear = m;
	}
	//��һ���ǿն����������һ�����
	else
	{
		q->rear->next = m;
		q->rear = m;
	}
}
//��ʽ���еĳ��Ӳ�����ɾ��ͷ��㲢��ͷ������
person DelQueue(Queue *q)
{
	QNode* Frontcell;//��һ�����
	person FrontElem;//��һ��Ԫ��
	if (empty(q))
	{
		printf("����Ϊ��");
		return NULL;
	}
	else
	{
		Frontcell = q->front;
	
		if (q->front == q->rear)//��������ֻ��һ��Ԫ��
		{
			q->front = q->rear = NULL;//ɾ���������Ϊ��
		}
		else//�����в�ֻ��һ��Ԫ��
		{
			q->front = q->front->next;
		}
		FrontElem = Frontcell->data;
		free(Frontcell);
		return FrontElem;
	}
}
