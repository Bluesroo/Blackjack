#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "prototypes.h"

//Generates the deck
void deckMake(card *pointer)
{
	int i, j, k, value[13];
	char rank[13][RANKSIZE], suit[4][SUITSIZE];
	FILE *valueFile, *suitFile, *rankFile;

	valueFile = fopen("value", "r");
	rankFile = fopen("rank", "r");
	suitFile = fopen("suit", "r");

	//Fills the rank and value arrays with the different ranks and values
	for(i = 0; i < 13; i++)
	{
		fgets(rank[i], RANKSIZE, rankFile);
		fscanf(valueFile, "%d", &value[i]);
	}

	//Fills the suit array with the different suits	
	for(i = 0; i < 4; i++)
	{
		fgets(suit[i], SUITSIZE, suitFile);
	}

	fclose(valueFile);
	fclose(rankFile);
	fclose(suitFile);

	//Does the actual deck generation
	for(i = 0, j = 0, k = 0; i < DECKSIZE; i++, j++)
	{
		if(i % 13 == 0)
		{
			j = 0;
		}
		
		strcpy(pointer[i].rank, rank[j]);
		strcpy(pointer[i].suit, suit[k]);
		pointer[i].value = value[j];

		if((i + 1) % 13 == 0)
		{
			k++;
		}

		//Trims the '\n' from fgets
		pointer[i] = newLineTrim(pointer[i]);
	}
	
	return;
}

//Takes the '/n' off of the end from fgets
card newLineTrim(card cardToTrim)
{
	int newLineTrim;

	newLineTrim = strlen(cardToTrim.rank);
	newLineTrim--;
 	cardToTrim.rank[newLineTrim] = '\0';

	newLineTrim = strlen(cardToTrim.suit);
	newLineTrim--;
	cardToTrim.suit[newLineTrim] = '\0';

	return cardToTrim;
}

//Shuffles the deck
void deckShuffle(card *deck)
{
	int i = 0, randomCardPlace;
	card temp;

	srand(time(NULL));

	//Does the actual shuffling
	while(i < DECKSIZE)
	{
		randomCardPlace = rand() %(DECKSIZE - 1);
		
		temp = deck[i];
		deck[i] = deck[randomCardPlace];
		deck[randomCardPlace] = temp;

		i++;
	}

	return;
}

//Deals the cards
int deal(deck)
{
	int dealer = 0, playerScore, dealerScore, countPlayer = 0, countDealer = 0;
	card handDealer[12], handPlayer[12];

	//Deals the first 2 cards
	for(i = 0; i < 2; i++)
	{
		handPlayer[countPlayer] = deck[dealer];
		dealer++;
		countPlayer++;
	
		handDealer[countDealer] = deck[dealer];
		dealer++;
		countDealer++;
	}

	playerScore = playerTurn(deck, handPlayer, countPlayer, dealer);

	dealerScore = dealerTurn(deck, handDealer, countDealer, dealer);
}

//Does the player's turn
int playerTurn(card deck, card hand, int size, int dealer)
{
	printf("Your hand: %s %s and %s %s.\n", hand.rank[0], hand[0].suit, hand[1].rank, hand[1].suit)

	while(1)
	{
		if(hitOrStay() == s);
		{
			printf("\nNow the it's dealer's turn.\n");
	
			

			return score(hand, size);
		}
		else
		{
			hand[count] = deck[dealer];

			printf("Your next card is the %s %s.\n", hand[count].rank, hand[count].suit);
		
			count++;
			dealer++;

			if(bust() == 1)
				return 1;
		}
	}
}

//Hitting or staying
char hitOrStay(void)
{
	char hitOrStay;

	do
	{
		printf("Would you like to hit or stay? (h/s)\n");
		scanf("%c", &hitOrStay);
	} while (hitOrStay != h || hitOrStay != s);

	return hitOrStay;
}

//Dealer's turn
int playerTurn(card deck, card hand, int size, int dealer)
{
	

	return score(hand, size);
}

//Score calculator
int score(card hand, int size)
{

	return score;
}
