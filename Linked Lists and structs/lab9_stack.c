/*  Operating and maintaining a stack */
#include <stdio.h>
#include <stdlib.h>

    /* self-referential structure */
struct stackNode {
   char data; /* each stackNode contains a character */
   struct stackNode *nextPtr; /* pointer to next node */
}; /* end structure stackNode */ 


typedef struct stackNode StackNode; /* synonym for struct stackNode */
typedef StackNode *StackNodePtr; /* synonym for StackNode* */

/* prototypes */
void insert( StackNodePtr *sPtr, char value );
char delete( StackNodePtr *sPtr );
int isEmpty( StackNodePtr sPtr );
void printStack( StackNodePtr currentPtr );
void instructions( void );

int main( void )
{
    StackNodePtr startPtr = NULL; /* initially there are no nodes */
    int choice; /* user's choice for what to do */
    char item; /* char entered by user */
    
    instructions(); /* display the menu */
    printf( "? " );
    scanf( "%d", &choice );

     /* loop while user does not choose 3 */
    while ( choice != 3 ) {
        switch ( choice ) {
            case 1:
                printf( "Enter a character: " );
                scanf( "\n%c", &item );
				
                insert( &startPtr, item ); /* insert item to stack */
                printStack( startPtr );
                break;
				
             case 2: /* delete an element */
                 /* if stack is not empty */
                if ( !isEmpty( startPtr ) ) {
                    delete(&startPtr);
					printStack(startPtr);
				}
                else {
                    printf( "Stack is empty.\n\n" );
                } /* end else */
                break;
            default:
                 printf( "Invalid choice.\n\n" );
                 instructions();
                 break;
                 } /* end switch */

        printf( "? " );
        scanf( "%d", &choice );
} /* end while */

    printf( "End of run.\n" );
    return 0; /* indicates successful termination */
     } /* end main */

     /* display program instructions to user */
void instructions( void )
{
    printf( "Enter your choice:\n"
         " 1 to insert an element to the stack.\n"
         " 2 to delete an element from the stack.\n"
         " 3 to end.\n" );
} /* end function instructions */

     /* Insert a new value into the stack in sorted order */
void insert( StackNodePtr *sPtr, char value )
{
	StackNodePtr newPtr = malloc(sizeof(StackNode)); /* create node */
	if(newPtr != NULL)/* is space available */
	{
		newPtr->data = value; /* place value in node */
		
		if(*sPtr == NULL) /* if it's the first element */
		{
			newPtr->nextPtr = NULL; /* node does not link to another node */
		}
		else
		{
			newPtr->nextPtr = *sPtr;
		}
		*sPtr = newPtr; /* point start to last element entered */
	}
	 else {
        printf( "%c not inserted. No memory available.\n", value );
    } /* end else */
} /* end function insert */



/* Delete a stack element */
char delete( StackNodePtr *sPtr )
{
	StackNodePtr temp = *sPtr;
	
	//display a message indicating which element was deleted
	printf("\n %c was deleted from the stack.\n", temp->data);
	
	*sPtr = temp->nextPtr; /*de-threaded node */
	free(temp); /*free the de-threaded node */
}
	
	
int isEmpty( StackNodePtr sPtr )
{
    return sPtr == NULL;
} /* end function isEmpty */

     /* Print the stack */
void printStack( StackNodePtr currentPtr )
{
    /* if stack is empty */
    if ( currentPtr == NULL ) {
        printf( "Stack is empty.\n\n" );
     } /* end if */
    else {
        printf( "The stack is:\n" );

    /* while not the end of the stack */
    while ( currentPtr != NULL ) {
        printf( "%c --> ", currentPtr->data );
        currentPtr = currentPtr->nextPtr;
     } /* end while */

    printf( "NULL\n\n" );
     } /* end else */
} /* end function printStack */