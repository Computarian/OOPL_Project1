#ifndef ROBOT_HPP
#define ROBOT_HPP

#include "Enemy.hpp"
#include "RobotArm.hpp"

class Robot : public Enemy{

public:
	Robot(int health, int damage, std::string name);
	void rocketPunch(CombatUnit* target);
protected:
	int rocket_punch_damage_ = 25;
};

#endif //ROBOT_HPP