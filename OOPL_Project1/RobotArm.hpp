#pragma once
#include "Item.hpp"
class RobotArm :
	public Item
{
public:
	RobotArm();
	void Effect(CombatUnit* target);
};

