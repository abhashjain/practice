#include<stdio.h>

#define NA -1

void moveElement(int *a,int n){
	int i=0,j=n-1;
	for(int i=n-1;i>=0;i--){
		if(a[i]!=NA){
			a[j] = a[i];
			j--;
		}
	}
}

void merge(int *a,int *b,int n,int m){
	int i=m;
	int j=0;
	int k=0;
	while(i<n && j<m){
		if(a[i] < b[j]){
			a[k++]=a[i];
			i++;
		} else if (a[i] > b[j]){
			a[k++] = b[j];
			j++;
		}
	}
	while(i<n){
		a[k++]=a[i++];
	}
	while(j<m){
		a[k++] = b[j++];
	}
}

int main(){
	int a[]={2,NA,7,NA,NA,10,NA};
	int b[]={5,8,12,14};
	int n= sizeof(a)/sizeof(int);
	int m = sizeof(b)/sizeof(int);

	moveElement(a,n);
	merge(a,b,n,m);
	//print
	for(int i=0;i<n;i++)
		printf("%d\t",a[i]);
	printf("\n");
	return 0;
}
