import random

# Definir el número de niveles y el número máximo de intentos permitidos en cada nivel
num_niveles = 3
intentos_maximos = 5

# Función para generar un número secreto aleatorio sin cifras repetidas
def generar_numero_secreto():
    digitos = list(range(10))
    random.shuffle(digitos)
    return int(''.join(map(str, digitos[:1])))

# Iniciar el juego en el nivel 1
nivel_actual = 1

while nivel_actual <= num_niveles:
# Generar el número secreto para el nivel actual
    numero_secreto = generar_numero_secreto()

    print("\nNivel ", nivel_actual)
    print("Tienes ", intentos_maximos, " intentos para adivinar el número secreto.")

    intentos_restantes = intentos_maximos

    while intentos_restantes > 0:
    # Pedir al usuario que ingrese un número
        numero_ingresado = int(input("Ingresa un número de cifras: "))

        if numero_ingresado == numero_secreto:
            print("¡Felicitaciones! Has adivinado el número secreto.")
            break
        elif numero_ingresado < numero_secreto:
            print("El número ingresado es menor que el número secreto.")
        else:
            print("El número ingresado es mayor que el número secreto.")

        intentos_restantes -= 1
        print("Intentos restantes:", intentos_restantes)

    if intentos_restantes == 0:
        print("\n¡Lo siento! Has agotado todos los intentos en el nivel ", nivel_actual)


    nivel_actual += 1

print("\nJuego terminado.") 