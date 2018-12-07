#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

Lista* criaLista (){

  Lista* l = (Lista*) malloc(sizeof(Lista));

  if (l != NULL){
    l -> head = NULL;
    l -> tail = NULL;
  }

  return l;
}

int insercao (Lista* a, int dado){ //Função que insere no tail da lista um novo valor

  if (a == NULL) return 0;

  Node* n = (Node*) malloc(sizeof(Node));

  if (n == NULL) return 0;

  n -> dado = dado;

  if ( a -> head == NULL){
    a -> head = n;
    a -> tail = n;
    a -> head -> next = NULL;
    a -> head -> prev = NULL;
    return 1;
  }

  a -> tail -> next = n;
  n -> prev = a -> tail;
  a -> tail = n;

  return 1;
}

int remocao (Lista* a, int dado){ //Remove valor dado pelo usuário da lista

  if (a == NULL || a -> head == NULL) return 0;

  Node* aux = a -> head;

  while (aux != NULL){
    if (aux -> dado == dado){
      aux -> prev -> next = aux -> next;
      if (aux -> next != NULL){
        aux -> next -> prev = aux -> prev;
      }
      free(aux);
      return 1;
    }
    aux = aux -> next;
  }
  return 1;
}

 Node* busca (Lista* a, int dado){ //Busca um valor na lista e retorna 1 se achar e 0 se nao achar
  if (a == NULL || a -> head == NULL) return 0;

  Node* aux = a -> head;

  while (aux != NULL){
    if (aux -> dado == dado){
      return aux;
    }
    aux = aux -> next;
  }

  return NULL;
}

void printaLista (Lista* a){ //Função que printa o conjunto
  if (a == NULL || (a -> head == NULL)) return;

  Node* aux = a -> head;

  while (aux != NULL){
    printf("%i ", aux -> dado);
    aux = aux -> next;
  }

  printf("\n\n\n");

  return;
}

void uniao(Lista *a, Lista *b){
int x;
Node *aux = b->head; 
  if (a != NULL && b !=NULL ){
    
    while (aux != NULL){
      x = aux->dado;
      if (!(busca(a,x)))
        insercao(a,x);
      aux = aux->next;
    }
  }

}

void interseccao (Lista* a, Lista* b){
  int x;
  Node *aux = a->head; 
  if (a != NULL && b !=NULL ){
    
    while (aux != NULL){
      printf("%d",x);
      x = aux->dado;
      if (!(busca(b,x)))
        remocao(a, x);
      aux = aux->next;
    }
  }
}
/*
int diferenca (Lista* a, Lista* b){

}
*/
int destroiLista(Lista** l){ //Destroi a lista atual

  if (*l == NULL) return 0;

  Node* aux = (*l) -> head;
  Node* p = aux;

  while (aux != NULL){
    p = p -> next;
    free(aux);
    aux = p;
  }
  
  free(*l);
  *l = NULL;
  return 1;
}


