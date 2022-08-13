#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
using namespace std;
#define Status int
#define SElemType int

//    InitStack(LinkStack &S) 参数：链栈S 功能：初始化  时间复杂度O(1)
//	Push(LinkStack &S,SElemType e) 参数：链栈S,元素e 功能：将e入栈 时间复杂度:O(1)
//	Pop(LinkStack &S,SElemType &e) 参数：链栈S,元素e 功能：栈顶出栈,e接收出栈元素值 时间复杂度O(1)
//	GetTop(LinkStack &S,SElemType &e) 参数：链栈S,元素e 功能：得到栈顶元素 时间复杂度O(1)


//链栈结点数据结构
typedef struct StackNode {
	SElemType data;//数据域
	struct StackNode *next;//指针域
} StackNode,*LinkStack;


//初始化函数
Status InitStack(LinkStack &S) {
	S = NULL;//生成空栈 以单链表表头为栈顶 注意，链栈没有像链表似的头结点
	return 1;
}

//入栈函数 将e压入栈
Status Push(LinkStack &S,SElemType e) {
	StackNode *p;
	p=new StackNode;//生成新节点
	p->data=e;      //赋值
	p->next=S;      //压入栈顶
	S=p;
	return 1;
}
//出栈函数  栈顶出栈用e返回 注意释放空间
bool Pop(LinkStack &S,SElemType &e) {
	LinkStack p;
	if(S==NULL)return false;//栈空
	e=S->data;
	p=S;
	S=S->next;
	free(p);
	return true;
}


//取栈顶函数 用e返回
bool GetTop(LinkStack &S,SElemType &e) { //严蔚敏版（人民邮电出版社） 61页有误
	if(S==NULL) return false;//栈顶为空
	e=S->data;
	return true;
}



//菜单
void menu() {
	printf("********1.入栈*********\n");
	printf("********2.出栈*********\n");
	printf("********3.取栈顶元素***\n");
	printf("********4.退出*********\n");
}
//入栈功能函数 调用Push函数
void PushToStack(LinkStack &S) {
	int n;
	SElemType e;
	int flag;
	printf("请输入入栈元素个数(>=1)：\n");
	scanf("%d",&n);
	for(int i=0; i<n; i++) {
		printf("请输入第%d个元素的值:",i+1);
		scanf("%d",&e);
		flag=Push(S,e);
		if(flag)printf("%d已入栈\n",e);
	}
}
//出栈功能函数 调用Pop函数
void PopFromStack(LinkStack &S) {
	int n;
	SElemType e;
	int flag;
	printf("请输入出栈元素个数(>=1)：\n");
	scanf("%d",&n);
	for(int i=0; i<n; i++) {
		flag=Pop(S,e);
		if(flag)printf("%d已出栈\n",e);
		else {
			printf("栈已空！！！\n");
			break;
		}
	}
}
//取栈顶功能函数 调用GetTop函数
void GetTopOfStack(LinkStack S) {
	SElemType e;
	bool flag;
	flag=GetTop(S,e);
	if(flag)printf("栈顶元素为:%d\n",e);
	else printf("栈已空！！！\n");
}
//主函数
int main() {
	LinkStack S;
	int choice;
	InitStack(S);
	while(1) {
		menu();
		printf("请输入菜单序号：\n");
		scanf("%d",&choice);
		if(choice==4) break;
		switch(choice) {
			case 1:
				PushToStack(S);
				break;
			case 2:
				PopFromStack(S);
				break;
			case 3:
				GetTopOfStack(S);
				break;
			default:
				printf("输入错误！！！\n");
		}
	}
	return 0;
}
