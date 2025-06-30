#include<stdio.h> 
#include<stdlib.h> 

#define MF 5

typedef int tvector[MF];

void mostrar(tvector vector, int n) { 
  int k;     
  for(k=0; k<n; k++)
    printf("%d ",vector[k]);
}


void ordenar(tvector vector, int n) {
  int k, i, aux;
  // método inserción
   for (k=1; k<n; k++) {
      aux = vector[k];
      i = k-1;
      // mientras no haya llegado al final
      // y aux este fuera de lugar 
      while ((i>=0) && (aux < vector[i])) {                      
         vector[i+1] = vector[i];      // desplazo vector[i] 
         i=i-1;                       // desplazo indice
      }
      vector[i+1] = aux;  //coloco aux en su lugar
   }
}

void ordenar_con_seguimiento(tvector vector, int n) {
   int k, i, aux;

   for (k=1; k<n; k++) {
      aux = vector[k];
      printf("\nElemento a insertar k= %d valor= %d  \n",k,aux);
      
      i=k-1;
      // mientras no haya llegado al final
      // y aux este fuera de lugar 
      while  ((i>=0) && (aux < vector[i])) {               
        vector[i+1] = vector[i];      // desplazo vector[i] 
         i=i-1;                       // desplazo indice

         mostrar(vector, MF);
         printf("   DESPLAZAMIENTO\n");
      }
      vector[i+1] = aux;    //coloco aux en su lugar

      mostrar(vector, MF);
      printf("   INSERTO\n");
   }
}

int main() { 
  tvector vec={4,3,5,2,1};

  printf("VECTOR ORIGINAL\n"); 
  mostrar(vec, MF);

  printf("\n\nMETODO DE INSERCION\n");
  ordenar_con_seguimiento(vec, MF);
        
  printf("\nVECTOR FINAL\n"); 
  mostrar(vec, MF);
  printf("\n");
        
  system("PAUSE");
  return 0;
} 