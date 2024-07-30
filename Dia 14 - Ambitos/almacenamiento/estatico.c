#include <stdio.h>

void funcion() {
    static int variableEstatica = 10; // Variable estática
    printf("Variable Estática: %d\n", variableEstatica);
    variableEstatica++;
}

int main() {
    funcion();
    funcion();
    return 0;
}

