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
	// constructor for player/enemies with mana
	CombatUnit(int health, int damage, int mana, std::string name);
	virtual ~CombatUnit();
	int GetDefaultHealth();
	int GetHealth();
	int GetDamage();
	std::string GetName();

	void UseItem(Item* item, CombatUnit* target);
	void AddItemToInventory(Item* item);
	void removeItemFromInventory(Item* item);
	void printInventory();
	std::vector<Item*> getInventory();

	void ModifyHealth(int amount);
	void ModifyMana(int amount);
	void DealDamage(CombatUnit* target);
	void PrintStats();

	void setMana(bool mana);	

	virtual void makeMove(int move, CombatUnit* target) = 0;
	
protected:
	int default_health_;
	int health;
	int damage;
	std::string name;
	int mana_;
	bool has_mana_;
	std::vector<Item*> inventory_;

};

#endif //COMBATUNIT_HPP