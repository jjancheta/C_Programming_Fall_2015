// WORKSHOP 8
// J. ANCHETA / ID # 017 433 152


// WORD COUNT

#include <stdio.h>
#include <string.h>


// This program will ask the user to input text to be analyzed and displays the number of words in the text.

int wordCount(char* textInput);


int main(void){
	
	char textInput[101];                         
	int count;

	printf("\nWord Counter\n");
	printf("=============\n");

	printf("Text to be analyzed : ");
	scanf("%100[^\n]", textInput);                

	count = wordCount(textInput);	
	
	printf("Word Count          : %d\n\n", count);

	return 0;

}


//  This function will return the number of word/s inputted by the user.

int wordCount(char* textInput){

	int count = 0;
	int i;
	int length;
	
	length = strlen(textInput);
	
	
	if (length > 0){

		textInput[length] = ' ';                                         

		for (i = 0; i < length; i++){
		
			if ((textInput[i] != ' '  && 					              // first set of condition if TRUE = non whitespace character
				 textInput[i] != '\n' && 
				 textInput[i] != '\r' && 
				 textInput[i] != '\t' && 
				 textInput[i] != '\f' && 
				 textInput[i] != '\v' )    
										  && (textInput[i+1] == ' '  ||   // second set of condition if TRUE = white space character
											  textInput[i+1] == '\n' || 
											  textInput[i+1] == '\r' || 
											  textInput[i+1] == '\t' || 
											  textInput[i+1] == '\f' || 
											  textInput[i+1] == '\v')) {         
				
				count +=1;	            // pattern at the end of every word is non whitespace character followed by whitespace character.                                

			}
		}
	
	}	

	return count;

}




