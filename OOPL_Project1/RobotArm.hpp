#ifndef ROBOTARM_HPP
#define ROBOTARM_HPP

#include "Item.hpp"

class RobotArm: public Item {
public:
	RobotArm();
	void Effect(CombatUnit* target);
};

#endif //ROBOTARM_HPP