#ifndef TROLL_HPP
#define TROLL_HPP

#include "Enemy.hpp"

class Troll :
	public Enemy
{
public:
	Troll(std::string name);
	~Troll();
	void makeMove(int move, CombatUnit* target);
	void regen();
	void insult(CombatUnit* target);
private:
	const static int defaultHealth = 50;
	const static int defaultDamage = 5;
	int regen_health_ = 5;
	int insult_damage_ = 10;
};

#endif TROLL_HPP