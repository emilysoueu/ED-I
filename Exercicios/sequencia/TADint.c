#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


typedef struct _sequencia_{
  int *dados;
  int entradas;
  int atual;
} sequencia;

sequencia *criarSeq(int entradas);
int inserir(sequencia *seq, int chave);
int buscar(sequencia *seq, int dado);
void listar(sequencia *seq);
int destruir(sequencia *seq);


int main(){
  int tam, menu;

  printf("Informe a quantidade de entradas: ");
  scanf("%d", &tam);

  sequencia *seq = criarSeq(tam);

  do {

    printf("=====Menu=====\n");
    printf("1 - inserir\n");
    printf("2 - buscar\n");
    printf("3 - listar\n");
    printf("4 - remover\n");
    printf("5 - destruir\n");
    printf("0 - sair ");
    printf("Sua escolha: ");
    scanf("%d", &menu);

    switch(menu){
       case 1:{
         int i, key;
         for (i=0; i<tam; i++){
           printf("Insira: \n");
           scanf("%d",&key);
           inserir(seq, key);
         }

      }
        break;
        case 2:{
          int elm;
          printf("Informe o elemento de busca: ");
          scanf("%d", &elm);
          buscar(seq, elm);         
        
      }
        break;
        case 3:{
          listar(seq);        
      }
        break;
        case 4:{
          int rem;
          printf("Informe o elemento para remover: \n");
          scanf("%d",&rem);
          remover(seq, rem);
          printf("Elemento removido com sucesso!!\n");
        
      }
        break;
        case 5:{
          destruir(seq);        
      }
        break;
        default:
        printf("Saindo do programa: ");
        exit(0);

    }

  }while(menu != 0);

}

sequencia *criarSeq(int entradas){
  sequencia *seq = (int*)malloc(sizeof(int));

  if ((seq == NULL) || (entradas <=0)){
    return NULL;
  }

  seq -> dados= (int*)malloc(sizeof(int)*entradas);

  if (seq -> dados == NULL){
    return NULL;
  }

  seq -> entradas = entradas;
  seq -> atual = 0;

  return seq;

} // fimcriar

int inserir(sequencia *seq, int chave){
  if ( (seq == NULL ) || (seq -> dados == NULL) ){
    return 0;
  }

  seq -> dados[seq -> atual] = chave;
  seq -> atual ++;

  return 1;
}// fim inserir

int buscar(sequencia *seq, int dado){
  if ((seq == NULL)|| (seq -> dados == NULL)){
    return 0;
  }
  int i;
  bool achei = false;

  for ( i=0; i< seq -> entradas; i++){
    if (seq -> dados[i] == dado){
      achei = true;
      break;
    }else{
      achei = false;
    }    
  }

    if (achei){
      printf("Achei\n");
    }else{
      printf("nada\n");
    }
  return i; // n sei se esta certo isso!!!
}// fim buscar

void listar(sequencia *seq){
  if ((seq == NULL)||(seq -> dados == NULL)){
    printf("ERRO funcao listar retornando NULL");
  }
  for (int i=0; i< seq -> entradas; i++){
    printf("%d\n",seq -> dados[i]);
  } 
} // fim listar

int remover(sequencia *seq, int chave){ // ainda n sei fazer mt bm
  if ((seq == NULL)||(seq -> dados == NULL)){
    return  0;
  }// fim remover

  for (int i =0; i< seq -> entradas; i++){
    if (seq -> dados[i] == chave){
        while(i < seq->entradas){
              seq->dados[i] = seq->dados[i+1]; // problemas aqui!!
              i++;                   
        }                     
      seq->entradas = seq-> entradas - 1;
    }
    return 1;

  }
}// fim remover
  

  int destruir(sequencia *seq){

    if ((seq == NULL) || (seq -> dados == NULL)){
      printf("sequencia ja nao existe\n");
      return 0;
    }

    free(seq -> dados);
    free(seq);
    seq = NULL;

    printf("Sequencia destruida com sucesso\n");

    return 1;
} // fim destruir

  
