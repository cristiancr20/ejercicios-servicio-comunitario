#include <stdio.h>
int main()
{
    int n;
    int contador=1;
    int suma=0;
    printf("Ingrese el numero: ");
    scanf("%d", &n);

    while (contador<=n)
    {
        suma=suma+contador;
        // printf("%d. Suma %d\n", contador, suma);

        // IMPORTANTE: Incremento
        contador++;
    }

    printf("Suma hasta el %d: %d\n", n, suma);


    return 0;
}