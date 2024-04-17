#include <stdio.h>
#include <stdbool.h>

int maximoComumRecursivo(int v1, int v2, int divisor){
    printf("%d %d  %d\n", v1,v2, divisor);
  if(v1 == 1 && v2 == 1)
    return 1;
  
  bool divisivelPelos2 = false;
  if(v1%divisor == 0 && v2%divisor == 0){
    v1 /=divisor;
    v2/=divisor;
    divisivelPelos2 = true;
  }
  else if(v1%divisor == 0)
    v1 /= divisor;
  else if(v2%divisor == 0)
    v2 /= divisor;
  else
    divisor++;
  
  int divisorAnterior = maximoComumRecursivo(v1, v2,divisor);
  
    return divisivelPelos2? divisor*divisorAnterior:divisorAnterior;

}

int main(void) {
  int v1,v2 = 0;
  v1 = 45;
  v2 = 63;
  printf("o valor máximo comum entre %d e %d é %d",v1,v2,maximoComumRecursivo(v1, v2,2));
  return 0;
}