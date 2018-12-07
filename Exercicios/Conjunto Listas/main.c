#include <stdio.h>
#include <stdlib.h>
//#include "lista.h"
#include "lista.c"

int main(void) {

  Lista* l1 = criaLista();
  
  for (int i = 1; i <= 15; i++){
    insercao(l1, i); 
  }

 printaLista(l1);
  
  Lista* l2 = criaLista();
  
  for (int i = 10; i <= 20; i++){
    insercao(l2, i); 
  }

  printaLista(l2);

  interseccao(l1, l2);

  printf("Tudo ok!!\n");
  
  printaLista(l1);

  return 0;
}
