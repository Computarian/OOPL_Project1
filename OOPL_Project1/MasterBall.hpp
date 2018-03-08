#ifndef MASTERBALL_HPP
#define MASTERBALL_HPP

#include "Item.hpp"
#include "MasterBallCapture.hpp"

class MasterBall : public Item {
public:
	MasterBall();
	void Effect(CombatUnit* target);
};

#endif //MASTERBALL_HPP