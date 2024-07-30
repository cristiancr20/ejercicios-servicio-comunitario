#include <stdio.h>
int main(){
    int num, resultado;
    printf("Que numero de tabla desea multiplicar: ");
    scanf("%d", &num);
    for (int i = 0; i <= 12; i++)
    {
        
        printf("%d x %d = %d\n", i, num, resultado = i * num);
    }
    
}