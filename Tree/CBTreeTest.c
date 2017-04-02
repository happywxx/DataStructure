#include <stdio.h>
#include <stdlib.h>
#include "LinkedBTree.h"

//获得数的结点数目，有一个非零结点，则返回值加1
int num(BTNode *t,int i,int *m){
	if(t==NULL){
		return 0;
	}
	if(*m<i){
		*m=i;
	}
	return (1+num(t->LChild,2*i,m)+num(t->RChild,2*i+1,m));
}
//判断树是否为完全二叉树
int checkTree(BTNode *root){
	//n为树的结点数目，maxn为将此树当成完全二叉树时,最后一个结点的序号
	//完全二叉树，若一个结点的序号为i,则其左孩子的序号为2*i,右孩子序号为2*i+1;
	int maxn=0,n;
	n=num(root,1,&maxn);
	if(n==maxn){
		printf("是完全二叉树,n=%d,maxn=%d\n",n,maxn);
	}else{
		printf("不是完全二叉树,n=%d,maxn=%d\n",n,maxn);
	}
}
//测试用例
//1 2 4 8 -1 -1 9 -1 -1 5 10 -1 -1 -1 3 6 -1 -1 7 -1 -1
//(相当于以前序遍历来建立二叉树)
//1 2 4 8 -1 -1 9 -1 -1 5 -1 -1 3 6 10 -1 -1 -1 7 -1 -1
int main(int argc, char const *argv[])
{
	BTNode *root;
	root=createBTree();
	checkTree(root);
	return 0;
}