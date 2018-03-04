#ifndef HEALTHPOTION_HPP
#define HEALTHPOTION_HPP

#include "Item.hpp"
#include "CombatUnit.hpp"

class HealthPotion : public Item {
public:
	HealthPotion();
	void Effect(CombatUnit* target);
};

#endif //HEALTHPOTION_HPP