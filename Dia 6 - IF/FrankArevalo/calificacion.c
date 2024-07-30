#include <stdio.h> // Entrada y salida de datos

int main() {
// declarar variables
int notas[5];
int suma = 0;
float media;
char calificacion;

// solicitar al usario los valore
printf("Ingrese las 5 notas del estudiante:\n");

for (int i = 0; i < 5; i++) {
printf("Nota %d: ", i + 1);
scanf("%d", &notas[i]);

// Si alguna nota es menor a 40, la calificación es F
if (notas[i] < 40) {
calificacion = 'F';
printf("La calificacion del estudiante es: %c\n", calificacion);
return 0; // Terminar el programa si hay una nota menor a 40
}

suma += notas[i];
}

media = suma / (float)5;
printf("La media es: %f\n", media);


if (media >= 90) {
calificacion = 'A';
} else if (media >= 80) {
calificacion = 'B';
} else if (media >= 70) {
calificacion = 'C';
} else if (media >= 60) {
calificacion = 'D';
} else {
calificacion = 'F';
}

printf("La calificacion del estudiante es: %c\n", calificacion);

return 0;
}