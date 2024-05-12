#include <stdio.h>

typedef struct Node *Link;
struct Node {
  int data;
  Link next;
};

void insert(Link *list, int data){
  Link newNode = (Link)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = NULL;
  Link aux = *list;
  while(aux->next != NULL) aux = aux->next;
  aux->next = newNode;
}

void removeAll(Link *list, int data){
  Link auxPrev = *list;
  Link aux = *list;
  do{
    if(aux->data == data){
      auxPrev->next = aux->next;
      free(aux);
      aux = *list;
    }else{
      auxPrev = aux;
      aux = aux->next;
    }
  }
  while(aux != NULL);
}

void constructor(Link *list){
  (*list)->data = 0;
  (*list)->next = NULL;
}

int mainRemoverTodasOcorrencias(void) {
  Link list = (Link)malloc(sizeof(struct Node));
  constructor(&list);
  insert(&list, 1);  
  insert(&list, 3);
  insert(&list, 4);
  insert(&list, 7);
  insert(&list, 7);

  removeAll(&list, 7);

  Link aux = list->next;
  while(aux != NULL){
    printf("%d", aux->data);
    aux = aux->next;
  }

  return 0;
}