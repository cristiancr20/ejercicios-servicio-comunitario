#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
    int dato;
    struct Nodo* siguiente;
} Nodo;

Nodo* crearNodo(int dato) {
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    nuevoNodo->dato = dato;
    nuevoNodo->siguiente = NULL;
    return nuevoNodo;
}

void insertarFinal(Nodo** cabeza, int dato) {
    Nodo* nuevoNodo = crearNodo(dato);
    if (*cabeza == NULL) {
        *cabeza = nuevoNodo;
    } else {
        Nodo* temp = *cabeza;
        while (temp->siguiente != NULL) {
            temp = temp->siguiente;
        }
        temp->siguiente = nuevoNodo;
    }
}

void eliminarNodo(Nodo** cabeza, int dato) {
    Nodo* temp = *cabeza;
    Nodo* prev = NULL;

    if (temp != NULL && temp->dato == dato) {
        *cabeza = temp->siguiente;
        free(temp);
        return;
    }

    while (temp != NULL && temp->dato != dato) {
        prev = temp;
        temp = temp->siguiente;
    }

    if (temp == NULL) return;

    prev->siguiente = temp->siguiente;
    free(temp);
}

Nodo* buscar(Nodo* cabeza, int dato) {
    Nodo* temp = cabeza;
    while (temp != NULL) {
        if (temp->dato == dato) return temp;
        temp = temp->siguiente;
    }
    return NULL;
}

void imprimirLista(Nodo* cabeza) {
    Nodo* temp = cabeza;
    while (temp != NULL) {
        printf("%d -> ", temp->dato);
        temp = temp->siguiente;
    }
    printf("NULL\n");
}

int main() {
    Nodo* cabeza = NULL;
    int opcion, valor;

    do {
        printf("\nMenu:\n");
        printf("1. Insertar un nodo\n");
        printf("2. Eliminar un nodo\n");
        printf("3. Buscar un nodo\n");
        printf("4. Imprimir la lista\n");
        printf("5. Salir\n");
        printf("Elige una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("Introduce un valor para insertar: ");
                scanf("%d", &valor);
                insertarFinal(&cabeza, valor);
                break;
            case 2:
                printf("Introduce un valor para eliminar: ");
                scanf("%d", &valor);
                eliminarNodo(&cabeza, valor);
                break;
            case 3:
                printf("Introduce un valor para buscar: ");
                scanf("%d", &valor);
                printf("Buscar %d: %s\n", valor, buscar(cabeza, valor) ? "Encontrado" : "No encontrado");
                break;
            case 4:
                printf("Lista: ");
                imprimirLista(cabeza);
                break;
            case 5:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opcion invalida\n");
        }
    } while (opcion != 5);

    return 0;
}