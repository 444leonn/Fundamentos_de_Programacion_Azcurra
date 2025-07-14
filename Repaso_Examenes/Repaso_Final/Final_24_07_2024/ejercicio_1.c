/*
* 1. Una libreria posee un archivo denominado `Stock.dat`, cuyos registros contienen
* el `codigo del libro` (entero), el `titulo` (30 caracteres), el `stock actual` de dicho libro (entero), 
* el `stock minimo` de dicho libro (entero) y el `precio unitario` (real). 
* Dicho archivo no esta ordenado y "NO ENTRA" en memoria en su totalidad.
*
* Se pide desarrollar un programa modular en lenguaje C que procese este archivo y que permita:
* - Generar una tabla llamada `Ofertas` que contenga solo los libros cuyo stock actual esta por encima del doble del stock minimo.
*  Incluir en la tabla los siguientes campos:
*   - El `codigo` del libro (entero)
*   - El `titulo` del libro (30 caracteres).
*   - La `cantidad` de libros a ofertar (entero, a lo sumo se pueden ofertar la mitad de los libros que estan por sobre el stock minimo).
*   - El `precio` unitario de oferta (real, el descuento de la oferta es del 30%).
* Asumir que esta tabla tendra como maximo 100 registros y que cabe en memoria.
* - Ordenar la tabla Ofertas ascendentemenete por titulo del libro.
*/