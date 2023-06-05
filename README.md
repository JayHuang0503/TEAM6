# TEAM6
## 一、基本資料
* 系級班級：資工系 1B
* 組別號碼：第六組
* 成員資訊：`組長`黃詠傑、洪嘉宏、楊循凱
## 二、專題內容
### 專題名稱：RogueLike卡牌遊戲
> *Roguelike：<br>
> Roguelike是角色扮演遊戲的一個分支類型，過去它以一系列隨機生成關卡的地牢、回合制戰鬥、基於磁貼的圖像和角色永久死亡為特點。
> *維基百科*
### 專題介紹
選擇你想使用的角色來開始冒險，在隨機生成的地圖上決定你的冒險路線，透過擊敗路途上的敵人獲得金錢，並購買卡牌來逐步構成你的牌組，並用屬於你的牌組來擊敗BOSS完成冒險。
### 主要程式介紹
### startPrint
輸出開始畫面，比例採用16:5
```cpp
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
```
### chooseCharacter
選擇遊玩時使用的角色
```cpp
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
```
### printState
輸出角色當前的狀態，在選擇完角色後會顯示於遊戲畫面上方
```cpp
void printState(Character& player) {		
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
```
### printFight
輸出戰鬥時的畫面，包含敵人名字、血量、狀態和玩家該回合的能量
```cpp
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
```
### battle
遭遇敵人時將會以亂數決定敵人和敵人的生命力跟攻擊力，開始戰鬥後會處理玩家出牌後的效果並計算傷害
```cpp
void battle(Character& player, Deck& deck,Map& map) {		
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
```
### camp
輸出進入營地的畫面並處理玩家的選擇
```cpp
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
```
### shop
輸出進入商店的畫面並處理玩家的交易選項
```cpp
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
```
### chooseRoad
輸出地圖和圖形提示，處理玩家輸入的路線選擇並判斷抵達的位置為何
```cpp
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
```
### 程式規則及玩法
按下`Enter`開始遊戲後輸入角色編號來選擇角色，該角色會具備一組基礎牌組以便你開始遊戲。之後遊戲將隨機產生一張作為本局遊戲使用的地圖，地圖上分別有`&`代表敵人、`$`代表商店、`#`代表營地、`.`代表你的足跡，以及`!`代表最終BOSS。
* 當抵達`&`時將觸發與敵人的戰鬥，回合開始時會從你的牌組中抽出5張牌作為手牌並可以輸入卡牌編號打出此牌，當出牌所需的能量用完時輸入`0`來結束回合，之後輪到敵人發動攻擊對玩家造成傷害，結束後又回到玩家的回合，直到雙方中有一方死亡，戰鬥勝利時將獲得金錢。
* 當抵達`$`時可以花費所擁有的金錢購買新的卡牌擴充你的牌組或增加出牌時用的能量。
* 當抵達`#`時能選擇回復30%的生命值或增加最大生命值，以幫助玩家繼續完成遊戲。
* 在遊戲最後，抵達`!`時將會進入與BOSS的戰鬥，擊敗BOSS即代表完成遊戲。
### 程式執行畫面截圖
#### 開始畫面展示
![](https://github.com/JayHuang0503/TEAM6/raw/main/專題執行畫面/開始畫面.png)
#### 選擇角色畫面展示
![](https://github.com/JayHuang0503/TEAM6/raw/main/專題執行畫面/選擇角色.png)
#### 地圖及選擇路線畫面展示
![](https://github.com/JayHuang0503/TEAM6/raw/main/專題執行畫面/地圖.png)
#### 戰鬥畫面展示
![](https://github.com/JayHuang0503/TEAM6/raw/main/專題執行畫面/戰鬥.png)
#### 商店畫面展示
![](https://github.com/JayHuang0503/TEAM6/raw/main/專題執行畫面/商店.png)
#### 營地畫面展示
![](https://github.com/JayHuang0503/TEAM6/raw/main/專題執行畫面/營地.png)
## 三、分工資訊
| 姓名 | 負責部分 |
|---- | :----------: |
|**黃詠傑**|Card物件、Map物件、遊戲畫面輸出、main函式|
|**洪嘉宏**|Character物件|
|**楊循凱**|Enemy物件|
