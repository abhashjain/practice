#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;

string LCP(string str1,string str2){
	
	int n1= str1.length();
	int n2 = str2.length();
	string result ="";
	for(int i=0,j=0;i<n1&&j<n2;i++,j++){
		if(str1[i]!=str2[j])
			break;
		result.push_back(str1[i]);
	}
	//cout<<result<<endl;
	return result;
}


string longestCommonPrefix(vector<string>& strs) {
	string result = strs[0];
	for(int i=1;i<strs.size();i++){
		result = LCP(result,strs[i]);
	}
	return result;
}

int main(){
	vector<string> strs;
	strs.push_back("");
	strs.push_back("geeksforgeeks");
	strs.push_back("geeks");
	strs.push_back("geek");
	cout<<longestCommonPrefix(strs)<<endl;
	return 0;
}
