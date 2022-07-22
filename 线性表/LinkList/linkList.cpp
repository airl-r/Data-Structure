
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#define Status int
#define ElemType int

using namespace std;


//	����ͷ�ڵ�ĵ����� 
//	InitList(LinkList &L) ������������L ���ܣ���ʼ�� ʱ�临�Ӷ� O(1)
//	ListLength(LinkList L) ������������L ���ܣ���õ������� ʱ�临�Ӷ�O(n) 
//	ListInsert(LinkList &L,int i,ElemType e) ������������L,λ��i��Ԫ��e ���ܣ�λ��i��� ʱ�临�Ӷ�O(n)
//	ListDelete(LinkList &L,int i) ������������L��λ��i ���ܣ�ɾ��λ��iԪ�� ʱ�临�Ӷ�O(n)[�����˲���] 
//	LocateElem(LinkList L,ElemType e) ������������L��Ԫ��e ���ܣ����ҵ�һ������e��Ԫ�أ�����ָ�� ʱ�临�Ӷ�O(n) 

//�����������ݽṹ
typedef struct LNode
{
	ElemType data;//������
	struct LNode *next;//ָ����
}LNode,*LinkList;
//**************************������������***************************//

//��ʼ������
Status InitList(LinkList &L)
{
 L = new LNode;//����ͷ��� ����ɾ���Ȳ����Ͳ��طֵ�һ������������
 L->next = NULL;
 return 1;
}

//��ȡ�������� ͷ��������ݣ�����
int ListLength(LinkList L)
{
	LinkList p=L;int sum=0;
	while(p)
	{
	 sum++;
	 p=p->next;
	}
	return sum-1;//ȥ��ͷ���
}

//���뺯��--��巨 ���뵽��i(1<=i<=length+1)��λ�� ��i-1֮�� ��������i��λ��
bool ListInsert(LinkList &L,int i,ElemType e)
{
	LNode* s;LinkList p=L;int j=0;
	while(p&&(j<i-1))//jָ��i-1λ�û���p�Ѿ������ʱ����
	{
	 p=p->next;
	 ++j;
	}
	if(!p||j>i-1)//i<1����i>ListLength(L)+1ʱ,����λ����Ч ������ListLength,���Ч��
	{
		printf("����λ����Ч������\n");
		return false;
	}
	s=new LNode;
	s->data=e;
	s->next=p->next;
	p->next=s;
	return true;
}

//ɾ������ ɾ��λ��i�Ľ�� ��ɾ��i-1֮��Ľ��
bool ListDelete(LinkList &L,int i)
{
 	LNode* s;LinkList p=L;int j=0;
	LinkList q;
	while(p&&(j<i-1))//jָ��i-1λ��
	{
	 p=p->next;
	 ++j;
	}
	if (p==NULL ||!(p->next) || j>i - 1)//i<1����i>ListLength(L)ʱ,ɾ��λ����Ч
	{
		printf("ɾ��λ����Ч������\n");
		return false;
	}
	q=p->next;
	p->next=q->next;
	free(q);//�ͷſռ�
	return true;
}

//���Һ��� ��ֵ���� ���ҵ�һ������e�Ľ�� �ɹ����ظý��ָ�룬���򷵻�NULL
LNode *LocateElem(LinkList L,ElemType e)
{
	LNode *p=L;
	while(p&&(p->data!=e))
	{
		p=p->next;
	}
	return p;
}



//**************************����ʵ�ֺ���**************************//
//�����������
void PrintList(LinkList L)
{
	LinkList p=L->next;//����ͷ���
	if(ListLength(L))
	{
		printf("��ǰ����������Ԫ��:");
		while(p)
		{
			printf("%d ",p->data);
			p=p->next;
		}
		printf("\n");
	}
	else
	{
		printf("��ǰ�������ѿգ�\n");
	}
}
//���빦�ܺ��� ����ListInsert���
void Insert(LinkList &L)
{
  int place;ElemType e;bool flag;
  printf("������Ҫ�����λ��(��1��ʼ)��Ԫ��:\n");
  scanf("%d%d",&place,&e);
  flag=ListInsert(L,place,e);
  if(flag) 
  {
	printf("����ɹ�������\n");
	PrintList(L);
  }
}
//ɾ�����ܺ��� ����ListDeleteɾ��
void Delete(LinkList L)
{
  int place;bool flag;
  printf("������Ҫɾ����λ��(��1��ʼ):\n");
  scanf("%d",&place);
  flag=ListDelete(L,place);
  if(flag) 
  {
	printf("ɾ���ɹ�������\n");
	PrintList(L);
  }
}
//���ҹ��ܺ��� ����LocateElem����
void Search(LinkList L)
{
  ElemType e;LNode *q;
  printf("������Ҫ���ҵ�ֵ:\n");
  scanf("%d",&e);
  q=LocateElem(L,e);
  if(q) 
  {
	printf("�ҵ���Ԫ�أ�\n");
  }
  else
	printf("δ�ҵ���Ԫ�أ�\n");
}
//�˵�
void menu()
{
   printf("********1.���*********\n");
   printf("********2.ɾ��*********\n");
   printf("********3.����*********\n");
   printf("********4.���*********\n");
   printf("********5.�˳�*********\n");
}
//������
int main()
{
 LinkList L;int choice;
 InitList(L);
 while(1)
 {
  menu();
  printf("������˵���ţ�\n");
  scanf("%d",&choice);
  if(choice==5) break;
  switch(choice)
  {
  case 1:Insert(L);break;
  case 2:Delete(L);break;
  case 3:Search(L);break;
  case 4:PrintList(L);break;
  default:printf("�������\n");
  }
 }
 return 0;
}
