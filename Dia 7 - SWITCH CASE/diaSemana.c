#include <stdio.h>

int main() {
    int dia;

    do
    {
        printf("Ingrese un número del 1 al 7: ");
        scanf("%d", &dia);

        switch (dia) {
            case 1:
                printf("Lunes\n");
                break;
            case 2:
                printf("Martes\n");
                break;
            case 3:
                printf("Miércoles\n");
                break;
            case 4:
                printf("Jueves\n");
                break;
            case 5:
                printf("Viernes\n");
                break;
            case 6:
                printf("Sábado\n");
                break;
            case 7:
                printf("Domingo\n");
                break;
            case 8:
                printf("Salir\n");
                break;
            default:
                printf("Número no válido. Ingrese un número del 1 al 7.\n");
                break;
        }
    } while (dia!=8);
    
    return 0;
}