#include <stdio.h>
#include <stdlib.h>


/* search string for close bracket, call recursively on each open found */
char * stringCheck( char * str ) {
	char* ret;

	/* move through string, looking for close brackets */
	while( *str != '\0' ) {
	    printf("%c ",*str);
	    switch( *str ) {
                case '(' :
			ret = stringCheck(++str);
			if ( *ret != ')' || *ret == '\0' )
			    return --str;
			str = ret;
                        break;
                case '{' :
			ret = stringCheck(++str);
			if ( *ret != '}' || *ret == '\0' )
			    return --str;
			str = ret;
                        break;
                case '[' :
			ret = stringCheck(++str);
			if ( *ret != ']' || *ret == '\0' )
			    return --str;
			str = ret;
                        break;
                case ')' :
                case '}' :
                case ']' :
			return str;
                        break;
                default:
                        break;
            }
	    str++;
	}	
	
	/* return end of string */
	return str;
}

int main( int argc, char* argv[] ) {
	char* str;
	
	/* get input string */
	if ( argc == 2 ) {
		str =  argv[1];
		printf( "working on string: %s\n",str);
	} else {
		printf("Usage: stringCheck <string>\n");
		return -1;
	}

	/* call stringCheck with passed in string */
	str = stringCheck(str);
	printf("\n");
	
	if (*str != '\0')
	   printf("FAIL: string does not have correct brackets!\n");
	else
	   printf("PASS: string does have correct brackets!\n");
	
	return 1;
}

