#ifndef Enemy_h
#define Enemy_h
#include <iostream>
#include<string>
using namespace std;
class Enemy {
private:
	string name;
	int hp;
	int damage;
	int money;
	int bleedround=0;
	int weekround=0;
public:
	Enemy(string,int,int,int);
	int getDamage();
	void setDamage(int);
	int getHp();
	void setHp(int h);
	int getMoney();
	void setMoney(int);
	void card(int[]);
	string getName();
	bool isDead();
};
#endif