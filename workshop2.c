// Workshop 2
// J. ANCHETA / ID 017 433 152

#include <stdio.h>

int main(void){
	
	int item;
	float price, cash;
	float purchase, HST, total, change, cents;
	
	printf("Enter the number of items:\t");						// prompts the user for the number of items purchased
	scanf("%d", &item);											// accepts the number of items purchased
	printf("Enter the unit price:\t\t");						// prompts the user for the unit price of each item
	scanf("%f", &price);										// accepts the unit price of each item
	
	purchase = item * price;									// calculates the total purchase price
	
	printf("Purchase price \t\t\t%.2f\n", purchase);

	HST = purchase *  0.13;										// calculates the HST

	printf("HST (13%%) \t\t\t%.2f\n", HST);

	total = purchase + HST;

	printf("Total Price \t\t\t%.2f\n\n", total);				// outputs the total purchase price

	printf("Cash tendered\t\t\t");								// prompts the user for the cash tendered
	scanf("%f", &cash);				  							// accepts the amount of cash tendered

	change = cash - total;       								// calculates the change owed to the user
	
	printf("Change loonies\t\t\t%d\n", (int)change);			// outputs the number of loonies in the change

	cents = change * 100 + 0.5;
	
	printf("Change cents\t\t\t%d\n", (int)cents % 100); 		// outputs the number of cents in the change

	return 0;

}
	
	
