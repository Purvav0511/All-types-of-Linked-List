#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

void create_list(struct node **head,int size){
	struct node *ptr,*curr;
	for(int i=0;i<size;i++){
		curr = (struct node *)malloc(sizeof(struct node));
		curr->data = i;
		curr->next = NULL;
		if(*head == NULL){
			ptr = *head = curr;
			curr->next = *head;
		}else{
			ptr->next = curr;
			curr->next = *head;
			ptr = ptr->next;
		}
	}	
}


void display(struct node *head){
	struct node *ptr = head;
	do{
		printf("%d->",ptr->data);
		ptr = ptr->next;
	}while(ptr!=head);
	printf("\n");
}

void insert(struct node **head, int pos, int val){
	struct node *curr = (struct node *)malloc(sizeof(struct node));
	curr->next = NULL;
	curr->data = val;
	if(*head == NULL){
		*head = curr;
		curr->next = *head;
	}else if(pos == 0){
		struct node *ptr;
		for(ptr = *head; ptr->next!=*head;ptr = ptr->next);
		curr->next = *head;
		*head = curr;
		ptr->next = *head;
	}else{
		struct node *ptr = *head;
		int i=1;
		while(i<pos && ptr->next != NULL){
			ptr = ptr->next;
			i++;
		}
			curr->next = ptr->next;
			ptr->next = curr;
		
	}
}

int delete(struct node **head, int pos , int *v){
	if(*head == NULL)
		return -1;
	else{
		struct node *ptr = *head,*prev;
		int i=0;
		while(i<pos){
			prev = ptr;
			ptr = ptr->next;
			i++;
		} 
		if(ptr == *head && ptr->next == *head){
			*head = NULL;
			*v = ptr->data;
			free(ptr);
		}else if(ptr==*head){
			for(prev=(*head)->next;prev->next!=*head;prev = prev->next);
			*head = ptr->next;
			prev->next = *head;
			*v = ptr->data;
			free(ptr);
		}
		else{
			prev->next = ptr->next;
			*v = ptr->data;
			free(ptr);
		}
	}
}

void main(){
	struct node *head = NULL;
	create_list(&head,5);
	int a;
	display(head);
	insert(&head,8,10);
	display(head);
	delete(&head,0,&a);
	display(head);
}
