#ifndef __BSTREE_H__
#define __BSTREE_H__
// #include <stdio.h>
// #include <stdlib.h>
//二叉排序树
/**************************结构体定义区**************************/
typedef int DataType;
typedef struct node
{
	struct node *LChild;
	DataType data;
	struct node *RChild;
}BSTNode;
/**************************函数定义区****************************/
//在二叉排序树中插入节点
BSTNode* insertBSTree(BSTNode *root,DataType elem);
//建立二叉排序树
BSTNode* createBSTree();
//二叉排序树的查找
BSTNode* searchBSTree(BSTNode* root,DataType elem);
//二叉排序树的删除
BSTNode* deleteBSTree(BSTNode* root,DataType elem);
//打印二叉树,中序打印
void printBSTree(BSTNode* root);
/**************************函数实现区****************************/
//在二叉排序树中插入节点
BSTNode* insertBSTree(BSTNode *root,DataType elem){
	BSTNode *t;
	if(NULL==root){
		t=(BSTNode*)malloc(sizeof(BSTNode));
		t->data=elem;
		t->LChild=NULL;
		t->RChild=NULL;
	}else if(elem<root->data){
		if(NULL!=root->LChild){
			t=insertBSTree(root->LChild,elem);
		}else{
			t=(BSTNode*)malloc(sizeof(BSTNode));
			t->data=elem;
			t->LChild=NULL;
			t->RChild=NULL;
			root->LChild=t;
		}		
	}else if(elem>root->data){
		if(NULL!=root->RChild){
			t=insertBSTree(root->RChild,elem);
		}else{
			t=(BSTNode*)malloc(sizeof(BSTNode));
			t->data=elem;
			t->LChild=NULL;
			t->RChild=NULL;
			root->RChild=t;
		}
	}
	return t;
}
//建立二叉排序树
BSTNode* createBSTree(){
	DataType elem;
	BSTNode *root=NULL;
	scanf("%d",&elem);
	while(-1!=elem){
		if(NULL==root){
			root=insertBSTree(root,elem);
		}else{
			insertBSTree(root,elem);
		}
		scanf("%d",&elem);
	}
	return root;
}
//二叉排序树的查找
BSTNode* searchBSTree(BSTNode* root,DataType elem){
	if(root==NULL){
		return NULL;
	}else if(elem==root->data){
		return root;
	}else if(elem<root->data){
		return searchBSTree(root->LChild,elem);
	}else{
		return searchBSTree(root->RChild,elem);
	}
}
//二叉排序树的删除
BSTNode* deleteBSTree(BSTNode* root,DataType elem){
	BSTNode *f=NULL,*c=root,*fp,*p;
	//while循环找出要删除的结点，保存为c
	//并记录其父结点，保存为f
	while(c->data!=elem){
		if(elem<c->data){
			f=c;
			c=c->LChild;
		}else{
			f=c;
			c=c->RChild;
		}
		if(c==NULL){
			printf("无此结点\n");
			return root;
		}
	}
	//如果要删除的结点没有右孩子，先判断其是否为根结点
	//若f=NULL,则c为根结点，则将c指向其左孩子，
	//若c不为根结点，则判断c是f的左孩子还是右孩子，并改变f的左或右孩子
	if(NULL==c->RChild){
		if(NULL==f){
			c=c->LChild;
			free(root);
			return c;
		}else{
			if(c->data<f->data){
				f->LChild=c->LChild;
			}else{
				f->RChild=c->LChild;
			}
			free(c);
		}
	//若要删除的结点没有左孩子，同上
	}else if(NULL==c->LChild){
		if(NULL==f){
			c=c->RChild;
			free(root);
			return c;
		}else{
			if(c->data<f->data){
				f->LChild=c->LChild;
			}else{
				f->RChild=c->RChild;
			}
			free(c);
		}
	//若要删除的结点既有左孩子也有右孩子，则先找出c的中序遍历前驱
	//根据二叉排序树的特点，c的中序遍历前驱即为c的左子树中右节点为NULL的结点
	//若c的中序遍历前驱为c的左孩子，记为p，
	//则用p中的数据替换c中的数据，并用p的左孩替换c的左孩子,
	//并将p删除，相当于把p移动到c的位置
	//否则的话，用用p的数据替换c的数据，并将fp(p的父节点)的右孩子指向p的左孩子
	}else{
		fp=c;p=c->LChild;
		while(p->RChild!=NULL){
			fp=p;
			p=p->RChild;
		}
		if(fp==c){
			fp->data==p->data;
			fp->LChild=p->LChild;
			free(p);
		}else{
			c->data=p->data;
			fp->RChild=p->LChild;
			free(p);
		}
	}
	return root;

}
void printBSTree(BSTNode* root){
	if(root!=NULL){
		printBSTree(root->LChild);
		printf("%d ",root->data);
		printBSTree(root->RChild);
	}
}

#endif