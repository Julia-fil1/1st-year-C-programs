#include <stdio.h>
//This program calculates the day of the week based on a date

int day_of_week(int q, int m, int K, int J);//function prototype

//calculate k and then set j
int main(void)
{
	int h,q,m,K,J,day,year;//declaring the variables
	
	//h is the day of the week (0 = Saturday, 1 = Sunday, 2 = Monday, ..., 6 = Friday)
	//q is the day of the month
	//m is the month (3 = March, 4 = April, 5 = May, ...)
	//K the year of the century
	//J is the zero-based century (year mod 100)
	
	//the date is in the (dd/mm/yyyy) format
	
	//Getting the input from the user
	printf("Enter the day:\n");//prompting the user
	scanf("%d", &q);//reading in the user input for the day
	
	printf("Enter the month:\n");//prompting the user
	scanf("%d", &m);//reading in the user input for the month
	
	printf("Enter the year:\n");//prompting the user
	scanf("%d", &year);//reading in the user input for the year
	
	//In this algorithm January and February are counted as months 13 and 14 of the previous year
	//Therefore, we set January(m==1) equal to be the 13th month and decrement the year varibale as it's counted as the 13th month of the previous year
	//Similarly, we set February(m==2) equal to be the 14th month and decrement the year for the reason outlined above
	if(m==1)
	{
		m= 13;
	
	year--;
	}
	
	if(m==2)
	{
		m=14;
	year--;
	}
	
	
	K=year % 100;
	J=year/100;
	
	day=day_of_week(q, m, K, J);
	h++;
	
	if(day==0)
	{
		printf("Saturday\n");
	}
	
	else if(day==1)
	{
		printf("Sunday\n");
	}
	
	else if(day==2)
	{
	printf("Monday\n");
	}
	
	else if(day==3)
	{
		printf("Tuesday\n");
	}
	
	else if(day==4)
	{
		printf("Wednesday\n");
	}
	
	else if(day==5)
	{
		printf("Thursday\n");
	}
	
	else if (day==6)
	{
		printf("Friday\n");
	}
	
	return 0;
}

//function to calculate the day of the week
int day_of_week(int q, int m, int K, int J)//Calling the function by value
{
	//initialising the variables
	int h;
	
	//The Zeller's congruence formula for the Georgian calendar, modified for the implementaion in software
	h=q + ((13*(m+1))/5) + K + K/4 + J/4 + 5*J;
	h=h%7;
	
	//printf("%d" ,h);
	return h;//return the day of the week calculated using the formula above
	
}
	
