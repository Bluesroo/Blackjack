#define DECKSIZE 52
#define RANKSIZE 6
#define SUITSIZE 13

//Creates the CARD type
typedef struct
{
	int value;
	char suit[SUITSIZE];
	char rank[RANKSIZE];
} CARD;

//Prototypes
void deckMake(CARD *);
CARD newLineTrim(CARD);
void deckShuffle(CARD *);
int deal(CARD *, int *);
int playerTurn(CARD *, CARD *, int, int *);
int dealerTurn(CARD *, CARD *, int, int *);
void reshuffle(CARD *, int);
char hitOrStay(void);
int score(CARD *, int);
char rematch(int, int);
