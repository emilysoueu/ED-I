#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define FALSE 0
#define TRUE 1

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
 void concatList(lista *l1, lista *l2){
	l1 -> tail -> prox = l2 ->cab;
	l1 ->tail = l2 -> tail;
  }

void show(lista* l){
    node* aux = l -> cab;
     int x;

    while(aux != NULL){
        x = aux -> dado;
        printf("%d ", x);
        aux = aux -> prox;
    }
}

int busca(lista *l, int x){
	node* copia = l -> cab;
	
	while(copia != NULL){
		if (copia -> dado == x)
		  return 1;

	 copia = copia->prox;
     }
	
	return 0;
}

void copiaLista(lista*l1, lista* novo){
    node* temp1 = l1 -> cab;

    while(temp1!= NULL){
        insert(novo, temp1 -> dado);
        temp1 = temp1 -> prox;
 
    }

    return ;
}

int sizeList(lista* l){
    node* tmp = l -> cab;
    int size = 0;

    while(tmp!= NULL){
        size++;
        tmp = tmp -> prox;
    }

    return size;
}
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

lista **concatOrdenada(lista *l1, lista *l2){ 
	
	// concatenando a lista l2 em l1
	l1 -> tail -> prox = l2 ->cab;
	l1 ->tail = l2 -> tail;
	
	show(l1);
	reordenaLista(l1);
	
}


// h -> Formar uma lista contendo a união dos elementos de duas listas. ok
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

int somaInt(lista *l){
	node* copia = l -> cab;
	int soma = 0;

	while(copia != NULL){
		soma += copia -> dado;
		copia = copia -> prox;
	}

	return soma;
}

void delSecond(lista *l){
	node* ant = l -> cab;
	node* atual = ant -> prox;

	ant -> prox = atual -> prox;
	free(atual);
	atual = ant -> prox;
}

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




int main(){
    lista* simples = NULL;
    lista* novata = NULL;
   

    simples = criar();
    novata  = criar();

    
    insert(simples,3); insert(simples,1); insert(simples,2); insert(simples,4);    
    printf("lista 1:\n");
    show(simples);
    
    //insert(novata,6); insert(novata,4); insert(novata,2);
    //printf("\nlista 2:\n");
    //show(novata);
   
    //copiaLista(simples,novata);     //ok funciona
    //show(novata);
	
	//printf("\nlista ordenada:\n");
	//reordenaLista(simples); // ok funciona
	//show(simples);
	
	// printf("\nlista 3:\n");
	 //concatOrdenada(simples,novata);
	 
	// concatList(simples, novata);
	// show(simples);
	 
	 //printf("\nlista UNiao :\n");
	// uniaoLista(simples,novata);
	// show(simples); //31246
	
	 delEnd(simples);
	 printf("\ndel last elem :\n");
	 show(simples);
	 
	 //apagarLista(simples);
	 //show(simples);
	 
	 int x=somaInt(simples);
	 printf("soma = %d", x);
	 
	 delSecond(simples);
	 show(simples);
	 
	 insertNpos(simples,1,10);
	 show(simples);
	 
	 deletElm(simples,1);
	 show(simples); 
	 
	 
	
	 
	 
     
   

}
