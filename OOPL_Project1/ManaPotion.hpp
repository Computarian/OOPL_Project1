#ifndef MANAPOTION_HPP
#define MANAPOTION_HPP

#include "Item.hpp"

class ManaPotion: public Item{
public:
	ManaPotion();
	void Effect(CombatUnit* target);	
};

#endif //MANAPOTION_HPP