#include<iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

struct node{
	int data;
	node *next;
};

struct node* newNode(int data){
	struct node* newnode = (struct node*)malloc(sizeof(struct node));
	newnode->data = data;
	newnode->next =NULL;
	return newnode;
}

void printList(struct node* temp){
	while(temp!=NULL){
		printf("%d\t",temp->data);
		temp=temp->next;
	}
	printf("\n");
}

struct node* addList(struct node* l1 , struct node* l2){
	node *result = NULL;
        node *tmpptr =result;
        int carry =0;
        while(l1 != NULL && l2 !=NULL){
            int temp1 = l1->data+l2->data+carry;
            carry = temp1/10;
            node *temp = newNode(temp1%10);
            if(result == NULL){
                result =temp;
                tmpptr =result;
                l1=l1->next;
                l2 = l2->next;
                continue;
            }
            tmpptr->next = temp;
            tmpptr = tmpptr->next;
            l1=l1->next;
            l2=l2->next;
        }
	while (l1 != NULL && l2 == NULL){
		int temp1 = carry + l1->data;
		carry = temp1/10;
		node *temp = newNode(temp1%10);
	    tmpptr->next = temp;
        tmpptr = tmpptr->next;
        l1=l1->next;
	}
	while (l2 != NULL && l1 == NULL){
        int temp1 = carry + l2->data;
        carry = temp1/10;
        node *temp = newNode(temp1%10);
        tmpptr->next = temp;
        tmpptr = tmpptr->next;
        l2=l2->next;
    }
	if(carry !=0){
		node *temp =newNode(carry);
		tmpptr->next =temp;
		tmpptr =tmpptr->next;
	}
        return result;
}

int main(){
	struct node* l1 = newNode(2);
	l1->next = newNode(9);
	//l1->next->next =newNode(7);
	struct node *l2 =newNode(3);
	l2->next = newNode(2);
	l2->next->next = newNode(9);
	//print the above list
	printList(l1);
	printList(l2);
	
	//add two list	
	struct node* result = addList(l1,l2);
	printList(result);
	return 0;
}
