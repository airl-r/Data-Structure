#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
using namespace std;
#define Status int
#define SElemType int

//    InitStack(LinkStack &S) ��������ջS ���ܣ���ʼ��  ʱ�临�Ӷ�O(1)
//	Push(LinkStack &S,SElemType e) ��������ջS,Ԫ��e ���ܣ���e��ջ ʱ�临�Ӷ�:O(1)
//	Pop(LinkStack &S,SElemType &e) ��������ջS,Ԫ��e ���ܣ�ջ����ջ,e���ճ�ջԪ��ֵ ʱ�临�Ӷ�O(1)
//	GetTop(LinkStack &S,SElemType &e) ��������ջS,Ԫ��e ���ܣ��õ�ջ��Ԫ�� ʱ�临�Ӷ�O(1)


//��ջ������ݽṹ
typedef struct StackNode {
	SElemType data;//������
	struct StackNode *next;//ָ����
} StackNode,*LinkStack;


//��ʼ������
Status InitStack(LinkStack &S) {
	S = NULL;//���ɿ�ջ �Ե������ͷΪջ�� ע�⣬��ջû���������Ƶ�ͷ���
	return 1;
}

//��ջ���� ��eѹ��ջ
Status Push(LinkStack &S,SElemType e) {
	StackNode *p;
	p=new StackNode;//�����½ڵ�
	p->data=e;      //��ֵ
	p->next=S;      //ѹ��ջ��
	S=p;
	return 1;
}
//��ջ����  ջ����ջ��e���� ע���ͷſռ�
bool Pop(LinkStack &S,SElemType &e) {
	LinkStack p;
	if(S==NULL)return false;//ջ��
	e=S->data;
	p=S;
	S=S->next;
	free(p);
	return true;
}


//ȡջ������ ��e����
bool GetTop(LinkStack &S,SElemType &e) { //��ε���棨�����ʵ�����磩 61ҳ����
	if(S==NULL) return false;//ջ��Ϊ��
	e=S->data;
	return true;
}



//�˵�
void menu() {
	printf("********1.��ջ*********\n");
	printf("********2.��ջ*********\n");
	printf("********3.ȡջ��Ԫ��***\n");
	printf("********4.�˳�*********\n");
}
//��ջ���ܺ��� ����Push����
void PushToStack(LinkStack &S) {
	int n;
	SElemType e;
	int flag;
	printf("��������ջԪ�ظ���(>=1)��\n");
	scanf("%d",&n);
	for(int i=0; i<n; i++) {
		printf("�������%d��Ԫ�ص�ֵ:",i+1);
		scanf("%d",&e);
		flag=Push(S,e);
		if(flag)printf("%d����ջ\n",e);
	}
}
//��ջ���ܺ��� ����Pop����
void PopFromStack(LinkStack &S) {
	int n;
	SElemType e;
	int flag;
	printf("�������ջԪ�ظ���(>=1)��\n");
	scanf("%d",&n);
	for(int i=0; i<n; i++) {
		flag=Pop(S,e);
		if(flag)printf("%d�ѳ�ջ\n",e);
		else {
			printf("ջ�ѿգ�����\n");
			break;
		}
	}
}
//ȡջ�����ܺ��� ����GetTop����
void GetTopOfStack(LinkStack S) {
	SElemType e;
	bool flag;
	flag=GetTop(S,e);
	if(flag)printf("ջ��Ԫ��Ϊ:%d\n",e);
	else printf("ջ�ѿգ�����\n");
}
//������
int main() {
	LinkStack S;
	int choice;
	InitStack(S);
	while(1) {
		menu();
		printf("������˵���ţ�\n");
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
				printf("������󣡣���\n");
		}
	}
	return 0;
}
