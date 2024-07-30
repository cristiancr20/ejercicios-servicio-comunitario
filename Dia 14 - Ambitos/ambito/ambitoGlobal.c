#include <stdio.h>

int variableGlobal; // Variable global

void funcion() {
    printf("Ingresa un valor para la variable global: ");
    scanf("%d", &variableGlobal);
    printf("Variable Global en funcion: %d\n", variableGlobal);
}

int main() {
    funcion();
    printf("Variable Global en main: %d\n", variableGlobal);
    return 0;
}

