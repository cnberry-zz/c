#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int squares(int A, int B) {
   
   /* handle negative values 
    by moving to 0, since technically
    [A,B] integers contains no negative
    sqaures, as imaginary integers are 
    not included. Probably not what the
    interverier wants though.
   */
   if ( A < 0 )
     A = 0;
   if ( B < 0 )
     B = 0;

   return floor(sqrt(B))-ceil(sqrt(A))+1;
}

int main (int argc, char **argv) {

  /* parse input */
  int A = (int) strtol(argv[1],NULL,0);
  int B = (int) strtol(argv[2],NULL,0);

  /* call the method */
  int num = squares(A,B);
  
  printf("Number of squares in [%d,%d] = %d\n",A,B,num);
  exit (0);
}
