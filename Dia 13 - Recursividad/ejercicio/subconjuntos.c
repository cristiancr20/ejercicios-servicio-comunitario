#include <stdio.h>

void generarSubconjuntos(int conjunto[], int tamano, int indice, int subconjunto[], int tamanoSubconjunto) {
    if (indice == tamano) {
        // Imprimir el subconjunto generado
        printf("{ ");
        for (int i = 0; i < tamanoSubconjunto; i++) {
            printf("%d ", subconjunto[i]);
        }
        printf("}\n");
        return;
    }

    // No incluir el elemento actual en el subconjunto
    generarSubconjuntos(conjunto, tamano, indice + 1, subconjunto, tamanoSubconjunto);

    // Incluir el elemento actual en el subconjunto
    subconjunto[tamanoSubconjunto] = conjunto[indice];
    generarSubconjuntos(conjunto, tamano, indice + 1, subconjunto, tamanoSubconjunto + 1);
}

int main() {
    int conjunto[100], tamanoConjunto;
    printf("Ingrese el tamaño del conjunto: ");
    scanf("%d", &tamanoConjunto);

    printf("Ingrese los elementos del conjunto:\n");
    for (int i = 0; i < tamanoConjunto; i++) {
        scanf("%d", &conjunto[i]);
    }

    int subconjunto[100];
    printf("Subconjuntos del conjunto dado:\n");
    generarSubconjuntos(conjunto, tamanoConjunto, 0, subconjunto, 0);

    return 0;
}
