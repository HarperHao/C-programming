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
void preorder(AVLTree t)
{
	if (t != NULL)
	{
		printf("%d\n", t->Data);
		preorder(t->Left);
		preorder(t->Right);
	}
}
int main()
{
	AVLTree T = NULL;
	T = Input(T);
	preorder(T);
	system("pause");
	return 0;
}