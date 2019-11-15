



#include<stdio.h>

#include<stdlib.h>

#include<stdbool.h>

#include<Windows.h>

	const int MaxSize = 100;

char Getchar();				// ��ȡһ����Ч�ַ��������û�������������������ɳ��������

int	 Getint();				// ��ȡһ����Ч���֣����ý����������޲��ࣩ

typedef char datatype;

//////////////������///////////////////

typedef struct node {

	datatype data;

	struct node*Lchild;

	struct node*Rchild;

}bintnode;

typedef bintnode *bintree;

typedef bintree ElementType;

bintree root;

////////////////////////////////////////

///////////////˳��ջ//////////////////

typedef struct SNode {

	ElementType Date[MaxSize];

	int  top;//ջ��ָ��

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

		printf("ջ����");

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

		printf("ջ�ѿ�");

		return NULL;

	}

	else

	{

		return s->Date[(s->top)--];

	}

}

///////////////////////////////////

// ��ȡһ����Ч�ַ�

char Getchar()

{

	char c[20] = {};

	gets_s(c, 20);

	if (c[1]) return '#';

	return c[0];

}

// ��ȡһ����Ч���֣������û��������͵�������ɳ��������

int Getint()

{

	char c[20] = {};

	gets_s(c, 20);

	int n = 0;

	int k = 0;

	while (c[k])k++;

	for (int i = 0; c[i]; i++)

	{

		if (c[i] < 48 || c[i] > 58)return 0;	// �����ַ�

		else

		{

			int t = 1;

			for (int i = --k; i > 0; i--)t = t * 10;

			n += (int(c[i]) - 48)*t;			// �ַ�ת����

		}

	}

	return n;

}

//ǰ������ݹ�

void preorder(bintree t)

{

	if (t != NULL)

	{

		printf("%c", t->data);

		preorder(t->Lchild);

		preorder(t->Rchild);

	}

}

//��������ݹ�

void midorder(bintree t)

{

	if (t != NULL)

	{

		midorder(t->Lchild);

		printf("%c", t->data);

		midorder(t->Rchild);

	}

}

//��������ݹ�

void behindorder(bintree t)

{

	if (t != NULL)

	{

		behindorder(t->Lchild);

		behindorder(t->Rchild);

		printf("%c", t->data);

	}

}

//ǰ������ǵݹ�ʵ��

void preorder1(bintree t)

{

	Stack s;

	bintree q = NULL;

	q = t;

	s = CreatStack();

	while ((q != NULL) || (!IsEmpty(s)))

	{

		while (q != NULL)//һֱ������;��ڵ�ѹ��ջ��

		{

			printf("%c ", q->data);

			Push(s, q);//��һ������q������

			q = q->Lchild;

		}

		if (!IsEmpty(s))

		{

			q = Pop(s);//�ڶ�������q���,��ʱ����൱��ֻ���Ҷ���û�������,����ֱ�����������ݼ���



			q = q->Rchild;//���ʴ˽ڵ���Ҷ���

		}

	}

}

//��������ǵݹ�ʵ��

void midorder1(bintree t)

{

	Stack s;

	bintree q;

	q = t;

	s = CreatStack();

	while ((q != NULL) || (!IsEmpty(s)))

	{

		while (q != NULL)//һֱ������;��ڵ�ѹ��ջ��

		{



			Push(s, q);//��q������ѹ��ջ��

			q = q->Lchild;

		}

		if (!IsEmpty(s))

		{

			q = Pop(s);//�ڶ�������q���,��ʱ����൱��ֻ���Ҷ���û�������,����ֱ�����������ݼ���

			printf("%c ", q->data);//��һ������q������

			q = q->Rchild;//���ʴ˽ڵ���Ҷ���

		}

	}

}

//��������ǵݹ�ʵ��

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

			if (t->Rchild == NULL || t->Rchild == r)//����������������

			{

				printf("%c ", t->data);

				r = t;

				t = NULL;

			}

			else//��û�з���������

			{

				Push(s, t);

				t = t->Rchild;

			}

		}



	}

}

//ʵ�ֶ������Ĳ��ң����ص�ַ

bintree locate(bintree t, datatype x)

