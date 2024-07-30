#include<stdio.h>
void numeropar(int numero, int par){
    if (numero % 2 == 0 )
    {
        par = 1;
        printf("%d", par);
    }else{
        par = 0;
        printf("%d", par);
    } 
}
int main(){
    int  numero, par = 0;
    printf("Ingrese un numero: ");
    scanf("%d", &numero);
    printf("%d\n", numero);
    numeropar(numero, par);
    return 0;
}