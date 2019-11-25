#include<stdio.h>
#include<stdlib.h>
//节点数最多只能有100个
#define MaxVertexNum 100
#define INFINITY 65535
typedef char DataType;//顶点存储的数据类型为字符型
//图的邻接矩阵表示
typedef struct {
	DataType Vertexes[MaxVertexNum];//储存顶点信息
	int  GEdge[MaxVertexNum][MaxVertexNum];//储存边信息
	int num_Vertex;//顶点的个数	
	int num_GEdge;//边的个数
}Graph;
//图的生成函数
void CreatGraph(Graph*G)
{
	int nv, ne,i,j;
	int v1, v2, weight;
	printf("请输入图的顶点数和边数:\n");
	scanf_s("%d %d", &nv, &ne);
	getchar();
	G->num_GEdge = ne;
	G->num_Vertex = nv;
	//图的初始化（初始化邻接矩阵）
	for (i = 0; i < nv; i++)
	{
		for (j = 0; j < nv; j++)
		{
			if (i == j)//初始化主对角线
				G->GEdge[i][j] = 0;
			else
				G->GEdge[i][j] = INFINITY;
		}
	}
	//将顶点的信息存入图中
	for (i = 0; i < nv; i++)
	{
		printf("请输入第%d个顶点的信息:\n", i + 1);
		scanf_s("%c", &G->Vertexes[i],1);
		getchar();
	}
	printf("\n");
	//如果有边，插入边
	if (G->num_GEdge != 0)
	{
		for (i = 0; i < ne; i++)
		{
			//读入边，格式为：起点 终点 权重
			//若为不带权的图则将weight赋值为1
			printf("请输入第%d条边的信息起点下标,终点下标,边权(以空格分隔):\n",i+1);
			scanf_s("%d %d %d", &v1, &v2, &weight);
			//对称矩阵
			G->GEdge[v1-1][v2-1] = weight;
			G->GEdge[v2 - 1][v1 - 1] = weight;
		}
	}
}
//图的展示函数
void DisplayGraph(Graph G)
{
	int i, j;
	printf("\n输出顶点的信息\n");
	for (i = 0; i < G.num_Vertex; i++)
	{   
		//顶点信息为char类型
		printf("%8c", G.Vertexes[i]);
	}
	printf("\n输出邻接矩阵\n");
	printf("\t");
	//第一行标签头
	for (i = 0; i < G.num_Vertex; i++)
	{
		//顶点信息为char类型
		printf("%8c", G.Vertexes[i]);
	}
	printf("\n");
	for (i = 0; i <G.num_Vertex; i++)//行
	{
		printf("\n%8c",G.Vertexes[i]);
		//列
		for (j = 0; j < G.num_Vertex; j++)
		{
			if (G.GEdge[i][j] == INFINITY)
			{
				printf("%8s", "∞");
			}
			else
				printf("%8d", G.GEdge[i][j]);
		}
		printf("\n");
	}
}
int main()
{
	Graph G;
	CreatGraph(&G);
	DisplayGraph(G);
	system("pause");
	return 0;
}