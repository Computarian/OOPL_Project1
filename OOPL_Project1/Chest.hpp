#ifndef CHEST_HPP
#define CHEST_HPP

#include <vector>
#include "Enemy.hpp"

class Item;

class Chest{
public:
	Chest(std::vector<Item*> loot, std::string name);
	std::vector<Item*> getLoot();
	std::string getName();
	void setChestEnemy(Enemy* chestEnemy);
	Enemy* getEnemy();

private:
	std::vector<Item*> loot_;
	Enemy* chest_enemy_;
	std::string name_;
};

#endif //CHEST_HPP