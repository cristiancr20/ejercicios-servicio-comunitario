#include <stdio.h>

void intercambiar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int num1, num2;

    printf("Ingresa el primer número: ");
    scanf("%d", &num1);
    printf("Ingresa el segundo número: ");
    scanf("%d", &num2);

    intercambiar(&num1, &num2);
    printf("Después de intercambiar: num1 = %d, num2 = %d\n", num1, num2);

    return 0;
}
