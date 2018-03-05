#include "Player.hpp"



Player::Player(int health, int damage, std::string name) : CombatUnit(health, damage, name) {

}


void Player::AddItemToInventory(Item* item) {
	this->inventory_.push_back(item);
}


void Player::removeItemFromInventory(Item* item) {
	for (int i = 0; i < inventory_.size(); i++) {
		if (inventory_[i] == item) {
			delete item;
			inventory_.erase(inventory_.begin() + i);
		}
	}
}


void Player::printInventory() {
	if (inventory_.empty()) {
		std::cout << "Inventory is empty!" << std::endl;
	}
	else {
		for (int i = 0; i < inventory_.size(); i++) {
			inventory_[i]->PrintData();
		}
	}
}


std::vector<Item*> Player::getInventory() {
	return this->inventory_;
}