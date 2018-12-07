#include <stdio.h>
#include <stdlib.h>

/*
void inverterListaCerto(lista* l) {
	node* head = l -> cab; // guarda a cabeça
	node* tail = l -> tail; // guarda o fim 
	node* aux; 

	while(tail != NULL){
		aux = tail -> prox;
		tail ->prox = tail -> prev;
		tail -> prev = aux;
		tail = tail -> prox;
	}

    aux = l -> tail;
    l -> tail = l -> cab;
    l -> cab = aux;
	
}
*/
typedef struct _node_{
    int dado;
    struct _node_ *prox;
    struct _node_ *prev;
} node;

typedef struct _lista_{
    node *cab;
    node *tail;
} lista;

lista* criar(){
    lista *l = (lista*)malloc(sizeof(lista)); 
    if (l != NULL){
        l -> cab = NULL;
        l -> tail = NULL;
    } 
    return l; 	
}

void insert(lista *l, int dado) {
    node* aux = l -> cab;// nó auxiliar pra guardar a cabeça e não perder a lista;
    node* novo = (node*)malloc(sizeof(node));
    if (novo!= NULL) {
        novo -> dado = dado;
    }
    if (l != NULL) {
      if (l -> cab == NULL) {
       
        l->cab = novo;
        l->tail = novo;
        l->cab -> prox = NULL;
        l->tail -> prox = NULL;
      } else {
         
        l -> tail -> prox = novo;
        novo->prev = l->tail;
        l->tail = novo;
      }
    }
}

void printaLista(lista *l){
    node* tmp = l -> cab;
    int x;
    while(tmp != NULL){
        x = tmp -> dado;
        printf("%d ",x);
        tmp = tmp -> prox;
    }
}

node* busca(lista* l1, int x){
    node* aux = l1 -> cab;

    while(aux != NULL){
      if (aux -> dado == x)
        return aux;
    }

    return NULL;
}


void uniao(lista* l1, lista*l2){
    node* aux = l2 -> cab;

    while(aux!= NULL){
        if (busca(l1, aux ->dado) != NULL)
            insert(l1,aux ->dado);
        aux = aux-> prox;           

    }

}

int main(){
    lista* l1;
    lista* l2;

    l1=criar();
    l2=criar();

    for(int i=0; i<=3;i++){
        insert(l1,i);
    }

    for(int i=2; i<5; i++){
        insert(l2,i);
    }

    printf("Lista 1\n");
    printaLista(l1);
    printf("\nLista 2\n");
    printaLista(l2);

    uniao(l1,l2);
    printf("\nLista 1\n");
    printaLista(l1);

}






/*

int main() {
    lista * newList = criar();

    for(int i = 0; i < 5; i++) {
        insert(newList, i);
    }
    printaLista(newList);
    printf("\n");
    inverterListaCerto(newList);
    printaLista(newList);
}
*/