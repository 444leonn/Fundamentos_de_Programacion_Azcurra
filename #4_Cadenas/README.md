# Cadenas

Una cadena de caracteres en C, es un tipo particular de vector, que contiene elementos de tipo char, siendo el ultimo, el caracter **nulo “\0”**

| *‘*H*’* | *‘*O*’* | *‘*L*’* | *‘*A*’* | *‘ ‘* | *‘*M*’* | *‘*U*’* | *‘*N*’* | *‘*D*’* | *‘*O*’* | ***‘*\0*’*** | ? |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |

Al igual que con los arreglos, vamos a definir una cantidad de bytes, que sera cuantos bytes vamos a reservar como maximo para nuestra cadenas de caracteres.

- Para mostrar las ***cadenas*** se utiliza la mascara (format specifier) **%s** el cual corresponde con los “strings”.
- Para mostrar unicamente ***caracteres*** se utiliza la mascara (format specifier) **%c** el cual corresponde con los “caracteres”.

## Declaracion de Cadenas

Existen varias manera de declarar cadenas, algunas mas o menos, convenientes.

### Indicando longitud y valor

Se indica la longitud total que la cadena puede tomar, seguido de un valor inicial entre comillas dobles

```c
char cadena1[15] = "Hola Mundo 1";
```

Se debe tener en cuenta que, como el lenguaje C asigna automaticamente el **“\0”** al final de la cadena, se debe tener en cuenta el espacio que necesita el cadena para almacenar ese **“\0”**. Por lo tanto si nuestra cadena tiene 10 caracteres + el “\0” son 11 caracteres o bytes que debe tener la cadena, como minimo.

### Sin Indicar la Longitud

Podemos no indicar la longitud inicial de la cadena, dandole un valor inicial.

Se debe tener en cuenta que el maximo fiisco de bytes/caracteres no se puede modificar.

```c
char cadena2[] = "Hola Mundo 2";
```

En este caso la cadena va a tener 13 bytes reservados, 12 para caracteres y 1 para el “\0” final.

### Indicando solo longitud

Declaro la cantidad de bytes que va a ocupar la cadena, pero no le asigno los valores.

```c
char cadena3[20];
```

# Manipulación de Cadenas en C

## Declaración y Recorrido de una Cadena

Analicemos este código que declara una cadena con una longitud máxima de 15 bytes. Recordemos que dentro de esos 15 bytes debe incluirse el carácter nulo (`\\0`).

```c
char cadena[15] = "Hola mundo";

```

### Mostrando la Cadena

Para imprimir la cadena completa usamos `printf` con la máscara `%s`:

```c
printf("%s", cadena);
// Imprime: Hola mundo

```

### Recorrido con For

Podemos recorrer la cadena carácter por carácter usando un bucle `for`:

```c
for(int i = 0; i < 15; i++) {
    printf("Caracter en posicion %i: %c. \n", i, cadena[i]);
    // %c para caracteres individuales
}
```

Este bucle recorre desde la posición 0 hasta la 14 (15 bytes reservados). Observaciones clave:

- **Cuidado con los límites**: Si seguimos más allá de la posición 14, accederíamos a memoria no reservada.
- El compilador no advierte sobre accesos fuera de los límites del arreglo.

### Recorrido con While

Una forma más segura es usar `while`, deteniéndonos al encontrar el carácter nulo:

```c
int i = 0;
while(cadena[i] != '\0') {
    printf("Caracter en posicion %i: %c", i, cadena[i]);
    i++;
}
```

Aquí solo se imprimen los caracteres hasta `'\0'` (posición 10), ignorando los bytes no utilizados.

---

## Modificación de Caracteres

Como es un arreglo, podemos modificar caracteres individuales:

```c
cadena[0] = 'X';  // Cambia 'H' → 'X'
cadena[5] = 'X';  // Cambia ' ' → 'X'
cadena[8] = 'X';  // Cambia 'd' → 'X'
```

Tras estas modificaciones, `printf("%s", cadena)` mostrará: `XolaXmunXo`.

### Precaución con los Límites

Si asignamos un valor más allá del `'\0' (ej: posición 11):

```c
cadena[11] = 'X';  // Posición no utilizada inicialmente
```

- `printf("%s", cadena)` seguirá mostrando `Hola mundo` (se detiene en `'\0'`).
- Pero el bucle `for` mostrará la `X` en la posición 11.

**Conclusión**:

- Las funciones como `printf` dependen de `\0'` para determinar el fin de la cadena.
- Si modificamos posiciones fuera del `'\0'`, no afectarán a `printf`, pero podrían corromper memoria.

