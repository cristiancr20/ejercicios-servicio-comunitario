#include <stdio.h> // Entrada y salida de datos

int main() {
// declarar variables
double ingresos;
int dependientes;
double tasaImpuesto;

// solicitar al usario los valores
printf("Ingrese los ingresos anuales: ");
scanf("%lf", &ingresos);
printf("Ingrese el número de dependientes: ");
scanf("%d", &dependientes);

// realizar la operacion con el if
if (ingresos <= 10000) {
tasaImpuesto = 0.0;
} else if (ingresos <= 30000) {
tasaImpuesto = 0.10;
} else if (ingresos <= 50000) {
tasaImpuesto = 0.20;
} else {
tasaImpuesto = 0.30;
}

// Reducir un 5% adicional si la persona tiene dependientes
if (dependientes > 0) {
tasaImpuesto -= 0.05;
}

double impuesto = ingresos * tasaImpuesto;

printf("El impuesto sobre la renta es: %.2f\n", impuesto);

return 0;
}