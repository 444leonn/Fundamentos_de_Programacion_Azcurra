/*
* Desarrollar una función recursiva para realizar una búsqueda binaria en un vector.
*/

#include <stdio.h>

#define MAX 20
#define NO_ENCONTRADO -1

typedef int T_Vec[MAX];

int busq_binaria(T_Vec valores, int inf, int sup, int buscado) {
  int mit, pos;

  if ((buscado < valores[inf]) || (buscado > valores[sup]))
    return NO_ENCONTRADO; // NO ESTA => FIN DE LA BUSQUEDA

  mit = inf + ((sup-inf)/2);

  if (valores[mit] == buscado)
    return mit; // ENCONTRADO => FIN DE LA BUSQUEDA
      
  if(valores[mit] < buscado)
    return busq_binaria(valores, mit+1, sup, buscado);
  
  return busq_binaria(valores, inf, mit-1, buscado);
}

int main() {
    T_Vec numeros = {1, 2, 3, 4, 5, 7};
    int ml = 6;

    printf("\n   %d   \n", busq_binaria(numeros, 0, ml - 1, 4));

    
    return 0;
}