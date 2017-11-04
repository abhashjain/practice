#include<stdio.h>
void show_mem_rep(char *start,int n){
	int i=0;
	for(i=0;i<n;i++)
		printf(" %.2x",start[i]);
	printf("\n");
}
int main(){
	int i=2;
	printf("%s",(char *)&i);
	show_mem_rep((char *)&i,sizeof(i));
	return 0;
}
