#include <stdio.h>

int* encontrarMax(int *a, int *b) {
    printf("a: %p\n", a);
    printf("b: %p\n", b);

    printf("*a: %d\n", *a);
    printf("*b: %d\n", *b);

    return (*a > *b) ? a : b;
}

int main() {
    int x, y;
    printf("Ingresa el primer número: ");
    scanf("%d", &x);
    printf("Ingresa el segundo número: ");
    scanf("%d", &y);
    
    int *max = encontrarMax(&x, &y);
    printf("Máximo: %d\n", *max); // Imprime el mayor de los dos números ingresados
    return 0;
}
