#include <stdio.h>
#include <stdlib.h>

#define max 5

typedef struct queue{
    char nomes[max][1000];
    int inicio, fim;
}Fila;

Fila* criaFila();
void insere(Fila* q, char n[][max]);
char remover(Fila* q);

int main (){
    char clientes[1000];
    Fila* q = criaFila();

    printf("Insira um nome: \n");
    scanf("%s", clientes);
    getchar();
    insere(q,clientes);
    printf("Insira um nome: \n");
    scanf("%s", clientes);
    getchar();
    insere(q,clientes);
    printf("Insira um nome: \n");
    scanf("%s", clientes);
    getchar();
    insere(q,clientes);

    printf("Apagando Clientes:\n");
    printf("%s\n", remover(q));
    printf("Apagando Clientes:\n");
    printf("%s\n", remover(q));
    printf("Apagando Clientes:\n");
    printf("%s\n", remover(q));

}

Fila* criaFila(){
    Fila* q = (Fila*) malloc(sizeof(Fila));
    q -> inicio = 0;
    q -> fim = 0;

    return q;
}

void insere(Fila* q, char n[][max]){
   q ->nomes[][q->fim++] = char n[][max];
}

char remover(Fila* q){
    char n[][q ->inicio] = q -> inicio++;

    return n[][q ->inicio];
}
