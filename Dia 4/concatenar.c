#include <stdio.h>
#include <string.h>

int main(){
    char cadena1[4] = "Hola";
    char cadena2[] = " a";
    char cadena3[] = " todos";

    strcat(cadena1, cadena2);
    printf("Primera: %s\n", cadena1);
    strcat(cadena1, cadena3);
    printf("Segunda: %s\n", cadena1);

    return 0;
}
