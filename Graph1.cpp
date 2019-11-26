//�ڽӱ�洢ͼ
#include<stdio.h>
#include<stdlib.h>
const int MaxVertex = 20;//���ֻ����20������
int visited[MaxVertex];
typedef char DataType;//������Ϣ��������
typedef struct node {
	int adjvex;
	struct node *next;
}EdgeNode;//�߱���
typedef struct VNode {
	DataType vertex;
	EdgeNode*FirstEdge;//�ڽӱ�ͷָ��
}VertexNode;//ͷ�ڵ�
typedef struct {
	VertexNode adjlist[MaxVertex];//���ͷ�ڵ������
	int num_vertex, num_edge;//ͼ�Ķ������ͱ���
}LinkedGraph;//�ڽӱ�
//c=0��ʾ��������ͼ��c=1��ʾ��������ͼ
void creatGraph(LinkedGraph *G, char *filename, int c)
{
	int i, j,k;
	FILE *fp;
	errno_t err;
	EdgeNode *s;
	 err= fopen_s(&fp,filename, "r");
	if (err==0)//��ȡ�ļ��ɹ�
	{
		//���붥�����ͱ���
		fscanf_s(fp, "%d%d", &G->num_vertex, &G->num_edge);//���ļ��ж�ȡ��������������������
		for (i = 0; i < G->num_vertex; i++)
		{
			//���붥����Ϣ
			fscanf_s(fp, " %c", &G->adjlist[i].vertex,1);//ע����һ���ո���%cǰ,���ո�ͻس�
			G->adjlist[i].FirstEdge = NULL;
		}
		//����߱���
		for (j = 0; j < G->num_edge; j++)
		{
			//�����
			fscanf_s(fp, "%d%d", &i,&k);//(i,k)
			s = (EdgeNode*)malloc(sizeof(EdgeNode));
			s->adjvex = k;
			//ǰ�巨
			s->next = G->adjlist[i].FirstEdge;
			G->adjlist[i].FirstEdge = s;
			//����ͼ���ڶ�Ӧ�Ķ��㻹Ҫ�ٲ�һ��
			if (c == 0)
			{
				s = (EdgeNode*)malloc(sizeof(EdgeNode));
				s->adjvex = i;//��i,k��
				//ǰ�巨
				s->next = G->adjlist[k].FirstEdge;
				G->adjlist[k].FirstEdge = s;
			}
		}
		fclose(fp);
	}

	else
	{
		G->num_vertex = 0;//�ļ���ʧ��
	}
}
//ͼ��������ȱ���(�ݹ�)
void DFS1(LinkedGraph G, int i)//���ʶ���i
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
//ͼ��������ȱ������ǵݹ飩
void DFS2(LinkedGraph G,int i)
{
	EdgeNode *p;
	VertexNode stack[MaxVertex];
	int top = -1;
	printf("visit vertex:%c \n", G.adjlist[i].vertex);
	visited[i] = 1;	
	stack[++top] = G.adjlist[i];//��һ�������ջ
	p = G.adjlist[i].FirstEdge;//���˵�һ���ڵ���
	while (p != NULL||top!=-1)//����һ������ջ����
	{
		if (p != NULL)
		{
			if (visited[p->adjvex]==0)//���û�б����ʹ�
			{
				printf("visit vertex:%c \n", G.adjlist[p->adjvex].vertex);
				visited[p->adjvex] = 1;//��۲�����Ϊ1
				stack[++top] = G.adjlist[p->adjvex];//��ջ
				p = G.adjlist[p->adjvex].FirstEdge;//��ȱ�����һ���ڵ�
			}
			else//����ý�㱻���ʹ���
			{
				p = p->next;
			}
		}
		else if (p == NULL)
		{
			//��ջ
			if (top != -1)//ջ���գ����Գ�ջ
			{
				//������һ����ȱ���
				p = stack[top--].FirstEdge;
			}
		}
	}
}
void DFSTraverse1(LinkedGraph G)
{
	int i;
	//��ʼ����־����
	for (i = 0; i < G.num_vertex; i++)
	{
		visited[i] = 0;
	}
	//�Է��ж����ͨ����
	for (i = 0; i < G.num_vertex; i++)
	{
		if (!visited[i])
			DFS1(G, i);
	}
}
void DFSTraverse2(LinkedGraph G)
{
	int i;
	//��ʼ����־����
	for (i = 0; i < G.num_vertex; i++)
	{
		visited[i] = 0;
	}
	//�Է��ж����ͨ����
	for (i = 0; i < G.num_vertex; i++)
	{
		if (!visited[i])
			DFS2(G, i);
	}
}
//ͼ�Ĺ�����ȱ���
void BFS(LinkedGraph G, int i)
{
	int j;
	EdgeNode*p;
	int queue[MaxVertex],front ,rear;
	front = rear = 0;
	printf("visit vertex : %c \n", G.adjlist[i].vertex);//����Դ��
	visited[i] = 1;
	queue[rear++] = i;//���i���
	while (rear > front)//���в���
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
//������ͨ�����ĸ���
int BFSTraverse(LinkedGraph G)
{
	int i, count = 0;
	//��ʼ����־����
	for (i = 0; i < G.num_vertex; i++)
	{
		visited[i] = 0;
	}
	//����ÿһ�����
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
	printf("\nDFS(�ݹ�)���:\n");
	DFSTraverse1(G);
	printf("\nDFS(�ǵݹ�)���\n");
	DFSTraverse2(G);
	printf("\nBFS�����\n");
	BFSTraverse(G);
	system("pause");
	return 0;
}