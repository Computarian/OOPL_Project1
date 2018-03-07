#ifndef COMBATUNIT_HPP
#define COMBATUNIT_HPP

#include <string>
#include <iostream>
#include <vector>
#include <string>
#include "Item.hpp"

class Item;

class CombatUnit {
public:
	CombatUnit(int health, int damage, std::string name);
	int GetHealth();
	int GetDamage();
	std::string GetName();
	void SetName(std::string newName);

	void UseItem(Item* name, CombatUnit* target);
	void ModifyHealth(int amount);
	void ModifyMana(int amount);
	void DealDamage(CombatUnit* target);
	void PrintStats();
	void setMana(bool mana);
	void makeMove(std::string move, CombatUnit* target);
protected:
	int health;
	int damage;
	std::string name;
	int mana_;
	bool has_mana_;
};

#endif