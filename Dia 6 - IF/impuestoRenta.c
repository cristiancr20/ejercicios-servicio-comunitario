#include <stdio.h>

int main()
{
    double ingresos;
    int dependientes;
    double impuesto;

    printf("Introduce los ingresos anuales: ");
    scanf("%lf", &ingresos);

    printf("Introduce el número de dependientes: ");
    scanf("%d", &dependientes);

    if (ingresos <= 10000)
    {
        impuesto = 0;
    }
    else if (ingresos <= 30000)
    {
        impuesto = (ingresos - 10000) * 0.10;
    }
    else if (ingresos <= 50000)
    {
        impuesto = (20000 * 0.10) + ((ingresos - 30000) * 0.20);
    }
    else
    {
        impuesto = (20000 * 0.10) + (20000 * 0.20) + ((ingresos - 50000) * 0.30);
    }

    if (dependientes > 0)
    {
        impuesto *= 0.95; // Reducción del 5%
    }

    printf("El impuesto sobre la renta es: $%.2lf\n", impuesto);

    return 0;
}