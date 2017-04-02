#ifndef __SEQQUEUE_H__
#define __SEQQUEUE_H__ 

/*******************结构体定义区*******************/
typedef int DataType;
#define MaxSize 200

typedef struct 
{
	DataType queue[MaxSize];
	int front,rear;
}SeqQueue;

/*******************函数定义区*********************/
//初始化队列
void initQueue(SeqQueue *q);
//清空队列
void clearQueue(SeqQueue *q);
//读取队头元素
DataType getTop(SeqQueue *q);
//检查队列是否为空
int isEmpty(SeqQueue *q);
//入队
void insertQueue(SeqQueue *q,DataType elem);
//出队
DataType deleteQueue(SeqQueue *q);

/*******************函数实现区**********************/
void initQueue(SeqQueue *q){
	q->front=-1;
	q->rear=-1;
}

void clearQueue(SeqQueue *q){
	q->front=-1;
	q->rear=-1;
}

DataType getTop(SeqQueue *q){
	if(q->front==q->rear){
		printf("Empty Queue\n");
		exit(-1);
	}
	return q->queue[q->front+1];
}

int isEmpty(SeqQueue *q){
	return (q->front==q->rear);
}

void insertQueue(SeqQueue *q,DataType elem){
	if(q->rear==MaxSize-1){
		printf("Overflow\n");
		exit(-1);
	}
	q->rear=q->rear+1;
	q->queue[q->rear]=elem;
}

DataType deleteQueue(SeqQueue *q){
	if(q->front==q->rear){
		printf("Empty Queue\n");
		exit(-1);
	}
	q->front++;
	return q->queue[q->front];
}
#endif