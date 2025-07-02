
/*
Combinaciones

Se llama combinaciones de n elementos tomados de m en m con n>m a todas las 
agrupaciones posibles que pueden hacerse con los n elementos de forma que:

- No entran todos los elementos.
- No importa el orden.
- No se repiten los elementos.

Ejemplo 
1)
  C(4,2) = 6 
  n=4 conjunto de 4 elementos = {A,B,C,D}
  m=2 tomados de a 2 elementos
  posibles combinaciones = 6 {AB,AC,AD,BC,BD,CD}

2)
  C(5,3) = 10
  n=5 conjunto de 5 elementos = {A,B,C,D,E}
  m=3 tomados de a 3 elementos
  posibles combinaciones = 10 {ABC,ABD,ABE,ACD,ACE,ADE,BCD,BCE,BDE,CDE}


Triangulo de Pascal

n=0  1
n=1  1  1
n=2  1  2  1
n=3  1  3  3   1
n=4  1  4  6   4   1
n=5  1  5  10  10  5  1

m -> 0  1  2   3   4  5


Definición
 C(n, 0) = 1                          para n>=0
 C(n, n) = 1                          para n>=0
 C(n, m) = C(n-1, m-1) + C(n-1, m)    para 0 < m < n

*/

#include <stdio.h>

long unsigned int comb(int n, int m) {
  if (m==0 || n==m)
    // caso base
    return 1;
  // caso recursivo            
  return (comb(n-1, m-1) + comb(n-1, m));   
}

void leer(int *num) {
  do {
    printf("Ingrese número positivo: ");
    scanf("%d", num);
  } while(*num < 0);
}

int main() {
  int n, m;
  printf("Se le solicitarán 2 números para calcular la combinatoria de elegir m objetos de un total de n objetos distintos. \n");

  printf("Ingrese la cantidad total de elementos (n) \n");
  leer(&n);
  printf("Ingrese la cantidad diferentes de elementos a seleccionar (m) \n");
  leer(&m);


  printf("La combinatoria de m entre n es %lu \n\n", comb(n, m));
  return 0;
}