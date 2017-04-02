#ifndef __LINKQUEUE_H__
#define __LINKQUEUE_H__ 
#include <stdio.h>
#include <stdlib.h>

/**********************结构体定义区********************/

typedef int DataType;

typedef struct node
{
	DataType data;
	struct node *next;
}QNode;

typedef struct 
{
	QNode *front;
	QNode *rear;
}LinkQueue;

/***********************函数定义区*********************/
// 初始化队列
void initQueue(LinkQueue *q);
//清空队列
void clearQueue(LinkQueue *q);
//读取队头元素
DataType getTop(LinkQueue *q);
//判断队列是否为空
int isEmpty(LinkQueue *q);
//入队
void insertQueue(LinkQueue *q,DataType elem);
//出队
DataType deleteQueue(LinkQueue *q);


/***********************函数实现区************************/

void initQueue(LinkQueue *q){
	q->front=NULL;
	q->rear=NULL;
}
void clearQueue(LinkQueue *q){
	QNode *tmp=NULL;
	while(q->front!=NULL){
		tmp=q->front;
		q->front=tmp->next;
		free(tmp);
	}
}

DataType getTop(LinkQueue *q){
	//首先判断队列是否为空
	if(q->front==NULL){
		printf("Empty Queue\n");
		exit(-1);
	}
	return q->front->data;
}

int isEmpty(LinkQueue *q){
	return (q->front==NULL);
}

void insertQueue(LinkQueue *q,DataType elem){
	QNode *tmp=NULL;
	tmp=(QNode*)malloc(sizeof(QNode));
	if(NULL==tmp){
		printf("Error allocate memory\n");
		exit(-1);
	}
	tmp->data=elem;
	tmp->next=NULL;
	if(q->rear==NULL){
		q->front=tmp;
		q->rear=tmp;
	}else{
		q->rear->next=tmp;
		q->rear=tmp;
	}
	
}

DataType deleteQueue(LinkQueue *q){

	DataType tData;
	QNode *tmp=NULL;
	if(q->front==NULL){
		printf("Empty Queue\n");
		exit(-1);
	}
	tData=q->front->data;
	tmp=q->front;
	q->front=q->front->next;
	if(q->front==NULL){
		q->rear=NULL;
	}
	free(tmp);
	return tData;
}


#endif