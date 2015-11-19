// WORKSHOP 6
// J. ANCHETA / ID # 017 433 152


// GROCERY STORE INVENTORY



#include <stdio.h>
#define N_ITEMS 100


void display (long int barcode[], float price[], int qty[], int num);

int validateInput (int itemNumber, int readFunction1, long int inputData,  char endInput);

void clear(void);


int main(void){
	
	long int barcode[N_ITEMS], y;
	float price[N_ITEMS];
	int qty[N_ITEMS];
	int counter = 0;
	int i, read;
	int input1=0, input2=0, input3 = 0;
	char endInput;

	printf ("Grocery Store Inventory\n");
	printf("=======================\n");

	for (i = 0; i < N_ITEMS; i++){

		do{
		printf("Barcode  :	");
		read = scanf("%ld%c",&barcode[i], &endInput);

		//printf("barcode = %ld\n", barcode[i]);
		//printf ("read = %d\n", read);

		input1 = validateInput(1, read, barcode[i], endInput);

		} while (input1 == 0);	

		
		if (barcode[i] == 0)
			i = N_ITEMS;
		
		else {
			
			do{
			printf("Price    :	");
			read = scanf("%f%c", &price[i], &endInput);

			input2 = validateInput(2, read, price[i], endInput);
			
			}while (input2 == 0); 

			
			do{
			printf("Quantity :	");
			read = scanf("%d%c", &qty[i], &endInput);

			input3 = validateInput(3, read, qty[i], endInput);

			} while (input3 == 0);

			counter = i + 1;	
		}	
	}

	display(barcode, price, qty, counter);
		
	return 0;
}


//This function will validate the inputs and it should in range or it cannot be less than 0.

int validateInput (int itemNumber, int readFunction1, long int inputData, char endInput){

	int result;

	switch (itemNumber){
		case 1:
			if (readFunction1 != 2){
				printf("ERROR! Try Again!\n");
				result = 0;
				clear();

			} 
			else if (endInput != '\n'){
				printf("ERROR! Try Again!\n");
				result = 0;
				clear();

			} else if ( inputData == 0)
				result = 1;
			
			else if (inputData < 1000000000 || inputData > 9999999999){
				printf("ERROR! Try Again!\n");
				result = 0;
			
			} else
				result = 1;

			break;

		case 2: case 3:
			if ( readFunction1 != 2){
				printf("ERROR! Try Again!\n");
				result = 0;
				clear();
			
			} else if (endInput != '\n'){
				printf("ERROR! Try Again!\n");
				result = 0;
				clear();
			
			} else if (inputData <= 0) {	
				printf("float data: %f\n", inputData);
				printf("ERROR! Try Again!\n");
				result = 0;
			
			} else
				result = 1;	 

			break;

	}	

	return result;

}


// This function will display the summary of the inventory and calculates the total value

void display (long int barcode[], float price[], int qty[], int num){

	int i;
	float total=0;

	printf("\n\n\t\tGoods in Stock\n");
	printf("\t\t==============\n");
	printf("Barcode\t\tPrice\tQuantity\tValue\n");
	printf("--------------------------------------------------------\n");

	for (i = 0; i < num; i++) {
		printf("%10ld %10.2f %10d     %10.2f\n", barcode[i], price[i], qty[i], price[i] * qty[i]);
		total += price[i] * qty[i];
	}	

	printf("\t\t\t\t\t--------\n");
	printf("Total value goods in stocks          %10.2f\n\n", total);

}


// This function clears the input buffer.

void clear(void){

	while (getchar() != '\n')
		;

}





