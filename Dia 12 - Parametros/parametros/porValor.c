#include <stdio.h>

void incrementar(int x) {
    x = x + 1;
}

int main() {
    int a;
    printf("Ingresa un número: ");
    scanf("%d", &a);
    
    incrementar(a);
    printf("El valor de a después de incrementar es: %d\n", a); // a sigue siendo el mismo valor ingresado
    return 0;
}

