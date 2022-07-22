
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#define Status int
#define ElemType int

using namespace std;


//	带有头节点的单链表 
//	InitList(LinkList &L) 参数：单链表L 功能：初始化 时间复杂度 O(1)
//	ListLength(LinkList L) 参数：单链表L 功能：获得单链表长度 时间复杂度O(n) 
//	ListInsert(LinkList &L,int i,ElemType e) 参数：单链表L,位置i，元素e 功能：位置i后插 时间复杂度O(n)
//	ListDelete(LinkList &L,int i) 参数：单链表L，位置i 功能：删除位置i元素 时间复杂度O(n)[加入了查找] 
//	LocateElem(LinkList L,ElemType e) 参数：单链表L，元素e 功能：查找第一个等于e的元素，返回指针 时间复杂度O(n) 

//单链表结点数据结构
typedef struct LNode
{
	ElemType data;//数据域
	struct LNode *next;//指针域
}LNode,*LinkList;
//**************************基本操作函数***************************//

//初始化函数
Status InitList(LinkList &L)
{
 L = new LNode;//生成头结点 这样删除等操作就不必分第一个结点和其他了
 L->next = NULL;
 return 1;
}

//获取单链表长度 头结点无数据，不算
int ListLength(LinkList L)
{
	LinkList p=L;int sum=0;
	while(p)
	{
	 sum++;
	 p=p->next;
	}
	return sum-1;//去除头结点
}

//插入函数--后插法 插入到第i(1<=i<=length+1)个位置 即i-1之后 不必区分i的位置
bool ListInsert(LinkList &L,int i,ElemType e)
{
	LNode* s;LinkList p=L;int j=0;
	while(p&&(j<i-1))//j指到i-1位置或者p已经到最后时跳出
	{
	 p=p->next;
	 ++j;
	}
	if(!p||j>i-1)//i<1或者i>ListLength(L)+1时,插入位置无效 不调用ListLength,提高效率
	{
		printf("插入位置无效！！！\n");
		return false;
	}
	s=new LNode;
	s->data=e;
	s->next=p->next;
	p->next=s;
	return true;
}

//删除函数 删除位置i的结点 即删除i-1之后的结点
bool ListDelete(LinkList &L,int i)
{
 	LNode* s;LinkList p=L;int j=0;
	LinkList q;
	while(p&&(j<i-1))//j指到i-1位置
	{
	 p=p->next;
	 ++j;
	}
	if (p==NULL ||!(p->next) || j>i - 1)//i<1或者i>ListLength(L)时,删除位置无效
	{
		printf("删除位置无效！！！\n");
		return false;
	}
	q=p->next;
	p->next=q->next;
	free(q);//释放空间
	return true;
}

//查找函数 按值查找 查找第一个等于e的结点 成功返回该结点指针，否则返回NULL
LNode *LocateElem(LinkList L,ElemType e)
{
	LNode *p=L;
	while(p&&(p->data!=e))
	{
		p=p->next;
	}
	return p;
}



//**************************功能实现函数**************************//
//遍历输出函数
void PrintList(LinkList L)
{
	LinkList p=L->next;//跳过头结点
	if(ListLength(L))
	{
		printf("当前单链表所有元素:");
		while(p)
		{
			printf("%d ",p->data);
			p=p->next;
		}
		printf("\n");
	}
	else
	{
		printf("当前单链表已空！\n");
	}
}
//插入功能函数 调用ListInsert后插
void Insert(LinkList &L)
{
  int place;ElemType e;bool flag;
  printf("请输入要插入的位置(从1开始)及元素:\n");
  scanf("%d%d",&place,&e);
  flag=ListInsert(L,place,e);
  if(flag) 
  {
	printf("插入成功！！！\n");
	PrintList(L);
  }
}
//删除功能函数 调用ListDelete删除
void Delete(LinkList L)
{
  int place;bool flag;
  printf("请输入要删除的位置(从1开始):\n");
  scanf("%d",&place);
  flag=ListDelete(L,place);
  if(flag) 
  {
	printf("删除成功！！！\n");
	PrintList(L);
  }
}
//查找功能函数 调用LocateElem查找
void Search(LinkList L)
{
  ElemType e;LNode *q;
  printf("请输入要查找的值:\n");
  scanf("%d",&e);
  q=LocateElem(L,e);
  if(q) 
  {
	printf("找到该元素！\n");
  }
  else
	printf("未找到该元素！\n");
}
//菜单
void menu()
{
   printf("********1.后插*********\n");
   printf("********2.删除*********\n");
   printf("********3.查找*********\n");
   printf("********4.输出*********\n");
   printf("********5.退出*********\n");
}
//主函数
int main()
{
 LinkList L;int choice;
 InitList(L);
 while(1)
 {
  menu();
  printf("请输入菜单序号：\n");
  scanf("%d",&choice);
  if(choice==5) break;
  switch(choice)
  {
  case 1:Insert(L);break;
  case 2:Delete(L);break;
  case 3:Search(L);break;
  case 4:PrintList(L);break;
  default:printf("输入错误！\n");
  }
 }
 return 0;
}
