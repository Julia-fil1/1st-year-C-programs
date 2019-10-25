//This program receives an integer as a parameter and modifies the array elements by multiplying each one by 10
//Pointers are to be used for the putpose of this program

//this program uses the principle of passing by address(reference)
#include <stdio.h>

void MUL_BY_10(int *arr);
//i is a counter
//n is the number of elements in the array
int i, n;
int arr[50];//initialising the array

int main(void)
{
	printf("Please enter how many elements you would like for your array\n");//prompting the user to input the number of elements for the array
	scanf("%d", &n);//reading in the integer for the number of elements
   
	printf("Enter elements:\n");//prompting the user to fill the array

	for(i = 0; i < n; ++i)
    scanf("%d", arr + i);//reading in the array elements
   
	MUL_BY_10(arr);//calling the function to multiply all the array elements by 10
   
	return 0;

}
//function to multiply each of the array elements by 10
 void MUL_BY_10(int *arr)
 {
	printf("The array after multiplication has been completed is: \n");
    for(int i = 0; i < n; ++i)
	printf("%d\n", *(arr + i)*10);//printing out the resulting array after the elements have been multiplied
 }