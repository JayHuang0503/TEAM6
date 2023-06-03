#include "Deck.h"
int Deck::numOfCard = 0;
int Deck::numOfDeck = 0;
int Deck::numOfUsed = 0;
int Deck::numOfHand = 0;
void Deck::roundStart() {
	draw(5);
}
void Deck::roundOver() {
	for (int i = 0; i < numOfHand; i++) {
		if (hand[i].getNum() != 18) {
			used[numOfUsed] = hand[i];
			numOfUsed++;
		}
		hand[i] = {};
	}
	numOfHand = 0;
}
void Deck::gameStart() {
	for (int i = 0; i < 9; i++) {
		if(i<4 && i>=0)
			deck[i].setNum(1);
		if(i<8 && i>=4)
			deck[i].setNum(2);
		if(i>=8)
			deck[i].setNum(3);
	}
	numOfCard += 9;
	numOfDeck += 9;
	srand(time(NULL));
	for (int i = 0; i < numOfDeck; i++) {
		int index = rand() % numOfDeck;
		Card temp = deck[i];
		deck[i] = deck[index];
		deck[index] = temp;
	}
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
		deck[numOfDeck - 1] = Card();
		numOfHand++;
		numOfDeck--;
	}
}
void Deck::addCard(Card& card) {
	deck[numOfDeck] = card;
	numOfDeck++;
}
int Deck::getNumOfHand() {
	return numOfHand;
}
void Deck::showHand() {
	for (int i = 0; i < numOfHand; i++) {
		cout <<"	"<< i + 1 << ". " << hand[i].getName() << "¡A";
		hand[i].getInfo();
	}
}
Card Deck::getHand(int n) {
	return hand[n];
}
void Deck::setUsed(Card& a) {
	used[numOfUsed] = a;
	numOfUsed++;
}
void Deck::setNumOfUsed(int n) {
	numOfUsed = n;
}
int Deck::getNumOfUsed() {
	return numOfUsed;
}
void Deck::setHand(int p,int n) {
	hand[p].setNum(n);
}