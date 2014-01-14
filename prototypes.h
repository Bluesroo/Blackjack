#define DECKSIZE 52
#define RANKSIZE 6
#define SUITSIZE 13

//Creates the card type
typedef struct
{
	int value;
	char suit[SUITSIZE];
	char rank[RANKSIZE];
} card;

//Prototypes
void deckMake(card *);
card newLineTrim(card);
void deckShuffle(card *);
