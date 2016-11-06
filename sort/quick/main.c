#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define  NUM_ELEM  20
#define  MAX_VALUE 50

/* swap */
static inline void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

/* find pivot, swap left and right, return value */
const int median3(int *data, int left, int right) {
  int center = (left + right) / 2;

  /* sort 3 elements with 3 compare/swaps */
  if ( data[left] > data[center] ) {
    swap(&data[left],&data[center]);
  }
  if ( data[right] > data[center] ) {
    swap(&data[center],&data[right]);
  }
  if ( data[left] > data[right] ) {
    swap(&data[left],&data[right]);
  }

  return data[right];

}

void printArray(const char *word,const int *data) {
  int i;

  printf("%s: ",word);
  for( i = 0; i < NUM_ELEM; i++ ) {
    printf("%d ",data[i]);
  }  
  printf("\n");

  
}

int partition3(int *data, int left, int right) {
  int pivot;
  int i = left-1;
  int j = right;

  /* use right if < 3, otherwise take median3 */ 
  if (right-left < 3)
    pivot = data[right];
  else
    pivot = median3(data,left,right);

  /* pivot in right spot */
  while ( 1 ) {
    while( data[++i] < pivot ) { } /* pivot in right acts as sentinel */
    while( j > 0 && data[--j] > pivot ) { } /*no sentinel, need compare to 0 */
   
    if ( i < j )
      swap(&data[i],&data[j]);
    else
      break;

  }
  
  /* put pivot into correct location */
  swap(&data[i],&data[right]);
  return i;
}

/* quicksort */
void quickSort(int *data, int left, int right) {

  if ( left < right) {
    int index = partition3(data,left,right);
    quickSort(data,left, index-1);
    quickSort(data,index+1,right);
  }

}

int main (int argc, char **argv) {
  int data[NUM_ELEM];
  int i;
  time_t t;

  /* seed the rand with time */
  srand((unsigned) time(&t));

  /* create the randon integer data to sort */
  for( i = 0; i < NUM_ELEM; i++ ) {
    data[i] = rand() % MAX_VALUE;
  }  

  printArray("DATA",data);

  /* call the sort */
  quickSort(data,0,NUM_ELEM-1);
  
  printArray("SORT",data);

  exit (0);
}
