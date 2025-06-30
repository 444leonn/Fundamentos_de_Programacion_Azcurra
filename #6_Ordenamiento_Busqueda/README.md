# Ordenamiento de Burbuja (Bubble Sort)

## Concepto Básico

El ordenamiento de burbuja es un algoritmo simple para ordenar elementos en un arreglo o lista. Funciona comparando pares de elementos adyacentes y **intercambiándolos** si están en el orden incorrecto.

## Características Principales

- **Complejidad temporal**:
    - Peor caso: $O(n²)$
    - Mejor caso: $O(n)$ (cuando el arreglo ya está ordenado)
    - Caso promedio: $O(n²)$
- **Estable**: Mantiene el orden relativo de elementos iguales
- **In-place**: Solo requiere una cantidad constante de espacio adicional

## Implementación en C

```c
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        // Últimos i elementos ya están en su lugar
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                // Intercambiar arr[j] y arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

```

# Ordenamiento de Burbuja Optimizado

El metodo de ordenamiento por burbujeo, se puede optimizar, con el objetivo de reducir la cantidad de iteraciones, en cuanto se detecte que el arreglo que se esta queriendo ordenar ya lo esta.

## Ventajas y Desventajas

**Ventajas**:

- Simple de entender e implementar
- No requiere espacio adicional significativo
- Eficiente para conjuntos de datos pequeños o casi ordenados

**Desventajas**:

- Ineficiente para conjuntos de datos grandes
- Rendimiento pobre comparado con algoritmos más avanzados como QuickSort o MergeSort

## Implementacion en C

```c
void ordenar_por_burbujeo_optimizado (tvec vec, int ml) {
	int i, j, aux;
	
	i = 1;
	bool hubo_intercambio = true;
	
	while ((i < ml) && hubo_intercambio) { // Pasos
		hubo_intercambio = false;
		for (j = 0; j < ml - i; j++) { // Comparacionesif (vec[j] > vec[j+1])
			aux = vec[j]; // Intercambio
			vec[j] = vec[j + 1];
			vec[j+1] = aux;
			hubo_intercambio = true;
		}
		i++;
	}
}
```

# Ordenamiento por Selección (Selection Sort)

## Concepto Fundamental

El ordenamiento por selección es un algoritmo de ordenamiento **in-place** que divide el arreglo en dos partes: una sublista ordenada y otra sublista desordenada. Funciona encontrando repetidamente el elemento mínimo (o máximo) de la parte desordenada y colocándolo al final de la parte ordenada.

## Características Clave

- **Complejidad temporal**: $O(n²)$ en todos los casos (peor, mejor y promedio)
- **In-place**: Solo requiere $O(1)$ espacio adicional
- **No estable**: Puede cambiar el orden relativo de elementos iguales
- **Pocos intercambios**: Realiza exactamente n-1 intercambios (ventaja cuando los intercambios son costosos)

## Ventajas y Desventajas

**Ventajas**:

- Simple de implementar
- Rendimiento predecible (siempre $O(n²)$)
- Eficiente en términos de número de intercambios (solo n-1 intercambios)

**Desventajas**:

- Ineficiente para listas grandes
- Peor rendimiento que otros algoritmos O(n²) como el insertion sort en la mayoría de casos
- No estable (no mantiene el orden original de elementos iguales)

## Implementación Básica en C

```c
void ordenar_seleccion(tvector vector, int n) {
	int i, j, minimo, aux;
	
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
```

# Ordenamiento por Insercion (Insertion Sort)

El metodo de ordenamiento como seleccion busca ordenar los elementos del arreglo, tomando un elemento y comparandolo contra los anteriores ya ordenados, deteniendose cuando se encuentra uno menor y entonces alli es donde se inserta, desplazando el resto de los elementos mayores.

## El Algoritmo

- Vamos a recorrer todo el vector `A` comenzando desde la posicion inicial del vector + 1, hasta la ultima posicion.
- Para cada elemento del vector `A[i]`, se trata de ubicar en el lugar correcto el elemento `A[i]` en cuestion, entre los elementos: `A[i-1]` , `A[i-2]` , …, `A[inicial]` .
- Dada la posicion actual *i*, el algoritmo se basa en que los elementos `A[inicial]` , `A[1]` , …, `A[i-1]` . ya estan ordenados

## Complejidad Temporal

- Mejor Caso: $O(n)$
- Peor Caso: $O(n^2/2)$

## Implementacion en C

