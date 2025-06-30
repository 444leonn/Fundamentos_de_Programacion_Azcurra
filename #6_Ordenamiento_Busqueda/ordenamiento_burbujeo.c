#include <stdio.h> 
#include <stdbool.h> 

#define MF 5

typedef int tvector[MF];

void mostrar(tvector vector, int n) { 
  int k;     
  for(k=0; k<n; k++)
    printf("%d ",vector[k]); 
}

void ordenar(tvector vector, int n) {
  int i, j, aux; 
  // método burbujeo
  for (i=1; i<n; i++) {                // ciclo de n-1 pasos
    for (j=0; j<n-i; j++) {            // ciclo de n-pasos comparaciones
      if (vector[j] > vector[j+1]) {   // si corresponde intercambio
         aux=vector[j]; 
         vector[j]=vector[j+1]; 
         vector[j+1]=aux; 
       } 
    }
  }
}

void ordenar_mejorado(tvector vector, int n) {
  int i, j, aux;     
  bool continuar=true;

  // método burbujeo mejorado
  i=1;
  while (continuar && i<n) {
    continuar=false;
    for (j=0; j<n-i; j++) {
      if (vector[j] > vector[j+1]) {
         aux=vector[j]; 
         vector[j]=vector[j+1]; 
         vector[j+1]=aux;
         continuar=true;
       } 
    }
    i++;
  }
}

void ordenar_con_seguimiento(tvector vector, int n) {
  int i, j, aux;     
  bool intercambio;  
  for (i=1; i<n; i++) {
    for (j=0; j<n-i; j++) {
      intercambio = false;
      if (vector[j] > vector[j+1]) {
          aux=vector[j]; 
          vector[j]=vector[j+1]; 
          vector[j+1]=aux;
          intercambio = true;
      } 
      mostrar(vector, n); 
      printf("   i = %d   j = %d   j+1 = %d ",i,j,j+1); 
      if (intercambio) printf(" intercambio");
      printf("\n");
    }
    printf("\n"); 
  }
}


int main() { 
  tvector vec={4,3,5,2,1}; 

  printf("VECTOR ORIGINAL\n"); 
  mostrar(vec, MF);

  printf("\n\nMETODO DE BURBUJEO\n\n");
  ordenar_con_seguimiento(vec, MF);
        
  printf("\nVECTOR FINAL\n"); 
  mostrar(vec, MF);
  printf("\n");

  return 0;
} 