#include <stdio.h>

int fibonacci(int n) {
    if (n == 0) {
        return 0; // Caso base
    } else if (n == 1) {
        return 1; // Caso base
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2); // Caso recursivo
    }
}

int main() {
    int numero;
    printf("Ingresa un número para calcular su Fibonacci: ");
    scanf("%d", &numero);
    
    printf("El número Fibonacci de %d es: %d\n", numero, fibonacci(numero));
    return 0;
}
