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