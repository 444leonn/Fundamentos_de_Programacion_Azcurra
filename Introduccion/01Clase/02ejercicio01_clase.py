# Escribir un programa que determine si un número ingresado por el usuario es positivo, negativo o cero.

numero = float(input("Ingrese un numero: "))

if numero > 0:
    print(f"El numero {numero} es positivo.")
elif numero < 0:
    print(f"El numero {numero} es negativo.")
else:
    print(f"El numero es {numero}.")