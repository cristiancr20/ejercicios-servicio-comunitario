#include <stdio.h>
#include <string.h>

#define MAX_PRODUCTOS 100
#define MAX_NOMBRE 50

typedef struct {
    char nombre[MAX_NOMBRE];
    int cantidad;
    float precio;
} Producto;

Producto inventario[MAX_PRODUCTOS];
int numProductos = 0;

void agregarProducto() {
    if (numProductos < MAX_PRODUCTOS) {
        Producto nuevoProducto;
        printf("Ingrese el nombre del producto: ");
        scanf("%s", nuevoProducto.nombre);
        printf("Ingrese la cantidad del producto: ");
        scanf("%d", &nuevoProducto.cantidad);
        printf("Ingrese el precio del producto: ");
        scanf("%f", &nuevoProducto.precio);

        inventario[numProductos] = nuevoProducto;
        numProductos++;
        printf("Producto agregado exitosamente.\n");
    } else {
        printf("Inventario lleno. No se pueden agregar más productos.\n");
    }
}

void eliminarProducto() {
    char nombre[MAX_NOMBRE];
    printf("Ingrese el nombre del producto a eliminar: ");
    scanf("%s", nombre);

    int i, j;
    for (i = 0; i < numProductos; i++) {
        if (strcmp(inventario[i].nombre, nombre) == 0) {
            for (j = i; j < numProductos - 1; j++) {
                inventario[j] = inventario[j + 1];
            }
            numProductos--;
            printf("Producto eliminado exitosamente.\n");
            return;
        }
    }
    printf("Producto no encontrado.\n");
}

void buscarProducto() {
    char nombre[MAX_NOMBRE];
    printf("Ingrese el nombre del producto a buscar: ");
    scanf("%s", nombre);

    int i;
    for (i = 0; i < numProductos; i++) {
        if (strcmp(inventario[i].nombre, nombre) == 0) {
            printf("Producto encontrado: %s, Cantidad: %d, Precio: %.2f\n",
                   inventario[i].nombre, inventario[i].cantidad, inventario[i].precio);
            return;
        }
    }
    printf("Producto no encontrado.\n");
}

void mostrarInventario() {
    if (numProductos == 0) {
        printf("El inventario está vacío.\n");
    } else {
        printf("Inventario de productos:\n");
        int i;
        for (i = 0; i < numProductos; i++) {
            printf("%d. Nombre: %s, Cantidad: %d, Precio: %.2f\n",
                   i + 1, inventario[i].nombre, inventario[i].cantidad, inventario[i].precio);
        }
    }
}

int main() {
    int opcion;

    do {
        printf("\nMenú de opciones:\n");
        printf("1. Agregar producto\n");
        printf("2. Eliminar producto\n");
        printf("3. Buscar producto por nombre\n");
        printf("4. Mostrar todos los productos\n");
        printf("5. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                agregarProducto();
                break;
            case 2:
                eliminarProducto();
                break;
            case 3:
                buscarProducto();
                break;
            case 4:
                mostrarInventario();
                break;
            case 5:
                printf("Saliendo del programa.\n");
                break;
            default:
                printf("Opción no válida. Intente nuevamente.\n");
        }
    } while (opcion != 5);

    return 0;
}
