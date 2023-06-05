#ifndef Enemy_h
#define Enemy_h
#include <iostream>
#include<string>
using namespace std;
class Enemy {
private:
	string name;
	int hp;
	int fullhp;
	int damage;
	int money;
	int bleedRound=0;
	int weakRound=0;
public:
	Enemy();
	Enemy(string,int,int,int);
	void setBleedRound(int);
	int getBleedRound();
	void setWeakRound(int);
	int getWeakRound();
	int getDamage();
	void setDamage(int);
	int getHp();
	void setHp(int h);
	int getFullHp();
	void setFullHp(int h);
	int getMoney();
	void setMoney(int);
	string getName();
	void setName(string);
	void setEnemy(Enemy&,int);
};
#endif