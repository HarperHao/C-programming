



#include<stdio.h>

#include<stdlib.h>

#include<stdbool.h>

#include<Windows.h>

	const int MaxSize = 100;

char Getchar();				// 获取一个有效字符（避免用户输入错误的数据类型造成程序崩溃）

int	 Getint();				// 获取一个有效数字（调用结束缓冲区无残余）

typedef char datatype;

//////////////二叉树///////////////////

typedef struct node {

	datatype data;

	struct node*Lchild;

	struct node*Rchild;

}bintnode;

typedef bintnode *bintree;

typedef bintree ElementType;

bintree root;

////////////////////////////////////////

///////////////顺序栈//////////////////

typedef struct SNode {

	ElementType Date[MaxSize];

	int  top;//栈顶指针

}snode;

typedef struct SNode * Stack;

Stack CreatStack()

{

	Stack s = (Stack)malloc(sizeof(struct SNode));

	s->top = -1;

	return s;

}

bool  IsFull(Stack s)

{

	if (s->top == MaxSize)

		return true;

	else

		return false;

}

bool  IsEmpty(Stack s)

{

	return(s->top == -1);

}

void Push(Stack s, ElementType x)

{

	if (IsFull(s))

	{

		printf("栈已满");

	}

	else

	{

		s->Date[++s->top] = x;



	}

}

ElementType Pop(Stack s)

{

	if (IsEmpty(s))

	{

		printf("栈已空");

		return NULL;

	}

	else

	{

		return s->Date[(s->top)--];

	}

}

///////////////////////////////////

// 获取一个有效字符

char Getchar()

{

	char c[20] = {};

	gets_s(c, 20);

	if (c[1]) return '#';

	return c[0];

}

// 获取一个有效数字（避免用户错误类型的输入造成程序崩溃）

int Getint()

{

	char c[20] = {};

	gets_s(c, 20);

	int n = 0;

	int k = 0;

	while (c[k])k++;

	for (int i = 0; c[i]; i++)

	{

		if (c[i] < 48 || c[i] > 58)return 0;	// 错误字符

		else

		{

			int t = 1;

			for (int i = --k; i > 0; i--)t = t * 10;

			n += (int(c[i]) - 48)*t;			// 字符转数字

		}

	}

	return n;

}

//前序遍历递归

void preorder(bintree t)

{

	if (t != NULL)

	{

		printf("%c", t->data);

		preorder(t->Lchild);

		preorder(t->Rchild);

	}

}

//中序遍历递归

void midorder(bintree t)

{

	if (t != NULL)

	{

		midorder(t->Lchild);

		printf("%c", t->data);

		midorder(t->Rchild);

	}

}

//后序遍历递归

void behindorder(bintree t)

{

	if (t != NULL)

	{

		behindorder(t->Lchild);

		behindorder(t->Rchild);

		printf("%c", t->data);

	}

}

//前序遍历非递归实现

void preorder1(bintree t)

{

	Stack s;

	bintree q = NULL;

	q = t;

	s = CreatStack();

	while ((q != NULL) || (!IsEmpty(s)))

	{

		while (q != NULL)//一直向左将沿途左节点压入栈中

		{

			printf("%c ", q->data);

			Push(s, q);//第一次遇到q这个结点

			q = q->Lchild;

		}

		if (!IsEmpty(s))

		{

			q = Pop(s);//第二次遇到q结点,此时结点相当于只有右儿子没有左儿子,所以直接输出这个数据即可



			q = q->Rchild;//访问此节点的右儿子

		}

	}

}

//中序遍历非递归实现

void midorder1(bintree t)

{

	Stack s;

	bintree q;

	q = t;

	s = CreatStack();

	while ((q != NULL) || (!IsEmpty(s)))

	{

		while (q != NULL)//一直向左将沿途左节点压入栈中

		{



			Push(s, q);//将q这个结点压入栈中

			q = q->Lchild;

		}

		if (!IsEmpty(s))

		{

			q = Pop(s);//第二次遇到q结点,此时结点相当于只有右儿子没有左儿子,所以直接输出这个数据即可

			printf("%c ", q->data);//第一次遇到q这个结点

			q = q->Rchild;//访问此节点的右儿子

		}

	}

}

//后序遍历非递归实现

void behindorder1(bintree t)

{

	bintree r = NULL;

	Stack s;

	s = CreatStack();

	while (t != NULL || (!IsEmpty(s)))

	{

		while (t != NULL)

		{

			Push(s, t);

			t = t->Lchild;

		}

		if (!IsEmpty(s))

		{

			t = Pop(s);

			if (t->Rchild == NULL || t->Rchild == r)//右子树被访问完了

			{

				printf("%c ", t->data);

				r = t;

				t = NULL;

			}

			else//还没有访问右子树

			{

				Push(s, t);

				t = t->Rchild;

			}

		}



	}

}

