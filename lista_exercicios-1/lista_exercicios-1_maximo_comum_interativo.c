#include <stdio.h>
#include <stdbool.h>

int multArr(int *v, int size){
  int response = 1;
  for(int i = 0; i<size; i++){
    response *= v[i];
  }
  return response;
}

int maximoComum(int v1, int v2){
  const int sizeDivisores = 20;
  int divisores [sizeDivisores];
  int indexDivisores = 0;
  int divisor = 2;
  while(v1 != 1 && v2 != 1){
    if(v1 % divisor == 0 && v2 %divisor == 0){
      divisores[indexDivisores++] = divisor;
      v1 /= divisor;      
      v2 /= divisor;
    }
    else if(v1%divisor == 0)
     v1 /= divisor;      
    else if(v2%divisor == 0)
      v2 /= divisor;      
    else
      divisor++;
  }

  return multArr(divisores, indexDivisores);
}

int mainMaximoComumInterativo(void) {
  int v1,v2 = 0;
  v1 = 45;
  v2 = 63;
  printf("o valor máximo comum entre %d e %d é %d",v1,v2,maximoComum(v1, v2));
  return 0;
}