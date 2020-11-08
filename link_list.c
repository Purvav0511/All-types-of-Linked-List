#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

void rev_list(struct node **head){
	if(*head == NULL) return;
	struct node *t;
	struct node *ptr = *head;
	while(ptr->next != NULL){
		t = ptr->next;
		ptr->next = t->next;
		t->next = *head;
		*head = t;
	}
	//ptr->next = *head;
	//*head = ptr;
}

void print_rev_list(struct node *head){
	struct node *ptr,*prev;
	for(ptr = head;ptr->next!=NULL; ptr = ptr->next);
	printf("%d->",ptr->data);
	while(head!=ptr){
		prev = head;
		while(prev->next!=ptr){
			prev = prev->next;
		}
		ptr = prev;
		printf("%d->",ptr->data);
	}//printf("%d->",ptr->data);
}

void create_list(struct node **head,int size){
	struct node *ptr,*curr;
	for(int i=0;i<size;i++){
		curr = (struct node *)malloc(sizeof(struct node));
		curr->data = i;
		curr->next = NULL;
		if(*head == NULL){
			ptr = *head = curr;
		}else{
			ptr->next = curr;
			ptr = ptr->next;
		}
	}	
}


void display(struct node *head){
	while(head!=NULL){
		printf("%d->",head->data);
		head = head->next;
	}
	printf("\n");
}

void insert(struct node **head, int pos, int val){
	struct node *curr = (struct node *)malloc(sizeof(struct node));
	curr->next = NULL;
	curr->data = val;
	if(*head == NULL){
		*head = curr;
	}else if(pos == 0){
		curr->next = *head;
		*head = curr;
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
		while(i<pos && ptr!=NULL){
			prev = ptr;
			ptr = ptr->next;
			i++;
		} 
		if(ptr == NULL){
			return -1;
		}else if(ptr == *head && ptr->next == NULL){
			*head = NULL;
			*v = ptr->data;
			free(ptr);
		}else if(pos==0){
			*head = ptr->next;
			*v = ptr->data;
			free(ptr);
		}/*else if(ptr->next == NULL){
			prev->next == NULL;
			*v = ptr->data;
			free(ptr);
		}
		else{*/
		else{
			prev->next = ptr->next;
			*v = ptr->data;
			free(ptr);
		}
		//}
	}
}

void main(){
	struct node *head = NULL;
	create_list(&head,5);
	int a;
	display(head);
	insert(&head,0,10);
	display(head);
	insert(&head,2,20);
	display(head);
	insert(&head,100,30);
	display(head);
	insert(&head,4,40);
	display(head);
	delete(&head,5,&a);
	display(head);
	delete(&head,0,&a);
	display(head);
	delete(&head,1,&a);
	display(head);
	//print_rev_list(head);
	rev_list(&head);
	display(head);
	
}
