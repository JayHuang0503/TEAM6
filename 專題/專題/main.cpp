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
			cout << '|' << "                 卡  牌  冒  險                 |" << endl;
		}
		else if (i == 10) {
			cout << '|' << "               按下 Enter 鍵繼續...             |" << endl;
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
			cout << '|' << "                    選擇角色:                   |" << endl;
		}
		else if (i == 6) {
			cout << '|' << "              1.戰士 生命:50 能量:3             |" << endl;
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
		cout << "選擇使用的角色:";
		cin >> choose;
		if (choose == 1) {
			player.setPlayer(warrior);
			cout << "你選擇了戰士" << endl;
			ok = true;
		}
		else {
			cout << "輸入無效，請重新輸入" << endl;
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
	cout << "商品列表:" << endl;
	cout << "1. " << "$" <<p1<< " " << card1.getName() << ":"; card1.getInfo();
	cout << "2. " << "$" <<p2 << " " << card2.getName() << ":"; card2.getInfo();
	cout << "3. " << "$" << p3<< " " << card3.getName() << ":"; card3.getInfo();
	cout << "4. " << "$" << p4<< " " <<card4.getName() << ":"; card4.getInfo();
	cout << "5. " << "$" << 50 << " " << "玩家能量+1 " << endl;
	while (!ok) {
		cout << "輸入商品編號 或 按下 E 離開商店..." << endl;
		int input;
		cin >> input;
		if (input==1) {
			if (player.getMoney() - p1 >= 0) {
				cout << "購買成功，" << card1.getName() << "已加入牌堆" << endl;
				deck.addCard(card1);
				ok = true;
			}
			else {
				cout << "購買失敗，金錢不足" << endl;
			}
		}
		else if (input == 2) {
			if (player.getMoney() - p2 >= 0) {
				cout << "購買成功，" << card1.getName() << "已加入牌堆" << endl;
				deck.addCard(card2);
				ok = true;
			}
			else {
				cout << "購買失敗，金錢不足" << endl;
			}
		}
		else if (input == 3) {
			if (player.getMoney() - p3 >= 0) {
				cout << "購買成功，" << card1.getName() << "已加入牌堆" << endl;
				deck.addCard(card3);
				ok = true;
			}
			else {
				cout << "購買失敗，金錢不足" << endl;
			}
		}
		else if (input == 4) {
			if (player.getMoney() - p4 >= 0) {
				cout << "購買成功，" << card1.getName() << "已加入牌堆" << endl;
				deck.addCard(card4);
				ok = true;
			}
			else {
				cout << "購買失敗，金錢不足" << endl;
			}
		}
		else if (input == 5) {
			if (player.getMoney() - p2 >= 0) {
				cout << "購買成功，能量+1" << endl;
				player.setEnergy(player.getEnergy() + 1);
				ok = true;
			}
			else {
				cout << "購買失敗，金錢不足" << endl;
			}
		}
	}
}
void chooseRoad(Map &map) {
	map.print();
	if (map.getMoveTimes() != 10) {
		int input=0,x=0;
		bool ok=false;
		cout << "選擇你的路線: ";
		while (!ok) {
			if (map.getPlayer() == 0) {
				if (map.getWay1(map.getMoveTimes()) == char(92)) {
					cout << "1.XXXX 2.往前 3.往下 " << endl;
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
						cout << "輸入無效，請重新輸入" << endl;
					}
				}
				else {
					cout << "1.XXXX 2.往前 3.XXXX " << endl;
					cin >> input;
					if (input == 2) {
						x = 0;
						ok = true;
					}
					else {
						cout << "輸入無效，請重新輸入" << endl;
					}
				}
			}
			else if (map.getPlayer() == 1) {
				if (map.getWay1(map.getMoveTimes()) == '/' && map.getWay2(map.getMoveTimes()) == char(92)) {
					cout << "1.往上 2.往前 3.往下" << endl;
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
						cout << "輸入無效，請重新輸入" << endl;
					}
				}
				else if (map.getWay1(map.getMoveTimes()) == '/' && map.getWay2(map.getMoveTimes()) == '/') {
					cout << "1.往上 2.往前 3.XXXX " << endl;
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
						cout << "輸入無效，請重新輸入" << endl;
					}
				}
				else if (map.getWay1(map.getMoveTimes()) == char(92) && map.getWay2(map.getMoveTimes()) == char(92)) {
					cout << "1.XXXX 2.往前 3.往下 " << endl;
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
						cout << "輸入無效，請重新輸入" << endl;
					}
				}
				else if (map.getWay1(map.getMoveTimes()) == char(92) && map.getWay2(map.getMoveTimes()) == '/') {
					cout << "1.XXXX 2.往前 3.XXXX " << endl;
					cin >> input;
					if (input == 2) {
						x = 1;
						ok = true;
					}
					else {
						cout << "輸入無效，請重新輸入" << endl;
					}
				}
			}
			else if (map.getPlayer() == 2) {
				if (map.getWay2(map.getMoveTimes()) == '/') {
					cout << "1.往上 2.往前 3.XXXX" << endl;
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
						cout << "輸入無效，請重新輸入" << endl;
					}
				}
				else {
					cout << "1..XXXX 2.往前 3.XXXX" << endl;
					cin >> input;
					if (input == 2) {
						x = 2;
						ok = true;
					}
					else {
						cout << "輸入無效，請重新輸入" << endl;
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
	Enemy slime("史萊姆", 20, 5, 15), bat("蝙蝠", 15, 3, 12), wolfman("狼人", 30, 7, 20);
	Map map;
	startPrint();
	cin.get(); // 等待使用者按下 Enter 鍵
	chooseCharacter(player);
	map.creatMap();
	chooseRoad(map);
	chooseRoad(map);
	shop(player,deck);
}