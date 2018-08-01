///1. Escreva o código das funções colocanafila, tiradafila, filavazia e filacheia.
#include <stdio.h>
#include <stdlib.h>

#define N 100

int fila[N];
int p, u;

void criafila (void);
void colocanafila (int y);
int tiradafila (void);
int filavazia (void);
int filacheia (void);

void criafila (void) {
   p = 0;
   u = 0;
}

void colocanafila (int y) {
   fila[u++] = y;
}

int tiradafila (void) {
   return fila[p++];
}

int filavazia (void) {
   return p >= u;
}

int filacheia (void) {
   return u > N;
}


