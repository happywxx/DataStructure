#ifndef __KRUSKAL_H__
#define __KRUSKAL_H__ 
#include "Graph.h"
/**************************结构体定义区**************************/
typedef struct 
{
	int begin;
	int end;
	int weight;
}Edge;
/**************************函数定义区****************************/
void Kruskal(Graph *g,Edge *mst);
/**************************函数实现区****************************/
void Kruskal(Graph *g,Edge *mst){
	int i,j,eCount,k,NUM=0,edgeNum=0,n1=0,n2=0;
	int **set;
	Edge *edges,tmp;
	eCount=getECount(g);
	edges=(Edge*)malloc(sizeof(Edge)*eCount);
	set=(int**)malloc(sizeof(int*)*g->vCnt);
	for(i=0;i<g->vCnt;i++){
		set[i]=(int*)malloc(sizeof(int)*g->vCnt);
	}
	//插入排序生成按权值升序的边集
	for(i=0;i<g->vCnt;i++){
		for(j=0;j<i;j++){
			if(g->adjMatrix[i][j]<=0){
				continue;
			}
			tmp.begin=i;
			tmp.end=j;
			tmp.weight=g->adjMatrix[i][j];
			for(k=NUM-1;k>=0;k--){
				if(edges[k].weight>tmp.weight){
					edges[k+1]=edges[k];
				}else{
					break;
				}
			}
			edges[k+1]=tmp;
			NUM++;
		}
	}
	//初始化顶点集
	for(i=0;i<g->vCnt;i++){
		for(j=0;j<g->vCnt;j++){
			if(i==j){
				set[i][j]==1;
			}else{
				set[i][j]
			}
		}
	}
	k=0;
	//逐一找到最小生成树的n-1条边
	while(k<g->vCnt-1){
		//找到当前两端点所在的子集
		for(i=0;i<g->vCnt;i++){
			for(j=0;j<g->vCnt;j++){
				if(edges[edgeNum].begin==j && set[i][j]==1){
					n1=i;
				}
				if(edges[edgeNum].end==j && set[i][j]==1){
					n2=i;
				}
			}
		}
		//若两端点在不同子集
		if(n1!=n2){
			//则将当前边加入到最小生成树的边集中
			mst[k]=edges[edgeNum];
			k++;
			// 合并两端点所在的子集
			for(j=0j<g->vCnt;j++){
				set[n1][j]=(set[n1][j]+set[n2][j])%2;
				set[n2][j]=0;
			}
		}
		edgeNum++;
	}
}
#endif