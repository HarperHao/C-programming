#include<stdio.h>
#include<stdlib.h>
#include<string.h>
const int MAXSIZE = 1000;//文件中商品个数的最大值
typedef int keytype;//定义排序码类型
typedef struct {
	keytype Price;//商品单价
	int number;//库存数量
	char name[10];//商品名称
	int identifier;//商品编号

}stu;
typedef struct {
	stu S[MAXSIZE];//商品集体
	int length;//当前商品的个数
}table;
typedef table* tab;
//初始化
tab init()
{
	tab t;
	t = (tab)malloc(sizeof(table));
	t->length = 0;
	return t;
}
//读取文件
tab ReadFile(tab t, const char *filename)
{
	FILE *f;
	errno_t err;
	err = fopen_s(&f, filename, "r");
	if (err != 0)
	{
		printf("文件不存在！\n");
	}
	//读取文件成功
	else if (err == 0)
	{
		fscanf_s(f, "%d", &(t->length));//读入商品的个数
		for (int i = 0; i < t->length; i++)
		{
			fscanf_s(f, "%d %s %d %d", &((t->S[i]).identifier), ((t->S[i]).name), 10, &((t->S[i]).Price), &((t->S[i]).number));
		}
	}
	fclose(f);
	return t;
}
//按商品单价进行排序
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
		//抽牌
		for (i = D; i < t->length; i++)
		{
			temp = t->S[i].Price;
			tmp = t->S[i];
			//挪位置
			for (j = i; temp < t->S[j - D].Price&&j >= D; j = j - D)
			{
				t->S[j] = t->S[j - D];
			}
			//插牌
			t->S[j] = tmp;
		}
	}
}
//按商品名称进行排序
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
		//抽牌
		for (i = D; i < t->length; i++)
		{
			strcpy_s(temp, t->S[i].name);
			tmp = t->S[i];
			//挪位置
			for (j = i; strcmp(temp, t->S[j - D].name) < 0 && j >= D; j = j - D)
			{
				t->S[j] = t->S[j - D];
			}
			//插牌
			t->S[j] = tmp;
		}
	}

}
//按商品数量进行排序,error
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
		//抽牌
		for (i = D; i < t->length; i++)
		{
			temp = t->S[i].number;
			tmp = t->S[i];
			//挪位置
			for (j = i; temp < t->S[j - D].number&&j >= D; j = j - D)
			{
				t->S[j] = t->S[j - D];
			}
			//插牌
			t->S[j] = tmp;
		}
	}

}
//输出商品信息
void Print(tab t)
{
	int i;
	if (!(t->length))
	{
		printf("库存中无商品！\n");
	}
	else
	{
		for (i = 0; i < t->length; i++)
		{
			printf("%10d %10s %10d %10d \n", t->S[i].identifier, t->S[i].name, t->S[i].Price, t->S[i].number);
		}
	}
	printf("排序成功！\n");
}
//添加商品信息
void Add(tab t)
{
	int i;
	if (t->length > MAXSIZE)
	{
		printf("仓库已满！\n");
	}
	else
	{
		printf("请依次输入商品编号,商品名称,商品单价,商品库存数量!\n");
		scanf_s("%d %s %d %d", &t->S[t->length].identifier, t->S[t->length].name, 10, &t->S[t->length].Price, &t->S[t->length].number);
		FILE *f;
		fopen_s(&f, "Goods_Data.txt", "a+");
		fprintf_s(f, "%d %s %d %d", t->S[t->length].identifier, t->S[t->length].name, t->S[t->length].Price, t->S[t->length].number);
		t->length++;
		/*i=fseek(f, 0L, SEEK_SET);
		printf("%d", i);
		fprintf_s(f, "%d\n", t->length);*/
		fclose(f);
		printf("添加商品信息成功！\n");
	}
}
//删除商品信息
void Delete(tab t)
{
	int flag;
	int i = 0;
	int j;
	printf("请输入要删除的商品的编号\n");
	scanf_s("%d", &flag);
	for (; i < t->length&&flag != t->S[i].identifier; i++)
	{
		;
	}
	if (i + 1 < t->length)//找到了
	{
		//目标在i这个位置上,总共有length个元素,最后一个元素下标是length-1
		for (j = i + 1; j <= t->length - 1; j++)
		{
			t->S[j - 1] = t->S[j];
		}
		t->length--;
		printf("删除商品信息成功！\n");
	}
	else
	{
		printf("仓库中没有编号为%d的商品！", flag);
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
			printf("\n\t\t*************欢迎使用商品信息管理系统******************\n");
			printf("\n\t\t******\t 1. 读取文件       ******\n");
			printf("\n\t\t******\t 2. 按商品单价进行排序       ******\n");
			printf("\n\t\t******\t 3.按商品名称进行排序       ******\n");
			printf("\n\t\t******\t 4.按商品数量进行排序       ******\n");
			printf("\n\t\t******\t 5. 查看所有信息       ******\n");
			printf("\n\t\t******\t 6.删除商品信息       ******\n");
			printf("\n\t\t******\t 7. 添加商品信息      ******\n");
			printf("\n\t\t******\t 8.退出操作系统 ******\n");
			printf("\n\t\t****************************************************\n");
			printf("\n\t\t请输入您选择操作的编号：");
			scanf_s("%d", &i);
			switch (i)
			{
			case 1:
				system("cls");
				t = ReadFile(t, "Goods_Data.txt");
				printf("读取文件成功！\n");
				printf("\n\t\t请按任意键继续!");
				getchar();
				getchar();
				break;
			case 2:
				system("cls");
				Shell_sort1(t);
				printf("排序成功！\n");
				printf("\n\t\t请按任意键继续!");
				getchar();
				getchar();
				break;
			case 3:
				system("cls");
				Shell_sort2(t);
				printf("排序成功！\n");
				printf("\n\t\t请按任意键继续!");
				getchar();
				getchar();
				break;
			case 4:
				system("cls");
				Shell_sort3(t);
				printf("排序成功！\n");
				printf("\n\t\t请按任意键继续!");
				getchar();
				getchar();
				break;
			case 5:
				system("cls");
				Print(t);
				printf("\n\t\t请按任意键继续!");
				getchar();
				getchar();
				break;
			case 6:
				system("cls");
				Delete(t);
				printf("\n\t\t请按任意键继续!");
				getchar();
				getchar();
				break;
			case 7:
				system("cls");
				Add(t);
				printf("\n\t\t请按任意键继续!");
				getchar();
				getchar();
				break;
			case 8:					// 退出（该分支请勿修改）
				printf("\n\t\t请按任意键退出操作系统");
				getchar();
				return 0;
			default:
				printf("\n\t\t输入有误！按任意键继续");
				getchar();
				break;
			}
		}
	}
	printf("\n\n");
	system("pause");
	return 0;
}