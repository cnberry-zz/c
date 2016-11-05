#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define  NUM_ELEM  20
#define  MAX_VALUE 50

/* selection sort */
void selectionSort(int *data, size_t size) {
  int i,j,length = size/sizeof(data[0]);
  int min,temp;

  /* loop through for each location */
  for (i = 0; i < length-1; i++) {  
    min = i;
    for (j = i; j < length; j++) {
      if ( data[j] < data[min] ) { 
	min = j;
      }	
    }  
    /* move the ith min into place */
    temp = data[i];
    data[i] = data[min];
    data[min] = temp;
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
  selectionSort(data,sizeof data);
  
  exit (0);
}
