//This program demonstrates pointers to functions
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void reverseArray(int arraySize, int array[]);//reverses the order of all the elements in the array
void randomiseArray(int arraySize, int array[]);//randomly mixes the order of all the elements in the array
void printArray(int arraySize, int array[], void (*arrayFunction)(int arraySize, int array[]));//prints the elements of the array in reverse order or random order depending on the user input

int main()
{
    srand(time(NULL));//random number generator without duplicates
    int myArray[10] = {2,4,6,8,10,12,14,16,18,20};//declaring the array
    int sizeOfArray = sizeof(myArray)/sizeof(myArray[0]);
    int userInput;//variable used to store user input
    printf("Enter 0 to reverse the array or 1 to randomise the order of the array elements\n");
    scanf("%d",&userInput);//read in the user input for what action they want to be performed 
    if(userInput == 0)//if user inputs 0
    {
        printArray(sizeOfArray,myArray,reverseArray);//print the array elements in reversed order
    }
    else if(userInput == 1)//if user inputs 1
    {
        printArray(sizeOfArray,myArray,randomiseArray);//print the array elements in a random order
    }
    return 0;
}

void reverseArray(int arraySize, int array[])
{
    int temp;//temporary variable used for storage during the swapping
    for(int i=0; i < arraySize/2; i++)
    {
		//swapping the positions of the elements in the array so that the one of the LHS are swapped with the ones on the RHS
        temp = array[i];
        array[i] = array[(arraySize-1) - i];
        array[(arraySize-1) - i] = temp;
    }
}

void randomiseArray(int arraySize, int array[])
{
    int temp,a;//temporary variables used for storage during the swapping
    for(int i=0;i<arraySize;i++)
    {
		//swapping the elements in the array by placing each one of them in a random positon genarated by the random number generator without duplicates
        a = rand()%arraySize;//generate a random position in the array
        temp = array[i];
        array[i] = array[a];
        array[a] = temp;
    }

}

void printArray(int arraySize, int array[], void (*arrayFunction)(int arraySize, int array[]))
{
    (*arrayFunction)(arraySize,array);
    for(int i = 0;i<arraySize;i++)
    {
        printf("%d ",array[i]);//printing the resulting array after the desired action has been performed
    }
}


