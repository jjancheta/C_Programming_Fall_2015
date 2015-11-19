// WORKSHOP 6
// J. ANCHETA / ID # 017 433 152


// CARD DRAW

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char validateSuit (char suit);
int validateRank (int rank);

int main(void){

	char suit;
	int rank;
	int exit1;
	int exit2;


	printf("Card Draw\n");
	printf("=============\n");

	do {

		printf("Enter Suit: ");
		scanf (" %c", &suit);

		exit1 = validateSuit(suit);
		
	} while ( exit1 != 1);

	do{

		printf("Enter Rank: ");
		scanf ("%2c", &rank);

		exit2 = validateRank(rank);		

		
	} while (exit2 != 1);	



	return 0;

}


char validateSuit (char suit){

	int result;

	if (suit == 'H' || suit == 'h')
		result = 1;
	else if (suit == 'S' || suit == 's')
		result = 1;
	else if (suit == 'C' || suit == 'c')
		result = 1;
	else if (suit == 'D' || suit == 'd')
		result = 1;
	else {
		printf("** Invalid Input! Try Again. **\n");
		result = 0;
	}

	return result;

}

int validateRank (int rank){

	int result;

	if (rank >= 2 && rank <= 10)
		result = 1;
	else if (rank == 73 || rank == 106)
		result = 1;
	//else if (rank == 'Q' || rank == 'q')
	//	result = 1;
	//else if (rank == 'K' || rank == 'k')
	//	result = 1;
	//else if (rank == 'A' || rank == 'a')
	//	result = 1;
	else {
		printf("** Invalid Input! Try Again. **\n");
		result = 0;
	}

	return result;
}














