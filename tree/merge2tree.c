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

struct node* mergeTree(struct node* t1,struct node* t2){
	if(!t1)
		return t2;
	if(!t2)
		return t1;
	t1->data += t2->data;
	t1->left = mergeTree(t1->left,t2->left);
	t1->right = mergeTree(t1->right,t2->right);
	
	return t1;
}

int main(){
	//struct node *root = NULL;
	struct node *t1=NULL,*t2=NULL,*t3 =NULL;
	t1 = createNode(2);
	t1->left = createNode(1);
	t1->right = createNode(4);
	t1->left->left = createNode(5);
	t2 = createNode(3);
	t2->left = createNode(6);
	t2->right = createNode(1);
	t2->left->right = createNode(2);
	t2->right->right = createNode(7);
	

	printf("\nPrinting Node in Inorder\n");
	printInorder(t1);
	printf("\nPrinting Node t2 in Inorder\n");
	printInorder(t2);
	/*printf("\nPrinting Node in Postorder\n");
	printPostorder(root);
	printf("\nPrinting Node in Preorder\n");
	printPreorder(root);
	printf("\n");
	*/
	t3 = mergeTree(t1,t2);
	printf("\nPrinting Node t3 in Inorder\n");
	printInorder(t3);
	

	return 0;
}

