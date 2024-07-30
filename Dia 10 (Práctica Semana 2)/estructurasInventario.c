#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INVENTARIO 100
#define MAX_NOMBRE 50
    
typedef struct {
    char nombre[MAX_NOMBRE];
    int cantidad;
    float precio;
} Articulo;

void agregarArticulo(Articulo inventario[], int *contador);
void eliminarArticulo(Articulo inventario[], int *contador);
void mostrarInventario(Articulo inventario[], int contador);
void buscarArticulo(Articulo inventario[], int contador);
void menu();

int main() {
    Articulo inventario[MAX_INVENTARIO];
    int contador = 0;
    int opcion;
    
    do {
        menu();
        scanf("%d", &opcion);
        
        switch (opcion) {
            case 1:
                agregarArticulo(inventario, &contador);
                break;
            case 2:
                eliminarArticulo(inventario, &contador);
                break;
            case 3:
                mostrarInventario(inventario, contador);
                break;
            case 4:
                buscarArticulo(inventario, contador);
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

void agregarArticulo(Articulo inventario[], int *contador) {
    if (*contador >= MAX_INVENTARIO) {
        printf("Inventario lleno. No se puede agregar más artículos.\n");
        return;
    }
    
    Articulo nuevoArticulo;
    
    printf("Ingrese el nombre del artículo: ");
    getchar(); // Para consumir el '\n' pendiente del buffer
    fgets(nuevoArticulo.nombre, MAX_NOMBRE, stdin);
    nuevoArticulo.nombre[strcspn(nuevoArticulo.nombre, "\n")] = '\0'; // Eliminar el salto de línea
    
    printf("Ingrese la cantidad del artículo: ");
    scanf("%d", &nuevoArticulo.cantidad);
    
    printf("Ingrese el precio del artículo: ");
    scanf("%f", &nuevoArticulo.precio);
    
    inventario[*contador] = nuevoArticulo;
    (*contador)++;
    
    printf("Artículo agregado con éxito.\n");
}

void eliminarArticulo(Articulo inventario[], int *contador) {
    if (*contador == 0) {
        printf("El inventario está vacío.\n");
        return;
    }
    
    char nombre[MAX_NOMBRE];
    printf("Ingrese el nombre del artículo a eliminar: ");
    getchar(); // Para consumir el '\n' pendiente del buffer
    fgets(nombre, MAX_NOMBRE, stdin);
    nombre[strcspn(nombre, "\n")] = '\0'; // Eliminar el salto de línea
    
    int encontrado = 0;
    for (int i = 0; i < *contador; i++) {
        if (strcmp(inventario[i].nombre, nombre) == 0) {
            encontrado = 1;
            for (int j = i; j < *contador - 1; j++) {
                inventario[j] = inventario[j + 1];
            }
            (*contador)--;
            printf("Artículo eliminado con éxito.\n");
            break;
        }
    }
    
    if (!encontrado) {
        printf("Artículo no encontrado.\n");
    }
}

void mostrarInventario(Articulo inventario[], int contador) {
    if (contador == 0) {
        printf("El inventario está vacío.\n");
        return;
    }
    
    printf("\nInventario:\n");
    printf("============================================\n");
    for (int i = 0; i < contador; i++) {
        printf("Nombre: %s\n", inventario[i].nombre);
        printf("Cantidad: %d\n", inventario[i].cantidad);
        printf("Precio: %.2f\n", inventario[i].precio);
        printf("============================================\n");
    }
}

void buscarArticulo(Articulo inventario[], int contador) {
    if (contador == 0) {
        printf("El inventario está vacío.\n");
        return;
    }
    
    char nombre[MAX_NOMBRE];
    printf("Ingrese el nombre del artículo a buscar: ");
    getchar(); // Para consumir el '\n' pendiente del buffer
    fgets(nombre, MAX_NOMBRE, stdin);
    nombre[strcspn(nombre, "\n")] = '\0'; // Eliminar el salto de línea
    
    int encontrado = 0;
    for (int i = 0; i < contador; i++) {
        if (strcmp(inventario[i].nombre, nombre) == 0) {
            encontrado = 1;
            printf("Artículo encontrado:\n");
            printf("Nombre: %s\n", inventario[i].nombre);
            printf("Cantidad: %d\n", inventario[i].cantidad);
            printf("Precio: %.2f\n", inventario[i].precio);
            break;
        }
    }
    
    if (!encontrado) {
        printf("Artículo no encontrado.\n");
    }
}

void menu() {
    printf("\nGestión de Inventario\n");
    printf("1. Agregar artículo\n");
    printf("2. Eliminar artículo\n");
    printf("3. Mostrar inventario\n");
    printf("4. Buscar artículo\n");
    printf("5. Salir\n");
    printf("Ingrese una opción: ");
}
