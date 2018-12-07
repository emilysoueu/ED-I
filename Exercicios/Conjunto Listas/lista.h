/*
Considerando conjuntos de valores inteiros, implementados numa lista duplamente encadeada, implemente as seguintes operações:

uniao (conjunto A, conjunto B) : o resultado fica em A. Lembre-se que união não pode ter repetição

intersecção (conjunto a A, conjunto B): o resultado fica em A

diferenca(conjunto A, conjunto B): o resultado fica em A
*/

typedef struct _Node_ {
  struct _Node_* next;
  struct _Node_* prev;
  int dado;
}Node;

typedef struct _Lista_ {
  Node* head;
  Node* tail;
}Lista;

Lista* criaLista ();
int destroiLista(Lista** l);

int insercao (Lista* a, int dado);
int remocao (Lista* a, int dado);

int busca (Lista* a, int dado);
void printaLista (Lista* a);

void uniao(Lista *a, Lista* b);
void interseccao (Lista* a, Lista* b);
//int diferenca (Lista* a, Lista* b);
