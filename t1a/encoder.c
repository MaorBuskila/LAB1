#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char **argv) {
  char c=0;
  printf("insert something:\n");
  fflush(stdout);
  
  while((c=fgetc(stdin))!=EOF)  {
    if(c >= 'A' & c <= 'Z'){
        fprintf(stdout,"%c" , '.');
    }
	else{
	printf("%c", c);
	}
  }
  fprintf(stdout,"%c", '\n');
  return 0;
}
