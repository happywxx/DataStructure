#include <stdio.h>
#include <stdlib.h>
#include "Heap.h"

//测试用例4 1 3 2 9 7 6 8 10 -1
int main(int argc, char const *argv[])
{
	Heap *h;
	h=(Heap*)malloc(sizeof(Heap));
	initHeap(h);
	createHeap(h);
	printf("****************************************\n");
	printHeap(h);
	insertHeap(h,5);
	printf("****************************************\n");
	printHeap(h);
	removeHeapItem(h,1);
	printf("****************************************\n");
	printHeap(h);
	return 0;
}