#ifndef Character_h
#define Character_h
class Character {
private:
	int fullHp;
	int hp;
	int armor;
	static int money;
	int energy;
	int fullEnergy;
public:
	Character();
	Character(int,int,int);
	int getHP();
	int getFullHP();
	int getArmor();
	int getMoney();
	int getEnergy();
	int getFullEnergy();
	void setHP(int);
	void setFullHP(int);
	void setArmor(int);
	void setMoney(int);
	void setEnergy(int);
	void setFullEnergy(int);
	void setPlayer(Character);
};
#endif


