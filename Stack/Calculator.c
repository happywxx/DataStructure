#include <stdio.h>
#include <stdlib.h>
// #include "SeqStack.h"
#include "LinkStack.h"

int getNum(int a,int b,char ch,int pro){
	if(pro){
		if(ch =='*'){
			return a*b;
		}else if(ch =='/'){
			return a/b;
		}
	}else{
		if(ch =='*'){
			return a*b;
		}else if(ch =='/'){
			return a/b;
		}else if(ch=='+'){
			return a+b;
		}else if(ch=='-'){
			return a-b;
		}
	}
}
int main(int argc, char const *argv[])
{
	char express[40];
	LinkStack *oprt=NULL;
	LinkStack *opnd=NULL;
	int i,tmp=0,j;
	int b,a;
	char ch;
	// express=(char*)malloc(sizeof(char)*40);
	printf("请输入表达式,以#号键结束\n");
	i=0;
	scanf("%c",&ch);
	while(ch!='#'){
		express[i++]=ch;
		scanf("%c",&ch);
	}
	express[i]='#';
	opnd=(LinkStack*)malloc(sizeof(LinkStack));
	oprt=(LinkStack*)malloc(sizeof(LinkStack));
	initStack(opnd);
	initStack(oprt);
	push(oprt,(int)'#');
	for (i = 0; i < 40;)
	{
		/* code */
		if(express[i]>='0'&& express[i]<='9'){
			tmp=0;
			j=i;
			while(j<40 && express[j]>='0'&& express[j]<='9'){
				tmp=tmp*10+express[j]-'0';
				j++;
			}
			printf("%d",tmp);
			push(opnd,tmp);
		}else{
			printf("%c",express[i]);
			switch(express[i]){
				case '(':
					push(oprt,(int)express[i]);
				break;
				case '*':
				case '/':
					ch=(char)getTop(oprt);
					if(ch=='*'||ch=='/'){
						b=pop(opnd);
						a=pop(opnd);
						push(opnd,getNum(a,b,ch,1));
						pop(oprt);
					}
					push(oprt,(int)express[i]);
				break;
				case '+':
				case '-':
					ch=(char)getTop(oprt);
					if(ch=='*'||ch=='/'||ch=='+'||ch=='-'){
						b=pop(opnd);
						a=pop(opnd);
						push(opnd,getNum(a,b,ch,0));
						pop(oprt);
					}
					push(oprt,(int)express[i]);
				break;
				case ')':
					ch=(char)getTop(oprt);
					while(ch!='('){
						b=pop(opnd);
						a=pop(opnd);
						push(opnd,getNum(a,b,ch,0));
						pop(oprt);
						ch=(char)getTop(oprt);
					}
					pop(oprt);
				break;
				case '#':
					ch=(char)getTop(oprt);
					while(ch!='#'){
						b=pop(opnd);
						a=pop(opnd);
						push(opnd,getNum(a,b,ch,0));
						pop(oprt);
						ch=(char)getTop(oprt);
					}
				break;
			}
			j=i+1;
		}
		if(express[i]=='#'){
			break;
		}
		i=j;

	}
	printf("=%d\n",pop(opnd));
	return 0;
}