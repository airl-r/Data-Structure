//分块查找 

#include <stdio.h>

#define MAXL 100                    //定义表中最多记录个数
#define MAXI 20                     //定义索引表的最大长度
typedef int KeyType;


typedef struct
{
    KeyType key;                    //KeyType为关键字的数据类型
} NodeType;

typedef NodeType SeqList[MAXL];     //顺序表类型
typedef struct
{
    KeyType key;                    //表示该块元素的最大值，也是关键字 
    int link;                       //指向分块的起始下标
} IdxType;

typedef IdxType IDX[MAXI];          //索引表类型


//索引采用二分查找，块内采用顺序查找 
//IdxSearch(索引 ，总块数 ，顺序表，总长度，要查找的元素） 
int IdxSearch(IDX I,int m,SeqList R,int n,KeyType k)    //分块查找算法
{
    int low=0,high=m-1,mid,i;
    int b=n/m;              //b为每块的记录个数
    printf("二分查找索引\n");
    while (low<=high)       //在索引表中进行二分查找,找到的位置存放在low中
    {
        mid=(low+high)/2;
        if (I[mid].key>=k)
            high=mid-1;
        else
            low=mid+1;
    }
    if (low<m)              //在索引表中查找成功后,再在线性表中进行顺序查找
    {
        
        i=I[low].link;
        printf("顺序查找第%d块:\n    ",low+1);
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
    for (i=0;i<25;i++)              //建立顺序表
        R[i].key=a[i];
    I[0].key=14;I[0].link=0;
    I[1].key=34;I[1].link=4;
    I[2].key=66;I[2].link=10;
    I[3].key=85;I[3].link=15;
    I[4].key=100;I[4].link=20;
    if ((i=IdxSearch(I,5,R,25,k))!=-1)
        printf("元素%d的下标是%d\n",k,i);
    else
        printf("元素%d不在表中\n",k);
    printf("\n");
}
