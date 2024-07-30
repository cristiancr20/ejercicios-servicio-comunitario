#include <stdio.h>
#include <ctype.h>

int main() {
    // Declarar una cadena de texto y una variable para contar vocales
    char str[100];
    int count = 0;

    // Solicitar al usuario una cadena de texto
    printf("Ingrese una cadena de texto: ");
    fgets(str, sizeof(str), stdin);
    
    // Recorrer la cadena de texto y contar las vocales
    for(int i = 0; str[i] != '\0'; i++) {
        char ch = tolower(str[i]);
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            count++;
        }
    }

    // Imprimir el número total de vocales
    printf("El número total de vocales es: %d\n", count);

    return 0;
}