#include<stdio.h>
#include<stdlib.h>
#include<time.h>//contains the prototype for the function time
//This program selects a random set of numbers for the Thunderball draw.
//Through the implementation of the time function we are able to get a different set of numbers each time

int main(void)
{

srand(time(NULL));//randomize random number generator using current time
printf("The five random numbers are:\n");

for(unsigned int i=1; i<=5; ++i)//looping 5 times to get 5 random numbers
{
	
	printf("%5d", 1 + (rand() % 39));//printing out 5 random numbers between 1 and 39
	
}

printf("\nThe thunder ball number is: %d", 1 +(rand() % 14));//printing a random number between 1 and 14 for the thunderball

}