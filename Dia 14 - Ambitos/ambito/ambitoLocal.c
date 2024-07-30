#include <stdio.h>

void funcion() {
    int variableLocal; // Variable local
    printf("Ingresa un valor para la variable local: ");
    scanf("%d", &variableLocal);
    printf("Variable Local: %d\n", variableLocal);
}

int main() {
    funcion();
    // printf("Variable Local: %d\n", variableLocal); // Esto causará un error
    return 0;
}

