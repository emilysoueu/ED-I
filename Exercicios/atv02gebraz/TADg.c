//@emilysoueu
//12/09/2018

#include <stdio.h>
#include <stdlib.h>
#include "tadg.h"


//===========> FUNÇÕES <===============//

sequencia *criar(int max, Comp c, Print p, Remover r){
	sequencia *tmp = (sequencia*) malloc(sizeof(sequencia)); 
	
	if (tmp != NULL){
		tmp -> dados = (void*)malloc(sizeof(void)* max);
		if (tmp -> dados != NULL){
			tmp -> max = max;
			tmp -> qtd = 0;
			tmp -> comp = c;    //novo
			tmp -> print = p;  //novo
			tmp -> rem = r;   //novo
		}else{
			free(tmp);
			tmp = NULL;
	   }	
   }
   return tmp;	
}

void destruir(sequencia **seq){ //passar por referencia 
	sequencia *tmp = *seq;
	
	for(int i=0; i< tmp -> qtd; i++){
		tmp -> rem(tmp -> dados[i]);
	}
	free(tmp -> dados);
	free (tmp);
	tmp = NULL;
}

//4) uma nova função de inserção que realize a inserção em ordem crescente dos elementos.
int inserir(sequencia *seq, void *valor){

	if (seq == NULL) return 0;	
		
	  if (seq -> qtd >= seq -> max){
		for (int i=0; i< seq -> max; i++){
			if (seq -> dados[i] == NULL){ // inserir novos elementos na posição nula;
				seq -> dados[i] = valor;
				break;								
			}/// fim if				
		}///fim for
		return 1;			
	}else{
		seq -> dados[seq -> qtd] = valor;
		seq -> qtd++;
		return 1;	
	}///fim if	
}

void listar(sequencia *seq){
	if (seq == NULL){
		printf("Erro NULL - funcao imprimir");
	}
	int i;
	
	for (i=0; i< seq -> qtd; i++){
		seq -> print(seq -> dados[i]);
	}
}

int buscar( sequencia *seq, void *chave){
	int i;
	if (seq == NULL){
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
	if (seq == NULL) {
		return -1;
	}
	int pos = buscar(seq, chave);
	
	if (pos >=0){
		
		   seq -> dados[pos] =  NULL;// qts 1!	   
		
	}
	
	return pos;	
}
/**
void removerTodos(sequencia *seq, void *chave){
	int pos;
	do{
		pos = remover(seq,chave);
	}while(pos >= 0);
}
*/







