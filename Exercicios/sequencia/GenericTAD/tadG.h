// TAD GENERICO 
//@emilysoueu

#ifndef tadG_H
#define tadG_H

typedef int(*Comp)(void *a, void *b); // compara
typedef void(*Print)(void*a);        //imprime
typedef void(*Remover)(void *a);    // Remover

typedef struct _sequencia_{
	void **dados;
	int max;
	int qtd;
	Comp comp;     // referencia a função comparar
	Print print;  // referencia a função imprimir
	Remover rem; // referencia a função remover
}sequencia;

sequencia *criar(int max, Comp c, Print p, Remover rem);
void destruir(sequencia **seq);
int inserir(sequencia *seq, void *valor);
void listar(sequencia *seq);
int buscar(sequencia *seq, void *chave);
void removerTodos(sequencia *seq, void *chave);
int remover(sequencia *seq, void *chave);

#endif
