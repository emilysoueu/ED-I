#include <stdio.h>
#include <stdlib.h>

typedef struct _lista_{
	int dado;
	struct _lista_ *prox;
} Lista;

Lista *formar(int valor){
	Lista *l = (Lista*)malloc(sizeof(Lista));
	if (l == NULL) return NULL;
	
	l -> dado = valor;
	l -> prox = NULL;
	
	return l;
}

// pegar o tamanho da lista
int tamanho(Lista *l){
	Lista *tmp = l; // criando uma copia da lista
	int c =0; // contador
	
	while(tmp != NULL){ // enquanto a lista não chegar ao fim
		c ++; // incrementar o contador
		tmp = tmp -> prox;
	}
	
	return c;
}

// apagar toda a lista

void DeletarLista(Lista **l){
	Lista *auxNode, *iterator; // declarar dois ponteiros
	
	iterator = *l; // pegando a lista original
	
	while (iterator){ // enquanto exisitir elementos na lista
		auxNode = iterator -> prox;
		free(iterator);
	}
	
	*l = NULL;
}

// inserir elementos na lista

void insertNodes(Lista **l, int valor, int pos){ 
	int k =1; // contador
	Lista *p, *q, *novo;
	
	novo = formar(valor); // criando um novo nó
	p = *l; // pegando a referencia da lista original 
	
	// inserindo no inicio
	
	if (pos == 1){
		novo -> prox = p;
		*l = novo;
	}else{
		// inserir na posição indicada
		while((p != NULL)&&(k<pos)){ // enquanto não chego no final da lista nem na posição indicada
			k++; // incrementa o contador
			q = p; 
			p = p -> prox;
		}
		q -> prox = novo;
		novo -> prox = p;
	}
}

//deletando nós de uma lista

void deleteNode(Lista **l, int pos){
	Lista *p, *q;
	int k =1;
	if (*l == NULL){
		printf("Lista is empty");
	}
	
	p = *l; // pegando a referenci da lista
	
	if (pos == 1){ // retirando nós do inicio
		*l = (*l) -> prox;
		free(p);
		return;
	}else{
		// percorrendo a lista pra deletar um no de um posição específica
		while((p!= NULL)&&(k<pos)){
			k++;
			q = p;
			p = p->prox;
		}
		if (p == NULL)
			printf("erro");
		else{
			q -> prox = p-> prox;
			free(p);
		}
	}
}

void printList(Lista *l){
	Lista *tmp = l;
	while (tmp != NULL){
		printf("%d ", tmp -> dado);
		tmp = tmp -> prox;
	}
}

int main(){
	
	Lista *head;
	head = NULL;
	
	insertNodes(&head,10,1);
	insertNodes(&head,2,2);
	insertNodes(&head,7,3);
	insertNodes(&head,1,4);
	insertNodes(&head,3,5);
	
	printList(head);
	
	deleteNode(&head, 4);
	
	printList(head);
	
	
	
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	


