#ifndef ROBOT_HPP
#define ROBOT_HPP

#include "Enemy.hpp"
class Robot : public Enemy{

public:
	Robot(int health, int damage, std::string name);
};

#endif //ROBOT_HPP