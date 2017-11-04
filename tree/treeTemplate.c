#include<stdio.h>
#include<stdlib.h>

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


int main(){
	struct node* root = NULL;
	root = createNode(2);
	root->left = createNode(7);
	root->right = createNode(5);
	root->left->right = createNode(6);
	root->left->right->left = createNode(1);
	root->left->right->right = createNode(11);
	root->right->right = createNode(9);
	root->right->right->left = createNode(4);
	

	printf("\nPrinting Node in Inorder\n");
	printInorder(root);
	printf("\nPrinting Node in Postorder\n");
	printPostorder(root);
	printf("\nPrinting Node in Preorder\n");
	printPreorder(root);
	printf("\n");



	return 0;
}

