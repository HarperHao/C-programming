#include<stdio.h>
#include<stdlib.h>
typedef int ElementType;
typedef struct HNode *Heap;
const int MAXDATA = 1000;//����Ԫ�ص����ֵ����
struct HNode {
	ElementType *Data;//����Ԫ�ص�����
	int size;//���е�ǰԪ�صĸ���
	int capacity;//�ѵ��������
};
typedef Heap MaxHeap;
//��������ΪMaxSize�Ŀյ�����
MaxHeap CreatHeap(int MaxSize)
{
	MaxHeap H = (MaxHeap)malloc(sizeof(HNode));
	H->Data = (ElementType *)malloc((MaxSize + 1) * sizeof(ElementType));
	H->size = 0;
	H->capacity = MaxSize;
	H->Data[0] = MAXDATA;
	return H;
}
//�ж϶��Ƿ�Ϊһ���ն�
bool IsEmpty(MaxHeap H)
{
	if (H->size == 0)
		return true;
	else
		return false;
}
//�ж϶��Ƿ�����
bool IsFull(MaxHeap H)
{
	return (H->capacity == H->size);
}
//��һ����Ԫ�ز������
void Insert(MaxHeap H,ElementType X)
{
	int i;
	if (IsFull(H))
	{
		printf("����������\n");
	}
	else
	{
		i = ++(H->size);
		//���Ϲ���X
		for (; H->Data[i / 2] < X; i = i / 2)
		{
			H->Data[i] = H->Data[i / 2];
		}
		H->Data[i] = X;
	}
}
//ȡ�������е����Ԫ��
ElementType DeleteMax(MaxHeap H)
{
	int parent, child;
	ElementType Maxitem, X;
	if (IsEmpty(H))
	{
		printf("����Ϊ�գ�\n");
		return -1;
	}
	else
	{
		Maxitem = H->Data[1];
		//������,ʹ��ά����ṹ
		X = H->Data[(H->size)--];//ȡ�������һ�����
		for (parent = 1; parent * 2 <= H->size; parent =child)//���������ӽ��
		{
			child = parent * 2;
			//�������ӽ���е����ֵ
			if (child + 1 <= H->size&&H->Data[child + 1] > H->Data[child])//�����ӽ��,�����ӽ��������ӽ��
				child++;
			if (H->Data[child] > X)
			{
				H->Data[parent] = H->Data[child];
			}
			else//�ҵ��˺��ʵ�λ��
			{
				break;
			}
			
		}
		H->Data[parent] = X;
		return Maxitem;
	}

}
//����
void Swap(ElementType *a, ElementType *b)
{
	ElementType c;
	c = *a;
	*a = *b;
	*b = c;
}
//�³�(��һ������ת��Ϊ��)
void PercDown(ElementType A[], int p, int N)
{
	//����N��Ԫ�ص�������A[p]Ϊ�����Ӷѵ�����Ϊ����
	//���նѵ�ɾ������
	int parent, child;
	ElementType x;
	x = A[p];//ȡ�����ڵ��ֵ
	for (parent = p; (parent * 2 + 1) < N; parent = child) //�ڶ���������0Ϊ���
	{
		child = parent * 2+1;
		if ((child != N - 1) && (A[child] < A[child + 1]))//Child != H->Size
		{
			child++;
		}
		if (x > A[child])//�ҵ���
		{
			break;
		}
		else//����
		{
			A[parent] = A[child];
		}
	}
	A[parent] = x;
}
//������
void HeapSort(ElementType A[], int N)
{
	int i;
	for (i = N / 2 - 1; i >= 0; i--)
		PercDown(A, i, N);
	for (i = N - 1; i >= 0; i--)
	{
		Swap(&A[0], &A[i]);
		PercDown(A, 0, i);
	}
}
int main()
{
	ElementType A[5] = { 1,3,5,2,4 };
	printf("����ǰ��");
	for (int i = 0; i < 5; i++)
	{
		printf("%d ", A[i]);
	}	
	printf("\n");
	HeapSort(A, 5);
	printf("�����");
	for (int i = 0; i < 5; i++)
		printf("%d ", A[i]);
	system("pause");
	return 0;
}