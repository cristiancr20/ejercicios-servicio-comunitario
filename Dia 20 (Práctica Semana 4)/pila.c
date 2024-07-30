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
    Nodo* cima;
} Pila;

void inicializarPila(Pila* pila) {
    pila->cima = NULL;
}

int esVacia(Pila* pila) {
    return pila->cima == NULL;
}

void apilar(Pila* pila, Persona p) {
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    nuevoNodo->persona = p;
    nuevoNodo->siguiente = pila->cima;
    pila->cima = nuevoNodo;
}

Persona desapilar(Pila* pila) {
    if (!esVacia(pila)) {
        Nodo* temp = pila->cima;
        Persona p = temp->persona;
        pila->cima = pila->cima->siguiente;
        free(temp);
        return p;
    } else {
        Persona p;
        strcpy(p.nombre, ""); // Empty string to indicate empty stack
        return p;
    }
}

void mostrarPila(Pila* pila) {
    Nodo* actual = pila->cima;
    while (actual != NULL) {
        printf("Nombre: %s, Edad: %d, Color Favorito: %s\n", actual->persona.nombre, actual->persona.edad, actual->persona.colorFavorito);
        actual = actual->siguiente;
    }
}

int main() {
    Pila pila;
    inicializarPila(&pila);
    int opcion;
    Persona p;

    do {
        printf("Menu:\n");
        printf("1. Agregar persona a la pila\n");
        printf("2. Eliminar persona de la pila\n");
        printf("3. Ver pila\n");
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
                apilar(&pila, p);
                break;
            case 2:
                p = desapilar(&pila);
                if (strlen(p.nombre) > 0) {
                    printf("Se eliminó: Nombre: %s, Edad: %d, Color Favorito: %s\n", p.nombre, p.edad, p.colorFavorito);
                } else {
                    printf("La pila está vacía.\n");
                }
                break;
            case 3:
                mostrarPila(&pila);
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
