#include <stdio.h>

int main(){
    int x = 10;
    int y = 20;

    int igual = (x == y);
    int diferente = (x != y);
    int menor_que = (x < y);
    int mayor_que = (x > y);
    int menor_igual=(x <= y);
    int mayor_igual = (x >= y);    

    printf("IGUAL. %d\n", igual);
    printf("DIFERENTE. %d\n", diferente);
    printf("MENOR. %d\n", menor_que);
    printf("MAYOR. %d\n", mayor_que);
    printf("MENOR IGUAL. %d\n", menor_igual);
    printf("MAYOR IGUAL. %d\n", mayor_igual);

    return 0;
}
