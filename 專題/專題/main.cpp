#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<ctime>
#include<string>
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
			cout << '|' << "                 �d  �P  �_  �I                 |" << endl;
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
void battle() {

}
void camp() {

}
void shop(Character& player,Deck& deck) {
	Card card1, card2, card3,card4;
	card1.setNum(rand() % 15 + 3);
	card2.setNum(rand() % 15 + 3);
	card3.setNum(rand() % 15 + 3);
	card4.setNum(rand() % 15 + 3);
	int p1 = 5 + rand() % 15 + rand() % 20;
	int p2 = 5 + rand() % 15 + rand() % 20;
	int p3 = 5 + rand() % 15 + rand() % 20;
	int p4 = 5 + rand() % 15 + rand() % 20;
	bool ok = false;
	cout << "�ӫ~�C��:" << endl;
	cout << "1. " << "$" <<p1<< " " << card1.getName() << ":"; card1.getInfo();
	cout << "2. " << "$" <<p2 << " " << card2.getName() << ":"; card2.getInfo();
	cout << "3. " << "$" << p3<< " " << card3.getName() << ":"; card3.getInfo();
	cout << "4. " << "$" << p4<< " " <<card4.getName() << ":"; card4.getInfo();
	cout << "5. " << "$" << 50 << " " << "���a��q+1 " << endl;
	while (!ok) {
		cout << "��J�ӫ~�s�� �� ���U E ���}�ө�..." << endl;
		int input;
		cin >> input;
		if (input==1) {
			if (player.getMoney() - p1 >= 0) {
				cout << "�ʶR���\�A" << card1.getName() << "�w�[�J�P��" << endl;
				deck.addCard(card1);
				ok = true;
			}
			else {
				cout << "�ʶR���ѡA��������" << endl;
			}
		}
		else if (input == 2) {
			if (player.getMoney() - p2 >= 0) {
				cout << "�ʶR���\�A" << card1.getName() << "�w�[�J�P��" << endl;
				deck.addCard(card2);
				ok = true;
			}
			else {
				cout << "�ʶR���ѡA��������" << endl;
			}
		}
		else if (input == 3) {
			if (player.getMoney() - p3 >= 0) {
				cout << "�ʶR���\�A" << card1.getName() << "�w�[�J�P��" << endl;
				deck.addCard(card3);
				ok = true;
			}
			else {
				cout << "�ʶR���ѡA��������" << endl;
			}
		}
		else if (input == 4) {
			if (player.getMoney() - p4 >= 0) {
				cout << "�ʶR���\�A" << card1.getName() << "�w�[�J�P��" << endl;
				deck.addCard(card4);
				ok = true;
			}
			else {
				cout << "�ʶR���ѡA��������" << endl;
			}
		}
		else if (input == 5) {
			if (player.getMoney() - p2 >= 0) {
				cout << "�ʶR���\�A��q+1" << endl;
				player.setEnergy(player.getEnergy() + 1);
				ok = true;
			}
			else {
				cout << "�ʶR���ѡA��������" << endl;
			}
		}
	}
}
void chooseRoad(Map &map) {
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
		map.setPlayer(x, map.getMoveTimes());
	}	
}
int main() {
	srand(time(NULL));
	Character player; 
	Deck deck;
	Enemy slime("�v�ܩi", 20, 5, 15), bat("����", 15, 3, 12), wolfman("�T�H", 30, 7, 20);
	Map map;
	startPrint();
	cin.get(); // ���ݨϥΪ̫��U Enter ��
	chooseCharacter(player);
	map.creatMap();
	chooseRoad(map);
	chooseRoad(map);
	shop(player,deck);
}