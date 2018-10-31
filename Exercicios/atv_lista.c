#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define FALSE 0
#define TRUE 1

// ========================== Estruturas para duplamente Encadeada===================================
/**
typedef struct _node_{
	int dado;
	struct _node_ *prox;
	struct _node_ *prev;
}node;

typedef struct _lista_{
	node* cab;
	node* tail;
}lista;


lista* criar(){
    lista *l = (lista*)malloc(sizeof(lista)); 
    if (l != NULL){
        l -> cab = NULL;
        l -> tail = NULL;
    } 
    return l; 	
}

void *insert(lista *l, int dado){
    node* aux = l -> cab;// nó auxiliar pra guardar a cabeça e não perder a lista;

    node* novo = (node*)malloc(sizeof(node));
    if (novo!= NULL){
        novo -> dado = dado;
    }

    if (l != NULL){
      if (l -> cab == NULL){
       
        l -> cab = novo;
        l -> tail = novo;
        l -> cab -> prox = NULL;
        l -> tail -> prox = NULL;
      }else{
         
        l -> tail -> prox  = novo;
        novo -> prev = l -> tail;
        l -> tail = novo;
      }
    }

}

void printaLista(lista *l){
    node* tmp = l -> cab;
    int x;

    while(tmp != NULL){
        x = tmp -> dado;
        printf("%d ",x);
        tmp = tmp -> prox;
    }
}
*/

//=========================== Estruturas para simplesmente encadeada==================================[usada pela maioria das questões]
typedef struct _node_{
    int dado;
    struct _node_ *prox;
} node;

typedef struct _lista_{
    node *cab;
    node *tail;
} lista;

lista *criar(){
    lista *l = (lista*)malloc(sizeof(lista));

    if (l!= NULL){
        l ->cab = NULL;
        l -> tail = NULL;
    }

    return l;
}



