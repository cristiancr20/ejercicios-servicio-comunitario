#include <stdio.h>

int main(){
    char x='a';
    // int x=1;
    while (x=='a')
    // while (x==1)
    {
        printf("Ingrese x\n");
        scanf("%s", &x);
        // scanf("%d", &x);
    }
    
    return 0;
}