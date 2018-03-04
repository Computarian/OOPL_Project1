#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Item.hpp"
#include "CombatUnit.hpp"
#include <vector>
#include <string>

class Player : public CombatUnit {
public:
	Player(int health, int damage, std::string name);
	void AddItemToInventory(Item* item);
	void printInventory();
private:
	std::vector<Item*> inventory_;
};

#endif