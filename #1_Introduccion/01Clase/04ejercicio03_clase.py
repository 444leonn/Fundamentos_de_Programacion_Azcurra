# Escribir un programa que reciba tres números y determine cuál es el mayor.

num1 = float(input("Ingrese el primer numero: "))
num2 = float(input("Ingrese el segundo numero: "))
num3 = float(input("Ingrese el ultimo numero: "))

try:
    num_mayor = max(num1, num2, num3)
    print(num_mayor)
except ValueError:
    print("Debes ingresar un numero valido")