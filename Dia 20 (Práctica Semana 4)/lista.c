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
    Nodo* cabeza;
} ListaEnlazada;

void inicializarLista(ListaEnlazada* lista) {
    lista->cabeza = NULL;
}

int esVacia(ListaEnlazada* lista) {
    return lista->cabeza == NULL;
}

void agregarPersona(ListaEnlazada* lista, Persona p) {
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    nuevoNodo->persona = p;
    nuevoNodo->siguiente = lista->cabeza;
    lista->cabeza = nuevoNodo;
}

Persona eliminarPersona(ListaEnlazada* lista) {
    if (!esVacia(lista)) {
        Nodo* temp = lista->cabeza;
        Persona p = temp->persona;
        lista->cabeza = lista->cabeza->siguiente;
        free(temp);
        return p;
    } else {
        Persona p;
        strcpy(p.nombre, ""); 
        return p;
    }
}

void mostrarLista(ListaEnlazada* lista) {
    Nodo* actual = lista->cabeza;
    while (actual != NULL) {
        printf("Nombre: %s, Edad: %d, Color Favorito: %s\n", actual->persona.nombre, actual->persona.edad, actual->persona.colorFavorito);
        actual = actual->siguiente;
    }
}

int main() {
    ListaEnlazada lista;
    inicializarLista(&lista);
    int opcion;
    Persona p;

    do {
        printf("Menu:\n");
        printf("1. Agregar persona a la lista\n");
        printf("2. Eliminar persona de la lista\n");
        printf("3. Ver lista\n");
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
                agregarPersona(&lista, p);
                break;
            case 2:
                p = eliminarPersona(&lista);
                if (strlen(p.nombre) > 0) {
                    printf("Se eliminó: Nombre: %s, Edad: %d, Color Favorito: %s\n", p.nombre, p.edad, p.colorFavorito);
                } else {
                    printf("La lista está vacía.\n");
                }
                break;
            case 3:
                mostrarLista(&lista);
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
