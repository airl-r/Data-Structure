#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#define Status int
#define SElemType int
#define MaxSize 100



using namespace std;

//	InitStack(SqStack &s) 参数：顺序栈s 功能：初始化  时间复杂度O(1)
//	Push(SqStack &s,SElemType e) 参数：顺序栈s,元素e 功能：将e入栈 时间复杂度:O(1)
//	Pop(SqStack &s,SElemType &e) 参数：顺序栈s,元素e 功能：出栈,e接收出栈元素值 时间复杂度O(1)
//	GetTop(SqStack s,SElemType &e) 参数：顺序栈s,元素e 功能：得到栈顶元素 时间复杂度O(1)	注意：严蔚敏版没有判断栈空函数，在入栈、出栈函数里面判断栈是否空，与王道的不同 尤其是top指针在base之上(有元素时)



//栈数据结构
typedef struct Stack
{
	SElemType *base;//栈底指针 不变
	SElemType *top;//栈顶指针 一直在栈顶元素上一个位置
	int stacksize;//栈可用的最大容量
}SqStack;
//**************************************基本操作函数************************************//

//初始化函数
Status InitStack(SqStack &s)
{
	s.base=new SElemType[MaxSize];//动态分配最大容量
	if(!s.base)
	{
		printf("分配失败\n");
		return 0;
	}
	s.top=s.base;//栈顶指针与栈底相同 王道上top起初在base下面，感觉很别扭，top应该高于或等于base
	s.stacksize=MaxSize;
	return 1;
}

//入栈
Status Push(SqStack &s,SElemType e)
{
	if(s.top-s.base==s.stacksize) return 0;//栈满
	*(s.top++)=e;//先入栈，栈顶指针再上移 注意与王道上的不同，具体问题具体分析
	return 1;	
}

//出栈 用e返回值
Status Pop(SqStack &s,SElemType &e)
{
	if(s.top==s.base) return 0;//栈空
	e=*--s.top;//先减减 指向栈顶元素，再给e
	return 1;	
}

//得到栈顶元素，不修改指针
bool GetTop(SqStack s,SElemType &e)
{
	if(s.top==s.base) return false;//栈空			
	else e=*--s.top;
	return true;
		
}

void PrintStack(SqStack s){
	if(s.top==s.base) printf("栈空");//栈空			
	else{
		int *q = s.top;
		q--;
		while(q != s.base){
			printf("%d ", *q);
			q--;
		}
		printf("%d ", *q);
		printf("\n");
	}
	
}

//********************************功能实现函数**************************************//
//菜单
void menu()
{
   printf("********1.入栈**********\n");
   printf("********2.出栈**********\n");
   printf("********3.取栈顶*********\n");
   printf("********4.查看栈内元素***\n");   
   printf("********5.退出**********\n");
   
   
}
//入栈功能函数 调用Push函数
void PushToStack(SqStack &s)
{
	int n;SElemType e;int flag;
	printf("请输入入栈元素个数(>=1)：\n");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
	 printf("请输入第%d个元素的值:",i+1);
	 scanf("%d",&e);
	 flag=Push(s,e);
	 if(flag)printf("%d已入栈\n",e);
	 else {printf("栈已满！！！\n");break;}
	}
}
//出栈功能函数 调用Pop函数
void PopFromStack(SqStack &s)
{
	int n;SElemType e;int flag;
	printf("请输入出栈元素个数(>=1)：\n");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
	 flag=Pop(s,e);
	 if(flag)printf("%d已出栈\n",e);
	 else {printf("栈已空！！！\n");break;}
	}
}
//取栈顶功能函数 调用GetTop
void GetTopOfStack(SqStack &s)
{
	SElemType e;bool flag; 
	flag=GetTop(s,e);
	if(flag)printf("栈顶元素为:%d\n",e);
	else printf("栈已空！！！\n");
}
//主函数
int main()
{
 SqStack s;int choice;
 InitStack(s);
 while(1)
 {
  menu();
  printf("请输入菜单序号：\n");
  scanf("%d",&choice);
  if(choice==5) break;
  switch(choice)
  {
  case 1:PushToStack(s);break;
  case 2:PopFromStack(s);break;
  case 3:GetTopOfStack(s);break;
  case 4:PrintStack(s);break;
  default:printf("输入错误！！！\n");
  }
 }
 return 0;
}
