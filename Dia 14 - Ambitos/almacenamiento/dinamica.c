#include <stdio.h>
#include <stdlib.h>

void funcion() {
    int *variableDinamica = (int *)malloc(sizeof(int)); // Variable dinámica
    *variableDinamica = 20;
    printf("Variable Dinámica: %d\n", *variableDinamica);
    free(variableDinamica); // Libera la memoria
}

int main() {
    funcion();
    return 0;
}


