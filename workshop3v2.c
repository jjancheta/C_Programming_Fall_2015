// Workshop 3
// J. ANCHETA / ID # 017 433 152



#include <stdio.h>

int main (void)
{
	int count, value;
	int done = 0;

	printf ("SIN Validator\n");
	printf ("==============\n");

	do 
	{
		int even = 0;
    	int odd = 0;
    	int total = 0;
    	int mult = 0;
    	int check = 0;
	
		printf ("SIN (0 to quit):");

		for (count = 1 ; count <= 9 && done == 0 ; count++)
		{
			scanf("%1d", &value);

			if (value == 0 && count == 1)
				done = 1;		
         
			else if (count % 2 == 0)    //(count % 2 == 0 && count <= 9)
			{
	     		value = ((value * 2) >= 10 )? (value * 2) % 10 + 1 : value * 2;
		   		even += value;
				//printf("even %d - count%d\n", value, count);
			}
	    
	    	else if (count <= 8) 
	    	{
		  		odd += value;
        		//printf("odd %d - count%d\n", value, count);
	    	}
	    
	    	else
	    	{
		  		check = value;
		  		//printf ("last %d - count %d\n", check, count);
         	}
        }

		total  = even + odd;

		mult = ((total /10) * 10) + 10;

		if (mult - total == check)
			printf ("This is a valid SIN.\n", total, mult);
			//printf ("%d - %d", total, mult);

		else if (done == 0) 
			printf ("This is not a valid SIN.\n");
			//printf ("%d - %d", total, mult);	


	} while ( done !=1);

		printf ("Have a Nice Day!\n");


	return 0;

}
