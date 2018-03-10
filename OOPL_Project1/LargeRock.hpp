#pragma once

#include "Enemy.hpp"

class LargeRock: public Enemy{
public:
	LargeRock(std::string name);
	~LargeRock();
	void makeMove(int move, CombatUnit* target);
private:
	const static int defaulthealth = 2000;
	const static int defaultDamage = 0;
	int punch_rock_damage_ = 25;
	int self_destruct_damage_ = 50;
	int rock_crack_damage_ = 10;

};

