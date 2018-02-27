#include "CombatUnit.hpp"


CombatUnit::CombatUnit(int health, int damage, std::string name) {
	this->health = health;
	this->damage = damage;
	this->name = name;
	std::cout << "CombatUnit health: " << this->health << " CombatUnit damage: " << this->damage << std::endl;

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
void CombatUnit::ModifyHealth(int amount) {
	this->health -= amount;
}


void CombatUnit::DealDamage(CombatUnit* target) {
	std::cout << this->name << " attacks!" << std::endl;
	target->ModifyHealth(this->damage);
}


void CombatUnit::UseItem(Item* name, CombatUnit* target) {
	std::cout << this->name << " uses " << name->GetName() << std::endl;
	name->Effect(target);
}


void CombatUnit::PrintStats() {
	std::cout << this->name << "'s health: " << this->health << "\tDamage: " << this->damage << std::endl;
}


void CombatUnit::SetName(std::string newName) {
	this->name = newName;
}