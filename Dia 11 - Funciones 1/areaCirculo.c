#include <stdio.h>

#define PI 3.14159

// Declaración de la función
float calcularAreaCirculo(float radio);

// Función principal
int main() {
    float radio = 4.5;
    float area = calcularAreaCirculo(radio);
    printf("El área del círculo con radio %.2f es %.5f\n", radio, area);
    return 0;
}

// Definición de la función
float calcularAreaCirculo(float radio) {
    return PI * radio * radio;
}