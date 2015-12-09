// WORKSHOP 10
// J. ANCHETA / ID # 017 433 152


// STATISTICS


#include <stdio.h>
#include <string.h>
#include <math.h>


void dataNumber(char fileName[], int* dataNum, float* mean, float* deviation);

int main (void){

	char fileName[50];
	int dataNum = 0;
	float mean = 0;
	float deviation = 0;
	
	printf("\nStatistics Calculator\n");
	printf("=====================\n");
	printf("Enter the name of the data file : ");
	scanf("%s", fileName);

	dataNumber (fileName, &dataNum, &mean, &deviation);

	printf("\nThe number of data values read from this file was %d \n", dataNum);	
	printf("Their statistical mean is %.2lf\n", mean);
	printf("Their standard deviation is %.2lf\n\n", deviation);
	
	return 0;
	
}

//This function reads the content of a file and calculates the mean and standard deviation.

void dataNumber(char fileName[], int* dataNum, float* mean, float* deviation) {
	
	int i;
	float dataFile;
	int count = 0;
	float total = 0;
	float sumSquares = 0;
	FILE* fp1 = NULL;

	fp1 = fopen (fileName, "r");	
	
	if (fp1 != NULL){   
		while (fscanf(fp1,"%f\n", &dataFile) == 1){
			count += 1;
			total += dataFile;
			sumSquares += pow (dataFile, 2);
			   		
		}
		
		*dataNum = count;
		*mean = total / count;
		*deviation = sqrt ((sumSquares/count) - pow (*mean, 2));	
		
	}
	else
		printf("Failed to open file!\n");		


	fclose(fp1);
}
