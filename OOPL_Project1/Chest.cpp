#include "Chest.hpp"


Chest::Chest(std::vector<Item*> loot, std::string name){
	this->loot_ = loot;
	this->name_ = name;
}


std::vector<Item*> Chest::getLoot() {
	return this->loot_;
}


std::string Chest::getName() {
	return this->name_;
}


