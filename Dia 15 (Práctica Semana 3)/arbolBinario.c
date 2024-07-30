#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
    int dato;
    struct Nodo *izquierdo;
    struct Nodo *derecho;
} Nodo;

Nodo* crearNodo(int dato) {
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    if (nuevoNodo == NULL) {
        printf("Error en la asignación de memoria.\n");
        exit(1);
    }
    nuevoNodo->dato = dato;
    nuevoNodo->izquierdo = NULL;
    nuevoNodo->derecho = NULL;
    return nuevoNodo;
}

Nodo* insertar(Nodo* raiz, int dato) {
    if (raiz == NULL) {
        return crearNodo(dato);
    }
    if (dato < raiz->dato) {
        raiz->izquierdo = insertar(raiz->izquierdo, dato);
    } else if (dato > raiz->dato) {
        raiz->derecho = insertar(raiz->derecho, dato);
    }
    return raiz;
}

Nodo* buscar(Nodo* raiz, int dato) {
    if (raiz == NULL || raiz->dato == dato) {
        return raiz;
    }
    if (dato < raiz->dato) {
        return buscar(raiz->izquierdo, dato);
    } else {
        return buscar(raiz->derecho, dato);
    }
}

void recorridoEnOrden(Nodo* raiz) {
    if (raiz != NULL) {
        recorridoEnOrden(raiz->izquierdo);
        printf("%d ", raiz->dato);
        recorridoEnOrden(raiz->derecho);
    }
}

void liberarArbol(Nodo* raiz) {
    if (raiz != NULL) {
        liberarArbol(raiz->izquierdo);
        liberarArbol(raiz->derecho);
        free(raiz);
    }
}

int main() {
    Nodo* raiz = NULL;
    int opcion, dato;

    do {
        printf("\n1. Insertar\n2. Buscar\n3. Recorrido en orden\n4. Salir\n");
        printf("Elige una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("Ingresa un número para insertar: ");
                scanf("%d", &dato);
                raiz = insertar(raiz, dato);
                break;
            case 2:
                printf("Ingresa un número para buscar: ");
                scanf("%d", &dato);
                Nodo* resultado = buscar(raiz, dato);
                if (resultado != NULL) {
                    printf("Número %d encontrado en el árbol.\n", dato);
                } else {
                    printf("Número %d no encontrado en el árbol.\n", dato);
                }
                break;
            case 3:
                printf("Recorrido en orden: ");
                recorridoEnOrden(raiz);
                printf("\n");
                break;
            case 4:
                liberarArbol(raiz);
                printf("Memoria liberada.\n");
                break;
            default:
                printf("Opción inválida.\n");
        }
    } while (opcion != 4);

    return 0;
}
