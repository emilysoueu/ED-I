
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
    cout << " ***********************************"<<endl;
    cout << "* [1] Inserir Dados do Colaborador * "<<endl;
    cout << "* [2] Editar  Dados do Colaborador * "<<endl;
    cout << "* [3] Buscar  Dados do Colaborador *"<<endl;
    cout << "* [0] Sair                         *"<<endl;
    cout << " ***********************************"<<endl;
    cout << "Sua Opcao: ";
    cin >> menu;
    cout <<endl;
    switch (menu){
    //########################## INSERIR COLABORADOR #########################//

      case 1:{
        string nome, entrada, saida, matricula;
        
        colaborador *novo = new colaborador;

        cout << "Insira o nome:"<<endl;
        cin >> nome;
        novo->nome = nome;
        cout << "Insira o numero de matricula: "<<endl;
        cin >> matricula;
        novo->matricula = matricula;
        cout << "Insira a data de entrada: "<<endl;
        cin >> entrada;
        novo->dtentrada = entrada;
        cout << "Insira a data de saida: "<<endl;
        cin >> saida;
        novo ->dtsaida = saida;     


        
        //************************ Inserindo na Lista de BD ***********************/
        insert(bancoDados,novo); 
        //************************ Inserindo na Lista de BD ***********************//


         //********************** Criando/Inserindo Arvore de Dados *********************///       
      
        node* tempCab = bancoDados->cab;
        nomesCol = criaTree(tempCab->dado->nome, tempCab->dado);
        inputCol = criaTree(tempCab->dado->dtentrada, tempCab->dado);
        outputCol = criaTree(tempCab->dado->dtsaida, tempCab->dado);


       
        node* temp = tempCab->prox;
        while(temp!=NULL){
          inserirTree(nomesCol, temp->dado->nome, temp->dado);// Árvore de nomes
          inserirTree(inputCol, temp->dado->dtentrada, temp->dado);// Árvore de entradas
          inserirTree(outputCol, temp->dado->dtsaida, temp->dado); //Árvore de Saída
          temp = temp->prox;
        }

        //cout << "\n\nIMPRESSAO LISTA:\n"<<endl;

        
       
        //print(bancoDados);
       
        cout<<"\n**********ARVORE DE NOMES********\n";
        inOrdem(nomesCol);
        cout <<endl;
        cout<<"\n**********ARVORE DE NOMES********\n";

        cout<<"\n**********ARVORE DE ENTRADA DOS COLABORADORES********\n";
        cout<<"\nENTRADA DOS COLABORADORES:\n";
        inOrdem(inputCol);
        cout <<endl;
        cout<<"\n**********ARVORE DE ENTRADA DOS COLABORADORES********\n";

        cout<<"\n**********ARVORE DE SAIDA DOS COLABORADORES********\n";
        cout<<"\nSAIDA DOS COLABORADORES:\n";
        inOrdem(outputCol);  
        cout <<endl; 
        cout<<"\n**********ARVORE DE SAIDA DOS COLABORADORES********\n";

        cout<<"\n\n";

      }break; //fim case 1[externo]
     //########################## INSERIR COLABORADOR #########################\\

     //########################## EDITAR  COLABORADOR #########################\\

      case 2:{

        int op;
        cout << " ***********************************"<<endl;
        cout << " * [1] Editar Nome do Colaborador   *"<< endl;
        cout << " * [2] Editar Data de Entrada       *"<< endl;
        cout << " * [3] Editar Data de Saida         *"<< endl;
        cout << " ***********************************"<<endl;
        cout << "Sua Opcao: ";
        cin >> op;
        cout <<endl;
        switch(op){
          case 1:{
            string name, novoNome;
            colaborador *temp0, *temp02;
            

            cout << "Informe o nome que deseja alterar: "<<endl;
            cin >> name;
            temp0 = busca(nomesCol,name);// guardando endereço de memoria

            //cout<<temp0<<endl; //imprimindo endereço de memoria

            if (temp0 == NULL){ 
              cout << "O nome informado nao esta cadastrado" <<endl;
            }else{
              //temp02 = temp0;
              cout << "Informe o novo nome:"<<endl;
              cin >> novoNome;
              //temp02->nome = novoNome; 
              temp0->nome = novoNome;

              
              // pq não usa mais o temp02???

              //impressão de lista  após alteração dos dados 
              cout << "\n\nIMPRESSAO LISTA APOS ALTERACAO\n"<<endl;
              node *temp25 = bancoDados->cab; 

              while(temp25!=NULL){
              cout<<temp25->dado->nome<<endl;        
              temp25 = temp25->prox;

              cout<<"\n\n";

              deleteNode(nomesCol,name);
              inserirTree(nomesCol, temp0->nome, temp0);

              cout<<"\n**********NOVA ARVORE ********\n";// in order
              inOrdem(nomesCol);
              cout<<endl;
              }                     
            }
          }
          break; //fim case 1[edição]
          case 2:{
            colaborador* temp0;

            string name,input;
            string  novoInput;
            cout << "Informe o nome do colaborador para alterar a data de entrada: ";
            cin >> name;

            temp0 = busca(inputCol,name);// guardando endereço de memoria


            if (temp0 == NULL){ 
              cout << "O nome informado nao esta cadastrado" <<endl;
            }else{
              //temp02 = temp0;
              cout << "Informe a nova data de entrada:"<<endl;
              cin >> novoInput;
              //temp02->nome = novoNome; 
              temp0->nome = novoInput;

              deleteNode(inputCol,name);
              inserirTree(inputCol, temp0->nome, temp0);

              cout<<"\n**********NOVA ARVORES********\n"; //In Order
              inOrdem(inputCol);
              cout<<endl;  
            }

          }break;//fim case 2[edição]
          case 3:{
            colaborador* temp0;
            string name,output;
            string novoOutput;
            cout << "Informe o nome do colaborador para alterar a data de saida: ";
            cin >> name;
            temp0 = busca(outputCol,name);

            if (temp0 == NULL){ 
              cout << "O nome informado nao esta cadastrado" <<endl;
            }else{
              //temp02 = temp0;
              cout << "Informe a nova data de saida:"<<endl;
              cin >> novoOutput;
              //temp02->nome = novoNome; 
              temp0->nome = novoOutput;              

              deleteNode(outputCol,name);
              inserirTree(outputCol, temp0->nome, temp0);

              cout<<"\n**********NOVA ARVORE********\n"; // IN ORDER
              inOrdem(outputCol);
              cout<<endl;  
            }                    

          }break; //fim case 3[edição]

        }// fim switch[edição ]

      }break; //fim case 2[externo]
      //########################## EDITAR  COLABORADOR #########################//

      //########################## BUSCAR  COLABORADOR #########################//


      case 3:{
        int opMenu;

        cout << " ***********************************"<<endl;
        cout << "* [1] Consultar por Nome           *"<<endl;
        cout << "* [2] Consultar por Data de entrada*"<<endl;
        cout << "* [3] Consultar por Data de saida  *"<<endl;
        cout << " ***********************************"<<endl;
        cout << "Sua Opcao:";
        cin >> opMenu;
        cout <<endl;

        switch(opMenu){
          case 1:{
            string name;  
            cout << "Informe o nome de colaborador:"<<endl;
            cin >> name; 
            colaborador* NOME = busca(nomesCol,name);

            if (NOME != NULL){
              cout << "Nome: "<< NOME->nome<<endl;
              cout << "Data de Entrada: "<< NOME->dtentrada<<endl;
              cout << "Data de Saída: "<< NOME->dtsaida<<endl;
              cout<<endl;
            }else{
              cout << "\nO nome informado nao esta cadastrado"<<endl;
            }       

          }break; //fim case 1[busca]

          case 2:{

            string input;
            cout << "Informe a data de entrada:"<<endl;
            cin >> input;
            colaborador* ENTRADA = busca(inputCol,input);

            if (ENTRADA != NULL){ //  árvore de entradas
              cout << "Nome: "<< ENTRADA->nome<<endl;
              cout << "Data de Entrada: "<< ENTRADA->dtentrada<<endl;
              cout << "Data de Saída: "<< ENTRADA->dtsaida<<endl;
              cout<<endl;
            }else{
              cout << "\nA data informada nao esta cadastrada"<<endl;
            } 


          }break;//fim case 2[busca]

          case 3:{
            string output;
            cout << "Informe a data de saida:"<<endl;
            cin >> output;
            colaborador* SAIDA = busca(outputCol,output);

            if (SAIDA!= NULL){ //  árvore de Saida
              cout << "Nome: "<< SAIDA->nome<<endl;
              cout << "Data de Entrada: "<< SAIDA->dtentrada<<endl;
              cout << "Data de Saída: "<< SAIDA->dtsaida<<endl;
              cout<<endl;
            }else{
              cout << "\nA data informada nao esta cadastrada"<<endl;
            } 

          }break;//fim case 3[busca]


        }break; //fim switch[busca]

      }break; //fim case 3[externo]
      //########################## BUSCAR  COLABORADOR #########################//

    }// fim switch menu


  }while(menu != 0);// fim do-while


}// fim main