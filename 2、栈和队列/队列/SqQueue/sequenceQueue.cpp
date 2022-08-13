#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
using namespace std;
#define Status int
#define QElemType int
#define MaxQSize 100




//	InitQueue(SqQueue &Q)              参数：循环队列Q 功能：初始化循环队列Q 时间复杂度：O(1)
//	QueueEmpty(SqQueue Q)              参数：循环队列Q 功能：判断队空与否 时间复杂度：O(1)
//	EnQueue(SqQueue &Q,QElemType e)    参数：循环队列Q，元素e 功能：使元素e入队 时间复杂度：O(1)
//	DeQueue(SqQueue &Q,QElemType &e)   参数：循环队列Q，元素e 功能：队头出队,用e返回值 时间复杂度：O(1)
//	GetHead(SqQueue &Q,QElemType &e)   参数：循环队列Q，元素e 功能：获取队头元素e 时间复杂度：O(1)



//循环队列数据结构
typedef struct
{
	QElemType data[MaxQSize];//数据域
	int front,rear;          //队头队尾指针
}SqQueue;


//初始化函数
Status InitQueue(SqQueue &Q)
{
	Q.front=Q.rear=0;
	return 1;
}


//判断队空函数
bool QueueEmpty(SqQueue Q)
{
	if(Q.front!=Q.rear)return false;
	else return true;
}

//入队函数
bool EnQueue(SqQueue &Q,QElemType e)
{
	if((Q.rear+1)%MaxQSize==Q.front)return false; //队列满 牺牲一个以判断
	Q.data[Q.rear]=e;
	Q.rear=(Q.rear+1)%MaxQSize;//指针加1 取模
	return true;
}

//出队函数
bool DeQueue(SqQueue &Q,QElemType &e)
{
	if(Q.front==Q.rear)return false;//队空 其实可以调用QueueEmpty 不然要它干啥呢 
	                                //严蔚敏版 给了判空函数，但在其他基本操作函数中也没用
	e=Q.data[Q.front];
	Q.front=(Q.front+1)%MaxQSize;   //指针加1 取模
	return true;
}

//取队头
bool GetHead(SqQueue &Q,QElemType &e)
{
	if(Q.front==Q.rear)return false;//队空 其实可以调用QueueEmpty 不然要它干啥呢 
	                                //严蔚敏版 给了判空函数，但在其他基本操作函数中也没用
	e=Q.data[Q.front];
	return true;
}




//**************************功能实现函数****************************//
//入队功能函数 调用EnQueue函数
void EnterToQueue(SqQueue &Q)
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
	 else {printf("队已满！！！\n");break;}
	}
}
//出队函数 调用DeQueue函数
void DeleteFromQueue(SqQueue &Q)
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
//获得队头元素 调用GetHead函数
void GetHeadOfQueue(SqQueue Q)
{
	QElemType e;bool flag; 
	flag=GetHead(Q,e);
	if(flag)printf("队头元素为:%d\n",e);
	else printf("队已空！！！\n");
}
//菜单
void menu()
{
   printf("********1.入队          2.出队*********\n");
   printf("********3.取队头元素    4.退出*********\n");
}
//主函数
int main()
{
	SqQueue Q;int choice;
	InitQueue(Q);
	while(1)
	{
	menu();
	printf("请输入菜单序号：\n");
	scanf("%d",&choice);
	if(choice==4) break;
	switch(choice)
	{
	case 1:EnterToQueue(Q);break;
	case 2:DeleteFromQueue(Q);break;
	case 3:GetHeadOfQueue(Q);break;
	default:printf("输入错误！！！\n");
	}
	}
	return 0;
}
