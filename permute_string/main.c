#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* swap */
static inline void swap(char *a, char *b) {
  char temp = *a;
  *a = *b;
  *b = temp;
}

void permute(char *str,int start, int end) {
  int i;

  /* base condition, string is permuted */
  if (start == end) {
    printf("%s\n",str);
    return;
  }

  /* swap on char into place on front of string
     when return, swap back
  */
  for ( i = start; i <=end; i++ ) {
    swap(&str[start],&str[i]);
    permute(str,start+1,end);
    swap(&str[start],&str[i]);
  }
}

int main (int argc, char **argv) {

  /* parse input */
  char *str = argv[1];

  printf("Permuting: %s\n",str);

  /* call the method */
  permute(str,0,strlen(str)-1);

  printf("...DONE\n");
  
  exit (0);
}
