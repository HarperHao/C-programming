#include<stdio.h>
#include<stdlib.h>
void Shellsort_sedgewick(int A[], int n)
{
	/* 希尔排序 - 用Sedgewick增量序列 */
	int Si, D, P, i, temp;
	int Sedgewick[]= { 929, 505, 209, 109, 41, 19, 5, 1, 0 };
	/* 初始的增量Sedgewick[Si]不能超过待排序列长度 */
	for (Si = 0; Sedgewick[Si] >= n; Si++)
	{
		;
	}
	for (D = Sedgewick[Si]; D > 0;D=Sedgewick[++Si])
	{
		for (P = D; P < n; P++)//抽牌
		{
			temp = A[P];
			for (i = P; i >= D && A[i - D] > temp; i = i - D)//挪牌
			{
				A[i] = A[i - D];
			}
			A[i] = temp;//插牌
		}
	}
}
void Insert_sort(int A[], int n)
{
	int i, j,temp;
	for (i = 1; i < n; i++)//从1开始抽牌
	{
		temp = A[i];//保存当前的牌
		for (j = i; j > 0 && A[j-1] > temp; j--)//挪牌
		{
			A[j] = A[j - 1];
		}
		A[j] = temp;//插牌
	}
}
void Shell_sort(int A[], int n)
{
	int D;
	int j;
	int i;
	for (D = n / 2; D > 0; D =D/ 2)//间隔（即分成了多少组）
	{
		for ( i = D; i < n; i++)//抽牌
		{
			int temp = A[i];//抽到的牌
			for ( j = i; j >= D && A[j - D] < temp; j = j - D)//挨个与前面的分组的牌进行比较
			{
				A[j] = A[j - D];
			}
			A[j] = temp;
		}
	}
}
int main()
{
	system("pause");
	return 0;
}