#ifndef __LINKEDGRAPH_H__
#define __LINKEDGRAPH_H__ 
/**************************结构体定义区**************************/
typedef struct node
{
	int v;
	struct node *next;
}GNode;
typedef struct graph
{
	int vCnt;//顶点数目
	int type;//0代表无向图，1代表有向图
	GNode *list;
}Graph;
/**************************函数定义区****************************/
//初始化图
Graph* initGraph(int vCnt,int type);
//输入图的顶点和边
void inputGraph(Graph *g);
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
int isAdjacent(Graph *g,int u,int v);
//计算一个顶点的度
int getDegree(Graph *g,int u);
//计算一个顶点的出度
int getOutDegree(Graph *g,int u);
//计算一个顶点的入度
int getInDegree(Graph *g,int u);
/**************************函数实现区****************************/
//初始化图
Graph* initGraph(int vCnt,int type){
	Graph *graph=NULL;
	int i;
	graph->vCnt=vCnt;
	graph->type=type;
	graph->list=(GNode*)malloc(sizeof(GNode)*vCnt);
	for(i=0;i<vCnt;i++){
		graph->list[i].next=NULL;
	}
}
//输入图的顶点和边
//输入时按以下格式输入(v,k,v(1),v(2),...,v(k)),其中,v为顶点
//k为顶点v的出边数，v(1),v(2),...,v(k)为顶点v的各出边的终点
void inputGraph(Graph *g){
	int i,v,n,u;
	GNode *t,*p;
	for(i=0;i<g->vCnt;i++){
		scanf("%d",&v);
		g->list[i].v=v;
		p=&g->list[i];
		scanf("%d",&n);
		while(n>0){
			scanf("%d",&u);
			t=(GNode*)malloc(sizeof(GNode));
			t->v=u;
			t->next=NULL;
			p->next=t;
			p=t;
			n--;
		}
	}
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
	int i,eCnt=0;
	GNode *p;
	for(i=0;i<g->vCnt;i++){
		p=&g->list[i];
		p=p->next;
		while(p!=NULL){
			eCnt++;
			p=p->next;
		}
	}
	return (g->type?eCnt;eCnt/2);
}
//插入边
void insertEdge(Graph *g,int u,int v){
	Graph *t,*p;
	int i;
	for(i=0;i<g->vCnt;i++){
		if(g->list[i].v==u){
			t=(GNode*)malloc(sizeof(GNode));
			t->v=v;
			t->next=g->list[i].next;
			g->list[i].next=t;
			break;
		}
	}
	if(g->type==0){
		for(i=0;i<g->vCnt;i++){
		if(g->list[i].v==v){
			t=(GNode*)malloc(sizeof(GNode));
			t->v=u;
			t->next=g->list[i].next;
			g->list[i].next=t;
			break;
		}
	}
	}
}
//删除边
void deleteEdge(Graph *g,int u,int v){
	int i;
	GNode *p,*t;
	for(i=0;i<g->vCnt;i++){
		if(g->list[i]==u){
			p=&g->list[i];
			t=p->next;
			while(t->v!=v){
				p=t;
				t=t->next;
			}
			if(t==NULL){
				printf("no such edge\n");
			}else{
				p->next=t->next;
				free(t);
			}
			break;
		}
	}
	if(g->type==0){
		for(i=0;i<g->vCnt;i++){
			if(g->list[i]==v){
				p=&g->list[i];
				t=p->next;
				while(t->v!=u){
					p=t;
					t=t->next;
				}
				if(t==NULL){
					printf("no such edge\n");
				}else{
					p->next=t->next;
					free(t);
				}
				break;
			}
		}
	}
}
//判断两个顶点是否相邻接
int isAdjacent(Graph *g,int u,int v){
	int i;
	GNode *t;
	for(i=0;i<vCnt;i++){
		if(g->list[i].v==u){
			t=&g->list[i];
			t=t->next;
			while(t!=NULL){
				if(t->v==v){
					return 1;
				}else{
					t=t->next;
				}
			}
			return 0;
		}
	}
	return 0;
}
//计算一个顶点的度
int getDegree(Graph *g,int u){
	int i,d=0;
	GNode *t;
	for(i=0;i<g->vCnt;i++){
		if(g->list[i].v==u){
			t=&g->list[i];
			t=t->next;
			while(t!=NULL){
				d++;
				t=t->next;
			}
			break;
		}
	}
	if(g->type==1){
		for(i=0;i<g->vCnt;i++){
			t=&g->list[i];
			t=t->next;
			while(t!=NULL){
				d++;
				t=t->next;
			}
			break;
		}
	}
	return d;
}
//计算一个顶点的出度
int getOutDegree(Graph *g,int u){
	int i,d=0;
	GNode *t;
	for(i=0;i<g->vCnt;i++){
		t=&g->list[i];
		t=t->next;
		while(t!=NULL){
			d++;
			t=t->next;
		}
	}
}
//计算一个顶点的入度
int getInDegree(Graph *g,int u){
	
}
#endif