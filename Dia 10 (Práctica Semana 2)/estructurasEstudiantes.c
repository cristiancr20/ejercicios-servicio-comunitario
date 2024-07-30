#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ESTUDIANTES 100
#define MAX_NOMBRE 50

typedef struct {
    char nombre[MAX_NOMBRE];
    int id;
    int edad;
    float promedio;
} Estudiante;

void agregarEstudiante(Estudiante estudiantes[], int *contador);
void eliminarEstudiante(Estudiante estudiantes[], int *contador);
void mostrarEstudiantes(Estudiante estudiantes[], int contador);
void buscarEstudiante(Estudiante estudiantes[], int contador);
void menu();

int main() {
    Estudiante estudiantes[MAX_ESTUDIANTES];
    int contador = 0;
    int opcion;
    
    do {
        menu();
        scanf("%d", &opcion);
        
        switch (opcion) {
            case 1:
                agregarEstudiante(estudiantes, &contador);
                break;
            case 2:
                eliminarEstudiante(estudiantes, &contador);
                break;
            case 3:
                mostrarEstudiantes(estudiantes, contador);
                break;
            case 4:
                buscarEstudiante(estudiantes, contador);
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

void agregarEstudiante(Estudiante estudiantes[], int *contador) {
    if (*contador >= MAX_ESTUDIANTES) {
        printf("Capacidad máxima de estudiantes alcanzada. No se puede agregar más estudiantes.\n");
        return;
    }
    
    Estudiante nuevoEstudiante;
    
    printf("Ingrese el nombre del estudiante: ");
    getchar(); // Para consumir el '\n' pendiente del buffer
    fgets(nuevoEstudiante.nombre, MAX_NOMBRE, stdin);
    nuevoEstudiante.nombre[strcspn(nuevoEstudiante.nombre, "\n")] = '\0'; // Eliminar el salto de línea
    
    printf("Ingrese el ID del estudiante: ");
    scanf("%d", &nuevoEstudiante.id);
    
    printf("Ingrese la edad del estudiante: ");
    scanf("%d", &nuevoEstudiante.edad);
    
    printf("Ingrese el promedio del estudiante: ");
    scanf("%f", &nuevoEstudiante.promedio);
    
    estudiantes[*contador] = nuevoEstudiante;
    (*contador)++;
    
    printf("Estudiante agregado con éxito.\n");
}

void eliminarEstudiante(Estudiante estudiantes[], int *contador) {
    if (*contador == 0) {
        printf("No hay estudiantes en la lista.\n");
        return;
    }
    
    int id;
    printf("Ingrese el ID del estudiante a eliminar: ");
    scanf("%d", &id);
    
    int encontrado = 0;
    for (int i = 0; i < *contador; i++) {
        if (estudiantes[i].id == id) {
            encontrado = 1;
            for (int j = i; j < *contador - 1; j++) {
                estudiantes[j] = estudiantes[j + 1];
            }
            (*contador)--;
            printf("Estudiante eliminado con éxito.\n");
            break;
        }
    }
    
    if (!encontrado) {
        printf("Estudiante no encontrado.\n");
    }
}

void mostrarEstudiantes(Estudiante estudiantes[], int contador) {
    if (contador == 0) {
        printf("No hay estudiantes en la lista.\n");
        return;
    }
    
    printf("\nLista de Estudiantes:\n");
    printf("=====================================================\n");
    for (int i = 0; i < contador; i++) {
        printf("Nombre: %s\n", estudiantes[i].nombre);
        printf("ID: %d\n", estudiantes[i].id);
        printf("Edad: %d\n", estudiantes[i].edad);
        printf("Promedio: %.2f\n", estudiantes[i].promedio);
        printf("=====================================================\n");
    }
}

void buscarEstudiante(Estudiante estudiantes[], int contador) {
    if (contador == 0) {
        printf("No hay estudiantes en la lista.\n");
        return;
    }
    
    int id;
    printf("Ingrese el ID del estudiante a buscar: ");
    scanf("%d", &id);
    
    int encontrado = 0;
    for (int i = 0; i < contador; i++) {
        if (estudiantes[i].id == id) {
            encontrado = 1;
            printf("Estudiante encontrado:\n");
            printf("Nombre: %s\n", estudiantes[i].nombre);
            printf("ID: %d\n", estudiantes[i].id);
            printf("Edad: %d\n", estudiantes[i].edad);
            printf("Promedio: %.2f\n", estudiantes[i].promedio);
            break;
        }
    }
    
    if (!encontrado) {
        printf("Estudiante no encontrado.\n");
    }
}

void menu() {
    printf("\nSistema de Gestión de Estudiantes\n");
    printf("1. Agregar estudiante\n");
    printf("2. Eliminar estudiante\n");
    printf("3. Mostrar todos los estudiantes\n");
    printf("4. Buscar estudiante por ID\n");
    printf("5. Salir\n");
    printf("Ingrese una opción: ");
}