---

# Lectura de Cadenas en C

## Uso de `fgets` para leer cadenas

Para leer cadenas de manera segura, **recomendamos usar `fgets`** en lugar de `scanf`.

### Sintaxis de `fgets`:

```c
fgets(variable_destino, longitud_maxima, stdin);

```

- **`variable_destino`**: Arreglo de caracteres donde se almacenará la entrada.
- **`longitud_maxima`**: Máximo de caracteres a leer (incluyendo el `\\0`).
- **`stdin`**: Indica que la entrada viene del teclado.

Ejemplo práctico:

```c
#include <stdio.h>
#define MAX_NOMBRE 15
#define MAX_APELLIDO 20
#define MAX_DOMICILIO 30

int main() {
    char nombre[MAX_NOMBRE];
    char apellido[MAX_APELLIDO];
    char domicilio[MAX_DOMICILIO];

    printf("Ingrese nombre: ");
    fgets(nombre, MAX_NOMBRE, stdin);
    fflush(stdin);  // Limpia el buffer después de fgets

    printf("Ingrese apellido: ");
    fgets(apellido, MAX_APELLIDO, stdin);
    fflush(stdin);

    printf("Ingrese domicilio: ");
    fgets(domicilio, MAX_DOMICILIO, stdin);

    printf("\\nDatos ingresados:\\n");
    printf("Nombre: %s", nombre);
    printf("Apellido: %s", apellido);
    printf("Domicilio: %s", domicilio);

    return 0;
}
```

### Observaciones clave:

1. **`fgets` captura espacios**: A diferencia de `scanf` con `%s`, `fgets` lee toda la línea (incluyendo espacios) hasta presionar *Enter*.
2. **Incluye `\\n`**: Almacena el salto de línea (`\\n`) al final de la cadena. Si no se desea, puede removerse manualmente:
    
    ```c
    nombre[strcspn(nombre, "\n")] = '\\0';  // Elimina el \\n
    ```
    
3. **`fflush(stdin)`**: Es crucial usarlo después de `fgets` para limpiar el buffer y evitar problemas en lecturas posteriores.

---

## Problemas con `scanf` para cadenas

### Limitaciones de `scanf` con `%s`:

```c
char nombre[20];
scanf("%s", nombre);  // Lee solo hasta el primer espacio
```

- Si se ingresa *"Juan Perez"*, solo almacena *"Juan"*.

### Solución parcial con `scanf`:

Para leer hasta el final de la línea:

```c
scanf("%[^\n]s", nombre);  // Lee hasta encontrar \\n
```

- **Problema**: No controla la longitud máxima, lo que puede causar *buffer overflow*.

---

## Comparación: `fgets` vs `scanf`

| Característica | `fgets` | `scanf` con `%s` |
| --- | --- | --- |
| Lectura de espacios | ✅ Sí (lee toda la línea) | ❌ No (hasta primer espacio) |
| Control de longitud | ✅ Sí (seguro) | ❌ No (riesgo de overflow) |
| Incluye `\n` | ✅ Sí | ❌ No |
| Uso recomendado | ✔️ Para cadenas con espacios | ✖️ Evitar para cadenas |

---

# Funciones para Manejo de Cadenas en C

Para trabajar con cadenas en C, utilizamos funciones de la librería `<string.h>`, excepto `strcmp` que está en la librería estándar.

## 1. `strlen`: Longitud de una cadena

**Propósito**: Obtener el número de caracteres (sin contar `\\0`).

```c
#include <stdio.h>
#include <string.h>

int main() {
    char cadena1[10] = "Hola";
    char cadena2[] = "Mundo";
    char cadena3[] = " ";

    printf("Longitud cadena1: %d\\n", strlen(cadena1));  // 4
    printf("Longitud cadena2: %d\\n", strlen(cadena2));  // 5
    printf("Longitud cadena3: %d\\n", strlen(cadena3));  // 1

    return 0;
}

```

**Nota**: `sizeof(cadena1)` devuelve 10 (bytes reservados), mientras que `strlen(cadena1)` devuelve 4 (caracteres útiles).

---

## 2. `strcpy`: Asignar valores a cadenas

**Propósito**: Copiar el contenido de una cadena a otra.

```c
#include <stdio.h>
#include <string.h>

int main() {
    char cadena[15] = "Hola";
    strcpy(cadena, "Chau");  // cadena ahora es "Chau"

    printf("%s\\n", cadena);  // Imprime: Chau
    return 0;
}

```

**Precaución**: Asegurarse de que la cadena destino tenga espacio suficiente.

---

## 3. `strcat`: Concatenar cadenas

