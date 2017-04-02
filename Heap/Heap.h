#ifndef __HEAP_H__
#define __HEAP_H__ 
/**************************结构体定义区**************************/
#define MaxSize 200
typedef int DataType;
typedef struct
{
	DataType v[MaxSize];
	int len;
}Heap;
/**************************函数定义区****************************/
//初始化堆
void initHeap(Heap *h);
//建立堆
void createHeap(Heap *h);
//堆的插入运算
void insertHeap(Heap *h,DataType elem);
//调整堆，将堆中以第k个元素为根的子树调整为堆，
//其要求是该元素的左右子树已经是堆
void adjustHeap(Heap *h,int k);
//堆的删除运算
//删除堆顶元素
DataType removeHeapTop(Heap *h);
//删除任意一个元素
DataType removeHeapItem(Heap *h,int k);
//打印堆
void printHeap(Heap *h);
/**************************函数实现区****************************/
//初始化堆
void initHeap(Heap *h){
	h->len=0;
}
//建立堆
void createHeap(Heap *h){
	int i;
	DataType elem;
	scanf("%d",&elem);
	while(elem!=-1){
		h->v[h->len]=elem;
		h->len++;
		scanf("%d",&elem);
	}
	for(i=h->len/2-1;i>=0;i--){
		adjustHeap(h,i);
	}
}
//调整堆，将堆中以第k个元素为根的子树调整为堆，
//其要求是该元素的左右子树已经是堆
void adjustHeap(Heap *h,int k){
	int i=k;
	//用j记录i左孩子的位置
	int j=2*i+1;
	//用t记录第k个元素
	DataType t=h->v[k];
	while(j<h->len){
		//找到i左孩子、右孩子中最小的一个
		if(j < h->len-1 && h->v[j] > h->v[j+1]){
			j++;
		}
		//如果t小于其左右孩子，终止循环
		if(t<=h->v[j]){
			break;
		}
		h->v[i]=h->v[j];
		i=j;
		j=2*i+1;
	}
	h->v[i]=t;
}
//堆的插入运算
void insertHeap(Heap *h,DataType elem){
	int i,j;
	if(h->len>=MaxSize){
		printf("The heap is full!\n");
		exit(1);
	}
	h->v[h->len]=elem;
	h->len++;
	i=h->len-1;
	while(i!=0){
		j=(i-1)/2;
		if(elem>=h->v[j]){
			break;
		}
		h->v[i]=h->v[j];
		i=j;
	}
	h->v[i]=elem;
}
//堆的删除运算
//删除堆顶元素
DataType removeHeapTop(Heap *h){
	int i,j;
	DataType top,t;
	if(h->len==0){
		printf("the heap is empty\n");
		exit(-1);
	}
	top=h->v[0];
	h->len--;
	if(h->len==0){
		return top;
	}
	h->v[0]=h->v[h->len];
	adjustHeap(h,0);
	return top;
}
//删除任意一个元素
DataType removeHeapItem(Heap *h,int k){
	int i,j;
	DataType t;
	if(k==0){
		removeHeapTop(h);
	}else if(k==h->len-1){
		h->len--;
		return h->v[k];
	}else{
		i=k;
		j=(i-1)/2;
		while(i!=0){
			t=h->v[i];
			h->v[i]=h->v[j];
			h->v[j]=t;
			i=j;
			j=(i-1)/2;
		}
		removeHeapTop(h);
	}
}

//打印堆
void printHeap(Heap *h){
	int i;
	for(i=0;i<h->len;i++){
		printf("h->len[%d]: %d\n",i,h->v[i]);
	}
}
#endif