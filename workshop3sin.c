// Workshop 3
// J. ANCHETA / ID # 017 433 152

// SIN VALIDATOR



#include <stdio.h>

int main (void){
	
	int sinNum;
	int i; 
	int done = 0;

	printf ("SIN Validator\n");
	printf ("==============\n");

	while ( done !=1){
			
			int even = 0;
			int odd = 0;
    		int total = 0;
    		int mult = 0;
    		int check = 0;	
    		int value = 0;

			printf ("SIN (0 to quit):");
			scanf("%d",&sinNum);

			if (sinNum == 0)
				done = 1;


			else {
				for (i = 9 ; i >= 1 ; i--) {
					
					value = sinNum % 10;

					if (i % 2 == 0) {
	     				value = ((value * 2) >= 10 ) ? (value * 2) % 10 + 1 : value * 2;
		   				even += value;
						//printf("even %d - count %d\n", value, i);
		   			} 
		   			else if (i <= 8) {
		  				odd += value;
        				//printf("odd %d - count%d\n", value, i);
		  			} 
		  			else {
		  				check = value;
		  				//printf ("last %d - count %d\n", check, i);
		  			}

					sinNum = sinNum / 10;        

				}	

				total  = even + odd;

				mult =  ((total % 10) == 0) ? total : ((total /10) * 10) + 10;  // what if total = 10 20 30 40 50 60 70 80 90

				if (mult - total == check)
					printf ("This is a valid SIN.\n");
					//printf ("%d - %d", total, mult);

				else 
					printf ("This is not a valid SIN.\n");
					//printf ("%d - %d", total, mult);	
			}	

	} 

		printf ("Have a Nice Day!\n");

	return 0;

}
