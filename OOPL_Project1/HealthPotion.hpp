#ifndef HEALTHPOTION_HPP
#define HEALTHPOTION_HPP

#include "Item.hpp"

class HealthPotion : public Item {
public:
	HealthPotion();
	void Effect(CombatUnit* target);

private:
	int health_potion_heal_ = 50;
};

#endif //HEALTHPOTION_HPP