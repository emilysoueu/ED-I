#include <stdlib.h>
#include <stdio.h>

typedef struct _node_{ // caixinha
	int dado;
	struct _node_ *prev;
	struct _node_ *prox;
} Node;

typedef struct _lista_{ // lista
	Node* cab;
	Node* fim;
} Lista;

Lista *criar(){
	Lista* l = (Lista*)malloc(sizeof(Lista));
	if (l == NULL) return NULL;
	
	l -> cab = NULL;
	l -> fim = NULL;
	
	return l;	
}


void addEnd(Lista *l, int valor){
   Node *novo = (Node*)malloc(sizeof(Node));
   if (novo == NULL) printf ("erro de memoria\n");

   novo -> dado = valor;	

   if (l!= NULL){
      if (l -> cab == NULL){ // lista vazia			
         l -> cab = novo;
         l -> fim = novo;
         l -> cab -> prev = NULL;
         l -> cab -> prox = NULL;
      }else{ // caso a lista não seja vazia,ou tem alguém lá

         l -> fim ->prox = novo;
         novo -> prev = l -> fim;
         l -> fim = novo;		

      }
   }
}

void printaLista(Lista *l){
   int x;
   Node *aux = l->cab;
   while(aux != NULL){
      x = aux->dado;
      printf("%d ", x);
      aux = aux->prox;
   }
}

int main(){
   Lista *head;
   head= NULL;

   head = criar();

   int i;
   for (i =1; i< 6; i++){
      addEnd(head,i);
      printf("Added number %d\n", i);
   }
   printf("%d\n", head->cab->dado);
   printf("%d\n", head->cab->prox->dado);

   printaLista(head);
}
