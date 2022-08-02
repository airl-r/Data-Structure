//�ֿ���� 

#include <stdio.h>

#define MAXL 100                    //�����������¼����
#define MAXI 20                     //�������������󳤶�
typedef int KeyType;


typedef struct
{
    KeyType key;                    //KeyTypeΪ�ؼ��ֵ���������
} NodeType;

typedef NodeType SeqList[MAXL];     //˳�������
typedef struct
{
    KeyType key;                    //��ʾ�ÿ�Ԫ�ص����ֵ��Ҳ�ǹؼ��� 
    int link;                       //ָ��ֿ����ʼ�±�
} IdxType;

typedef IdxType IDX[MAXI];          //����������


//�������ö��ֲ��ң����ڲ���˳����� 
//IdxSearch(���� ���ܿ��� ��˳����ܳ��ȣ�Ҫ���ҵ�Ԫ�أ� 
int IdxSearch(IDX I,int m,SeqList R,int n,KeyType k)    //�ֿ�����㷨
{
    int low=0,high=m-1,mid,i;
    int b=n/m;              //bΪÿ��ļ�¼����
    printf("���ֲ�������\n");
    while (low<=high)       //���������н��ж��ֲ���,�ҵ���λ�ô����low��
    {
        mid=(low+high)/2;
        if (I[mid].key>=k)
            high=mid-1;
        else
            low=mid+1;
    }
    if (low<m)              //���������в��ҳɹ���,�������Ա��н���˳�����
    {
        
        i=I[low].link;
        printf("˳����ҵ�%d��:\n    ",low+1);
        while (i<=I[low].link+b-1 && R[i].key!=k)
        {
            
            printf("%d ",R[i].key);
            i++;
        }  
		printf("%d ",R[i].key);   
        printf("\n");
        if (i<=I[low].link+b-1)
            return i;
        else
            return -1;
    }
    return -1;
}
int  main()
{
    SeqList R;
    KeyType k=46;
    IDX I;
    int a[]={8,14,6,9,10,22,34,18,19,31,40,38,54,66,46,71,78,68,80,85 ,100,94,88,96,87},i;
    for (i=0;i<25;i++)              //����˳���
        R[i].key=a[i];
    I[0].key=14;I[0].link=0;
    I[1].key=34;I[1].link=4;
    I[2].key=66;I[2].link=10;
    I[3].key=85;I[3].link=15;
    I[4].key=100;I[4].link=20;
    if ((i=IdxSearch(I,5,R,25,k))!=-1)
        printf("Ԫ��%d���±���%d\n",k,i);
    else
        printf("Ԫ��%d���ڱ���\n",k);
    printf("\n");
}
