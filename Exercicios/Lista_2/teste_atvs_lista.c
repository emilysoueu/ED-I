#include <stdio.h>
#include <stdlib.h>

typedef struct _lista_{
	int dado;
	struct _lista_ *prox;
}lista;

// cria a caixinha
lista *criar(int dado){
	lista *l = (lista*)malloc(sizeof(lista)); 
	if (l == NULL) return NULL;
	
	l -> dado = dado;
	l -> prox = NULL;
	
	return l;	
}

//insere no fim 
void addEnd(lista **l, int x){
	lista *aux ;
	lista *novo = criar(x);
	if(novo == NULL) return ;
	
	aux = *l;	
	
	if (aux == NULL){
		if (novo!= NULL){
			novo -> prox = aux;
			*l = novo;
		}		
	}else{		
		if (novo!= NULL){
			while(aux -> prox != NULL){ // prestar atenção aqui
				aux = aux -> prox;
			}
			aux-> prox = novo;
		}
	}
		
}

int busca(lista *l, int x){
	int achou= 0;
	while(l != NULL){
		if (l -> dado == x)
		  achou =  1;
		else
		  achou = 0;
		l = l -> prox;
     }
	
	return achou;
}


void delBeg(lista **l){
	lista *temp = *l; // pego a 1 pos
	lista * next = temp -> prox;  // pego a prox pos, ja que quando pra não perder a lista
	
	*l = next; // faço a cabeça apontar pro antigo prox
	free(temp); // libero a antiga cabeça	
}


void delEnd(lista **l){
	lista *last = *l;
	lista *prev;
	
	while(last->prox != NULL){
		prev = last;
		last = last -> prox;
	}
	free(last);
	prev -> prox = NULL;
	
}

void apagarLista(lista **l){
	lista *temp, *aux;
	
	temp = *l;
	
	while(temp != NULL){
		aux = temp -> prox;
		free(temp);	
		temp = aux;
	}
	
	*l = NULL;
	
}



void printaLista(lista *l1){
	int x;
	while (l1 != NULL){
		x = l1 -> dado;
		printf("%d ", x);
		l1 = l1 -> prox;		
	}
}
// ================================ ATIVIDADE =============================================== //

void concatList(lista **l1, lista *l2){
	lista *temp1;
	temp1 = *l1;

	while(temp1 -> prox != NULL)
		temp1 = temp1 -> prox;

	temp1 -> prox = l2;
}

//para duplamente encadeada -- letra d -- // d -> Inverter uma lista de modo que o último elemento se torne o primeiro, e assim por diante. ok


void trocaOrdem(lista* l1){
	node* beg = l1 -> cab;
	node* end = l1 ->  tail;
	node* temp;
	
	
	temp = beg;
	beg = end;
	end = temp;
	
	int x;
	
	while(beg!= NULL){
		x = beg -> dado;
		printf("%d ", x);
		beg = beg -> prev;
	}
		
}




// letra g

lista **concatOrdenada(lista **l1, lista **l2){
	lista **l3, *aux, *temp1, *temp2;
	aux = *l3; 
	temp1 = *l1;
	temp2 = *l2;

	while(temp1 != NULL || temp2 != NULL)
		if (temp1-> dado <  temp2 -> dado){
			addEnd( &*l3,temp1->dado);
		}else{
			addEnd( &*l3,temp2 -> dado);
		}
		
	/*
	if ( temp1 == NULL){
		addEnd( &*l3,temp2 -> dado);
		aux-> prox = temp2;
	}else{
		addEnd( &*l3,temp1->dado);
		aux -> prox = temp1;
	}
*/
	return l3;
}

// m -> Retornar a soma dos inteiros numa lista. ok
int somaInt(lista *l){
	lista *copia = l;
	int soma = 0;

	while(copia != NULL){
		soma += copia -> dado;
		copia = copia -> prox;
	}

	return soma;
}
int main(){
	
	lista *papel;
	lista *livro;
	lista *bibliotk;
	papel = NULL;
	livro = NULL;
	bibliotk = NULL;
	int i,j;
	
	
	
	// lista 1
	for (i=1; i<=5; i++){
		addEnd(&papel,i);
	}
	printaLista(papel);
	printf("\n");
	
	
	// lista 2
	for (j=10; j<=15; j++){
		addEnd(&livro,j);
	}
	printaLista(livro);
	printf("\n");
	
	
	
	
	
	
	//==============================> teste atividade <========================================//
	// a
	/**
	printf("Lista Concatenada");
	concatList(&papel, livro);
	printaLista(papel);
	printf("\n");
	*/
	
	
	int soma=somaInt(papel);
	printf("%d", soma);
	
	
	
	
	
	
	
	
			
}