{

	bintree p;

	if (t == NULL)

	{

		//printf("�����ǿ�����\n");

		return NULL;

	}

	else

		if (t->data == x)

			return t;

		else

		{

			p = locate(t->Lchild, x);//�������������

			if (p != NULL)

				return p;

			else

				return locate(t->Rchild, x);//���������������

		}

}

//ͳ�ƶ������н��ĸ���

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

//ͳ�ƶ�������Ҷ�ӽ��ĸ���(�ݹ�)

int numofbTreeleaves(bintree t)

{



	if ((t->Lchild == NULL) && (t->Rchild == NULL))

	{

		return 1;

	}

	else

	{

		if (t->Lchild == NULL && (t->Rchild != NULL))//���������Ϊ�գ���ô��ȥ����������Ҷ�ӵĸ���

			return numofbTreeleaves(t->Rchild);

		else if (t->Rchild == NULL && t->Lchild != NULL)

			return numofbTreeleaves(t->Lchild);

		else if ((t->Lchild != NULL) && (t->Rchild != NULL))

			return numofbTreeleaves(t->Lchild) + numofbTreeleaves(t->Rchild);

	}

}

//ͳ�ƶ�������Ҷ�ӽ��ĸ���(�ǵݹ�)

int numofbTreeleaves1(bintree t)

{

	//��ǰ������Ĺ����в���Ҷ�ӽ��

	int count = 0;

	Stack s;

	bintree q = NULL;

	q = t;

	s = CreatStack();

	while ((q != NULL) || (!IsEmpty(s)))

	{

		while (q != NULL)//һֱ������;��ڵ�ѹ��ջ��

		{

			Push(s, q);//��һ������q������

			q = q->Lchild;

		}

		if (!IsEmpty(s))

		{

			q = Pop(s);

			if ((q->Lchild == NULL) && (q->Rchild == NULL))

			{

				count++;

			}

			q = q->Rchild;//���ʴ˽ڵ���Ҷ���

		}

	}

	return count;

}

//���һ�ø�������������������µ����һ�����

void Btnode_end_value(bintree t)

{

	Stack s;

	bintree q, r = NULL;

	q = t;

	s = CreatStack();

	while (q != NULL)//һֱ���ҽ���;�ҽڵ�ѹ��ջ��

	{

		Push(s, q);//��һ������q������

		q = q->Rchild;

	}

	r = Pop(s);

	printf("%c\n", r->data);

}

//��������������㣬�����������������Ĺ�ͬ����

bintree Btnode_nearest_parents(bintree t, bintree p, bintree q)

{

	if (t == NULL || p == t || q == t)//����ǿÿ�������p,q��һ���Ǹ��ڵ���ô��ͬ���ȼ�Ϊ�����

		return t;

	bintree left = Btnode_nearest_parents(t->Lchild, p, q);//��������������Ѱ�������ͬ����

	bintree right = Btnode_nearest_parents(t->Rchild, p, q);

	if (left != NULL && right != NULL)//��������������صĽ������Ϊ�գ���ô�����ͬ���ȿ϶��Ǹ��ڵ�

		return t;

	else

		return left == NULL ? right : left;

}

//��������depth

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

//����һ�ö����������ú���������ٶ�������

void destroy_btree(bintree t)//�����ֻ��root��һ�����Ʒ,�˺����޷�ɾ��root��Ҫ��ɾ���ô���ָ���ָ�롣

{

	if (t == NULL)//����

		return;

	destroy_btree(t->Lchild);

	destroy_btree(t->Rchild);

	free(t);

	return;

}