```c
void ordenar_insercion (tvec vec, int ml) {
	int i, j, aux;
	for (i = 1; i <= ml; i++) {
		aux = vec[i]; // preservo valor
		j = i - 1;
		while ((j >= 0) && (vec[j] > aux)) {
			vec[j+1] = vec[j]; // desplazo elemento
			j = j - 1;
		}
		vec[j+1] = aux;
	}
}
```

# Comparación entre Algoritmos

| Característica | Selection Sort | Bubble Sort | Insertion Sort |
| --- | --- | --- | --- |
| Complejidad | O(n²) | O(n²) | O(n²) |
| Intercambios | O(n) | O(n²) | O(n²) |
| Estabilidad | No | Sí | Sí |
| Rendimiento práctico | Pobre | Pobre | Mejor para pequeños/con casi ordenados |


# Búsqueda Secuencial (Linear Search)

## Concepto Básico

La búsqueda secuencial es un algoritmo simple para encontrar un elemento en un arreglo o lista. Consiste en recorrer el arreglo elemento por elemento, comparando cada uno con el valor buscado hasta encontrarlo o llegar al final de la estructura.

## Características Principales

- **No requiere arreglo ordenado**: Puede utilizarse en cualquier lista, ordenada o no.
- **Complejidad temporal**:
    - Mejor caso: $O(1)$ (si el elemento está en la primera posición)
    - Peor y caso promedio: $O(n)$ (donde $n$ es la cantidad de elementos)
- **In-place**: No requiere espacio adicional significativo.
- **Simplicidad**: Muy sencilla de implementar.

## Implementación en C

```c
int busqueda_secuencial(tvector valores, int tamanio, int buscado) {
  int i = 0, posicion = NO_ENCONTRADO;
  bool encontrado = false; 
  
  // mientras no se encontro y restan elementos por comparar
  while (!encontrado && i<tamanio) {
    if (valores[i] == buscado) {
        encontrado = true;
        posicion = i;
    }
    i++; 
  }

  return posicion;
}
```

## Ventajas y Desventajas

**Ventajas**:

- Funciona en cualquier tipo de lista o arreglo, ordenado o no
- Muy fácil de implementar
- Útil para listas pequeñas o cuando no se requiere mucha eficiencia

**Desventajas**:

- Muy ineficiente para listas grandes
- Requiere recorrer toda la lista en el peor caso

# Búsqueda Binaria (Binary Search)

## Concepto Básico

La búsqueda binaria es un algoritmo eficiente para encontrar un elemento en un arreglo **ordenado**. Funciona dividiendo repetidamente el rango de búsqueda a la mitad, comparando el elemento buscado con el elemento central, y descartando la mitad en la que el elemento no puede estar.

## Características Principales

- **Requiere arreglo ordenado**: Solo funciona correctamente si los datos están ordenados.
- **Complejidad temporal**:
    - Mejor caso: O(1) (si el elemento es central en la primera comparación)
    - Peor y caso promedio: $O(log_2(n))$
- **In-place**: Puede implementarse sin requerir espacio adicional significativo.
- **No es estable**: No es relevante ya que no reordena elementos, solo los busca.

## Implementación en C

```c
int busqueda_binaria(tvector valores, int tamanio, int buscado) {
  int inf, sup, mit;
  bool terminado; 
  int posicion;
  
  // inicializaciones
  inf = 0;
  sup = tamanio-1;
  terminado = false;

  while (!terminado) {
      if ((buscado < valores[inf]) || (buscado > valores[sup])) {
          terminado = true; // NO ESTA => FIN DE LA BUSQUEDA
          posicion = NO_ENCONTRADO;
      } else {
          mit = inf + ((sup-inf)/2); // evitamos overflow de la suma directa

          if (valores[mit] == buscado) {
            terminado = true; // ENCONTRADO => FIN DE LA BUSQUEDA
            posicion = mit;
          } else if(buscado > valores[mit]) {
            inf = mit + 1;
          } else {
            sup = mit - 1;
          }
      }        
  }

  return posicion;
}
```

## Ventajas y Desventajas

**Ventajas**:

- Mucho más rápida que la búsqueda lineal para arreglos grandes
- Fácil de implementar
- Eficiente en términos de comparaciones

**Desventajas**:

- Solo funciona sobre estructuras de datos ordenadas
- No es adecuada para listas enlazadas o estructuras sin acceso aleatorio rápido
- Requiere que el arreglo permanezca ordenado

# Comparación entre Busquedas

| Característica | Búsqueda Binaria | Búsqueda Lineal |
| --- | --- | --- |
| Requiere orden | Sí | No |
| Complejidad | O(log n) | O(n) |
| Ideal para | Datos ordenados | Datos pequeños o no ordenados |
| Acceso aleatorio | Necesario | No necesario |
