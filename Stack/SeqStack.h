#ifndef __SEQSTACK_H__
#define __SEQSTACK_H__

/**************结构体定义区***************/
typedef int DataType;

#define MaxSize 200

//顺序栈的定义
// 用一组连续的存储单元存储栈中的元素
// 用top作为栈顶指针,当栈中无元素时，top指向-1
typedef struct 
{
	DataType stack[MaxSize];
	int top;
}SeqStack; 

/*****************函数定义区****************/
//初始化栈
void initStack(SeqStack *s);
//清空栈
void clearStack(SeqStack *s);
//读取栈顶数据元素
DataType getTop(SeqStack *s);
//检查栈是否为空
int isEmpty(SeqStack *s);
//入栈
void push(SeqStack *s,DataType elem);
//出栈
DataType pop(SeqStack *s);

/*****************函数实现区******************/
void initStack(SeqStack *s){
	s->top=-1;
}

void clearStack(SeqStack *s){
	s->top=-1;
}

DataType getTop(SeqStack *s){
	//首先检查栈是否为空
	if(s->top==-1){
		printf("栈为空\n");
		exit(-1);
	}
	return s->stack[s->top];
}

int isEmpty(SeqStack *s){
	return (s->top==-1);
}

void push(SeqStack *s,DataType elem){
	//首先检查栈是否已满
	if(s->top==MaxSize-1){
		printf("栈已满\n");
		exit(-1);
	}
	s->top++;
	s->stack[s->top]=elem;
}

DataType pop(SeqStack *s){
	//首先检查栈是否为空
	if(s->top==-1){
		printf("栈为空\n");
		exit(-1);
	}
	return (s->stack[s->top--]);
}
#endif