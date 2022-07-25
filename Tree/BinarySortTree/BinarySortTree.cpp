#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<string>
#include<stack>
#include<queue>
#include<algorithm>
#include<iostream>
#define TElemType char
//�����������Ļ������� 
//BST_Insert(BSTree &T, TElemType data)  ����T��������������ڵ� ���ã���������data,��֤������ϸ�����������ظ���
//PreOrder(BSTree T)  ����T��������������ڵ� ���ã��������������������ݹ鷽ʽ
//InOrder(BSTree T)   ����T��������������ڵ� ���ã��������������������ݹ鷽ʽ
//PostOrder(BSTree T) ����T��������������ڵ� ���ã��������������������ݹ鷽ʽ
//LevelOrder(BSTree T)����T��������������ڵ� ���ã��������������������ݹ鷽ʽ
//BST_Search(BSTree T, TElemType key) ���� BSTree T, TElemType key�����ò���key�Ƿ�����ڶ���������У������ڣ�����ָ��ý���ָ�룬���򣬷��ؿ�
//BST_Delete(BSTree &T, TElemType key) ���� BSTree T, TElemType key�����ò���key�Ƿ�����ڶ���������У������ڣ�ɾ��������true,���򣬷���false
//CreateBSTree(BSTree &T) ����T��������������ڵ� ���ã�����InitTree���������������
//Traverse(BSTree T)      ����T��������������ڵ� ���ã�PreOrder InOrder PostOrder LevelOrder�������������
//InsertBSTree(BSTree &T) ����T��������������ڵ� ���ã������㣬����BST_Insert
//DeleteBSTree(BSTree &T) ����T��������������ڵ� ���ã�ɾ����㣬����BST_Delete
//SearchBSTree(BSTree T)  ����T��������������ڵ� ���ã����ҽ�㣬����BST_Search


using namespace std;
//��ʽ������������ݽṹ
typedef struct BSTNode
{
	TElemType data;//������
	struct BSTNode *lchild, *rchild;//���Һ���
}BSTNode, *BSTree;

//������������� ����T��������������ڵ� ���ã���������data,��֤������ϸ�����������ظ���
int BST_Insert(BSTree &T, TElemType data)
{
	if (T == NULL)//��Ϊ��
	{
		T = (BSTree)malloc(sizeof(BSTNode));//������ռ�
		T->data = data;                     //��ֵ
		T->lchild = NULL;                   //���Һ���Ϊ��
		T->rchild = NULL;
		return 1;
	}
	else if (data < T->data)               //�ȵ�ǰ�ڵ�����С������������
	{
		return BST_Insert(T->lchild,data);
	}
	else                                   //����涨��������������ظ������ڼ����ڵ�ǰ���ʱ������������
	{
		return BST_Insert(T->rchild,data);
	}
}

//�������-�ݹ�
void PreOrder(BSTree T)
{
	if (T != NULL)
	{
		cout<<T->data<<" ";
		PreOrder(T->lchild);//�ݹ����������������
		PreOrder(T->rchild);
	}
}

//�������-�ݹ�
void InOrder(BSTree T)
{
	if (T != NULL)
	{
		InOrder(T->lchild);//�ݹ����������������
		cout << T->data << " ";
		InOrder(T->rchild);
	}
}

//�������-�ݹ�
void PostOrder(BSTree T)
{
	if (T != NULL)
	{
		PostOrder(T->lchild);//�ݹ���������������
		PostOrder(T->rchild);
		cout << T->data << " ";
	}
}

//������� ��������
void LevelOrder(BSTree T)
{
	queue<BSTNode> q;//��������
	if (T != NULL)
	{
		BSTNode temp;//�ݴ�Ҫ���ӵĽ��
		q.push(*T);//��������
		while (!q.empty())//���зǿ�
		{
			temp = q.front();
			q.pop();
			cout << temp.data << " ";
			if (temp.lchild != NULL) q.push(*temp.lchild);//�����Ƚ��ȳ�����������
			if (temp.rchild != NULL) q.push(*temp.rchild);
		}
	}
}

//������������� ���� BSTree T, TElemType key�����ò���key�Ƿ�����ڶ���������У������ڣ�����ָ��ý���ָ�룬���򣬷��ؿ�
BSTNode * BST_Search(BSTree T, TElemType key)
{
   BSTNode *cur = T; //��ǰ���ָ��cur
   while (cur&&key!=cur->data)
   {
	   if (key<cur->data)     //�ȵ�ǰ�������С�������������� 
	   {
		   cur = cur->lchild;
	   }
	   else                  //�ȵ�ǰ������ݴ������������� 
	   {
		   cur = cur->rchild;
	   }
   }
   return cur;
}