//实现二叉树的查找，返回地址

bintree locate(bintree t, datatype x)

{

	bintree p;

	if (t == NULL)

	{

		//printf("该树是空树！\n");

		return NULL;

	}

	else

		if (t->data == x)

			return t;

		else

		{

			p = locate(t->Lchild, x);//在左子树里查找

			if (p != NULL)

				return p;

			else

				return locate(t->Rchild, x);//在右子树里面查找

		}

}

//统计二叉树中结点的个数

int numofbTree(bintree t)

{

	if (t == NULL)

	{

		return 0;

	}

	else

	{

		return (numofbTree(t->Lchild) + numofbTree(t->Rchild) + 1);

	}



}

//统计二叉树中叶子结点的个数(递归)

int numofbTreeleaves(bintree t)

{



	if ((t->Lchild == NULL) && (t->Rchild == NULL))

	{

		return 1;

	}

	else

	{

		if (t->Lchild == NULL && (t->Rchild != NULL))//如果左子树为空，那么就去找右子树中叶子的个数

			return numofbTreeleaves(t->Rchild);

		else if (t->Rchild == NULL && t->Lchild != NULL)

			return numofbTreeleaves(t->Lchild);

		else if ((t->Lchild != NULL) && (t->Rchild != NULL))

			return numofbTreeleaves(t->Lchild) + numofbTreeleaves(t->Rchild);

	}

}

//统计二叉树中叶子结点的个数(非递归)

int numofbTreeleaves1(bintree t)

{

	//在前序遍历的过程中查找叶子结点

	int count = 0;

	Stack s;

	bintree q = NULL;

	q = t;

	s = CreatStack();

	while ((q != NULL) || (!IsEmpty(s)))

	{

		while (q != NULL)//一直向左将沿途左节点压入栈中

		{

			Push(s, q);//第一次遇到q这个结点

			q = q->Lchild;

		}

		if (!IsEmpty(s))

		{

			q = Pop(s);

			if ((q->Lchild == NULL) && (q->Rchild == NULL))

			{

				count++;

			}

			q = q->Rchild;//访问此节点的右儿子

		}

	}

	return count;

}

//输出一棵给定二叉树在中序遍历下的最后一个结点

void Btnode_end_value(bintree t)

{

	Stack s;

	bintree q, r = NULL;

	q = t;

	s = CreatStack();

	while (q != NULL)//一直向右将沿途右节点压入栈中

	{

		Push(s, q);//第一次遇到q这个结点

		q = q->Rchild;

	}

	r = Pop(s);

	printf("%c\n", r->data);

}

//给定任意两个结点，返回这两个结点最近的共同祖先

bintree Btnode_nearest_parents(bintree t, bintree p, bintree q)

{

	if (t == NULL || p == t || q == t)//如果是棵空树或者p,q有一个是根节点那么共同祖先即为根结点

		return t;

	bintree left = Btnode_nearest_parents(t->Lchild, p, q);//在左右子树里面寻找最近共同祖先

	bintree right = Btnode_nearest_parents(t->Rchild, p, q);

	if (left != NULL && right != NULL)//如果左右子树返回的结果都不为空，那么最近共同祖先肯定是根节点

		return t;

	else

		return left == NULL ? right : left;

}

//二叉树的depth

int depth(bintree t)

{

	int h = 0, lh, rh;

	if (t == NULL)

	{

		return h;

	}

	else

	{

		lh = depth(t->Lchild);

		rh = depth(t->Rchild);

		h = (lh >= rh) ? lh : rh;

		return h + 1;

	}

}

//销毁一棵二叉树（采用后序遍历销毁二叉树）

void destroy_btree(bintree t)//传入的只是root的一个替代品,此函数无法删除root，要想删除得传入指针的指针。

{

	if (t == NULL)//空树

		return;

	destroy_btree(t->Lchild);

	destroy_btree(t->Rchild);

	free(t);

	return;

}

//根据前序遍历的结果创建一个二叉树

bintree createbintree()

{

	char ch;

	bintree t;

	if ((ch = getchar()) == '#')

		t = NULL;

	else

	{

		t = (bintree)malloc(sizeof(bintnode));

		t->data = ch;

		t->Lchild = createbintree();

		t->Rchild = createbintree();

	}

	return t;

}

int menu()

