#include <stdio.h>

int main(void) {
  int arr[] = {25, 50, 75, 100};
  int i;
  for(i = 0; i < 4; i++){
    if(arr[i]==75){
      printf("Elemento encontrado en la posición %d: %d\n", i, arr[i]);
    }
  }
  return 0;
}
