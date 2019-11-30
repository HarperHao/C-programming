#include<stdio.h>
#include<stdlib.h>
typedef int ElementType;
typedef struct HNode *Heap;
const int MAXDATA = 1000;//堆中元素的最大值上限
struct HNode {
	ElementType *Data;//储存元素的数组
	int size;//堆中当前元素的个数
	int capacity;//堆的最大容量
};
typedef Heap MaxHeap;
//创建容量为MaxSize的空的最大堆
MaxHeap CreatHeap(int MaxSize)
{
	MaxHeap H = (MaxHeap)malloc(sizeof(HNode));
	H->Data = (ElementType *)malloc((MaxSize + 1) * sizeof(ElementType));
	H->size = 0;
	H->capacity = MaxSize;
	H->Data[0] = MAXDATA;
	return H;
}
//判断堆是否为一个空堆
bool IsEmpty(MaxHeap H)
{
	if (H->size == 0)
		return true;
	else
		return false;
}
//判断堆是否满了
bool IsFull(MaxHeap H)
{
	return (H->capacity == H->size);
}
//将一个新元素插入堆中
void Insert(MaxHeap H,ElementType X)
{
	int i;
	if (IsFull(H))
	{
		printf("最大堆已满！\n");
	}
	else
	{
		i = ++(H->size);
		//向上过滤X
		for (; H->Data[i / 2] < X; i = i / 2)
		{
			H->Data[i] = H->Data[i / 2];
		}
		H->Data[i] = X;
	}
}
//取出最大堆中的最大元素
ElementType DeleteMax(MaxHeap H)
{
	int parent, child;
	ElementType Maxitem, X;
	if (IsEmpty(H))
	{
		printf("最大堆为空！\n");
		return -1;
	}
	else
	{
		Maxitem = H->Data[1];
		//调整堆,使其维持其结构
		X = H->Data[(H->size)--];//取出的最后一个结点
		for (parent = 1; parent * 2 <= H->size; parent =child)//至少有左子结点
		{
			child = parent * 2;
			//找左右子结点中的最大值
			if (child + 1 <= H->size&&H->Data[child + 1] > H->Data[child])//有右子结点,且右子结点大于左子结点
				child++;
			if (H->Data[child] > X)
			{
				H->Data[parent] = H->Data[child];
			}
			else//找到了合适的位置
			{
				break;
			}
			
		}
		H->Data[parent] = X;
		return Maxitem;
	}

}
//交换
void Swap(ElementType *a, ElementType *b)
{
	ElementType c;
	c = *a;
	*a = *b;
	*b = c;
}
//下沉(把一个数组转换为堆)
void PercDown(ElementType A[], int p, int N)
{
	//将有N个元素的数组以A[p]为根的子堆调整成为最大堆
	//仿照堆的删除操作
	int parent, child;
	ElementType x;
	x = A[p];//取出根节点的值
	for (parent = p; (parent * 2 + 1) < N; parent = child) //在堆排序中以0为起点
	{
		child = parent * 2+1;
		if ((child != N - 1) && (A[child] < A[child + 1]))//Child != H->Size
		{
			child++;
		}
		if (x > A[child])//找到了
		{
			break;
		}
		else//下滤
		{
			A[parent] = A[child];
		}
	}
	A[parent] = x;
}
//堆排序
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
	printf("排序前：");
	for (int i = 0; i < 5; i++)
	{
		printf("%d ", A[i]);
	}	
	printf("\n");
	HeapSort(A, 5);
	printf("排序后：");
	for (int i = 0; i < 5; i++)
		printf("%d ", A[i]);
	system("pause");
	return 0;
}