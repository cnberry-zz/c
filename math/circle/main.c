#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int guassianCircle(int R) {
   int i,sum;
 
   /* caculate sum */
   for(i = 1, sum = 0; i < R; i++) {
     sum += floor(sqrt(pow(R,2)-pow(i,2)));
   }

   return 1 + 4*R + 4*sum;
}

int main (int argc, char **argv) {

  /* parse input */
  int R = (int) strtol(argv[1],NULL,0);

  /* call the method */
  int num = guassianCircle(R);
  
  printf("Number of lattice points in circle R=%d : %d\n",R,num);
  exit (0);
}
