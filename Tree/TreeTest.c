#include <stdio.h>
#include <stdlib.h>
#include "Tree.h"

// 以下为树的测试用例:A(B(E,F,G),C(H,I),D)
int main(int argc, char const *argv[])
{
	char *a;
	TreeNode *root=NULL;
	printf("请以广义表形式输入树\n");
	a=(char*)malloc(sizeof(char)*100);
	gets(a);
	root=createTree(a);
	printf("depth: %d\n",getTreeDepth(root));
	layerOrderTree(root);
	return 0;
}