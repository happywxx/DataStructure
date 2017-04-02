#ifndef __GRAPH_H__
#define __GRAPH_H__ 
#include "SeqQueue.h"
/**************************结构体定义区**************************/
//最大的图的顶点数
#define N 20
typedef struct graph
{
	int vCnt;//图的顶点数
	int type;//图的类型，0表示无向图，1表示有向图
	int adjMatrix[N][N];//静态分配一个二维数组，以存储图的邻接矩阵
}Graph;
/**************************函数定义区****************************/
//初始化图
Graph* initGraph(int vCnt,int type);
//判断图的类型
int getType(Graph *g);
//求图的顶点数
int getVCount(Graph *g);
//求图的边数
int getECount(Graph *g);
//插入边
void insertEdge(Graph *g,int u,int v);
//删除边
void deleteEdge(Graph *g,int u,int v);
//判断两个顶点是否相邻接
int isAdjcent(Graph *g,int u,int v);
//计算一个顶点的度
int getDegree(Graph *g,int u);
//计算一个顶点的出度
int getOutDegree(Graph *g,int u);
//计算一个顶点的入度
int getInDegree(Graph *g,int u);
//深度优先遍历
void dfs(Graph *g,int v,int *visited);
//广度优先遍历
void bfs(Graph *g,int v);
/**************************函数实现区****************************/
//初始化图
Graph* initGraph(int vCnt,int type){
	int i,j;
	Graph *graph=(Graph*)malloc(sizeof(Graph));
	graph->vCnt=vCnt;
	graph->type=type;
	for(i=0;i<vCnt;i++){
		for(j=0;j<vCnt;j++){
			graph->adjMatrix[i][j]=0;
		}
	}
	return graph;
}
//判断图的类型
int getType(Graph *g){
	return g->type;
}
//求图的顶点数
int getVCount(Graph *g){
	return g->vCnt;
}
//求图的边数
int getECount(Graph *g){
	int eCnt=0,i,j;
	for(i=0;i<g->vCnt;i++){
		for(j=0;j<g->vCnt;j++){
			if(1==g->adjMatrix[i][j]){
				eCnt++;
			}
		}
	}
	if(g->type==0){
		return eCnt/2;
	}
	return eCnt;
}
//插入边
//u,v分别表示定点的下标，以1开始
void insertEdge(Graph *g,int u,int v){
	if(g->type==0){
		g->adjMatrix[u-1][v-1]=1;
		g->adjMatrix[v-1][u-1]=1;
	}else{
		g->adjMatrix[u-1][v-1]=1;
	}
}
//删除边
void deleteEdge(Graph *g,int u,int v){
	if(g->type==0){
		g->adjMatrix[u-1][v-1]=0;
		g->adjMatrix[u-1][v-1]=0;
	}else{
		g->adjMatrix[u-1][v-1]=0;
	}
}
//判断两个顶点是否相邻接
int isAdjcent(Graph *g,int u,int v){
	return g->adjMatrix[u-1][v-1];
}
//计算一个顶点的度
int getDegree(Graph *g,int u){
	int i,j,d=0;
	if(g->type==0){
		for(j=0;j<g->vCnt;j++){
			d+=g->adjMatrix[u-1][j];
		}
	}else{
		for(j=0;j<g->vCnt;j++){
			d+=g->adjMatrix[u-1][j];
		}
		for(i=0;i<g->vCnt;i++){
			d+=g->adjMatrix[i][u-1];
		}
	}
	return d;
}
//计算一个顶点的出度
int getOutDegree(Graph *g,int u){
	int j,d=0;
	if(g->type==0){
		printf("Type error!\n");
	}else{
		for(j=0;j<g->vCnt;j++){
			d+=g->adjMatrix[u-1][j];
		}
	}
	return d;
}
//计算一个顶点的入度
int getInDegree(Graph *g,int u){
	int i,d=0;
	if(g->type==0){
		printf("Type error\n");
	}else{
		for(i=0;i<g->vCnt;i++){
			d+=g->adjMatrix[i][u-1];
		}
	}
	return d;
}
//深度优先遍历
void dfs(Graph *g,int v,int *visited){
	int i;
	visited[v-1]=1;
	printf("%d ",v);
	for(i=0;i<g->vCnt;i++){
		if(g->adjMatrix[v-1][i]==1 && visited[i]==0){
			dfs(g,i+1,visited);
		}
	}
}
//广度优先遍历
void bfs(Graph *g,int v){
	int t,i;
	int *visited=(int*)malloc(sizeof(int)*g->vCnt);
	SeqQueue queue;
	for(i=0;i<g->vCnt;i++){
		visited[i]=0;
	}
	initQueue(&queue);
	insertQueue(&queue,v-1);
	visited[v-1]=1;
	while(!isEmpty(&queue)){
		t=deleteQueue(&queue);
		printf("%d ",t+1);
		for(i=0;i<g->vCnt;i++){
			if(g->adjMatrix[t][i]==1 && visited[i]==0){
				insertQueue(&queue,i);
				visited[i]=1;
			}
		}
	}

}
#endif