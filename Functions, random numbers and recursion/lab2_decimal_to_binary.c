#include<stdio.h>
//This program converts decimal to binary using recursion
/*example: convert 26 to binary
26 % 2=0 => 26/2=13
13 % 2=1 => 13/2
6 % 2=0 => 6/2=3
3 % 2=1 => 3/2=1
1 % 2=1 => 1/2=0
Therefore, the binary representation is 11010 */
//The following program is based on the method of conversion shown above

int convert_decimal_to_binary(int decimal_num);//function prototype

int main(void)
{
	int decimal_num;//declaring the variable
	
	//getting the input from the user
	printf("Please enter the decimal number to be converted:\n");//prompting the user
	scanf("%d", &decimal_num);//reading in the user input
	printf("The entered number is %d in binary", convert_decimal_to_binary(decimal_num));//display the number converted to binary
	return 0;
}

int convert_decimal_to_binary(int decimal_num)//calling the function by value
{
	
	if(decimal_num == 0)//setting up the base case for recursion
	{
		return 0;
	}
	
	else
	{
	return(decimal_num % 2 + 10* convert_decimal_to_binary(decimal_num/2));//convert the given number to binary and return the result
	}
	
}
	
	
	