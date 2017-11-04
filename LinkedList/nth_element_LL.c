#include<stdio.h>
#include<stdlib.h>
struct list{
int data;
struct list* next;
};
int addElement_Front(struct list** head,int n){
	struct list* newnode =(struct list*) malloc(sizeof(struct list));
	newnode->data = n;
	newnode->next = *head;
	*head = newnode;
}
int getNth_Node(struct list **head,int index){
	int i=0;
	struct list* current = *head;
	while(current->next !=NULL){
		if(i==index){
			return current->data;
		}
		i++;
		current = current->next;
	}
}
void printlist (struct list **head){
	struct list *current = *head;
	while(current->next !=NULL){
		printf("%d \t",current->data);
		current= current->next;
	} 
	printf("\n");
}
int main(){
	struct list* head =NULL;
	addElement_Front(&head,2);
	addElement_Front(&head,3);
        addElement_Front(&head,4);
        addElement_Front(&head,5);
        addElement_Front(&head,6);
        addElement_Front(&head,7);
	printlist(&head);
	printf("%d\n",getNth_Node(&head,5));
	return 0;
}
