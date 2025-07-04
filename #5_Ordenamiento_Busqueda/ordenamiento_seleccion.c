#include<stdio.h> 

#define MF 5

typedef int tvector[MF];

void mostrar(tvector vector, int n) { 
  int k;     
  for(k=0; k<n; k++)
    printf("%d ",vector[k]); 
}

void ordenar(tvector vector, int n) {
  int i, j, minimo, aux;     
  // método selección
  for (i=0; i<n-1; i++) { 
    minimo = i;
    for (j=i+1; j<n; j++) {
      if (vector[j] < vector[minimo]) { 
        minimo = j;
      } 
    }
    aux=vector[i];                  
    vector[i]=vector[minimo]; 
    vector[minimo]=aux; 
  }
} 

void ordenar_con_seguimiento(tvector vector, int n) {
  int i, j, minimo, aux;     
     
  for (i=0; i<n-1; i++) {
    minimo = i;
    for (j=i+1; j<n; j++) {
      if (vector[i] > vector[j]) {
        minimo = j;
      }       
      printf("i = %d   j = %d  minimo = %d\n", i, j, minimo); 
    }
    aux=vector[i];                  
    vector[i]=vector[minimo]; 
    vector[minimo]=aux; 
    mostrar(vector, n);
    printf("\n\n"); 
  }
}

int main() {
  tvector vec={4,3,5,2,1};

  printf("VECTOR ORIGINAL\n"); 
  mostrar(vec, MF);

  printf("\n\nMETODO DE SELECCION\n\n");
  ordenar_con_seguimiento(vec, MF);

  printf("\nVECTOR FINAL\n"); 
  mostrar(vec, MF);
  printf("\n");

  return 0;
} 
