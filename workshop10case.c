// WORKSHOP 10
// J. ANCHETA / ID # 017 433 152


// CHANGE CASE


#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>


void changeCase( char choice, char* original, char* updated);

int main (void){

	char original[100];
	char updated[100];
	char choice;

	printf("Change Case\n");
	printf("==============\n");
	printf("Case (U for upper, L for lower) : ");
	scanf(" %c", &choice);
	printf("Name of the original file       : ");
	scanf("%s", original);
	printf("Name of the updated file        : ");
	scanf("%s", updated);

	changeCase (choice, original, updated);

	return 0;
	
}

// This function reads a text file and change the case of the letters either lower case
// or upper case depending on the input of the user and will save it to a new file.

void changeCase( char choice, char* input, char* output){

	int i;
	char text[100];

	FILE *fp1 = fopen (input, "r");
	FILE *fp2 = fopen(output, "w");
	

	while (fscanf(fp1,"%[^\n]\n", text) != EOF){

			for (i = 0 ; i < strlen(text); i++){

				if (toupper(choice) == 'U')
					text[i] = toupper(text[i]);
				
				else if (toupper(choice) == 'L')
					text[i] = tolower(text[i]);

				else {
					printf("Case selected unknown!\n");
					exit(0);
				}
			}
			
			fprintf(fp2, "%s\n", text);	
	}
	
	printf("Text has been updated and stored in %s\n", output);

	fclose(fp1);
	fclose(fp2);	
}
