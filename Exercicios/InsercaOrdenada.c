/** =======Algoritmo======
 * 1.) pesquisar posição onde inserir novo elemento (pesquisa sequencial)
 * 2.) realocar memoria para mais um elemento
 * 3.) avançar um posição todos os elementos do vetor
 * 4.) Inserir novo elemento
 * 
 * =======Resolução=======
 * 
 */
 // pesquisar
 
 int pesquisarPosInsercao(int elm, int V[], int tam){
	 int i=0, k = -1; // k = pos inserir novo elemento
	 
	 while ((i<tam) && (k == -1)){
		 if(elm == V[i]){
			 k = i;
		 }else{
			 if(V[i] < elm){
				 i+=1;
			 }else{
				 k=i;
			 }
		 }
	 }
	 return k;
}

// inserir novo elemento

int* inserirElemento(int elm, int V[], int *tam){
	int pos, i;
	pos = pesquisarPosInsercao(elm, V[], int *tam);
	*tam +=1;// aumenta em 1 unidade o tamanho do vetor;
	V = (int*) realloc(*tam, sizeof(int));
		if (pos >= 0){ // avançar 1 posição no vetor desde pos
			for(i= *tam-1; i>pos; i--){
				V[i] = V[i-1]
			}else{
				pos = *tam-1;
		}
	V[pos] = elm; // inserir novo elemento;
	return V;
}
