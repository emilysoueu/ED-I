#include <stdlib.h>
#include <stdio.h>

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
    lista* l = (lista*)malloc(sizeof(lista));
    if (l == NULL) return NULL;

    l -> tail = NULL;
    l -> cab = NULL;

    return l;
}

void insert(lista* l, int dado){
    node* novo = (node*) malloc(sizeof(node));
    if (novo == NULL) return;

    novo -> dado = dado;
    node* aux = l -> cab;

    if (l!= NULL){
        if(aux == NULL){ // se não tem ninguem na cabeça da lista
            l -> cab = novo;
            l -> tail = novo;
            l -> cab ->prox = NULL;
        }else{ // caso ja exista alguém na lista
            l -> tail -> prox = novo;
            novo -> prev = l -> tail;
            l -> tail = novo;
        }

    }

}

void printaLista(lista* l){
    node* aux = l -> cab;
    int x;
    while(aux != NULL){
        x = aux -> dado;
        printf("%d ",x);
        aux = aux -> prox;
    }
}

node* buscarNode(lista* l, int x){
    node* aux = l -> cab;

    while(aux != NULL){
        if (aux -> dado == x)
            return aux;
        aux = aux -> prox;
    }

    return NULL;
}

void removerNode(lista* l, int del){
    node* tmp = l -> cab;

    while(tmp != NULL){
        if (tmp == buscarNode(l,del)){
            if(tmp -> prev != NULL){
                if (tmp -> prox != NULL){
                    tmp -> prev -> prox = tmp -> prox;   
                }
        }else{
            l->cab = l->cab->prox;
        }
        free(tmp);
        tmp = tmp -> prox;
    }
}


void uniaoLista(lista* a, lista* b){
    node* aux = b -> cab;

    while(aux != NULL){
        if(buscarNode(b,aux -> dado)!= NULL){
            insert(a, aux -> dado);
        }
        aux = aux -> prox
    }
    return;
}
/*
void interLista(){

}

void difLista(){

}

*/
int main(){
    lista* bonita;
    lista* linda;

    bonita = criar();
    linda = criar();

    

    insert(bonita,1);
    insert(bonita,2)
    printaLista(bonita);

    insert(linda,2);
    insert(linda,3)
    insert(linda,4)
    printaLista(linda);

    printaLista(bonita);
}