{



	bool LOOP = true;					// 循环控制变量

	int Choice_Num = -1;				// 选择函数序号

	while (LOOP)

	{

		system("cls");

		printf("\n");

		printf("\n\t\t*******************************\n");

		printf("\n\t\t******\t 1. 前序遍历法创建树      ******\n");

		printf("\n\t\t******\t 2. 前序遍历（递归）      ******\n");

		printf("\n\t\t******\t 3. 中序遍历（递归）     ******\n");

		printf("\n\t\t******\t 4. 后序遍历（递归）       ******\n");

		printf("\n\t\t******\t 5. 前序遍历（非递归）       ******\n");

		printf("\n\t\t******\t 6. 中序遍历（非递归）       ******\n");

		printf("\n\t\t******\t 7. 后序遍历（非递归）       ******\n");

		printf("\n\t\t******\t 8. 二叉树中结点的个数       ******\n");

		printf("\n\t\t******\t 9. 二叉树的深度       ******\n");

		printf("\n\t\t******\t 10. 二叉树的叶子结点的个数（递归）       ******\n");

		printf("\n\t\t******\t 11. 二叉树的叶子结点的个数（非递归）       ******\n");

		printf("\n\t\t******\t 12. 二叉树中序遍历情况下的最后一个结点值       ******\n");

		printf("\n\t\t******\t 13. 二叉树两个结点的最近共同祖先       ******\n");

		printf("\n\t\t******\t 14. 销毁一棵二叉树       ******\n");

		printf("\n\t\t******\t 15.退出操作系统 ******\n");

		printf("\n\t\t*******************************\n");

		printf("\n\t\t请输入您选择操作的编号：");

		Choice_Num = Getint();

		switch (Choice_Num)

		{

		case 1:

			system("cls");



			root = createbintree();



			printf("\n\t\t请按任意键继续!");

			getchar();

			break;

		case 2:

			system("cls");



			preorder(root);

			printf("\n\t\t请按任意键继续!");

			getchar();

			break;

		case 3:

			system("cls");

			midorder(root);



			printf("\n\t\t请按任意键继续!");

			getchar();

			break;

		case 4:

			system("cls");

			behindorder(root);

			printf("\n\t\t请按任意键继续!");

			getchar();

			break;

		case 5:

			system("cls");

			preorder1(root);



			printf("\n\t\t请按任意键继续!");

			getchar();

			break;

		case 6:

			system("cls");

			midorder1(root);



			printf("\n\t\t请按任意键继续!");

			getchar();

			break;

		case 7:

			system("cls");

			behindorder1(root);



			printf("\n\t\t请按任意键继续!");

			getchar();

			break;

		case 8:

			system("cls");

			int count;

			count = numofbTree(root);

			printf("%d\n", count);

			printf("\n\t\t请按任意键继续!");

			getchar();

			break;

		case 9:

			system("cls");

			count = depth(root);

			printf("%d\n", count);

			printf("\n\t\t请按任意键继续!");

			getchar();

			break;

		case 10:

			system("cls");

			count = numofbTreeleaves(root);

			printf("%d\n", count);

			printf("\n\t\t请按任意键继续!");

			getchar();

			break;

		case 11:

			system("cls");

			count = numofbTreeleaves1(root);

			printf("%d\n", count);

			printf("\n\t\t请按任意键继续!");

			getchar();

			break;

		case 12:

			system("cls");

			Btnode_end_value(root);

			printf("\n\t\t请按任意键继续!");

			getchar();

			break;

		case 13:

			system("cls");

			bintree p, q, r;

			char  a, b;

			printf("请输入要查找的两个结点的值\n");

			scanf_s("%c %c", &a, 1, &b, 1);

			p = locate(root, a);

			q = locate(root, b);

			if (p == NULL && q != NULL)

				printf("树中没有结点%c\n", a);

			else if (q == NULL && p != NULL)

				printf("树中没有结点%c\n", b);

			else if (!p && !q)

				printf("树中没有结点%c和%c\n", a, b);

			else

			{

				r = Btnode_nearest_parents(root, p, q);

				printf("%c\n", r->data);

			}

			Sleep(2000);

			printf("\n\t\t请按任意键继续!");

			getchar();

			break;

		case 14:

			system("cls");

			destroy_btree(root);

			root = NULL;

			printf("\n\t\t请按任意键继续!");

			getchar();

			break;

		case 15:

			printf("\n\t\t请按任意键退出操作系统");

			getchar();

			return 0;

		default:

			printf("\n\t\t输入有误！按任意键继续");

			getchar();

			break;

		}

	}

	return 1;

}

int main()

{

	system("mode con cols=63 lines=46,color 12");       /*调整窗口大小*/

	while (menu());

	system("pause");
	return 0;

}


