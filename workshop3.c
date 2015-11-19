// Workshop 3
// J. ANCHETA / ID# 017 433 152

#include <stdio.h>

int main(void) {
	int a, b, c, d, e, f, g, h, i, b1, b2, d1, d2, f1, f2, h1, h2, value, lop=1;
	int done = 1;
	int sum1, sum2, sum3, sum4, alt1, alt2, total, mult;

	printf ("SIN VALIDATOR\n");
	printf ("=============\n\n");



	printf("SIN  (0 to quit) :");
	
	for (lop = 1; lop < 10 && done == 1; lop++){
		scanf ("%1d",&value);
			if (value == 0)
				done = 1;

	}
	


	//scanf("%1d %1d %1d %1d %1d %1d %1d %1d", &b, &c, &d, &e, &f, &g, &h, &i);

//	sum1 = b + b;
//	if (sum1 >= 10){
//		b1 = 1;
//		b2 = sum1 - 10;
//		sum1 = b1 + b2;
//	}
	
//	sum2 = d + d;
//	if (sum2 >= 10){
//		d1 = 1;
//		d2 = sum2 - 10;
//		sum2 = d1 + d2;
//	}	
	
//	sum3 = f + f;
//	if (sum3 >= 10){
//		f1 = 1;
//		f2 = sum3 - 10;
//		sum3 = f1 + f2;
//	}
		
//	sum4 = h + h;
//	if (sum4 >= 10){
//		h1 = 1;
//		h2 = sum4 - 10;
//		sum4 = h1 + h2;
//	}


	alt1 = sum1 + sum2 + sum3 + sum4; 	

	alt2 = a + c + e + g;
	
	total = alt1 + alt2;

	mult = ((total /10) * 10) + 10;

	if (mult - total == i){
		printf ("This is a valid SIN.\n");
	}
	else {
	   printf ("This is not a valid SIN.\n");	
	}


	return 0;






}