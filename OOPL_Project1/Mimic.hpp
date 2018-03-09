#ifndef MIMIC_HPP
#define MIMIC_HPP

#include "Enemy.hpp"
#include "ManaPotion.hpp"

class Mimic: public Enemy {
public:
	Mimic(std::string name);
	~Mimic();
	void makeMove(int move, CombatUnit* target);
	void shootCan(CombatUnit* target);
private:
	const static int defaultHealth = 100;
	const static int defaultDamage = 50;
	const static int shoot_can_damage_ = 10;
};

#endif //MIMIC_HPP