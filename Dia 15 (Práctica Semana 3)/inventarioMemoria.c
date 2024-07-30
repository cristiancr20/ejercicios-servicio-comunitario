#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Producto {
    char nombre[50];
    int cantidad;
    float precio;
    struct Producto* siguiente;
} Producto;

static int totalProductos = 0; // Variable estática

Producto* crearProducto(char* nombre, int cantidad, float precio) {
    Producto* nuevoProducto = (Producto*)malloc(sizeof(Producto));
    if (nuevoProducto == NULL) {
        printf("Error en la asignación de memoria.\n");
        exit(1);
    }
    strcpy(nuevoProducto->nombre, nombre);
    nuevoProducto->cantidad = cantidad;
    nuevoProducto->precio = precio;
    nuevoProducto->siguiente = NULL;
    totalProductos++;
    return nuevoProducto;
}

Producto* agregarProducto(Producto* cabeza, char* nombre, int cantidad, float precio) {
    if (cabeza == NULL) {
        return crearProducto(nombre, cantidad, precio);
    }
    cabeza->siguiente = agregarProducto(cabeza->siguiente, nombre, cantidad, precio);
    return cabeza;
}

Producto* eliminarProducto(Producto* cabeza, char* nombre) {
    if (cabeza == NULL) {
        printf("Producto no encontrado.\n");
        return NULL;
    }
    if (strcmp(cabeza->nombre, nombre) == 0) {
        Producto* temp = cabeza->siguiente;
        free(cabeza);
        totalProductos--;
        return temp;
    }
    cabeza->siguiente = eliminarProducto(cabeza->siguiente, nombre);
    return cabeza;
}

Producto* buscarProducto(Producto* cabeza, char* nombre) {
    if (cabeza == NULL) {
        return NULL;
    }
    if (strcmp(cabeza->nombre, nombre) == 0) {
        return cabeza;
    }
    return buscarProducto(cabeza->siguiente, nombre);
}

void mostrarInventario(Producto* cabeza) {
    if (cabeza == NULL) {
        return;
    }
    printf("Nombre: %s, Cantidad: %d, Precio: %.2f\n", cabeza->nombre, cabeza->cantidad, cabeza->precio);
    mostrarInventario(cabeza->siguiente);
}

void liberarMemoria(Producto* cabeza) {
    if (cabeza == NULL) {
        return;
    }
    liberarMemoria(cabeza->siguiente);
    free(cabeza);
}

int main() {
    Producto* inventario = NULL;
    int opcion;
    char nombre[50];
    int cantidad;
    float precio;

    do {
        printf("\n1. Agregar Producto\n2. Eliminar Producto\n3. Buscar Producto\n4. Mostrar Inventario\n5. Salir\n");
        printf("Elige una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("Ingresa el nombre del producto: ");
                scanf("%s", nombre);
                printf("Ingresa la cantidad: ");
                scanf("%d", &cantidad);
                printf("Ingresa el precio: ");
                scanf("%f", &precio);
                inventario = agregarProducto(inventario, nombre, cantidad, precio);
                break;
            case 2:
                printf("Ingresa el nombre del producto a eliminar: ");
                scanf("%s", nombre);
                inventario = eliminarProducto(inventario, nombre);
                break;
            case 3:
                printf("Ingresa el nombre del producto a buscar: ");
                scanf("%s", nombre);
                Producto* producto = buscarProducto(inventario, nombre);
                if (producto != NULL) {
                    printf("Producto encontrado - Nombre: %s, Cantidad: %d, Precio: %.2f\n", producto->nombre, producto->cantidad, producto->precio);
                } else {
                    printf("Producto no encontrado.\n");
                }
                break;
            case 4:
                printf("Inventario:\n");
                mostrarInventario(inventario);
                printf("Total de productos: %d\n", totalProductos);
                break;
            case 5:
                liberarMemoria(inventario);
                break;
            default:
                printf("Opción inválida.\n");
        }
    } while (opcion != 5);

    return 0;
}
