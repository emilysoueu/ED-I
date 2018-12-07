#include <stdio.h>
#include <stdlib.h>

typedef struct _node_{
	int data;
	struct _node_ *next;
}node;

node *createLinkedList(int n);
void printList(node *head);

int main(){
	int n =0; // quantidade de nós na lista
	node* HEAD = NULL;
	printf("How many nodes: ");
	scanf("%d", &n) ;
	
	HEAD = createLinkedList(n);
	printList(HEAD);
	
}

node *createLinkedList(int n){
	node * head = NULL;
	node * tmp = NULL;
	node * p = NULL;
	
	for (int i=0; i<n; i++){
		
		tmp = (node*)malloc(sizeof(node));
		printf("Enter: \n");
		scanf("%d", &(tmp ->data));
		tmp -> next = NULL;
		
		if (head == NULL){
			head = tmp;
		}else{
			p = head;
			while(p -> next!= NULL)
				p= p->next;
			p -> next = tmp;
						
		}
	}
	
	return head;
}

void printList(node *head){
	node * p = head;
	
	while (p != NULL){
		printf("%d ", p -> data);
		p = p -> next;
	}
}  
  
