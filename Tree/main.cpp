
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <cstring>
#include <string>
//#include "tree.cpp"
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
		  
        // ******************** Dados Padrão para fins de teste *************************/
        colaborador *c1 = new colaborador;
        c1->nome = "africa";
        c1->dtsaida = "03/10/2190";
        c1->dtentrada = "09/10/1992";

        colaborador *c2 = new colaborador;
        c2->nome = "zeus";
        c2->dtsaida = "03/10/2006";
        c2->dtentrada = "09/10/1987";

        colaborador *c3 = new colaborador;
        c3->nome = "perseu";
        c3->dtsaida = "03/10/2700";
        c3->dtentrada = "09/10/1956";

       // ******************** Dados Padrão para fins de teste *************************/


		
	  //************************* Entrada do Usuário ******************************//

		
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
        
      //************************* Entrada do Usuário ******************************//
 


        
        //************************ Inserindo na Lista de BD ***********************/
        insert(bancoDados,c1); // funcionários padrão (fins de teste)
        insert(bancoDados,c2); // funcionários padrão (fins de teste)
        insert(bancoDados,c3); // funcionários padrão (fins de teste)
        
        insert(bancoDados,novo); // ENtrada do usuário
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
            colaborador *temp0;
            

            cout << "Informe o nome que deseja alterar: "<<endl;
            cin >> name;
            temp0 = busca(nomesCol,name);// guardando endereço de memoria

            //cout<<temp0<<endl; //imprimindo endereço de memoria

            if (temp0 == NULL){ 
              cout << "O nome informado nao esta cadastrado" <<endl;
            }else{             
              cout << "Informe o novo nome:"<<endl;
              cin >> novoNome;              
              temp0->nome = novoNome;

              deleteNode(nomesCol,name);
              inserirTree(nomesCol, temp0->nome, temp0);

              cout<<"\n**********NOVA ARVORE ********\n";// in order
              inOrdem(nomesCol);
              cout<<endl;
                                  
            }
          }
          break; //fim case 1[edição]
          case 2:{
            colaborador* temp0;
            string  input;
            string  novoInput;
            
            cout << "Informe a data de entrada que deseja alterar: ";
            cin >> input;

            temp0 = busca(inputCol,input);// guardando endereço de memoria


            if (temp0 == NULL){ 
              cout << "A data informada nao esta cadastrado" <<endl;
            }else{
              cout << "Informe a nova data de entrada:"<<endl;
              cin >> novoInput;
              temp0->dtentrada = novoInput;

              deleteNode(inputCol,input);
              inserirTree(inputCol, temp0->dtentrada, temp0);

              cout<<"\n**********NOVA ARVORES********\n"; //In Order
              inOrdem(inputCol);
              cout<<endl;  
            }

          }break;//fim case 2[edição]
          case 3:{
            colaborador* temp0;
            string name,output;
            string novoOutput;
            cout << "Informe a data de saida que deseja alterar: "<<endl;           
            cin >>output;
            temp0 = busca(outputCol,output);// guardando endereço de memoria


            if (temp0 == NULL){ 
              cout << "A data informada nao esta cadastrado" <<endl;
            }else{
              cout << "Informe a nova data de saida:"<<endl;
              cin >> novoOutput;
              temp0->dtsaida = novoOutput;              

              deleteNode(outputCol,name);
              inserirTree(outputCol, temp0->dtsaida, temp0);

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
