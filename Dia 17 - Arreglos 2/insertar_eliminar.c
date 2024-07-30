#include <stdio.h>

int main(void) {
   int arr[] = {25, 50, 75, 100};
  printf("Array Original\n");
  for(int i = 0; i < 4; i++)
    printf("%d\n", arr[i]);

  //inserción de un elemento 

  int n = 4;
  int pos = 2;
  int elemento = 32;
  for(int i = n - 1; i >= pos; i--)
    arr[i + 1] = arr[i];
  arr[pos] = elemento;
  n++;
  printf("\nArray despues de la insercion\n");
  for(int i = 0; i < n; i++)
    printf("%d\n", arr[i]);

  //eliminacion de un elemento en la posicion 2
  int pos2 = 2;
  for(int i = pos2; i < n - 1; i++)
    arr[i] = arr[i + 1];
  n--;
  
  printf("\nArray despues de la eliminación\n");
  for(int i = 0; i < n; i++)
    printf("%d\n", arr[i]);
  return 0;
}