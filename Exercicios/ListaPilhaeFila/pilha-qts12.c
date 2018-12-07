/**12. Faça um procedimento interativo: PESQFILA( int fila Q, int x) que pesquisa em uma
fila Q por um argumento x, ambos passados como parâmetro.O procedimento deve
retornar V ou F caso encontre ou não o argumento. A fila, ao final do processo, não
deve estar alterada, por isso deve ser utilizada uma estrutura auxiliar (pilha ou fila)
para efetuar a pesquisa.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _fila_{
	int *queue;
	int beg;
	int end;
	int max;
	int qtd;	
}fila;

fila *criar(int max){
	fila *f = (fila*)malloc(sizeof(fila));
	if ((f == NULL) || (max<=0)) return NULL;
	
	f -> queue= (int*)malloc(sizeof(int));
	if (f->queue == NULL) return NULL;
	
	f -> beg = 0;
	f -> end = 0;
	f -> max = 0;
	f -> qtd = 0;
	
	return f; 
}

void push(fila *f, int valor){
	if ((f == NULL)||(f -> queue) == NULL) return;
	
	f -> queue[f->end] = valor;
	f -> end++;
	f -> qtd++;	
}

int pop(fila *f){
	if ((f == NULL)||(f -> queue) == NULL) return -1;
	
	int x;
	x = f ->queue[f->beg];
	f -> beg ++;
	f -> qtd --;
	
	return x;
	
}

int PESQFILA( fila *f, int elm){
	/**if ((f == NULL)||(f -> queue) == NULL) return -1;
	fila *tmp = criar(f->max);
	int x,i;
	
	for(i=0; i<f->max; i++){			
		x = pop(f);
		if (x == elm){			
			push(tmp,x);
			return 0;
		}else{
			return 1;
		}
		push(f,pop(tmp));
	}	
	*/
	if ((f == NULL)||(f -> queue) == NULL) return -1;
	fila *aux = criar(f->max);
	int x,i, achou = 0;
	
	for(i=0; i<f->max; i++){			
		x = pop(f); /// remove um elemento de f
		push(aux,x); /// salva o elemento excluido no auxiliar
		if (x == elm){	 // se encontrar o valor buscado	
			achou = 1; /// marca 1 como achou o elemento
			break;	// freia o laço
		
	}
	/// processo de recuperação dos elementos excluidos de f
	for(i=0; i<f->max; i++){
		x = pop(aux);  /// remove o elemento do topo de aux
		push(f,x);	   /// insere esse elemento em f novamente
	}					// preservando sua ordem original
	if (achou == 1) return 0; /// se o elemento foi encontrado retorna 0
	return 1; // senao 1
}
	
	
	
}

int main(){
	int max = 3, valor,x;
	fila *f = criar(max);
	
	for (int i=1; i<=max; i++){
		x = i;
		push(f,x);	
		printf("entrou\n");	
	}
	
	printf("Informe o valor de busca: \n");
	scanf("%d ",&valor);
	
	if (PESQFILA(f,valor)== 0){
		printf("ok\n");
	}else{
		printf("nok");
		
	}
	
	// não sei o que ta acontecendo aqui;
}

