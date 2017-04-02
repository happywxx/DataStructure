#include <stdio.h>
#include <stdlib.h>
// #include "OrderTableTest.h"
#include "LinkedList.h"
#include "SequenceList.h"


int main(int argc, char const *argv[])
{
	/* SeqList 顺序表 */
	// SeqList *L=(SeqList*)malloc(sizeof(SeqList));
	// initList(L);
	// createList(L);
	// printList(L);
	// fastInsert(L,0);
	// fastInsert(L,10);
	// fastInsert(L,20);
	// printList(L);
	// return 0;
	/*LinkedList 链表*/
	Lnode *h=initList();
	createList(h);
	printList(h);
	insertAfter(h->next,getLength(h));
	printList(h);
	deleteNode(h,h->next);
	printList(h);
	Lnode *p=searchList(h,getLength(h));
	printf("the index of element %d is p,p->data=%d\n",getLength(h),p->data);
	return 0;
}