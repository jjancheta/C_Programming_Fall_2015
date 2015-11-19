// WORKSHOP 7
// J. ANCHETA / ID # 017 433 152


// GROCERY STORE INVENTORY

// This program will list all the stocks and the total value of all stocks.
// It will ask the user to input 3 data, the barcode, unit price and total qty.
// All inputs will be validated and will return an error if there are mistakes with the input.


#include <stdio.h>
#define N_ITEMS 100


void inputBarcode (const char* prompt, long int barcode[], int i);
void inputPrice (const char* prompt, float price[], int i);
void inputQuantity (const char* prompt, int qty[], int i);
void display (long int barcode[], float price[], int qty[], int num);
void clear(void);


int main(void){
	
	long int barcode[N_ITEMS], y;
	float price[N_ITEMS];
	int qty[N_ITEMS];
	int counter = 0;
	int i;

	printf ("Grocery Store Inventory\n");
	printf("=======================\n");

	for (i = 0; i < N_ITEMS; i++){

		inputBarcode ("Barcode   : ", barcode, i);

		if (barcode[i] == 0)
			i = N_ITEMS;

		else {

		 	inputPrice("Price     : ", price, i);
		 	inputQuantity("Quantity  : ", qty, i);	

		 	counter = i + 1;
		}

	}

	display(barcode, price, qty, counter);

	return 0;

}	

//This function will ask the user to input BARCODE data and validates the input.

void inputBarcode(const char* prompt, long int barcode[], int i){

	char endInput;
	int result = 0;
	int read;

	do{
		
		printf("%s", prompt);
		read = scanf ("%ld%c", &barcode[i], &endInput);

		if (read != 2){
				printf("ERROR! Try Again!\n");
				result = 0;
				clear();

		} else if (endInput != '\n'){
				printf("ERROR! Try Again!\n");
				result = 0;
				clear();

		} else if (barcode[i] == 0)
				result = 1;
			
		else if (barcode[i] < 1000000000 || barcode[i] > 9999999999){
				printf("ERROR! Try Again!\n");
				result = 0;
			
		} else
				result = 1;

	} while (result == 0); 	

}

//This function will ask the user to input PRICE data and validates the input.

void inputPrice (const char* prompt, float price[], int i){

	char endInput;
	int result = 0;
	int read;

	do{
		
		printf("%s", prompt);
		read = scanf ("%f%c", &price[i], &endInput);

		if (read != 2){
				printf("ERROR! Try Again!\n");
				result = 0;
				clear();

		} else if (endInput != '\n'){
				printf("ERROR! Try Again!\n");
				result = 0;
				clear();
			
		} else if (price[i] <= 0 ){
				printf("ERROR! Try Again!\n");
				result = 0;
			
		} else
				result = 1;

	} while (result == 0); 	

}


//This function will ask the user to input QUANTITY data and validates the input.

void inputQuantity (const char* prompt, int qty[], int i){

	char endInput;
	int result = 0;
	int read;

	do{
		
		printf("%s", prompt);
		read = scanf ("%d%c", &qty[i], &endInput);

		if (read != 2){
				printf("ERROR! Try Again!\n");
				result = 0;
				clear();

		} else if (endInput != '\n'){
				printf("ERROR! Try Again!\n");
				result = 0;
				clear();
			
		} else if (qty[i] <= 0 ){
				printf("ERROR! Try Again!\n");
				result = 0;
			
		} else
				result = 1;

	} while (result == 0); 	


}


// This function will display the summary of the inventory and calculates the total value per item 
// and the grandtotal.

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





