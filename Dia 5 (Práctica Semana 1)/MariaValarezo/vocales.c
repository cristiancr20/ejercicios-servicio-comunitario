#include <stdio.h>
#include <ctype.h>

int main() {
    char texto[100];
    int contador = 0;

    printf("Ingrese una cadena de texto: ");
    fgets(texto, sizeof(texto), stdin);

    for (int i = 0; texto[i] != '\0'; i++) {
        char caracter = tolower(texto[i]);
        if (caracter == 'a' || caracter == 'e' || caracter == 'i' || caracter == 'o' || caracter == 'u') {
            contador++;
        }
    }

    printf("El número total de vocales es: %d\n", contador);

    return 0;
}