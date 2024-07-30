#include <stdio.h>
#include <stdlib.h>

int contadorGlobal = 0; // Variable global

void interactuarVariables() {
    static int contadorLocalEstatico = 0; // Variable estática local
    int *contadorDinamico = (int *)malloc(sizeof(int)); // Variable dinámico

    printf("Ingresa un valor para el Contador Dinámico: ");
    scanf("%d", contadorDinamico);
    
    printf("Contador Global: %d\n", contadorGlobal);
    printf("Contador Local Estático: %d\n", contadorLocalEstatico);
    printf("Contador Dinámico: %d\n", *contadorDinamico);

    contadorGlobal++;
    contadorLocalEstatico++;

    free(contadorDinamico); // Libera la memoria
}

int main() {
    for (int i = 0; i < 3; i++) {
        interactuarVariables();
    }
    return 0;
}
