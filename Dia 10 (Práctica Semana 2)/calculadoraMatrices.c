#include <stdio.h>

#define TAMANO 3

void ingresarMatriz(float matriz[TAMANO][TAMANO]);
void mostrarMatriz(float matriz[TAMANO][TAMANO]);
void sumarMatrices(float matriz1[TAMANO][TAMANO], float matriz2[TAMANO][TAMANO], float resultado[TAMANO][TAMANO]);
void restarMatrices(float matriz1[TAMANO][TAMANO], float matriz2[TAMANO][TAMANO], float resultado[TAMANO][TAMANO]);
void multiplicarMatrices(float matriz1[TAMANO][TAMANO], float matriz2[TAMANO][TAMANO], float resultado[TAMANO][TAMANO]);
void menu();

int main() {
    float matriz1[TAMANO][TAMANO];
    float matriz2[TAMANO][TAMANO];
    float resultado[TAMANO][TAMANO];
    int opcion;
    
    void ingresarMatriz(matriz1);
    void ingresarMatriz(matriz2);

    do {
        menu();
        scanf("%d", &opcion);
        
        switch (opcion) {
            case 1:
                printf("Ingrese los elementos de la primera matriz:\n");
                ingresarMatriz(matriz1);
                printf("Ingrese los elementos de la segunda matriz:\n");
                ingresarMatriz(matriz2);
                sumarMatrices(matriz1, matriz2, resultado);
                printf("Resultado de la suma:\n");
                mostrarMatriz(resultado);
                break;
            case 2:
                printf("Ingrese los elementos de la primera matriz:\n");
                ingresarMatriz(matriz1);
                printf("Ingrese los elementos de la segunda matriz:\n");
                ingresarMatriz(matriz2);
                restarMatrices(matriz1, matriz2, resultado);
                printf("Resultado de la resta:\n");
                mostrarMatriz(resultado);
                break;
            case 3:
                printf("Ingrese los elementos de la primera matriz:\n");
                ingresarMatriz(matriz1);
                printf("Ingrese los elementos de la segunda matriz:\n");
                ingresarMatriz(matriz2);
                multiplicarMatrices(matriz1, matriz2, resultado);
                printf("Resultado de la multiplicación:\n");
                mostrarMatriz(resultado);
                break;
            case 4:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opción no válida. Intente de nuevo.\n");
                break;
        }
    } while (opcion != 4);
    
    return 0;
}

void ingresarMatriz(float matriz[TAMANO][TAMANO]) {
    for (int i = 0; i < TAMANO; i++) {
        for (int j = 0; j < TAMANO; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%f", &matriz[i][j]);
        }
    }
}

void mostrarMatriz(float matriz[TAMANO][TAMANO]) {
    for (int i = 0; i < TAMANO; i++) {
        for (int j = 0; j < TAMANO; j++) {
            printf("%.2f\t", matriz[i][j]);
        }
        printf("\n");
    }
}

void sumarMatrices(float matriz1[TAMANO][TAMANO], float matriz2[TAMANO][TAMANO], float resultado[TAMANO][TAMANO]) {
    for (int i = 0; i < TAMANO; i++) {
        for (int j = 0; j < TAMANO; j++) {
            resultado[i][j] = matriz1[i][j] + matriz2[i][j];
        }
    }
}

void restarMatrices(float matriz1[TAMANO][TAMANO], float matriz2[TAMANO][TAMANO], float resultado[TAMANO][TAMANO]) {
    for (int i = 0; i < TAMANO; i++) {
        for (int j = 0; j < TAMANO; j++) {
            resultado[i][j] = matriz1[i][j] - matriz2[i][j];
        }
    }
}

void multiplicarMatrices(float matriz1[TAMANO][TAMANO], float matriz2[TAMANO][TAMANO], float resultado[TAMANO][TAMANO]) {
    for (int i = 0; i < TAMANO; i++) {
        for (int j = 0; j < TAMANO; j++) {
            resultado[i][j] = 0;
            for (int k = 0; k < TAMANO; k++) {
                resultado[i][j] += matriz1[i][k] * matriz2[k][j];
            }
        }
    }
}

void menu() {
    printf("\nCalculadora de Matrices 3x3\n");
    printf("1. Sumar matrices\n");
    printf("2. Restar matrices\n");
    printf("3. Multiplicar matrices\n");
    printf("4. Salir\n");
    printf("Ingrese una opción: ");
}
