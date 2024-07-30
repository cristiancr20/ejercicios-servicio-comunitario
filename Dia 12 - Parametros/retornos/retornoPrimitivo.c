#include <stdio.h>

char obtenerInicial() {
    return 'A';
}

int main() {
    char inicial = obtenerInicial();
    printf("Inicial: %c\n", inicial); // Inicial es 'A'
    return 0;
}
