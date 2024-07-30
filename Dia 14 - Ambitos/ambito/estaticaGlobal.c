#include <stdio.h>

static int variableGlobalEstatica = 100; // Variable estática global

void funcion() {
    printf("Variable Global Estática: %d\n", variableGlobalEstatica);
}

int main() {
    funcion();
    printf("Variable Global Estática en el main: %d\n", variableGlobalEstatica);
    return 0;
}

