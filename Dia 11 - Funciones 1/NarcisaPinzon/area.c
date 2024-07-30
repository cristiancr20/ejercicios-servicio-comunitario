#include<stdio.h>
//float calcularAreaCirculo(float PI, float area, float radio);
float calcularAreaCirculo(float PI, float area, float radio){
    radio = radio * radio;
    area = PI * radio;
    return area;
}
int main(){
    float PI = 3.14159;
    float area = 0, radio;
    printf("Ingrese el radio: ");
    scanf("%f", &radio);
    area = calcularAreaCirculo(PI, area, radio);
    printf("El area es %f", area);
    return 0;
}