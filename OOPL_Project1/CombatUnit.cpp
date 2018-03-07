#include "CombatUnit.hpp"


CombatUnit::CombatUnit(int health, int damage, std::string name) {
	this->default_health_ = health;
	this->health = health;
	this->damage = damage;
	this->name = name;
	//std::cout << "CombatUnit health: " << this->health << " CombatUnit damage: " << this->damage << std::endl;
}


CombatUnit::CombatUnit(int health, int damage, int mana, std::string name) {
	this->default_health_ = health;
	this->health = health;
	this->damage = damage;
	this->name = name;
	this->mana_ = mana;
}


int CombatUnit::GetDefaultHealth() {
	return this->default_health_;
}


int CombatUnit::GetHealth() {
	return this->health;
}


int CombatUnit::GetDamage() {
	return this->damage;
}


std::string CombatUnit::GetName() {
	return this->name;
}


// Inventory Management functions
void CombatUnit::UseItem(Item* item, CombatUnit* target) {
	std::cout << this->name << " uses " << item->GetName() << std::endl;
	item->Effect(target);
}


void CombatUnit::AddItemToInventory(Item* item) {
	this->inventory_.push_back(item);
}


void CombatUnit::removeItemFromInventory(Item* item) {
	if (item->GetName() == "Master Ball") {
		std::cout << "The Master Ball flies back to you!" << std::endl;
		return;
	}
	for (int i = 0; i < inventory_.size(); i++) {
		if (inventory_[i] == item) {
			delete item;
			inventory_.erase(inventory_.begin() + i);
		}
	}
}


void CombatUnit::printInventory() {
	if (inventory_.empty()) {
		std::cout << "Inventory is empty!" << std::endl;
	}
	else {
		for (int i = 0; i < inventory_.size(); i++) {
			std::cout << i + 1 << ". ";
			inventory_[i]->PrintData();
		}
		std::cout << std::endl;
	}
}


std::vector<Item*> CombatUnit::getInventory() {
	return this->inventory_;
}


void CombatUnit::ModifyHealth(int amount) {
	this->health -= amount;
}


void CombatUnit::ModifyMana(int amount) {
	this->mana_ -= amount;
}


void CombatUnit::DealDamage(CombatUnit* target) {
	std::cout << this->name << " attacks " << target->GetName() << " for " << this->damage << " damage!" << std::endl;
	target->ModifyHealth(this->damage);
}


void CombatUnit::PrintStats() {
	std::cout << this->name << "'s health: " << this->health << "\tDamage: " << this->damage;
	if (has_mana_) {
		std::cout << "\tMana: " << this->mana_;
	}
	std::cout<<std::endl;
}


void CombatUnit::setMana(bool mana) {
	has_mana_ = mana;
}