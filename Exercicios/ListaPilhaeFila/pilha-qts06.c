#include <stdio.h>
#include <stdlib.h>

typedef struct _Dequeue_{
	int *deq;
	int inicio;
	int fim;
	int qtd;
	int max;	
}dequeue;

dequeue *criar(int tam){
	dequeue *dq = (dequeue*)malloc(sizeof(dequeue));
	if ((dq == NULL) || (tam <= 0)) return NULL;
	
	dq -> deq = (int*)malloc(sizeof(int)*tam);
	if (dq -> deq == NULL) return NULL;
	
	dq -> inicio = 0;
	dq -> fim = tam -1; // posiciono dq na ultima posicao do vetor
	dq -> qtd = 0;
	dq -> max = tam;// acho q deve ser tam/2
	
	return dq;
}

// insere elementos no inicio do vetor
void insere_beg(dequeue *dq, int valor){
	if ((dq == NULL) || (dq -> deq) == NULL) printf ("NAO ALOCADO\n");
	
	dq-> deq[dq -> inicio] = valor;
	printf("Inserido no inicio \n");
	dq -> inicio ++;
		if (dq ->inicio == dq->max) // vetor circular??
			inicio = 0; 
	dq -> qtd ++;
	
}

// insere elementos no fim do vetor
void insere_end(dequeue *dq, int valor){
	if ((dq == NULL) || (dq -> deq) == NULL) printf ("NAO ALOCADO\n");
	
	dq-> deq[dq -> fim] = valor;
	printf("Inserido no fim \n");

	dq -> fim --; // como seria vetor circular aqui?
	dq -> qtd ++;
}

// remove elementos do inicio do vetor
int remove_beg(dequeue *dq){
	if ((dq == NULL) || (dq -> deq) == NULL) printf ("NAO ALOCADO\n");
	
	int x;
	x = dq -> deq[dq -> inicio];
	dq -> inicio --;
	dq -> qtd --;
	
	return x;	
}

// remove elementos do fim do vetor
int remove_end(dequeue *dq){
	if ((dq == NULL) || (dq -> deq) == NULL) printf ("NAO ALOCADO\n");
	
	int x;
	x = dq -> deq[dq -> fim];
	dq -> fim ++;
	dq -> qtd --;
	
	return x;
}

int main(){
	int max; // informado pelo user
	int beg, end;
	
	dequeue *dq = criar(max);
	
	insere_beg(dq,1);
	insere_beg(dq,2);
	insere_end(dq,10);
	insere_end(dq,20);
	
	beg = remove_beg(dq);
	printf("%d\n", beg);
	beg = remove_beg(dq);
	printf("%d\n", beg);
	end = remove_beg(dq);
	printf("%d\n", end);
	end = remove_beg(dq);
	printf("%d\n", end);
	
	// concertar algumas parads na remover ou inserir mas ta ok
	// limitar pra não preencher no espaço do outro
	
}
