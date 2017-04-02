#include <stdio.h>
#include <stdlib.h>
#include "CharSequence.h"
int main(int argc, char const *argv[])
{
	CharSequence *s,*r,*t;
	s=(CharSequence*)malloc(sizeof(CharSequence));
	r=(CharSequence*)malloc(sizeof(CharSequence));
	t=(CharSequence*)malloc(sizeof(CharSequence));
	int i;
	initCharSequence(s);
	initCharSequence(t);
	initCharSequence(r);
	printf("%d\n",bruteMatch(s,t));
	replace(s,t,r);
	for(i=0;i<s->len;i++){
		printf("%c",s->str[i]);
	}
	printf("\n");
	return 0;
}