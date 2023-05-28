#include"Map.h"
int Map::moveTimes = 0;
void Map::creatMap() {
	srand(time(NULL));
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 10; j++) {
			if (j != 0)
				setRoad(i, j, rand()%7);
			else
				setRoad(i, j, 0);
		}
	}
	for (int i = 1; i < 10; i++) {
		if (rand() % 2 == 0) {
			way1[i] = up;
		}
		else {
			way1[i] = down;
		}
	}
	for (int i = 1; i < 10; i++) {
		if (rand() % 2 == 0) {
			way2[i] = up;
		}
		else {
			way2[i] = down;
		}
	}
}
void Map::setRoad(int i,int j, int event) {
	if (event < 4) {
		road[i][j] = monster;
	}
	else if (event == 4 ) {
		road[i][j] = camp;
	}
	else if (event > 4) {
		road[i][j] = shop;
	}
}
void Map::print() { //輸出地圖
	int times = 3;
	cout << '*';
	for (int i = 0; i < 16 * times; i++) {
		cout << '-';
	}
	cout << '*' << endl;
	for (int i = 0; i < 5 * times; i++) {
		if (i == 0) {
			cout << '|' << player << ':' << "你的位置"<< "                                      |" << endl;
		}
		if (i == 1) {
			cout << '|' << monster << ':' << "敵人" << "                                          |" << endl;
		}
		if (i == 2) {
			cout << '|' <<camp <<  ":休息              本局地圖:                   |" << endl;
		}
		if (i == 3) {
			cout << '|' << shop << ':' << "商店" << "                                          |" << endl;
		}
		if (i == 4) {
			cout << '|' << boss << ':' << "BOSS" << "                                          |" << endl;
		}
		else if (i == 6) {
			for (int i = 0; i < 28; i++) {
				if (i == 0 ) {
					cout << "|          *";
				}
				else if (i == 27) {
					cout << "*          |";
				}
				else {
					cout << '-';
				}
			}
			cout << endl;
			for (int i = 0; i < 10; i++) {
				if (i == 0) {
					cout << "|          |   ";
				}
				else {
					cout << '-';
				}
				cout << road[0][i];
			}
			cout << "    |          |" << endl;
			for (int i = 0; i < 10; i++) {
				if (i == 0) {
					cout << "|          |  /";
				}
				else {
					cout << " " << way1[i];
				}
			}
			cout << " " << char(92) << "   |          |" << endl;
			for (int i = 0; i < 10; i++) {
				if (i == 0) {
					cout << "|          | .-";
				}
				else {
					cout << '-';
				}
				cout << road[1][i];
			}
			cout << "-" << boss << "  |          |" << endl;
			for (int i = 0; i < 10; i++) {
				if (i == 0) {
					cout << "|          |  " << down;
				}
				else {
					cout << " " << way2[i];
				}
			}
			cout << " /   |          |" << endl;
			for (int i = 0; i < 10; i++) {
				if (i == 0) {
					cout << "|          |   ";
				}
				else {
					cout << '-';
				}
				cout << road[2][i];
			}
			cout << "    |          |" << endl;
			for (int i = 0; i < 28; i++) {
				if (i == 0) {
					cout << "|          *";
				}
				else if (i == 27) {
					cout << "*          |" << endl;
				}
				else {
					cout << '-';
				}
			}
		}
		else if(i==5||i>12){
			cout << '|' << "                                                |" << endl;
		}
	}
	cout << '*';
	for (int i = 0; i < 16 * times; i++) {
		cout << '-';
	}
	cout << '*' << endl;
}
void Map::setPlayer(int x, int y) {
	playerPlace[0] = x;
	playerPlace[1] = y;
	moveTimes++;
}
int Map::getPlayer() {
	return playerPlace[0];
}
int Map::getMoveTimes() {
	return moveTimes;
}
char Map::getWay1(int i) {
	return way1[i];
}
char Map::getWay2(int i) {
	return way2[i];
}