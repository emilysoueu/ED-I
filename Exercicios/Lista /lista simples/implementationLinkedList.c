// implementar funções e operações usando lista ligada

#include <stdlib.h>
#include <stdio.h>

typedef struct _node_{
	int data;
	struct _node_ *prox;	
} Node;

typedef struct _lista{
	Node *cab;
	Node *rabo;
} Lista;

// criar
Lista *criarList(){
	Lista * L = (Lista*)malloc(sizeof(Lista));
	if (L == NULL) return NULL; 
	
	L -> cab = NULL;
	
	return L;	
}

// inserir
int insertList(Lista *L, int elm){
	Node *novo, *p;
	
	if (L != NULL){
		novo = (Node*)malloc(sizeof(Node));
		if (novo!= NULL){
			novo -> data = elm;
			novo -> prox = NULL;
			L -> cab = novo;
			return 1;
		}else{
			return 0;
		}
	}else{
		novo = (Node*)malloc(sizeof(Node));
		if (novo != NULL){
			novo -> data = elm;
			novo -> prox = NULL;
			p = L -> cab;
			while (p-> prox != NULL)
				p = p -> prox;
			p -> prox = novo;
			return 1;
			}else{
				return 0;
			}
		}
		
	}
	
	
int main(){
	Node * head = criarList();
	insertList(head,1);

	showList(head);
}


// mostrar a lista

void showList(Node *L){
	Node *p = L;
	
		while(p != NULL){
			printf("% d ", p -> data);
			p = p -> prox;
		}
		
	}

// buscar

// remover

// destruir lista

