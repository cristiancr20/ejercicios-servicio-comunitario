#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nombre[50];
    int edad;
    char colorFavorito[20];
} Persona;

typedef struct Nodo {
    Persona persona;
    struct Nodo* siguiente;
} Nodo;

typedef struct {
    Nodo* frente;
    Nodo* final;
} Cola;

void inicializarCola(Cola* cola) {
    cola->frente = NULL;
    cola->final = NULL;
}

int esVacia(Cola* cola) {
    return cola->frente == NULL;
}

void encolar(Cola* cola, Persona p) {
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    nuevoNodo->persona = p;
    nuevoNodo->siguiente = NULL;
    if (esVacia(cola)) {
        cola->frente = nuevoNodo;
    } else {
        cola->final->siguiente = nuevoNodo;
    }
    cola->final = nuevoNodo;
}

Persona desencolar(Cola* cola) {
    if (!esVacia(cola)) {
        Nodo* temp = cola->frente;
        Persona p = temp->persona;
        cola->frente = cola->frente->siguiente;
        if (cola->frente == NULL) {
            cola->final = NULL;
        }
        free(temp);
        return p;
    } else {
        Persona p;
        strcpy(p.nombre, ""); // Empty string to indicate empty queue
        return p;
    }
}

void mostrarCola(Cola* cola) {
    Nodo* actual = cola->frente;
    while (actual != NULL) {
        printf("Nombre: %s, Edad: %d, Color Favorito: %s\n", actual->persona.nombre, actual->persona.edad, actual->persona.colorFavorito);
        actual = actual->siguiente;
    }
}

int main() {
    Cola cola;
    inicializarCola(&cola);
    int opcion;
    Persona p;

    do {
        printf("Menu:\n");
        printf("1. Agregar persona a la cola\n");
        printf("2. Eliminar persona de la cola\n");
        printf("3. Ver cola\n");
        printf("4. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("Ingrese nombre: ");
                scanf("%s", p.nombre);
                printf("Ingrese edad: ");
                scanf("%d", &p.edad);
                printf("Ingrese color favorito: ");
                scanf("%s", p.colorFavorito);
                encolar(&cola, p);
                break;
            case 2:
                p = desencolar(&cola);
                if (strlen(p.nombre) > 0) {
                    printf("Se eliminó: Nombre: %s, Edad: %d, Color Favorito: %s\n", p.nombre, p.edad, p.colorFavorito);
                } else {
                    printf("La cola está vacía.\n");
                }
                break;
            case 3:
                mostrarCola(&cola);
                break;
            case 4:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opción no válida.\n");
        }
    } while (opcion != 4);

    return 0;
}
