//This program prints the size in bytes of the given variables to the screen

#include <stdio.h>
#define SIZE 10//defining the maximum size for the arrays
int main(void)
{
	//declaring the variables
	char character;
	int integer;
	long long_;
	long long long__;
	double double_;
	long double long_double;
	float float_;
	int integer_array[SIZE];
	int *array[SIZE];
	
	//printing the size of the called variables using the sizeof operator
	//this allows us to display the size of a particular type without us having to know how many bytes each of them is
	//to print out the particular type we call it as an argument inside the sizeof
	printf("The size of a character is %d bytes\n", sizeof(character));
	printf("The size of an integer is %d bytes\n", sizeof(integer));
	printf("The size of a long is %d bytes\n", sizeof(long_));
	printf("The size of a long long is %d bytes\n", sizeof(long__));
	printf("The size of a double is %d bytes\n", sizeof(double_));
	printf("The size of a long double is %d bytes\n", sizeof(long_double));
	printf("The size of a float is %d bytes\n", sizeof(float_));
	printf("The size of an integer array is %d bytes\n", sizeof(integer_array[SIZE]));
	printf("The size of a pointer to an array is %d bytes\n", sizeof(*array[SIZE]));
	
	return 0;
}
