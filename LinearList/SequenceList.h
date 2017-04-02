#ifndef __SEQUENCELIST_H__
#define __SEQUENCELIST_H__

/************************结构体定义区**************************/
typedef int DataType;
#define MaxSize 2000
typedef struct 
{
	DataType list[MaxSize];
	int len;
}SeqList; 


/************************函数定义区**************************/
//初始化一个顺序表
void initList(SeqList *L);
//创建一个顺序表
void createList(SeqList *L);
//清空一个顺序表
void clearList(SeqList *L);
//输出顺序表中的所有元素
void printList(SeqList *L);
// 获取顺序表的长度
int getLength(SeqList *L);
// 判断顺序表是否为空
int isEmpty(SeqList *L);
// 读取顺序表的第i个元素
DataType getItem(SeqList *L,int i);
// 获取某一数据在顺序表中的下标
int searchList(SeqList *L,DataType elem);
// 在第i个位置插入一个新的数据元素
void insertList(SeqList *L,int i,DataType elem);
// 删除顺序表中的第i个数据元素
void deleteList(SeqList *L,int i);
//已知L递增有序，编写一个算法
//将元素x插入到顺序表的适当位置上
//保持顺序表的有序性,算法如下
void fastInsert(SeqList *L,DataType x);


/************************函数实现区**************************/
//初始化一个顺序表
void initList(SeqList *L){
	L->len=0;
}
//创建一个顺序表
void createList(SeqList *L){
	int n;
	printf("请输入顺序表的长度\n");
	scanf("%d",&n);
	L->len=n;
	printf("请输入顺序表的数据\n");
	int i;
	for (i = 0; i < n; ++i)
	{
		/* code */
		int t;
		scanf("%d",&t);
		L->list[i]=t;
	}
}
//清空一个顺序表
void clearList(SeqList *L){
	L->len=0;
}
//输出顺序表中的所有元素
void printList(SeqList *L){
	int i;
	for (i = 0; i < L->len; ++i)
	{
		/* code */
		printf("%d ",L->list[i]);
	}
	printf("\n");
}
// 获取顺序表的长度
int getLength(SeqList *L){
	return L->len;
}
// 判断顺序表是否为空
int isEmpty(SeqList *L){
	return (L->len==0);
}
// 读取顺序表的第i个元素
DataType getItem(SeqList *L,int i){
	return L->list[i];
}
// 获取某一数据在顺序表中的下标
int searchList(SeqList *L,DataType elem){
	int i;
	for (i = 0; i < L->len; ++i)
	{
		/* code */
		if (L->list[i]==elem)
		{
			/* code */
			return i;
		}
	}
	return -1;
}
// 在第i个位置插入一个新的数据元素
void insertList(SeqList *L,int i,DataType elem){
	if (L->len==MaxSize)
	{
		/* code */
		printf("overflow\n");
		exit(-1);
	}
	if (i<0)
	{
		i=0;
	}else if (i>=L->len){
		/* code */
		i=L->len;
	}
	int k;
	for (k=L->len-1;k>=i;k--)
	{
		/* code */
		L->list[k+1]=L->list[k];
	}
	L->list[i]=elem;
	L->len++;

}
// 删除顺序表中的第i个数据元素
void deleteList(SeqList *L,int i){
	if (L->len==0)
	{
		/* code */
		printf("empty error\n");
		exit(-1);
	}
	if (i<0)
	{
		i=0;
	}else if (i>=L->len){
		/* code */
		i=L->len-1;
	}
	int k;
	for (k=i;k<L->len;k++)
	{
		/* code */
		L->list[k]=L->list[k+1];
	}
	L->len--;
}

//已知L递增有序，编写一个算法
//将元素x插入到顺序表的适当位置上
//保持顺序表的有序性,算法如下
void fastInsert(SeqList *L,DataType x){
	int left=0,right=L->len-1,mid;
	while(left < right-1){
		mid=(left + right)/2;
		if(L->list[mid]>x){
			right=mid;
		}else if(L->list[mid]<x){
			left=mid;
		}else{
			break;
		}
	} 
	if(L->list[mid]==x){
		insertList(L,mid+1,x);
	}else if(L->list[right]<=x){
		insertList(L,right+1,x);
	}else if(L->list[left]<=x){
		insertList(L,left+1,x);
	}else{
		insertList(L,left,x);
	}
	
}

#endif