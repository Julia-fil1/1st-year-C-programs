//this program mimics a two horse race
//the two horses are named Firefoot and Shadowfox
//they start the race at first grid of the race track and the finish line is a 100 hoops away
//the race ends when a horse reaches or passes the space 100
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function prototypes - pay attention to the use of pointers instead of global variables
void moveFirefoot( int *FirefootPtr);
void moveShadowfox( int *ShadowfoxPtr);
void printCurrentPositions(unsigned int, unsigned int);

int main()
{ 
   srand(time(NULL));

   int Firefoot  = 1; // Firefoot  current position
   int Shadowfox = 1; // Shadowfox current position      
   int counter = 0; // counter for the for loop controling the race.

 
   puts("The Race has started");
   
   // loop through the progress on the track
   while (Firefoot  != 100 && Shadowfox != 100) 
   { 
   //neither of the horses has reached the end of the track
   //call functions to move horses on the track
   
	moveShadowfox(&Shadowfox);//call the function for Shadowfox
	moveFirefoot(&Firefoot);//call the function for Firefoot
	
	printCurrentPositions(Firefoot,Shadowfox);//printing the positons of both horses
	counter++;//increment the counter
      
   } 

   // determine the winner and print message - one horse has passed the end as it is outside the loop.
   if (Firefoot  > Shadowfox)//Firefoot won
   {
      
	  printf("The Firefoot wins the race. Firefoot: %d, Shadowfox: %d\n", Firefoot,Shadowfox);
   } 
             
   if (Firefoot  < Shadowfox)//Shadowfox won
   {
      
	  printf("The Shadowfox wins the race. Shadowfox: %d, Firefoot: %d\n", Shadowfox,Firefoot);
   }
   if (Firefoot==Shadowfox)//both horses reached the end of the track at the same time
   {
	   printf("It's a tie\n");
      
   } 

   printf("iterations: %u \n", counter);
} 

// progress for Shadowfox
void moveShadowfox( int *ShadowfoxPtr)
{ 
int x;
   // generate random number from 1-10
	x= 1 + (rand() % 10);
	
	//testing all the rules
	//OPTION A
   // determine progress
   if (x >= 1 && x <= 5)//the randomly generated integer is between 1 and 5 inclusive
   { 

   // full speed 50% of the time
      *ShadowfoxPtr += 2;//move two spaces forward
   } 
   
   //OPTION B
   //determine progress
   if(x==7)//the randomly generated number is 7
   {
	   //progress 1 space 10% of the time
	   *ShadowfoxPtr += 1;//move one space forward
   }
   
   //OPTION C
   //determine progress
   if(x==6)//the randomly generated number is 6
   {
		//progress 3 spaces 10% of the time
		*ShadowfoxPtr += 3;//move 3 spaces forward
   }
   
   //OPTION D
   //determine progress
   if(x==8)//the randomly generated number is 8
   {
	   //10% of the time the jockey will fall off the horse and will not move at all
	   *ShadowfoxPtr += 0;//move 0 spaces
   }
   
   //OPTION E
   //determine progress
   if(x==9 && x==10)//the randomly generated number is 9 or 10
   {
	   //the horse will jump backwards 2 spaces
	   *ShadowfoxPtr -= 2;//move 2 spaces backwards
   }
   
    
   // check boundaries
   
   if (*ShadowfoxPtr < 1) {//if the horse happens to go backwards past the first space
      *ShadowfoxPtr = 1;//reset the horse back to the first space
   } 
   if (*ShadowfoxPtr > 100) {//if the horse goes past the end of the track
      *ShadowfoxPtr = 100;//move the horse back to the last position
   } 
} 


// progress for Firefoot 
void moveFirefoot ( int *FirefootPtr)
{ 
 int x;
 // generate random number from 1-10
 x= 1 + (rand() % 10);
 
	//testing all the rules
	//OPTION A
	
   // determine progress
   if (x >= 1 && x <= 5)//the randomly generated number is between 1 and 5 inclusive
   { 

   // full speed 50% of the time
      *FirefootPtr += 2;//move two spaces forward
   } 
    
   //OPTION B
   //determine progress
   if(x==7)//the randomly geberated number is 7
   {
	   //progress 1 space 10% of the time
	   *FirefootPtr += 1;//move one space forward
   }
   
   //OPTION C
   //determine progress
   if(x==6)//the randomly generated number is 6
   {
		//progress 3 spaces 10% of the time
		*FirefootPtr += 3;//move 3 spaces forward
   }
   
   //OPTION D
   //determine progress
   if(x==8)//the randomly generated number is 8
   {
	   //10% of the time the jockey will fall off the horse and will not move at all
	   *FirefootPtr += 0;//move 0 spaces
   }
   
   //OPTION E
   //determine progress
   if(x==9 && x==10)//the randomly generated number is 9 or 10 
   {
	   //the horse will jump backwards 2 spaces
	   *FirefootPtr -= 2;//move two spaces backwards
   }
    // check boundaries
   
   if (*FirefootPtr < 1) {//if the horse happens to go backwards past the first space
      *FirefootPtr = 1;//reset the horse back to the first space
   } 
   if (*FirefootPtr > 100) {//if the horse goes past the end of the track
      *FirefootPtr = 100;//move the horse back to the last position
   } 
 
   
} 

// display new position
void printCurrentPositions(unsigned int Firefoot, unsigned int Shadowfox)
{ 
   // loop through race
   //prints the location of each horse at every loop iteration
   for (unsigned int count = 1; count <= 100; ++count) 
   {
      // this loop will print 100 characters at each run: either S,F,T or a space to 
      //give the user an idea of where the horse at every iteration
      
      if (count == Firefoot  && count == Shadowfox) 
      {
		printf("T\n");//print T if the two horses are in the same position
      } 
      else if (count == Shadowfox) {
		 printf("S\n");//print S if Shadowfox is in a further postion than Firefoot
      } 
      else if (count == Firefoot ) {
		 printf("F\n");//print F if Firefoot is in a further position than Shadowfox
      } 
      else {
		 printf(" ");
      } 
   }

   puts("");
} 
