#include<stdio.h>
#include<string.h>
int Count(char a,char b){
	char temp[10][8]={
		"1110111",//0
		"0110000",//1
		"1101101",//2
		"1111001",//3
		"0110011",//4
		"1011011",//5
		"1011111",//6
		"1110000",//7
		"1111111",//8
		"1111011"//9 
	};
	int count=0;
	for(int i=0;i<7;i++){
		if(temp[a-'0'][i]!=temp[b-'0'][i]){
			count++;
		}
	}
	return count;
}
int main(){
	char m[100001],n[100001];
	scanf("%s",m);
	scanf("%s",n);
	int number;
	int len=strlen(m);//计算字符串长度，m和n长度相同
	for(int i=0;i<len;i++){
		number+=Count(m[i],n[i]);
	} 
	printf("%d",number);
	return 0;
	
	 
	
	
	 
} 
