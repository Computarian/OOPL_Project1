#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Item.hpp"
#include "CombatUnit.hpp"

class Player : public CombatUnit {
public:
	Player(int health, int damage, std::string name);
	~Player();
	void makeMove(int move, CombatUnit* target);
	void boltMagic(CombatUnit* target);
	void cureMagic(CombatUnit* target);

private:
	const static int mana_ = 100;
	//spell stats
	int bolt_cost_ = 50;
	int bolt_damage_ = 300;
	int cure_cost_ = 25;
	int cure_heal_ = 300;
};

#endif //PLAYER_HPP