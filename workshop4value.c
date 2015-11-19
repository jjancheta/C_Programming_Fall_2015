// Workshop 4
// J. ANCHETA / ID # 017 433 142

// FUTURE VALUE

#include <stdio.h>

float futureValue (int principal, float rate, int year);


int main (void){

	int principal;
	float rate;
	int year;
	float value;

	printf ("Investment Calculator\n");
	printf ("=====================\n");
	printf ("Principal   : ");
	scanf ("%d", &principal);
	printf ("Annual Rate : ");
	scanf ("%f", &rate);
	printf ("No of Years : ");
	scanf ("%d", &year);

	value = futureValue(principal, rate, year);   
												 
	printf("\n");
	printf ("The future value is $%.2f\n", value);  // prints the value that was stored 

	return 0;

}


//computes the future value of an investment based on the principal, rate & years inputted by


float futureValue (int principal, float rate, int year){

	int i;
	float interest;
	float semiInterest = 1;

	for (i = 0; i < year; i++){

		semiInterest = semiInterest * (1 + rate);   //compute the partial formula (1 + rate) ^ (number of periods)
	}

	interest = principal * semiInterest;

	return interest;

}
