#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define tam 3

typedef struct stack{
    int s[tam];
    int topo;

}pilha;

pilha* criaPilha();
void push(pilha * pSta, int x);
int pop(pilha*pSta);
bool isFull(pilha *pSta);
bool isEmpty(pilha *pSta);



int main(){
    int num;

    pilha * pSta = criaPilha();

    printf("Insira elementos na sua pilha: \n");
    scanf("%d", &num);
    push(pSta, num);
    printf("Insira elementos na sua pilha: \n");
    scanf("%d", &num);
    push(pSta, num);
    printf("Insira elementos na sua pilha: \n");
    scanf("%d", &num);
    push(pSta, num);
    printf("Removendo Elementos da sua pilha: \n");
    printf("%d\n", pop(pSta));
    printf("%d\n", pop(pSta));
    printf("%d\n", pop(pSta));
}

pilha* criaPilha(){
    pilha* pSta = (pilha*) malloc(sizeof(pilha));
    pSta -> topo = -1;

    return pSta;
}

void push(pilha * pSta, int x){
    pSta -> s[pSta->topo++] = x;
}

int pop(pilha*pSta){
    int x = pSta -> s[pSta->topo-= 1];

    return x;
}

bool isEmpty(pilha *pSta){
    if (pSta -> topo == -1){
            printf("Stack is Underflow");
         return true;
    }else{
        return false;
}


}

bool isFull(pilha *pSta){
    if (pSta -> topo >= tam ){
            printf("Stack is Overflow");
        return true;
    }else{
        return false;
    }


}

