#include <stdio.h>

int main() {
    int num;
    int suma = 0;

    printf("Ingrese el número hasta el cual desee realizar la suma: ");
    scanf("%d", &num);

    for (int i = 2; i <= num; i += 2) {
        suma += i;
    }

    printf("La suma de los números pares es: %d\n", suma);

    return 0;
}
