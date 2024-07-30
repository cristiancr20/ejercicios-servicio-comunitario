#include <stdio.h>
int main(){
    int n, resultado;
    printf("Ingrese un numero: ");
    scanf("%d", &n);
    for (int i = 0; i <= n; i++)
    {
        if (i % 2 == 0)
        {
            resultado += i;
        }
        
    }
    printf("El resultado es: %d", resultado);
    

    return 0;
}