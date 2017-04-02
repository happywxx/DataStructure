#include <stdlib.h>
#include <stdio.h>
/********************求最大等值字符串程*********************/
//等值字符串：如果一个字符串的各个字符均相同，且其长度大于1
//设计算法：输入字符串S,以'!'为结束符，如果S中不存在等值字符串，
//则输出信息“无等值字符串”，否则求出一个长度最大的等值字符串
#define Size 100


void sigleValueString(char S[],int sLen,char *result,int *resultLen){
	char tmp;
	int i,tmpLen=1;
	*result=tmp=S[0];
	*resultLen=1;
	for (i = 1; i < sLen; ++i)
	{
		if(sLen-i+tmpLen<=*resultLen){
			break;
		}else{
			if(S[i]==tmp){
				tmpLen++;
			}else{
				if(tmpLen>*resultLen){
					*result=tmp;
					*resultLen=tmpLen;
				}
				tmp=S[i];
				tmpLen=1;
			}
		}
	}
	if(tmpLen>*resultLen){
		*result=tmp;
		*resultLen=tmpLen;
	}
}

int main(int argc, char const *argv[])
{
	char S[Size],ch;
	int sLen=0;
	char result;
	int resultLen,i;
	printf("请输入字符串，并以!键结尾\n");
	scanf("%c",&ch);
	while(ch!='!'){
		S[sLen++]=ch;
		scanf("%c",&ch);
	}
	sigleValueString(S,sLen,&result,&resultLen);
	if(resultLen>1){
		printf("等值字符串为：");
		for(i=0;i<resultLen;i++){
			printf("%c",result);
		}
		printf("\n");
	}else{
		printf("无等值字符串\n");
	}
	return 0;
}
/**********************KMP算法测试程序**********************/
// #define Size 10
// void partStringLen(char str[],int n[],int len){
// 	int i=1,j=0;//i表示
// 	n[0]=0;
// 	while(i<len){
// 		if(str[i]==str[j]){
// 			n[i]=j+1;
// 			i++;
// 			j++;
// 		}else if(j>0){
// 			j=n[j-1];
// 		}else{
// 			n[i++]=0;
// 		}
// 	}
// }
// int main(int argc, char const *argv[])
// {
// 	char str[Size];
// 	int n[Size],i;
// 	for(i=0;i<Size;i++){
// 		scanf("%c",&str[i]);
// 	}
// 	partStringLen(str,n,Size);
// 	for(i=0;i<Size;i++){
// 		printf("%d\n",n[i]);
// 	}
// 	return 0;
// }