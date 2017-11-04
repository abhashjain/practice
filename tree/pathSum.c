#include<stdio.h>
#include<stdlib.h>
typedef int bool;
#define true 1
#define false 0

struct node {
	int data;
	struct node *left,*right;
};

struct node* createNode(int data){
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	if(temp == NULL){
		printf("Malloc failed!\n");
		return NULL;
	}
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}
/* print Inorder traversal */
void printInorder(struct node* root){
	if(root == NULL){
		return;
	}
	printInorder(root->left);
	printf("%d\t",root->data);
	printInorder(root->right);
}
/* print preorder traversal */
void printPreorder(struct node* root){
	if(root == NULL){
		return;
	}
	printf("%d\t",root->data);
	printPreorder(root->left);
	printPreorder(root->right);
}

/* print postorder traversal */
void printPostorder(struct node* root){
	if(root == NULL){
		return;
	}
	printPostorder(root->left);
	printPostorder(root->right);
	printf("%d\t",root->data);
}

bool pathSum(struct node* root,int key){
	bool ans=0;
	if(root==NULL || key < 0)
		return false;
	if (root->left==NULL && root->right ==NULL && key-root->data == 0)
		return true;
	if(root->left)
		ans = ans || pathSum(root->left,key-root->data);
	if(root->right)
		ans = ans || pathSum(root->right,key-root->data);
	return ans;
}

int main(){
	struct node* root = NULL;
	root = createNode(2);
	/*root->left = createNode(7);
	root->right = createNode(5);
	root->left->right = createNode(6);
	root->left->right->left = createNode(1);
	root->left->right->right = createNode(11);
	root->right->right = createNode(9);
	root->right->right->left = createNode(4);
	*/
/*
	printf("\nPrinting Node in Inorder\n");
	printInorder(root);
	printf("\nPrinting Node in Postorder\n");
	printPostorder(root);
	printf("\nPrinting Node in Preorder\n");
	printPreorder(root);
	printf("\n");
*/
	printf("Checking the sum node %s\n",pathSum(root,2)?"Yes":"NO");

	return 0;
}

