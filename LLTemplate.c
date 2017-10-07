#include<stdio.h>
#include<stdlib.h>

struct node{
int data;
struct node* next;
};

struct node* createNode(int data){
	struct node* newNode = (struct node*) malloc(sizeof(struct node));
	newNode->data = data;
	newNode->next =NULL;
	return newNode;
}

void printList(struct node* head){
	while(head!=NULL){
		printf("%d\t",head->data);
		head = head->next;
	}
}

int main(){
	struct node* head =NULL;
	head = createNode(2);
	head->next = createNode(5);
	head->next->next = createNode(1);
	head->next->next->next = createNode(15);
	head->next->next->next->next = createNode(3);
	
	printList(head);
	printf("\n");
	return 0;
}
