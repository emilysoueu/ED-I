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


lista* criar(){
    lista *l = (lista*)malloc(sizeof(lista)); 
    if (l != NULL){
        l -> cab = NULL;
        l -> tail = NULL;
    } 
    return l; 	
}

void *insert(lista *l, int dado){
    node* aux = l -> cab;// nó auxiliar pra guardar a cabeça e não perder a lista;

    node* novo = (node*)malloc(sizeof(node));
    if (novo!= NULL){
        novo -> dado = dado;
    }

    if (l != NULL){
      if (l -> cab == NULL){
       
        l -> cab = novo;
        l -> tail = novo;
        l -> cab -> prox = NULL;
        l -> tail -> prox = NULL;
      }else{
         
        l -> tail -> prox  = novo;
        novo -> prev = l -> tail;
        l -> tail = novo;
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

void trocaOrdem(lista* l1){
	node* beg = l1 -> cab;
	node* end = l1 ->  tail;
	node* temp;
	
	
	temp = beg;
	beg = end;
	end = temp;
	
	int x;
	
	while(beg!= NULL){
		x = beg -> dado;
		printf("%d ", x);
		beg = beg -> prev;
	}
		
}
int somaInt(lista *l){
	node *copia = l -> cab;
	int soma = 0;

	while(copia != NULL){
		soma += copia -> dado;
		copia = copia -> prox;
	}

	return soma;
}

int main(){
    lista *lista;
    lista = NULL;
    lista = criar();
    insert(lista, 1);
    insert(lista, 2);
    insert(lista, 4);
   
    printaLista(lista);
    
    printf("\n");
    trocaOrdem(lista);

    int soma = somaInt(lista);
    
    printf("soma = %d", soma);
}



