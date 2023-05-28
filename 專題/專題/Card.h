#ifndef Card_h
#define Card_h
#include<string>
#include<iostream>
using namespace std;
class Card{
private:
	int num =0;
	int cardQuantity = 17;
	string nameOfCard[17] = { "¥´À»","¨¾¿m","¬åÀ»","¬ÞÀ»","³Æ¾Ô",
								"­«®±","¼««ã","¼A±Ù","¾Ô§q","¾d©T",
								"ªZ¸Ë","«÷©R","Ãº±ñ","¬ð¨ë","¦åñZ",
								"¶Ý¦å","¨gÀ»" };
	//int allOfCard[17] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17 };
	int infoOfCard[17][5] ={{3,0,1,0,0},{0,2,1,0,0},{4,0,2,2,0},{0,0,1,0,0},{0,2,1,0,0},
							{4,0,2,0,2},{2,0,0,0,0},{8,0,3,3,0},{0,0,1,0,0},{0,0,2,0,0},
							{0,2,1,0,0},{10,0,1,0,0},{0,0,1,0,3},{1,0,2,0,0},{0,12,1,0,0},
							{6,0,2,0,0},{2,0,3,0,0} };

public:
	Card();
	void useCard();
	void setNum(int);
	int getNum();
	string getName();
	int getDamage();
	int getArmor();
	int getEnergy();
	int getBleedRound();
	int getWeekRound();
	void getInfo();
};
#endif
