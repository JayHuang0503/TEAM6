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
int Character::getArmor() {
	return armor;
}
int Character::getMoney() {
	return money;
}
int Character::getEnergy() {
	return energy;
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
void Character::endTurn() {

}
void Character::setPlayer(Character x) {
	setHP(x.getHP());
	setEnergy(x.getEnergy());
}