#include <stdio.h>

void intercambiar(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main() {
    int a, b;
    printf("Ingresa el primer número: ");
    scanf("%d", &a);
    printf("Ingresa el segundo número: ");
    scanf("%d", &b);
    
    intercambiar(&a, &b);
    printf("Después de intercambiar: a = %d, b = %d\n", a, b); // Intercambia los valores de a y b
    return 0;
}
