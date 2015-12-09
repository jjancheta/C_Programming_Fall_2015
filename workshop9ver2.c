// WORKSHOP 9
// J. ANCHETA / ID # 017 433 152


// SALES RECORD


// This program accepts sales data from the user, adds the sales records, calculates the tax, 
// if applicable, and displays the results.


#include <stdio.h>
const int MAX_SALES = 10;


struct Sale
{
	int qty;
	float price;
	char tax;
};

int enter (struct Sale s[], int maxno);
void total (const struct Sale s[], int no_sales);


int main(){

	int noSales;
	struct Sale sale[MAX_SALES];

	printf("Sale Records \n");
	printf("==============\n");

	noSales = enter(sale, MAX_SALES);
	total(sale, noSales);

	return 0;

}


// This function accepts sales records from the user. It terminates the adding of records once 
// the user entered 0 in quantify field.  It returns the size of the array being field.

int enter (struct Sale s[], int maxno){

	int i;
	int counter = 0;

	for (i=0; i < maxno; i++){
		
		printf("Quantity   : ");
		scanf("%d", &s[i].qty);
		
		if (s[i].qty == 0)
			i = maxno;

		else {

			printf("Unit Price : ");
			scanf("%f", &s[i].price);
			
			printf("Taxable	   : ");
			scanf(" %c", &s[i].tax);
			
			counter += 1; 
			
			printf("\n");
		}	

	}

	return counter;

}



// This function calculates the value per record and computes tax if applicable.  It displays also
// the total value of all sales records plus the tax incurred by some records.

void total (const struct Sale s[], int no_sales){

	int i;
	float subtotal = 0;
	float HST = 0;

	for (i = 0; i < no_sales; i++){

		//printf("Qty: %d\n", s[i].qty);
		//printf("Price: %f\n", s[i].price);
		//printf("Taxable: %c\n", s[i].tax);

		subtotal += s[i].qty * s[i].price;

		if (s[i].tax == 'y')
			HST += s[i].qty * s[i].price * 0.13;

	}

	printf("\nSubtotal   : %5.2f\n", subtotal);
	printf("HST (13%%)  : %5.2f\n", HST);
	printf("Total      : %5.2f\n\n", subtotal + HST);

		
}

