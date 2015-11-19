// Workshop 3 
// J. ANCHETA / ID # 017 433 152


// UPC Validator

#include <stdio.h>

int main(void){

	long long UPC;
	int done = 0;
	int i;
	int comCode;
	int proCode;

	printf ("UPC Validator\n");
	printf ("==============\n");

	while (done != 1){

		int value = 0;
		int even = 0;
		int odd = 0;
		int check = 0;
		int total = 0;

		printf("UPC (0 to quit): ");
		scanf("%lld",&UPC);

		comCode = UPC / 1000000;
		proCode = (UPC / 10) % 100000;

	
		if (UPC == 0){
			done = 1;
		}


		else{
		
			for (i=12; i >= 1; i--){
			
				value = UPC % 10;

				if (i % 2 == 0 && i != 12){
					even += value;
					//printf ("%d - even %d - value\n", i, value);
				}
				else if (i <= 11){
					odd += value;
					//printf ("%d - odd %d - value\n", i, value);
				}	
				else{
					check = value;
					//printf ("%d - check %d - value\n", i, value);
				}
			
				UPC = UPC / 10;

			}

			total = (odd * 3) + even + check;

			//printf ("%d total\n", total);

			if (total % 10 == 0){
				printf ("This is a valid UPC.\n");
				printf ("The company code is %06d.\n", comCode);
				printf ("The product code is %05d.\n", proCode);
			}
			else{
				printf ("This is not a valid UPC.\n");
			}

		}
	}	
	
	printf ("Have a Nice Day!\n");


	return 0;
}


// another valid UPC 1234 5678 9012  odd total = 78 even total = 20  sum = (98 + 2) % 10 