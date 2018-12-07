

#include <stdio.h>
#include <stdlib.h>

typedef struct _node_{
	int dado;
	struct _node_ *prox;
	struct _node_ *prev;
}node;

typedef struct _lista_{
	node* cab;
	node* tail;
}lista;

int cmp(int a, int b){
    if (a == b)
    return 1;
 return 0;
}

lista* criar(){
    lista *l = (lista*)malloc(sizeof(lista)); 
    if (l != NULL){
        l -> cab = NULL;
        l -> tail = NULL;
    } 
    return l; 	
}
void *insert(lista *l, int dado){ // inserção lista circular duplamente encadeada
    node* aux = l -> cab;// nó auxiliar pra guardar a cabeça e não perder a lista;

    node* novo = (node*)malloc(sizeof(node));
    if (novo!= NULL){
        novo -> dado = dado;
    }

    if (l != NULL){
      if (l -> cab == NULL){
       
        l -> cab = novo;
        l -> tail = novo;
        l -> cab -> prox = l -> tail;
        l -> cab -> prev = l -> tail;
        l -> tail -> prox = l-> cab;
        l -> tail -> prev = l-> cab;
      }else{

        l -> tail -> prox  = novo;
        novo -> prev = l -> tail;
        novo -> prox = l -> cab;
        l -> tail = novo;      
        l -> cab -> prev = novo;
       
      }
    }

}



void printaLista(lista *l){
    node* beg = l -> cab;
    int x;

    while(beg != l -> cab){
        x = beg -> dado;
        printf("%d ",x);
        beg = beg -> prox;
    }
}

int main(){
    lista* umaFila;
    umaFila = criar();
    int i,a,b;

    
        insert(umaFila,1);
        printaLista(umaFila);
        insert(umaFila,2);
        printaLista(umaFila);
        insert(umaFila,3);
        printaLista(umaFila);

    



    
    //printaLista(umaFila);
}

void PuneElemento(lista* l1){
    node* tmp;
    if(l1 == NULL) return;

    if (l1 -> cab!= NULL) 
        tmp = l1 -> cab;

    tmp -> prox -> prev = NULL;
    l1 -> cab = tmp -> prox;
    tmp ->prox = NULL;
    tmp ->prev = l1 ->tail;
    l1 ->tail ->prox = tmp;
}
