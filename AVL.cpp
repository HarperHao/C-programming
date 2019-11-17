#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
const int MaxSize = 15;
typedef int ElementType;
typedef struct AVLNode* AVLTree;
struct AVLNode {
	ElementType Data; /* 结点数据 */
	AVLTree Left;     /* 指向左子树 */
	AVLTree Right;    /* 指向右子树 */
	int Height;       /* 树高 */
};
/////////////////循环栈（顺序）//////////////////
typedef AVLTree datatype;
typedef  struct {
	datatype a[MaxSize];
	int front;
	int rear;
}sequence_queue;
//初始化
sequence_queue* init()
{
	sequence_queue* q = (sequence_queue*)malloc(sizeof(sequence_queue));
	q->front = q->rear = 0;
	return  q;
}
//插入操作
void insert_sequence_cqueue(sequence_queue *sq, datatype x)
{
	if ((sq->rear + 1) % MaxSize == sq->front)
	{
		printf("\n顺序循环队列是满的！无法进行插入操作！");
		return;
	}
	sq->a[sq->rear] = x;
	sq->rear = (sq->rear + 1) % MaxSize;
}
//出队操作
datatype pop_sequence_cqueue(sequence_queue *sq)
{
	datatype t;
	if (sq->front == sq->rear)
	{
		printf("循环队列是空的！无法进行出队操作！\n");
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
{ /* 注意：A必须有一个左子结点B */
  /* 将A与B做左单旋，更新A与B的高度，返回新的根结点B */
 //LL旋转
	AVLTree B = A->Left;
	A->Left = B->Right;
	B->Right = A;
	A->Height = Max(GetHeight(A->Left), GetHeight(A->Right)) + 1;//A->Height 代表以A为根结点树的高度
	B->Height = Max(GetHeight(B->Left), A->Height) + 1;

	return B;
}
AVLTree SingleRightRotation(AVLTree A)
{
	//结点A必须有一个右子结点B
	//RR旋转
	AVLTree B = A->Right;
	A->Right = B->Left;
	B->Left = A;
	A->Height = Max(GetHeight(A->Left), GetHeight(A->Right)) + 1;
	B->Height = Max(GetHeight(B->Right), A->Height) + 1;
	return B;
}
AVLTree DoubleLeftRightRotation(AVLTree A)
{ /* 注意：A必须有一个左子结点B，且B必须有一个右子结点C */
  /* 将A、B与C做两次单旋，返回新的根结点C */
  //LR旋转
	/* 将B与C做右单旋，C被返回 */
	//RR旋转
	A->Left = SingleRightRotation(A->Left);
	/* 将A与C做左单旋，C被返回 */
	//LL旋转
	return SingleLeftRotation(A);
}
AVLTree DoubleRightLeftRotation(AVLTree A)
{
	//RL旋转
	//A结点必须有一个右子结点B,B必须有一个左子结点C
	A->Right = SingleLeftRotation(A->Right);
	return SingleRightRotation(A);
}
AVLTree Insert(AVLTree T, ElementType x)
{
	//如果树是空树
	if (!T)
	{
		T = (AVLTree)malloc(sizeof(struct AVLNode));
		T->Data = x;
		T->Left = T->Right = NULL;
		T->Height = 0;//以边数来看
	}
	//插入到树的左子树中
	else if (x < T->Data)
	{
		T->Left = Insert(T->Left, x);//返回插入一个结点后树的根节点
		//如果需要左旋
		if (GetHeight(T->Left) - GetHeight(T->Right) == 2)
		{
			if (x < T->Left->Data)//LL旋转,麻烦节点在被破坏结点的左子树的左边上
				T = SingleLeftRotation(T);
			else//LR旋转
				T = DoubleLeftRightRotation(T);
		}
	}
	//插入到树的右子树中
	else if (x > T->Data)
	{
		T->Right = Insert(T->Right, x);
		//如果需要右旋
		if (GetHeight(T->Left) - GetHeight(T->Right) == -2)
		{
			//RR旋转
			if (x > T->Right->Data)
				T = SingleRightRotation(T);
			else //RL旋转
				T = DoubleRightLeftRotation(T);
		}
	}
	//T->Data==x,啥也不用做
	else
	{

	}
	//更新树的高度
	T->Height = Max(GetHeight(T->Left), GetHeight(T->Right)) + 1;
	return T;
}
AVLTree Input(AVLTree T)
{
	//AVLTree T = NULL;
	//输入-1停止
	ElementType data = 0;
	printf("请输入结点值：\n");
	scanf_s("%d", &data);
	while (data != -1)
	{
		T = Insert(T, data);
		scanf_s("%d", &data);
	}
	return T;
}
//树的前序遍历
void preorder(AVLTree t)
{
	if (t != NULL)
	{
		printf("%d\n", t->Data);
		preorder(t->Left);
		preorder(t->Right);
	}
}
//树的层序遍历
void level_order(AVLTree t)
{
	AVLTree s = NULL;
	sequence_queue *sq = NULL;
	if (t == NULL)
		return;
	sq = init();
	insert_sequence_cqueue(sq, t);
	while (sq->front != sq->rear)//当栈不空时
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