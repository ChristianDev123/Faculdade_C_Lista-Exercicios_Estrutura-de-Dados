#include <stdio.h>
#include <math.h>

typedef struct Node *Link;
struct Node {
  int produto;
  int exponencial;
  Link next; 
};

void constructor(Link *list){
  (*list)->next = *list;
  (*list)->exponencial = -1;
}

void insert(Link *list, int produto, int exponencial){
  Link newNode = (Link)malloc(sizeof(struct Node));
  newNode->exponencial = exponencial;
  newNode->produto = produto;

  Link aux = *list;
  while(aux->next != *list) aux = aux->next;
  newNode->next = aux->next;
  aux->next = newNode;
}

double calcular(Link list, int x){
  Link aux = list;
  double response = 0;
  do{
    response += aux->produto * pow(x,aux->exponencial);
    aux = aux->next;
  }while(aux != list);
  return response;
}


int main(void){
  Link lista = (Link)malloc(sizeof(struct Node));
  constructor(&lista);
  insert(&lista, 1,1);        
  insert(&lista, 2,2);
  insert(&lista, 3,3);
  printf("resposta do polinômio: %2.f\n", calcular(lista,10));

  Link aux = lista;
  do{
    printf("%dX^%d\n",aux->produto,aux->exponencial);
    aux = aux->next;
  }while(aux != lista);

  return 0;
}