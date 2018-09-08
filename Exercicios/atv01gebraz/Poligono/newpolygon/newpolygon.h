
/*b) Modifique o TAD dado em sala de aula para armazenar coordenadas (dois valores float). 
  Chame o TAD de polígono. Especifique num .h as funcionalidades desse TAD: 

  - criar polígono

  - inserção em ordem dos pontos do polígono

  - imprimir polígono

  - obter tamanho dos lados do polígono

  - obter perímetro do polígono

  - destruir polígono

Depois implemente as funções do TAD.
*/

/* Cria o TAD poligono;
 * @parametro size o tamanho desejado
 * return um ponteiro para um poligono vazio
 */
 #define TRUE 1
 #define FALSE 0
 
  #ifndef POLIGONO_H
    #define POLIGONO_H
    
   typedef struct _poligono_{
	   int **vecpoli;  // matriz para o poligono
	   int qtdPontos; // condição de parada do for
	   int atual;    // controlar a movimentação dentro da matriz
   }poligono;
   
    poligono *criarPolig(int qtdpontos);   
    int inserirPontos(poligono* pol);   
    int imprimirPoligono(poligono *pol);
    int tamanhoLados(poligono *pol);
    int destruirPol(poligono *pol);

#endif


 

	






