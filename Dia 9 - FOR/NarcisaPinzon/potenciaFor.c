#include<stdio.h>
int main(){

    int potencia = 1, base, exponente;
    printf("Ingrese la base: ");
    scanf("%d", &base);
    printf("Ingrese el exponente: ");
    scanf("%d", &exponente);
    for (int i = 1; i <= exponente; i++)
    {
        potencia *= base;
    }
    printf("La potencia del numero ingresado es: %d", potencia);
    
    return 0;
}