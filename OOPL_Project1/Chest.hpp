#ifndef CHEST_HPP
#define CHEST_HPP

#include <vector>

class Item;

class Chest{
public:
	Chest(std::vector<Item*> loot, std::string name);
	std::vector<Item*> getLoot();
	std::string getName();
private:
	std::vector<Item*> loot_;
	std::string name_;
};

#endif //CHEST_HPP