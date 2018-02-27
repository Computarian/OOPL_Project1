#ifndef COMBATUNIT_HPP
#define COMBATUNIT_HPP

#include <string>
#include <iostream>
#include <vector>
#include <string>
#include "Item.hpp"

class CombatUnit {
public:
	CombatUnit(int health, int damage, std::string name);
	int GetHealth();
	int GetDamage();
	std::string GetName();
	void UseItem(Item* item, CombatUnit* target);
	void ModifyHealth(int amount);
	void DealDamage(CombatUnit* target);
	void PrintStats();
	void SetName(std::string newName);
protected:
	int health;
	int damage;
	std::string name;
};

#endif