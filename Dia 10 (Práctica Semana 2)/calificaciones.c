#include <stdio.h>
#include <stdlib.h>

#define MAX_ESTUDIANTES 100

void ingresarCalificaciones(float calificaciones[], int *numEstudiantes);
float calcularPromedio(float calificaciones[], int numEstudiantes);
float calcularMaxima(float calificaciones[], int numEstudiantes);
float calcularMinima(float calificaciones[], int numEstudiantes);
void menu();

int main() {
    float calificaciones[MAX_ESTUDIANTES];
    int numEstudiantes = 0;
    int opcion;
    
    do {
        menu();
        scanf("%d", &opcion);
        
        switch (opcion) {
            case 1:
                ingresarCalificaciones(calificaciones, &numEstudiantes);
                break;
            case 2:
                if (numEstudiantes == 0) {
                    printf("No hay calificaciones ingresadas.\n");
                } else {
                    float promedio = calcularPromedio(calificaciones, numEstudiantes);
                    printf("El promedio de las calificaciones es: %.2f\n", promedio);
                }
                break;
            case 3:
                if (numEstudiantes == 0) {
                    printf("No hay calificaciones ingresadas.\n");
                } else {
                    float maxima = calcularMaxima(calificaciones, numEstudiantes);
                    printf("La calificación más alta es: %.2f\n", maxima);
                }
                break;
            case 4:
                if (numEstudiantes == 0) {
                    printf("No hay calificaciones ingresadas.\n");
                } else {
                    float minima = calcularMinima(calificaciones, numEstudiantes);
                    printf("La calificación más baja es: %.2f\n", minima);
                }
                break;
            case 5:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opción no válida. Intente de nuevo.\n");
                break;
        }
    } while (opcion != 5);
    
    return 0;
}

void ingresarCalificaciones(float calificaciones[], int *numEstudiantes) {
    int n;
    printf("Ingrese el número de calificaciones a ingresar: ");
    scanf("%d", &n);
    
    if (*numEstudiantes + n > MAX_ESTUDIANTES) {
        printf("No se pueden ingresar más de %d calificaciones.\n", MAX_ESTUDIANTES);
        return;
    }
    
    for (int i = 0; i < n; i++) {
        printf("Ingrese la calificación %d: ", *numEstudiantes + 1);
        scanf("%f", &calificaciones[*numEstudiantes]);
        (*numEstudiantes)++;
    }
    
    printf("Calificaciones ingresadas con éxito.\n");
}

float calcularPromedio(float calificaciones[], int numEstudiantes) {
    float suma = 0.0;
    for (int i = 0; i < numEstudiantes; i++) {
        suma += calificaciones[i];
    }
    return suma / numEstudiantes;
}

float calcularMaxima(float calificaciones[], int numEstudiantes) {
    float maxima = calificaciones[0];
    for (int i = 1; i < numEstudiantes; i++) {
        if (calificaciones[i] > maxima) {
            maxima = calificaciones[i];
        }
    }
    return maxima;
}

float calcularMinima(float calificaciones[], int numEstudiantes) {
    float minima = calificaciones[0];
    for (int i = 1; i < numEstudiantes; i++) {
        if (calificaciones[i] < minima) {
            minima = calificaciones[i];
        }
    }
    return minima;
}

void menu() {
    printf("\nSistema de Gestión de Calificaciones\n");
    printf("1. Ingresar calificaciones\n");
    printf("2. Calcular promedio\n");
    printf("3. Calificación más alta\n");
    printf("4. Calificación más baja\n");
    printf("5. Salir\n");
    printf("Ingrese una opción: ");
}
