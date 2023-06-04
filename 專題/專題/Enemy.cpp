#include "Enemy.h"
#include <iostream>
#include<string>
using namespace std;
Enemy::Enemy() {

}
Enemy::Enemy(string n,int h, int d, int m) {
	name = n;
	setHp(h);
	setDamage(d);
	setMoney(m);
}
void Enemy::setBleedRound(int br) {
	bleedround = br;
}
int Enemy::getBleedRound() {
	return bleedround;
}
void Enemy::setWeekRound(int wr) {
	weekround = wr;
}
int Enemy::getWeekRound() {
	return weekround;
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
int Enemy::getFullHp() {
	return fullhp;
}
void Enemy::setFullHp(int h) {
	fullhp = h;
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
void Enemy::setName(string n) {
	name = n;
}
void Enemy::setEnemy(Enemy& a,int mt) {
	int num = rand() % ((mt + 1) * 2);
	setName(a.getName());
	setHp(a.getHp()+num);
	setFullHp(a.getHp() + num);
	setDamage(a.getDamage());
	setMoney(a.getMoney() + num);
}