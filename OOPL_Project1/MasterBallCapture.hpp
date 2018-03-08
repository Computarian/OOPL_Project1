#pragma once
#include "Item.hpp"
#ifndef MASTERBALLCAPTURE_HPP
#define MASTERBALLCAPTURE_HPP

#include "Item.hpp"

class MasterBallCapture : public Item {
public:
	MasterBallCapture(CombatUnit* target);
	void Effect(CombatUnit* target);
private:
	std::string captured_enemy_;
};

#endif //MASTERBALLCAPTURE_HPP

