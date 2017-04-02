#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Graph.h"
// #include "SeqQueue.h"

int main(int argc, char const *argv[])
{
	//有向图数据结构测试区
	// int vCnt=5,i,a,b;
	// Graph *graph=initGraph(vCnt,1);
	// insertEdge(graph,2,1);
	// insertEdge(graph,2,4);
	// insertEdge(graph,3,1);
	// insertEdge(graph,3,4);
	// insertEdge(graph,4,5);
	// insertEdge(graph,4,1);
	// insertEdge(graph,5,2);
	// deleteEdge(graph,2,4);
	// for(i=0;i<vCnt;i++){
	// 	printf("vertex %d:OutDegree: %d,InDegree: %d\n", 
	// 		i+1,getOutDegree(graph,i+1),getInDegree(graph,i+1));
	// }
	// srand(time(NULL));
	// a=rand()%5+1;;
	// srand(rand());
	// b=rand()%5+1;
	// printf("%d and %d %s adjcent",a,b,isAdjcent(graph,a,b)?"is":"is not");
	// return 0;
	//广度优先遍历测试区
	int vCnt=5,i;
	int *visited;
	Graph *graph=initGraph(vCnt,0);
	insertEdge(graph,2,1);
	insertEdge(graph,2,4);
	insertEdge(graph,3,1);
	insertEdge(graph,3,4);
	insertEdge(graph,4,5);
	insertEdge(graph,4,1);
	insertEdge(graph,5,2);
	visited=(int*)malloc(sizeof(int)*graph->vCnt);
	for(i=0;i<graph->vCnt;i++){
		visited[i]=0;
	}
	dfs(graph,2,visited);
	printf("\n");
	bfs(graph,2);
	return 0;
}
