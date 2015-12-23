// Assignment 1
// ANCHETA J. / ID # 017 433 152

// WEATHER ANALYZER

// A program that asks a user to enter the number of days and input high and low temperatures for each day.
// This program will keep asking the user to input number of days until he enter a value greater than 0.
// The program validates also the low temperature entered by the user and keep asking until user enter a value lesser than the high temperature.
// The program will compute the average temperature per day and print out symbols depending on the average temperature per day.
// The program will output also the number of days entered and the average temperature of all days.


#include <stdio.h>

int main(void){

	int numDay;
	float high;
	float low;
	char condition;
	float average;
	float subtotal;
	const int symbols = 20;
	int i;
	int j;

	
	printf("Weather Analyzer\n");
	printf("=================\n");

	do {
		printf("Please enter a positive number of days: ");
		scanf("%d", &numDay);
	
	} while (numDay <=0);


	for (i=1; i<=numDay; i++){

		printf("DAY: %d\n", i);
		printf("Enter today's high: ");
		scanf("%f", &high);
		
		do {
		printf("Enter today's low: ");
		scanf("%f", &low);

		if (low > high)
			printf("Invalid Input! Must be <= than high temperature.\n");

		} while (low > high);
		
		printf("Enter today's conditions (s: sunny, c: cloudy, p: precipicitation): ");
		scanf (" %c", &condition);
		
		average = (high + low) / 2;

		printf("Today's average temperature is: %.2f\n", average);


		if (condition == 's'){
			for (j=0; j<symbols; j++)
				printf ("@");

		} else if (condition == 'c'){
			for (j=0; j<symbols; j++)
				printf("~");

		} else if (condition == 'p' && average <= 0){
			for (j=0; j<symbols; j++)
				printf("*");
		
		} else {
			for (j=0; j<symbols; j++)
				printf(";");

		}
		
		printf("\n");

		subtotal += average;

		average = 0;

	}

	printf("Average for all %d days is: %.2f degrees.\n", numDay, subtotal/numDay);

	return 0;

}


/* I declare that the attached assignment is wholly my own work in accordance with Seneca Academic Policy.
No part of this assignment has been copied manually or electronically from any source (including web sites) or
distributed to other students.

Name:  ANCHETA, JESUS JR     ID:  017 433 152 */





