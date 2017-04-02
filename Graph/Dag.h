#ifndef __DAG_H__
#define __DAG_H__ 
#include "Graph.h"
//Dag 即为directed acyclic graph,有向无环图
//图使用图的邻接矩阵的存储结构
/**************************结构体定义区**************************/
/**************************函数定义区****************************/
//拓扑排序
void topSort(Graph *g,int *sort);
//关键路径
void keyPath(Graph *g);
int maxValue=0;
/**************************函数实现区****************************/
//拓扑排序
void topSort(Graph *g,int *sort){
	int *isSorted,*inDegree,i,j,sorted=0;
	isSorted=(int*)malloc(sizeof(int)*g->vCnt);
	inDegree=(int*)malloc(sizeof(int)*g->vCnt);
	for(i=0;i<g->vCnt;i++){
		isSorted[i]=0;
	}
	for(i=0;i<g->vCnt;i++){
		inDegree[i]=0;
		for(j=0;j<g->vCnt;j++){
			inDegree[i]+=g->adjMatrix[j][i];
		}
	}
	while(sorted<g->vCnt){
		for(i=0;i<g->vCnt;i++){
			if(inDegree[i]==0 && isSorted[i]==0){
				break;
			}
		}
		if(i>=g->vCnt){
			printf("There is a cycle\n");
			break;
		}
		sort[sorted]=i;
		isSorted[i]=1;
		sorted++;
		for(j=0;j<g->vCnt;j++){
			if(g->adjMatrix[i][j]==1){
				inDegree[j]--;
			}
		}
	}
}
//关键路径
void keyPath(Graph *g){
	int i,j,k,eCount;
	int *ve,*vl,*e,*t,*w,*sort;
	ve=(int*)malloc(sizeof(int)*g->vCnt);
	vl=(int*)malloc(sizeof(int)*g->vCnt);
	sort=(int*)malloc(sizeof(int)*g->vCnt);
	eCount=getECount(g);
	e=(int*)malloc(sizeof(int)*eCount);
	t=(int*)malloc(sizeof(int)*eCount);
	w=(int*)malloc(sizeof(int)*eCount);
	topSort(g,sort);
	for(i=0;i<g->vCnt;i++){
		vl[i]=maxValue;
	}
	ve[sort[0]]=0;
	for(i=1;i<g->vCnt;i++){
		k=sort[i];
		for(j=0;j<g->vCnt;j++){
			if(g->adjMatrix[j][k]>0){
				if(ve[j]+g->adjMatrix[j][k]>ve[k]){
					ve[k]=ve[j]+g->adjMatrix[j][k];
				}
			}
		}
	}
	vl[sort[g->vCnt-1]]=ve[sort[g->vCnt-1]];
	for(i=g->vCnt-2;i>=0;i--){
		k=sort[i];
		for(j=0;j=g->vCnt;j++){
			if(g->adjMatrix[k][j]>0){
				if(vl[j]-g->adjMatrix[k][j]<vl[k]){
					vl[k]=vl[j]-g->adjMatrix[k][j];
				}
			}
		}
	}
	k=0;
	printf("关键路径是\n");
	for(i=0;i<g->vCnt;j++){
		for(j=0;j<g->vCnt;j++){
			if(g->adjMatrix[i][j]>0){
				e[k]=ve[i];
				t[k]=vl[j];
				w[k]=g->adjMatrix[i][j];
				if(t[k]-e[k]==w[k]){
					printf("<%d,%d>\n",i,j);
				}
				k++;
			}
		}
	}
	printf("\n");
	free(ve);
	free(vl);
	free(e);
	free(t);
	free(w);
}
#endif