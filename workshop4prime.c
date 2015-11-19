// Workshop 4
// J. ANCHETA / ID # 017 433 152

// PRIME NUMBERS

#include <stdio.h>

int prime (int i);

int main (void){

	int limit;
	int column;
	int primeNum;
	int i;
	int row;

	printf ("Table of Primes\n");
	printf ("===============\n");

	printf ("Upper limit  :	");
	scanf ("%d", &limit);
	printf ("# of columns :	");
	scanf ("%d", &column);

	for (i = 2; i <= limit; i++ ){

		primeNum = prime(i);		
									
		if (primeNum == 1){
			printf("%d\t", i);
			row = row + 1;
		}	
		
		if (row == column){
			printf ("\n");
			row = 0;
		}
				
	}
	
return 0;

}


// A function to verify if a number is a prime number.

int prime (int i){    			

	int j;
	int count = 0;
	int row;

		for (j = 2; j <=i; j++){
			
			if ( i % j == 0 ){			
				count = count + 1;    // a counter how many met the condition. count > 1 then its not a prime number.
			}	
		}

		return count;    // return the value of count to the main function.

}



