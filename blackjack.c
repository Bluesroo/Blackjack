#include "prototypes.h"
#include <stdio.h>

int main(void)
{
	int done, dealer = 0, *dealerPointer;
	dealerPointer = &dealer;

	//Creates the deck variable
	CARD deck[DECKSIZE];
	
	//Generates the deck
	deckMake(deck);
	
	//Shuffles the deck
	deckShuffle(deck);

	//Deals until the player doesn't want a rematch
	while(done != 1)
		done = deal(deck, dealerPointer);

	return 0;
}
