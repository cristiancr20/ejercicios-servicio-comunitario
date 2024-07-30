#include <stdio.h>

int main() {
    char calificacion;

    do
    {
        printf("Ingrese una calificación (A, B, C, D, F): ");
        scanf(" %c", &calificacion);  // El espacio antes de %c es importante para consumir el carácter de nueva línea dejado por scanf anterior.
    
        switch (calificacion) {
            case 'A':
            case 'a':
                printf("Excelente\n");
                break;
            case 'B':
            case 'b':
                printf("Muy Bien\n");
                break;
            case 'C':
            case 'c':
                printf("Bien\n");
                break;
            case 'D':
            case 'd':
                printf("Suficiente\n");
                break;
            case 'F':
            case 'f':
                printf("Reprobado\n");
                break;
            case 'X':
            case 'x':
                printf("Salir\n");
                break;
            default:
                printf("Calificación no válida. Ingrese una letra (A, B, C, D, F).\n");
                break;
        }
    } while (calificacion!='X' && calificacion!='x');
    
    return 0;
}
