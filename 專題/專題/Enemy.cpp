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
		cout << "�A�� " << getName() << " �y���F " << (infoOfCard[1] + (this->weekround)) << " �I�ˮ`" << endl;
	}
	if (infoOfCard[3] != 0) {
		this->bleedround += infoOfCard[3];
		cout << getName() << "�W�[�F" << infoOfCard[3] << "�h�u�y��v" << endl;
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