#include "Chest.hpp"


Chest::Chest(std::vector<Item*> loot, std::string name){
	this->loot_ = loot;
	this->name_ = name;
	this->chest_enemy_ = nullptr;
}


std::vector<Item*> Chest::getLoot() {
	return this->loot_;
}


std::string Chest::getName() {
	return this->name_;
}


void Chest::setChestEnemy(Enemy* chestEnemy) {
	chest_enemy_ = chestEnemy;
}


Enemy* Chest::getEnemy() {
	if (chest_enemy_) {
		return chest_enemy_;
	}
	return nullptr;
}
