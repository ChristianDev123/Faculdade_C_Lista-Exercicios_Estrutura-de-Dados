#include <stdio.h>
#include <string.h>
#include <stdbool.h>

const int MAX = 100;

typedef struct {
  int top;
  char words [MAX][1];
} STACK;

void push(STACK *stack, char letter){
  if(stack->top != MAX-1)
    stack->words[++stack->top][0] = letter;
}

void pop(STACK *stack, char *copyLetter){
  if(stack->top != -1)
    *copyLetter = stack->words[stack->top--][0];
}

void printStack(STACK stack){
  for(int i = stack.top; i >= 0; i--)
    printf("%c ",stack.words[i][0]);
  printf("\n");
}

void constructor(STACK *stack){
  stack->top = -1;
}

bool verificaPalindromo(STACK stack, char *word){
  bool response = true;
  char letter;
  int indexWord = 0;
  for(int i = strlen(word); i >0; i--){
    pop(&stack, &letter);
    if(stack.words[indexWord++][0] != letter)
      return false;
  }
  return response;
}

int main(void) {
  STACK stack;
  constructor(&stack);

  char *word = "ovo";
  for(int i = 0; i < strlen(word);i++)
    push(&stack,word[i]);

  printf("%s %s",word, verificaPalindromo(stack,word)?"é um palíndromo!":"não é um palíndromo!");

  return 0;
}