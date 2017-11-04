#include<stdio.h>

	int sum = 0;

int makeChange(int n){
	if(n<0)
		return -1;
	else if(n == 0)
		return sum;
	else if(n-50 >= 0){
		sum++;
		printf("%d\t",50);
		return makeChange(n-50);
	} else if(n-25 >= 0) {
		sum++;
		printf("%d\t",25);
		return makeChange(n-25);
	} else if(n-10 >= 0){
		sum++;
 		printf("%d\t",10);
 		return makeChange(n-10);
	} else if(n-5 >= 0){
		sum++;
 		printf("%d\t",5);
 		return makeChange(n-5);
	} else if (n-1 >= 0){
		sum++;
		printf("%d\t",1);
		return makeChange(n-1);
	}
	return sum;
}

int change_rec(int n, int demo[],int i){
	//printf("\ni=%d\n and demo[i]= %d\n",i,demo[i]);
	if(n == 0 )
		return sum;
	while(n > 0){
		if(n-demo[i] >= 0){
			sum++;
			printf("%d\t",demo[i]);
			return change_rec(n-demo[i],demo,i);	
		} else {
			i++;
		}
	}
	return sum;
}

int change_iter(int n,int demo[]){
	int i=0,sum=0;
	while(n>0){
		if(n-demo[i] >=0 ){
			sum++;
			printf("%d\t",demo[i]);
			n=n-demo[i];
		} else {
			i++;
		}
	}
	return sum;
}

int main(){
	//printf("\nSum of coin%d\n",makeChange(17));
	int demo[] = {50,25,10,5,1};
	//printf("Coin is %d\n",change_rec(167,demo,0));
	printf("\n number of coin is %d\n",change_iter(17,demo));
	return 0;
}
