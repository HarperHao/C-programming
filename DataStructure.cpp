#include<stdio.h>
#include<stdlib.h>
#include<string.h>
const int MAXSIZE = 100;//�ļ���ѧ�����������ֵ
typedef int keytype;//��������������
typedef struct {
	keytype ID_Card;
	int class_num;
	char name[10];
	char sex[5];
	char department[10];//ϵ��
	
}stu;
typedef struct {
	stu S[MAXSIZE];//ѧ������
	int length;//��ǰѧ���ĸ���
}table;
typedef table* tab;
//��ʼ��
tab init()
{
	tab t;
	t = (tab)malloc(sizeof(table));
	t->length = 0;
	return t;
}
//��ȡ�ļ�
tab ReadFile(tab t, const char *filename)
{
	FILE *f;
	errno_t err;
	err = fopen_s(&f, filename, "r");
	if (err!=0)
	{
		printf("�ļ������ڣ�\n");
	}
	//��ȡ�ļ��ɹ�
	else if(err==0)
	{
		fscanf_s(f, "%d", &(t->length));//����ѧ���ĸ���
		for (int i = 0; i < t->length; i++)
		{
			fscanf_s(f, "%s %s %s %d %d", ((t->S[i]).name),10,  ((t->S[i]).sex),5, ((t->S[i]).department),10, &((t->S[i]).ID_Card), &((t->S[i]).class_num));
		}
	}
	fclose(f);
	return t;
}
//�����Ž�������
void Shell_sort(tab t)
{
	int Si,D,i,j;
	stu tmp;
	keytype temp;
	int Sedgewick[] = { 929, 505, 209, 109, 41, 19, 5, 1, 0 };
	for (Si = 0; Sedgewick[Si] >= t->length; Si++)
	{
		;
	}
	for (D = Sedgewick[Si]; D > 0; D=Sedgewick[++Si])
	{
		//����
		for (i = D; i < t->length; i++)
		{
			temp = t->S[i].ID_Card;
			tmp = t->S[i];
			//Ųλ��
			for (j = i; temp < t->S[j - D].ID_Card&&j >= D; j = j - D)
			{
				t->S[j] = t->S[j - D];
			}
			//����
			t->S[j] = tmp;
		}
	}
}
//����ĳ��ϵ��ѧ����������Ϣ,�����
void search(tab t,char A[])
{
	int i ;
	int flag = 0;
	printf("%10s%10s%10s%10s%10s\n", "����", "�Ա�", "ϵ��", "���", "ͼ�鿨��");
	for (i = 0; i < t->length; i++)
	{
		if (!(strcmp(A, t->S[i].department)))//���һ��
		{
			printf("%10s %10s %10s %d %d",t->S[i].name, t->S[i].sex,t->S[i].department, t->S[i].class_num, t->S[i].ID_Card);
			printf("\n");
			flag++;
		}
	}
	if (flag == 0)
	{
		printf("%s��ѧ��û�н��飡\n", A);
	}
}
int main()
{
	char A[10];
	tab t = NULL;
	t = init();
	t = ReadFile(t, "Library_Data.txt");
	Shell_sort(t);
	printf("\t\t������Ҫ���ҵ�ϵ��:\t\t");
	scanf_s("%s", A, 10);
	printf("\n\n");
	search(t, A);
	system("pause");
	return 0;
}