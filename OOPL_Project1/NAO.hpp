#ifndef NAO_HPP
#define NAO_HPP

#include "Robot.hpp"
#include "HealthPotion.hpp"

class NAO: public Robot {
public:
	NAO(std::string name);
	~NAO();
	void makeMove(int move, CombatUnit* target);
	void fallOver(CombatUnit* target);
	void dropCan(CombatUnit* target);
	void headHurts(CombatUnit* target);
	void slipped(CombatUnit* target);
	void dab(CombatUnit* target);

private:
	const static int defaultHealth = 400;
	const static int defaultDamage = 20;
	int fall_over_damage_ = 40;
	int slipped_damage_ = 10;
};

#endif //NAO_HPP