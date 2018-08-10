#include <stdio.h>
#include <stdlib.h>

typedef struct _Lista_{
  int data;
  struct _Lista_ *next;
}List;

List* newNode();
void insertNode(List ** cab, int data);
void printList(List *head);
void removeList(List *head);

int main(){

}



List* newNode(){
  List* new = malloc(sizeof(List));

  if (new == NULL){
    return new;
  }

  new -> data = data;
  new -> next = NULL;
  
  return new;
}

void insertNode(List ** cab, int data){
  List *head = new;

  if (*head == NULL){
    *head = new;
  }else{
    List* tmp = new;
        while(tmp -> next != NULL){
          tmp = tmp -> next;
        }
     tmp -> next = new;

  } 

}



void printList(List *head){
  if (head == NULL){
    printf("List is empty");
  return;
  }

  while (head != NULL){
      printf("%d", head -> data);
  }
  tmp = tmp -> next;
}

void removeList(List *head){
    List * aux;
    while (head !- NULL){}
      aux = head;
      head = head -> next;
      free(aux);
  }
}
