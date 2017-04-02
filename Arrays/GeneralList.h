#ifndef __GENERALLIST_H__
#define __GENERALLIST_H__ 
#include "CharSequence.h"
/******************结构体定义区*****************/
// enum NodeType{head=0,atom=1,sub=2};
typedef char DataType;
typedef struct GNode
{
	int type;

	union{
		DataType data;
		struct GNode *sub;
	}datSub;
	struct GNode *next;
}GNode;
/******************函数定义区*******************/
//广义表的初始化
GNode* initGList();
//创建广义表
GNode* createGList(CharSequence *pStr);
//求广义表的长度
int getLength(GNode *head);
//求广义表的深度
int getDepth(GNode *head);
//输出广义表
void printList(GNode *head);
/******************函数实现区*******************/
//广义表的初始化
GNode* initGList(){
	GNode *head;
	head=(GNode*)malloc(sizeof(GNode));
	head->type=0;
	head->datSub.sub=NULL;
	head->next=NULL;
	return head;
}
//创建广义表
GNode* createGList(CharSequence *pStr){
	int i,j,len;
	DataType data;
	GNode *head=initGList(),*tmp,*cur;
	CharSequence *tmpStr;
	cur=head;
	for(i=1;i<pStr->len-1;i++){
		if(pStr->str[i]!=',' && pStr->str[i]!='('){
			tmp=(GNode*)malloc(sizeof(GNode));
			tmp->type=1;
			tmp->datSub.data=pStr->str[i];
			tmp->next=NULL;
			if(cur->type==0){
				cur->datSub.sub=tmp;
				cur=tmp;
			}else{
				cur->next=tmp;
				cur=tmp;
			}
		}else if(pStr->str[i]=='('){
			j=i+1;
			len=0;
			while(pStr->str[j]!=')' || len!=0){
				if(pStr->str[j]=='('){
					len++;
				}else if(pStr->str[j]==')'){
					len--;
				}
				j++;
			}
			tmpStr=(CharSequence*)malloc(sizeof(CharSequence));
			subString(tmpStr,pStr,i,j+1);
			tmp=(GNode*)malloc(sizeof(GNode));
			tmp=createGList(tmpStr);
			tmp->type=2;
			if(cur->type==0){
				cur->datSub.sub=tmp;
				cur=tmp;
			}else{
				cur->next=tmp;
				cur=tmp;
			}
			i=j;
		}
	}
	free(tmpStr);
	return head;
}
//求广义表的长度
int getLength(GNode *head){
	int len=0;
	GNode* p=head;
	if(p->type==0){
		p=p->datSub.sub;
	}
	if(NULL!=p){
		len=getLength(p->next);
		return len+1;
	}else{
		return 0;
	}
}
//求广义表的深度
int getDepth(GNode *head){
	int depth=0,maxDepth=0;
	GNode *p=head;
	if(p->type==0){
		p=p->datSub.sub;
	}
	while(NULL!=p){
		if(p->type==2){
			depth=getDepth(p->datSub.sub);
			if(depth>maxDepth){
				maxDepth=depth;
			}
		}
		p=p->next;
	}
	return maxDepth+1;
}
//输出广义表
void printList(GNode *head){
	if(head->type==0 || head->type==2){
		printf("(");
		if(head->datSub.sub==NULL){
			printf(" ");
		}else{
			printList(head->datSub.sub);
		}
	}else{
		printf("%c",head->datSub.data);
	}
	if(head->type==0 || head->type==2){
		printf(")");
	}
	if(head->next!=NULL){
		printf(",");
		printList(head->next);
	}
}
#endif