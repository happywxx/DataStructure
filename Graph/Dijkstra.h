#ifndef __DIJKSTRA_H__
#define __DIJKSTRA_H__
#include "Graph.h"
/**************************结构体定义区**************************/
/**************************函数定义区****************************/
void Dijkstra(Graph *g,int v);
/**************************函数实现区****************************/
void Dijkstra(Graph *g,int v){
	int maxValue=10000;
	int *dst,*s,**path,*plen;
	int i,j,w,m,p;
	//path用来记录从点v到各点的最短路径
	path=(int**)malloc(sizeof(int*)*g->vCnt);
	for(i=0;i<g->vCnt;i++){
		path[i]=(int*)malloc(sizeof(int)*g->vCnt);
	}
	//s[i]=1表示第i个顶点已经求出最短路径
	s=(int*)malloc(sizeof(int)*g->vCnt);
	//dist[i]表示v到第i个顶点的距离
	dist=(int*)malloc(sizeof(int)*g->vCnt);
	//plen[i]表示从v到第i个顶点的顶点数
	plen=(int*)malloc(sizeof(int)*g->vCnt);
	//初始化s,plen,dist和path
	for(i=0;i<g->vCnt;i++){
		if(i==v){
			s[i]=1;
		}else{
			s[i]=0;
		}
		plen[i]=0;
		dist[i]=g->adjMatrix[v][i];
		if(dist[i]<maxValue && i!=v){
			path[i][0]=v;
			path[i][1]=i;
			plen[i]=2;
		}
	}
	//求出最短路径及相关数组
	for(i=1;i<g->vCnt-1;i++){
		m=v;
		w=maxValue;
		for(j=0;j<g->vCnt;j++){
			if(s[j]==0 && dist[j]<w){
				w=dist[j];
				m=j;
			}
		}
		if(m!=v){
			s[m]=1;
		}else{
			break;
		}
		//更新dist,plen,path
		for(j=0;j<g->vCnt;j++){
			if(s[j]==0 && dist[m]+g->adjMatrix[m][j]){
				dist[j]=dist[m]+g->adjMatrix[m][j];
				for(p=0;p<plen[m];p++){
					path[j][p]=path[m][p];
				}
				path[j][p]=j;
				plen[j]=plen[m]+1;
			}
		}
	}
	for(i=0;i<g->vCnt;i++){
		for(j=0;j<plen[i];j++){
			printf("%d ",path[i][j]);
		}
		printf("\n");
	}
}
#endif