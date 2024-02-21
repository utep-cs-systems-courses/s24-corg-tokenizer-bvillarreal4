#include <stdio.h>

int main(){
  fputs("Enter input: \n>" , stdout);

  char input[100];
  scanf("%[^\n]s", input);
  printf("%s\n", input);

}
