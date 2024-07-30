#include <stdio.h>

int main(void) {
  int arr[] = {25, 50, 75, 100};

  printf("Arrya original\n");
  for(int i = 0; i < 4; i++){
      printf("Elemento en la posición %d: %d\n", i, arr[i]);
  }

  arr[1]=500;

  printf("Arrya Modificado\n");

  for(int i = 0; i < 4; i++){
      printf("Elemento en la posición %d: %d\n", i, arr[i]);
  }
  return 0;
}
