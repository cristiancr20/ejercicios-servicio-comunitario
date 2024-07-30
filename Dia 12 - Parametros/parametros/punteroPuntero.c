#include <stdio.h>

int main() {
    int a;
    int *ptr;
    int **ptr_ptr; // ptr_ptr es un puntero a ptr
    
    printf("Ingresa un número: ");
    scanf("%d", &a);
    
    ptr = &a;
    printf("PTR es: %p\n", ptr); 
    ptr_ptr = &ptr; // ptr_ptr ahora contiene la dirección de ptr
    printf("PTR_PTR es: %p\n", ptr_ptr); 
    printf("El valor de a es: %d\n", **ptr_ptr); // Imprime el valor de a
    return 0;
}
