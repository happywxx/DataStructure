#include <stdio.h>
#include <stdlib.h>
// #include "SeqQueue.h"
// #include "LinkQueue.h"
#include "CircleQueue.h"

int main(int argc, char const *argv[])
{
	/*******************顺序队列测试区*******************/
	// SeqQueue *q=(SeqQueue*)malloc(sizeof(SeqQueue));
	// int i;
	// initQueue(q);
	// for(i=0;i<10;i++){
	// 	insertQueue(q,i);
	// }
	// for(i=0;i<10;i++){
	// 	printf("%d ",deleteQueue(q));
	// }
	// printf("\n");
	// printf("the queue %s empty\n", isEmpty(q)!=0?"is":"is not");
	// return 0;
	/*******************链式队列测试区*******************/
	// LinkQueue *q=(LinkQueue*)malloc(sizeof(LinkQueue));
	// int i;
	// initQueue(q);
	// for(i=0;i<10;i++){
	// 	insertQueue(q,i);
	// }
	// for(i=0;i<10;i++){
	// 	printf("%d ",deleteQueue(q));
	// }
	// printf("\n");
	// printf("the queue %s empty\n", isEmpty(q)!=0?"is":"is not");
	// return 0;
	/*******************循环队列测试区*******************/
	CircleQueue *q=(CircleQueue*)malloc(sizeof(CircleQueue));
	int i;
	initQueue(q);
	for(i=0;i<10;i++){
		insertQueue(q,i);
	}
	for(i=0;i<6;i++){
		// printf("%d ",deleteQueue(q));
		deleteQueue(q);
	}
	for(i=5;i<9;i++){
		insertQueue(q,i);
	}
	while(!isEmpty(q)){
		printf("%d ",deleteQueue(q));
	}
	printf("\n");
	printf("the queue %s empty\n", isEmpty(q)!=0?"is":"is not");
	return 0;
}