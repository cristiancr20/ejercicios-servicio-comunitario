#include <stdio.h>

// Definición completa de la función
int maximoDeTres(int a, int b, int c) {
    if (a > b && a > c) {
        return a;
    } else if (b > c) {
        return b;
    } else {
        return c;
    }
}

// Función principal
int main() {
    int a = 15, b = 25, c = 10;
    int maximo = maximoDeTres(a, b, c);
    printf("El mayor de %d, %d y %d es %d\n", a, b, c, maximo);
    return 0;
}


