#ifndef __TREE_H__
#define __TREE_H__ 
#include "SeqQueue.h"
/**************************结构体定义区**************************/
// 以定长方式的孩子表示法作为树的存储结构
#define N 10
#define M 30
typedef char MyDataType;
typedef struct tnode
{
	MyDataType data;
	struct tnode *child[N];
}TreeNode;
/**************************函数定义区****************************/
//创建树的存储结构
TreeNode* createTree(char a[]);
//遍历树
//先序遍历
void preOrderTree(TreeNode *root);
//后序遍历
void postOrderTree(TreeNode *root);
//层次遍历
void layerOrderTree(TreeNode *root);
//求树的深度
int getTreeDepth(TreeNode *root);
/**************************函数实现区****************************/
//创建树的存储结构
//M表示树的深度，类似于堆栈，top表示栈顶元素，栈顶为当前层 树的存储
//link[top]记录当前层孩子的数量，即为下一个孩子的下标
TreeNode* createTree(char a[]){
	TreeNode *s[M],*root,*t;
	int link[M],i,j,top;
	i=0;root=NULL;top=-1;
	while(a[i]){
		switch(a[i]){
			case ' ':break;
			case '(':top++;s[top]=t;link[top]=0;break;
			case ')':top--;break;
			case ',':link[top]++;break;
			default:
				t=(TreeNode*)malloc(sizeof(TreeNode));
				t->data=a[i];
				for(j=0;j<N;j++){
					t->child[j]=NULL;
				}
				if(NULL==root){
					root=t;
				}else{
					s[top]->child[link[top]]=t;
				}
		}
		i++;
	}
	return root;
}
//先序遍历
void preOrderTree(TreeNode *root){
	int i;
	if(NULL!=root){
		printf("%c ",root->data);
		for(i=0;i<N;i++){
			preOrderTree(root->child[i]);
		}
	}
}
//后序遍历
void postOrderTree(TreeNode *root){
	int i;
	if(NULL!=root){
		for(i=0;i<N;i++){
			postOrderTree(root->child[i]);
		}
		printf("%c ",root->data);
	}
}
//层次遍历
void layerOrderTree(TreeNode *root){
	int i;
	TreeNode *t;
	SeqQueue btQueue;
	initQueue(&btQueue);
	if(NULL!=root){
		insertQueue(&btQueue,(int)root);
	}
	while(!isEmpty(&btQueue)){
		t=(TreeNode*)deleteQueue(&btQueue);
		printf("%c ",t->data);
		for(i=0;i<N;i++){
			if(NULL!=t->child[i]){
				insertQueue(&btQueue,(int)t->child[i]);
			}
		}
	}
}
//求树的深度
int getTreeDepth(TreeNode *root){
	int i,max,depth;
	if(NULL==root){
		return 0;
	}else{
		max=0;
		for(i=0;i<N;i++){
			depth=getTreeDepth(root->child[i]);
			if(depth>max){
				max=depth;
			}
		}
	}
	return max+1;
}
#endif