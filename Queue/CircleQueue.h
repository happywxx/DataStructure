#ifndef __CIRCLEQUEUE_H__
#define __CIRCLEQUEUE_H__ 

/*********************结构体定义区*********************/
typedef int DataType;
#define MaxSize 200
typedef struct 
{
	DataType queue[MaxSize];
	int front,rear;
}CircleQueue;

/*********************函数定义区************************/
//初始化循环队列
void initQueue(CircleQueue *q);
//清空队列
void clearQueue(CircleQueue *q);
//读取队头元素
DataType getTop(CircleQueue *q);
//判断队列是否为空
int isEmpty(CircleQueue *q);
//入队
void insertQueue(CircleQueue *q,DataType elem);
//出队
DataType deleteQueue(CircleQueue *q);

/*********************函数实现区************************/
void initQueue(CircleQueue *q){
	q->front=-1;
	q->rear=-1;
}

void clearQueue(CircleQueue *q){
	q->front=-1;
	q->rear=-1;
}

DataType getTop(CircleQueue *q){
	if(q->front==q->rear){
		printf("Empty Queue\n");
		exit(-1);
	}
	return q->queue[(q->front+1)%MaxSize];
}

int isEmpty(CircleQueue *q){
	return (q->front==q->rear);
}

void insertQueue(CircleQueue *q,DataType elem){
	if(q->front==(q->rear+1)%MaxSize){
		printf("Overflow\n");
		exit(-1);
	}
	q->rear=(q->rear+1)%MaxSize;
	q->queue[q->rear]=elem;
}

DataType deleteQueue(CircleQueue *q){
	if(q->front==q->rear){
		printf("Empty Queue\n");
		exit(-1);
	}
	q->front=(q->front+1)%MaxSize;
	return q->queue[q->front];
}
#endif