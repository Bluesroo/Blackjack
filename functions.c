#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "prototypes.h"

//Generates the deck
void deckMake(CARD *deck)
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
		fscanf(rankFile, "%s", rank[i]);
		fscanf(valueFile, "%d", &value[i]);
	}

	//Fills the suit array with the different suits	
	for(i = 0; i < 4; i++)
		fgets(suit[i], SUITSIZE, suitFile);

	fclose(valueFile);
	fclose(rankFile);
	fclose(suitFile);

	//Does the actual deck generation
	for(i = 0, j = 0, k = 0; i < DECKSIZE; i++, j++)
	{
		if(i % 13 == 0)
			j = 0;
		
		strcpy(deck[i].rank, rank[j]);
		strcpy(deck[i].suit, suit[k]);
		deck[i].value = value[j];

		if((i + 1) % 13 == 0)
			k++;
		
		//Trims the '\n' from fgets
		deck[i] = newLineTrim(deck[i]);
	}

	return;
}

//Takes the '/n' off of the end from fgets
CARD newLineTrim(CARD cardToTrim)
{
	int newLineTrim;

	newLineTrim = strlen(cardToTrim.suit);
	newLineTrim--;
	cardToTrim.suit[newLineTrim] = '\0';

	return cardToTrim;
}

//Shuffles the deck
void deckShuffle(CARD *deck)
{
	int i = 0, randomCardPlace;
	CARD temp;

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

//Deals the CARDs
int deal(CARD *deck, int *dealer)
{
	int  playerScore, dealerScore, countPlayer = 0, countDealer = 0, again, i;
	CARD handDealer[12], handPlayer[12];

	//Deals the first 2 CARDs
	for(i = 0; i < 2; i++)
	{
		handPlayer[i] = deck[*dealer];

		*dealer += 1;
		countPlayer++;

		handDealer[i] = deck[*dealer];
			
		*dealer += 1;
		countDealer++;
	}

	printf("\nThe dealer's face up card: %s %s.\n", handDealer[1].rank, handDealer[1].suit);
	
	//Player's turn
	playerScore = playerTurn(deck, handPlayer, countPlayer, dealer);
	
	if(playerScore > 21)
	{
		dealerScore = score(handDealer, countDealer);

		return rematch(playerScore, dealerScore);
	}
	//Dealer's turn
	else
		dealerScore = dealerTurn(deck, handDealer, countDealer, dealer);
	
	return rematch(playerScore, dealerScore);
}

//Deals with the player's turn
int playerTurn(CARD *deck, CARD *hand, int size, int *dealer)
{
	int playerScore;

	printf("Your hand: %s %s and %s %s.\n", hand[0].rank, hand[0].suit, hand[1].rank, hand[1].suit);

	while(1)
	{
		if(hitOrStay() == 's')
		{
			printf("\nNow the it's the dealer's turn.\n");
			
			return score(hand, size);
		}
		else
		{
			hand[size] = deck[*dealer];

			printf("Your next card is the %s %s.\n", hand[size].rank, hand[size].suit);
		
			size++;
			*dealer++;
		}

		playerScore = score(hand, size);

		//If there is a bust
		if(playerScore > 21)
			return playerScore;
	}
}

//Dealer's turn
int dealerTurn(CARD *deck, CARD *hand, int size, int *dealer)
{
	int dealerScore;
	
	dealerScore = score(hand, size);
	
	while(dealerScore < 17)
	{
		hand[size] = deck[*dealer];
		
		*dealer++;
		size++;

		dealerScore = score(hand, size);
	}

	return dealerScore;
}

//Hitting or staying
char hitOrStay(void)
{
	char hitOrStay;

	do
	{
		printf("Would you like to hit or stay? (h/s)\n");
		scanf("%c", &hitOrStay);
	} while (hitOrStay != 'h' && hitOrStay != 's');

	return hitOrStay;
}

//Score calculator
int score(CARD *hand, int size)
{
	int i, score = 0, aceCount = 0;

	for(i = 0; i < size; i++)
	{
		score = score + hand[i].value;
		if(hand[i].value == 11)
			aceCount++;
	}

	while(score > 21 && aceCount > 0)
	{
		score -= 10;
		aceCount--;
	}

	return score;
}

//Shows the final score for the hand and asks for a rematch
char rematch(int playerScore, int dealerScore)
{
	char again;
	
	if(playerScore > 21)
		printf("You bust with %d!\n", playerScore);
	else if(playerScore == 21)
		printf("You got a Blackjack!\n");
	else
		printf("Your hand total was %d.\n", playerScore);

	if(dealerScore > 21)
		printf("The dealer bust with %d!\n", dealerScore);
	else if(playerScore == 21)
		printf("The got a Blackjack!\n");
	else
		printf("The dealer's hand total was %d.\n", dealerScore);	

	printf("Would you like to play again? (y/n)\n");

	do
	{
		scanf("%c", &again);
	} while (again != 'y' && again != 'n');

	return again;
}
