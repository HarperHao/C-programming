#include<stdio.h>
#include<stdlib.h>
#include<string.h>
const int MAXSIZE = 1000;//�ļ�����Ʒ���������ֵ
typedef int keytype;//��������������
typedef struct {
	keytype Price;//��Ʒ����
	int number;//�������
	char name[10];//��Ʒ����
	int identifier;//��Ʒ���

}stu;
typedef struct {
	stu S[MAXSIZE];//��Ʒ����
	int length;//��ǰ��Ʒ�ĸ���
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
	if (err != 0)
	{
		printf("�ļ������ڣ�\n");
	}
	//��ȡ�ļ��ɹ�
	else if (err == 0)
	{
		fscanf_s(f, "%d", &(t->length));//������Ʒ�ĸ���
		for (int i = 0; i < t->length; i++)
		{
			fscanf_s(f, "%d %s %d %d", &((t->S[i]).identifier), ((t->S[i]).name), 10, &((t->S[i]).Price), &((t->S[i]).number));
		}
	}
	fclose(f);
	return t;
}
//����Ʒ���۽�������
void Shell_sort1(tab t)
{
	int Si, D, i, j;
	stu tmp;
	keytype temp;
	int Sedgewick[] = { 929, 505, 209, 109, 41, 19, 5, 1, 0 };
	for (Si = 0; Sedgewick[Si] >= t->length; Si++)
	{
		;
	}
	for (D = Sedgewick[Si]; D > 0; D = Sedgewick[++Si])
	{
		//����
		for (i = D; i < t->length; i++)
		{
			temp = t->S[i].Price;
			tmp = t->S[i];
			//Ųλ��
			for (j = i; temp < t->S[j - D].Price&&j >= D; j = j - D)
			{
				t->S[j] = t->S[j - D];
			}
			//����
			t->S[j] = tmp;
		}
	}
}
//����Ʒ���ƽ�������
void Shell_sort2(tab t)
{
	int Si, D, i, j;
	stu tmp;
	char temp[10];
	int Sedgewick[] = { 929, 505, 209, 109, 41, 19, 5, 1, 0 };
	for (Si = 0; Sedgewick[Si] >= t->length; Si++)
	{
		;
	}
	for (D = Sedgewick[Si]; D > 0; D = Sedgewick[++Si])
	{
		//����
		for (i = D; i < t->length; i++)
		{
			strcpy_s(temp, t->S[i].name);
			tmp = t->S[i];
			//Ųλ��
			for (j = i; strcmp(temp, t->S[j - D].name) < 0 && j >= D; j = j - D)
			{
				t->S[j] = t->S[j - D];
			}
			//����
			t->S[j] = tmp;
		}
	}

}
//����Ʒ������������,error
void Shell_sort3(tab t)
{
	int Si, D, i, j;
	int temp;
	stu tmp;
	int Sedgewick[] = { 929, 505, 209, 109, 41, 19, 5, 1, 0 };
	for (Si = 0; Sedgewick[Si] >= t->length; Si++)
	{
		;
	}
	for (D = Sedgewick[Si]; D > 0; D = Sedgewick[++Si])
	{
		//����
		for (i = D; i < t->length; i++)
		{
			temp = t->S[i].number;
			tmp = t->S[i];
			//Ųλ��
			for (j = i; temp < t->S[j - D].number&&j >= D; j = j - D)
			{
				t->S[j] = t->S[j - D];
			}
			//����
			t->S[j] = tmp;
		}
	}

}
//�����Ʒ��Ϣ
void Print(tab t)
{
	int i;
	if (!(t->length))
	{
		printf("���������Ʒ��\n");
	}
	else
	{
		for (i = 0; i < t->length; i++)
		{
			printf("%10d %10s %10d %10d \n", t->S[i].identifier, t->S[i].name, t->S[i].Price, t->S[i].number);
		}
	}
	printf("����ɹ���\n");
}
//�����Ʒ��Ϣ
void Add(tab t)
{
	int i;
	if (t->length > MAXSIZE)
	{
		printf("�ֿ�������\n");
	}
	else
	{
		printf("������������Ʒ���,��Ʒ����,��Ʒ����,��Ʒ�������!\n");
		scanf_s("%d %s %d %d", &t->S[t->length].identifier, t->S[t->length].name, 10, &t->S[t->length].Price, &t->S[t->length].number);
		FILE *f;
		fopen_s(&f, "Goods_Data.txt", "a+");
		fprintf_s(f, "%d %s %d %d", t->S[t->length].identifier, t->S[t->length].name, t->S[t->length].Price, t->S[t->length].number);
		t->length++;
		/*i=fseek(f, 0L, SEEK_SET);
		printf("%d", i);
		fprintf_s(f, "%d\n", t->length);*/
		fclose(f);
		printf("�����Ʒ��Ϣ�ɹ���\n");
	}
}
//ɾ����Ʒ��Ϣ
void Delete(tab t)
{
	int flag;
	int i = 0;
	int j;
	printf("������Ҫɾ������Ʒ�ı��\n");
	scanf_s("%d", &flag);
	for (; i < t->length&&flag != t->S[i].identifier; i++)
	{
		;
	}
	if (i + 1 < t->length)//�ҵ���
	{
		//Ŀ����i���λ����,�ܹ���length��Ԫ��,���һ��Ԫ���±���length-1
		for (j = i + 1; j <= t->length - 1; j++)
		{
			t->S[j - 1] = t->S[j];
		}
		t->length--;
		printf("ɾ����Ʒ��Ϣ�ɹ���\n");
	}
	else
	{
		printf("�ֿ���û�б��Ϊ%d����Ʒ��", flag);
	}
}
int main()
{
	int i;
	tab t = NULL;
	t = init();
	while (1)
	{
		while (1)
		{
			system("color 2");
			system("cls");
			printf("\n");
			printf("\n\t\t*************��ӭʹ����Ʒ��Ϣ����ϵͳ******************\n");
			printf("\n\t\t******\t 1. ��ȡ�ļ�       ******\n");
			printf("\n\t\t******\t 2. ����Ʒ���۽�������       ******\n");
			printf("\n\t\t******\t 3.����Ʒ���ƽ�������       ******\n");
			printf("\n\t\t******\t 4.����Ʒ������������       ******\n");
			printf("\n\t\t******\t 5. �鿴������Ϣ       ******\n");
			printf("\n\t\t******\t 6.ɾ����Ʒ��Ϣ       ******\n");
			printf("\n\t\t******\t 7. �����Ʒ��Ϣ      ******\n");
			printf("\n\t\t******\t 8.�˳�����ϵͳ ******\n");
			printf("\n\t\t****************************************************\n");
			printf("\n\t\t��������ѡ������ı�ţ�");
			scanf_s("%d", &i);
			switch (i)
			{
			case 1:
				system("cls");
				t = ReadFile(t, "Goods_Data.txt");
				printf("��ȡ�ļ��ɹ���\n");
				printf("\n\t\t�밴���������!");
				getchar();
				getchar();
				break;
			case 2:
				system("cls");
				Shell_sort1(t);
				printf("����ɹ���\n");
				printf("\n\t\t�밴���������!");
				getchar();
				getchar();
				break;
			case 3:
				system("cls");
				Shell_sort2(t);
				printf("����ɹ���\n");
				printf("\n\t\t�밴���������!");
				getchar();
				getchar();
				break;
			case 4:
				system("cls");
				Shell_sort3(t);
				printf("����ɹ���\n");
				printf("\n\t\t�밴���������!");
				getchar();
				getchar();
				break;
			case 5:
				system("cls");
				Print(t);
				printf("\n\t\t�밴���������!");
				getchar();
				getchar();
				break;
			case 6:
				system("cls");
				Delete(t);
				printf("\n\t\t�밴���������!");
				getchar();
				getchar();
				break;
			case 7:
				system("cls");
				Add(t);
				printf("\n\t\t�밴���������!");
				getchar();
				getchar();
				break;
			case 8:					// �˳����÷�֧�����޸ģ�
				printf("\n\t\t�밴������˳�����ϵͳ");
				getchar();
				return 0;
			default:
				printf("\n\t\t�������󣡰����������");
				getchar();
				break;
			}
		}
	}
	printf("\n\n");
	system("pause");
	return 0;
}