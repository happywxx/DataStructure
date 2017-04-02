#ifndef __LINKSTACK_H__
#define __LINKSTACK_H__ 

//链栈
//首先定义链栈节点
//以链栈节点的指针定义链栈,即为链栈头指针
//链栈头指针指向的链栈节点包含栈中其他元素的位置
/***************结构体定义区*****************/

typedef int DataType;
//定义链栈的节点
typedef struct node
{
	DataType data;
	struct node *next;
}SNode;

//定义链栈的数据结构
typedef struct 
{
	SNode *top;
}LinkStack;

/****************函数定义区*******************/
// 初始化链栈
void initStack(LinkStack *LS);
// 清空栈
void clearStack(LinkStack *LS);
//读取栈顶元素
DataType getTop(LinkStack *LS);
//检查栈是否为空
int isEmpty(LinkStack *LS);
//入栈
void push(LinkStack *LS,DataType elem);
//出栈
DataType pop(LinkStack *LS);
/*****************函数实现区******************/
void initStack(LinkStack *LS){
	LS->top=NULL;
}
void clearStack(LinkStack *LS){
	SNode *p=LS->top,*q=NULL;
	while(p!=NULL){
		q=p;
		p=p->next;
		free(q);
	}
	LS->top=NULL;
}

DataType getTop(LinkStack *LS){
	if(LS->top==NULL){
		printf("链栈为空\n");
		exit(-1);
	}
	return (LS->top->data);
}

int isEmpty(LinkStack *LS){
	return (LS->top==NULL);
}

void push(LinkStack *LS,DataType elem){
	//需要先为新的元素分配空间
	//若分配失败,则退出
	SNode *tmp=(SNode*)malloc(sizeof(SNode));
	if(NULL==tmp){
		printf("failed to allocate memory\n");
		exit(-1);
	}
	tmp->data=elem;
	tmp->next=LS->top;
	LS->top=tmp;
}

DataType pop(LinkStack *LS){
	//需要判断是否已到栈底
	SNode *tmp=NULL;
	DataType tData;
	if(LS->top==NULL){
		printf("链栈为空\n");
		exit(-1);
	}
	tmp=LS->top;
	LS->top=tmp->next;
	tData=tmp->data;
	free(tmp);
	return tData;

}
#endif