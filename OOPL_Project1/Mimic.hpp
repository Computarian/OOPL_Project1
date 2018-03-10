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
	void chomp(CombatUnit* target);
private:
	const static int defaultHealth = 500;
	const static int defaultDamage = 20;
	int shoot_can_damage_ = 10;
	int chomp_damage_ = 50;
};

#endif //MIMIC_HPP