#include <stdio.h>
#include <stdlib.h>


typedef struct tagBracketElem {
    int bracketType; /* 1 = (), 2 = {}, 3 = [] */
    struct tagBracketElem *next;
} BracketElem;

/* method to insert at current head, return new head */
BracketElem* insert(int bracketType, BracketElem* currentHead) {

	/* Create new element */
        BracketElem *newElem = (BracketElem*) malloc(sizeof(BracketElem));

	/* set bracket type */
	newElem->bracketType = bracketType;
	newElem->next = currentHead;

	return newElem;
}

/* pop head if it is the same bracket type */
BracketElem* pop(BracketElem* currentHead) {
	BracketElem* newHead = currentHead->next;
	free(currentHead);
	return newHead;
}

/* check if open bracket on head matches closed bracket */
int check(int bracketType, BracketElem* currentHead) {
	/* Check that head is not NULL */
	if (!currentHead)
	    return -1;	

	/* check that open matches close */
	if (currentHead->bracketType != bracketType)
	    return -1;

	/* success */
	return 1;


}

int stringCheck( const char * str ) {
	char *ptr = NULL;
	BracketElem *head = NULL;
	int ret;

	for(ptr=str; *ptr!='\0'; ptr++) {
	   printf("%c ",*ptr);
	   switch(*ptr) {
		case '(' :
			head = insert(1,head);
			break;
		case ')' :
			ret = check(1,head);
			if (ret < 0)
			    return -1;
			head = pop(head);
			break;
		case '{' :
			head = insert(2,head);
			break;
		case '}' :
			ret = check(2,head);
			if (ret < 0)
			    return -1;
			head = pop(head);
			break;
		case '[' :
			head = insert(3,head);
			break;
		case ']' :
			ret = check(3,head);
			if (ret < 0)
			    return -1;
			head = pop(head);
			break;
		default:
			break;
	    }
	}
	printf("\n");
	
	/* check head is null (we have popped all opens) */
	if (head != NULL)
		return -1;

	/* passed */
	return 1;
}

int main( int argc, const char* argv[] ) {
	char* str;
	int ret;
	
	/* get input string */
	if ( argc == 2 ) 
	{
		str =  argv[1];
		printf( "working on string: %s\n",str);
		
	} else {
		printf("Usage: stringCheck <string>\n");
		return -1;
	}

	/* call stringCheck with passed in string */
	ret = stringCheck(str);
	
	if (ret < 0)
	   printf("FAIL: string does not have correct brackets!\n");
	else
	   printf("PASS: string does have correct brackets!\n");
	
	return ret;
}

