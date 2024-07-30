#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Nodo {
    int dato;
    struct Nodo* siguiente;
} Nodo;

typedef struct Pila {
    Nodo* cima;
} Pila;

Pila* crearPila() {
  Pila* pila = (Pila*)malloc(sizeof(Pila));
  pila->cima = NULL;
  return pila;
}

void apilar(Pila* pila, int dato) {
  Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
  nuevoNodo->dato = dato;
  nuevoNodo->siguiente = pila->cima;
  pila->cima = nuevoNodo;
}

int desapilar(Pila* pila) {
  if (pila->cima == NULL) {
      printf("Pila vacía\n");
      return -1;
  }
  Nodo* temp = pila->cima;
  int dato = temp->dato;
  pila->cima = temp->siguiente;
  free(temp);
  return dato;
}

int cima(Pila* pila) {
  if (pila->cima == NULL) {
      printf("Pila vacía\n");
      return -1;
  }
  return pila->cima->dato;
}

bool estaVacia(Pila* pila) {
  return pila->cima == NULL;
}

void mostrarPila(Pila* pila) {
  if (estaVacia(pila)) {
      printf("La pila está vacía\n");
  } else {
      printf("Pila: ");
      Nodo* actual = pila->cima;
      while (actual != NULL) {
          printf("%d ", actual->dato);
          actual = actual->siguiente;
      }
      printf("\n");
  }
}


int main() {
    Pila* pila = crearPila();
    int opcion, valor;
    do {
        printf("\nMenu:\n");
        printf("1. Apilar\n");
        printf("2. Desapilar\n");
        printf("3. Ver cima\n");
        printf("4. Verificar si la pila está vacía\n");
        printf("5. Salir\n");
        printf("Elige una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("Introduce un valor para apilar: ");
                scanf("%d", &valor);
                apilar(pila, valor);
                break;
            case 2:
                printf("Desapilar: %d\n", desapilar(pila));
                break;
            case 3:
                printf("Elemento superior: %d\n", cima(pila));
                break;
            case 4:
              if (estaVacia(pila)) {
                printf("Pila vacía: Sí\n");
              } else {
                printf("Pila vacía: No\n");
                mostrarPila(pila);
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