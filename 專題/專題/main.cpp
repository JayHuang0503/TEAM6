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
			cout << '|' << "             卡  牌  冒  險  遊  戲             |" << endl;
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
void printState(Character& player) {		//狀態列表
	int times = 3;
	cout << '*';
	for (int i = 0; i < 16 * times; i++) {
		cout << '-';
	}
	cout << '*' << endl;
	cout << "|" << "生命:" << setw(2) << player.getHP() << '/' << player.getFullHP();
	if (player.getArmor() > 0) {
		cout << "          護甲:" << setw(2) << player.getArmor();
	}
	else {
		cout << "                 "; 
	}
	cout << "             金錢:" << setw(3) << player.getMoney() << "|" << endl;
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
			cout << "|                    " << "傷害:" << setw(2) << monster.getDamage() << "                     |" << endl;
		}
		else if (i == 9) {
			if (monster.getWeakRound() != 0) {
				cout << "|                  " << "虛弱:" << setw(2) << monster.getWeakRound() << "回合" << "                   |" << endl;
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
				cout << "|                  " << "流血:" << setw(2) << monster.getBleedRound() << "回合" << "                   |" << endl;
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
			cout << "|" << "能量:" << setw(2) << player.getEnergy() << "|                                        |" << endl;
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
void battle(Character& player, Deck& deck,Map& map) {		//戰鬥
	Enemy slime("殭屍", 15, 4, 10), bat("蝙蝠", 10, 3, 8), wolfman("狼人", 26, 8, 12), ghost("幽靈", 30, 5, 15), boss("魔王", 50, 10, 0);
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
			cout << "輸入編號打出卡牌 或 輸入0結束回合..." << endl << endl;
			deck.showHand();
			cin >> input;
			Card temp = *new Card;
			if (input >= 1 && input <= deck.getNumOfHand()) {
				int newEn = en-deck.getHand(input - 1).getEnergy();
				if (newEn < 0) {
					cout << "能量不足" << endl;
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
				cout << "結束回合" << endl;
				ok = true;
				break;
			}
			else {
				cout << "輸入無效，請重新輸入" << endl;
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
			cout << monster.getName() << "對你造成了 " << monster.getDamage() << " 點傷害" << endl;
		}
		if (player.getHP() <= 0) {
			cout << "~~~~~~~~~~~~~~~~~~~~~遊戲結束~~~~~~~~~~~~~~~~~~~~~" << endl;
			cout << "		你被 " << monster.getName() << " 消滅了" << endl;
			exit(0);
		}
		deck.roundOver();
	}
	player.setMoney(player.getMoney() + monster.getMoney());
	cout <<endl<< "~~~~~~~~~~~~~~~~~~~~~戰鬥勝利~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "\t    你擊敗了 " << monster.getName() << " 並獲得了 $" << monster.getMoney() << endl << endl;
}
void camp(Character& player) {
	cout <<endl<< "~~~~~~~~~~~~~~~~~~~你抵達了營地~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "當前生命:" << setw(2) << player.getHP() << '/' << player.getFullHP() << endl << endl;
	cout << "營火似乎有某種神奇的力量:" << endl <<endl;
	int a, b;
	char input;
	bool ok=false;
	a = player.getFullHP() * 0.3 + player.getHP();
	if (a > player.getFullHP()) {
		a = player.getFullHP();
	}
	b = player.getFullHP() + 8;
	cout << "  1. " << "回復30%生命值 -> " << a << '/' << player.getFullHP() << endl << endl;
	cout << "  2. " << "最大生命值+8 -> " << player.getHP()+8 << '/' << b << endl << endl;
	cout << "輸入你的選擇..." << endl;
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
			cout << "輸入無效，請重新輸入" << endl;
		}
	}
	cout << "~~~~~~~~~~~~~~~~~~~你離開了營地~~~~~~~~~~~~~~~~~~~" << endl;
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
	cout << "~~~~~~~~~~~~~~~~~~~歡迎來到商店~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "你的金錢$:" << player.getMoney() << endl << endl;
	cout << "商品列表:" << endl << endl;
	cout << "  1. " << "$" << setw(2) <<p1<< " " << card1.getName() << ":"; card1.getInfo();
	cout << "  2. " << "$" <<setw(2) << p2 << " " << card2.getName() << ":"; card2.getInfo();
	cout << "  3. " << "$" << setw(2) << p3<< " " << card3.getName() << ":"; card3.getInfo();
	cout << "  4. " << "$" << setw(2) << p4<< " " <<card4.getName() << ":"; card4.getInfo();
	cout << "  5. " << "$" << setw(2) << 50 << " " << "玩家能量+1 " << endl << endl;
	cout << "輸入商品編號購買 或 輸入E離開商店..." << endl;
	while (true) {
		char input;
		cin >> input;
		if (input=='1') {
			if (player.getMoney() - p1 >= 0) {
				cout << "購買成功，" << card1.getName() << "已加入牌堆" << endl;
				player.setMoney(player.getMoney() - p1);
				cout << "剩餘金錢$:" << player.getMoney() << endl;
				deck.addCard(card1);
			}
			else {
				cout << "購買失敗，金錢不足" << endl;
			}
		}
		else if (input == '2') {
			if (player.getMoney() - p2 >= 0) {
				cout << "購買成功，" << card2.getName() << "已加入牌堆" << endl;
				player.setMoney(player.getMoney() - p2);
				cout << "剩餘金錢$:" << player.getMoney() << endl;
				deck.addCard(card2);
			}
			else {
				cout << "購買失敗，金錢不足" << endl;
			}
		}
		else if (input == '3') {
			if (player.getMoney() - p3 >= 0) {
				cout << "購買成功，" << card3.getName() << "已加入牌堆" << endl;
				player.setMoney(player.getMoney() - p3);
				cout << "剩餘金錢$:" << player.getMoney() << endl;
				deck.addCard(card3);
			}
			else {
				cout << "購買失敗，金錢不足" << endl;
			}
		}
		else if (input == '4') {
			if (player.getMoney() - p4 >= 0) {
				cout << "購買成功，" << card4.getName() << "已加入牌堆" << endl;
				player.setMoney(player.getMoney() - p4);
				cout << "剩餘金錢$:" << player.getMoney() << endl;
				deck.addCard(card4);
			}
			else {
				cout << "購買失敗，金錢不足" << endl;
			}
		}
		else if (input == '5') {
			if (player.getMoney() - p2 >= 0) {
				cout << "購買成功，能量+1" << endl;
				player.setMoney(player.getMoney() - 50);
				cout << "剩餘金錢$:" << player.getMoney() << endl;
				player.setFullEnergy(player.getFullEnergy() + 1);
			}
			else {
				cout << "購買失敗，金錢不足" << endl;
			}
		}
		else if (input == 'e' || input=='H') {
			cout << "~~~~~~~~~~~~~~~~~~~歡迎再次光臨~~~~~~~~~~~~~~~~~~~" << endl;
			break;
		}
		else {
			cout << "輸入無效，請重新輸入" << endl;
		}
	}
}
void chooseRoad(Map &map,Character& player,Deck& deck) {
	printState(player);
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
		if (map.getRoad(x, map.getMoveTimes()) == '&') {
			battle(player, deck, map);
		//	cout << "打怪" << endl;
		}
		else if (map.getRoad(x, map.getMoveTimes()) == '$') {
			shop(player, deck);
		//	cout << "商店" << endl;
		}
		else if (map.getRoad(x, map.getMoveTimes()) == '#') {
			camp(player);
		//	cout << "營地" << endl;
		}
		//cout << x << ',' << map.getMoveTimes() << endl;
		map.setRoad(x, map.getMoveTimes(), 7);
		map.setPlayer(x, map.getMoveTimes());
	}
	else {
		cout << "你一路上披荊斬棘終於抵達了魔王的所在地..." << endl;
		battle(player, deck, map);
		cout << "~~~~~~~~~~~~~~~~~感謝遊玩此遊戲！~~~~~~~~~~~~~~~~~";
	}
}
int main() {
	srand(time(NULL));
	Character player; 
	Deck deck;
	
	Map map;
	startPrint();
	cin.get(); // 等待使用者按下 Enter 鍵
	chooseCharacter(player);
	deck.gameStart();
	map.creatMap();
	while (map.getMoveTimes() <= 11) {
		chooseRoad(map, player, deck);
	}
}