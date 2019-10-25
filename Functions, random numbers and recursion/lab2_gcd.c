#include<stdio.h>
//Program to find the greatest common divisor of x and y
//The greatest common divisor of x and y is defined as follows
//If y is equal to 0 then gcd of x and y is x
//Otherwise gcd of x and y is x mod y

int gcd(int x, int y);//function prototype
int main(void)
{
	int x, y;//declaring the variables
	
	//getting the input from the user 
	printf("Please enter the two numbers:\n");//prompting the user 
	scanf("%d\n %d", &x, &y);//reading in the user inout for the values of which the gcd is to be found
	
	printf("The greatest common divisor of the entered numbers is %d", gcd(x, y));//displaying the gcd on the screen
	
	return 0;
}

//function to find the gcd of two entered numbers
int gcd(int x, int y)//calling the function by value
{
	if(y==0)//setting up the base case for recursion
	{
		return x;//if one of the entered numbers is 0 the gcd of the two is going to be the other number
	}
	
	else 
	{
		return gcd(y, x%y);//calculating the gcd and returning the result
	}
	
}
