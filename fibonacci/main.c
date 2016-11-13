#include <stdio.h>
#include <stdlib.h>

/* Standard recursive fib program */
int fibonacci(int n) {
  if (n == 0 ) return 0;
  if (n == 1) return 1;
  
   return ( fibonacci(n-1) + fibonacci(n-2) );

}

int main (int argc, char **argv) {
          
        /* get n from cmd line */
        int n = (int) strtol(argv[1],NULL,0);       

        for(int i=0; i<n; i++) {
           printf("%d ",fibonacci(i));
        }
        printf("\n");
}


