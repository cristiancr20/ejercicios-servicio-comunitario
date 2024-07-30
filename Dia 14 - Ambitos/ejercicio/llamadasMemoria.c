#include <stdio.h>
#include <stdlib.h>

static int contadorLlamadas = 0; // Variable estática global

void contarLlamadas() {
    static int contadorLocal = 0; // Variable estática local
    contadorLlamadas++;
    contadorLocal++;
    printf("Llamadas Totales: %d, Llamadas Locales: %d\n", contadorLlamadas, contadorLocal);
}

void gestionarLista() {
    static int *lista = NULL;
    static int tamano = 0;
    int opcion, elemento, indice;

    while (1) {
        printf("\n1. Agregar Elemento\n2. Eliminar Elemento\n3. Mostrar Lista\n4. Salir\n");
        printf("Elige una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("Ingresa un elemento para agregar a la lista: ");
                scanf("%d", &elemento);
                lista = realloc(lista, (tamano + 1) * sizeof(int));
                lista[tamano++] = elemento;
                break;
            case 2:
                printf("Ingresa el índice del elemento para eliminar: ");
                scanf("%d", &indice);
                if (indice < 0 || indice >= tamano) {
                    printf("Índice inválido\n");
                } else {
                    for (int i = indice; i < tamano - 1; i++) {
                        lista[i] = lista[i + 1];
                    }
                    lista = realloc(lista, (--tamano) * sizeof(int));
                }
                break;
            case 3:
                printf("Lista de elementos: ");
                for (int i = 0; i < tamano; i++) {
                    printf("%d ", lista[i]);
                }
                printf("\n");
                break;
            case 4:
                free(lista);
                return;
            default:
                printf("Opción inválida\n");
        }
    }
}

int main() {
    contarLlamadas();
    contarLlamadas();
    gestionarLista();
    return 0;
}
