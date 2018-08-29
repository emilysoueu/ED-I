#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct _sequencia_{
    int *dados;
    int tam ;
    int qtd;
} sequencia;

sequencia * seq = creat(int size);
int insert(sequencia* seq, int dado);
int search(sequencia* seq, int chave);
void remov(sequencia* seq);

int main(){
    int opcao;
    int size;

    printf("Insira o tamanho da sua sequencia:\n");
    scanf("%d",&size);

    sequencia* seq = creat(size);


    do{
        printf("TAD - Sequencia................\n");
        printf("Menu...........................\n");
        printf("1 - Inserir Elementos..........\n");
        printf("2 - Pesquisar Elementos........\n");
        printf("3 - Remover Elementos Elementos\n");
        scanf("%d", &opcao);

        switch (opcao){
            case 1:{
                int elem;
                ///INSERIR ELEMENTOs NA SEQUENCIA
                printf("Insira elementos na sua sequencia: \n");
                scanf("%d", &elem);
                insert(seq, elem);

            }
                break;
            case 2:{
                int pesq;
                ///INSERE ELEMENTOS PARA PESQUISA
                printf("Elemento para pesquisa: \n");
                scanf("%d", &pesq);
                search(seq, pesq);
                }
                break;
            case 3:{
                printf("Removendo elementos da sequencia");
                remov(seq);
                printf("Elementos Removidos");
                }
                break;
            default:
                printf("Opcao Invalida\n");
        }

    }while(opcao > 0 && opcao < 4);

}

sequencia* creat(int tam){
    sequencia* seq = (sequencia *) malloc(tam * sizeof(sequencia));
    seq -> qtd = 0;

    return seq;
}

int insert(sequencia* seq, int dado){
    seq -> qtd = 0;
    seq -> dados[seq->qtd] = dado;
    seq -> qtd ++;

    return 1;
}

int search(sequencia* seq, int chave){
    int i = 0;
    bool achou;
    while (!achou){
        if(seq -> dados[i] == chave){
        printf("Encontrado na posicao %d", i );
        achou = true;
        }
        i++;
    }
    return 2;
}

void remov(sequencia* seq){
    seq -> dados[seq -> qtd] = NULL;
    seq -> qtd ++;

}