**Propósito**: Unir dos cadenas.

```c
#include <stdio.h>
#include <string.h>

int main() {
    char cadena1[15] = "Hola";
    char cadena2[] = " ";
    char cadena3[] = "Mundo";

    strcat(cadena1, cadena2);  // cadena1 = "Hola "
    strcat(cadena1, cadena3);  // cadena1 = "Hola Mundo"

    printf("%s\\n", cadena1);  // Imprime: Hola Mundo
    return 0;
}

```

**Importante**: La cadena destino debe tener capacidad para almacenar el resultado.

---

## 4. `strcmp`: Comparar cadenas

**Propósito**: Comparar alfabéticamente dos cadenas.

```c
#include <stdio.h>  // No requiere <string.h>

int main() {
    char cadena1[] = "Hola";
    char cadena2[] = "Mundo";

    int resultado = strcmp(cadena1, cadena2);

    if (resultado == 0) {
        printf("Son iguales\\n");
    } else if (resultado > 0) {
        printf("Cadena1 es mayor\\n");  // "Hola" > "Mundo" → NO
    } else {
        printf("Cadena1 es menor\\n");  // "Hola" < "Mundo" → SÍ
    }

    return 0;
}

```

**Reglas**:

- Devuelve `0` si son iguales.
- Devuelve `> 0` si `cadena1` es mayor (en orden alfabético).
- Devuelve `< 0` si `cadena1` es menor.

---

## 5. `strstr`: Buscar subcadenas

**Propósito**: Encontrar una subcadena dentro de otra.

```c
#include <stdio.h>
#include <string.h>

int main() {
    char cadena1[] = "Mundo";
    char cadena2[] = "Hola Mundo";
    char *posicion;

    posicion = strstr(cadena2, cadena1);

    if (posicion != NULL) {
        printf("'%s' está en '%s'\\n", cadena1, cadena2); // "Mundo" está en "Hola Mundo"
    } else {
        printf("No encontrado\\n");
    }

    return 0;
}
```

**Detalles**:

- Devuelve un puntero a la primera ocurrencia de la subcadena.
- Si no se encuentra, devuelve `NULL`.

---

# Ejercicios

## Primer Ejercicio

**Consigna**:

1. Escriba un programa que pida al usuario:
    - Nombre completo (con espacios).
    - Dirección (con espacios).
2. Usar `fgets` para ambas entradas.
3. Eliminar los `\n` finales de las cadenas.
4. Mostrar los datos en el formato:
    
    ```
    [Nombre]: [Dirección]
    
    ```
    

**Solución sugerida**:

```c
#include <stdio.h>
#include <string.h>
#define MAX 50

int main() {
    char nombre[MAX];
    char direccion[MAX];

    printf("Ingrese nombre completo: ");
    fgets(nombre, MAX, stdin);
    nombre[strcspn(nombre, "\n")] = '\0';  // Elimina \n

    printf("Ingrese dirección: ");
    fgets(direccion, MAX, stdin);
    direccion[strcspn(direccion, "\n")] = '\0';

    printf("\\n%s: %s\\n", nombre, direccion);
    return 0;
}

```

## Segundo Ejercicio

Para practicar, escriban un programa que:

1. Declare una cadena de 20 bytes.
2. La inicialice con un texto corto (ej: "Programar en C").
3. La recorra con `for` y `while`, mostrando cada carácter.
4. Modifique al menos 3 posiciones y observen cómo cambia la salida.

**Preguntas para reflexionar**:

- ¿Qué pasa si el texto inicial supera los 19 caracteres?
- ¿Cómo afecta al programa si olvidamos el `'\\0'`?

## Tercer Ejercicio

**Consigna**:

1. Declarar una cadena con capacidad para 50 caracteres.
2. Leer un nombre completo usando `fgets`.
3. Usar `strlen` para mostrar su longitud.
4. Buscar la subcadena "Juan" con `strstr`.
5. Compararla con "Ana" usando `strcmp`.

**Solución sugerida**:

```c
#include <stdio.h>
#include <string.h>

int main() {
    char nombre[50];
    printf("Ingrese nombre completo: ");
    fgets(nombre, 50, stdin);
    nombre[strcspn(nombre, "\\n")] = '\\0';  // Eliminar \\n

    printf("Longitud: %d\\n", strlen(nombre));

    if (strstr(nombre, "Juan") != NULL) {
        printf("Contiene 'Juan'\\n");
    }

    if (strcmp(nombre, "Ana") == 0) {
        printf("Es igual a 'Ana'\\n");
    }

    return 0;
}

```

---
