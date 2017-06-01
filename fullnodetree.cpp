#include<stdio.h>
#include<iostream>
#include<stdlib.h>
using namespace std;

struct node{
int data;
struct node *left=NULL,*right=NULL;
};

struct node* createNode(int data){
	struct node* newnode = (struct node*)malloc(sizeof(struct node));
	newnode->data = data;
	return newnode;
}

int countfullnode(struct node* root){
	if(root->left !=NULL && root->right !=NULL)
		return 1+countfullnode(root->left)+countfullnode(root->right);
	if(root->left !=NULL){
		countfullnode(root->left);
	}
	if(root->right !=NULL)
		countfullnode(root->right);
	if(root->left == NULL && root->right == NULL){
		return 0;
	}
	//return 0;
}

void preorder(struct node* root){
	if(root ==NULL)
		return ;
	printf("%d\t",root->data);
	preorder(root->left);
	preorder(root->right);
}
int main(){
	struct node* root =NULL;
	root = createNode(1);
	root->left = createNode(2);
	root->left->left = createNode(4);
	root->right = createNode(3);
	root->left->right = createNode(5);	
	root->right->left = createNode(10);
	root->right->right = createNode(11);
	
	//preorder(root);
	cout<<countfullnode(root)<<endl;
	cout<<endl;
	return 0;
}
