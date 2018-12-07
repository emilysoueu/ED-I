
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
using namespace std;


typedef struct _colaborador{
	string nome;
	string dtentrada;
	string dtsaida;
	string matricula;
}colaborador;

typedef struct _dado_{
    string chave; /*Dado a ser pesquisado: [dado][dataEntrada][dataSaida]*/
    struct _dado_* direita; 
    struct _dado_* esquerda; 
    int tipo; // ??
	colaborador* ptcolaborador; /*Guarda a referencia para o banco de Dados*/
}dado;

//==================Estruturas para o Banco de Dados ======================//


typedef struct _node_{ // caixinha
	colaborador* dado;
	struct _node_ * prev;
	struct _node_ * prox;
} node;

typedef struct _lista_{ // lista
	node *cab;
	node *fim;
} lista;

lista *criar();
void insert(lista *l, colaborador* nome);


//==================Estruturas para Árvores de Pesquisas ======================//


colaborador* busca(dado* raiz, string name);


dado* criaTree(string name, colaborador *ptrcolaborador);
//dado* insert(dado* pai, char *name, colaborador **ptrcolaborador);

//dado* insert(dado* pai, int ptcolaborador);
dado* inserirTree(dado* pai, string name, colaborador *vetorcolaborador);


void inOrdem(dado *raiz);

void preOrdem(dado *raiz);

//dado* FindMin(dado* raiz); // ffunção orginal
colaborador* FindMin(dado* raiz); // fins de teste

//dado* removeNode(dado* root, string key); //ORIGINAL
colaborador* removeNode(dado* root, string key);//TESTE
void buscaF(dado** raiz);






