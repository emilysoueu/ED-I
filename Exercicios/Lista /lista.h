#ifndef LISTA_H
#define LISTA_H

typedef struct _node_{
	int data;
	struct _node_ *prox;
}node;

typedef struct _lista_{
	node *first;
	node *cur;
}lista;

lista *crialista(); // pra criar a lista tem q ser do tipoda segunda estrutura
void insereLista(lista *L, int x);
int removeLista(lista *L);





#endif
