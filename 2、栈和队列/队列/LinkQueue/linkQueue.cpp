
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
using namespace std;
#define Status int
#define QElemType int



//    InitQueue(LinkQueue &Q) 参数：链队Q 功能：初始化  时间复杂度O(1)
//	EnQueue(LinkQueue &Q,QElemType e) 参数：链队Q,元素e 功能：将e入队 时间复杂度:O(1)
//	DeQueue(LinkQueue &Q,QElemType &e) 参数：链队Q,元素e 功能：队头出队,e接收出队元素值 时间复杂度O(1)
//	GetHead(LinkQueue &Q,QElemType &e)  参数：链队Q,元素e 功能：得到队顶元素 时间复杂度O(1)
//	注意：有头结点


//链队结点数据结构

typedef struct QNode
{
	QElemType data;//数据域
	struct QNode *next;//指针域
	
}QNode,*QueuePtr;

typedef struct
{
	struct QNode *front,*rear;//rear指针指向队尾 用于入队 front指针指向队头 用于出队
}LinkQueue;
//**************************基本操作函数***************************//
//初始化函数
Status InitQueue(LinkQueue &Q)
{
	Q.front=Q.rear=new QNode;//生成新节点作为头结点，队头队尾指针均指向它
	Q.front->next=NULL;
	return 1;
}
//入队函数 
Status EnQueue(LinkQueue &Q,QElemType e)
{
	QNode *p;
	p=new QNode;//生成新节点
	p->data=e;    //赋值
	p->next=NULL;
	Q.rear->next=p;//加入队尾
	Q.rear=p;      //尾指针后移
	return 1;
}

//出队函数  队头出队用e返回 注意释放空间
bool DeQueue(LinkQueue &Q,QElemType &e)
{
	QueuePtr p;
	if(Q.front==Q.rear)return false;//队空
	e=Q.front->next->data;           //e返回值 之前写的Q.front->data 炸了，头结点没数据的，一定要注意头结点
	p=Q.front->next;                //保留，一会儿释放空间
	Q.front->next=p->next;          //出队,注意Q.front->next 不是Q.front 还有头结点
	if(Q.rear==p)Q.rear=Q.front;    //最后一个元素出队，rear指向头结点
	free(p);
	return true;
}

//取队顶函数 用e返回
bool GetHead(LinkQueue &Q,QElemType &e) 
{
	if(Q.front==Q.rear) return false;//队列为空
	e=Q.front->next->data;
	return true;
}

//打印输出对内元素
void PrintQueue(LinkQueue Q){
	QNode *p;
	p = Q.front->next;
	while(p->next != NULL){
		printf("%d ",p->data);
		p = p->next;
	}
	printf("%d\n",p->data);
} 
//**************************功能实现函数***************************//
//菜单
void menu()
{
   printf("********1.入队*********\n");
   printf("********2.出队*********\n");
   printf("********3.取队顶元素***\n");
   printf("********4.打印对内元素*\n");
   printf("********5.退出*********\n");

}
//入队功能函数 调用EnQueue函数 
void EnterToQueue(LinkQueue &Q)
{
	int n;QElemType e;int flag;
	printf("请输入入队元素个数(>=1)：\n");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
	 printf("请输入第%d个元素的值:",i+1);
	 scanf("%d",&e);
	 flag=EnQueue(Q,e);
	 if(flag)printf("%d已入队\n",e);
	}
}
//出队功能函数 调用DeQueue函数
void DeleteFromQueue(LinkQueue &Q)
{
	int n;QElemType e;int flag;
	printf("请输入出队元素个数(>=1)：\n");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
	 flag=DeQueue(Q,e);
	 if(flag)printf("%d已出队\n",e);
	 else {printf("队已空！！！\n");break;}
	}
}
//取队顶功能函数 调用GetHead函数
void GetHeadOfStack(LinkQueue Q)
{
	QElemType e;bool flag; 
	flag=GetHead(Q,e);
	if(flag)printf("队头元素为:%d\n",e);
	else printf("队已空！！！\n");
}
//主函数
int main()
{
 LinkQueue Q;int choice;
 InitQueue(Q);
 while(1)
 {
  menu();
  printf("请输入菜单序号：\n");
  scanf("%d",&choice);
  if(5==choice) break;
  switch(choice)
  {
  case 1:EnterToQueue(Q);break;
  case 2:DeleteFromQueue(Q);break;
  case 3:GetHeadOfStack(Q);break;
  case 4:PrintQueue(Q);break; 
  default:printf("输入错误！！！\n");
  }
 }
 return 0;
}
