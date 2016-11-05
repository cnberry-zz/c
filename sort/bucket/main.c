#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define  NUM_ELEM  20
#define  MAX_VALUE 50

/* bucket sort */
void bucketSort(const int *data, size_t size) {
  int i,j,count[MAX_VALUE] = {0};
  int length = size/sizeof(data[0]);
  
  /* loop through input array */
  for (i = 0; i < length; i++) {
    count[data[i]]++;   
  }

  /* printf out sorted list */
  printf("SORT: ");
  for (i = 0; i < MAX_VALUE; i++) {
    for (j = 0; j < count[i]; j++) {
      printf("%d ",i);
    }
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

  bucketSort(data,sizeof data);
  
  exit (0);
}
