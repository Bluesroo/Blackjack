#include "prototypes.h"
#include <stdio.h>

int main(void)
{
	card deck[DECKSIZE];
	
	printf("Making the deck...\n");
	//Generates the deck
	deckMake(deck);
	printf("Done!\n");
	
	printf("Shuffling...\n");
	//Shuffles the deck
	deckShuffle(deck);
	printf("Done!\n");

	printf("Time to play!\n");
	//deal
	//hitOrStay
	//dealTurn
	//winner
	//deal
	//check for end of deck

	return 0;
}
