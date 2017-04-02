#include <stdio.h>
#include <stdlib.h>
// #include "SeqStack.h"
#include "LinkStack.h"

int main(int argc, char const *argv[])
{
	/***************顺序栈*****************/
	// int i;
	// SeqStack *s=(SeqStack*)malloc(sizeof(SeqStack));
	// initStack(s);
	// for (i = 0; i < 10; ++i)
	// {
	// 	push(s,i);
	// }
	// for (i = 0; i < 10; ++i)
	// {
	// 	printf("%d ",pop(s));
	// }
	// return 0;
	/***************链式栈*******************/
	int i;
	LinkStack *LS=(LinkStack*)malloc(sizeof(LinkStack));
	initStack(LS);
	for (i = 0; i < 10; ++i)
	{
		push(LS,i);
	}
	for (i = 0; i < 10; ++i)
	{
		printf("%d\n",pop(LS));
	}
	/****************************************/
	
}