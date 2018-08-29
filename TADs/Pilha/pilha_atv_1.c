/**
Escreva um algoritmo que use uma pilha para inverter a ordem das letras de cada palavra de uma string ASCII,
 preservando a ordem das palavras. Por exemplo, para a string  ESTE EXERCICIO E MUITO FACIL  o resultado deve ser :
  ETSE OICICREXE E OTIUM LICAF.
*/

#include <stdlib.h>
#include <stdio.h>

#define max 5

typedef struct stack{
    char word[max];
    int topo;
}pilha;

pilha* createStack();
void push(pilha* p, char ch);
void push(pilha* p, char ch);
char pop(pilha*p);

int main(){
    pilha* p = createStack();

    char w;
    printf("Insira sua palavra: \n");
    for (int i=0; i<5; i++){
        printf(".\n");
        w = getchar();
        push(p,w);
    }
    printf("Sua palavra ao contrario");
        for (int i=0; i<5; i++){
            printf("%c", pop(p));
        }


}

pilha* createStack(){
    pilha * p = (pilha*) malloc(sizeof(pilha));
    p->topo = -1;
}

void push(pilha* p, char ch){
    p -> word[p->topo++] = ch;
}

char pop(pilha*p){
    char ch = p->word[p->topo-=1];
    return ch;
}




