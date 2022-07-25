
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<string>
#include<stack>
#include<queue>
#include<algorithm>
#include<iostream>
#define TElemType int



//InitTree(BiTree &T) 参数T，二叉树根节点 作用：初始化二叉树，先序递归创建
//PreOrder(BiTree T)  参数T，二叉树根节点 作用：先序遍历二叉树，递归方式
//InOrder(BiTree T)   参数T，二叉树根节点 作用：中序遍历二叉树，递归方式
//PostOrder(BiTree T) 参数T，二叉树根节点 作用：后序遍历二叉树，递归方式
//LevelOrder(BiTree T)参数T，二叉树根节点 作用：层序遍历二叉树，递归方式 
//CreateBiTree(BiTree &T) 参数T，二叉树根节点 作用：调用InitTree，创建二叉树
//Traverse(BiTree T)      参数T，二叉树根节点 作用：PreOrder InOrder PostOrder LevelOrder遍历二叉树

using namespace std;
//链式二叉树数据结构
typedef struct BiTNode
{
	TElemType data;//数据域
	struct BiTNode *lchild, *rchild;//左右孩子
}BiTNode, *BiTree;


//创建二叉树 规定数据域为-1，则为空 先序创建
int InitTree(BiTree &T)
{
	TElemType a;
	scanf("%d", &a);
	if (-1 == a) T = NULL;
	else {
		T = (BiTree)malloc(sizeof(BiTNode));
		T->data = a;
		InitTree(T->lchild);
		InitTree(T->rchild);
	}
	return 0;
}
//先序遍历-递归
//先序遍历 按照逻辑来说,执行这个函数前,应该进行逻辑判断（树是否为空），放在里面的话也没有else进行输出提示，不太好
//这里就按照课本敲代码了，在对应功能实现函数进行逻辑判断
void PreOrder(BiTree T)
{
	if (T != NULL)
	{
		printf("%d ", T->data);
		PreOrder(T->lchild);//递归先序遍历左右子树
		PreOrder(T->rchild);
	}
}
//中序遍历-递归
void InOrder(BiTree T)
{
	if (T != NULL)
	{
		InOrder(T->lchild);//递归中序遍历左右子树
		printf("%d ", T->data);
		InOrder(T->rchild);
	}
}
//后序遍历-递归
void PostOrder(BiTree T)
{
	if (T != NULL)
	{
		PostOrder(T->lchild);//递归后序遍历左右子树
		PostOrder(T->rchild);
		printf("%d ", T->data);
	}
}
//层序遍历
void LevelOrder(BiTree T)
{
	queue<BiTNode> q;//借助队列
	if (T != NULL)
	{
		BiTNode temp;//暂存要出队的结点
		q.push(*T);//根结点入队
		while (!q.empty())//队列非空
		{
			temp = q.front();
			q.pop();
			printf("%d ", temp.data);
			if (temp.lchild != NULL) q.push(*temp.lchild);//队列先进先出，先入左孩子
			if (temp.rchild != NULL) q.push(*temp.rchild);
		}
	}
}


//调用InitTree
void CreateBiTree(BiTree &T)
{
	printf("请按照先序遍历输入二叉树(-1表示该节点为空):");
	InitTree(T);
	printf("二叉树先序遍历序列:");
	PreOrder(T);
	printf("\n");
}
//遍历功能函数 调用PreOrder InOrder PostOrder LevelOrder
void Traverse(BiTree T)
{
	int choice;
	while (1)
	{
		printf("********1.先序遍历*********\n");
		printf("********2.中序遍历*********\n");
		printf("********3.后序遍历*********\n");
		printf("********4.层次遍历*********\n");
		printf("********5.返回上一单元*****\n");
		printf("请输入菜单序号：\n");
		scanf("%d", &choice);
		if (5 == choice) break;
		switch (choice)
		{
		case 1: {printf("二叉树先序遍历序列:");PreOrder(T);printf("\n");}break;
		case 2: {printf("二叉树中序遍历序列:");InOrder(T);printf("\n");}break;
		case 3: {printf("二叉树后序遍历序列:");PostOrder(T);printf("\n");}break;
		case 4: {printf("二叉树层次遍历序列:");LevelOrder(T);printf("\n");}break;
		default:printf("输入错误！！！\n");break;
		}
	}
}
//菜单
void menu()
{
	printf("********1.创建*********\n");
	printf("********2.遍历*********\n");
	printf("********3.退出*********\n");
}

//主函数
int main()
{
	BiTree T = NULL;int choice = 0;
	while (1)
	{
		menu();
		printf("请输入菜单序号：\n");
 
		scanf("%d", &choice);
		if (3 == choice) break;
		switch (choice)
		{
		case 1:CreateBiTree(T);break;
		case 2:Traverse(T);break;
		default:printf("输入错误！！！\n");break;
		}
	}
	return 0;
}
