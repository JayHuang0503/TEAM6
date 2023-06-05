#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<ctime>
#include<string>
#include <conio.h>
#include<cstdlib>
#include"Map.h"
#include"Enemy.h"
#include"Deck.h"
#include"Character.h"
using namespace std;

void startPrint() {
	int times = 3;
	cout << '*';
	for (int i = 0; i < 16*times; i++) {
		cout << '-';
	}
	cout << '*' << endl;
	for (int i = 0; i < 5*times; i++) {
		if (i == 5) {
			cout << '|' << "             �d  �P  �_  �I  �C  ��             |" << endl;
		}
		else if (i == 10) {
			cout << '|' << "               ���U Enter ���~��...             |" << endl;
		}
		
		else {
			cout << '|' << "                                                |" << endl;
		}
	}
	cout << '*';
	for (int i = 0; i < 16*times; i++) {
		cout << '-';
	}
	cout << '*' << endl;
}
void chooseCharacter(Character& player) {
	Character warrior(50, 0, 3);
	bool ok = false;
	int choose = 0;
	int times = 3;
	cout << '*';
	for (int i = 0; i < 16 * times; i++) {
		cout << '-';
	}
	cout << '*' << endl;
	for (int i = 0; i < 5 * times; i++) {
		if (i == 3) {
			cout << '|' << "                    ��ܨ���:                   |" << endl;
		}
		else if (i == 6) {
			cout << '|' << "              1.�Ԥh �ͩR:50 ��q:3             |" << endl;
		}
		else if (i == 9) {
			cout << '|' << "                       2.                       |" << endl;
		}
		else {
			cout << '|' << "                                                |" << endl;
		}
	}
	cout << '*';
	for (int i = 0; i < 16 * times; i++) {
		cout << '-';
	}
	cout << '*' << endl;
	while (!ok) {
		cout << "��ܨϥΪ�����:";
		cin >> choose;
		if (choose == 1) {
			player.setPlayer(warrior);
			cout << "�A��ܤF�Ԥh" << endl;
			ok = true;
		}
		else {
			cout << "��J�L�ġA�Э��s��J" << endl;
		}
	}
}
void printState(Character& player) {		//���A�C��
	int times = 3;
	cout << '*';
	for (int i = 0; i < 16 * times; i++) {
		cout << '-';
	}
	cout << '*' << endl;
	cout << "|" << "�ͩR:" << setw(2) << player.getHP() << '/' << player.getFullHP();
	if (player.getArmor() > 0) {
		cout << "          �@��:" << setw(2) << player.getArmor();
	}
	else {
		cout << "                 "; 
	}
	cout << "             ����:" << setw(3) << player.getMoney() << "|" << endl;
}
void printFight(Enemy& monster, Character& player) {
	int times = 3;
	printState(player);
	cout << '*';
	for (int i = 0; i < 16 * times; i++) {
		cout << '-';
	}
	cout << '*' << endl;
	for (int i = 0; i < 5 * times; i++) {
		if (i == 6) {
			cout << "|                      " << monster.getName() << "                      |" << endl;
		}
		else if (i == 7) {
			cout << "|                     " << setw(2) << monster.getHp() << " /" << monster.getFullHp() << "                     |" << endl;
		}
		else if (i == 8) {
			cout << "|                    " << "�ˮ`:" << setw(2) << monster.getDamage() << "                     |" << endl;
		}
		else if (i == 9) {
			if (monster.getWeakRound() != 0) {
				cout << "|                  " << "��z:" << setw(2) << monster.getWeakRound() << "�^�X" << "                   |" << endl;
			}
			else {
				cout << "|";
				for (int j = 0; j < 16 * times; j++) {
					cout << " ";
				}
				cout << "|" << endl;
			}
		}
		else if (i == 10) {
			if (monster.getBleedRound() != 0) {
				cout << "|                  " << "�y��:" << setw(2) << monster.getBleedRound() << "�^�X" << "                   |" << endl;
			}
			else {
				cout << "|";
				for (int j = 0; j < 16 * times; j++) {
					cout << " ";
				}
				cout << "|" << endl;
			}
		}
		else if (i == 13) {
			cout << "*-------*                                        |" << endl;
		}
		else if (i == 14) {
			cout << "|" << "��q:" << setw(2) << player.getEnergy() << "|                                        |" << endl;
		}
		else {
			cout << "|";
			for (int j = 0; j < 16 * times; j++) {
				cout << " ";
			}
			cout << "|" << endl;
		}
	}
	cout << '*';
	for (int i = 0; i < 16 * times; i++) {
		if (i == 7) {
			cout << "*";
		}
		else {
			cout << '-';
		}
	}
	cout << '*' << endl;
}
void battle(Character& player, Deck& deck,Map& map) {		//�԰�
	Enemy slime("�L��", 15, 4, 10), bat("����", 10, 3, 8), wolfman("�T�H", 26, 8, 12), ghost("���F", 30, 5, 15), boss("�]��", 50, 10, 0);
	Enemy monster;
	int r = rand() % 4;
	if (r == 0) {
		monster.setEnemy(slime,map.getMoveTimes());
	}
	else if (r == 1) {
		monster.setEnemy(bat,map.getMoveTimes());
	}
	else if (r == 2) {
		monster.setEnemy(wolfman, map.getMoveTimes());
	}
	else if (r == 3) {
		monster.setEnemy(ghost, map.getMoveTimes());
	}
	if (map.getMoveTimes() == 10) {
		monster.setEnemy(boss, map.getMoveTimes());
	}
	while (monster.getHp() > 0) {
		bool ok = false;
		deck.roundStart();
		int input;
		int en = player.getFullEnergy();
		player.setEnergy(en);
		printFight(monster, player);
		do{
			cout << "��J�s�����X�d�P �� ��J0�����^�X..." << endl << endl;
			deck.showHand();
			cin >> input;
			Card temp = *new Card;
			if (input >= 1 && input <= deck.getNumOfHand()) {
				int newEn = en-deck.getHand(input - 1).getEnergy();
				if (newEn < 0) {
					cout << "��q����" << endl;
				}
				else {
					temp = deck.getHand(input - 1);
					en = newEn;
					player.setEnergy(en);
					if (temp.getDamage() != 0) {
						monster.setHp(monster.getHp() - (temp.getDamage()+monster.getWeakRound()));
					}
					if (temp.getArmor() != 0) {
						player.setArmor(temp.getArmor()+player.getArmor());
					}
					if (temp.getWeakRound() != 0) {
						monster.setWeakRound(temp.getWeakRound() + monster.getWeakRound());
					}
					if (temp.getBleedRound() != 0) {
						monster.setBleedRound(temp.getBleedRound() + monster.getBleedRound());
					}
					if (temp.getNum() == 4) {
						monster.setHp(monster.getHp()-player.getArmor());
					}
					if (temp.getNum() == 5) {
						deck.draw(1);
					}
					if (temp.getNum() == 7) {
						deck.setUsed(temp);
						deck.setNumOfUsed(deck.getNumOfUsed()+1);
					}
					if (temp.getNum() == 9) {
						deck.draw(2);
					}
					if (temp.getNum() == 10) {
						player.setArmor(player.getArmor() * 2);
					}
					if (temp.getNum() == 12) {
						player.setHP(player.getHP() - 5);
					}
					if (temp.getNum() == 14) {
						for (int i = 0; i < 4; i++) {
							monster.setHp(monster.getHp() - (temp.getDamage() + monster.getWeakRound()));
						}
					}
					if (temp.getNum() == 15) {
						player.setHP(player.getHP() - 5);
					}
					if (temp.getNum() == 16) {
						if (player.getHP() + temp.getDamage() + monster.getWeakRound() > player.getFullHP()) {
							player.setHP(player.getFullHP());
						}
						else {
							player.setHP(player.getHP()+temp.getDamage() + monster.getWeakRound());
						}
					}
					if (temp.getNum() == 17) {
						for (int i = 0; i < 6; i++) {
							monster.setHp(monster.getHp() - (temp.getDamage() + monster.getWeakRound()));
						}
					}
					deck.setUsed(temp);
					deck.setHand(input-1,18);
				}
				printFight(monster, player);
			}
			else if(input==0) {
				if (monster.getBleedRound()>0) {
					monster.setHp(monster.getHp() - 2);
					monster.setBleedRound(monster.getBleedRound() - 1);
				}
				if (monster.getWeakRound() > 0) {
					monster.setWeakRound(monster.getWeakRound() - 1);
				}
				cout << "�����^�X" << endl;
				ok = true;
				break;
			}
			else {
				cout << "��J�L�ġA�Э��s��J" << endl;
			}
		} while (!ok&& monster.getHp()>0);
		if (monster.getHp() > 0) {
			if (player.getArmor() > 0) {
				if (monster.getDamage() - player.getArmor() > 0) {
					int newDamage = monster.getDamage() - player.getArmor();
					player.setArmor(0);
					player.setHP(player.getHP() - newDamage);
				}
				else if (player.getArmor() - monster.getDamage() >= 0) {
					int newArmor = player.getArmor() - monster.getDamage();
					player.setArmor(newArmor);
				}
			}
			else {
				player.setHP(player.getHP() - monster.getDamage());
			}
			cout << monster.getName() << "��A�y���F " << monster.getDamage() << " �I�ˮ`" << endl;
		}
		if (player.getHP() <= 0) {
			cout << "~~~~~~~~~~~~~~~~~~~~~�C������~~~~~~~~~~~~~~~~~~~~~" << endl;
			cout << "		�A�Q " << monster.getName() << " �����F" << endl;
			exit(0);
		}
		deck.roundOver();
	}
	player.setMoney(player.getMoney() + monster.getMoney());
	cout <<endl<< "~~~~~~~~~~~~~~~~~~~~~�԰��ӧQ~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "\t    �A���ѤF " << monster.getName() << " ����o�F $" << monster.getMoney() << endl << endl;
}
void camp(Character& player) {
	cout <<endl<< "~~~~~~~~~~~~~~~~~~~�A��F�F��a~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "��e�ͩR:" << setw(2) << player.getHP() << '/' << player.getFullHP() << endl << endl;
	cout << "������G���Y�د��_���O�q:" << endl <<endl;
	int a, b;
	char input;
	bool ok=false;
	a = player.getFullHP() * 0.3 + player.getHP();
	if (a > player.getFullHP()) {
		a = player.getFullHP();
	}
	b = player.getFullHP() + 8;
	cout << "  1. " << "�^�_30%�ͩR�� -> " << a << '/' << player.getFullHP() << endl << endl;
	cout << "  2. " << "�̤j�ͩR��+8 -> " << player.getHP()+8 << '/' << b << endl << endl;
	cout << "��J�A�����..." << endl;
	while (!ok) {
		cin >> input;
		if (input == '1') {
			player.setHP(a);
			ok = true;
		}
		else if (input == '2') {
			player.setHP(player.getHP() + 8);
			player.setFullHP(b);
			ok = true;
		}
		else {
			cout << "��J�L�ġA�Э��s��J" << endl;
		}
	}
	cout << "~~~~~~~~~~~~~~~~~~~�A���}�F��a~~~~~~~~~~~~~~~~~~~" << endl;
}
void shop(Character& player,Deck& deck) {
	Card card1, card2, card3,card4;
	card1.setNum(rand() % 15 + 3);
	card2.setNum(rand() % 15 + 3);
	card3.setNum(rand() % 15 + 3);
	card4.setNum(rand() % 15 + 3);
	int p1 = 5 + rand() % 10 + rand() % 20;
	int p2 = 5 + rand() % 10 + rand() % 20;
	int p3 = 5 + rand() % 10 + rand() % 20;
	int p4 = 5 + rand() % 10 + rand() % 20;
	cout << "~~~~~~~~~~~~~~~~~~~�w��Ө�ө�~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "�A������$:" << player.getMoney() << endl << endl;
	cout << "�ӫ~�C��:" << endl << endl;
	cout << "  1. " << "$" << setw(2) <<p1<< " " << card1.getName() << ":"; card1.getInfo();
	cout << "  2. " << "$" <<setw(2) << p2 << " " << card2.getName() << ":"; card2.getInfo();
	cout << "  3. " << "$" << setw(2) << p3<< " " << card3.getName() << ":"; card3.getInfo();
	cout << "  4. " << "$" << setw(2) << p4<< " " <<card4.getName() << ":"; card4.getInfo();
	cout << "  5. " << "$" << setw(2) << 50 << " " << "���a��q+1 " << endl << endl;
	cout << "��J�ӫ~�s���ʶR �� ��JE���}�ө�..." << endl;
	while (true) {
		char input;
		cin >> input;
		if (input=='1') {
			if (player.getMoney() - p1 >= 0) {
				cout << "�ʶR���\�A" << card1.getName() << "�w�[�J�P��" << endl;
				player.setMoney(player.getMoney() - p1);
				cout << "�Ѿl����$:" << player.getMoney() << endl;
				deck.addCard(card1);
			}
			else {
				cout << "�ʶR���ѡA��������" << endl;
			}
		}
		else if (input == '2') {
			if (player.getMoney() - p2 >= 0) {
				cout << "�ʶR���\�A" << card2.getName() << "�w�[�J�P��" << endl;
				player.setMoney(player.getMoney() - p2);
				cout << "�Ѿl����$:" << player.getMoney() << endl;
				deck.addCard(card2);
			}
			else {
				cout << "�ʶR���ѡA��������" << endl;
			}
		}
		else if (input == '3') {
			if (player.getMoney() - p3 >= 0) {
				cout << "�ʶR���\�A" << card3.getName() << "�w�[�J�P��" << endl;
				player.setMoney(player.getMoney() - p3);
				cout << "�Ѿl����$:" << player.getMoney() << endl;
				deck.addCard(card3);
			}
			else {
				cout << "�ʶR���ѡA��������" << endl;
			}
		}
		else if (input == '4') {
			if (player.getMoney() - p4 >= 0) {
				cout << "�ʶR���\�A" << card4.getName() << "�w�[�J�P��" << endl;
				player.setMoney(player.getMoney() - p4);
				cout << "�Ѿl����$:" << player.getMoney() << endl;
				deck.addCard(card4);
			}
			else {
				cout << "�ʶR���ѡA��������" << endl;
			}
		}
		else if (input == '5') {
			if (player.getMoney() - p2 >= 0) {
				cout << "�ʶR���\�A��q+1" << endl;
				player.setMoney(player.getMoney() - 50);
				cout << "�Ѿl����$:" << player.getMoney() << endl;
				player.setFullEnergy(player.getFullEnergy() + 1);
			}
			else {
				cout << "�ʶR���ѡA��������" << endl;
			}
		}
		else if (input == 'e' || input=='H') {
			cout << "~~~~~~~~~~~~~~~~~~~�w��A�����{~~~~~~~~~~~~~~~~~~~" << endl;
			break;
		}
		else {
			cout << "��J�L�ġA�Э��s��J" << endl;
		}
	}
}
void chooseRoad(Map &map,Character& player,Deck& deck) {
	printState(player);
	map.print();
	if (map.getMoveTimes() != 10) {
		int input=0,x=0;
		bool ok=false;
		cout << "��ܧA�����u: ";
		while (!ok) {
			if (map.getPlayer() == 0) {
				if (map.getWay1(map.getMoveTimes()) == char(92)) {
					cout << "1.XXXX 2.���e 3.���U " << endl;
					cin >> input;
					if (input == 2) {
						x = 0;
						ok = true;
					}
					else if (input == 3) {
						x = 1;
						ok = true;
					}
					else {
						cout << "��J�L�ġA�Э��s��J" << endl;
					}
				}
				else {
					cout << "1.XXXX 2.���e 3.XXXX " << endl;
					cin >> input;
					if (input == 2) {
						x = 0;
						ok = true;
					}
					else {
						cout << "��J�L�ġA�Э��s��J" << endl;
					}
				}
			}
			else if (map.getPlayer() == 1) {
				if (map.getWay1(map.getMoveTimes()) == '/' && map.getWay2(map.getMoveTimes()) == char(92)) {
					cout << "1.���W 2.���e 3.���U" << endl;
					cin >> input;
					if (input == 1) {
						x = 0;
						ok = true;
					}
					else if (input == 2) {
						x = 1;
						ok = true;
					}
					else if (input == 3) {
						x = 2;
						ok = true;
					}
					else {
						cout << "��J�L�ġA�Э��s��J" << endl;
					}
				}
				else if (map.getWay1(map.getMoveTimes()) == '/' && map.getWay2(map.getMoveTimes()) == '/') {
					cout << "1.���W 2.���e 3.XXXX " << endl;
					cin >> input;
					if (input == 1) {
						x = 0;
						ok = true;
					}
					else if (input == 2) {
						x = 1;
						ok = true;
					}
					else {
						cout << "��J�L�ġA�Э��s��J" << endl;
					}
				}
				else if (map.getWay1(map.getMoveTimes()) == char(92) && map.getWay2(map.getMoveTimes()) == char(92)) {
					cout << "1.XXXX 2.���e 3.���U " << endl;
					cin >> input;
					if (input == 2) {
						x = 1;
						ok = true;
					}
					else if (input == 3) {
						x = 2;
						ok = true;
					}
					else {
						cout << "��J�L�ġA�Э��s��J" << endl;
					}
				}
				else if (map.getWay1(map.getMoveTimes()) == char(92) && map.getWay2(map.getMoveTimes()) == '/') {
					cout << "1.XXXX 2.���e 3.XXXX " << endl;
					cin >> input;
					if (input == 2) {
						x = 1;
						ok = true;
					}
					else {
						cout << "��J�L�ġA�Э��s��J" << endl;
					}
				}
			}
			else if (map.getPlayer() == 2) {
				if (map.getWay2(map.getMoveTimes()) == '/') {
					cout << "1.���W 2.���e 3.XXXX" << endl;
					cin >> input;
					if (input == 1) {
						x = 1;
						ok = true;
					}
					else if (input == 2) {
						x = 2;
						ok = true;
					}
					else {
						cout << "��J�L�ġA�Э��s��J" << endl;
					}
				}
				else {
					cout << "1..XXXX 2.���e 3.XXXX" << endl;
					cin >> input;
					if (input == 2) {
						x = 2;
						ok = true;
					}
					else {
						cout << "��J�L�ġA�Э��s��J" << endl;
					}
				}
			}
		}
		if (map.getRoad(x, map.getMoveTimes()) == '&') {
			battle(player, deck, map);
		//	cout << "����" << endl;
		}
		else if (map.getRoad(x, map.getMoveTimes()) == '$') {
			shop(player, deck);
		//	cout << "�ө�" << endl;
		}
		else if (map.getRoad(x, map.getMoveTimes()) == '#') {
			camp(player);
		//	cout << "��a" << endl;
		}
		//cout << x << ',' << map.getMoveTimes() << endl;
		map.setRoad(x, map.getMoveTimes(), 7);
		map.setPlayer(x, map.getMoveTimes());
	}
	else {
		cout << "�A�@���W�ܯ�ٴƲש��F�F�]�����Ҧb�a..." << endl;
		battle(player, deck, map);
		cout << "~~~~~~~~~~~~~~~~~�P�¹C�����C���I~~~~~~~~~~~~~~~~~";
	}
}
int main() {
	srand(time(NULL));
	Character player; 
	Deck deck;
	
	Map map;
	startPrint();
	cin.get(); // ���ݨϥΪ̫��U Enter ��
	chooseCharacter(player);
	deck.gameStart();
	map.creatMap();
	while (map.getMoveTimes() <= 11) {
		chooseRoad(map, player, deck);
	}
}