#include <stdio.h>
#include <string.h>

#define MAX_PRODUCTOS 100
#define MAX_NOMBRE 50

typedef struct {
    char nombre[MAX_NOMBRE];
    int cantidad;
    float precio;
} Producto;

int main() {
    Producto inventario[MAX_PRODUCTOS];
    int numProductos = 0;
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

        if (opcion == 1) {
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
        } else if (opcion == 2) {
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
                    break;
                }
            }
            if (i == numProductos) {
                printf("Producto no encontrado.\n");
            }
        } else if (opcion == 3) {
            char nombre[MAX_NOMBRE];
            printf("Ingrese el nombre del producto a buscar: ");
            scanf("%s", nombre);

            int i;
            for (i = 0; i < numProductos; i++) {
                if (strcmp(inventario[i].nombre, nombre) == 0) {
                    printf("Producto encontrado: %s, Cantidad: %d, Precio: %.2f\n",
                           inventario[i].nombre, inventario[i].cantidad, inventario[i].precio);
                    break;
                }
            }
            if (i == numProductos) {
                printf("Producto no encontrado.\n");
            }
        } else if (opcion == 4) {
            if (numProductos == 0) {
                printf("El inventario está vacío.\n");
            } else {
                printf("Inventario de productos:\n");
                for (int i = 0; i < numProductos; i++) {
                    printf("%d. Nombre: %s, Cantidad: %d, Precio: %.2f\n",
                           i + 1, inventario[i].nombre, inventario[i].cantidad, inventario[i].precio);
                }
            }
        } else if (opcion == 5) {
            printf("Saliendo del programa.\n");
        } else {
            printf("Opción no válida. Intente nuevamente.\n");
        }
    } while (opcion != 5);

    return 0;
}
