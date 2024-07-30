#include <stdio.h>

int main() {
    int arr[5];
    int *ptr;
    
    printf("Ingresa 5 números: ");
    for (int i = 0; i < 5; i++) {
        scanf("%d", &arr[i]);
    }
    
    ptr = arr; // ptr apunta al primer elemento del arreglo
    printf("PTR es: %d\n", *(ptr)); 
    //printf("PTR es: %p\n", ptr); 
    printf("El tercer elemento del arreglo es: %d\n", *(ptr + 2)); // Imprime el tercer elemento del arreglo
    return 0;
}
