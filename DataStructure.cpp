#include<stdio.h>
#include<stdlib.h>
#include<string.h>
const int MAXSIZE = 100;//文件中学生个数的最大值
typedef int keytype;//定义排序码类型
typedef struct {
	keytype ID_Card;
	int class_num;
	char name[10];
	char sex[5];
	char department[10];//系别
	
}stu;
typedef struct {
	stu S[MAXSIZE];//学生集体
	int length;//当前学生的个数
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
	if (err!=0)
	{
		printf("文件不存在！\n");
	}
	//读取文件成功
	else if(err==0)
	{
		fscanf_s(f, "%d", &(t->length));//读入学生的个数
		for (int i = 0; i < t->length; i++)
		{
			fscanf_s(f, "%s %s %s %d %d", ((t->S[i]).name),10,  ((t->S[i]).sex),5, ((t->S[i]).department),10, &((t->S[i]).ID_Card), &((t->S[i]).class_num));
		}
	}
	fclose(f);
	return t;
}
//按卡号进行排序
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
		//抽牌
		for (i = D; i < t->length; i++)
		{
			temp = t->S[i].ID_Card;
			tmp = t->S[i];
			//挪位置
			for (j = i; temp < t->S[j - D].ID_Card&&j >= D; j = j - D)
			{
				t->S[j] = t->S[j - D];
			}
			//插牌
			t->S[j] = tmp;
		}
	}
}
//查找某个系的学生的所有信息,并输出
void search(tab t,char A[])
{
	int i ;
	int flag = 0;
	printf("%10s%10s%10s%10s%10s\n", "姓名", "性别", "系别", "班号", "图书卡号");
	for (i = 0; i < t->length; i++)
	{
		if (!(strcmp(A, t->S[i].department)))//如果一样
		{
			printf("%10s %10s %10s %d %d",t->S[i].name, t->S[i].sex,t->S[i].department, t->S[i].class_num, t->S[i].ID_Card);
			printf("\n");
			flag++;
		}
	}
	if (flag == 0)
	{
		printf("%s的学生没有借书！\n", A);
	}
}
int main()
{
	char A[10];
	tab t = NULL;
	t = init();
	t = ReadFile(t, "Library_Data.txt");
	Shell_sort(t);
	printf("\t\t请输入要查找的系别:\t\t");
	scanf_s("%s", A, 10);
	printf("\n\n");
	search(t, A);
	system("pause");
	return 0;
}