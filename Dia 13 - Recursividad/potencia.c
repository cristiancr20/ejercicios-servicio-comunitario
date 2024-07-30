#include <stdio.h>

int potencia(int base, int exponente) {
    if (exponente == 0) {
        return 1; // Caso base
    } else {
        return base * potencia(base, exponente - 1); // Caso recursivo
    }
}

int main() {
    int base, exponente;
    printf("Ingresa la base: ");
    scanf("%d", &base);
    printf("Ingresa el exponente: ");
    scanf("%d", &exponente);
    
    printf("%d^%d = %d\n", base, exponente, potencia(base, exponente));
    return 0;
}
