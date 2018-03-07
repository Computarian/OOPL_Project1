#ifndef HAMSANDWICH_HPP
#define HAMSANDWICH_HPP

#include "Item.hpp"

class HamSandwich : public Item {

public:
	HamSandwich();
	void Effect(CombatUnit* target);
};

#endif //HAMSANDWICH_HPP