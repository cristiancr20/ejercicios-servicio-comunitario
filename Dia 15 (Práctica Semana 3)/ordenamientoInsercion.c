#include <stdio.h>
#include <stdlib.h>

void ordenamientoInsercion(int *arreglo, int n) {
    if (n <= 1) {
        return;
    }

    ordenamientoInsercion(arreglo, n - 1);

    int ultimo = arreglo[n - 1];
    int j = n - 2;

    while (j >= 0 && arreglo[j] > ultimo) {
        arreglo[j + 1] = arreglo[j];
        j--;
    }

    arreglo[j + 1] = ultimo;
}

int main() {
    int n;
    printf("Ingrese el tamaño del arreglo: ");
    scanf("%d", &n);

    int *arreglo = (int *)malloc(n * sizeof(int));

    printf("Ingrese los elementos del arreglo:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arreglo[i]);
    }

    ordenamientoInsercion(arreglo, n);

    printf("Arreglo ordenado:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arreglo[i]);
    }
    printf("\n");

    free(arreglo);

    return 0;
}
