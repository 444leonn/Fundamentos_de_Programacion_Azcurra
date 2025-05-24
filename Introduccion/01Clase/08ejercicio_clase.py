# Leer numeros, sumarlos, si ingresa 0 terminar

N=int(input("Ingrese un numero: "))
sum = 0

while (N != 0):
    sum = sum + N
    N=int(input("Ingrese otro numero: "))

print(f"El resultado de la suma es: {sum}")