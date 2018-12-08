// a -> Incluir um elemento no final de uma lista. // testei 0k

void insertEnd(Lista **L, int dado){  
	Lista *novo, *aux ;
	*novo = criar(int dado);

	if (novo != NULL){
		if (*L != NULL){ // averiguar
			*L = novo;
		}else{
			aux = *L;
			while (aux -> prox != NULL)
				aux = aux -> prox 
			aux -> prox = novo;
		}
		return 1;

	}
	return 0;
}
// b -> Concatenar duas listas. // teste ok

void concatList(lista *l1, lista *l2){
	lista *temp1, *temp2;
	temp1 = l1;

	while(temp1 -> prox != NULL)
		temp1 = temp1 -> prox;

	temp1 -> prox = l2;
}

// c -> Liberar todos os nós numa lista. teste  ok

void deleteNode(lista **l){
	lista *temp, *aux;
	temp= *l;

	while (temp!= NULL){
		aux = temp -> prox;
		free(temp);
		temp = aux;
	}

	*l = NULL;
}

// d -> Inverter uma lista de modo que o último elemento se torne o primeiro, e assim por diante. ok

void trocaOrdem(lista **l){
	lista *ant, *prox, *atual;

	if (*l!= NULL){
		atual = *l;

		while(atual != NULL){
			prox = atual -> prox;
			if (ant != NULL)
				atual -> prox = ant;
			ant = atual;
			atual = prox;
		}
		if (atual != NULL)
			*l = atual;
	}

}

// e -> Eliminar o último elemento de uma lista. teste ok (ver no teste de execução)
void deletLast(lista **l){
	lista *aux;
	aux = *l;

	while (aux -> prox != NULL)
		aux = aux -> prox;

	free(aux -> prox);

}

// f -> Eliminar o enésimo elemento de uma lista. teste ok (ver no teste de execução) ok
void deletElm(lista **l, int pos){
	lista *temp, *temp2;
	temp = *l;
	k = 1;


	while (temp != NULL && k < pos){
		temp = temp -> prox;
		k++;
	}

	if (k < pos && temp -> prox NULL)
		printf("Pos nao existe\n");

	temp2 = temp -> prox;
	free(temp2);
}

// g -> Combinar duas listas ordenadas numa única lista ordenada. ok

lista **concatOrdenada(lista **l1, lista **l2){
	lista **l3, *aux;
	aux = *l3; 

	while((*l1) != NULL ||(*l2) != NULL)
		if ((*l1) -> dado <= (*l2) -> dado){
			novo = criar( (*l1)-> dado);
		}else{
			novo = criar( (*l2) -> dado);
		}
		(*l3) -> prox = novo;
		(*l3) = l3 -> prox;

	if (*l1 == NULL){
		(*l3) -> prox = *l2;
	}else{
		(*l3) -> prox = *l1;
	}

	return *aux;
}

// j -> Inserir um elemento depois do enésimo elemento de uma lista. ok

void insertNpos(lista **l, int pos, int dado){
	lista *aux;
	aux = *l;
	int k =1;

	while(aux != NULL && k < pos){
		k ++;
		aux = aux -> prox;
	}

	if (k == pos){
		novo = criar(dado);
		novo -> prox = aux -> prox;
		aux -> prox = novo;
	}

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
// n -> Retornar o número de elementos numa lista. ok
int sizeofLista(lista *l){

	int size= 0;

	while(lista != NULL){
		size++;
		lista = lista -> prox;
	}

	return size;
}

// k -> Eliminar cada segundo elemento de uma lista.
void delSecond(lista **l){
	lista *ant = *l, *atual = ant -> prox;

	ant -> prox = atual -> prox;
	free(atual);
	atual = ant -> prox;
}

// p -> Criar uma segunda cópia de uma lista. ok

void copiaLista(lista*l1, lista* novo){
    node* temp1 = l1 -> cab;

    while(temp1!= NULL){
        insert(novo, temp1 -> dado);
        temp1 = temp1 -> prox;
 
    }

    return ;
}
// o -> Deslocar node(p) n posições à frente numa lista. ok

void deslocaNode(lista **l, int pos, int p){
	int k = 0, q = 0;
	lista *aux = *l;
	lista *ant = l;

	while(aux != NULL && k < pos){
		ant = aux;
		aux = aux -> prox;
		k++;
		// testar se chegou em pos

		ant -> prox = atual -> prox;
		while(ant!= NULL && q != n){
			ant = ant -> prox;
			q++;
		}
		// testar se chegou em n
		aux -> prox = ant -> prox;
		ant -> prox = aux;
	}
}

void inverterListaCerto(lista* l) {// ======================TERÇAS=======================
	node* head = l -> cab; // guarda a cabeça
	node* tail = l -> tail; // guarda o fim 
	node* aux; 

	while(tail != NULL){
		aux = tail -> prox;
		tail ->prox = tail -> prev;
		tail -> prev = aux;
		tail = tail -> prox;
	}

    aux = l -> tail;
    l -> tail = l -> cab;
    l -> cab = aux;
	
}

// h -> Formar uma lista contendo a união dos elementos de duas listas. ok
void uniaoLista(lista *l1, lista *l2){
	int x;
	lista *aux = l2 -> cab;

	while(l2 != NULL){
		x = l2 -> dado;
		if (busca(l1,x) != 1)
			insert(l1,x);
		l2 = l2 -> prox
	}

}

// i -> Formar uma lista contendo a intersecção dos elementos de duas listas.  ok
void intersecLista(lista *l1, lista *l2){
	int x;
	lista *aux = l2;

	while(aux != NULL){
		x = l1 -> dado;
		if (busca(l2,aux)!= 1)
			remover(l1,aux);
		l2 = l2 -> prox;
	}

}
// l -> Colocar os elementos de uma lista em ordem ascendente.
void reordenaLista(lista *l1){
	int tamanho = sizeofLista(l1);// pegar o tamanho da lista
	lista *aux = l1 -> prox;
	int k,j;
	int atual = l1 -> dado, prox = aux -> prox;

	for (k = 0; k< tamanho -1; k++){
		for (j = 0; j< tamanho - k-1; j++){
			if (atual > prox){
				atual -> prox = aux -> prox;
				aux -> prox = atual;
			}
		}
	}
}
