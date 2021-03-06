#include<iostream>
#include<climits>
using namespace std;

int maxSum(int a[],int n){
	int max_ending_here =0;
	int max_so_far=INT_MIN;
	for(int i=0;i<n;i++){
		max_ending_here +=a[i];
		if(max_so_far < max_ending_here)
			max_so_far = max_ending_here;
		if(max_ending_here < 0)
			max_ending_here = 0;
	}
	return max_so_far;
}


int main(){
	int a[] = {-2,-3,4,-1,-2,1,5,-3};
	int n = sizeof(a)/sizeof(a[0]);
	cout<<"Max Sum is \t"<<maxSum(a,n)<<endl;
	return 0;
}
