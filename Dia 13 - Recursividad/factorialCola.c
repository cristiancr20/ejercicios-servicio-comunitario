#include <stdio.h>

int factorialAux(int n, int acumulador) {
    if (n == 0) {
        return acumulador; // Caso base
    } else {
        return factorialAux(n - 1, n * acumulador); // Caso recursivo
    }
}

int factorial(int n) {
    return factorialAux(n, 1);
}

int main() {
    int numero;
    printf("Ingresa un número para calcular su factorial: ");
    scanf("%d", &numero);
    
    printf("El factorial de %d es: %d\n", numero, factorial(numero));
    return 0;
}
