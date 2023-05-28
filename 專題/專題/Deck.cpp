#include "Deck.h"
int Deck::numOfCard = 0;
int Deck::numOfDeck = 0;
int Deck::numOfUsed = 0;
int Deck::numOfHand = 0;
void Deck::roundStart() {
	srand(time(NULL));
	for (int i = 0; i < numOfUsed; i++) {
		deck[numOfDeck] = used[i];
		numOfDeck++;
	}
	for (int i = 0; i < numOfDeck; i++) {
		int index = rand() % numOfDeck;
		Card temp = deck[i];
		deck[i] = deck[index];
		deck[index] = temp;
	}
	draw(5);
}
void Deck::roundOver() {
	for (int i = 0; i < numOfUsed; i++) {
		deck[numOfDeck] = used[i];
		numOfDeck++;
	}
	if (numOfDeck == numOfCard)
		cout << "¥dµP¼Æ¥¿½T" << endl; //test
	for (int i = 0; i < numOfCard; i++) {
		for (int j = i+1; j < numOfDeck-1; j++) {
			if (deck[i].getNum() > deck[j].getNum()) {
				Card temp = deck[i];
				deck[i] = deck[j];
				deck[j] = temp;
			}
		}
	}
}
void Deck::gameStart() {
	for (int i = 0; i < 9; i++) {
		if(i<4 && i>0)
			deck[i].setNum(1);
		if(i<8 && i>4)
			deck[i].setNum(2);
		if(i>8)
			deck[i].setNum(3);
	}
	numOfCard += 9;
	numOfDeck += 9;
}
void Deck::shuffle() {
	srand(time(NULL));
	for (int i = 0; i < numOfUsed; i++) {
		deck[numOfDeck] = used[i];
		numOfDeck++;
	}
	numOfUsed = 0;
	for (int i = 0; i < numOfDeck; i++) {
		int index = rand() % numOfDeck;
		Card temp = deck[i];
		deck[i] = deck[index];
		deck[index] = temp;
	}
}
void Deck::draw(int n) {
	for (int i = 0; i < n; i++) {
		if (numOfDeck == 0) {
			shuffle();
		}
		hand[numOfHand] = deck[numOfDeck - 1];
		deck[numOfDeck - 1] = {};
		numOfHand++;
		numOfDeck--;
	}
}
void Deck::addCard(Card& card) {
	deck[numOfDeck] = card;
	numOfDeck++;
}
