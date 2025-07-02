#include <stdio.h>

long unsigned int factorial(int n) {
  if(n==1 || n==0)
    // caso base
    return 1;
  // caso recursivo            
  return factorial(--n) * n;   
}

int main() {
  int num;
  do {
    printf("Ingrese numero mayor o igual a cero para calcular su factorial: ");
    scanf("%d", &num);
  } while(num < 0);


  printf("El factorial del numero %d es %lu \n\n", num, factorial(num));
  return 0;
}
