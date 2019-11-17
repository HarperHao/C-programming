#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
const int MaxSize = 15;
typedef int ElementType;
typedef struct AVLNode* AVLTree;
struct AVLNode {
	ElementType Data; /* ������� */
	AVLTree Left;     /* ָ�������� */
	AVLTree Right;    /* ָ�������� */
	int Height;       /* ���� */
};
/////////////////ѭ��ջ��˳��//////////////////
typedef AVLTree datatype;
typedef  struct {
	datatype a[MaxSize];
	int front;
	int rear;
}sequence_queue;
//��ʼ��
sequence_queue* init()
{
	sequence_queue* q = (sequence_queue*)malloc(sizeof(sequence_queue));
	q->front = q->rear = 0;
	return  q;
}
//�������
void insert_sequence_cqueue(sequence_queue *sq, datatype x)
{
	if ((sq->rear + 1) % MaxSize == sq->front)
	{
		printf("\n˳��ѭ�����������ģ��޷����в��������");
		return;
	}
	sq->a[sq->rear] = x;
	sq->rear = (sq->rear + 1) % MaxSize;
}
//���Ӳ���
datatype pop_sequence_cqueue(sequence_queue *sq)
{
	datatype t;
	if (sq->front == sq->rear)
	{
		printf("ѭ�������ǿյģ��޷����г��Ӳ�����\n");
	}
	t = sq->a[sq->front];
	sq->front = (sq->front + 1) % MaxSize;
	return t;
}
///////////////////////////////////////////////////
int Max(int a, int b)
{
	return a > b ? a : b;
}
int GetHeight(AVLTree T)
{
	if (!T)
	{
		return 0;
	}
	else
		return T->Height;
}
AVLTree SingleLeftRotation(AVLTree A)
{ /* ע�⣺A������һ�����ӽ��B */
  /* ��A��B������������A��B�ĸ߶ȣ������µĸ����B */
 //LL��ת
	AVLTree B = A->Left;
	A->Left = B->Right;
	B->Right = A;
	A->Height = Max(GetHeight(A->Left), GetHeight(A->Right)) + 1;//A->Height ������AΪ��������ĸ߶�
	B->Height = Max(GetHeight(B->Left), A->Height) + 1;

	return B;
}
AVLTree SingleRightRotation(AVLTree A)
{
	//���A������һ�����ӽ��B
	//RR��ת
	AVLTree B = A->Right;
	A->Right = B->Left;
	B->Left = A;
	A->Height = Max(GetHeight(A->Left), GetHeight(A->Right)) + 1;
	B->Height = Max(GetHeight(B->Right), A->Height) + 1;
	return B;
}
AVLTree DoubleLeftRightRotation(AVLTree A)
{ /* ע�⣺A������һ�����ӽ��B����B������һ�����ӽ��C */
  /* ��A��B��C�����ε����������µĸ����C */
  //LR��ת
	/* ��B��C���ҵ�����C������ */
	//RR��ת
	A->Left = SingleRightRotation(A->Left);
	/* ��A��C��������C������ */
	//LL��ת
	return SingleLeftRotation(A);
}
AVLTree DoubleRightLeftRotation(AVLTree A)
{
	//RL��ת
	//A��������һ�����ӽ��B,B������һ�����ӽ��C
	A->Right = SingleLeftRotation(A->Right);
	return SingleRightRotation(A);
}
AVLTree Insert(AVLTree T, ElementType x)
{
	//������ǿ���
	if (!T)
	{
		T = (AVLTree)malloc(sizeof(struct AVLNode));
		T->Data = x;
		T->Left = T->Right = NULL;
		T->Height = 0;//�Ա�������
	}
	//���뵽������������
	else if (x < T->Data)
	{
		T->Left = Insert(T->Left, x);//���ز���һ���������ĸ��ڵ�
		//�����Ҫ����
		if (GetHeight(T->Left) - GetHeight(T->Right) == 2)
		{
			if (x < T->Left->Data)//LL��ת,�鷳�ڵ��ڱ��ƻ������������������
				T = SingleLeftRotation(T);
			else//LR��ת
				T = DoubleLeftRightRotation(T);
		}
	}
	//���뵽������������
	else if (x > T->Data)
	{
		T->Right = Insert(T->Right, x);
		//�����Ҫ����
		if (GetHeight(T->Left) - GetHeight(T->Right) == -2)
		{
			//RR��ת
			if (x > T->Right->Data)
				T = SingleRightRotation(T);
			else //RL��ת
				T = DoubleRightLeftRotation(T);
		}
	}
	//T->Data==x,ɶҲ������
	else
	{

	}
	//�������ĸ߶�
	T->Height = Max(GetHeight(T->Left), GetHeight(T->Right)) + 1;
	return T;
}
AVLTree Input(AVLTree T)
{
	//AVLTree T = NULL;
	//����-1ֹͣ
	ElementType data = 0;
	printf("��������ֵ��\n");
	scanf_s("%d", &data);
	while (data != -1)
	{
		T = Insert(T, data);
		scanf_s("%d", &data);
	}
	return T;
}
//����ǰ�����
void preorder(AVLTree t)
{
	if (t != NULL)
	{
		printf("%d\n", t->Data);
		preorder(t->Left);
		preorder(t->Right);
	}
}
//���Ĳ������
void level_order(AVLTree t)
{
	AVLTree s = NULL;
	sequence_queue *sq = NULL;
	if (t == NULL)
		return;
	sq = init();
	insert_sequence_cqueue(sq, t);
	while (sq->front != sq->rear)//��ջ����ʱ
	{
		s = pop_sequence_cqueue(sq);
		printf("%d ", s->Data);
		if (s->Left != NULL)
			insert_sequence_cqueue(sq, s->Left);
		if (s->Right != NULL)
			insert_sequence_cqueue(sq, s->Right);
	}
}
int main()
{
	AVLTree T = NULL;
	T = Input(T);
	level_order(T);
	system("pause");
	return 0;
}