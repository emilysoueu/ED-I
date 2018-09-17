/** Simule com a Fila implementada em (1) uma fila de atendimento da coordenação. A fila da coordenação deve funcionar da seguinte maneira:
o tamanho máximo da fila é 20. Qualquer entrada a mais na fila deve ser descartada
para começar o atendimento, a fila deve possuir pelo menos 10 pessoas em espera
depois que começa o atendimento, novas pessoas entram na fila e sempre pessoas a mais tempo são atendidas
 */

#ifndef COORDENAC_H
#define COORDENAC_H

typedef struct _fila_{
	int *coor;
	int inicio;
	int fim ;
}fila;

//criar fila
fila *criar(int max);
// verifica se a fila esta vazia e retorna true caso contrario retorna false
bool isEmpty(fila *q);
// insere elementos na fila
int enfileira(fila *q, int dado);
//remove elementos da fila  (FIFO)
int pop(fila *q);

#endif
