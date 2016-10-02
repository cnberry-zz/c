#include <stdlib.h>
#include <stdio.h>

long bitSet(long val, long bit) {
	return val | (1<<bit);
}

int main( int argc, char* argv[] ) {
	long val,bit;	
	long ret;

	/* get input string */
	if ( argc == 3 ) 
	{
		val =  strtol(argv[1],NULL,0);
		bit =  strtol(argv[2],NULL,0);
		
	} else {
		printf("Usage: bitSet <integer>\n");
		return -1;
	}

	/* call bitset */
	ret = bitSet(val,bit);
	printf("input: %lx, setbit: %ld, result: %lx\n",val,bit,ret);
	return 0;
}
