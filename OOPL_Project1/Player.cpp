#include "Player.hpp"



Player::Player(int health, int damage, std::string name) : CombatUnit(health, damage, name) {

}


void Player::AddItemToInventory(Item* item) {
	this->inventory_.push_back(item);
}


void Player::printInventory() {
	if (inventory_.empty()) {
		std::cout << "Inventory is empty!" << std::endl;
	}
	else {
		for (int i = 0; i < inventory_.size(); i++) {
			inventory_.at(i)->PrintData();
		}
	}
}
