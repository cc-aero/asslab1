//#############################################################################
// Script Name:		main.c						      /
//									     /
// Purpose of Script:	Display a random pair of 8 predefined advertisement /
//			messages					   /  
//									  /  
// Author:		Will Stevens					 /     
//									/      
// Contact Email:	wxs244@student.bham.ac.uk		       / 	      
//##################################################################### 


//Includes

#include <stdio.h>	// For output
#include <stdlib.h>	// We will use the rand function
#include <time.h>	// We will use the srand function
#include <stdbool.h>	// We use booleans in our while loop

const char phrases[8][16] = {	// 8 Elements, 16 Chars Max
"Great News",
"The Awakening",
"Born to Run",
"Walk and Talk",
"Sport Fever",
"Peak Performance",
"New Horizons",
"Non Stop"
};

int main(){
	srand(time(NULL)); // Seed for our random num generation
	
	int idx1;	// Index of our first phrase
	int idx2;	// Index of our second phrase

	bool generatingNums = true;	// Loop condition
	idx1 = rand()%8;	// Index 1 is completely independent of 2
	while (generatingNums){	// We may need to regenerate Index 2 if = idx1
		idx2 = rand()%8;	// Generate Index 2
		if(idx2 != idx1){	// If Index 1 & 2 are not alike...
			generatingNums = false;	// Exit loop
		}
	}
	// Ouput Phrases
	printf(phrases[idx1]);
	printf("\n");
	printf(phrases[idx2]);
	printf("\n");
}
