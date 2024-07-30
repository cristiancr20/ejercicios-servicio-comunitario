#include <stdio.h>

int main() {
    // Declarar variables
    float fahrenheit, celsius, kelvin;
    
    // Solicitar al usuario la temperatura en Fahrenheit
    printf("Ingrese la temperatura en grados Fahrenheit: ");
    scanf("%f", &fahrenheit);
    
    // Convertir de Fahrenheit a Celsius
    celsius = (fahrenheit - 32) * 5.0 / 9.0;
    
    // Convertir de Celsius a Kelvin
    kelvin = celsius + 273.15;
    
    // Imprimir los resultados
    printf("Temperatura en Celsius: %.2f\n", celsius);
    printf("Temperatura en Kelvin: %.2f\n", kelvin);
    
    return 0;
}