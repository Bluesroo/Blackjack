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
int deal(card *);
int playerTurn(card *, card *, int, int);
int dealerTurn(card *, card *, int);
void reshuffle(card *, int);
char hitOrStay(void);
int bust(card *);
int score(card *, int);
