#include <stdio.h>

int factorial(int n) {
    int resultado = 1;
    for (int i = 1; i <= n; ++i) {
        resultado *= i;
    }
    return resultado;
}

int main() {
    int numero;
    printf("Ingresa un número para calcular su factorial: ");
    scanf("%d", &numero);

    if (numero < 0) {
        printf("Error: No se puede calcular el factorial de un número negativo.\n");
    } else {
        int resultado = factorial(numero);
        printf("El factorial de %d es: %d\n", numero, resultado);
    }

    return 0;
}

