#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int nivel = 1;
    int intentos_maximos = 3;
    int numero_secreto, intentos_restantes, intento;

    srand(time(NULL)); // Inicializar la semilla para números aleatorios
    
    do {
        // Generar un número secreto aleatorio para el nivel actual
        numero_secreto = rand() % (nivel * 10) + 1; // Número secreto entre 1 y nivel * 10
        intentos_restantes = intentos_maximos;
        
        printf("\n*** Nivel %d ***\n", nivel);
        printf("Intenta adivinar el número secreto (entre 1 y %d).\n", nivel * 10);
        
        do {
            printf("Intentos restantes: %d\n", intentos_restantes);
            printf("Ingresa tu intento: ");
            scanf("%d", &intento);
            
            if (intento == numero_secreto) {
                printf("¡Correcto! Has adivinado el número secreto %d.\n", numero_secreto);
                break;
            } else {
                if (intento < numero_secreto) {
                    printf("Incorrecto. El número secreto es mayor.\n");
                } else {
                    printf("Incorrecto. El número secreto es menor.\n");
                }
                intentos_restantes--;
            }
        } while (intentos_restantes > 0);
        
        if (intento != numero_secreto) {
            printf("Has agotado tus intentos en el nivel %d. Fin del juego.\n", nivel);
            break;
        }
        
        nivel++;
    } while (nivel <= 3); // Jugar hasta el nivel 3
    
    printf("Gracias por jugar.\n");
    
    return 0;
}
