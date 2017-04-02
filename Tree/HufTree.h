#ifndef __HUFTREE_H
#define __HUFTREE_H 
#include <stdio.h>
#include <stdlib.h>
int k=0;
//哈夫曼树，即最优二叉树
/**************************结构体定义区**************************/
typedef struct hnode
{
	struct hnode *LChild;
	int weight;
	char content;
	struct hnode *RChild;
}HufNode;
/**************************函数定义区****************************/
//创建哈夫曼树
HufNode* createHufTree(char content[],int w[],int n);
//获取哈夫曼树的深度
int getLength(HufNode* root);
//利用哈夫曼树进行编码
int searchForCode(HufNode* root,char c,int* result);
/**************************函数实现区****************************/
//创建哈夫曼树
HufNode* createHufTree(char content[],int w[],int n){
	int i,j,min,smin;
	HufNode **s,*t;
	s=(HufNode**)malloc(n*sizeof(HufNode*));
	for(i=0;i<n;i++){
		s[i]=(HufNode*)malloc(sizeof(HufNode));
		s[i]->weight=w[i];
		s[i]->content=content[i];
		s[i]->LChild=s[i]->RChild=NULL;
	}
	for(i=0;i<n-1;i++){
		//min表示最小权重的下标，smin表示次小权重的下标
		//利用选择排序法选出最小权重和次小权重的下标
		min=i;smin=i+1;
		for(j=smin;j<n;j++){
			if(s[j]->weight<s[min]->weight){
				smin=min;
				min=j;
			}else if(s[j]->weight<s[smin]->weight){
				smin=j;
			}
		}
		//将权重最小s[min]与次小s[smin]的树合成一棵树t，并将原先最小和次小的树
		//s[min]和s[smin]删除，将合成的树t加入集合中
		t=(HufNode*)malloc(sizeof(HufNode));
		t->weight=s[min]->weight+s[smin]->weight;
		t->LChild=s[min];
		t->RChild=s[smin];
		//易混淆，若min==i,则将t赋值给s[smin],因为smin=i+1,所以在下一轮会被扫到
		//同时将s[i]置为空，若min!=i,则min>=i+1,则将t赋值给s[min],将s[i]赋值给s[smin],
		//同时将s[i]置为空，保证t和s[i]均能被扫描到。
		s[min]=t;
		s[smin]=s[i];
		s[i]=NULL;
	}
	return t;
}
//获取哈夫曼树的深度
int getLength(HufNode* root){
	int left,right;
	if(root==NULL){
		return 0;
	}
	left=getLength(root->LChild);
	right=getLength(root->RChild);
	return (left>right?left:right)+1;

}
//利用哈夫曼树进行编码
int searchForCode(HufNode* root,char c,int* result){
	if(root==NULL){
		return -1;
	}
	if(root->content==c){
		return k;
	}
	if(searchForCode(root->LChild,c,result)!=-1){
		*(result+k)=0;
		k++;
		return k;
	}
	if(searchForCode(root->RChild,c,result)!=-1){
		*(result+k)=1;
		k++;
		return k;
	}
	return -1;
}
#endif