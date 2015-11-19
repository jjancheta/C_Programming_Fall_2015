// WORKSHOP 5
// J. ANCHETA / ID # 017 433 152


//FRACTION SIMPLIFIER


#include <stdio.h>

int specialFraction(int numerator, int denominator);
void simplify(int *numerator, int *denominator);


int main(void){

	int numerator1;
	int denominator1;
	int num1;
	int num2;
	int fractionCase;

	printf("Numerator:\t");
	scanf("%d", &numerator1);
	printf("Denominator:\t");
	scanf("%d", &denominator1);
	printf("\n");
	
	fractionCase = specialFraction(numerator1, denominator1);

	if (fractionCase == 1){

		num1 = numerator1;
		num2 = denominator1;

		simplify(&numerator1, &denominator1);

		printf("%d / %d = %d / %d\n", num1, num2, numerator1, denominator1);

	}

	return 0;
}


// This function validates and simplify SPECIAL fractions and return a value if its not a special fraction.

int specialFraction(int numerator, int denominator){

	int result;
	
	if (numerator == 0)
		printf("%d / %d = 0\n", numerator, denominator);

	else if (denominator == 0)
		printf("%d / %d = UNDEFINED\n", numerator, denominator);

	else if (denominator == 1)
		printf("%d / %d = %d\n", numerator, denominator, numerator);

	else
		result = 1;

	return result;

}

// This function will simplify fraction by taking the lowest number entered by the user.
// This lowest number will be used to divide with the 2 numbers (numerator & denomintor) until both will return 0 remainder.
// If both will return 0 remainder, this will become the GCD to be used to simplify the fraction

void simplify (int *numerator, int *denominator){

	int commonNum;                               
	int lowestNum;

	
	if (*numerator < *denominator && *numerator > 0)
		lowestNum = *numerator;                      
	
	else if (*denominator > 0)
		lowestNum = *denominator;
	
	else
		lowestNum = *numerator;          // select the + number if 1 number is - to get the same result during division.
										 // if both are negative, it select the less number of looping (bigger value).
	


	while (lowestNum != 0){

		if (*numerator % lowestNum == 0 && *denominator % lowestNum == 0) {   //if lowestNum = +1 or -1 and its the number that can satisfy this condition, meaning fraction cannot be simplified.
				commonNum = lowestNum;				  
				lowestNum = 0;                       // exit the loop 
		
		} else if (lowestNum > 0)
					
					lowestNum = lowestNum - 1;       // for positive number
		
			  	else
					lowestNum = lowestNum + 1;		// for negative number
	}
	

	if (commonNum == -1)
		commonNum *= commonNum;       // both are negative and cannot be simplied. Change the sign so it will return the same value and signs of the numbers.

	*numerator = *numerator / commonNum;
	*denominator = *denominator / commonNum;

}