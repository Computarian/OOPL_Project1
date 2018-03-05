#ifndef ITEM_HPP
#define ITEM_HPP

#include "CombatUnit.hpp"
#include <iostream>
#include <string>
#include "Spawnable.hpp"

class CombatUnit;

class Item /*: public Spawnable*/ {
public:
	Item(std::string name, std::string description);
	std::string GetName();
	std::string GetDescription();
	void SetDescription(std::string description);
	void PrintData();
	virtual void Effect(CombatUnit* target) = 0;
private:
	std::string name;
	std::string description_;
};

#endif