// WORKSHOP 6
// J. ANCHETA / ID # 017 433 152


// DICE THROWS

// This program ask the user to enter the total of 2 dices when thrown that he wants.
// Input is validated by a function called validate and if out of range, it will ask user again to enter another number.
// The program will generate 2 random numbers from 1 to 6 continously and will only stop if the total matches the inputed number by the user.
// At the end of the program, it will print the total of throws to get the total.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int validate (int resultFunction1, int numFunction1, int endInputFunction1);
void throw (int total);
void clear(void);

int main(void){

	int num;
	char endInput;
	int result = 0;
	int loop = 0;


	printf("Game of Dice\n");
	printf("=============\n");

	while (loop == 0){ 

		printf("Enter total sought: ");
		result = scanf ("%d%c", &num, &endInput);
		
		loop = validate(result, num, endInput);
		
	}

	throw (num);

	return 0;

}

// This function will validate the input of the user if its inside the range (e.g. 2-12).

int validate (int resultFunction1, int numFunction1, int endInputFunction1){

	int result;

	if (resultFunction1 != 2){
		printf("** Invalid Input! Try Again! **\n");
		result = 0;
		clear();

	} else if (endInputFunction1 != '\n'){
		printf("** Invalid Input! Try Again! **\n");
		result = 0;				
		clear();

	} else if (numFunction1 > 12 || numFunction1 <= 1){
		printf("** Invalid Input! Try Again! **\n");
		result = 0;
	
	} else
		result = 1;

	return result;

}

//This function will generate 2 different random numbers and it will stop when the total of these 2 random numbers
// is equal to the inputted number.

void throw (int total){

	int count = 0;
	int dice1, dice2;

	srand(time(NULL));

	while (dice1 + dice2 != total) {

		count = count + 1;

		dice1 = rand() % 6 + 1;
		dice2 = rand() % 6 + 1;

		printf("Result of throw %d:  %d + %d\n", count, dice1, dice2);
		
	}

	printf("You got your total in %d throws!\n", count);  

}

//This function clears the input buffer.

void clear (void){
	while(getchar() != '\n')
		;
}	
