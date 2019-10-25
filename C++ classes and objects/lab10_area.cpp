//this program finds the area of different shapes
//the user is able to specify the required parameters but default parameters are also provided
#include <iostream>
#include <iomanip>
#define PI 3.14159265359
using namespace std;

float triangle_area(float height=1.0, float base=2.3);
float square_area(float side=10);
float rectangle_area(float height1, float length=20);
float rhombus_area(float diagonal1=10.2, float diagonal2=3.8);
float circle_area(float radius=3.6);
float trapezoid_area(float height2, float base1, float base2=8);

int main()
{
	int choice;//user's choice for the shape for which they want to calculate area
	int answer;//user's answer for whether they want to use the default values or not
	
	//asking the user which shape they want
	cout << '\n' << "What shape area would you like to calculate: " << "\n";
	cout << "1. Triangle" << "\t" << "2. Square" << "\n" << "3. Rectangle" << "\t";
	cout << "4. Rhombus" << "\n" << "5. Circle" << "\t" << "6. Trapezoid" << "\n" << "Your choice: ";
	
	cin >> choice;//reading in the value for choice
	
	switch(choice){
		case 1://area of a triangle
		cout << "The default parameteres for the triangle are height=1.0, base=2.3" << "\n";
		cout << "Would you like to change them? Enter 1 for YES enter 2 for NO" << "\n";
		cin >> answer;
		if (answer == 1)//if they want to change the default values
		{
			float height, base;
			cout << "Height: ";
			cin >> height;
			cout << "Base: ";
			cin >> base;
			cout << "The area of the triangle is: " << triangle_area(height, base) << "\n";
		}
		else if (answer == 2) {//if default values are to be used for the area of the triangle 
		cout<< "The area of the triangle is: " << triangle_area() << "\n";
		}
		else {//error checking
			cout << "Enter Valid Input: "; cin >> answer;
		}
		break;
		
		case 2://area of a square
		cout << "The default parameteres for the square are side = 10" << "\n";
		cout << "Would you like to change them? Enter 1 for YES enter 2 for NO" << "\n";
		cin >> answer;
		if (answer == 1)//if they want to change the default values
		{
			float side;
			cout << "Side: ";
			cin >> side;
			cout << "The area of the square is: " << square_area(side) << "\n";
		}
		else if (answer == 2){//if default values are to be used for the area of the square
		cout << "The area of the square is: " << square_area() << "\n";
		}
		else{//error checking
			cout << "Enter Valid Input: "; cin >> answer;
		}
		break;
		
		case 3://area of a rectangle
		cout << "The default parameteres for the rectangle are length = 20" << "\n";
		cout << "Would you like to change them? Enter 1 for YES enter 2 for NO" << "\n";
		cin >> answer;
		
		//read in the height as it wasn't provided as default
		float height1;
		cout << "Height: ";
		cin >> height1;
		
		if (answer == 1)//if they want to change the default values
		{
			float length;
			cout << "Length: ";
			cin >> length;
			cout << "The area of the rectangle is: " << rectangle_area(height1, length) << "\n";
		}
		else if (answer == 2){//if default values are to be used for the area of the rectangle
		cout << "The area of the rectangle is: " << rectangle_area(height1) << "\n";
		}
		else{//error checking
			cout << "Enter Valid Input: "; cin >> answer;
		}
		break;
		
		case 4://area of a rhombus
		cout << "The default parameteres for the rhombus are diagonal1 = 10.2, diagonal2 = 3.8" <<"\n";
		cout << "Would you like to change them? Enter 1 for YES enter 2 for NO" << "\n";
		cin >> answer;
		if (answer == 1)//if they want to change the default values
		{
			float diagonal1, diagonal2;
			cout << "Diagonal1: ";
			cin >> diagonal1;
			cout << "Diagonal2: ";
			cin >> diagonal2;
			cout << "The area of the rhombus is: " << rhombus_area(diagonal1, diagonal2) << "\n";
		}
		else if (answer == 2){//if default values are to be used for the area of the rhombus
		cout << "The area of the rhombus is: " << rhombus_area() << "\n";
		}
		else{//error checking
			cout << "Enter Valid Input: "; cin >> answer;
		}
		break;
		
		case 5://area of a circle
		cout << "The default parameteres for the circle are radius = 3.6" << "\n";
		cout << "Would you like to change them? Enter 1 for YES enter 2 for NO" << "\n";
		cin >> answer;
		if (answer == 1)//if they want to change the default values
		{
			float radius;
			cout << "Radius: ";
			cin >> radius;
			cout << "The area of the circle is: " << circle_area(radius) << "\n";
		}
		else if(answer == 2){//if default values are to be used for the area of the circle
		cout << "The area of the circle is: " << circle_area() << "\n";
		}
		else{//error checking
			cout << "Enter Valid Input: "; cin >> answer;
		}
		break;
		
		case 6://area of a trapezoid
		cout << "The default parameteres for the trapezoid are base2 = 8" <<"\n";
		cout << "Would you like to change them? Enter 1 for YES enter 2 for NO" << "\n";
		cin >> answer;
		
		//read in the height and the base from the user's input as they weren't provided as default
		float height2, base1;
		cout << "Height: ";
		cin >> height2;
		cout << "Base1: ";
		cin >> base1;
		
		if (answer == 1)//if they want to change the default values
		{
			float base2;
			cout << "Base2: ";
			cin >> base2;
			cout << "The area of the trapezoid is: " << trapezoid_area(height2, base1, base2) << "\n";
		}
		else if(answer == 2){//if default values are to be used for the area of the rhombus
		cout << "The area of the trapezoid is: " << trapezoid_area(height2, base1) << "\n";
		}
		else{//error checking
			cout << "Enter Valid Input: "; cin >> answer;
		}
		break;
		
		
	
}
}

//function definitions to calculate area of each of the shapes

float triangle_area(float height, float base)
{
	return (height * base)/2;
}

float square_area(float side)
{
	return side * side;
}

float rectangle_area(float height1, float length)
{
	return height1 * length;
}

float rhombus_area(float diagonal1, float diagonal2)
{
	return (diagonal1 * diagonal2)/2;
}

float circle_area(float radius)
{
	return PI * radius * radius;
}

float trapezoid_area(float height2, float base1, float base2)
{
	return ((base1 + base2)/2) * height2;
}
