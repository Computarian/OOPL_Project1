#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Item.hpp"
#include "CombatUnit.hpp"
#include <vector>
#include <string>

class Player : public CombatUnit {
public:
	Player(int health, int damage, std::string name);
	void makeMove(int move, CombatUnit* target);
	void boltMagic(CombatUnit* target);
private:
	const static int mana_ = 100;
};

#endif //PLAYER_HPP