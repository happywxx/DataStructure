#ifndef __PRIM_H__
#define __PRIM_H__ 
#include "Graph.h"
/**************************结构体定义区**************************/
typedef struct 
{
	int begin;
	int end;
	int weight;
}Edge;
/**************************函数定义区****************************/
void Prim(Graph *g,Edge *mst,int v);
/**************************函数实现区****************************/
void Prim(Graph *g,Edge *mst,int v){
	int MaxValue=10000;
	int i,j,k,min,m,t,w;
	Edge temp;
	for(i=0;i<g->vCnt;i++){
		if(i<v){
			mst[i].begin=v;
			mst[i].end=i;
			mst[i].weight=g->adjMatrix[v][i];
		}else if(i>v){
			mst[i-1].begin=v;
			mst[i-1].end=i;
			mst[i-1].weight=g->adjMatrix[v][i];
		}
	}
	for(k=0;k<g->vCnt-1;k++){
		min=MaxValue;
		m=k;
		for(j=k;j<g->vCnt-1;j++){
			if(mst[j].weight<min){
				min=mst[j].weight;
				m=j;
			}
		}
		temp=mst[k];
		mst[k]=mst[m];
		mst[m]=temp;
		j=mst[k].end;
		for(i=k+1;i<g->vCnt-1;i++){
			t=mst[i].end;
			w=g->adjMatrix[j][t];
			if(w<mst[i].weight){
				mst[i].weight=w;
				mst[i].begin=j;
			}
		}
	}
}
#endif