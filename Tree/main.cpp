
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <cstring>
#include <string>
#include "tree.h"

using namespace std;

void print(lista *banco){
  node *print2 = banco->cab;
  while(print2!=NULL){
    cout<<print2->dado->nome<<endl;
    print2 = print2->prox;    
  }
}

int main() {
  int menu;

  // ****************** Árvores Binárias de Pesquisa **************************//
  dado* nomesCol = NULL; // árvore de nomes dos colaboradores
  dado* inputCol = NULL; // árvore de datas de entrada dos colaboradores
  dado* outputCol = NULL; // árvores de saída dos colaboradores
  // ****************** Árvores Binárias de Pesquisa **************************//


  lista* bancoDados = criar(); //criando a lista que possui o banco de dados do laboratorio 
  
  
  do{
    cout << "Inserir[1]"<<endl;
    cout << "Editar[2]"<<endl;
    cout << "Buscar[3]"<<endl;
    cout << "Sair[0]"<<endl;
    cin >> menu;
    switch (menu){
      case 1:{

        colaborador *aux =  new colaborador[1];
        
        colaborador *aux0 = new colaborador[1];
        aux0->nome = "fernando";
        aux0->dtsaida = "07/10/2100";
        aux0->dtentrada = "07/10/1992";

        colaborador *aux1 = new colaborador[1];
        aux1->nome = "henrique";
        aux1->dtsaida = "07/10/2086";
        aux1->dtentrada = "07/10/1987";

        colaborador *aux2 = new colaborador[1];
        aux2->nome = "benjamin";
        aux2->dtsaida = "07/10/2974";
        aux2->dtentrada = "07/10/1956";

        
        //************************ Inserindo na Lista de BD ***********************//
        insert(bancoDados,aux0);
        insert(bancoDados,aux1);
        insert(bancoDados,aux2);         
      
        node* temp = bancoDados->cab;

        //********************** Criando Arvore de Dados *********************//
        nomesCol = criaTree(temp->dado->nome, temp->dado);
        inputCol = criaTree(temp->dado->dtentrada, temp->dado);
        outputCol = criaTree(temp->dado->dtsaida, temp->dado);

        cout << "\n\nIMPRESSAO LISTA:\n"<<endl;

        //********************** Inserindo nas Arvore de Dados *********************//
        while(temp->prox!=NULL){
          temp = temp->prox;        
          inserirTree(nomesCol, temp->dado->nome, temp->dado);// Árvore de nomes
          inserirTree(inputCol, temp->dado->dtentrada, temp->dado);// Árvore de entradas
          inserirTree(outputCol, temp->dado->dtsaida, temp->dado); //Árvore de Saída

        }

        print(bancoDados);
       
        cout<<"\n**********ARVORES********\n";
        cout<<"\nNOMES DOS COLABORADORES:\n";
        inOrdem(nomesCol);
        cout <<endl;

        cout<<"\nENTRADA DOS COLABORADORES:\n";
        inOrdem(inputCol);
        cout <<endl;

        cout<<"\nSAIDA DOS COLABORADORES:\n";
        inOrdem(outputCol);  
        cout <<endl; 
        cout<<"\n**********ARVORES********\n";   
        
        cout<<"\n\n";

      }break; //fim case 1[externo]
      case 2:{

        int op;
        cout << "editar nome[1]"<< endl;
        cout << "editar data entrada[2] "<< endl;
        cout << "editar data de saida[3] "<< endl;
        cin >> op;
        switch(op){
          case 1:{
            string name, novoNome;
            colaborador *temp0, *temp02;

            cout << "Informe o nome que deseja alterar: "<<endl;
            cin >> name;
            temp0 = busca(nomesCol,name);// guardando endereço de memoria
            cout<<temp0<<endl; //imprimindo endereço de memoria

            if (temp0 == NULL){ 
              cout << "O nome informado nao esta cadastrado" <<endl;
            }else{
              temp02 = temp0;
              cout << "Informe o novo nome:"<<endl;
              cin >> novoNome;
              temp02->nome = novoNome; 

              //impressão de lista  após alteração dos dados 
              cout << "\n\nIMPRESSAO LISTA APOS ALTERACAO\n"<<endl;
              node *temp25 = bancoDados->cab; 

              while(temp25!=NULL){
              cout<<temp25->dado->nome<<endl;        
              temp25 = temp25->prox;

              cout<<"\n\n";
              }
                     
            }

          }
          break; //fim case 1[edição]
          case 2:{
            string name,input;
            string  novoInput;
            cout << "Informe o nome que deseja alterar a data de entrada: ";
            cin >> name;
            cout << "Informe a nova data de entrada:"<<endl;
            cin >> novoInput;
          }break;//fim case 2[edição]
          case 3:{
            string name,output;
            string novoOutput;
            cout << "Informe o nome que deseja alterar a data de saida: ";
            cin >> name;
            cout << "Informe a nova data de saida:"<<endl;
            cin >> novoOutput;         

          }break; //fim case 3[edição]

        }// fim switch[edição ]


      }break; //fim case 2[externo]
      case 3:{
        int opMenu;

        cout << "Consultar por Nome[1]"<<endl;
        cout << "Consultar por Data de entrada[2]"<<endl;
        cout << "Consultar por Data de saida[3]"<<endl;
        cin >> opMenu;

        switch(opMenu){
          case 1:{
            string name;  
            cout << "Informe o nome de colaborador:"<<endl;
            cin >> name;      
            if (busca(nomesCol,name)){
              cout << "\nAchou!"<<endl;
            }else{
              cout << "\nNao Achou"<<endl;
            }       

          }break; //fim case 1[busca]

          case 2:{

            string input;
            cout << "Informe a data de entrada:"<<endl;
            cin >> input;

            if (busca(inputCol,input)){ //  árvore de entradas
            cout << "\nAchou!"<<endl;
            }else{
              cout << "\nNao Achou"<<endl;
            } 


          }break;//fim case 2[busca]

          case 3:{
            string output;
            cout << "Informe a data de saida:"<<endl;
            cin >> output;

            if (busca(outputCol,output)){ //  árvore de Saida
            cout << "\nAchou!"<<endl;
            }else{
              cout << "\nNao Achou"<<endl;
            } 

          }break;//fim case 3[busca]


        }break; //fim swictch[busca]

      }break; //fim case 3[externo]

    }// fim switch menu


  }while(menu != 0);// fim do-while


}// fim main