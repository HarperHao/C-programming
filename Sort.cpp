#include<stdio.h>
#include<stdlib.h>
void Shellsort_sedgewick(int A[], int n)
{
	/* ϣ������ - ��Sedgewick�������� */
	int Si, D, P, i, temp;
	int Sedgewick[]= { 929, 505, 209, 109, 41, 19, 5, 1, 0 };
	/* ��ʼ������Sedgewick[Si]���ܳ����������г��� */
	for (Si = 0; Sedgewick[Si] >= n; Si++)
	{
		;
	}
	for (D = Sedgewick[Si]; D > 0;D=Sedgewick[++Si])
	{
		for (P = D; P < n; P++)//����
		{
			temp = A[P];
			for (i = P; i >= D && A[i - D] > temp; i = i - D)//Ų��
			{
				A[i] = A[i - D];
			}
			A[i] = temp;//����
		}
	}
}
void Insert_sort(int A[], int n)
{
	int i, j,temp;
	for (i = 1; i < n; i++)//��1��ʼ����
	{
		temp = A[i];//���浱ǰ����
		for (j = i; j > 0 && A[j-1] > temp; j--)//Ų��
		{
			A[j] = A[j - 1];
		}
		A[j] = temp;//����
	}
}
void Shell_sort(int A[], int n)
{
	int D;
	int j;
	int i;
	for (D = n / 2; D > 0; D =D/ 2)//��������ֳ��˶����飩
	{
		for ( i = D; i < n; i++)//����
		{
			int temp = A[i];//�鵽����
			for ( j = i; j >= D && A[j - D] < temp; j = j - D)//������ǰ��ķ�����ƽ��бȽ�
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