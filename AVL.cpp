#include<stdio.h>
#include<stdlib.h>
typedef char datatype;
typedef struct Tree_Node {
	datatype info;
	TNode *Lchild;
	TNode* Rchild;

}TNode;
typedef TNode* BinTree;
//在二叉搜索树里返回值为x的结点的地址(递归)
BinTree Find(BinTree t, datatype x)
{
	if (!t)
		return NULL;//空树，没有找到
	else if (x > t->info)
		Find(t->Rchild, x);
	else if (x < t->info)
		Find(t->Lchild, x);
	else if (x == t->info)
		return t;
}
//在二叉搜索树里返回值为x的结点的地址(非递归)
BinTree Find1(BinTree t, datatype x)
{
	while (t)//当树不为空的时候一直查找
	{
		if (x > t->info)
			t = t->Rchild;
		else if (x < t->info)
			t = t->Lchild;
		else
			return t;
	}
	return NULL; 
}
//在二叉搜索树里返回最小值结点的地址(递归)
BinTree FindMin(BinTree t)
{
	if (!t)//空树返回NULL
		return NULL;
	else if (!t->Lchild)//如果左子树为空就找到了
		return t;
	else
		return FindMin(t->Lchild);//继续查找左子树
}
//在二叉搜索树里返回最大值结点的地址(非递归)
BinTree FindMax(BinTree t)
{
	if (t)//现判断t是否为空
	{
		while (t->Rchild != NULL)
		{
			t = t->Rchild;
		}
	}
	return t;
}
//二叉搜索树的插入操作
BinTree Insert(BinTree t, datatype x)
{
	if (t == NULL)//树为空树
	{
		t = (BinTree)malloc(sizeof(TNode));
		t->info = x;
		t->Lchild = NULL;
		t->Rchild = NULL;
	}
	else
	{
		if (x < t->info)
		{
			t->Lchild = Insert(t->Lchild, x);//递归插入左子树
		}
		else if (x > t->info)
		{
			t->Rchild = Insert(t->Rchild, x);//递归插入右子树
		}
		else
		{
			;//如果等于的话啥也不做
		}
			
	}
	return t;
}
//二叉搜索树的删除操作
BinTree Delete(BinTree t, datatype x)
{
	BinTree tmp = NULL;
	if (t == NULL)
		printf("要删除的元素未找到!\n");
	else
	{
		//先找到要删除的元素
		if (x < t->info)
			t->Lchild = Delete(t->Lchild, x);
		else if (x > t->info)
			t->Rchild = Delete(t->Rchild, x);
		else//找到了
		{
			//如果被删除结点有两个子结点
			if (t->Lchild&&t->Rchild)
			{
				tmp = FindMin(t->Rchild);//找到右子树中的最小值
				t->info = tmp->info;
				t->Rchild = Delete(t->Rchild, tmp->info);
			}
			//如果被删除的结点有一个子结点或没有子节点
			else
			{
				tmp = t;
				if (!t->Lchild)//只有右子节点或无子结点
					t = t->Rchild;
				else //只有左子节点
					t = t->Lchild;
				free(tmp);
			}
		}
	}
	return t;
}
int main()
{
	
	return 0;
}