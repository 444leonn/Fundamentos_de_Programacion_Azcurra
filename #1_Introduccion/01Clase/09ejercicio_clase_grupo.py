# Ingresar una serie de numeros finalizada en -1. Indicar cantidad de 0, cantidad de pares y cantidad de impares.

cuenta_par = 0
cuenta_impar = 0
cuenta_ceros = 0

num = float(input("Ingrese un numero: "))

while (num != -1):
    if num == 0:
        cuenta_ceros += 1
    else:
        if (num % 2 == 0):
            cuenta_par += 1
        else:
            cuenta_impar += 1

    num = float(input("Ingrese otro numero: "))

print("Has ingresado",cuenta_ceros, " ceros")
print("Has ingresado", cuenta_par, "numeros pares")
print("Has ingresado", cuenta_impar, "numeros impares")
