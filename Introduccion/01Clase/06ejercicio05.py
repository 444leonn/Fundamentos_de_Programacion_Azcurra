# Escribir un programa que cuente cuántos números positivos y negativos ingresa el usuario. El ciclo termina cuando se ingresa el número cero.

cuenta_pos = 0
cuenta_neg = 0

num = float(input("Ingrese un numero: "))

while (num != 0):
    if num > 0:
        cuenta_pos += 1
    else:
        cuenta_neg += 1

    num = float(input("Ingrese otro numero: "))

print("Has ingresado", cuenta_pos, "numeros positivos")
print(f"Has ingresado", cuenta_neg, "numeros negativos")