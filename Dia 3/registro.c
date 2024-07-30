#include <stdio.h>
#include <stdbool.h>

// Definicion de constantes
#define GRAVEDAD 9.8
#define PI 3.1416
#define DIAS_SEMANA 7


int main(){
    // Definicion de variables
    char nombre[45];
    int edad;
    float altura;
    int es_estudiante_entrada;
    bool es_estudiante;

    // Entrada de valores
    printf("Introduce el nombre: ");
    scanf("%s", nombre);

    printf("Introduce el edad: ");
    scanf("%d", &edad);

    printf("Introduce el altura: ");
    scanf("%f", &altura);

    printf("Introduce el es estudiante: (0. Falso, 1. Verdadero): ");
    scanf("%d", &es_estudiante_entrada);

    // Es estudiante
    if (es_estudiante_entrada==1){
        es_estudiante = true;
    }
    else {
        es_estudiante = false;
    }

    // Es estudiante ternario
    // es_estudiante = (es_estudiante_entrada==1) ? true : false;

    // Mostrar informacion
    printf("---------INFORMACION REGISTRADA---------\n");
    printf("Nombre: %s\n", nombre);
    printf("Edad: %d\n", edad);
    printf("Altura: %.2f\n", altura);
    printf("Es estudiante: %d\n", es_estudiante);

    printf("---------CONSTANTES---------\n");
    printf("Gravedad: %.1f\n", GRAVEDAD);
    printf("Pi: %.4f\n", PI);
    printf("Dias de la semana: %d\n", DIAS_SEMANA);
    
    return 0;
}



