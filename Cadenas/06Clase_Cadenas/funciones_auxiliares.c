#include <stdio.h>
#include <string.h>
#define STRING_SIZE 50
typedef char T_string[STRING_SIZE];
typedef char T_char_str[2];

// Función que convierte un caracter simple a un string de largo 1
void charstr(char c, T_char_str str)
{
  str[0] = c;
  str[1] = '\0';
}

// Elimina caractes del buffer de entrada standar input hasta encontrar el caracter salto de línea. Equivalente al fflush(stdin) que funciona en windows
void clear_stdin()
{
    while (getchar() != '\n');
}

/*
* Carga en el array cadena el texto ingresado por el usuario de tamaño largo-1, ya que se debe reservar un lugar para el caracter nulo.
* Internamente hace uso de la función "strcspn" -> "string complementary span"
* Revisar presentación en el campus para revisar su funcionamiento.
*/
void obtener_cadena(char cadena[], int largo)
{
  fgets(cadena, largo, stdin);
  cadena[strcspn(cadena, "\n")] = '\0';
}

// Carga en el array a el texto ingresado por el usuario sin inluir el salto de línea.
void obtener_cadena_scan(T_string s)
{
  scanf("%[^\n]%*c", s);
}

int main()
{
  T_string name;
  T_char_str char_str;
  char caracter;

  /* Ingresamos texto con fgets */
  printf("Ingresa tu nombre: ");
  obtener_cadena(name, STRING_SIZE);
  printf("Mucho gusto %s\n\n", name);

  /* Ingresamos texto con scanf */
  printf("Ingresa tu nombre: ");
  obtener_cadena_scan(name);
  printf("Mucho gusto %s\n\n",name);

  /* Ingresamos texto con scanf */
  printf("Ingresa un unico caracter: ");
  scanf("%c", &caracter);
  clear_stdin();
  
  printf("\n");
  /* Imprimimos el caracter manejandolo como caracter */
  printf("El caracter ingresado es %c \n", caracter);

  /* Imprimimos el caracter siendo parte de una cadena */
  charstr(caracter, char_str);
  printf("El caracter ingresado es %s \n", char_str);

  return 0;
}