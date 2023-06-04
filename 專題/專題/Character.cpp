#include<iostream>
#include"Character.h"
using namespace std;
int Character::money = 0;
Character::Character() {
	setHP(0);
	setArmor(0);
	setEnergy(0);
}
Character::Character(int h,int a,int e) {
	setHP(h);
	setArmor(a);
	setEnergy(e);
}
int Character::getHP() {
	return hp;
}
int Character::getFullHP() {
	return fullHp;
}
int Character::getArmor() {
	return armor;
}
int Character::getMoney() {
	return money;
}
int Character::getEnergy() {
	return energy;
}
int Character::getFullEnergy(){
	return fullEnergy;
}
void Character::setHP(int h) {
	hp = h;
}
void Character::setArmor(int a) {
	armor = a;
}
void Character::setMoney(int m) {
	money = m;
}
void Character::setEnergy(int e) {
	energy = e;
}
void Character::setPlayer(Character x) {
	fullHp = x.getHP();
	setHP(x.getHP());
	fullEnergy = x.getEnergy();
}
void Character::setFullHP(int h) {
	fullHp = h;
}
void Character::setFullEnergy(int e) {
	fullEnergy = e;
}