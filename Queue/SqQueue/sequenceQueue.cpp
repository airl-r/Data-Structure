#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
using namespace std;
#define Status int
#define QElemType int
#define MaxQSize 100




//	InitQueue(SqQueue &Q)              ������ѭ������Q ���ܣ���ʼ��ѭ������Q ʱ�临�Ӷȣ�O(1)
//	QueueEmpty(SqQueue Q)              ������ѭ������Q ���ܣ��ж϶ӿ���� ʱ�临�Ӷȣ�O(1)
//	EnQueue(SqQueue &Q,QElemType e)    ������ѭ������Q��Ԫ��e ���ܣ�ʹԪ��e��� ʱ�临�Ӷȣ�O(1)
//	DeQueue(SqQueue &Q,QElemType &e)   ������ѭ������Q��Ԫ��e ���ܣ���ͷ����,��e����ֵ ʱ�临�Ӷȣ�O(1)
//	GetHead(SqQueue &Q,QElemType &e)   ������ѭ������Q��Ԫ��e ���ܣ���ȡ��ͷԪ��e ʱ�临�Ӷȣ�O(1)



//ѭ���������ݽṹ
typedef struct
{
	QElemType data[MaxQSize];//������
	int front,rear;          //��ͷ��βָ��
}SqQueue;


//��ʼ������
Status InitQueue(SqQueue &Q)
{
	Q.front=Q.rear=0;
	return 1;
}


//�ж϶ӿպ���
bool QueueEmpty(SqQueue Q)
{
	if(Q.front!=Q.rear)return false;
	else return true;
}

//��Ӻ���
bool EnQueue(SqQueue &Q,QElemType e)
{
	if((Q.rear+1)%MaxQSize==Q.front)return false; //������ ����һ�����ж�
	Q.data[Q.rear]=e;
	Q.rear=(Q.rear+1)%MaxQSize;//ָ���1 ȡģ
	return true;
}

//���Ӻ���
bool DeQueue(SqQueue &Q,QElemType &e)
{
	if(Q.front==Q.rear)return false;//�ӿ� ��ʵ���Ե���QueueEmpty ��ȻҪ����ɶ�� 
	                                //��ε���� �����пպ���������������������������Ҳû��
	e=Q.data[Q.front];
	Q.front=(Q.front+1)%MaxQSize;   //ָ���1 ȡģ
	return true;
}

//ȡ��ͷ
bool GetHead(SqQueue &Q,QElemType &e)
{
	if(Q.front==Q.rear)return false;//�ӿ� ��ʵ���Ե���QueueEmpty ��ȻҪ����ɶ�� 
	                                //��ε���� �����пպ���������������������������Ҳû��
	e=Q.data[Q.front];
	return true;
}




//**************************����ʵ�ֺ���****************************//
//��ӹ��ܺ��� ����EnQueue����
void EnterToQueue(SqQueue &Q)
{
	int n;QElemType e;int flag;
	printf("���������Ԫ�ظ���(>=1)��\n");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
	 printf("�������%d��Ԫ�ص�ֵ:",i+1);
	 scanf("%d",&e);
	 flag=EnQueue(Q,e);
	 if(flag)printf("%d�����\n",e);
	 else {printf("������������\n");break;}
	}
}
//���Ӻ��� ����DeQueue����
void DeleteFromQueue(SqQueue &Q)
{
	int n;QElemType e;int flag;
	printf("���������Ԫ�ظ���(>=1)��\n");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
	 flag=DeQueue(Q,e);
	 if(flag)printf("%d�ѳ���\n",e);
	 else {printf("���ѿգ�����\n");break;}
	}
}
//��ö�ͷԪ�� ����GetHead����
void GetHeadOfQueue(SqQueue Q)
{
	QElemType e;bool flag; 
	flag=GetHead(Q,e);
	if(flag)printf("��ͷԪ��Ϊ:%d\n",e);
	else printf("���ѿգ�����\n");
}
//�˵�
void menu()
{
   printf("********1.���          2.����*********\n");
   printf("********3.ȡ��ͷԪ��    4.�˳�*********\n");
}
//������
int main()
{
	SqQueue Q;int choice;
	InitQueue(Q);
	while(1)
	{
	menu();
	printf("������˵���ţ�\n");
	scanf("%d",&choice);
	if(choice==4) break;
	switch(choice)
	{
	case 1:EnterToQueue(Q);break;
	case 2:DeleteFromQueue(Q);break;
	case 3:GetHeadOfQueue(Q);break;
	default:printf("������󣡣���\n");
	}
	}
	return 0;
}
