///1. Escreva o código das funções colocanafila, tiradafila, filavazia e filacheia.
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 3

typedef struct{
    int v[MAX];
    int inicio, fim;
}Fila;

Fila* criaFila();
void insere(Fila* q, int x);
int remover(Fila* q);
bool isFull(Fila *q);
bool isEmpty(Fila *q);

/// Criar a Fila

int main (){
    int num;
    Fila* q = criaFila();

    isEmpty(q);
    isFull(q);


    if (!isFull(q)){
        printf("Insira elementos na sua fila: ");
        scanf("%d", &num);
        insere(q,num);
        printf("Insira elementos na sua fila: ");
        scanf("%d", &num);
        insere(q,num);
        printf("Insira elementos na sua fila: ");
        scanf("%d", &num);
        insere(q,num);
    }

    isEmpty(q);
    isFull(q);


    if (!isEmpty(q)){
        printf("Removendo elementos: \n");
        printf("%d", remover(q));
        printf("\n");
        printf("%d", remover(q));
        printf("\n");
        printf("%d", remover(q));
        printf("\n");

    }

    isEmpty(q);
    isFull(q);


}

Fila* criaFila(){
    Fila* q = (Fila* ) /// pq q aqui n tem [;]????????????
        malloc(sizeof(Fila));
        q -> inicio = 0;
        q -> fim = 0;
    return q;
}

/// Inserir Elementos

void insere(Fila *q, int x){
    q-> v[q->fim++] = x;
/**
        if (q-> fim == MAX)
            q-> fim = 0;
*/
}

/// Remover Elementos

int remover(Fila *q){
    int x = q -> v[q->inicio ++];

    /**
        if (q->inicio == MAX)
            q->inicio = 0;
        return x;
    */

}

bool isEmpty(Fila *q){
    if ( (q ->inicio == 0) &&  (q ->fim ==  0) )
        printf("\n\nFila Vazia\n\n");
}
bool isFull(Fila *q){
    if (q ->fim == 3)
        printf("\n\nFila Cheia\n\n");


}

