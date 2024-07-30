#include <stdio.h> // Entrada y salida de datos

int main() {
char operator;
double num1, num2;
int valid = 1;

// solicitar al usario la informacion
printf("Ingrese el primer número: ");
scanf("%lf", &num1);
printf("Ingrese el segundo número: ");
scanf("%lf", &num2);
printf("Ingrese la operación a realizar (+, -, *, /): ");
scanf(" %c", &operator);

// realizar las operaciones segun el operador que elegio el usario
if (operator == '+') {
printf("%.2lf + %.2lf = %.2lf\n", num1, num2, num1 + num2);
} else if (operator == '-') {
printf("%.2lf - %.2lf = %.2lf\n", num1, num2, num1 - num2);
} else if (operator == '*') {
printf("%.2lf * %.2lf = %.2lf\n", num1, num2, num1 * num2);
} else if (operator == '/') {
if (num2 != 0) {
printf("%.2lf / %.2lf = %.2lf\n", num1, num2, num1 / num2);
} else {
printf("Error: División por cero no permitida.\n");
valid = 0;
}
} else {
printf("Error: Operación no válida.\n");
valid = 0;
}

return valid;
}