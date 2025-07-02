#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MF 20
#define NO_ENCONTRADO -1

typedef int tvector[MF];

int busq_binaria(tvector valores, int inf, int sup, int buscado) {
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

void mostrar_resultado(char *tipo, int dato, int pos) {
  if (pos == NO_ENCONTRADO) {
    printf("Valor %d buscado x BUSQUEDA %s no encontrado \n\n", dato, tipo);
  } else {
    printf("Valor %d buscado x BUSQUEDA %s encontrado en posicion %d \n\n", dato, tipo ,pos);
  }
}

int main() {
  tvector vector = {0,10,20,30,40,50,60,70,80,90,100,110,120,130,140,150,160,170,180,190};
  int dato, n = MF;
  int pos; 

  printf("Ingrese dato a buscar: ");
  scanf("%d", &dato);

  /* BUSQUEDA BINARIA */
  pos = busq_binaria(vector, 0, n-1, dato);
  mostrar_resultado("BINARIA", dato, pos);

  return 0;
}