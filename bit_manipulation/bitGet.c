#include <stdlib.h>
#include <stdio.h>


/* get bit using and with bitshifted mask, compare to zero */
long bitGet(long val, long bit) {
	return (val & (1<<bit)) == 0 ? 0 : 1 ;
}

int main( int argc, char* argv[] ) {
	long val,bit;	
	long ret;

	/* get input string */
	if ( argc == 3 ) 
	{
		/* convert input strings in hex,oct,dec to long */
		val =  strtol(argv[1],NULL,0);
		bit =  strtol(argv[2],NULL,0);
		
	} else {
		printf("Usage: bitGet <integer> <bitnumber>\n");
		return -1;
	}

	/* call bitset */
	ret = bitGet(val,bit);
	printf("input: 0x%lx, getbit: %ld, result: 0x%lx\n",val,bit,ret);
	return 0;
}
