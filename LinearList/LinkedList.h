#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__


/************************结构体定义区*****************************/
typedef int DataType;

typedef struct node
{
	DataType data;
	struct node *next;
} Lnode;


/************************函数定义区*****************************/
//带头节点的链表初始化
Lnode* initList();

//建立链表
void createList(Lnode* h);
//清空链表
void clearList(Lnode* h);
//输出链表每个元素的值
void printList(Lnode*h);
//求链表的长度
int getLength(Lnode*h);
//判断链表是否为空
int isEmpty(Lnode*h);
//在链表中插入一个新的元素
void insertAfter(Lnode *p,DataType elem);
void insertBefore(Lnode *h,Lnode *p,DataType elem);
//在链表中删除一个节点
void deleteNode(Lnode *h,Lnode *p);
//在链表中查找指定关键字的数据元素
Lnode* searchList(Lnode* h,DataType elem);
//拆分链表
void splitList(Lnode* h,Lnode* he,Lnode* ho);
//合并链表
void mergeList(Lnode *hp,Lnode *hq,Lnode *h);


/************************函数实现区*****************************/
Lnode* initList(){
	Lnode *h=(Lnode*)malloc(sizeof(Lnode));
	h->next=NULL;
	return h;
}
void createList(Lnode* h){
	Lnode *cur=h;
	Lnode *tmp=NULL;
	int n;
	printf("请输入线性表的长度\n");
	scanf("%d",&n);
	printf("请输入线性表的数据以空格分隔，以回车结束\n");
	int i;
	for (i = 0; i < n; ++i)
	{
		int t;
		scanf("%d",&t);
		tmp=(Lnode*)malloc(sizeof(Lnode));
		tmp->data=t;
		tmp->next=NULL;
		cur->next=tmp;
		cur=cur->next;
	}
}
void clearList(Lnode* h){
	Lnode *tmp=NULL;
	while(h->next!=NULL){
		tmp=h->next;
		h->next=h->next->next;
		free(tmp);
	}
}
void printList(Lnode*h){
	Lnode *q=h->next;
	while(q!=NULL){
		printf("%d ", q->data);
		q=q->next;
	}
	printf("\n");
}
int getLength(Lnode*h){
	Lnode *cur=h->next;
	int count=0;
	while(cur!=NULL){
		count++;
		cur=cur->next;
	}
	return count;
}
int isEmpty(Lnode*h){
	return (h->next==NULL);
}
void insertAfter(Lnode *p,DataType elem){
	Lnode *tmp=(Lnode*)malloc(sizeof(Lnode));
	tmp->data=elem;
	tmp->next=p->next;
	p->next=tmp;
}
void insertBefore(Lnode *h,Lnode *p,DataType elem){
	Lnode *tmp=NULL,*q=h;
	while(q->next!=p){
		q=q->next;
	}
	tmp=(Lnode*)malloc(sizeof(Lnode));
	tmp->data=elem;
	tmp->next=p;
	q->next=tmp;
}
void deleteNode(Lnode *h,Lnode *p){
	Lnode *q=h;
	while(q->next!=p){
		q=q->next;
	}
	q->next=p->next;
	free(p);
}
Lnode* searchList(Lnode* h,DataType elem){
	Lnode *q=h->next;
	while(q!=NULL){
		if (q->data==elem)
		{
			/* code */
			return q;
		}else{
			q=q->next;
		}

	}
	return q;
}

void splitList(Lnode* h,Lnode* he,Lnode* ho){
	Lnode *q=h->next;
	Lnode *tmp=NULL;
	while(q!=NULL){
		tmp=q;
		if (q->data%2==1)
		{
			/* code */
			tmp->next=ho->next;
			ho->next=tmp;
		}else{
			tmp->next=he->next;
			he->next=tmp;
		}
		q=q->next;
	}
	free(h);
}

void mergeList(Lnode *hp,Lnode *hq,Lnode *h){
	Lnode *p=hp->next,*q=hq->next,*tmp=NULL;
	while(p!=NULL || q!=NULL){
		if (p->data <= q->data)
		{
			/* code */
			tmp=p;
			tmp->next=h->next;
			h->next=tmp;
			p=p->next;
		}else{
			tmp=q;
			tmp->next=h->next;
			h->next=tmp;
			q=q->next;
		}
	}
	while(p!=NULL){
		tmp=p;
		tmp->next=h->next;
		h->next=tmp;
		p=p->next;
	}
	while(q!=NULL){
		tmp=q;
		tmp->next=h->next;
		h->next=tmp;
		q=q->next;
	}
}

#endif