#ifndef ITEM_HPP
#define ITEM_HPP

#include "CombatUnit.hpp"
#include <iostream>

class CombatUnit;

class Item  {
public:
	Item(std::string name, std::string description);
	std::string GetName();
	std::string GetDescription();
	void SetDescription(std::string description);
	void PrintData();
	virtual void Effect(CombatUnit* target) = 0;

private:
	std::string name_;
	std::string description_;
};

#endif