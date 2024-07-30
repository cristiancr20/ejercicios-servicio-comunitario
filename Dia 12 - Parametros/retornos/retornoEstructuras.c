#include <stdio.h>

struct Punto {
    int x;
    int y;
};

struct Punto crearPunto(int x, int y) {
    struct Punto p;
    p.x = x;
    p.y = y;
    return p;
}

int main() {
    int x, y;
    printf("Ingresa la coordenada x: ");
    scanf("%d", &x);
    printf("Ingresa la coordenada y: ");
    scanf("%d", &y);
    
    struct Punto punto = crearPunto(x, y);
    printf("Punto: (%d, %d)\n", punto.x, punto.y); // Imprime las coordenadas del punto creado
    return 0;
}
