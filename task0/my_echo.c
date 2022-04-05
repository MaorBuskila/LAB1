#include <stdio.h>
#include <stdlib.h>
#include <string.h>
extern int _sum(int a, int b);
void getNumbers(int* a, int* b);

int main(int argc, char **argv) {
  int i;
  FILE* output=stdout;
  for(i=1; i<argc; i++){
 	fprintf(output , "%s\n" , argv[i]);
  }
  return 0;
}
