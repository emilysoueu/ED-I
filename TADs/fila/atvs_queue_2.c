#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define max 3

typedef struct queue{
    char f[max];
    int inicio, fim;
}Fila;

Fila* criaFila();
void insere(Fila* q, char x);
char remover(Fila* q);

int main(){
    char h;
    Fila* q = criaFila();

    printf("Insira um caractere: \n");
    scanf("%c", &h);
    insere(q,h);
    getchar(); /// equivale ao cin.igore()
    printf("Insira um caractere: \n");
    scanf("%c", &h);
    insere(q,h);
    getchar();
    printf("Insira um caractere: \n");
    scanf("%c", &h);
    insere(q,h);

    printf("Apagando Fila: \n");
    printf("%c\n", remover(q));
    printf("%c\n", remover(q));
    printf("%c\n", remover(q));


}

Fila* criaFila(){
    Fila* q = (Fila*)malloc(sizeof(Fila));
    q -> fim = 0;
    q -> inicio = 0;

    return q;
}

void insere(Fila* q, char x){
    q -> f[q ->fim++] = x;
}

char remover(Fila* q){
    char x = q -> f[q->inicio++];

    return x;
}

