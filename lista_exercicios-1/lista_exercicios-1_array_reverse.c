#include <stdio.h>
#include <stdbool.h>

void swap(int *v, int i1, int i2){
  int aux = v[i1];
  v[i1] = v[i2];
  v[i2] = aux;
}

void reverse(int *v,int index, int size){
  if(size == 1){
    swap(v,0,index);
    return;
  }
  reverse(v, index+1, size-1);
  swap(v,size-1,index);
}

int main(void) {
  const int size = 5;
  int data [size] = {5,4,3,2,1};
  reverse(data, 0, size);
  for(int i = 0; i < size; i++){
    printf("%d ", data[i]);
  }
  return 0;
}