//����ǰ������Ľ������һ��������

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



	bool LOOP = true;					// ѭ�����Ʊ���

	int Choice_Num = -1;				// ѡ�������

	while (LOOP)

	{

		system("cls");

		printf("\n");

		printf("\n\t\t*******************************\n");

		printf("\n\t\t******\t 1. ǰ�������������      ******\n");

		printf("\n\t\t******\t 2. ǰ��������ݹ飩      ******\n");

		printf("\n\t\t******\t 3. ����������ݹ飩     ******\n");

		printf("\n\t\t******\t 4. ����������ݹ飩       ******\n");

		printf("\n\t\t******\t 5. ǰ��������ǵݹ飩       ******\n");

		printf("\n\t\t******\t 6. ����������ǵݹ飩       ******\n");

		printf("\n\t\t******\t 7. ����������ǵݹ飩       ******\n");

		printf("\n\t\t******\t 8. �������н��ĸ���       ******\n");

		printf("\n\t\t******\t 9. �����������       ******\n");

		printf("\n\t\t******\t 10. ��������Ҷ�ӽ��ĸ������ݹ飩       ******\n");

		printf("\n\t\t******\t 11. ��������Ҷ�ӽ��ĸ������ǵݹ飩       ******\n");

		printf("\n\t\t******\t 12. �����������������µ����һ�����ֵ       ******\n");

		printf("\n\t\t******\t 13. �������������������ͬ����       ******\n");

		printf("\n\t\t******\t 14. ����һ�ö�����       ******\n");

		printf("\n\t\t******\t 15.�˳�����ϵͳ ******\n");

		printf("\n\t\t*******************************\n");

		printf("\n\t\t��������ѡ������ı�ţ�");

		Choice_Num = Getint();

		switch (Choice_Num)

		{

		case 1:

			system("cls");



			root = createbintree();



			printf("\n\t\t�밴���������!");

			getchar();

			break;

		case 2:

			system("cls");



			preorder(root);

			printf("\n\t\t�밴���������!");

			getchar();

			break;

		case 3:

			system("cls");

			midorder(root);



			printf("\n\t\t�밴���������!");

			getchar();

			break;

		case 4:

			system("cls");

			behindorder(root);

			printf("\n\t\t�밴���������!");

			getchar();

			break;

		case 5:

			system("cls");

			preorder1(root);



			printf("\n\t\t�밴���������!");

			getchar();

			break;

		case 6:

			system("cls");

			midorder1(root);



			printf("\n\t\t�밴���������!");

			getchar();

			break;

		case 7:

			system("cls");

			behindorder1(root);



			printf("\n\t\t�밴���������!");

			getchar();

			break;

		case 8:

			system("cls");

			int count;

			count = numofbTree(root);

			printf("%d\n", count);

			printf("\n\t\t�밴���������!");

			getchar();

			break;

		case 9:

			system("cls");

			count = depth(root);

			printf("%d\n", count);

			printf("\n\t\t�밴���������!");

			getchar();

			break;

		case 10:

			system("cls");

			count = numofbTreeleaves(root);

			printf("%d\n", count);

			printf("\n\t\t�밴���������!");

			getchar();

			break;

		case 11:

			system("cls");

			count = numofbTreeleaves1(root);

			printf("%d\n", count);

			printf("\n\t\t�밴���������!");

			getchar();

			break;

		case 12:

			system("cls");

			Btnode_end_value(root);

			printf("\n\t\t�밴���������!");

			getchar();

			break;

		case 13:

			system("cls");

			bintree p, q, r;

			char  a, b;

			printf("������Ҫ���ҵ���������ֵ\n");

			scanf_s("%c %c", &a, 1, &b, 1);

			p = locate(root, a);

			q = locate(root, b);

			if (p == NULL && q != NULL)

				printf("����û�н��%c\n", a);

			else if (q == NULL && p != NULL)

				printf("����û�н��%c\n", b);

			else if (!p && !q)

				printf("����û�н��%c��%c\n", a, b);

			else

			{

				r = Btnode_nearest_parents(root, p, q);

				printf("%c\n", r->data);

			}

			Sleep(2000);

			printf("\n\t\t�밴���������!");

			getchar();

			break;

		case 14:

			system("cls");

			destroy_btree(root);

			root = NULL;

			printf("\n\t\t�밴���������!");

			getchar();

			break;

		case 15:

			printf("\n\t\t�밴������˳�����ϵͳ");

			getchar();

			return 0;

		default:

			printf("\n\t\t�������󣡰����������");

			getchar();

			break;

		}

	}

	return 1;

}

int main()

{

	system("mode con cols=63 lines=46,color 12");       /*�������ڴ�С*/

	while (menu());

	system("pause");
	return 0;

}


