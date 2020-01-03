#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include"Family.h"
typedef struct {
	char name[20];
	int age;
}stu;
// int main()
//{
//	FILE *fp;
//	int n;
//	scanf("%d", &n);
//	fp = fopen("temp.txt", "w");
//	fprintf(fp, "%d", n);
//	fclose(fp);
//	return 0;
//}
int main()
{
	person T;
	char filename[] = "JiaPu.txt";
	T = creat(filename);
	/*AddNewNode(T);
	save(T);*/
	//displaytree(T);
	system("pause");
	return 0;
}