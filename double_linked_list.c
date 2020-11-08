#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
	struct node *prev;
};

void create(struct node **head,int n){
	struct node *ptr;
	for(int i=0;i<n;i++){
		struct node *curr = (struct node *)malloc(sizeof(struct node));
		curr->next = NULL;
		curr->prev = NULL;
		curr->data = random()%10;
		if(*head == NULL){
			ptr = *head = curr;
		}else{
			ptr->next = curr;
			curr->prev = ptr;
			ptr = ptr->next;
		}
	}
}

void insert(struct node **head, int pos, int val){
	struct node *curr = (struct node *)malloc(sizeof(struct node));
	curr->next = NULL;
	curr->prev = NULL;
	curr->data = val;
	if(*head == NULL){
		*head = curr;
	}else if(pos == 0){
		curr->next = *head;
		(*head)->prev = curr;
		*head = curr;
	}else{
		struct node *ptr = *head;
		int i=1;
		while(i<pos && ptr->next!=NULL){
			ptr = ptr->next;
			i++;
		}
		if(ptr->next == NULL){
			ptr->next = curr;
			curr->prev = ptr;
		}else{
			curr->next = ptr->next;
			curr->prev = ptr;
			curr->next->prev = curr;
			ptr->next = curr;
		}
	}
}

int delete(struct node **head, int pos, int *val){
	if(*head == NULL)
		return -1;
	else{
			struct node *ptr = *head;
			int i=0;
			while(i<pos && ptr!=NULL){
				ptr = ptr->next;
				i++;
			}
			if(ptr == NULL)
				return -1;
			else if(ptr==*head && ptr->next == NULL){
				ptr->prev->next = NULL;
				*val = ptr->data;
				free(ptr); 
			}else if(pos == 0){
				*head = ptr->next;
				ptr->next->prev = *head;
				*val = ptr->data;
				free(ptr);
				return 0;
			}else if(ptr->next == NULL){
				ptr->prev->next = ptr->next;
				*val = ptr->data;
				free(ptr);
				return 0;
			}else{
				ptr->prev->next = ptr->next;
				ptr->next->prev = ptr->prev;
				*val = ptr->data;
				free(ptr);
				return 0;
			}
		}
}

void display(struct node *head){
	while(head!=NULL){
		printf("%d->",head->data);
		head = head->next;
	}printf("\n");
}

int main(){
	struct node *head = NULL;
	int v;
	create(&head,4);
	display(head);
	insert(&head,3,90);
	display(head);
	delete(&head,4,&v);
	display(head);
	return 0;
}

























