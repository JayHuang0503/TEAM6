#include "Enemy.h"
#include <iostream>
#include<string>
using namespace std;
Enemy::Enemy(string n,int h, int d, int m) {
	name = n;
	setHp(h);
	setDamage(d);
	setMoney(m);
}
int Enemy::getDamage() {
	return damage;
}
void Enemy::setDamage(int d) {
	damage = d;
}
int Enemy::getHp() {
	return hp;
}
void Enemy::setHp(int h) {
	hp = h;
}
int Enemy::getMoney() {
	return money;
}
void Enemy::setMoney(int m) {
	money = m;
}
string Enemy::getName() {
	return name;
}
void Enemy::card(int infoOfCard[]) {
	if (infoOfCard[0] != 0) {
		this->hp -= (infoOfCard[0]+(this->weekround));
		cout << "你對 " << getName() << " 造成了 " << (infoOfCard[1] + (this->weekround)) << " 點傷害" << endl;
	}
	if (infoOfCard[3] != 0) {
		this->bleedround += infoOfCard[3];
		cout << getName() << "增加了" << infoOfCard[3] << "層「流血」" << endl;
	}
}
bool Enemy::isDead() {
	if (this->hp <= 0) {
		return true;
	}
	else {
		return false;
	}
}