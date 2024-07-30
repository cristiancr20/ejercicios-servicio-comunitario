#include <stdio.h>

int main()
{
    int a;

    // Declaración de punteros
    int *ptr; // ptr es un puntero a un entero
    
    printf("Ingresa un número: ");
    scanf("%d", &a);

    // Asignación de direcciones:
    ptr = &a; // ptr ahora contiene la dirección de a

    // Dereferencia de punteros
    int valor = *ptr; // valor es ahora 10, el valor almacenado en la dirección a la que apunta ptr

    printf("El valor de a es: %d\n", *ptr); // Imprime el valor almacenado en la dirección a la que apunta ptr
    return 0;
}


