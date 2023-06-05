#include"Card.h"
Card::Card() {

}
void Card::useCard() {

}
void Card::setNum(int num) {
	this->num = num;
}
int Card::getNum() {
	return num;
}
string Card::getName() {
	return nameOfCard[num - 1];
}
int Card::getDamage() {
	return infoOfCard[num - 1][0];
}
int Card::getArmor() {
	return infoOfCard[num - 1][1];
}
int Card::getEnergy() {
	return infoOfCard[num - 1][2];
}
int Card::getBleedRound() {
	return infoOfCard[num - 1][3];
}
int Card::getWeakRound() {
	return infoOfCard[num-1][4];
}
void Card::getInfo() {		//卡牌描述
	int c = 0;
	if (getNum() != 18) {
		cout << "能量:" << getEnergy() << "，";
	}
	if (getDamage() != 0) {
		cout << "造成" << getDamage() << "點傷害";
		c += 1;
	}
	if (getArmor() != 0) {
		if (c > 0) {
			cout << " 並 ";
		}
		cout << "獲得" << getArmor() << "點護甲";
		c += 1;
	}
	if (getWeakRound() != 0) {
		if (c > 0) {
			cout << " 並 ";
		}
		cout << "造成" << getWeakRound() << "層「虛弱」";
		cout << endl << "\t\t  *虛弱:受到的傷害+1";
		c += 1;
	}
	if (getBleedRound() != 0) {
		if (c > 0) {
			cout << " 並 ";
		}
		cout << "造成" << getBleedRound() << "層「流血」";
		cout << endl << "\t\t  *流血:回合結束生命-2";
		c += 1;
	}
	if (getNum() == 4) {
		cout << "造成等同當前護甲值的傷害";
	}
	if (getNum() == 5) {
		cout << "，抽一張牌";
	}
	if (getNum() == 7) {
		cout << "，在棄牌堆生成此牌的複製牌";
	}
	if (getNum() == 9) {
		cout << "抽兩張牌";
	}
	if (getNum() == 10) {
		cout << "護甲值翻倍";
	}
	if (getNum() == 12) {
		cout << "，生命-5";
	}
	if (getNum() == 14) {
		cout << "5次";
	}
	if (getNum() == 15) {
		cout << "，生命-5";
	}
	if (getNum() == 16) {
		cout << "恢復等同於傷害的生命";
	}
	if (getNum() == 17) {
		cout << "7次";
	}
	cout << endl;
}