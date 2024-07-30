#include <stdio.h>

// definir estructura persona

struct personas
{
    char nombre[50];
    int edad;
    float altura;
};

int main()
{
    // definir variable de tipo persona

    int numPersonas;

    printf("Cuantas personas quieres registrar: ");
    scanf("%d", &numPersonas);

    struct personas persona1[numPersonas];
    // ingresar datos de las personas
    for (int i = 0; i < numPersonas; i++)
    {
        printf("Ingresa el nombre de la persona %d: \n", i + 1);
        scanf("%s", persona1[i].nombre);
        printf("Ingresa la edad de la persona %d: \n", i + 1);
        scanf("%d", &persona1[i].edad);
        printf("Ingresa la altura de la persona %d: \n", i + 1);
        scanf("%f", &persona1[i].altura);
    }

    // mostrar datos de las personas
    for (int i = 0; i < numPersonas; i++)
    {
        printf("Persona %d\n", i);
        printf("Nombre: %s\n", persona1[i].nombre);
        printf("Edad: %d\n", persona1[i].edad);
        printf("Altura: %.2f\n", persona1[i].altura);
        printf("\n");
    }

    return 0;
}