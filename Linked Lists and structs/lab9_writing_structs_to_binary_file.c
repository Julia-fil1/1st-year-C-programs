//This program creates 5 structs from the integer array myCustomers and writes each struct to binary file named customers.dat
//myCustomers has 2 columns. Column 0 contains the area/zip code and column 1 contains the number of customers living there
#include <stdio.h>

//struct definition
struct zip_cuts{
	int zip_code;
	int customer_count;
};

int main(void)
{
	FILE *filePtr;//customers.dat file pointer
	
	//2D array holding the customer data
	int myCustomers[5][2] = {{86956, 1}, {36568, 3}, {6565,0}, {999555, 22}, {85446, 88}};
	
	//initializing array of structs type zip_cuts
	struct zip_cuts CustomerData[5];
	
	//fopen opens the file; exits if the file cannot be opened
	if((filePtr = fopen("customers.dat", "wb+")) == NULL){//open the file customers.dat in the read and write in binary mode
		puts("File could not be opened.");//print this if a problem is encountered while trying to open the file
	}
	else{
		int j=0;
		
		//for loop to fill the structs with customer data  
		for(size_t i=0; i<5; i++){
			
			CustomerData[i].zip_code = myCustomers[i][j];
			CustomerData[i].customer_count = myCustomers[i][j+1];
			
			fprintf(filePtr, "%d %d\n", CustomerData[i].zip_code, CustomerData[i].customer_count);//print the data to the file
		}
	}
	fclose(filePtr);//close the file
}
