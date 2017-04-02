#include <stdio.h>
#include <stdlib.h>
// #include "LinkedBTree.h"
// #include "LinkedTTree.h"
// #include "BSTree.h"
#include "HufTree.h"
#include <string.h>


int main(int argc, char const *argv[])
{
	/********************二叉树测试区***********************/
	// BTNode *root;
	// root=createBTree();
	// LayerOrder(root);
	// printf("\n%d",getDepth(searchBTree(root,2)));
	// return 0;
	/********************二叉线索树测试区*******************/
	// TTNode *root;
	// root=createTTree();
	// midThread(root);
	// midTOrder(root);
	// // printTree(root);
	// return 0;
	/********************二叉排序树测试区*******************/
	// BSTNode *root;
	// int tmp;
	// printf("请输入树的数据，以-1结束\n");
	// root=createBSTree();
	// printf("二叉排序树的中序遍历结果为：\n");
	// printBSTree(root);
	// printf("\n请输入要删除的数据\n");
	// scanf("%d",&tmp);
	// deleteBSTree(root,tmp);
	// printf("二叉排序树的中序遍历结果为：\n");
	// printBSTree(root);
	// return 0;
	/********************哈夫曼树测试区*******************/
	//len为字符串的长度，n为不重复字符的长度
	//测试用例AAABBBCD或者AABBBCCCD
	char str[100],*content;
	int len,*w,*result,n=0,*flag,i,j;
	HufNode *root;
	printf("请输入一行要编码的字符串\n");
	gets(str);
	len=strlen(str);
	content=(char*)malloc(sizeof(char)*len);
	w=(int*)malloc(sizeof(int)*len);
	flag=(int*)malloc(sizeof(int)*len);
	for(i=0;i<len;i++){
		flag[i]=0;
	}
	for(i=0;i<len;i++){
	int vCnt=5,i,a,b;
		if(flag[i]==0){
			content[n]=str[i];
			w[n]=1;
			for(j=i+1;j<len;j++){
				if(str[j]==str[i]){
					flag[j]=1;
					w[n]=w[n]+1;
				}
			}
			n++;
		}
	}
	root=createHufTree(content,w,n);
	result=(int*)malloc(sizeof(int)*getLength(root));
	for(i=0;i<n;i++){
		k=0;
		len=searchForCode(root,content[i],result);
		printf("%c: ",content[i]);
		for(j=len-1;j>=0;j--){
			printf("%d ",result[j]);
		}
		printf("\n");
	}

	return 0;

}