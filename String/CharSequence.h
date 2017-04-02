#ifndef __CHARSEQUENCE_H__
#define __CHARSEQUENCE_H__ 
// #include <stdio.h>
// #include <stdlib.h>

/********************结构体定义区*******************/

#define MaxSize 200
typedef struct 
{
	char str[MaxSize];
	int len;
}CharSequence;

/********************函数定义区*********************/

//初始化字符串
void initCharSequence(CharSequence *pStr);
//判断两个字符串是否相等
int equals(CharSequence *pStr1,CharSequence *pStr2);
//求字符串长度
int getLength(CharSequence *pStr);
//连接两个字符串,将pStr2连接到pStr1
CharSequence* concat(CharSequence *pStr1,CharSequence *pStr2);
//求子串，以取从指定位置开始到指定位置结束的子串为例
CharSequence* subString(CharSequence *pSub,CharSequence *pMain,int start,int end);
//子串定位：给定两个字符串，即字符串D和字符串M，求字符串M在字符串D中的位置
//其中字符串D称为目标串，字符串M称为模式串，因此子串定位又称为字符串的模式匹配
//穷举法又称蛮力算法，
int bruteMatch(CharSequence *pDst,CharSequence *pMode);
//KMP算法
//求解已匹配子串的部分匹配串的长度，pMode为已匹配子串，n为所有部分匹配串的长度
void partStringLen(CharSequence *pMode,int n[]);
//KMP定位
int kmpMatch(CharSequence *pDst,CharSequence *pMode);
//字符串替换
CharSequence* replace(CharSequence *s,CharSequence *t,CharSequence *r);
/********************函数实现区*********************/

void initCharSequence(CharSequence *pStr){
	char ch;
	pStr->len=0;
	printf("请输入字符串，以换行符结束\n");
	scanf("%c",&ch);
	while(ch!='\n'){
		pStr->str[pStr->len++]=ch;
		scanf("%c",&ch);
	}
}
int equals(CharSequence *pStr1,CharSequence *pStr2){
	int i=0;
	if(pStr1->len==pStr2->len){
		for(i=0;i<pStr1->len;i++){
			if(pStr1->str[i]!=pStr2->str[i]){
				return 0;
			}
		}
		return 1;
	}
	return 0;
}
int getLength(CharSequence *pStr){
	return pStr->len;
}
CharSequence* concat(CharSequence *pStr1,CharSequence *pStr2){
	int i=0;
	for(i=0;i<pStr2->len;i++){
		pStr1->str[pStr1->len]=pStr2->str[i];
		pStr1->len++;
	}
	return pStr1;
}
CharSequence* subString(CharSequence *pSub,CharSequence *pMain,int start,int end){
	int i=0;
	pSub->len=0;
	if(start<0){
		start=0;
	}
	if(end>pMain->len){
		end=pMain->len;
	}
	for(i=start;i<end;i++){
		pSub->str[pSub->len]=pMain->str[i];
		pSub->len++;
	}
	return pSub;
}
int bruteMatch(CharSequence *pDst,CharSequence *pMode){
	int i,j;
	int n=pDst->len;
	int m=pMode->len;
	for(i=0;i<n-m;i++){
		j=0;
		while(j<m && (pDst->str[i+j]==pMode->str[j])){
			j++;
		}
		if(j>=m){
			return i;
		}
	}
	return -1;
}
//KMP算法的精髓，求取模式字符串所有前缀的部分匹配串
void partStringLen(CharSequence *pMode,int n[]){
	int i=1,j=0;
	int m=pMode->len;
	n[0]=0;
	while(i<m){
		if(pMode->str[i]==pMode->str[j]){
			n[i]=j+1;
			i++;
			j++;
		}else if(j>0){
			j=n[j-1];
		}else{
			n[i++]=0;
		}
	}
}
//KMP算法的易惑点
//为什么在判断语句if(j>0)时，j=next[j-1]，与上个函数partStringLen
//原理一致，若先令k=next[j-1],则此时
//{str[0],str[1],...,str[k-1],...,str[j-k],...,str[j-2],str[j-1]}的部分匹配串
//为{str[0],str[1],...,str[k-1]}={str[j-k],...,str[j-2],str[j-1]}，考虑到
//pDst->{str[i-k],...,str[i-2],str[i-1]}=pMode->{str[j-k],...,str[j-2],str[j-1]}
//即pDst->{str[i-k],...,str[i-2],str[i-1]}=pMode->{str[0],str[1],...,str[k-1]}
int kmpMatch(CharSequence *pDst,CharSequence *pMode){
	int n=pDst->len;
	int m=pMode->len;
	int i=0,j=0,next[MaxSize];
	partStringLen(pMode,next);
	while(i<n){
		if(pDst->str[i]==pMode->str[j]){
			if(j==m-1){
				return i-j;
			}
			i++;
			j++;
		}else{
			if(j>0){
				j=next[j-1];
			}else{
				i++;
			}
		}
	}
	return -1;
}

//子串替换，通过运用KMP算法定位到将被替换的子串，然后进行替换
CharSequence* replace(CharSequence *s,CharSequence *t,CharSequence *r){
	CharSequence tmp;
	int begin,i;
	while((begin=kmpMatch(s,t))>=0){
		tmp.len=s->len-t->len-begin;
		//将s中子串t后面的字符复制到临时字符串tmp中
		for(i=0;i<tmp.len;i++){
			tmp.str[i]=s->str[t->len+begin+i];
		}
		//将r中字符拷贝到s中
		for(i=0;i<r->len;i++){
			s->str[begin+i]=r->str[i];
		}
		//将tmp中的变量复制回s中
		for(i=0;i<tmp.len;i++){
			s->str[begin+r->len+i]=tmp.str[i];
		}
		s->len=s->len-t->len+r->len;
	}
	return s;
}
#endif