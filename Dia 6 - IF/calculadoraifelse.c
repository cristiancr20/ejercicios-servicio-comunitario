#include <stdio.h>

int main()
{
    double num1, num2;
    char operacion;
    double resultado;

    printf("Introduce el primer número: ");
    scanf("%lf", &num1);

    printf("Introduce el segundo número: ");
    scanf("%lf", &num2);

    printf("Introduce la operación (+, -, *, /): ");
    scanf(" %c", &operacion);

    if (operacion == '+')
    {
        resultado = num1 + num2;
    }
    else if (operacion == '-')
    {
        resultado = num1 - num2;
    }
    else if (operacion == '*')
    {
        resultado = num1 * num2;
    }
    else if (operacion == '/')
    {
        if (num2 != 0)
        {
            resultado = num1 / num2;
        }
        else
        {
            printf("Error: División por cero no permitida.\n");
            return 1;
        }
    }
    else
    {
        printf("Error: Operación no válida.\n");
        return 1;
    }

    printf("El resultado de %lf %c %lf es: %lf\n", num1, operacion, num2, resultado);

    return 0;
}