#include "Player.hpp"



Player::Player(int health, int damage, std::string name) : CombatUnit(health, damage, name) {
	this->mana_ = 100;
	setMana(true);
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
			std::cout << i + 1 << ". ";
			inventory_[i]->PrintData();
		}
		std::cout<<std::endl;
	}
}


std::vector<Item*> Player::getInventory() {
	return this->inventory_;
}


void Player::makeMove(std::string move, CombatUnit* target){
	CombatUnit::makeMove(move, target);
	if (move == "bolt") {
		boltMagic(target);
	}
}


void Player::boltMagic(CombatUnit* target) {
	// bolt spell stats
	int boltCost = 50;
	int boltDamage = 125;

	// bolt logic
	// maybe add if enemy is a robot do more damage?
	if (mana_ >= 10) {
		std::cout << GetName() << " shoots a lightning bolt at " << target->GetName() << " for " << boltDamage << " damage!" << std::endl;
		target->ModifyHealth(boltDamage);
		ModifyMana(boltCost);
	}
	else {
		std::cout << GetName() << " doesnt have enough mana and the spell fizzles,\n";
		std::cout<<"doing no damage to "<<target->GetName() <<"!"<< std::endl;
	}
}