//邻接表存储图
#include<stdio.h>
#include<stdlib.h>
const int MaxVertex = 20;//最多只能有20个顶点
int visited[MaxVertex];
typedef char DataType;//顶点信息数据类型
typedef struct node {
	int adjvex;
	struct node *next;
}EdgeNode;//边表结点
typedef struct VNode {
	DataType vertex;
	EdgeNode*FirstEdge;//邻接表头指针
}VertexNode;//头节点
typedef struct {
	VertexNode adjlist[MaxVertex];//存放头节点的数组
	int num_vertex, num_edge;//图的顶点数和边数
}LinkedGraph;//邻接表
//c=0表示建立无向图，c=1表示建立有向图
void creatGraph(LinkedGraph *G, char *filename, int c)
{
	int i, j,k;
	FILE *fp;
	errno_t err;
	EdgeNode *s;
	 err= fopen_s(&fp,filename, "r");
	if (err==0)//读取文件成功
	{
		//读入顶点数和边数
		fscanf_s(fp, "%d%d", &G->num_vertex, &G->num_edge);//从文件中读取两个数到这两个变量中
		for (i = 0; i < G->num_vertex; i++)
		{
			//读入顶点信息
			fscanf_s(fp, " %c", &G->adjlist[i].vertex,1);//注意有一个空格在%c前,吸空格和回车
			G->adjlist[i].FirstEdge = NULL;
		}
		//置入边表结点
		for (j = 0; j < G->num_edge; j++)
		{
			//读入边
			fscanf_s(fp, "%d%d", &i,&k);//(i,k)
			s = (EdgeNode*)malloc(sizeof(EdgeNode));
			s->adjvex = k;
			//前插法
			s->next = G->adjlist[i].FirstEdge;
			G->adjlist[i].FirstEdge = s;
			//无向图，在对应的顶点还要再插一次
			if (c == 0)
			{
				s = (EdgeNode*)malloc(sizeof(EdgeNode));
				s->adjvex = i;//（i,k）
				//前插法
				s->next = G->adjlist[k].FirstEdge;
				G->adjlist[k].FirstEdge = s;
			}
		}
		fclose(fp);
	}

	else
	{
		G->num_vertex = 0;//文件打开失败
	}
}
//图的深度优先遍历(递归)
void DFS1(LinkedGraph G, int i)//访问顶点i
{
	EdgeNode *p;
	printf("visit vertex :%c \n", G.adjlist[i].vertex);
	visited[i] = 1;
	p = G.adjlist[i].FirstEdge;
	while (p)
	{
		if (!visited[p->adjvex])
		{
			DFS1(G, p->adjvex);
		}
		else
		{
			p = p->next;
		}
	}
}
//图的深度优先遍历（非递归）
void DFS2(LinkedGraph G,int i)
{
	EdgeNode *p;
	VertexNode stack[MaxVertex];
	int top = -1;
	printf("visit vertex:%c \n", G.adjlist[i].vertex);
	visited[i] = 1;	
	stack[++top] = G.adjlist[i];//第一个结点入栈
	p = G.adjlist[i].FirstEdge;//到了第一个节点上
	while (p != NULL||top!=-1)//当第一个结点或栈不空
	{
		if (p != NULL)
		{
			if (visited[p->adjvex]==0)//如果没有被访问过
			{
				printf("visit vertex:%c \n", G.adjlist[p->adjvex].vertex);
				visited[p->adjvex] = 1;//设观察数组为1
				stack[++top] = G.adjlist[p->adjvex];//入栈
				p = G.adjlist[p->adjvex].FirstEdge;//深度遍历下一个节点
			}
			else//如果该结点被访问过了
			{
				p = p->next;
			}
		}
		else if (p == NULL)
		{
			//出栈
			if (top != -1)//栈不空，可以出栈
			{
				//进行下一轮深度遍历
				p = stack[top--].FirstEdge;
			}
		}
	}
}
void DFSTraverse1(LinkedGraph G)
{
	int i;
	//初始化标志数组
	for (i = 0; i < G.num_vertex; i++)
	{
		visited[i] = 0;
	}
	//以防有多个连通分量
	for (i = 0; i < G.num_vertex; i++)
	{
		if (!visited[i])
			DFS1(G, i);
	}
}
void DFSTraverse2(LinkedGraph G)
{
	int i;
	//初始化标志数组
	for (i = 0; i < G.num_vertex; i++)
	{
		visited[i] = 0;
	}
	//以防有多个连通分量
	for (i = 0; i < G.num_vertex; i++)
	{
		if (!visited[i])
			DFS2(G, i);
	}
}
//图的广度优先遍历
void BFS(LinkedGraph G, int i)
{
	int j;
	EdgeNode*p;
	int queue[MaxVertex],front ,rear;
	front = rear = 0;
	printf("visit vertex : %c \n", G.adjlist[i].vertex);//访问源点
	visited[i] = 1;
	queue[rear++] = i;//结点i入队
	while (rear > front)//队列不空
	{
		j = queue[front++];
		p = G.adjlist[j].FirstEdge;
		while (p)
		{
			if (visited[p->adjvex] == 0)
			{
				printf("visit vertex : %c \n", G.adjlist[p->adjvex].vertex);
				queue[rear++] = p->adjvex;
				visited[p->adjvex] = 1;
			}
			else
			{
				p = p->next;
			}
		}
	}
}
//返回连通分量的个数
int BFSTraverse(LinkedGraph G)
{
	int i, count = 0;
	//初始化标志数组
	for (i = 0; i < G.num_vertex; i++)
	{
		visited[i] = 0;
	}
	//访问每一个结点
	for (i = 0; i < G.num_vertex; i++)
	{
		if (!visited[i])
		{
			printf("\n");
			count++;
			BFS(G, i);
		}
	}
	return count;
}
int main()
{
	int j;
	char filename[100] = "data.txt";
	LinkedGraph G;
	creatGraph(&G,filename, 0);
	printf("\nDFS(递归)结果:\n");
	DFSTraverse1(G);
	printf("\nDFS(非递归)结果\n");
	DFSTraverse2(G);
	printf("\nBFS结果：\n");
	BFSTraverse(G);
	system("pause");
	return 0;
}