// ================================= ATIVIDADE =====================================//
   ///a. Incluir um elemento no final de uma lista.
   void insert(lista* l, int x){
    node* aux = l -> cab;

    node* novo = (node*)malloc(sizeof(node));
    if (novo == NULL) return;

    novo -> dado = x;

    if (l != NULL){
        if (aux == NULL){
            l -> cab =novo;
            l -> tail = novo;
        }else{
			l -> tail -> prox = novo;
            l -> tail = novo;
        }
    }
  }
   ///  b. Concatenar duas listas.
   void concatList(lista *l1, lista *l2){

	l1 -> tail -> prox = l2 ->cab;
	l1 ->tail = l2 -> tail;

  }
   ///  c. Liberar todos os nós numa lista.
   void apagarLista(lista *l){
	node *temp, *aux;
	
	temp = l -> cab;
	
	while(temp != NULL){
		aux = temp -> prox;
		free(temp);	
		temp = aux;
	}
	
	l-> cab = NULL;
	
}
   ///  d. Inverter uma lista de modo que o último elemento se torne o primeiro, e assim por diante.
   //[aqui é pra ser utilizada em uma lista duplamente encadeada]
   void trocaOrdem(lista* l1){

	node* end = l1 ->  tail;
  node* beg = end -> prev;
	node* tmp;
	
	while(end != NULL){
    
    tmp = end->prox;
    end->prox = end ->prev;
    end ->prev = tmp;
    end = end -> prox;
  }

  tmp = l1-> tail;
  l1 -> tail = l1 -> cab;
  l1 -> cab = tmp;
   
		
}
   ///  e. Eliminar o último elemento de uma lista.
   void delEnd(lista *l){
	node* last = l -> cab;
	node* befLast ;
	
	while(last -> prox != NULL){
		befLast = last;
		last= last -> prox;
		
	}
	
	free(last);
	befLast -> prox = NULL;	
}
   ///  f. Eliminar o enésimo elemento de uma lista.
   void deletElm(lista *l, int pos){
	node* temp;
	node* temp2;
	temp = l -> cab;
	int k = 1;


	while (temp != NULL && k < pos){
		temp = temp -> prox;
		k++;
		printf("\npos: %d",k);
	}

	if (k < pos && temp -> prox == NULL)
		printf("Pos nao existe\n");

	temp2 = temp -> prox;
	free(temp2);
	temp -> prox  = temp -> prox -> prox;
	
}

   ///  g. Combinar duas listas ordenadas numa única lista ordenada.
  void concatOrdenada(lista *l1, lista *l2){ 
	concatList(l1, l2);	
	reordenaLista(l1);
    show(l1);
    //somente para fins de teste, geraldo quer pra reesecrever os códigos e não apenas chamar as funções
	
}

   ///  h. Formar uma lista contendo a união dos elementos de duas listas.
   void uniaoLista(lista *l1, lista *l2){
	node* temp = l1 -> cab;
	node* aux = l2 -> cab;

	while(aux != NULL){
		if (busca(l1,aux -> dado) != 1){
			printf("%d != %d",l1 -> cab-> dado, aux-> dado);
			printf(" = %d ",busca(l1,aux -> dado));
		    insert(l1,aux -> dado);
		    printf("\n numero inserido: %d \n", aux -> dado);
		 }			
		aux = aux -> prox;
	}
  }
   
   ///   j. Inserir um elemento depois do enésimo elemento de uma lista.
    void insertNpos(lista *l, int pos, int dado){
	node* aux = l -> cab;
	node* novo = (node*)malloc(sizeof(node));
	if (novo == NULL) return;
	
	novo -> dado = dado;
	int k =1;

	while(aux != NULL && k < pos){
		k ++;
		aux = aux -> prox;
	}

	if (k == pos){		
		novo -> prox = aux -> prox;
		aux -> prox = novo;
	}

}
   ///  k. Eliminar cada segundo elemento de uma lista.
   void delSecond(lista *l){
	node* ant = l -> cab;
	node* atual = ant -> prox;

	ant -> prox = atual -> prox;
	free(atual);
	atual = ant -> prox;
}
   ///  l. Colocar os elementos de uma lista em ordem ascendente.
   void reordenaLista(lista *l1){
   //printf("Reordenando a lista\n");
   int tamanho = sizeList(l1);// pegar o tamanho da lista
  // printf("Tamanho da lista: %d\n", tamanho);

   node *atual = l1->cab;
   bool ordenada = true;
   while(atual != NULL) {
      ordenada = true;
      while(atual->dado > atual->prox->dado) {
        // printf("\n%d > %d\n", atual->dado, atual->prox->dado);
         int aux = atual->prox->dado;
         atual->prox->dado = atual->dado;
         atual->dado = aux;
         atual = atual->prox;
         ordenada = false;
      }
      if(ordenada) {
         break;
      } else {
         atual = l1->cab;
      }
   }
   printf("\nNova Lista: \n");
   show(l1);
}  
   ///  m. Retornar a soma dos inteiros numa lista
    int somaInt(lista *l){
        node* copia = l -> cab;
        int soma = 0;

        while(copia != NULL){
            soma += copia -> dado;
            copia = copia -> prox;
        }

        return soma;
    }
   ///  n. Retornar o número de elementos numa lista.
   int sizeList(lista* l){
    node* tmp = l -> cab;
    int size = 0;

    while(tmp!= NULL){
        size++;
        tmp = tmp -> prox;
    }

    return size;
}
   /// p. Criar uma segunda cópia de uma lista.
   void copiaLista(lista*l1, lista* novo){
    node* temp1 = l1 -> cab;

    while(temp1!= NULL){
        insert(novo, temp1 -> dado);
        temp1 = temp1 -> prox;
 
    }

    return ;
}
   ///   i. Formar uma lista contendo a intersecção dos elementos de duas listas.
   ///  o. Deslocar node(p) n posições à frente numa lista.

