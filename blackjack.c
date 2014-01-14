#include "prototypes.h"
#include <stdio.h>

int main(void)
{
	//Creates the deck variable
	card deck[DECKSIZE];
	
	//Generates the deck
	deckMake(deck);
	
	//Shuffles the deck
	deckShuffle(deck);

	//deal
	//hitOrStay
	//dealTurn
	//winner
	//deal
	//check for end of deck

	return 0;
}
