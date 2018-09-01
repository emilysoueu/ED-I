/**
TAD para manipular dados em sequencia vetor
*/

#ifdef TAD- sequencia
#define TAD - sequencia

///Cria o TAD sequencia 
sequencia* criar(sequencia* seq, int dado);

/// Insere novo elemento na sequencia se houver espaço
int insert (sequencia* seq, int dado);

///Procura e Remove elemento na sequencia
int apagar(sequencia* seq, int dado);

///Procura elemento na sequencia
int procura(sequencia* seq, int dado);

///Apaga Totalmente a sequencia
int apagarTudo(sequencia* seq);

#endif