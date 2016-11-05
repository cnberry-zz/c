#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define  NUM_ELEM  20
#define  MAX_VALUE 50

/* bubble sort */
void bubbleSort(int *data, size_t size) {
  int i,length = size/sizeof(data[0]);
  int swapFlag = 1;
  int temp;

  /* loop through until no swaps take place */
  while ( swapFlag ) {
    
    swapFlag = 0;
    for (i = 1; i < length; i++) {
      if ( data[i] < data[i-1] ) { 
        temp = data[i];
	data[i] = data[i-1];
	data[i-1] = temp;
	swapFlag = 1;
      }	
    }  
  }

  /* print out the results */
  printf("SORT: ");
  for( i = 0; i < length; i++ ) {
    printf("%d ",data[i]);
  }  
  printf("\n");
}

int main (int argc, char **argv) {
  int data[NUM_ELEM];
  int i;
  time_t t;

  /* seed the rand with time */
  srand((unsigned) time(&t));

  /* create the randon integer data to sort */
  printf("DATA: ");
  for( i = 0; i < NUM_ELEM; i++ ) {
    data[i] = rand() % MAX_VALUE;
    printf("%d ",data[i]);
  }  
  printf("\n");

  /* call the sort */
  bubbleSort(data,sizeof data);
  
  exit (0);
}
