#ifndef Character_h
#define Character_h
class Character {
private:
	int hp;
	int armor;
	static int money;
	int energy;
public:
	Character();
	Character(int,int,int);
	int getHP();
	int getArmor();
	int getMoney();
	int getEnergy();
	void setHP(int);
	void setArmor(int);
	void setMoney(int);
	void setEnergy(int);
	void endTurn();
	void setPlayer(Character);
};
#endif


