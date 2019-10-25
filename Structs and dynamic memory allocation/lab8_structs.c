//this program can fill and initialise the structures with user data read from two files and print the name, population, county's longName, county's shortName for each of the 5 town records 
#include <stdio.h>
#include <string.h>
#define MAX 50
#define MIN 5

int count_no_rows(void); //function prototype to count lines from the file

//struct storing the data from the counties.txt file
struct county{
  char *longName;
  char *shortName;
  unsigned int population;
};

//struct storing the data from the towns.txt file
struct town{
  char *name;
  unsigned int population;
  struct county aCounty;
};

int main(void)//main function
{
  FILE *countyPtr; //pointer to counties.txt file

	//fopen opens the file
	//exit program if unable to open the file
	if ((countyPtr = fopen("counties.txt", "rb+")) == NULL)//open the file counties.txt for both reading and writing in binary mode
  {
    printf("\nThe file could not be opened.\n");//print this if a problem is encountered while trying to open the file
  }
	else
  {
    int rows = count_no_rows();//calling the function to count the rows of data in the document
    struct county counties[rows];//array of struct in which data from counties.txt is saved
    
	//2-d arrays to store the data from the file
    char countyLongName[rows][MAX];
    char countyShortName[rows][MIN];

	//for loop to iterate through the rows of data in the file counties.txt
    //it scans the elements from the file and places them in the 'struct county' array
	for (size_t i = 0; i < rows; i++)
    {
		fscanf(countyPtr, "%s %s %u", countyLongName[i], countyShortName[i], &counties[i].population);
		counties[i].longName = countyLongName[i];
		counties[i].shortName = countyShortName[i];
    }

    FILE *townsPtr; //pointer to towns.txt file
	
	//open file. If file cannot be opened prompt warning message and exit
    if ((townsPtr = fopen("towns.txt", "rb+")) == NULL)//open the file towns.txt for both reading and writing in binary mode
    {
		printf("\nThe file towns.txt could not be opened.\n");//print this if a problem is encountered while trying to open the file
    }
     else
     {
		 struct town towns; //definimg struct variable
		 
		 //arrays in which the data from the file is stored
		 char nameTown[MAX];
		 char county[MAX];
		 
		 //while loop to scan data from file and print it
		 while (!feof(townsPtr))
		 {
         fscanf(townsPtr, "%s %u %s", nameTown, &towns.population, county);
         towns.name = nameTown;

         //for loop to compare and fill the 'aCounty' struct
         for (size_t i = 0; i < rows; i++)
         {
			 if (strcmp(county, counties[i].longName) == 0)
			 {
				 towns.aCounty.longName = counties[i].longName;
				 towns.aCounty.shortName = counties[i].shortName;
				 towns.aCounty.population = counties[i].population;
			 }
         }

         //prompt messages with the informatin required for each town
         printf("\nTown: %s\n", towns.name);
         printf("Population: %d\n", towns.population);
         printf("County: %s, %s\n", towns.aCounty.longName, towns.aCounty.shortName);
         printf("County's population: %d\n", towns.aCounty.population);
       }
       printf("\n");
     }

     fclose(townsPtr); //close file

    fclose(countyPtr);//close file
  }
}
//function definition to count the number of rows of data in the file
//this is needed if new data is added in the future
int count_no_rows()
{
	FILE *coPtr; //pointer to the file
	int rows_counter = 0;//initialize counter to 0

	//fopen opens the file
	//exit program if unable to create file
	if ((coPtr = fopen("counties.txt", "r")) == NULL)
	{
		printf("The file could not be opened.\n");
	}
	else
	{
		char arr[MAX];
		//using fgets to count the number of rows of data
		while (fgets(arr, MAX, coPtr) != NULL)
		{
			rows_counter++;
		}
		fclose(coPtr);//close file
	}
	return rows_counter; //return the number of lines
}