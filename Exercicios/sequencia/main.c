/**
a) Implemente um pequeno programa que registra ID de entrada num evento.
O ID é um número aleatório de 4 dígitos que identifica o participante da seção.
Existe um número máximo de participantes na seção. No final, o programa deve informar quais participantes estavam presentes na seção
*/

/// definir a quantidade de entradas ok
/// inserir n entrada
/// buscar entradas
/// imprimir as entradas

#include <stdio.h>
#include <stdlib.h>

/// pedir na main a quantidade de entradas;

typedef struct _evento_{
    int *eve; /// vetor tad
    int entradas; /// tamanho do vetor TAD
    int atual; /// posição atual no vetor TAD
} evento;

void mostraTudo(evento* s, int entradas);
int buscar(evento* s, int chave);
int insert(evento* s, int chave);
evento* Criar(int entradas);

int main(){
    int tam, chave;

    int i;

    printf("Esse eh o seu vetor TAD para registrar entradas em um evento: \n");
    printf(" Informe a quantidade de entradas na secao: \n");
    scanf("%d", &tam);

    evento *s = Criar(tam);
    printf("Insira os IDs de entradas\n");
    for (i=0; i<=tam;i++){
        scanf("%d", &chave);
        inserir(s, chave);

    }

    printf("Aqui estão todos os IDs presentes no evento: \n");
    mostraTudo(s, tam);

}

evento* Criar(int entradas){
    evento* s = NULL;

    if (entradas > 0){
        s = (evento*) malloc (sizeof(evento));
    }

    if(s -> eve != NULL){
        s-> eve = (evento*)malloc(sizeof(entradas)*entradas);
        s -> atual = 0;
    }else{
        free(s);
        s = NULL;
    }

    return s;

}

int inserir(evento* s, int chave){
    if (s != NULL){
        if ((s-> eve != NULL) && (s -> entradas > s -> atual)){
            s-> eve[s-> atual] = chave;
            s-> atual ++;
            return 1;

        }
    }

    return 0;

}

int buscar(evento* s, int chave){

    while(s-> atual != chave);
        if (s -> eve[s->atual] == chave){
            printf("%d", s -> atual);
            return 1;
        }else{
            s-> atual ++;
        }
}

void mostraTudo(evento* s, int entradas){
    int i;

    if (s != NULL){
        if ( (s-> eve != NULL) && (s -> entradas > s -> atual)) {
            for (i=0; i<= entradas; i++){
                 printf("%d", s -> eve[i]);
             }

        }
    }



}





