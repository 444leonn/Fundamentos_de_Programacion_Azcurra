# Escribir un programa en Python, C - o pseudocódigo- que le solicite al usuario que ingrese su número de padrón y devuelva por pantalla todos los divisores del padrón ingresado.
# En la lista se deben omitir el 1 y el propio padrón.

nro_padron = int(input("Ingrese un numero de padron: "))

for i in range(2, nro_padron):
    if nro_padron % i == 0:
        print(f"El numero {i} es divisor del numero de padron.")
