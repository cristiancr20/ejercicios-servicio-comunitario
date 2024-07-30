#include <stdio.h>

int main() {
    int base, exponente;
    int resultado = 1;

    printf("Ingrese la base: ");
    scanf("%d", &base);

    printf("Ingrese el exponente: ");
    scanf("%d", &exponente);

    for (int i = 0; i < exponente; i++) {
        resultado *= base;
    }

    printf("El resultado de %d elevado a la %d es: %d\n", base, exponente, resultado);

    return 0;
}