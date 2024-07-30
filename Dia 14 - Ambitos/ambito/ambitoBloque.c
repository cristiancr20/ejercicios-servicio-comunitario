#include <stdio.h>

int main() {
    int x = 10;
    printf("Fuera del bloque: %d\n", x);

    {
        int x = 20; // Variable de bloque
        printf("Dentro del bloque: %d\n", x);
    }

    printf("Fuera del bloque de nuevo: %d\n", x);
    return 0;
}


