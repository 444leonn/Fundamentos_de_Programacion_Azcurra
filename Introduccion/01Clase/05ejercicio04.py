# Escribir un programa que pida al usuario ingresar numeros y vaya sumandolos hasta que el usuario ingrese un numero negativo. 
# Al final, muestra la suma total.

es_positivo = 0
suma = 0

while es_positivo == 0 :
    ingreso = float(input("Ingrese un numero para la suma: "))
    if (ingreso >= 0):
        suma += ingreso
        print(f"La cuenta va: {suma}")
    else:
        es_positivo = 1

print(f"Suma = {suma}")
