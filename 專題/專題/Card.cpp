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
void Card::getInfo() {		//�d�P�y�z
	int c = 0;
	if (getNum() != 18) {
		cout << "��q:" << getEnergy() << "�A";
	}
	if (getDamage() != 0) {
		cout << "�y��" << getDamage() << "�I�ˮ`";
		c += 1;
	}
	if (getArmor() != 0) {
		if (c > 0) {
			cout << " �� ";
		}
		cout << "��o" << getArmor() << "�I�@��";
		c += 1;
	}
	if (getWeakRound() != 0) {
		if (c > 0) {
			cout << " �� ";
		}
		cout << "�y��" << getWeakRound() << "�h�u��z�v";
		cout << endl << "\t\t  *��z:���쪺�ˮ`+1";
		c += 1;
	}
	if (getBleedRound() != 0) {
		if (c > 0) {
			cout << " �� ";
		}
		cout << "�y��" << getBleedRound() << "�h�u�y��v";
		cout << endl << "\t\t  *�y��:�^�X�����ͩR-2";
		c += 1;
	}
	if (getNum() == 4) {
		cout << "�y�����P��e�@�ҭȪ��ˮ`";
	}
	if (getNum() == 5) {
		cout << "�A��@�i�P";
	}
	if (getNum() == 7) {
		cout << "�A�b��P��ͦ����P���ƻs�P";
	}
	if (getNum() == 9) {
		cout << "���i�P";
	}
	if (getNum() == 10) {
		cout << "�@�ҭ�½��";
	}
	if (getNum() == 12) {
		cout << "�A�ͩR-5";
	}
	if (getNum() == 14) {
		cout << "5��";
	}
	if (getNum() == 15) {
		cout << "�A�ͩR-5";
	}
	if (getNum() == 16) {
		cout << "��_���P��ˮ`���ͩR";
	}
	if (getNum() == 17) {
		cout << "7��";
	}
	cout << endl;
}