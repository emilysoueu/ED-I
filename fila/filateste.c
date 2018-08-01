#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define max 3

typedef struct queue{
    int f[max];
    int inicio, fim;
}Fila;

Fila* criarFila();
void insereFila(Fila*, int x);
int removeFila(Fila*);
bool isEmpty(Fila*);
bool isFull(Fila*);

int main(){
    int num;
    Fila* q = criarFila();


            printf("Insira Elementos: \n");
            scanf("%d", &num);
            insereFila(q,num);
            printf("Insira Elementos: \n");
            scanf("%d", &num);
            insereFila(q,num);
            printf("Insira Elementos: \n");
            scanf("%d", &num);
            insereFila(q,num);


        printf("%d\n", removeFila(q));
        printf("%d\n", removeFila(q));
        printf("%d\n", removeFila(q));


}



Fila* criarFila(){
    Fila* q = (Fila*) malloc(sizeof(Fila));
    q -> inicio = 0;
    q -> fim = 0;

    return q;

}

void insereFila(Fila* q, int x){
    q -> f[q -> fim ++] = x;
}

int removeFila(Fila* q){
    int x = q -> f[q -> inicio++];

    return x;
}

bool isEmpty(Fila* q){
    if (q -> fim == q -> inicio){
        printf("Lista Vazia!");
    }
}
bool isFull(Fila* q){
    if (q -> fim == 3){}
    printf("Lista Cheia!");
}

