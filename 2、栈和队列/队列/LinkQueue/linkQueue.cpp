
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
using namespace std;
#define Status int
#define QElemType int



//    InitQueue(LinkQueue &Q) ����������Q ���ܣ���ʼ��  ʱ�临�Ӷ�O(1)
//	EnQueue(LinkQueue &Q,QElemType e) ����������Q,Ԫ��e ���ܣ���e��� ʱ�临�Ӷ�:O(1)
//	DeQueue(LinkQueue &Q,QElemType &e) ����������Q,Ԫ��e ���ܣ���ͷ����,e���ճ���Ԫ��ֵ ʱ�临�Ӷ�O(1)
//	GetHead(LinkQueue &Q,QElemType &e)  ����������Q,Ԫ��e ���ܣ��õ��Ӷ�Ԫ�� ʱ�临�Ӷ�O(1)
//	ע�⣺��ͷ���


//���ӽ�����ݽṹ

typedef struct QNode
{
	QElemType data;//������
	struct QNode *next;//ָ����
	
}QNode,*QueuePtr;

typedef struct
{
	struct QNode *front,*rear;//rearָ��ָ���β ������� frontָ��ָ���ͷ ���ڳ���
}LinkQueue;
//**************************������������***************************//
//��ʼ������
Status InitQueue(LinkQueue &Q)
{
	Q.front=Q.rear=new QNode;//�����½ڵ���Ϊͷ��㣬��ͷ��βָ���ָ����
	Q.front->next=NULL;
	return 1;
}
//��Ӻ��� 
Status EnQueue(LinkQueue &Q,QElemType e)
{
	QNode *p;
	p=new QNode;//�����½ڵ�
	p->data=e;    //��ֵ
	p->next=NULL;
	Q.rear->next=p;//�����β
	Q.rear=p;      //βָ�����
	return 1;
}

//���Ӻ���  ��ͷ������e���� ע���ͷſռ�
bool DeQueue(LinkQueue &Q,QElemType &e)
{
	QueuePtr p;
	if(Q.front==Q.rear)return false;//�ӿ�
	e=Q.front->next->data;           //e����ֵ ֮ǰд��Q.front->data ը�ˣ�ͷ���û���ݵģ�һ��Ҫע��ͷ���
	p=Q.front->next;                //������һ����ͷſռ�
	Q.front->next=p->next;          //����,ע��Q.front->next ����Q.front ����ͷ���
	if(Q.rear==p)Q.rear=Q.front;    //���һ��Ԫ�س��ӣ�rearָ��ͷ���
	free(p);
	return true;
}

//ȡ�Ӷ����� ��e����
bool GetHead(LinkQueue &Q,QElemType &e) 
{
	if(Q.front==Q.rear) return false;//����Ϊ��
	e=Q.front->next->data;
	return true;
}

//��ӡ�������Ԫ��
void PrintQueue(LinkQueue Q){
	QNode *p;
	p = Q.front->next;
	while(p->next != NULL){
		printf("%d ",p->data);
		p = p->next;
	}
	printf("%d\n",p->data);
} 
//**************************����ʵ�ֺ���***************************//
//�˵�
void menu()
{
   printf("********1.���*********\n");
   printf("********2.����*********\n");
   printf("********3.ȡ�Ӷ�Ԫ��***\n");
   printf("********4.��ӡ����Ԫ��*\n");
   printf("********5.�˳�*********\n");

}
//��ӹ��ܺ��� ����EnQueue���� 
void EnterToQueue(LinkQueue &Q)
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
	}
}
//���ӹ��ܺ��� ����DeQueue����
void DeleteFromQueue(LinkQueue &Q)
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
//ȡ�Ӷ����ܺ��� ����GetHead����
void GetHeadOfStack(LinkQueue Q)
{
	QElemType e;bool flag; 
	flag=GetHead(Q,e);
	if(flag)printf("��ͷԪ��Ϊ:%d\n",e);
	else printf("���ѿգ�����\n");
}
//������
int main()
{
 LinkQueue Q;int choice;
 InitQueue(Q);
 while(1)
 {
  menu();
  printf("������˵���ţ�\n");
  scanf("%d",&choice);
  if(5==choice) break;
  switch(choice)
  {
  case 1:EnterToQueue(Q);break;
  case 2:DeleteFromQueue(Q);break;
  case 3:GetHeadOfStack(Q);break;
  case 4:PrintQueue(Q);break; 
  default:printf("������󣡣���\n");
  }
 }
 return 0;
}
