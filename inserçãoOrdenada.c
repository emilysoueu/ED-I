int insere(fila *f, int valor){
	int i;

	if (seq == NULL) return 0;

	for(i=0; i<seq ->max; i++){
		if (seq ->qtd == 0){ // se o meu tad estiver vazio
			seq ->dados[i] = valor; // insere o valor na primeira posição
			seq -> qtd++;
		}else if((seq ->qtd != 0) || (seq -> qtd >= seq->qtd max)){ // caso o meu TAD não esteja vazio
			if (seq -> dados[i] == NULL){ // inserir novos elementos na posição nula;				
				if (seq -> comp(seq ->dados[i-1], valor) == 1){ ///(a > b) = 1, (a<b) = -1, (a==b) = 0; // comparar o elemento anterior se eh maior
					int *aux = (int*)seq->dados[i-1]; ///var pra aux na troca de valores
					seq ->dados[i-1] = valor;
					seq ->dados[i] = aux;	
					// se o ultimo elemento inserido for menor que o novo elemento não faz nada apenas insere;			
				}else if (seq -> comp(seq ->dados[i], valor) == -1){ ///(a > b) = 1, (a<b) = -1, (a==b) = 0;
					     seq ->dados[i] = valor;	
				}				
			}

		}

	}
}