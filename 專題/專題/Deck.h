#ifndef Deck_h
#define Deck_h
#include "Card.h"
#include<ctime>
class Deck {
	static const int deckSize = 20;
	static int numOfCard;
	static int numOfDeck;
	static int numOfUsed;
	static int numOfHand;
private:
	Card deck[deckSize] = {};
	Card used[deckSize] = {};
	Card hand[10] = {};
public:
	void gameStart();
	void roundOver();
	void roundStart();
	void addCard(Card&);
	void shuffle();
	void draw(int);

};
#endif
