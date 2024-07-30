#include <stdio.h>

void funcion() {
    static int variableEstatica = 0; // Variable estática local
    variableEstatica++;
    printf("Variable Estática: %d\n", variableEstatica);
}

int main() {
    funcion();
    funcion();
    funcion();
    return 0;
}

