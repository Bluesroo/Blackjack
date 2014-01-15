#include "prototypes.h"
#include <stdio.h>

int main(void)
{
	int done;
	//Creates the deck variable
	card deck[DECKSIZE];
	
	//Generates the deck
	deckMake(deck);
	
	//Shuffles the deck
	deckShuffle(deck);

	//Deals until the player doesn't want a rematch
	while(done != 1)
		done = deal(deck);

	return 0;
}
