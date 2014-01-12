#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

typedef struct
{
	int value;
	char suit[20];
	char rank[10];
} card;

void deckMake(card *);
void deckShuffle(void);

int main(void)
{
	int i;
	card deck[16];

	deckMake(deck);

	for(i = 0; i < 4; i++)
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

void deckMake(card *pointer)
{
	int i, j = 0, newLineTrim;
	FILE *value, *suit, *rank;

	value = fopen("value", "r");
	rank = fopen("rank", "r");
	suit = fopen("suit", "r");

	for(i = 0; i < 4; i++)
	{
		fscanf(value, "%d", &pointer[i].value);

		fgets(pointer[i].rank, 20, rank);
		newLineTrim = strlen(pointer[i].rank);
		newLineTrim -= 2;
		pointer[i].rank[newLineTrim] = '\0';

		fgets(pointer[i].suit, 20, suit);
		newLineTrim = strlen(pointer[i].suit);
		newLineTrim--;
		pointer[i].suit[newLineTrim] = '\0';
	}

	fclose(value);
	fclose(rank);
	fclose(suit);
	
	return;
}
