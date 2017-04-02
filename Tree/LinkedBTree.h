#ifndef __LINKEDBTREE_H__
#define __LINKEDBTREE_H__ 

#include "SeqQueue.h"
//以二叉链表的形式定义二叉树
/**********************结构体定义区**********************/
typedef int DataType;

typedef struct node
{
	struct node *LChild;
	DataType data;
	struct node *RChild;
}BTNode;

/**********************函数定义区************************/
//建立二叉树
BTNode* createBTree();
//二叉树遍历算法
//二叉树层次遍历算法
void LayerOrder(BTNode *root);
//递归遍历算法
//递归遍历之先序遍历
void preOrder(BTNode *root);
//递归遍历之中序遍历
void midOrder(BTNode *root);
//递归遍历之后序遍历
void postOrder(BTNode *root);
//查找结点
BTNode* searchBTree(BTNode *root,DataType elem);
//求二叉树的深度
int getDepth(BTNode *root);
/**********************函数实现区************************/
BTNode* createBTree(){
	BTNode *bt=NULL;
	int elem;
	scanf("%d",&elem);
	if(elem!=-1){
		bt=(BTNode*)malloc(sizeof(BTNode));
		if(bt==NULL){
			printf("memory allocation failure\n");
			exit(1);
		}
		bt->data=elem;
		bt->LChild=createBTree();
		bt->RChild=createBTree();
	}
	return bt;
}

//二叉树层次遍历算法
void LayerOrder(BTNode *root){
	BTNode *t;
	SeqQueue btQueue;
	initQueue(&btQueue);
	if(NULL!=root){
		insertQueue(&btQueue,(int)root);
	}
	while(!isEmpty(&btQueue)){
		t=(BTNode*)deleteQueue(&btQueue);
		printf("%d ",t->data);
		if(NULL!=t->LChild){
			insertQueue(&btQueue,(int)t->LChild);
		}
		if(NULL!=t->RChild){
			insertQueue(&btQueue,(int)t->RChild);
		}
	}
}
//递归遍历之先序遍历
void preOrder(BTNode *root){
	if(NULL!=root){
		printf("%d ",root->data);
		preOrder(root->LChild);
		preOrder(root->RChild);
	}
}
//递归遍历之中序遍历
void midOrder(BTNode *root){
	if(NULL!=root){
		midOrder(root->LChild);
		printf("%d ",root->data);
		midOrder(root->RChild);
	}
}
//递归遍历之后序遍历
void postOrder(BTNode *root){
	if(NULL!=root){
		postOrder(root->LChild);
		postOrder(root->RChild);
		printf("%d",root->data);
	}
}
//查找结点
BTNode* searchBTree(BTNode *root,DataType elem){
	BTNode *tmp;
	if(NULL==root){
		return NULL;
	}
	if(root->data==elem){
		return root;
	}
	tmp=searchBTree(root->LChild,elem);
	if(NULL!=tmp){
		return tmp;
	}
	tmp=searchBTree(root->RChild,elem);
	return tmp;

}
//求二叉树的深度
int getDepth(BTNode *root){
	int ldepth=0,rdepth=0;
	if(NULL==root){
		return 0;
	}
	ldepth=getDepth(root->LChild);
	rdepth=getDepth(root->RChild);
	if(ldepth>rdepth){
		return ldepth+1;
	}else{
		return rdepth+1;
	}
}
#endif