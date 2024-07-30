#include <stdio.h>

int multiplicar(int x, int y) {
    return x * y;
}

int main() {
    int num1, num2, resultado;
    printf("Ingresa el primer número: ");
    scanf("%d", &num1);
    printf("Ingresa el segundo número: ");
    scanf("%d", &num2);
    
    resultado = multiplicar(num1, num2);
    printf("Resultado: %d\n", resultado); // Imprime el producto de los dos números ingresados
    return 0;
}
