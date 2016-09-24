This was an interview question I was asked recently. 

You are given a string which may contain 3 types of brackets:

  ( )
  { }
  [ ]

These brackets can occur in any order and may be nested, but
they follow standard bracket rules such that when an open bracket
of a given type occures in must be closed in the reverse of the
order that they are opened, exactly like you would expect.

For example, the following string is valid:
 
  {8888990-}(value[2])

but, these next strings are not valid:

  {333)     /*FAIL*/
  {{hello   /*FAIL*/
  }help     /*FAIL*/

It is a fun problem which can include the concepts below: 
  1. structs
  2. singly linked list
  3. Last-In-First-Out (LIFO)
  4. processing null terminated strings
  5. malloc/free
  6. recursion 

Since there are two main (maybe more?) ways to do this, application
managed memory using a linked list, or compiler/os managed memory
using the stack and recursion, I did both (although, I only implemented
the linked list method during the interview...)

To use:

  $ gcc listBracket.c 
  $ gcc recursiveBracket.c

then pass the string in as an arguement:

  $ ./a.out '{{}889}'


