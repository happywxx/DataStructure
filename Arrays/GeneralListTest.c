#include <stdio.h>
#include <stdlib.h>
#include "GeneralList.h"
#include "CharSequence.h"

int main(int argc, char const *argv[])
{
	CharSequence *pStr;
	GNode *head;
	pStr=(CharSequence*)malloc(sizeof(CharSequence));
	initCharSequence(pStr);
	head=createGList(pStr);
	printList(head);
	free(pStr);
	return 0;
}