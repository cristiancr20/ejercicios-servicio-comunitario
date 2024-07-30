#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Nodo {
    int dato;
    struct Nodo* siguiente;
} Nodo;

typedef struct Cola {
    Nodo* frente;
    Nodo* final;
} Cola;

Cola* crearCola() {
    Cola* cola = (Cola*)malloc(sizeof(Cola));
    cola->frente = NULL;
    cola->final = NULL;
    return cola;
}

void encolar(Cola* cola, int dato) {
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    nuevoNodo->dato = dato;
    nuevoNodo->siguiente = NULL;
    if (cola->final == NULL) {
        cola->frente = cola->final = nuevoNodo;
        return;
    }
    cola->final->siguiente = nuevoNodo;
    cola->final = nuevoNodo;
}

int desencolar(Cola* cola) {
    if (cola->frente == NULL) {
        printf("Cola vacía\n");
        return -1;
    }
    Nodo* temp = cola->frente;
    int dato = temp->dato;
    cola->frente = temp->siguiente;
    if (cola->frente == NULL) {
        cola->final = NULL;
    }
    free(temp);
    return dato;
}

int frente(Cola* cola) {
    if (cola->frente == NULL) {
        printf("Cola vacía\n");
        return -1;
    }
    return cola->frente->dato;
}

bool estaVacia(Cola* cola) {
    return cola->frente == NULL;
}

void mostrarCola(Cola* cola) {
    if (estaVacia(cola)) {
        printf("La cola está vacía\n");
    } else {
        printf("Cola: ");
        Nodo* actual = cola->frente;
        while (actual != NULL) {
            printf("%d ", actual->dato);
            actual = actual->siguiente;
        }
        printf("\n");
    }
}

int main() {
    Cola* cola = crearCola();
    int opcion, valor;

    do {
        printf("\nMenu:\n");
        printf("1. Encolar\n");
        printf("2. Desencolar\n");
        printf("3. Ver frente\n");
        printf("4. Verificar si la cola está vacía\n");
        printf("5. Salir\n");
        printf("Elige una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("Introduce un valor para encolar: ");
                scanf("%d", &valor);
                encolar(cola, valor);
                break;
            case 2:
                printf("Desencolar: %d\n", desencolar(cola));
                break;
            case 3:
                printf("Elemento frontal: %d\n", frente(cola));
                break;
            case 4:
                if (estaVacia(cola)) {
                    printf("Cola vacía: Sí\n");
                } else {
                    printf("Cola vacía: No\n");
                    mostrarCola(cola);
                }
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
