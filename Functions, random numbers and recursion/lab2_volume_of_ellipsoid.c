#include <stdio.h>
//This program calculates the volume of an ellipsoid implementing the use of a function
#define PI 3.14159265358979323846

double volume_of_ellipsoid(double a, double b, double c);//function prototype

int main(void)
{
	double volume, a, b, c;//declaring the variables
	
	//looping 4 times to get the volume of 4 ellipsoids
	for(int i=1;i<=4;++i)
	{
		//getting the input from the user
	printf("Please enter the values for a axis, b axis, and c axis of the ellipsoid:\n");//prompting the user
	scanf("%lf\n %lf\n %lf", &a, &b, &c);//reading in the user input for the three 3 axes values
	

	volume= volume_of_ellipsoid(a, b, c);
	
	printf("The volume of ellipsoid is: %lf\n", volume);//displaying the volume on the screen
	}
	return 0;
	
}

//Function to find the volume
//returns the volume of an ellipsoid
double volume_of_ellipsoid(double a, double b, double c)//calling the function by value
{
	return 1.33 * PI * a * b * c;//calculate the volume of an ellipsoid and return the result
}
	

	
	
