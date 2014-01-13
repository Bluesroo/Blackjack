#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

//Card data type
typedef struct
{
	int value;
	char suit[20];
	char rank[10];
} card;

//Functions
void deckMake(card *);
card newLineTrim(card);
void deckShuffle(card *);

#define DECKSIZE 4

int main(void)
{
	int i;
	card deck[DECKSIZE];

	//Generates the deck
	deckMake(deck);

	//Shuffles the deck
	deckShuffle(deck);

	//Deck test
	for(i = 0; i < DECKSIZE; i++)
	{
		printf("%d ", deck[i].value);
		printf("%s ", deck[i].rank);
		printf("%s ", deck[i].suit);

		printf("\n");
	}

	//deckShuffle
	//deal
	//hitorstay
	//dealTurn
	//winner
	//deal
	//check for end of deck

	return 0;
}

//Generates the deck
void deckMake(card *pointer)
{
	int i;
	FILE *value, *suit, *rank;

	value = fopen("value", "r");
	rank = fopen("rank", "r");
	suit = fopen("suit", "r");

	for(i = 0; i < DECKSIZE; i++)
	{
		fscanf(value, "%d", &pointer[i].value);
		fgets(pointer[i].rank, 20, rank);
		fgets(pointer[i].suit, 20, suit);

		pointer[i] = newLineTrim(pointer[i]);
	}

	fclose(value);
	fclose(rank);
	fclose(suit);
	
	return;
}

card newLineTrim(card cardToTrim)
{
	int newLineTrim;

	newLineTrim = strlen(cardToTrim.rank);
	newLineTrim -= 2;
 	cardToTrim.rank[newLineTrim] = '\0';

	newLineTrim = strlen(cardToTrim.suit);
	newLineTrim--;
	cardToTrim.suit[newLineTrim] = '\0';

	return cardToTrim;
}

void deckShuffle(card *deck)
{
	int i = 0, randomCardPlace;
	card temp;

	srand(time(NULL));

	while (i < DECKSIZE)
	{
		randomCardPlace = rand() %(DECKSIZE - 1);
		
		temp = deck[i];
		deck[i] = deck[randomCardPlace];
		deck[randomCardPlace] = temp;

		i++;
	}
}
