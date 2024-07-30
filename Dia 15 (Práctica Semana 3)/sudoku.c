#include <stdio.h>

#define N 9

static int llamadasRecursivas = 0; // Variable estática

void imprimirSudoku(int sudoku[N][N]) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            printf("%2d", sudoku[row][col]);
        }
        printf("\n");
    }
}

int esSeguro(int sudoku[N][N], int row, int col, int num) {
    for (int x = 0; x < N; x++) {
        if (sudoku[row][x] == num || sudoku[x][col] == num) {
            return 0;
        }
    }
    int inicioFila = row - row % 3, inicioColumna = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (sudoku[i + inicioFila][j + inicioColumna] == num) {
                return 0;
            }
        }
    }
    return 1;
}

int resolverSudoku(int sudoku[N][N], int row, int col) {
    llamadasRecursivas++;
    if (row == N - 1 && col == N) {
        return 1;
    }
    if (col == N) {
        row++;
        col = 0;
    }
    if (sudoku[row][col] != 0) {
        return resolverSudoku(sudoku, row, col + 1);
    }
    for (int num = 1; num <= N; num++) {
        if (esSeguro(sudoku, row, col, num)) {
            sudoku[row][col] = num;
            if (resolverSudoku(sudoku, row, col + 1)) {
                return 1;
            }
        }
        sudoku[row][col] = 0;
    }
    return 0;
}

int main() {
    int sudoku[N][N];
    printf("Ingrese el tablero de Sudoku (use 0 para las celdas vacías):\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &sudoku[i][j]);
        }
    }

    if (resolverSudoku(sudoku, 0, 0)) {
        printf("Sudoku resuelto:\n");
        imprimirSudoku(sudoku);
        printf("Número de llamadas recursivas: %d\n", llamadasRecursivas);
    } else {
        printf("No hay solución para el Sudoku dado.\n");
    }

    return 0;
}
