#include <stdio.h>

int main() {
    float fahrenheit, celsius, kelvin;

    printf("Ingrese la temperatura en grados Fahrenheit: ");
    scanf("%f", &fahrenheit);

    celsius = (fahrenheit - 32) * 5 / 9;
    kelvin = celsius + 273.15;

    printf("Temperatura en grados Celsius: %.2f\n", celsius);
    printf("Temperatura en grados Kelvin: %.2f\n", kelvin);

    return 0;
}