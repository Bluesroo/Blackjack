#Blackjack

This is a CLI blackjack game. It has a very simple dealer AI and only uses 1 deck. This is the second version of a
project that I did when I first started learning programming. This version was written after my first programming class.

##Files
###[blackjack.c](https://github.com/Bluesroo/Blackjack/blob/master/blackjack.c)
This is the main entry point for the game. It sets up the deck and shuffles it for the first play.
###[functions.c](https://github.com/Bluesroo/Blackjack/blob/master/functions.c)
This file contains the functions that govern the actual playing of the game. e.g. Dealing the cards, AI logic, making/
shuffling the deck, etc.
###[prototypes.h](https://github.com/Bluesroo/Blackjack/blob/master/prototypes.h)
Contains the defined values, defines the struct for the deck, and defines the functions that are used in the program.
###[rank](https://github.com/Bluesroo/Blackjack/blob/master/rank), [suit](https://github.com/Bluesroo/Blackjack/blob/master/suit), and [value](https://github.com/Bluesroo/Blackjack/blob/master/value)
These files are used for creating the deck at the beginning of the game.