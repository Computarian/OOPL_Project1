#ifndef CLUMSYROBOT_HPP
#define CLUMBSYROBOT_HPP

#include "Robot.hpp"
#include "HamSandwich.hpp"


//Eventually became the Final Boss
class ClumsyRobot : public Robot{

public:
	ClumsyRobot(std::string name);
	~ClumsyRobot();
	void makeMove(int move, CombatUnit* target);
	void bandage();
	void clean();
	void reeling();
	void gear();
	void wobbly();
	void battery();
	void missile(CombatUnit* target);
	void beam(CombatUnit* target);
	void sandwich();

private:
	const static int defaultHealth = 2000;
	const static int defaultDamage = 1;
	const static int missile_damage_ = 300;
	const static int beam_damage_ = 50;
};

#endif //CLUMSYROBOT_HPP