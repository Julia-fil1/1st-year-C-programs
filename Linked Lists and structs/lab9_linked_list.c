/*  Operating and maintaining a linked list */
//this program is an implementation of a linked list with an added function which replaces a character in a linked list with another character
//when a user chooses a character to be replaced all the instances of that character in the linked list are replaced with the new chosen character
#include <stdio.h>
#include <stdlib.h>

    /* self-referential structure */
struct listNode {
             char data; /* each listNode contains a character */
             struct listNode *nextPtr; /* pointer to next node */
}; /* end structure listNode */ 


typedef struct listNode ListNode; /* synonym for struct listNode */
typedef ListNode *ListNodePtr; /* synonym for ListNode* */

/* prototypes */
void insert( ListNodePtr *sPtr, char value );
char delete( ListNodePtr *sPtr, char value );
int isEmpty( ListNodePtr sPtr );
void printList( ListNodePtr currentPtr );
void instructions( void );
void replace_char(ListNodePtr currentPtr, char value, char new_value);
char new_value;

int main( void )
{
    ListNodePtr startPtr = NULL; /* initially there are no nodes */
	//ListNodePtr newPtr = malloc( sizeof( ListNode ) ); /* create node */
    int choice; /* user's choice */
    char item; /* char entered by user */
    
    instructions(); /* display the menu */
    printf( "? " );
    scanf( "%d", &choice );

     /* loop while user does not choose 3 */
    while ( choice != 4 ) {
        switch ( choice ) {
            case 1:
                printf( "Enter a character: " );
                scanf( "\n%c", &item );
                insert( &startPtr, item ); /* insert item in list */
                printList( startPtr );
                break;
             case 2: /* delete an element */
                 /* if list is not empty */
                if ( !isEmpty( startPtr ) ) {
                    printf( "Enter character to be deleted: " );
                    scanf( "\n%c", &item );
                    /* if character is found, remove it*/
                    if ( delete( &startPtr, item ) ) { /* remove item */
                        printf( "%c deleted.\n", item );
                        printList( startPtr );
                    } /* end if */
                    else {
                        printf( "%c not found.\n\n", item );
                    } /* end else */
                } /* end if */
                else {
                    printf( "List is empty.\n\n" );
                } /* end else */

                break;
				case 3:
				printf("Enter character which you want to replace: ");
				scanf("\n%c", &item);
				printf("Enter the new character: ");
				scanf("\n%c", &new_value);
			
				replace_char(startPtr, item, new_value);
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
         " 1 to insert an element into the list.\n"
         " 2 to delete an element from the list.\n"
		 " 3 to replace an element from the list with another character.\n"
         " 4 to end.\n" );
} /* end function instructions */

     /* Insert a new value into the list in sorted order */
void insert( ListNodePtr *sPtr, char value )
{
    ListNodePtr newPtr = malloc( sizeof( ListNode ) ); /* create node */
    if ( newPtr != NULL ) { /* is space available */
        newPtr->data = value; /* place value in node */
        newPtr->nextPtr = NULL; /* node does not link to another node */

        ListNodePtr previousPtr = NULL;  /* pointer to previous node in list */
        ListNodePtr currentPtr = *sPtr; /* pointer to current node in list */

        /* loop to find the correct location in the list */
        while ( currentPtr != NULL && value > currentPtr->data ) {
            previousPtr = currentPtr; /* walk to ... */
            currentPtr = currentPtr->nextPtr; /* ... next node */
        } /* end while */ 

                /* insert new node at beginning of list */
        if ( previousPtr == NULL ) {
            newPtr->nextPtr = *sPtr;
            *sPtr = newPtr;
        } /* end if */
        else { /* insert new node between previousPtr and currentPtr */
            previousPtr->nextPtr = newPtr;
            newPtr->nextPtr = currentPtr;
            } /* end else */
    } /* end if */
    else {
        printf( "%c not inserted. No memory available.\n", value );
    } /* end else */
} /* end function insert */

/* Delete a list element */
char delete( ListNodePtr *sPtr, char value )
{
    /* delete first node */
    if ( value == ( *sPtr )->data ) {
        ListNodePtr tempPtr = *sPtr; /* hold onto node being removed */
        *sPtr = ( *sPtr )->nextPtr; /* de-thread the node */
        free( tempPtr ); /* free the de-threaded node */
        return value;
     } /* end if */
     
    else {
        ListNodePtr previousPtr = *sPtr;
        ListNodePtr currentPtr = ( *sPtr )->nextPtr;

    /* loop to find the correct location in the list */
     while ( currentPtr != NULL && currentPtr->data != value ) {
         previousPtr = currentPtr; /* walk to ... */
         currentPtr = currentPtr->nextPtr; /* ... next node */
     } /* end while */

     /* delete node at currentPtr */
     if ( currentPtr != NULL ) {
         ListNodePtr tempPtr = currentPtr;
         previousPtr->nextPtr = currentPtr->nextPtr;
         return value;
        } /* end if */
     } /* end else */

     return '\0';
} /* end function delete */

     /* Return 1 if the list is empty, 0 otherwise */
int isEmpty( ListNodePtr sPtr )
{
    return sPtr == NULL;
} /* end function isEmpty */

     /* Print the list */
void printList( ListNodePtr currentPtr )
{
    /* if list is empty */
    if ( currentPtr == NULL ) {
        printf( "List is empty.\n\n" );
     } /* end if */
    else {
        printf( "The list is:\n" );

    /* while not the end of the list */
    while ( currentPtr != NULL ) {
        printf( "%c --> ", currentPtr->data );
        currentPtr = currentPtr->nextPtr;
     } /* end while */

    printf( "NULL\n\n" );
     } /* end else */
} /* end function printList */

/*function to replace all instances of a chosen character with another character specified by the user*/
void replace_char(ListNodePtr currentPtr, char value, char new_value)
{
	while(currentPtr != NULL){
		
		if(currentPtr->data ==value){ /*if current pointer is pointing to the chosen character */
		
		currentPtr->data = new_value; /*replace the old character with a new one */
		}
		printf( "%c --> ", currentPtr->data );
        currentPtr = currentPtr->nextPtr;
		
	}
	
}