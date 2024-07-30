#include <stdio.h>

int main()
{
    int nota1, nota2, nota3, nota4, nota5;
    float media;

    printf("Introduce las cinco notas del estudiante: ");
    scanf("%d %d %d %d %d", &nota1, &nota2, &nota3, &nota4, &nota5);

    media = (nota1 + nota2 + nota3 + nota4 + nota5) / 5.0;
    printf("La media es: %f\n", media);


    if (nota1 < 40 || nota2 < 40 || nota3 < 40 || nota4 < 40 || nota5 < 40)
    {
        printf("Calificación: F\n");
    }
    else
    {
        if (media >= 90)
        {
            printf("Calificación: A\n");
        }
        else if (media >= 80)
        {
            printf("Calificación: B\n");
        }
        else if (media >= 70)
        {
            printf("Calificación: C\n");
        }
        else if (media >= 60)
        {
            printf("Calificación: D\n");
        }
        else
        {
            printf("Calificación: F\n");
        }
    }

    return 0;
}
