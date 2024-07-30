#include <stdio.h>

// Declaración de las funciones
int encontrarMaximoMatriz(int matriz[][3], int filas, int columnas, int *filaMax, int *colMax);
int encontrarMinimoMatriz(int matriz[][3], int filas, int columnas, int *filaMin, int *colMin);
float calcularPromedioMatriz(int matriz[][3], int filas, int columnas);

// Función principal
int main() {
    int matriz[3][3] = {
        {1, 5, 3},
        {7, 8, 2},
        {4, 6, 9}
    };
    int filas = 3;
    int columnas = 3;
    int filaMax, colMax;
    int filaMin, colMin;

    int maximo = encontrarMaximoMatriz(matriz, filas, columnas, &filaMax, &colMax);
    int minimo = encontrarMinimoMatriz(matriz, filas, columnas, &filaMin, &colMin);
    float promedio = calcularPromedioMatriz(matriz, filas, columnas);

    printf("El elemento máximo en la matriz es %d y está en la posición [%d][%d]\n", maximo, filaMax, colMax);
    printf("El elemento mínimo en la matriz es %d y está en la posición [%d][%d]\n", minimo, filaMin, colMin);
    printf("El promedio de todos los elementos de la matriz es %.2f\n", promedio);

    return 0;
}

// Definición de la función para encontrar el máximo
int encontrarMaximoMatriz(int matriz[][3], int filas, int columnas, int *filaMax, int *colMax) {
    int maximo = matriz[0][0];
    *filaMax = 0;
    *colMax = 0;

    // int matriz[3][3] = {
    //       0  1  2 
    //   0  {1, 5, 3},
    //   1  {7, 8, 2},
    //   2  {4, 6, 9}
    // };

    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            if (matriz[i][j] > maximo) {
                maximo = matriz[i][j];
                *filaMax = i;
                *colMax = j;
            }
        }
    }
    return maximo;
}

// Definición de la función para encontrar el mínimo
int encontrarMinimoMatriz(int matriz[][3], int filas, int columnas, int *filaMin, int *colMin) {
    int minimo = matriz[0][0];
    *filaMin = 0;
    *colMin = 0;

    // int matriz[3][3] = {
    //       0  1  2 
    //   0  {1, 5, 3},
    //   1  {7, 8, 2},
    //   2  {4, 6, 9}
    // };

    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            if (matriz[i][j] < minimo) {
                minimo = matriz[i][j];
                *filaMin = i;
                *colMin = j;
            }
        }
    }
    return minimo;
}

// Definición de la función para calcular el promedio
float calcularPromedioMatriz(int matriz[][3], int filas, int columnas) {
    int suma = 0;
    int totalElementos = filas * columnas;

    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            suma += matriz[i][j];
        }
    }
    //Casteo a flotante
    return (float)suma / totalElementos;
}
