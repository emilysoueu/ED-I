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
poligono *criarPolig(int );

//- inserção em ordem dos pontos do polígono 
int inserirPontos(poligono *, float , float ); 

//- imprimir polígono  (imprimir os pontos do polígono?????)
float printPoli(poligono *); 

//- obter tamanho dos lados do polígono e perímetro do poligono
int tamanhoLados(poligono *); 


//- destruir polígono
void destroiPol(poligono *);


 

	





