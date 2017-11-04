#include<iostream>
using namespace std;

#define ALPHA 26

struct TrieNode{
	struct TrieNode *children[ALPHA];
	bool isEnd;
};

struct TrieNode *getNode(){
	struct TrieNode *pNode = new TrieNode;
	pNode->isEnd =false;
	for(int i=0;i<ALPHA;i++)
		pNode->children[i] = NULL;
	return pNode;
}

void insert (struct TrieNode *root,string key){
	struct TrieNode *crawl = root;
	for(int i=0;i<key.length();i++){
		int index = key[i]-'a';
		if(!crawl->children[index]){
			crawl->children[index] = getNode();
		}
		crawl = crawl->children[index];
	}
	crawl->isEnd = true;
}

bool search(struct TrieNode *root, string key){
	struct TrieNode *crawl = root;
	for (int i =0 ;i<key.length();i++){
		int index = key[i]-'a';
		if (!crawl->children[index])
			return false;
		crawl = crawl->children[index];
	}
	return (crawl!=NULL && crawl->isEnd);
}
int main(){
	struct TrieNode *root=getNode();
	string dict[] = {"abhash","jain","kaman","akash","jain"};
	int n = sizeof(dict)/sizeof(dict[0]);
	string s ="abhash jain kaman bharatpur";
	cout<<sizeof(s);
	cout<<"\nArray size " << sizeof(dict) <<"\nfirst element "<<sizeof(dict[0])<<endl;
	for(int i=0;i<n;i++){
		insert(root,dict[i]);
		
	}
	search(root,"abhash") ? cout<<"Found\n":cout<<"Not Found\n";
	search(root,"abha") ? cout<<"Found\n":cout<<"Not Found\n";
	search(root,"jain") ?cout<<"Found\n":cout<<"Not Found\n";
	return 0;
}
