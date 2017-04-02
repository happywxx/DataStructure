#ifndef __FLOYD_H__
#define __FLOYD_H__
#include "Graph.h"
/**************************结构体定义区**************************/
/**************************函数定义区****************************/
void Floyd(Graph *g);
/**************************函数实现区****************************/
void Floyd(Graph *g){
	int **dist,***path,**plen;
	int v,w,i,s,t,m,n;
	dist=(int**)malloc(sizeof(int*)*g->vCnt);
	path=(int***)malloc(sizeof(int**)*g->vCnt);
	plen=(int*8)malloc(sizeof(int*)*g->vCnt);
	//数组初始化
	for(v=0;v<g->vCnt;v++){
		dist[v]=(int*)malloc(sizeof(int)*g->vCnt);
		path[v]=(int**)malloc(sizeof(int*)*g->vCnt);
		plen[v]=(int*)malloc(sizeof(int)*g->vCnt);
		for(w=0;w<g->vCnt;w++){
			path[v][w]=(int*)malloc(sizeof(int)*g->vCnt);
			if(v==w){
				dist[v][w]=0;
				plen[v][w]=0;
			}else{
				dist[v][w]=g->adjMatrix[v][w];
				path[v][w][0]=v;
				path[v][w][1]=w;
				plen[v][w]=2;
			}
		}
	}
	//求取弗洛伊德矩阵
	for(i=0;i<g->vCnt;i++){
		for(s=0;s<g->vCnt;s++){
			for(t=0;t<g->vCnt;t++){
				if(dist[s][t]>dist[s][i]+dist[i][t]){
					dist[s][t]=dist[s][i]+dist[i][t];
					for(m=0;m<plen[s][i];m++){
						path[s][t][m]=path[s][i][m];
					}
					for(n=1;n<plen[i][t];n++,m++){
						path[s][t][m]=path[i][t][n];
					}
					plen[s][t]=plen[s][i]+plen[i][t]-1;
				}
			}
		}
		prinf("distance matrix after the %dth turn\n",i);
		for(s=0;s<g->vCnt;s++){
			for(t=0;t<g->vCnt;t++){
				printf("%d ",dist[s][t]);
			}
			printf("\n");
		}
	}
}

#endif