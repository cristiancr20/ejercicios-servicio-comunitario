#include <stdio.h>
#include <string.h>

void swap(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

void generarPermutaciones(char *cadena, int inicio, int fin) {
    if (inicio == fin) {
        printf("%s\n", cadena);
        return;
    }

    for (int i = inicio; i <= fin; i++) {
        swap(&cadena[inicio], &cadena[i]);
        generarPermutaciones(cadena, inicio + 1, fin);
        swap(&cadena[inicio], &cadena[i]); // Restaurar el arreglo original
    }
}

int main() {
    char cadena[20];
    printf("Ingrese una cadena de caracteres para generar sus permutaciones: ");
    scanf("%s", cadena);

    int n = strlen(cadena);
    printf("Permutaciones de la cadena \"%s\":\n", cadena);
    generarPermutaciones(cadena, 0, n - 1);

    return 0;
}
