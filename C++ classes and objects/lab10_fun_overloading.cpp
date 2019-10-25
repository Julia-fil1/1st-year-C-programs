//this program demonstrates function overloading by creating 4 functions called addTwo in one program
//which have two arguemnts of the same type and return the two numbers added together
#include <iostream>
using namespace std;

//function for float values
float addTwo(float a, float b)
{
	cout << "float" << a << "+" << b << "=";//printing out the sum to the screen
	return a + b;//returning the sum
}

//function for integer values
int addTwo(int a, int b)
{
	cout << "integer" << a << "+" << b << "=";//printing out the sum to the screen
	return a + b;//returning the sum
}
//function for double values
double addTwo(double a, double b)
{
	cout << "double" << a << "+" << b << "=";//printing out the sum to the screen
	return a + b;//returning the sum
}

//function for long values
long addTwo(long a, long b)
{
	cout << "long" << a << "+" << b << "=";//printing out the sum to the screen
	return a + b;//returning the sum
}
int main()
{
	cout << addTwo(1,2) << endl;
	cout << addTwo(100000000, 200000000) << endl;
	cout << addTwo((float)0.3, (float)0.5) << endl;//this call had to be forced beacuse otherwise it would run the double function
	cout << addTwo(3.14159265358979323846, 2.123456764828483291799) <<endl;
}









/*
	int main()
{
  //depending on the types of integers entered, the program will know which function to use.
  //I had to force the third call to have float values, otherwise it would just run the double function
  //instead of the float.
  cout << addTwo(7, 8) << endl;
  cout << addTwo(7000000000, 8000000000) << endl;
  cout << addTwo((float)0.7, (float)0.3) << endl;
  cout << addTwo(1.4123456789, 2.4356721456) << endl;
}
*/