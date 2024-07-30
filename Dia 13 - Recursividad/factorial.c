#include <stdio.h>

int factorial(int n) {
    if (n == 0) {
        return 1; // Caso base
    } else {
        return n * factorial(n - 1); // Caso recursivo
    }
}

int main() {
    int numero;
    printf("Ingresa un número para calcular su factorial: ");
    scanf("%d", &numero);
    
    printf("El factorial de %d es: %d\n", numero, factorial(numero));
    return 0;
}

