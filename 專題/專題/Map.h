#ifndef Map_h
#define Map_h
#include<iostream>
#include<ctime>
using namespace std;
class Map {
private:
	static int moveTimes;
	int playerPlace[2] = { 1,-1};
	char road[3][10] = {};
	char up = '/';
	char down = 92;
	char player = '.';
	char monster='&';
	char camp='#';
	char shop='$';
	char boss = '!';
	char way1[10] = {up};
	char way2[10] = {down};
public:
	void creatMap();
	void setRoad(int,int ,int);
	void print();
	void setPlayer(int, int);
	int getPlayer();
	int getMoveTimes();
	char getWay1(int);
	char getWay2(int);
};
#endif
