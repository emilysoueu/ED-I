//@emilysoueu

#include <stdio.h>
#include <stdlib.h>
#include "tadG.h"

//===========> FUNÇÕES <===============//

sequencia *criar(int max, Comp c, Print p, Remover r){
	sequencia *tmp = (sequencia*) malloc(sizeof(sequencia)); 
	
	if (tmp != NULL){
		tmp -> dados = (void*)malloc(sizeof(void)* max);
		if (tmp -> dados != NULL){
			tmp -> max = max;
			tmp -> qtd = 0;
			tmp -> comp = c;    // novo
			tmp -> print = p;  //novo
			tmp -> rem = r;   //novo
		}else{
			free(tmp);
			tmp = NULL;
	   }	
   }
   return tmp;	
}

void destruir(sequencia **seq){
	sequencia *tmp = *seq;
	
	for(int i=0; i< tmp -> qtd; i++){
		tmp -> rem(tmp -> dados[i]);
	}
	free(tmp -> dados);
	free (tmp);
	tmp = NULL;
}

int inserir(sequencia *seq, void *valor){
	if( (seq == NULL) || (seq -> dados == NULL) || (seq -> qtd>= seq -> max) ){
		return 0;
	}
	
	seq -> dados[seq -> qtd] = valor;
	seq -> qtd++;
	
	return 1;
}

void listar(sequencia *seq){
	if ((seq == NULL) || (seq -> dados == NULL) ){
		printf("Erro NULL - funcao imprimir");
	}
	int i;
	
	for (i=0; i< seq -> qtd; i++){
		seq -> print(seq -> dados[i]);
	}
}

int buscar( sequencia *seq, void *chave){
	int i;
	if ((seq == NULL) || (seq -> dados == NULL)){
		return -1;
	}
	for(i=0; i< seq ->qtd; i++){
		if (seq -> comp(seq ->dados[i], chave) == 0){
			return i;
		}
	}
	return -1;
}

int remover(sequencia *seq, void *chave){
	if ((seq == NULL) || (seq -> dados == NULL)){
		return -1;
	}
	int pos = buscar(seq, chave);
	
	if (pos >=0){
		seq -> rem(seq -> dados[pos]);
		
		seq -> dados[pos] = seq -> dados[seq -> qtd -1];
		seq -> qtd --;
	}

	
	return pos;	
}

void removerTodos(sequencia *seq, void *chave){
	int pos;
	do{
		pos = remover(seq,chave);
	}while(pos >= 0);
}








