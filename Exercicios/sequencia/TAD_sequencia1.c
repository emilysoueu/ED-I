#include <stdio.h>
#include <stdlib.h>
#include "seq.h"  /// documentação

typedef struct _sequencia_{
	int *dados; /// vetor TAD
	int qtd_max; /// maior numero de elementos
	int qtd_elm; /// mostra a posição atual no vetor
}sequencia;


sequencia* criar(int qtd_max){

	sequencia* seq = NULL; // inicializa a sequencia com NULL

	if( qtd_max > 0){ /// condição de existencia 
		seq = (sequencia*) malloc(sizeof(sequencia)); // aloca 1 espaço

		if (seq -> dados != NULL){
			seq -> dados = (sequencia*) malloc(sizeof(sequencia*)*qtd_max);
			seq -> qtd_max = qtd_max;
			seq -> qtd_elm = 0;
		}
	}else{
		free(seq);
		seq = NULL;

	}

	return seq;

}
/**
  if (max > 0) {
    s = (Stack *)malloc (sizeof(Stack));
    if(s != NULL) {
      s->itens =(void*)malloc(sizeof(void*)*max));
      if (s->itens != NULL) {
        s->top = -1;
        s->maxItens = max;
        return s;
      }
    }
  }
  return NULL;
}

*/

int insert (sequencia* seq, int dado){
	if(seq != NULL){
		if(seq -> dados != NULL) && (seq -> qtd_max > seq -> qtd_elm){
			seq -> dado[seq -> qtd_elm] = dado;
			seq -> qtd_elm ++;

			return 1;
		}
	}

	return 0;

}

/**
 Recebe a pilha e o item;
int stkPush (Stack *s, void *item) {
  ///Testa se a pilha é válida
  if (s != NULL) {
  /// Teste se estante é válida
    if (s->itens != NULL) {
   /// Se tem espaço na estante
      if(s->top < s->maxItens-1) {
      ///Coloca o item na posição (1ª livre) top+1
        s->itens[s->top+1]=item;
        ///Incrementa top
        s->top++;
        ///Retorna TRUE
        return TRUE;
      }
    }
  }
  return FALSE;
}

*/


int apagar(sequencia* seq, int dado){
	int i;

	if((seq!= NULL) && (seq-> dados != NULL) && (seq -> qtd_elm >0)){
		for(i=0; i < seq -> qtd_elm; ){
			if (seq -> dados[i] == qtd_elm){
				seq -> dados[i] = seq -> dados[seq -> qtd_elm -1];
				seq -> qtd_elm --;

			}else{
				i++;
			}
			return 1;
		}
		return 0;
	}


}

int procura(sequencia* seq, int dado);
int apagarTudo(sequencia* seq);