//���������ɾ�� ���� BSTree T, TElemType key�����ò���key�Ƿ�����ڶ���������У������ڣ�ɾ��������true,���򣬷���false
bool BST_Delete(BSTree &T, TElemType key)
{
	BSTNode*  cur = T;
	BSTNode*  cur_par = NULL;//��ǰ����˫�׽��
	while (cur&&key != cur->data)
	{
		if (key<cur->data)     //�ȵ�ǰ�������С
		{
			cur_par = cur;    //��¼˫�׽��
			cur = cur->lchild;
		}
		else                  //�ȵ�ǰ������ݴ�
		{
			cur_par = cur;    //��¼˫�׽��
			cur = cur->rchild;
		}
	}
	if (cur) //�ҵ����������ɾ����Ҷ�ӽ�㣨��Ϊ0�� ��֧��㣨��Ϊ1�� ˫֧��㣨��Ϊ2��
	{
		if (cur->lchild==NULL&&cur->rchild==NULL)//Ҷ�ӽ��
		{
			if (cur == T)//���ڵ�
			{
				T = NULL;
			}
			else if (cur_par->lchild == cur)//Ҫɾ������cur_par������
			{
				cur_par->lchild = NULL;
			}
			else
			{
				cur_par->rchild = NULL;
			}
		}
		else if (cur->lchild == NULL || cur->rchild == NULL)//��֧���
		{
			if (cur == T)//���ڵ�
			{
				if (cur->lchild)//������
				{
					T = cur->lchild;
				}
				else
				{
					T = cur->rchild;
				}
			}
			else //�Ǹ���㣬˫�׽��ָ��Ҫɾ�������ӽ�㼴��
			{
				if (cur_par->lchild == cur&&cur->lchild)//curΪcur��˫�׽������ӣ���������
				{
					cur_par->lchild = cur->lchild;
				}
				else if (cur_par->lchild == cur&&cur->rchild)
				{
					cur_par->lchild = cur->rchild;
				}
				else if (cur_par->rchild == cur&&cur->lchild)
				{
					cur_par->rchild = cur->lchild;
				} 
				else{
					cur_par->rchild = cur->rchild;
				}
			}
		}
		else //˫֧���  ����ѡ����ֱ��ǰ������������Ȼ��ɾ��ֱ��ǰ����
			//���ߣ���ֱ�Ӻ�̽���������ɾ��ֱ�Ӻ�̡�����ѡ����ߡ�
		{
			BSTNode* temp = cur;//��¼��Ҫɾ���Ľ�㣬������Ҫ��ֱ�Ӻ�̽���������
			cur_par = cur;      //��cur�ҵ�temp��ֱ�Ӻ�� ��curΪtemp��������������
			cur = cur->rchild;  //������
			while (cur->lchild)//�ҵ�ֱ�Ӻ�̣����������������ӣ���Сֵ��
			{
				cur_par = cur;
				cur=cur->lchild;
			}
			temp->data = cur->data;//����������
			if (cur_par == temp)//��ɾ������������û���������������������ڵ㼴Ϊ��ɾ�������
			{
				cur_par->rchild = cur->rchild;
			}
			else               //��ɾ��������������������
			{
				cur_par->lchild = cur->rchild;//��cur����������˫�׽��
			}		
		}
		free(cur);
		return true;
	}//if
	return false;
}

//����BST_Insert���ж���������Ĵ���
void CreateBSTree(BSTree &T)
{
	string s;
	printf("�����������������ݴ������������(����ַ���):");
	cin >> s;
	for (int i=0;i<s.length();i++)
	{
		BST_Insert(T,s[i]);
	}
	printf("��������������������:");
	PreOrder(T);
	printf("\n");
}
//�������ܺ��� ����PreOrder InOrder PostOrder LevelOrder
void Traverse(BSTree T)
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
		case 1: {printf("�����������:");PreOrder(T);printf("\n");}break;
		case 2: {printf("�����������:");InOrder(T);printf("\n");}break;
		case 3: {printf("�����������:");PostOrder(T);printf("\n");}break;
		case 4: {printf("��α�������:");LevelOrder(T);printf("\n");}break;
		default:printf("������󣡣���\n");break;
		}
	}
}
//���� ����BST_Insert
void InsertBSTree(BSTree &T)
{
	TElemType data;
	printf("������Ҫ��������ݣ�\n");
	cin >> data;
	BST_Insert(T,data);
	printf("����ɹ�������\n");
}
//ɾ�� ����BST_Delete
void DeleteBSTree(BSTree &T)
{
	TElemType key;
	printf("������Ҫɾ�������ݣ�\n");
	cin >> key;
	if (BST_Delete(T, key))
	{
		printf("ɾ���ɹ���\n");
	}
	else
	{
		printf("δ�ҵ���\n");
	}
}
//���� ����BST_Search
void SearchBSTree(BSTree T)
{
	TElemType data;
	BSTNode *p;
	printf("������Ҫ���ҵ����ݣ�\n");
	cin >> data;
	p = BST_Search(T, data);
	if (p) 
	{
		printf("�����ݴ��ڣ�����\n");
	}
	else
		printf("�����ݲ����ڣ�����\n");
}
//�˵�
void menu()
{
	printf("********1.����*********\n");
	printf("********2.����*********\n");
	printf("********3.����*********\n");
	printf("********4.����*********\n");
	printf("********5.ɾ��*********\n");
	printf("********6.�˳�*********\n");

}
//������
int main()
{
	BSTree T = NULL;int choice = 0;
	while (1)
	{
		menu();
		printf("������˵���ţ�\n");
		scanf("%d", &choice);
		if (6 == choice) break;
		switch (choice)
		{
		case 1:CreateBSTree(T);break;
		case 2:Traverse(T);break;
		case 3:InsertBSTree(T);break;
		case 4:SearchBSTree(T);break;
		case 5:DeleteBSTree(T);break;
		default:printf("������󣡣���\n");break;
		}
	}
	return 0;
}
