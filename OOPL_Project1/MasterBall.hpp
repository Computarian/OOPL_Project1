#ifndef MASTERBALL_HPP
#define MASTERBALL_HPP

#include "Item.hpp"

class MasterBall : public Item {
public:
	MasterBall();
	void Effect(CombatUnit* target);
	void viewCapturedEnemy();
private:
	CombatUnit* captured_enemy_;
};

#endif //MASTERBALL_HPP