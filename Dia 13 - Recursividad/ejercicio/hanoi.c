#include <stdio.h>

void torreHanoi(int n, char origen, char auxiliar, char destino) {
    if (n == 1) {
        printf("Mover disco 1 desde %c hasta %c\n", origen, destino);
        return;
    }
    torreHanoi(n - 1, origen, destino, auxiliar);
    printf("Mover disco %d desde %c hasta %c\n", n, origen, destino);
    torreHanoi(n - 1, auxiliar, origen, destino);
}

int main() {
    int n;
    printf("Ingrese el número de discos para la Torre de Hanoi: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Error: El número de discos debe ser mayor que cero.\n");
    } else {
        printf("Movimientos requeridos para resolver la Torre de Hanoi con %d discos:\n", n);
        torreHanoi(n, 'A', 'B', 'C');
    }

    return 0;
}
