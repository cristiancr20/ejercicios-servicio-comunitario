def calcular_mcd():
    a = int(input("Ingresa el primer número: "))
    b = int(input("Ingresa el segundo número: "))

    while b != 0:
        r = a % b
        a = b
        b = r

    return a
    

mcd = calcular_mcd()

print("El MCD de los números ingresados es:", mcd) 
