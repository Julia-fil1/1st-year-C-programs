//this program uses dynamic memory allocation to acheive the following:
/*Prompts the user to enter the type (integer or float) and number of elements they
wish to store in an array
• Create sufficient memory to store the array
• Ask the user to enter each of the values they want to store
• After all elements have been entered and stored in the array, calculate the average
and print to the screen.
• Ask the user if there are more elements to be added to the array, if yes, prompt the
user to enter the number of additional elements.
• Reallocate sufficient memory to the array to store the new number of elements
• Ask the user to enter each of the new values they want to store
• After all the new elements have been entered and stored in the array, calculate the
average and print to the screen.
*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int type, num_elements;
	
	do{
	printf("Please enter the type of elements you wish to store in the array. Input 0 for an integer or 1 for a float:\n");
	scanf("%d", &type);
	}while(type != 0 && type !=1);
	
	printf("Please enter the number of elements you wish to store in the array:\n");
	scanf("%d", &num_elements);
	
	//if the user selects integer as type 
	if(type == 0)
	{
		int *array;
		int sum = 0;
		float average = 0;
		
		
		array = (int*)calloc(num_elements, sizeof(int));//creating sufficient memory for the integer array
		
		//if the space is insuffiecient, allocation fails and returns a NULL pointer
		if(array == NULL)
		{
			printf("ERROR! Memory allocation failed.\n");
			return 0;
		}
		else
		{
			printf("Please enter %d elements of the array:\n", num_elements);
			for(size_t i=0; i<num_elements; i++)
			{
				scanf("%d", &array[i]);
				sum+= array[i];//calculates the sum of the elements in the array
			}
			
			average = sum/num_elements;
			printf("The average of all the elements is: %.2f\n", average);
			
			do{
				printf("Would you like to add more elements to the array. Select 2 for NO or 3 for YES.\n");
				scanf("%d", &type);
			
			if(type == 3)//if the user wants to add more elements to the integer array
			{
					int num_extra_elements =0;
					
					//ask for the number of extra elements
					printf("How many extra elements would you like to enter?\n");
					scanf("%d", &num_extra_elements);
					
					array = (int*) realloc(array, num_extra_elements*sizeof(int));//reallocating memory to store the extra elements
					
					
					//ask to input the extra elements
					printf("Please enter %d extra elements to be stored in the array:\n", num_extra_elements);
					for(size_t i=0; i<num_extra_elements; i++)
					{
						scanf("%d", &array[i]);
						sum+= array[i];//calculating the sum of the elemnets in the array again since new elements have been entered
					}
					num_elements+= num_extra_elements;//calculating the total number of elements in the array after the new elements have been entered
					average= (float) sum/num_elements;//calculating the average of the elements
					printf("The average of the elements in the array is: %.2f\n", average);
			}
			}while(type == 1);
		}
	}
	
	else//float is selected as type
	{
		float *array;
		float sum = 0;
		float average = 0;
		
		array =(float*)calloc(num_elements, sizeof(float));
		
		if(array == NULL)
		{
			printf("ERROR! Memory allocation failed.\n");
			return 0;
		}
		else
		{
			printf("Please enter %d elements of the array:\n", num_elements);
			for(size_t i=0; i<num_elements; i++)
			{
				scanf("%f", &array[i]);
				sum+= array[i];//calculates the sum of the elements in the array
			}
			
			average = sum/num_elements;
			printf("The average of all the elements is: %.2f\n", average);
			
			do{
				printf("Would you like to add more elements to the array. Select 2 for NO or 3 for YES.\n");
				scanf("%d", &type);
			
			if(type == 3)//if the user wants to add more elements to the integer array
			{
					int num_extra_elements =0;
					
					//ask for the number of extra elements
					printf("How many extra elements would you like to enter?\n");
					scanf("%d", &num_extra_elements);
					
					array = (float*) realloc(array, num_extra_elements*sizeof(float));//reallocating memory to store the extra elements
					
					
					//ask to input the extra elements
					printf("Please enter %d extra elements to be stored in the array:\n", num_extra_elements);
					for(size_t i=0; i<num_extra_elements; i++)
					{
						scanf("%f", &array[i]);
						sum+= array[i];//calculating the sum of the elemnets in the array again since new elements have been entered
					}
					num_elements+= num_extra_elements;//calculating the total number of elements in the array after the new elements have been entered
					average= (float) sum/num_elements;//calculating the average of the elements
					printf("The average of the elements in the array is: %.2f\n", average);
			}
			}while(type = 0);
		}
	}
}
		
			