#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nombre[50];
    int cantidad;
    float precio;
} Producto;

static Producto *inventario = NULL; // Variable estática global
static int tamanoInventario = 0;

void agregarProducto() {
    Producto nuevoProducto;
    printf("Ingresa el nombre del producto: ");
    scanf("%s", nuevoProducto.nombre);
    printf("Ingresa la cantidad: ");
    scanf("%d", &nuevoProducto.cantidad);
    printf("Ingresa el precio: ");
    scanf("%f", &nuevoProducto.precio);

    inventario = realloc(inventario, (tamanoInventario + 1) * sizeof(Producto));
    inventario[tamanoInventario++] = nuevoProducto;
}

void eliminarProducto() {
    char nombre[50];
    printf("Ingresa el nombre del producto a eliminar: ");
    scanf("%s", nombre);

    for (int i = 0; i < tamanoInventario; i++) {
        if (strcmp(inventario[i].nombre, nombre) == 0) {
            for (int j = i; j < tamanoInventario - 1; j++) {
                inventario[j] = inventario[j + 1];
            }
            inventario = realloc(inventario, (--tamanoInventario) * sizeof(Producto));
            printf("Producto eliminado\n");
            return;
        }
    }
    printf("Producto no encontrado\n");
}

void mostrarInventario() {
    printf("Inventario:\n");
    for (int i = 0; i < tamanoInventario; i++) {
        printf("Nombre: %s, Cantidad: %d, Precio: %.2f\n", inventario[i].nombre, inventario[i].cantidad, inventario[i].precio);
    }
}

int main() {
    int opcion;

    while (1) {
        printf("\n1. Agregar Producto\n2. Eliminar Producto\n3. Mostrar Inventario\n4. Salir\n");
        printf("Elige una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                agregarProducto();
                break;
            case 2:
                eliminarProducto();
                break;
            case 3:
                mostrarInventario();
                break;
            case 4:
                free(inventario);
                return 0;
            default:
                printf("Opción inválida\n");
        }
    }
}
