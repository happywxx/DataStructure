#ifndef __CIRCLELIST_H__
#define __CIRCLELIST_H__


/***********************结构体定义区***********************/
//此头文件中定义双向链表及其相关方法
typedef int DataType;

typedef struct node
{
	DataType data;
	struct node *prev;
	struct node *next;
}CListNode;


/***********************函数定义区***********************/
//初始化链表
CListNode* initList();

//创建链表
void createList(CListNode *h);

//清空链表
void clearList(CListNode *h);

//输出链表中的每个值
void printList(CListNode *h);

//求链表的长度
int getLength(CListNode *h);

//判断链表是否为空
int isEmpty(CListNode *h);

//在给定节点之后插入一个数据元素
void insertAfter(CListNode *p,DataType elem);

//在给定节点之前插入一个数据元素
void insertBefore(CListNode *p,DataType elem);

//删除指定的节点
void deleteNode(CListNode *p);

/***********************函数实现区***********************/

CListNode* initList(){
	CListNode *h=(CListNode*)malloc(sizeof(CListNode));
	h->prev=NULL;
	h->next=NULL;
	return h;
}

void createList(CListNode *h){
	CListNode *tmp=NULL,*cur=h;
	int n;
	printf("请输入双向链表的长度\n");
	scanf("%d",&n);
	printf("请输入双向链表的数据\n");
	int i;
	for (i = 0; i < n; ++i)
	{
		/* code */
		int t;
		scanf("%d",&t);
		tmp=(CListNode*)malloc(sizeof(CListNode));
		tmp->data=t;
		tmp->prev=cur;
		tmp->next=NULL;
		cur->next=tmp;
		cur=cur->next;
	}
}

//清空双向链表和清空单向链表形式一致
void clearList(CListNode *h){
	CListNode *tmp=NULL;
	while(h->next!=NULL){
		tmp=h->next;
		h->next=h->next->next;
		free(tmp);
	}
}
//输出链表
void printList(CListNode *h){
	CListNode *p=h->next;
	while(p!=NULL){
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
}
//以下函数基本与单链表LinkedList.c函数一致
//下面挑选不一致的函数来实现
//删除一个节点和插入一个节点

void insertAfter(CListNode *p,DataType elem){
	//先判断p是否为尾指针

	CListNode *tmp=(CListNode*)malloc(sizeof(CListNode));
	if (p->next==NULL)
	{
		/* code */
		tmp->data=elem;
		tmp->prev=p;
		tmp->next=p->next;
		p->next=tmp;
	}else{
		tmp->data=elem;
		tmp->next=p->next;
		tmp->prev=p;
		p->next->prev=tmp;
		p->next=tmp;
	}
	
}
void insertBefore(CListNode *p,DataType elem){
	CListNode *tmp=(CListNode*)malloc(sizeof(CListNode));
	tmp->data=elem;
	tmp->next=p;
	tmp->prev=p->prev;
	p->prev->next=tmp;
	p->prev=tmp;
}

void deleteNode(CListNode *p){
	if (p->next==NULL)
	{
		/* code */
		p->prev->next=NULL;
		free(p);
	}else{
		p->prev->next=p->next;
		p->next->prev=p->prev;
		free(p);
	}
	
}

#endif