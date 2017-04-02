#ifndef __LINKEDTTREE_H__
#define __LINKEDTTREE_H__ 

/**************************结构体定义区**************************/
typedef int DataType;
typedef struct node
{
	int LTag;
	struct node *LChild;
	DataType data;
	int RTag;
	struct node *RChild;
}TTNode;
/**************************函数定义区****************************/
//建立二叉树
TTNode* createTTree();
//二叉树的线索化与遍历均采用中序
//二叉树线索化
void midThread(TTNode *root);
//遍历线索二叉树
void midTOrder(TTNode *root);
//打印线索二叉树
void printTree(TTNode *root);
/**************************函数实现区****************************/
//建立二叉树
TTNode* createTTree(){
	int elem;
	TTNode *root;
	scanf("%d",&elem);
	if(elem!=-1){
		root=(TTNode*)malloc(sizeof(TTNode));
		root->data=elem;
		root->LTag=0;
		root->RTag=0;
		root->LChild=createTTree();
		root->RChild=createTTree();
	}else{
		root=NULL;
	}
	return root;
}
//二叉树的线索化与遍历均采用中序
//二叉树线索化
void midThread(TTNode *root){
	static TTNode *pre=NULL;
	if(NULL!=root){
		midThread(root->LChild);
		if(NULL!=pre && pre->RTag==1){
			pre->RChild=root;
		}
		if(NULL==root->LChild){
			root->LTag=1;
			root->LChild=pre;
		}
		if(NULL==root->RChild){
			root->RTag=1;
		}
		pre=root;
		midThread(root->RChild);
	}
}
//遍历线索二叉树
//遍历二叉线索树之后，可以线索二叉树为基础对线索二叉树进行遍历操作
//遍历的基本思路：首先找到遍历序列的第一个结点，然后找到它的后继结点
//以及后继结点的后继等。当找到最后一个结点时，它的后继为空，遍历结束
//在中序线索二叉树中，寻找一个结点t的后继可以分为如下两种情况：
//（1）如果RTag==1,则它的右指针域RChild指向的结点就是它的后序指针
//（2）如果RTag==0,则它的右子树中最左边的结点就是它的中序后继。寻找时，
//先要找到结点t的右孩子结点r,再找到结点r的左孩子，然后找到左孩子的左孩子，
//直到找到一个没有左孩子的结点p,结点p就是t的中序后继。
void midTOrder(TTNode *root){
	TTNode *t=root;
	if(NULL!=t){
		while(t->LTag==0){
			t=t->LChild;
		}
		while(NULL!=t){
			printf("%d ",t->data);
			if(t->RTag==1){
				t=t->RChild;
			}else{
				t=t->RChild;
				while(t->LTag==0){
					t=t->LChild;
				}
			}
		}
	}
}
void printTree(TTNode *root){
	if(root!=NULL){
		if(root->LTag==0){
			printTree(root->LChild);
		}
		printf("*****************************\n");
		printf("the content is %d\n",root->data);
		printf("the LTag is %d\n",root->LTag);
		if(root->LTag==1){
			if(root->LChild==NULL){
				printf("no pre\n");
			}else{
				printf("the pre is %d\n",root->LChild->data);
			}			
		}
		printf("the RTag is %d\n",root->RTag);
		if(root->RTag==1){
			if(root->RChild==NULL){
				printf("no next\n");
			}else{
				printf("the next is %d\n",root->RChild->data);
			}
		}
		if(root->RTag==0){
			printTree(root->RChild);
		}
	}
}
#endif