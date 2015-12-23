// Assignment 2
// ANCHETA J. / ID # 017 433 152

// WEATHER ANALYZER version 2


#include <stdio.h>

int getInteger (int min, int max);
void getDailyData (float* high, float* low, char* condition);
float average (float first, float second);
void draw (char c, int num);
char symbolToDraw (char condition, float averageTemperature);
void displayResult (int days, float allDaysAverage);
void clear(void);
void error(void);


int main(void){
	
	int numDays;
	int i;
	float sum = 0;
	float dailyHigh;
	float dailyLow;
	char conditions;
	float dailyAvg = 0;

	printf("\nWeather Analyzer 2.0\n");
	printf("=====================\n");

	printf("\nHow many days of data? \n");

	numDays = getInteger (1, 14);

	for(i = 0; i < numDays; i++) { 

		getDailyData (&dailyHigh, &dailyLow, &conditions);
		dailyAvg = average (dailyHigh, dailyLow);
		printf("Today's average temperature is: %.2f\n", dailyAvg);
		sum += dailyAvg;
		draw(symbolToDraw(conditions, dailyAvg), 20);

	}

	displayResult (numDays, (sum/numDays));

	return 0;

}


//FUNCTION 1 - Prompts the user to input an integer between the range of 1 to 14.  If the user entered an invalid number,
// it will display an error and ask the user to input another number.  This function will return a valid integer
// to the main function.

int getInteger (int min, int max){
	
	int numDaysFunction1;
	int validateInput;
	int exitLoop = 0;
	char endInputFunction1;

 
 	do {
		printf("Enter an integer between 1 and 14: ");
		validateInput = scanf("%d%c", &numDaysFunction1, &endInputFunction1);
		
		if (validateInput != 2){                       
			error();
			clear();

		} else if (endInputFunction1 != '\n'){
			error();
			clear();
		
		} else if (numDaysFunction1 < min || numDaysFunction1 > max)
			error();

		else
			exitLoop++;

	} while (exitLoop == 0);

	return numDaysFunction1;

}


//FUNCTION 2 - This function will ask the user to input the daily temperatures (highs & lows) & conditions separated by
//commas.  It validates the inputs (e.g. wrong data types, missing inputs, excess inputs) and will return an error message
// if it doesn't meet criteria and ask the user to input a different set of inputs. 

void getDailyData (float* high, float* low, char* condition){

	float highFunction2;
	float lowFunction2;
	char conditionFunction2;
	char endInput;
	int exitLoop = 0;
	int validateInput;
	

	while (exitLoop == 0) {
		
		printf("\nEnter today's high, low and condition (c = cloudy, s = sunny, p = precipitation) \nseparated by commas: ");
		validateInput = scanf("%f, %f, %c%c", &highFunction2, &lowFunction2, &conditionFunction2, &endInput);

		if (validateInput != 4){
			error();
			clear();
			
		} else if (endInput != '\n'){
			error();
			clear();

		} else if (lowFunction2 > highFunction2){
			error();

		} else if (conditionFunction2 != 'c' && conditionFunction2 != 's' && conditionFunction2 != 'p'){
			error();	
	
		} else {
			*high = highFunction2;
	  	  	*low = lowFunction2;
	  	  	*condition = conditionFunction2;
	   		exitLoop++;
		}
	
	}	

}


//FUNCTION 3 - This function will calculate the daily temperature average and return the result to the main function.

float average (float first, float second){

	float dailyAvgFunction3 = 0;

	dailyAvgFunction3 = (first + second) / 2;

	return dailyAvgFunction3;
}


//FUNCTION 4 - This function will draw row of characters depending on the value of char c which came from Function 5.

void draw (char c, int num){

	int i;

	for (i = 0; i < num; i++){
		printf("%c", c);

	}
	
	printf("\n");

}

//FUNCTION 5 - This function will select which character to send to Function 4 depending on the condition entered
// by the user (Function 2) and the computed daily temperature average (Function 3).

char symbolToDraw (char condition, float averageTemperature){

	char symbolFunction5;

	if (condition == 's')
		symbolFunction5 = '@';
	
	else if (condition == 'c')
		symbolFunction5 = '~';
	
	else if (condition == 'p' && averageTemperature <= 0)
		symbolFunction5 = '*';
	
	else
		symbolFunction5 = ';';

	
	return symbolFunction5;

}

//FUNCTION 6  - This funtion will print the average temperature of all days.  It will also print the number of days 
// in "word" if inputted days is from 1 - 9 otherwise it will print the numeric days.

void displayResult (int days, float allDaysAverage){

	printf("\nYour ");

	switch (days) {
		case 1 :
			printf("one ");
			break;
		case 2 :
			printf("two ");
			break;
		case 3 :
			printf("three ");
			break;
		case 4 :
			printf("four ");
			break;
		case 5 :
			printf("five ");
			break;
		case 6 :
			printf("six ");
			break;
		case 7 :
			printf("seven ");
			break;
		case 8 :
			printf("eight ");
			break;
		case 9 :
			printf("nine ");
			break;
		default :
			printf("%d ", days);
			break;								
	}

	printf("day average is %.2f\n\n", allDaysAverage);

}


//FUNCTION 7 - This function clears the input buffer.

void clear (void){

	while ( getchar() != '\n')
		;
}

//FUNCTION 8 - This function displays an error message for invalid inputs.

void error(void){

	printf("** ERROR! Try Again! **\n");

}



/* I declare that the attached assignment is wholly my own work in accordance with Seneca Academic Policy.
No part of this assignment has been copied manually or electronically from any source (including web sites) or
distributed to other students.

Name:  ANCHETA, JESUS JR     ID:  017 433 152 */
