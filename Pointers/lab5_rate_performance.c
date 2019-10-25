//Program that asks users to rate the performance of political parties (FineF, FineG, SinnF, GreenP, IndependA) by rating the party's performance out of 10.
//After asking for the rating the program asks the questions again for the next user and so on.
//After the last user has indicated that there are no more users, the program gives a summary of the results, showing which political party had the highest and lowest rating

#include <stdio.h>
#include <string.h>
#define MAX_SIZE 50

int main(void)
{
	
	int n;//number of users
	//int arr[n][5];//array which stores the ratings for the 5 parties entered by the n users
	int i,j;
	char *parties_names[5]={"FineF", "FineG", "SinnF", "GreenP", "IndependA"};
	int rate=0;//variable used to store the rating entered for each party
	int sum;//variable used to store the sum of all the ratings for each party
	
	printf("How many users would you like to ask?\n");//determines how amny times to ask for ratings for the 5 parties
	scanf("%d", &n);//reading in the input for the amount of users that will provide the ratings for the 5 parties
	
	//reading in and storing the ratings
	
	int ratings[n][5];//array which stores the ratings for the 5 parties entered by the n users
		for(i=0;i<n;i++)
		{
			for(j=0;j<5;j++)
			{
			printf("Provide the rating between 1 and 10 for the party: %s\n", parties_names[j]);//prompt the user to provide the rating for the party
			scanf("%d", &rate);//read in the user input for the rate
			ratings[i][j] = rate;
			printf("%d", ratings[i][j]);
			
			}
			

		}
	
	//summing the ratings
	
	for(j=0;j<5;++j)
	{
		sum=0;
		for(i=0;i<n;++i)
		{
			sum=sum+ratings[i][j];//calculate the sum of the ratings of each party
		}
		printf("The sum of ratings of party %d is %d \n", j, sum);//displays the sum of all the ratings entered for each of the parties
		
	}
}