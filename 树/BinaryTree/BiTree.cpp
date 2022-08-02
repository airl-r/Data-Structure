
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



//InitTree(BiTree &T) ����T�����������ڵ� ���ã���ʼ��������������ݹ鴴��
//PreOrder(BiTree T)  ����T�����������ڵ� ���ã�����������������ݹ鷽ʽ
//InOrder(BiTree T)   ����T�����������ڵ� ���ã�����������������ݹ鷽ʽ
//PostOrder(BiTree T) ����T�����������ڵ� ���ã�����������������ݹ鷽ʽ
//LevelOrder(BiTree T)����T�����������ڵ� ���ã�����������������ݹ鷽ʽ 
//CreateBiTree(BiTree &T) ����T�����������ڵ� ���ã�����InitTree������������
//Traverse(BiTree T)      ����T�����������ڵ� ���ã�PreOrder InOrder PostOrder LevelOrder����������

using namespace std;
//��ʽ���������ݽṹ
typedef struct BiTNode
{
	TElemType data;//������
	struct BiTNode *lchild, *rchild;//���Һ���
}BiTNode, *BiTree;


//���������� �涨������Ϊ-1����Ϊ�� ���򴴽�
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
//�������-�ݹ�
//������� �����߼���˵,ִ���������ǰ,Ӧ�ý����߼��жϣ����Ƿ�Ϊ�գ�����������Ļ�Ҳû��else���������ʾ����̫��
//����Ͱ��տα��ô����ˣ��ڶ�Ӧ����ʵ�ֺ��������߼��ж�
void PreOrder(BiTree T)
{
	if (T != NULL)
	{
		printf("%d ", T->data);
		PreOrder(T->lchild);//�ݹ����������������
		PreOrder(T->rchild);
	}
}
//�������-�ݹ�
void InOrder(BiTree T)
{
	if (T != NULL)
	{
		InOrder(T->lchild);//�ݹ����������������
		printf("%d ", T->data);
		InOrder(T->rchild);
	}
}
//�������-�ݹ�
void PostOrder(BiTree T)
{
	if (T != NULL)
	{
		PostOrder(T->lchild);//�ݹ���������������
		PostOrder(T->rchild);
		printf("%d ", T->data);
	}
}
//�������
void LevelOrder(BiTree T)
{
	queue<BiTNode> q;//��������
	if (T != NULL)
	{
		BiTNode temp;//�ݴ�Ҫ���ӵĽ��
		q.push(*T);//��������
		while (!q.empty())//���зǿ�
		{
			temp = q.front();
			q.pop();
			printf("%d ", temp.data);
			if (temp.lchild != NULL) q.push(*temp.lchild);//�����Ƚ��ȳ�����������
			if (temp.rchild != NULL) q.push(*temp.rchild);
		}
	}
}


//����InitTree
void CreateBiTree(BiTree &T)
{
	printf("�밴������������������(-1��ʾ�ýڵ�Ϊ��):");
	InitTree(T);
	printf("�����������������:");
	PreOrder(T);
	printf("\n");
}
//�������ܺ��� ����PreOrder InOrder PostOrder LevelOrder
void Traverse(BiTree T)
{
	int choice;
	while (1)
	{
		printf("********1.�������*********\n");
		printf("********2.�������*********\n");
		printf("********3.�������*********\n");
		printf("********4.��α���*********\n");
		printf("********5.������һ��Ԫ*****\n");
		printf("������˵���ţ�\n");
		scanf("%d", &choice);
		if (5 == choice) break;
		switch (choice)
		{
		case 1: {printf("�����������������:");PreOrder(T);printf("\n");}break;
		case 2: {printf("�����������������:");InOrder(T);printf("\n");}break;
		case 3: {printf("�����������������:");PostOrder(T);printf("\n");}break;
		case 4: {printf("��������α�������:");LevelOrder(T);printf("\n");}break;
		default:printf("������󣡣���\n");break;
		}
	}
}
//�˵�
void menu()
{
	printf("********1.����*********\n");
	printf("********2.����*********\n");
	printf("********3.�˳�*********\n");
}

//������
int main()
{
	BiTree T = NULL;int choice = 0;
	while (1)
	{
		menu();
		printf("������˵���ţ�\n");
 
		scanf("%d", &choice);
		if (3 == choice) break;
		switch (choice)
		{
		case 1:CreateBiTree(T);break;
		case 2:Traverse(T);break;
		default:printf("������󣡣���\n");break;
		}
	}
	return 0;
}
