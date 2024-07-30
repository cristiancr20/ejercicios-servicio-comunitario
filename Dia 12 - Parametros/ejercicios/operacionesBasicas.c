#include <stdio.h>

// Definición de la estructura para números complejos
struct Complejo {
    float real;
    float imag;
};

// Función para sumar dos números complejos
struct Complejo sumarComplejos(struct Complejo c1, struct Complejo c2) {
    struct Complejo resultado;
    resultado.real = c1.real + c2.real;
    resultado.imag = c1.imag + c2.imag;
    return resultado;
}

// Función para restar dos números complejos
struct Complejo restarComplejos(struct Complejo c1, struct Complejo c2) {
    struct Complejo resultado;
    resultado.real = c1.real - c2.real;
    resultado.imag = c1.imag - c2.imag;
    return resultado;
}

// Función para multiplicar dos números complejos
struct Complejo multiplicarComplejos(struct Complejo c1, struct Complejo c2) {
    struct Complejo resultado;
    resultado.real = c1.real * c2.real - c1.imag * c2.imag;
    resultado.imag = c1.real * c2.imag + c1.imag * c2.real;
    return resultado;
}

int main() {
    struct Complejo num1, num2, resultadoSuma, resultadoResta, resultadoMultiplicacion;

    // Ingresar primer número complejo
    printf("Ingresa la parte real del primer número complejo: ");
    scanf("%f", &num1.real);
    printf("Ingresa la parte imaginaria del primer número complejo: ");
    scanf("%f", &num1.imag);

    // Ingresar segundo número complejo
    printf("Ingresa la parte real del segundo número complejo: ");
    scanf("%f", &num2.real);
    printf("Ingresa la parte imaginaria del segundo número complejo: ");
    scanf("%f", &num2.imag);

    // Realizar las operaciones
    resultadoSuma = sumarComplejos(num1, num2);
    resultadoResta = restarComplejos(num1, num2);
    resultadoMultiplicacion = multiplicarComplejos(num1, num2);

    // Mostrar resultados
    printf("\nSuma de los dos números complejos: %.2f + %.2fi\n", resultadoSuma.real, resultadoSuma.imag);
    printf("Resta de los dos números complejos: %.2f + %.2fi\n", resultadoResta.real, resultadoResta.imag);
    printf("Multiplicación de los dos números complejos: %.2f + %.2fi\n", resultadoMultiplicacion.real, resultadoMultiplicacion.imag);

    return 0;
}
