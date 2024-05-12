#include <stdio.h>

typedef struct Node *Link;
struct Node {
  int id;
  Link next;
};

void insert(Link *list, int id){
  Link newNode = (Link)malloc(sizeof(struct Node));
  newNode->id = id;
  if(*list == NULL){
    newNode->next = newNode;
    *list = newNode;
  }
  else{
    Link aux = *list;
    while(aux->next != *list) aux = aux->next;
    newNode->next = aux->next;
    aux->next = newNode;
  }
}

void printList(Link list){
  Link aux = list;
  do{
    printf("%d\n", aux->id);
    aux = aux->next;
  }
  while(aux != list);
}

void removeElementList(Link *list, Link element){
  if((*list)->next == *list) return;
  Link previous = NULL, current = *list;
  do{
    if(current == element) break;
    previous = current;
    current = current->next;
  }while(current != *list);
  if(previous != NULL) previous->next = current->next;
  else {
    Link r = *list;
    while(r->next != *list) r = r->next;
    r->next = (*list)->next;
    *list = (*list)->next;
  }
  free(current);
}

void JosephusProblem(Link *list, int initId){
  Link aux = *list;
  do{
    if(aux->id == initId) break;
    aux = aux->next;
  }
  while(aux != *list);
  Link aux2 = aux;

  while(aux2->next != aux2){
    aux = aux2;
    aux2 = aux2->next;
    removeElementList(list, aux);
  }
}

int main(void){
  Link list = NULL;
  for(int i = 1; i <= 10; i++)
    insert(&list, i);
  JosephusProblem(&list, 9);
  printf("o líder é o id: %d", list->id);
  return 0;
}