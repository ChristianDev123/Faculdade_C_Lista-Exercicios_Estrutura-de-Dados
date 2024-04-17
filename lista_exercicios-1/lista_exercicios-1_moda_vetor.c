#include <stdio.h>
#include <stdbool.h>
int max(int *v, int size) {
  if (size == 1)
    return v[0];
  int maxValue = max(v, size - 1);
  return v[size - 1] > maxValue ? v[size - 1] : maxValue;
}

int findIndex(int *v, int size, int data){
  if(size == 1)
    return v[0] == data?0:-1;
  int index = findIndex(v,size-1,data);
  if(v[size-1] == data)
    return size-1;
  else if(index != -1)
    return index;
  return -1;
}

int calculaModa(int *v, int size) {
  int auxArr[size];
  int auxIndex = 0;
  for (int i = 0; i < size; i++)
    auxArr[i] = 0;
  
  for (int i = 0; i < size; i++) {
    int indexFinded = findIndex(v,size,v[i]);
    auxIndex = indexFinded;
    auxArr[auxIndex]++;
  }

  return v[findIndex(auxArr,size,max(auxArr, size))];
}

int main(void) {
  const int size = 5;
  int data[size] = {3, 7, 7, 3, 7};
  printf("a moda do vertor é o elemento %d", calculaModa(data, size));
  return 0;
}