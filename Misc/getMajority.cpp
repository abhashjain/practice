#include<stdio.h>
#include<iostream>
using namespace std;

int findMajorityCandidate(int arr[],int n);
bool isMajority(int arr[],int size,int num);

void printMajority(int arr[],int size){
	int cand = findMajorityCandidate(arr,size);
	if(isMajority(arr,size,cand))
		cout<<cand<<endl;
	else
		cout<<"No Majority\n";
}

bool isMajority(int arr[],int size,int num){
	int count =0;
	for(int i=0;i<size;i++){
		if (arr[i]==num)
			count++;
	}
	if(count >size/2)
		return true;
	return false;
}

int findMajorityCandidate(int arr[],int n){

 int majIndex =0,count =1;
 for(int i=1;i<n;i++){
	if(arr[majIndex]==arr[i]){
		count++;
	} else {
		count--;
	}
	if(count ==0){
		count =1;
		majIndex =i;
	}
 }
	return arr[majIndex];
}



int main(){
	//int a[]={3 ,3 ,4 ,2 ,4 ,4 ,2,4};
	//printMajority(a,8);
	int a[]={3, 3, 4 ,2 ,4 ,4, 2, 4, 4};
	printMajority(a,9);
	return 0;
}
