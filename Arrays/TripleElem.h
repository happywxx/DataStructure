#ifndef __TRIPLEELEM_H
#define __TRIPLEELEM_H 

/********************结构体定义区******************/
#define M 6
#define N 6
#define MaxSize 200
typedef int DataType;
typedef struct
{
	int i,j;
	DataType v;
}TripleElem;
typedef struct 
{
	TripleElem matData[MaxSize];
	int p[M+1],t[M+1];
	int m,n,k;
}Matrix;
//m表示p数组的长度，n表示t数组的长度，包含i=0但不使用
//k表示matData数组的长度，即三元组的长度
/********************函数定义区********************/
//初始化标志
void initMark(Matrix *pMat);
//访问元素A(i,j)
DataType getElem(Matrix *pMat,int i,int j);
//矩阵相加
//1.矩阵法矩阵相加
void addMat1(Matrix *pMat1,Matrix *pMat2,Matrix *pMat3);
//2.三元组法矩阵相加
void addMat(Matrix *pMat1,Matrix *pMat2,Matrix *pMat3);
/********************函数实现区********************/
//初始化标志
void initMark(Matrix *pMat){
	int i,j;
	for(i=1;i<pMat->m;i++){
		pMat->t[i]=0;
	}
	for(j=0;j<pMat->k;j++){
		pMat->t[pMat->matData[j].i]++;
	}
	pMat->p[1]=0;
	for(i=2;i<pMat->m;i++){
		pMat->p[i]=pMat->p[i-1]+pMat->t[i-1];
	}
}
//访问元素A(i,j)
DataType getElem(Matrix *pMat,int i,int j){
	int q;
	for(q=pMat->p[i];q<pMat->p[i]+pMat->t[i];q++){
		if(pMat->matData[q].i==i && pMat->matData[q].j==j){
			return pMat->matData[q].v;
		}
	}
	return 0;
}
//矩阵相加
//1.矩阵法矩阵相加
void addMat1(Matrix *pMat1,Matrix *pMat2,Matrix *pMat3){
	int i,j;
	TripleElem tmp;
	DataType k;
	pMat3->k=0;
	for(i=1;i<=pMat1->m;i++){
		for(j=1;j<=pMat1->n;j++){
			k=getElem(pMat1,i,j)+getElem(pMat2,i,j);
			if(0!=k){
				tmp.i=i;
				tmp.j=j;
				tmp.k=k;
				pMat3->matData[pMat3->k]=tmp;
				pMat3->k++;
			}
		}
	}
}
//2.三元组法矩阵相加
void addMat(Matrix *pMat1,Matrix *pMat2,Matrix *pMat3){
	int p=0,q=0;
	TripleElem tmp;
	pMat3->k=0;
	while((p<pMat1->k) && (q<pMat2->k)){
		if((pMat1->matData[p].i<pMat2->matData[q].i) || 
			( (pMat1->matData[p].i==pMat2->matData[q].i) &&
				(pMat1->matData[p].j<pMat2->matData[q].j) ) )
		{
			tmp.i=pMat1->matData[p].i;
			tmp.j=pMat1->matData[p].j;
			tmp.v=pMat1->matData[p].v;
			pMat3->matData[pMat3->k]=tmp;
			pMat3->k++;
			p++;
		}
		else if( (pMat1->matData[p].i>pMat2->matData[q].i) ||
			( (pMat1->matData[p].i==pMat2->matData[q].i) &&
				(pMat1->matData[p]).j>pMat2.matData[q].j ) )
		{
			tmp.i=pMat2->matData[q].i;
			tmp.j=pMat2->matData[q].j;
			tmp.v=pMat2->matData[q].v;
			pMat3->matData[pMat3->k]=tmp;
			pMat3->k++;
			q++;
		}
		else if( (pMat1->matData[p].i==pMat2->matData[q].i) &&
				(pMat1->matData[p]).j>pMat2.matData[q].j) )
		{
			tmp.i=pMat1->matData[p].i;
			tmp.j=pMat1->matData[p].j;
			tmp.v=pMat1->matData[p].v+pMat2->matData[q].v;
			if(0!=tmp.v){
				pMat3->matData[pMat3->k]=tmp;
				pMat3->k++;
			}
		}
		p++;
		q++;
	}
	while(p<pMat1->k){
		tmp.i=pMat1->matData[p].i;
		tmp.j=pMat1->matData[p].j;
		tmp.v=pMat1->matData[p].v;
		pMat3->matData[pMat3->k]=tmp;
		pMat3->k++;
		p++;
	}
	while(q<pMat2->k){
		tmp.i=pMat2->matData[q].i;
		tmp.j=pMat2->matData[q].j;
		tmp.v=pMat2->matData[q].v;
		pMat3->matData[pMat3->k]=tmp;
		pMat3->k++;
		q++;
	}
}
#endif