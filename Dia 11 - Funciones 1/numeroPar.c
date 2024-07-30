#include <stdio.h>

// Declaración de la función
int esPar(int numero);

// Función principal
int main() {
    int numero = 9.5;
    if (esPar(numero)) {
        printf("El número %d es par.\n", numero);
    } else {
        printf("El número %d es impar.\n", numero);
    }
    return 0;
}

// Definición de la función
int esPar(int numero) {
    return numero % 2 == 0;
}
